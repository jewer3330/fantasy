using UnityEngine;
using UnityEditor;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using SLua;

public class PlatoLoader
{
    private PLATO plato;
    private Dictionary<PlatoNode, List<PrevEntry>> links = new Dictionary<PlatoNode, List<PrevEntry>>();

    public PlatoLoader(PLATO plato)
    {
        this.plato = plato;
    }

    public void Load(string filename)
    {
        PlatoNodeGenerator.Parse();

        plato.ResetID();
        plato.graph = new PlatoGraph();

        TextAsset asset = AssetDatabase.LoadAssetAtPath<TextAsset>(filename);
        if (asset == null)
            return;

        IntPtr L = LuaDLL.luaL_newstate();
        LuaDLL.luaL_openlibs(L);

        object table;
        if (LuaUtil.LoadLua(L, asset.bytes, filename, out table) && table != null)
        {
            LuaUtil.TravelTable(L, table as LuaTable, (key, value) =>
            {
                if (key == "nodes") LoadNodes(L, value as LuaTable);
            });
            LuaUtil.TravelTable(L, table as LuaTable, (key, value) =>
            {
                if (key == "comments") LoadComments(L, value as LuaTable);
            });
            LuaUtil.TravelTable(L, table as LuaTable, (key, value) =>
            {
                //if (key == "reroutes") LoadReroutes(L, value as LuaTable);
            });
        }

        LuaDLL.lua_close(L);
        L = IntPtr.Zero;

        // Post load
        foreach (PlatoNode node in plato.graph.GetAllNodes())
        {
            node.PostLoad();
        }
        
        // Link
        var iter = links.GetEnumerator();
        while (iter.MoveNext())
        {
            PlatoNode nextNode = iter.Current.Key;
            List<PrevEntry> prevs = iter.Current.Value;
            
            foreach (var prev in prevs)
            {
                PlatoNode prevNode = plato.graph.FindNodeByID(prev.prev_id);
                if (prevNode == null)
                    continue;
                PlatoPin prevPin = prevNode.FindPinByTitle(prev.prev_title, false);
                if (prevPin == null)
                    continue;
                PlatoPin nextPin = nextNode.FindPinByTitle(prev.next_title, true);
                if (nextPin == null)
                    continue;

                prevPin.AddNext(nextPin);
                nextPin.AddPrev(prevPin);
            }
        }
        List<PlatoNode> allNodes = plato.graph.GetAllNodes();
        allNodes.Sort();
        if (allNodes.Count > 0)
            plato.MaxNodeID = allNodes[allNodes.Count - 1].ID;
    }

    /// 加载节点表
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    void LoadNodes(IntPtr L, LuaTable table)
    {
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            LoadNode(L, value as LuaTable);
        });
    }

    /// <summary>
    /// 加载节点
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    void LoadNode(IntPtr L, LuaTable table)
    {
        int posX = 0;
        int posY = 0;
        List<PlatoPin> inPins = new List<PlatoPin>();
        List<PlatoPin> outPins = new List<PlatoPin>();

        PlatoNode node = null;
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            if (key == "type")
                node = PLATO.CreateNode(value as string, plato);
        });
        plato.graph.AddNode(node);

        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            if (key == "id")
                node.ID = Convert.ToInt32(value);
            else if (key == "posX")
                posX = Convert.ToInt32(value);
            else if (key == "posY")
                posY = Convert.ToInt32(value);
            else if (key == "inPins")
                LoadPins(L, value as LuaTable, inPins, node, true);
            else if (key == "outPins")
                LoadPins(L, value as LuaTable, outPins, node, false);
        });
        node.Position = new Vector2(posX, posY);

        // 兼容旧版本
        TryFix(node, inPins, outPins);

        // 设置引脚
        Action<PlatoPin> setup = (PlatoPin src) =>
        {
            if (!string.IsNullOrEmpty(src.ParentPin))
            {
                PlatoPin parentPin = node.FindPinByTitle(src.ParentPin, true);
                if (parentPin is DropdownPin)
                {
                    if ((parentPin as DropdownPin).IsOuputPins)
                        node.AddPin(src);
                    else
                        node.InsertAsLastChild(src, parentPin);
                }
                else
                {
                    PlatoPin dst = node.AddDynamicPin(src.Title, src.Type, src.IsInput);
                    if (dst != null)
                    {
                        dst.Value = src.Value;
                        dst.ParentPin = src.ParentPin;
                        dst.ChildIndex = src.ChildIndex;

                        //FIXME(kai.zou): 动态执行引脚是否都是事件触发？
                        if (!dst.IsInput && dst is ExecPin)
                            (dst as ExecPin).IsEvent = true;
                    }
                }
            }
            else if (src.IsDynamic == false)
            {
                PlatoPin dst = node.FindPinByTitle(src.Title, src.IsInput);
                if (dst != null)
                    dst.Value = src.Value;
            }
            else
            {
                PlatoPin dst = node.AddDynamicPin(src.Title, src.Type, src.IsInput);
                if (dst != null)
                    dst.Value = src.Value;
            }
        };
        inPins.ForEach(setup);
        outPins.ForEach(setup);
    }

    /// <summary>
    /// 加载引脚
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    /// <param name="pins"></param>
    void LoadPins(IntPtr L, LuaTable table, List<PlatoPin> pins, PlatoNode node, bool isInput)
    {
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            PlatoPin pin = LoadPin(L, value as LuaTable, node);
            pin.IsInput = isInput;
            pins.Add(pin);
        });
    }

    /// <summary>
    /// 加载用前驱节点
    /// </summary>
    class PrevEntry
    {
        public int prev_id;
        public string prev_title;
        public string next_title;
    }

    /// <summary>
    /// 加载引脚
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    /// <returns></returns>
    PlatoPin LoadPin(IntPtr L, LuaTable table, PlatoNode node)
    {
        PlatoPin pin = null;
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            if (key == "type")
                pin = PlatoNodeGenerator.CreatePin(LuaObject.FindType(value as string));
        });
        List<PrevEntry> prevs = null;
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            if (key == "prevs")
                prevs = LoadPrevs(L, value as LuaTable, node);
            else
                pin.Load(key, value);
        });

        foreach (var prev in prevs)
        {
            prev.next_title = pin.Title;
        }
        List<PrevEntry> link;
        if (!links.TryGetValue(node, out link))
        {
            link = new List<PrevEntry>();
            links.Add(node, link);
        }

        link.AddRange(prevs);
        return pin;
    }

    /// <summary>
    /// 加载前驱表
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    /// <param name="prevs"></param>
    List<PrevEntry> LoadPrevs(IntPtr L, LuaTable table, PlatoNode node)
    {
        List<PrevEntry> prevs = new List<PrevEntry>();
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            PrevEntry prev = LoadPrev(L, value as LuaTable);
            prevs.Add(prev);
        });
        return prevs;
    }

    /// <summary>
    /// 加载前驱
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    /// <returns></returns>
    PrevEntry LoadPrev(IntPtr L, LuaTable table)
    {
        PrevEntry entry = new PrevEntry();
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            if (key == "prevId")
                entry.prev_id = Convert.ToInt32(value);
            else if (key == "prevTitle")
                entry.prev_title = (string)value;
        });
        return entry;
    }

    /// <summary>
    /// 加载Comments
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    void LoadComments(IntPtr L, LuaTable table)
    {
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            LoadComment(L, value as LuaTable);
        });
    }

    /// <summary>
    /// 加载Comment
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    void LoadComment(IntPtr L, LuaTable table)
    {
        int id = 0;
        string title = "Comment";
        int posX = 0;
        int posY = 0;
        int width = 0;
        int height = 0;
        List<CommentNode.ChildEntry> childs = new List<CommentNode.ChildEntry>();

        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            if (key == "id")
                id = Convert.ToInt32(value);
            else if (key == "title")
                title = (string)value;
            else if (key == "posX")
                posX = Convert.ToInt32(value);
            else if (key == "posY")
                posY = Convert.ToInt32(value);
            else if (key == "width")
                width = Convert.ToInt32(value);
            else if (key == "height")
                height = Convert.ToInt32(value);
            else if (key == "childs")
                LoadChilds(L, value as LuaTable, childs);
        });


        CommentNode node = PLATO.CreateNode("Comment", plato) as CommentNode;
        node.ID = id;
        node.Position = new Vector2(posX, posY);
        node.Size = new Vector2(width, height);
        node.Title = title;
        node.childEntries = childs;
        plato.graph.AddNode(node);
    }

    /// <summary>
    /// 加载子节点
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    /// <param name="childs"></param>
    void LoadChilds(IntPtr L, LuaTable table, List<CommentNode.ChildEntry> childs)
    {
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            CommentNode.ChildEntry entry = LoadChild(L, value as LuaTable);
            childs.Add(entry);
        });
    }

    CommentNode.ChildEntry LoadChild(IntPtr L, LuaTable table)
    {
        CommentNode.ChildEntry entry = new CommentNode.ChildEntry();
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            if (key == "id")
                entry.child = plato.graph.FindNodeByID(Convert.ToInt32(value));
            else if (key == "offsetX")
                entry.offset.x = Convert.ToSingle(value);
            else if (key == "offsetY")
                entry.offset.y = Convert.ToSingle(value);
        });
        return entry;
    }

    void TryFix(PlatoNode node, List<PlatoPin> inPins, List<PlatoPin> outPins)
    {
        int index = 0;
        Action<PlatoPin> fix = (PlatoPin src) =>
        {
            if (!string.IsNullOrEmpty(src.ParentPin))
                return;
            src.ParentPin = node.FindParentPin(src.Title);
            if (!string.IsNullOrEmpty(src.ParentPin))
                src.ChildIndex = index++;
        };
        index = 0; inPins.ForEach(fix);
        index = 0; outPins.ForEach(fix);

        if (node.Title == "TriggerCheck")
        {
            index = 0;
            foreach (PlatoPin pin in inPins)
            {
                if (!pin.IsDynamic)
                    continue;
                pin.ParentPin = "Add";
                pin.ChildIndex = index++;
            }
        }
        else if (node.Title == "ReviseMapI32")
        {
            index = 0;
            foreach (PlatoPin pin in inPins)
            {
                if (!pin.IsDynamic)
                    continue;
                pin.ParentPin = "Add";
                pin.ChildIndex = index++;
            }
        }
    }
}
