using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using UnityEditor;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;
using SLua;

public class PLATO
{
    /// <summary>PLATO保存路径</summary>
    public static readonly string PLATO_SAVE_PATH = "Assets/Editor Default Resources/PLATO/";
    public static readonly string PLATO_WEAPON_SAVE_PATH = "Assets/Editor Default Resources/PLATO/WeaponEditor/";
    public static readonly string PLATO_PROJECTILE_SAVE_PATH = "Assets/Editor Default Resources/PLATO/WeaponEditor/Projectile/";
    /// <summary>LUA导出路径</summary>
    public static readonly string LUA_SAVE_PATH = "Assets/Scripts/Slua/Resources/plato/";
    /// <summary>CPP导出路径</summary>
    public static readonly string CPP_SAVE_PATH = "Assets/Editor Default Resources/PLATO/CPP/";
    /// <summary>C#导出路径</summary>
    public static readonly string CSHARP_SAVE_PATH = "Assets/Scripts/Plato/Export";
    /// <summary>MACRO导出路径</summary>
    public static readonly string MACRO_PATH = "Assets/Editor Default Resources/PLATO/Macros/";

    /// <summary>最大节点ID</summary>
    public int MaxNodeID { get; set; }
    /// <summary>重置最大节点ID</summary>
    public void ResetID() { MaxNodeID = 1; }
    /// <summary>节点图</summary>
    public PlatoGraph graph;
    /// <summary>拖动起始位置</summary>
    private Vector2 dragStartPos;
    /// <summary>右键菜单位置</summary>
    private Vector2 contextMenuPos;
    /// <summary>滚动条起始位置</summary>
    private Vector2 scrollPos = new Vector2(0, 0);
    /// <summary>弹出菜单节点</summary>
    private PlatoNode menuNode;

    /// <summary>左面板滚动条位置</summary>
    private Vector2 leftScrollPos = new Vector2(0, 0);


    static PLATO()
    {
        CPP_SAVE_PATH = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);
    }

    public PLATO()
    {
        dragPins.Clear();
        dragNodes.Clear();
        linkPins = null;
        dragNodeStart = Vector2.zero;
    }

    public PLATO(PLATO rhs)
    {
        graph = new PlatoGraph();
        scrollPos = rhs.scrollPos;

        // 复制节点
        foreach (PlatoNode node in rhs.graph.GetAllNodes())
        {
            if (node is EditorNode)
                continue;

            PlatoNode copy = node.Clone(this);
            copy.Position = node.Position;
            copy.ID = node.ID;
            graph.AddNode(copy);
        }

        // 连线
        foreach (PlatoNode node in rhs.graph.GetAllNodes())
        {
            if (node is EditorNode)
                continue;
            PlatoNode copy = graph.FindNodeByID(node.ID);

            foreach (PlatoPin pin in node.GetAllInPins())
            {
                foreach (PlatoPin prev in pin.Prevs)
                {
                    PlatoNode prevNode = graph.FindNodeByID(prev.ParentNode.ID);

                    prevNode.FindPinByTitle(prev.Title, false).AddNext(copy.FindPinByTitle(pin.Title, true));
                    copy.FindPinByTitle(pin.Title, true).AddPrev(prevNode.FindPinByTitle(prev.Title, false));
                }
            }
        }
        MaxNodeID = rhs.MaxNodeID;
    }

    /// <summary>
    /// 拖拽引脚
    /// </summary>
    public class DragPin
    {
        public Rect start;
        public PlatoPin pin;
    }
    public class DragNode
    {
        public Vector2 start;
        public PlatoNode node;
    }
    /// <summary>当前拖拽引脚列表</summary>
    public static List<DragPin> dragPins = new List<DragPin>();
    /// <summary>当前待连接引脚列表</summary>
    public static List<DragPin> linkPins;
    /// <summary>当前拖拽节点</summary>
    private static List<DragNode> dragNodes = new List<DragNode>();
    /// <summary>当前拖拽开始点</summary>
    private static Vector2 dragNodeStart;
    /// <summary>
    /// 添加拖拽
    /// </summary>
    /// <param name="pin"></param>
    public static void AddDrag(DragPin pin)
    {
        dragPins.Add(pin);
    }
    /// <summary>取消拖拽</summary>
    public static void CancelDrag()
    {
        dragPins.Clear();
    }
    /// <summary>
    /// 连接拖拽
    /// </summary>
    /// <param name="target"></param>
    public static void LinkDrag(DragPin target)
    {
        foreach (DragPin dragPin in dragPins)
        {
            if (dragPin.pin.Nexts.Contains(target.pin))
                continue;
            if (dragPin.pin.ParentNode == target.pin.ParentNode)
                continue;
            if (dragPin.pin.Type != target.pin.Type)
            {
                if (dragPin.pin.ParentNode.Title == "Reroute")
                {
                    if (dragPin.pin.ParentNode.FindPinByIndex(0, true).Prevs.Count > 0)
                        continue;
                }
                else if (target.pin.ParentNode.Title == "Reroute")
                {
                    if (target.pin.ParentNode.FindPinByIndex(0, false).Nexts.Count > 0)
                        continue;
                }
                else
                {
                    continue;
                }
            }

            if (dragPin.pin.Type != null)
            {
                foreach (PlatoPin prev in target.pin.Prevs)
                {
                    prev.RemoveNext(target.pin);
                }
                target.pin.Prevs.Clear();
            }
            target.pin.AddPrev(dragPin.pin);
            dragPin.pin.AddNext(target.pin);

            if (dragPin.pin.ParentNode.Title == "Reroute")
            {
                dragPin.pin.Type = target.pin.Type;
                dragPin.pin.Value = target.pin.Value;
                dragPin.pin.ParentNode.FindPinByIndex(0, true).Type = target.pin.Type;
            }
            else if (target.pin.ParentNode.Title == "Reroute")
            {
                target.pin.Type = dragPin.pin.Type;
                target.pin.Value = dragPin.pin.Value;
                target.pin.ParentNode.FindPinByIndex(0, false).Type = dragPin.pin.Type;
            }
        }
        CancelDrag();
    }

    /// <summary>
    /// 尝试拖拽
    /// </summary>
    /// <param name="target"></param>
    /// <returns></returns>
    public static string TryLink(DragPin target)
    {
        foreach (DragPin dragPin in dragPins)
        {
            if (dragPin.pin.Nexts.Contains(target.pin))
                return "Same link";
            if (dragPin.pin.ParentNode == target.pin.ParentNode)
                return "Don't fuck yourself";
            if (dragPin.pin.ParentNode.Title == "Reroute" && dragPin.pin.ParentNode.FindPinByIndex(0, true).Prevs.Count == 0)
                return string.Empty;
            if (target.pin.ParentNode.Title == "Reroute" && target.pin.ParentNode.FindPinByIndex(0, false).Nexts.Count == 0)
                return string.Empty;

            if (dragPin.pin.Type != target.pin.Type)
            {
                return string.Format("{0} is not compatible with {1}",
                    dragPin.pin.Type == null ? "Exec" : dragPin.pin.Type.ToString(),
                    target.pin.Type == null ? "Exec" : target.pin.Type.ToString());
            }
        }
        return string.Empty;
    }

    /// <summary>选择框起点</summary>
    private Vector2 selectionBoxStart;
    /// <summary>选择框大小</summary>
    private Rect selectionBoxRect;

    private string tip;
    private Vector2 tipPos;
    private Vector2 dragPos;

    private static PlatoCopyGroup copyGroup;

    /// <summary>
    /// 跳到某个节点
    /// </summary>
    /// <param name="node"></param>
    public void Goto(PlatoNode node, EditorWindow wnd)
    {
        graph.GetAllNodes().ForEach((n) => { n.IsFocus = false; });
        node.IsFocus = true;
        scrollPos.x = Mathf.Max(0.0f, node.Position.x - wnd.position.width / 2);
        scrollPos.y = Mathf.Max(0.0f, node.Position.y - wnd.position.height / 2);
        wnd.Repaint();
    }

    public void Break(PlatoNode node)
    {
        foreach (PlatoNode n in graph.GetAllNodes())
        {
            n.IsBreaking = false;
        }
        if (node != null)
            node.IsBreaking = true;
    }

    public void CreateMenu(Vector2 pos)
    {
        menuNode = PLATO.CreateNode("ContextMenu", this) as EditorNode;
        menuNode.Position = pos;
        graph.AddNode(menuNode);
    }

    public void RemoveMenu()
    {
        PLATO.linkPins = null;
        if (menuNode != null)
        {
            graph.RemoveNode(menuNode);
            menuNode = null;
        }
    }

    public void ShowTip(Vector2 pos, string msg)
    {
        tip = msg;
        tipPos = pos;
    }

    public void HideTip()
    {
        tip = null;
    }

    public bool IsDragPin(PlatoNode node)
    {
        if (dragPins == null || dragPins.Count == 0)
            return false;

        foreach (DragPin drag in dragPins)
        {
            if (drag.pin.ParentNode == node)
                return true;
        }
        return false;
    }

    public bool IsDragNode(PlatoNode node)
    {
        if (dragNodes == null || dragNodes.Count == 0)
            return false;

        foreach (DragNode drag in dragNodes)
        {
            if (drag.node == node)
                return true;
        }
        return false;
    }

    class MacroEntry
    {
        public Rect rect;
        public string macro;
    }
    List<MacroEntry> macros = new List<MacroEntry>();

    /// <summary>
    /// 自定义GUI绘制
    /// </summary>
    /// <param name="wnd"></param>
    public void DrawGUI(EditorWindow wnd, Vector2 offset, bool debug = false)
    {
        GUI.skin = null;
        GUIStyle foldStyle = new GUIStyle(GUI.skin.FindStyle("Foldout"));
        foldStyle.normal.textColor = Color.white;
        foldStyle.fontStyle = FontStyle.Bold;

        GUI.skin = PlatoNode.skin;

        // 左边栏
        if (!debug)
        {
            GUILayout.Space(offset.y - 45);
            leftScrollPos = GUILayout.BeginScrollView(leftScrollPos, GUILayout.MaxWidth(200));

            GUILayout.BeginHorizontal();
            GUILayout.Label("MACROS", EditorStyles.boldLabel);
            if (GUILayout.Button("+", GUILayout.Width(20)))
                CreatePlatoMacroWindow.PopUp();
            GUILayout.EndHorizontal();
            {
                macros.Clear();

                GUILayout.BeginVertical();
                string[] filenames = Directory.GetFiles(MACRO_PATH, "*.txt");
                foreach (string filename in filenames)
                {
                    GUILayout.BeginHorizontal();
                    GUILayout.Label("    " + Path.GetFileNameWithoutExtension(filename));

                    MacroEntry entry = new MacroEntry();
                    entry.macro = Path.GetFileNameWithoutExtension(filename);
                    entry.rect = GUILayoutUtility.GetLastRect();
                    macros.Add(entry);

                    if (GUILayout.Button("E", GUILayout.Width(20))) PlatoEditor.ShowEditor(filename);
                    GUILayout.EndHorizontal();
                }
                GUILayout.EndVertical();
            }

            // 拖拽
            if (Event.current.type == EventType.MouseDrag && dragPins.Count == 0 && dragNodes.Count == 0)
            {
                if (DragAndDrop.GetGenericData("Macro") != null)
                {
                    DragAndDrop.StartDrag("Draggin");
                    Event.current.Use();
                }
            }
            else if (Event.current.type == EventType.MouseDown)
            {
                DragAndDrop.PrepareStartDrag();
                foreach (MacroEntry entry in macros)
                {
                    if (entry.rect.Contains(Event.current.mousePosition))
                    {
                        DragAndDrop.SetGenericData("Macro", entry.macro);
                        DragAndDrop.paths = null;
                        DragAndDrop.objectReferences = new UnityEngine.Object[0];
                        Event.current.Use();
                        break;
                    }
                }
            }

            GUILayout.EndScrollView();
            offset.x += 200;
        }

        scrollPos = GUI.BeginScrollView(new Rect() { x = offset.x, y = offset.y, width = wnd.position.width - offset.x, height = wnd.position.height - offset.y }, scrollPos, new Rect(0, 0, 10000, 10000), true, true);

        // 点击判断
        if (Event.current.type == EventType.MouseDown && graph != null)
        {
            if (Event.current.button == 0)
            {
                OnLeftMouseDown(wnd);
            }
            else if (Event.current.button == 1 && debug)
            {
                foreach (PlatoNode node in graph.GetAllNodes())
                {
                    Rect rect = new Rect(node.Position, node.Size);
                    if (rect.Contains(Event.current.mousePosition))
                    {
                        GenericMenu menu = new GenericMenu();
                        if (!node.IsBreak)
                            menu.AddItem(new GUIContent("New Break"), false, () => { node.IsBreak = true; });
                        else
                            menu.AddItem(new GUIContent("Delete Break"), false, () => { node.IsBreak = false; });
                        menu.ShowAsContext();
                        break;
                    }
                }
            }
        }
        // 拖拽完成
        else if (!debug && Event.current.type == EventType.MouseUp && Event.current.button == 0 && graph != null)
        {
            DragAndDrop.PrepareStartDrag();
            dragNodes.Clear();
            if (selectionBoxStart != Vector2.zero)
            {
                foreach (PlatoNode node in graph.GetAllNodes())
                {
                    Rect rect = new Rect(node.Position, node.Size);
                    if (selectionBoxRect.Overlaps(rect, true))
                        node.IsFocus = true;
                    else
                        node.IsFocus = false;
                }
                selectionBoxStart = Vector2.zero;
                selectionBoxRect.Set(0, 0, 0, 0);
            }
        }
        // 删除选中
        else if (!debug && Event.current.type == EventType.KeyDown && Event.current.keyCode == KeyCode.Delete && graph != null)
        {
            List<PlatoNode> focusNodes = graph.GetAllNodes().FindAll((node) => { return node.IsFocus; });
            for (int i = 0; i < focusNodes.Count; ++i)
            {
                PLATO.RemoveNode(focusNodes[i], this);
            }
            wnd.Repaint();
        }
        // 复制
        else if (!debug && Event.current.type == EventType.KeyUp && Event.current.control && Event.current.keyCode == KeyCode.C)
        {
            List<PlatoNode> copyNodes = graph.GetAllNodes().FindAll((node) => { return node.IsFocus; });
            if (copyNodes.Count > 0)
            {
                copyGroup = new PlatoCopyGroup();
                copyGroup.AddNodes(copyNodes);
            }
        }
        // 粘贴
        else if (!debug && Event.current.type == EventType.KeyUp && Event.current.control && Event.current.keyCode == KeyCode.V)
        {
            if (copyGroup != null)
            {
                copyGroup.Copy(Event.current.mousePosition, this);
            }
            wnd.Repaint();
        }
        else if (Event.current.type == EventType.DragUpdated)
        {
            dragPos = Event.current.mousePosition;
            DragAndDrop.visualMode = DragAndDropVisualMode.Copy;
            Event.current.Use();
        }
        else if (Event.current.type == EventType.DragPerform)
        {
            DragAndDrop.AcceptDrag();
            if (DragAndDrop.GetGenericData("Macro") != null)
            {
                string macroFilename = DragAndDrop.GetGenericData("Macro") as string;
                graph.AddNode(CreateMacroNode(macroFilename, dragPos, this));
                DragAndDrop.PrepareStartDrag();
                Event.current.Use();
            }
            wnd.Repaint();
        }

        // 拖拽
        foreach (DragNode node in dragNodes)
        {
            Vector2 dragOffset = Event.current.mousePosition - dragNodeStart;
            node.node.Position = node.start + dragOffset;
            wnd.Repaint();
        }
        // 绘制拖拽框
        if (selectionBoxStart != Vector2.zero)
        {
            // 鼠标到达窗口边缘时自动滚动
            Vector2 wndPos = Event.current.mousePosition - scrollPos;
            if (wndPos.x < 0.0f)
                scrollPos.x -= 4.0f;
            else if (wndPos.x > wnd.position.width - offset.x - 40.0f)
                scrollPos.x += 4.0f;

            if (wndPos.y < 0.0f)
                scrollPos.y -= 4.0f;
            else if (wndPos.y > wnd.position.height)
                scrollPos.y += 4.0f;

            // 计算选择框
            Vector2 min;
            min.x = Mathf.Min(selectionBoxStart.x, Event.current.mousePosition.x);
            min.y = Mathf.Min(selectionBoxStart.y, Event.current.mousePosition.y);
            Vector2 max;
            max.x = Mathf.Max(selectionBoxStart.x, Event.current.mousePosition.x);
            max.y = Mathf.Max(selectionBoxStart.y, Event.current.mousePosition.y);
            selectionBoxRect = Rect.MinMaxRect(min.x, min.y, max.x, max.y);

            Color oldColor = GUI.color;
            GUI.color = new Color(0.0f, 0.0f, 0.0f, 0.25f);
            GUI.DrawTexture(selectionBoxRect, Texture2D.whiteTexture);
            GUI.color = oldColor;
            wnd.Repaint();
        }

        // 绘制节点窗口
        Rect wndRect = new Rect(scrollPos, wnd.position.size);
        wnd.BeginWindows();
        if (graph != null) graph.Draw(wndRect, debug);
        wnd.EndWindows();

        // 拖拽中鼠标到达窗口边缘时自动滚动
        if (dragPins.Count > 0)
        {
            Vector2 wndPos = Event.current.mousePosition - scrollPos;
            if (wndPos.x < 0.0f)
                scrollPos.x -= 4.0f;
            else if (wndPos.x > wnd.position.width - offset.x - 40.0f)
                scrollPos.x += 4.0f;

            if (wndPos.y < 0.0f)
                scrollPos.y -= 4.0f;
            else if (wndPos.y > wnd.position.height)
                scrollPos.y += 4.0f;
        }

        // 绘制拖拽
        Handles.BeginGUI();
        foreach (DragPin drag in dragPins)
        {
            float distance = Vector3.Distance(drag.start.center, Event.current.mousePosition);
            Handles.DrawBezier(drag.start.center,
                Event.current.mousePosition,
                new Vector2(drag.start.xMax + distance * 0.2f, drag.start.center.y),
                new Vector2(Event.current.mousePosition.x - distance * 0.2f, Event.current.mousePosition.y), drag.pin.GetColor(),
                null,
                5f);
            HandleUtility.Repaint();
        }
        Handles.EndGUI();

        // 绘制Tip
        if (!string.IsNullOrEmpty(tip))
        {
            if (tip == "OK")
            {
                GUI.color = Color.green;
                GUI.Box(new Rect(tipPos + new Vector2(10, 10), new Vector2(40, 24)), "OK");
            }
            else
            {
                GUI.color = Color.red;
                GUI.Box(new Rect(tipPos + new Vector2(10, 10), new Vector2(350, 24)), tip);
            }
        }

        GUI.EndScrollView();

        int controlId = GUIUtility.GetControlID(FocusType.Passive);
        switch (Event.current.GetTypeForControl(controlId))
        {
            case EventType.MouseUp:
                // 鼠标弹起，取消引脚拖拽
                bool showMenu = true;
                foreach (DragPin p in dragPins)
                {
                    if (PinTypeUtil.IsExec(p.pin) == false)
                    {
                        showMenu = false;
                        break;
                    }
                }
                if (showMenu && dragPins.Count > 0)
                {
                    linkPins = new List<DragPin>(dragPins);
                    contextMenuPos = Event.current.mousePosition;
                    contextMenuPos -= offset;
                    CreateMenu(contextMenuPos + scrollPos);
                }
                HideTip();
                CancelDrag();
                break;

            case EventType.MouseDown:
                // 右键点击
                if (Event.current.button == 1 && !debug)
                {
                    contextMenuPos = Event.current.mousePosition;
                    contextMenuPos -= offset;

                    RemoveMenu();
                    CreateMenu(contextMenuPos + scrollPos);

                    wnd.Repaint();
                }
                // 中键点击，开始拖拽
                else if (Event.current.button == 2)
                {
                    dragStartPos = Event.current.mousePosition;
                }
                break;

            case EventType.MouseDrag:
                // 中键拖拽
                if (Event.current.button == 2)
                {
                    scrollPos -= (Event.current.mousePosition - dragStartPos);
                    dragStartPos = Event.current.mousePosition;
                    wnd.Repaint();
                }
                break;
        }

        GUI.skin = null;
    }

    void OnLeftMouseDown(EditorWindow wnd)
    {
        if (menuNode != null)
        {
            // 点击菜单
            Rect rect = new Rect(menuNode.Position, menuNode.Size);
            if (rect.Contains(Event.current.mousePosition))
            {
                wnd.Repaint();
                return;
            }
        }

        RemoveMenu();
        bool isDrag = false;

        // 如果点击的是已选中节点的标题栏，开始拖拽
        List<PlatoNode> focusNodes = graph.GetAllNodes().FindAll((node) => { return node.IsFocus; });
        foreach (PlatoNode node in focusNodes)
        {
            Rect dragRect = new Rect(node.Position, node.Size) { width = node.Size.x - 18, height = 18 };
            if (dragRect.Contains(Event.current.mousePosition))
            {
                isDrag = true;
                dragNodeStart = Event.current.mousePosition;
                break;
            }
        }

        dragNodes.Clear();
        if (isDrag)
        {
            foreach (PlatoNode node in focusNodes)
            {
                if (IsDragPin(node) == false)
                    dragNodes.Add(new DragNode() { node = node, start = node.Position });
            }
        }
        else
        {
            // 重新开始选中节点
            selectionBoxStart = Event.current.mousePosition;
            foreach (PlatoNode node in graph.GetAllNodes())
            {
                Rect rect = new Rect(node.Position, node.Size);
                if (rect.Contains(Event.current.mousePosition))
                {
                    node.IsFocus = true;
                    selectionBoxStart = Vector2.zero;
                    // 如果点中了标题栏，开始拖拽
                    if (new Rect(rect) { width = rect.width - 18, height = 18 }.Contains(Event.current.mousePosition))
                    {
                        if (IsDragPin(node) == false)
                        {
                            dragNodes.Add(new DragNode() { node = node, start = node.Position });
                            dragNodeStart = Event.current.mousePosition;
                        }
                    }
                }
                else
                {
                    node.IsFocus = false;
                }
            }
        }

        wnd.Repaint();
    }

    /// <summary>
    /// 自定义场景绘制
    /// </summary>
    /// <param name="sceneView"></param>
    public void DrawSceneGUI(SceneView sceneView)
    {
        // Empty
    }

    /// <summary>
    /// 添加节点
    /// </summary>
    /// <param name="node"></param>
    public static void AddNode(PlatoNode node, PLATO plato)
    {
        if (plato != null && plato.graph != null)
        {
            node.plato = plato;
            node.Position = plato.contextMenuPos + plato.scrollPos;
            plato.graph.AddNode(node);
        }
    }

    /// <summary>
    /// 创建节点
    /// </summary>
    /// <param name="title">节点名</param>
    /// <returns></returns>
    public static PlatoNode CreateNode(string title, PLATO plato)
    {
        if (plato != null)
        {
            if (title.Contains("Macro-"))
            {
                string macroFilename = title.Remove(0, 6);
                return CreateMacroNode(macroFilename, Vector2.zero, plato);
            }
            else
            {
                PlatoNode prototype = PlatoNodeGenerator.FindPrototypeByTitle(title);
                return prototype.Clone(plato);
            }
        }
        return null;
    }

    /// <summary>
    /// 移除节点
    /// </summary>
    /// <param name="node"></param>
    public static void RemoveNode(PlatoNode node, PLATO plato)
    {
        if (plato != null)
        {
            node.Clear();
            plato.graph.RemoveNode(node);
        }
    }

    /// 导出lua
    /// </summary>
    public void ExportLua(string filename = null, bool isWeapon = false)
    {
        if (graph == null)
            return;

        PLATO export = new PLATO(this);
        ExpandMacro(export);

        if (string.IsNullOrEmpty(filename))
        {
            filename = Path.Combine(LUA_SAVE_PATH, PROTOGONOS.Instance.LevelName) + ".txt";
            filename = filename.Replace("GAIA_", "");
        }
        PlatoLuaExporter exporter = new PlatoLuaExporter(export, filename);
        exporter.Export();
    }

    public void ExportCSharp(string filename = null, bool isWeapon = false)
    {
        if (graph == null)
            return;

        PLATO export = new PLATO(this);
        ExpandMacro(export);

        if (string.IsNullOrEmpty(filename))
        {
            filename = Path.Combine(Path.Combine(CSHARP_SAVE_PATH, "Level"), PROTOGONOS.Instance.LevelName) + ".cs";
            filename = filename.Replace("GAIA_", "");
        }
        PlatoCSharpExporter exporter = new PlatoCSharpExporter(export, filename);
        exporter.Export();
    }

    public static void ExpandMacro(PLATO target)
    {
        PlatoNode macroNode;
        while (true)
        {
            // 每次展开一个
            var macros = target.graph.GetAllNodes().FindAll((node) => { return node.Title.Contains("Macro-"); });
            if (macros.Count == 0)
                break;

            macros.Sort();
            macroNode = macros[0];

            string macroName = macroNode.Title.Remove(0, 6);

            // 打卡宏文件
            PLATO macro = new PLATO();
            macro.graph = new PlatoGraph();

            PlatoLoader loader = new PlatoLoader(macro);
            loader.Load(Path.Combine(MACRO_PATH, macroName) + ".txt");

            PlatoNode startNode = macro.graph.FindNodesByTitle("MacroInputs")[0];
            PlatoNode endNode = macro.graph.FindNodesByTitle("MacroOutputs")[0];
            List<PlatoNode> nodes = macro.graph.GetAllNodes().FindAll((node) =>
            {
                return node.Title != "MacroInputs" && node.Title != "MacroOutputs";
            });

            if (nodes.Count == 0)
            {
                Debug.LogWarningFormat("Macro[{0}] is empty!", macroName);
                continue;
            }

            PlatoCopyGroup copy = new PlatoCopyGroup();
            copy.AddNodes(nodes);
            copy.Copy(macroNode.Position, target);

            // 重连输入
            foreach (PlatoPin inLeftPin in macroNode.GetAllInPins())
            {
                PlatoPin inRightPin = startNode.FindPinByTitle(inLeftPin.Title, false);

                foreach (PlatoPin next in inRightPin.Nexts)
                {
                    PlatoNode copyNode = copy.GetCopy(next.ParentNode);
                    PlatoPin realNext = copyNode.FindPinByTitle(next.Title, true);

                    // 连线
                    if (inLeftPin.Prevs.Count > 0)
                    {
                        foreach (PlatoPin prev in inLeftPin.Prevs)
                        {
                            prev.AddNext(realNext);
                            realNext.AddPrev(prev);
                        }
                    }
                    else // 赋值
                    {
                        realNext.Value = inLeftPin.Value;
                    }
                }
            }

            // 重连输出
            foreach (PlatoPin outLeftPin in endNode.GetAllInPins())
            {
                if (outLeftPin.Type == typeof(Button) || outLeftPin.Type == typeof(Dropdown))
                    continue;

                PlatoPin outRightPin = macroNode.FindPinByTitle(outLeftPin.Title, false);

                foreach (PlatoPin next in outRightPin.Nexts)
                {
                    // 连线
                    if (outLeftPin.Prevs.Count > 0)
                    {
                        foreach (PlatoPin prev in outLeftPin.Prevs)
                        {
                            PlatoNode copyNode = copy.GetCopy(prev.ParentNode);
                            PlatoPin realPrev = copyNode.FindPinByTitle(prev.Title, false);

                            realPrev.AddNext(next);
                            next.AddPrev(realPrev);
                        }
                    }
                    else // 赋值
                    {
                        next.Value = outLeftPin.Value;
                    }
                }
            }

            PLATO.RemoveNode(macroNode, target);
        }
    }

    public void ExportCpp(string filename = null)
    {
        if (graph == null)
            return;

        if (!Directory.Exists(CPP_SAVE_PATH))
            Directory.CreateDirectory(CPP_SAVE_PATH);
        if (string.IsNullOrEmpty(filename))
            filename = ("drama_" + PROTOGONOS.Instance.LevelName).ToLower();

        PlatoWriter writer = null;
        PLATO export = new PLATO(this);

        // 宏展开
        ExpandMacro(export);

        // 导出头文件
        try
        {
            writer = new PlatoWriter(Path.Combine(CPP_SAVE_PATH, filename) + ".h");

            ExportComment(writer, "THIS IS GENERATED BY MACHINE, DO NOT MODIFIY");
            writer.Line("#ifndef {0}_H_", filename.ToUpper());
            writer.Line("#define {0}_H_", filename.ToUpper());
            writer.Line(null);

            writer.Line("#include \"drama.h\"");
            writer.Line(null);

            writer.Line("namespace pvp {{");
            writer.PushIndent();
            writer.Line("DECLARE_ENGINE({0})", PROTOGONOS.Instance.LevelName);
            writer.PopIndent();
            writer.Line("}}");
            writer.Line(null);

            writer.Line("#endif // {0}_H_", filename.ToUpper());
        }
        finally
        {
            if (writer != null)
                writer.Close();
            AssetDatabase.Refresh();
        }

        // 导出源文件
        try
        {
            export.graph.ResetExported();

            writer = new PlatoWriter(Path.Combine(CPP_SAVE_PATH, filename) + ".cpp");

            ExportComment(writer, "THIS IS GENERATED BY MACHINE, DO NOT MODIFIY");
            writer.Line("#include \"{0}.h\"", filename);
            writer.Line(null);

            // include
            writer.Line("#include \"drama_variable.h\"");
            foreach (string title in export.graph.GetUsedNodes())
            {
                string[] strs = Regex.Split(title, @"(?<!^)(?=[A-Z])");
                writer.Line("#include \"drama_{0}.h\"", String.Join("_", strs).ToLower());
            }
            writer.Line("#include \"drama_damage_volume_active.h\"");
            writer.Line(null);

            writer.Line("namespace pvp {{");
            writer.PushIndent();

            writer.Line("IMPLEMENT_ENGINE_INIT({0}) {{", PROTOGONOS.Instance.LevelName);
            writer.PushIndent();

            export.graph.ResetExported();
            List<List<PlatoNode>> trees = GetTrees(export);

            // 导出变量
            ExportComment(writer, "Variables");
            ExportTreesCpp(FilterTree("Value", trees), (tree) =>
            {
                foreach (PlatoNode node in tree)
                {
                    node.ExportCpp(writer, "func");
                }
            }); writer.Line(null);

            // TODO(kai.zou): 特殊处理的代码是没有灵魂的
            // 导出DamageVolume
            ExportComment(writer, "OnDamageVolume");
            writer.Line("DramaFunc* damageFunc = new DramaFunc(getBattleField(), this);");
            foreach (PlatoNode node in export.graph.GetAllNodes())
            {
                if (node.Title != "OnDamageVolume")
                    continue;
                node.ExportCpp(writer, "damageFunc");
                writer.Line("damageFunc->addStartNode(ondamagevolume_{0});", node.ID);
            }
            writer.Line("addFunc(damageFunc);");
            writer.Line(null);

            // 导出函数
            ExportTreesCpp(FilterTree("Function", trees), (tree) =>
            {
                PlatoNode funcNode = tree.Find((x) => { return x.Title == "FunctionStart"; });
                string funcName = "func" + funcNode.FindPinByTitle("Name", true).Value;
                ExportComment(writer, funcName);

                writer.Line("DramaFunc* {0} = new DramaFunc(getBattleField(), this);", funcName);
                writer.Line(null);

                // 构造函数
                foreach (PlatoNode node in tree)
                {
                    if (FilterExport(node) || node.Category == "Get")
                        continue;
                    node.ExportCpp(writer, funcName);
                }
                writer.Line(null);

                // 连线
                foreach (PlatoNode node in tree)
                {
                    if (FilterExport(node) || node.Category == "Get")
                        continue;
                    node.LinkCpp(writer);
                }
                writer.Line(null);

                foreach (PlatoNode node in funcNode.GetNextNodes(false))
                {
                    if (FilterExport(node))
                        continue;
                    writer.Line("{2}->addStartNode({0}_{1});", node.Title.ToLower(), node.ID, funcName);
                }
                writer.Line("addNameFunc(\"{0}\", {1});", funcNode.FindPinByTitle("Name", true).Value, funcName);
                writer.Line(null);
            }); writer.Line(null);

            // 导出事件
            ExportTreesCpp(FilterTree("Event", trees), (tree) =>
            {
                // TODO(kai.zou): 特殊处理的代码是没有灵魂的
                if (tree.Count == 1 && tree[0].Title == "OnDamageVolume")
                    return;

                // 尝试导出comment
                ExportComment(writer, GetNodesComment(tree));

                writer.Line("{{");
                writer.PushIndent();
                writer.Line("DramaFunc* func = new DramaFunc(getBattleField(), this);");
                writer.Line(null);

                // 构造函数
                foreach (PlatoNode node in tree)
                {
                    if (FilterExport(node) || node.Category == "Get")
                        continue;
                    node.ExportCpp(writer, "func");
                }
                writer.Line(null);

                // 连线
                foreach (PlatoNode node in tree)
                {
                    if (FilterExport(node) || node.Category == "Get")
                        continue;
                    node.LinkCpp(writer);
                }
                writer.Line(null);

                foreach (PlatoNode node in tree.FindAll((x) => { return x.Category == "Event"; }))
                {
                    writer.Line("func->addStartNode({0}_{1});", node.Title.ToLower(), node.ID);
                }
                writer.Line("addFunc(func);");
                writer.PopIndent();
                writer.Line("}}");
            }); writer.Line(null);

            writer.Line("return true;");
            writer.PopIndent();
            writer.Line("}}");

            writer.PopIndent();
            writer.Line("}}");
        }
        finally
        {
            if (writer != null)
                writer.Close();
            AssetDatabase.Refresh();
        }
    }

    void ExportTreesCpp(List<List<PlatoNode>> trees, Action<List<PlatoNode>> callback)
    {
        foreach (List<PlatoNode> tree in trees)
        {
            callback(tree);
        }
    }

    public void Comment()
    {
        EditorNode node = PLATO.CreateNode("Comment", this) as EditorNode;
        node.SetTarget(null, true);
        graph.AddNode(node);

        EditorWindow.focusedWindow.Repaint();
    }

    string GetNodesComment(List<PlatoNode> nodes)
    {
        foreach (PlatoNode node in graph.GetAllNodes())
        {
            CommentNode comment = node as CommentNode;
            if (comment == null)
                continue;
            if (comment.childEntries.Count != nodes.Count)
                continue;

            bool exists = true;
            foreach (var entry in comment.childEntries)
            {
                if (!nodes.Contains(entry.child))
                {
                    exists = false;
                    break;
                }
            }
            if (exists)
                return comment.Title;
        }
        return string.Empty;
    }

    void ExportComment(PlatoWriter writer, string comment)
    {
        writer.Line("//========================================");
        writer.Line("// {0}", comment);
        writer.Line("//");
    }

    public static bool FilterExport(PlatoNode node)
    {
        if (node is EditorNode)
            return true;
        if (node.Category == "Value" ||
            node.Category == "Function")
            return true;
        return false;
    }

    public static List<List<PlatoNode>> GetTrees(PLATO plato)
    {
        List<List<PlatoNode>> trees = new List<List<PlatoNode>>();

        foreach (PlatoNode node in plato.graph.GetAllNodes())
        {
            bool found = false;
            foreach (List<PlatoNode> tree in trees)
            {
                if (IsInTree(tree, node))
                {
                    tree.Add(node);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                trees.Add(new List<PlatoNode>(new PlatoNode[] { node }));
            }
        }
        return trees;
    }

    static bool IsInTree(List<PlatoNode> tree, PlatoNode node)
    {
        foreach (PlatoNode child in tree)
        {
            HashSet<PlatoNode> a = new HashSet<PlatoNode>(child.GetAllNextNodes(false));
            a.Add(child);
            HashSet<PlatoNode> b = new HashSet<PlatoNode>(node.GetAllNextNodes(false));
            b.Add(node);

            if (a.Overlaps(b))
                return true;
        }
        return false;
    }
    
    List<List<PlatoNode>> FilterTree(string category, List<List<PlatoNode>> trees)
    {
        List<List<PlatoNode>> result = new List<List<PlatoNode>>();
        foreach (List<PlatoNode> tree in trees)
        {
            bool found = false;
            foreach (PlatoNode node in tree)
            {
                if (node.Category == category)
                {
                    found = true;
                    break;
                }
            }

            if (found)
                result.Add(tree);
        }
        return result;
    }

    private static PlatoNode CreateMacroNode(string macroFilename, Vector2 pos, PLATO plato)
    {
        PLATO macro = new PLATO();
        macro.graph = new PlatoGraph();

        PlatoLoader loader = new PlatoLoader(macro);
        loader.Load(Path.Combine(MACRO_PATH, macroFilename) + ".txt");

        PlatoNode input = macro.graph.FindNodesByTitle("MacroInputs")[0];
        PlatoNode output = macro.graph.FindNodesByTitle("MacroOutputs")[0];

        PlatoNode node = new PlatoNode();
        node.ID = ++plato.MaxNodeID;
        node.plato = plato;
        node.SetColor(Color.gray);
        node.Title = "Macro-" + Path.GetFileNameWithoutExtension(macroFilename);
        node.Position = pos;
        foreach (PlatoPin pin in input.GetAllOutPins())
        {
            if (pin.IsDynamic) node.AddPin(pin.Title, pin.Type, true);
        }
        foreach (PlatoPin pin in output.GetAllInPins())
        {
            if (pin.IsDynamic) node.AddPin(pin.Title, pin.Type, false);
        }
        return node;
    }
}
