using UnityEngine;
using UnityEngine.UI;
using UnityEditor;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection;
using System.IO;
using SLua;

/// <summary>
/// 节点生成器
/// </summary>
public static class PlatoNodeGenerator
{
    /// <summary>所有节点原型</summary>
    public static Dictionary<string, Dictionary<string, PlatoNode>> AllNodes = new Dictionary<string, Dictionary<string, PlatoNode>>();
    /// <summary>LUA导出路径</summary>
    static readonly string LUA_PATH = "Assets/Scripts/Slua/Resources/plato/";
    /// <summary>LUA导出路径</summary>
    static readonly string CSHARP_PATH = "Assets/Scripts/Plato/";
    /// <summary>自定义代码开始标记</summary>
    static readonly string LUA_CODE_BEGIN = "------BEGIN";
    /// <summary>自定义代码结束标记</summary>
    static readonly string LUA_CODE_END = "------END";
    /// <summary>自定义代码主函数开始标记</summary>
    static readonly string CSHARP_CODE_BEGIN = "//////BEGIN";
    /// <summary>自定义代码主函数结束标记</summary>
    static readonly string CSHARP_CODE_END = "//////END";
    /// <summary>自定义代码类成员定义开始标记</summary>
    static readonly string CSHARP_MEMBER_CODE_BEGIN = "//////MEMBER_BEGIN";
    /// <summary>自定义代码类成员定义结束标记</summary>
    static readonly string CSHARP_MEMBER_CODE_END = "//////MEMBER_END";


    /// <summary>
    /// 导出lua
    /// </summary>
    [MenuItem("Custom/PLATO to Lua")]
    public static void GenerateLua()
    {
        Parse();

        // For each category (Action, Event, Math...)
        var category = AllNodes.GetEnumerator();
        while (category.MoveNext())
        {
            string filename = Path.Combine(LUA_PATH, category.Current.Key) + ".txt";
            string nodeName = null;

            // Save old codes
            Dictionary<string, List<string>> allCodes = new Dictionary<string, List<string>>();
            if (File.Exists(filename))
            {
                using (StreamReader reader = new StreamReader(filename, System.Text.Encoding.UTF8))
                {
                    while (!reader.EndOfStream)
                    {
                        string line = reader.ReadLine();
                        if (!string.IsNullOrEmpty(nodeName))
                        {
                            if (line.Contains(LUA_CODE_END))
                                nodeName = null;
                            else
                                allCodes[nodeName].Add(line);
                        }
                        else if (line.Contains(LUA_CODE_BEGIN))
                        {
                            nodeName = line.Split(' ')[1];
                            allCodes.Add(nodeName, new List<string>());
                        }
                    }
                }
            }

            // Write lua file
            using (StreamWriter writer = new StreamWriter(filename))
            {
                writer.WriteLine("{0} = {{}}", category.Current.Key);
                writer.WriteLine();

                var node = category.Current.Value.GetEnumerator();
                while (node.MoveNext())
                {
                    // Simple export, do not need generate lua class
                    if (!string.IsNullOrEmpty(node.Current.Value.FormatLua))
                        continue;
                    if (node.Current.Value.Title == "Reroute")
                        continue;

                    // new node call
                    node.Current.Value.GetAllInPins().FindAll((x) => PinTypeUtil.IsExec(x)).ForEach((x) =>
                    {
                        nodeName = string.Format("{0}.{1}.{2}", node.Current.Value.Category, node.Current.Value.Title, x.Title);
                        writer.WriteLine("---------------------------------------------------------------------");
                        writer.WriteLine("-- {0}", nodeName);
                        node.Current.Value.GetAllInPins().FindAll((p) => PinTypeUtil.IsValue(p)).ForEach((p) =>
                        { writer.WriteLine("-- input.{0}", p.Title); });
                        node.Current.Value.GetAllOutPins().FindAll((p) => PinTypeUtil.IsValue(p)).ForEach((p) =>
                        { writer.WriteLine("-- output.{0}", p.Title); });
                        node.Current.Value.GetAllOutPins().FindAll((p) => PinTypeUtil.IsExec(p) && (p as ExecPin).IsEvent).ForEach((p) =>
                        { writer.WriteLine("-- callback.{0}", p.Title); });
                        writer.WriteLine("---------------------------------------------------------------------");
                        writer.WriteLine("{0}.{1} = {0}.{1} or {{}}", category.Current.Key, node.Current.Key);
                        writer.WriteLine("{0} = function(args)", nodeName);
                        writer.WriteLine("{0} {1} CALL------", LUA_CODE_BEGIN, nodeName);
                        List<string> codes;
                        if (allCodes.TryGetValue(nodeName, out codes))
                        {
                            foreach (string code in codes)
                            {
                                writer.WriteLine(code);
                            }
                        }
                        writer.WriteLine("{0} {1} CALL------", LUA_CODE_END, nodeName);
                        writer.WriteLine("end");
                        writer.WriteLine();
                    });
                }
            }
        }
    }

    /// <summary>
    /// 导出C#
    /// </summary>
    [MenuItem("Custom/PLATO to C#")]
    public static void GenerateCSharp()
    {
        Parse();

        if (!Directory.Exists(CSHARP_PATH))
            Directory.CreateDirectory(CSHARP_PATH);

        // For each category (Action, Event, Math...)
        var category = AllNodes.GetEnumerator();
        while (category.MoveNext())
        {
            if (category.Current.Key == "Editor")
                continue;

            string filename = Path.Combine(CSHARP_PATH, category.Current.Key) + ".cs";
            string nodeName = null;

            // Save old codes
            Dictionary<string, List<string>> callCodes = new Dictionary<string, List<string>>();
            Dictionary<string, List<string>> membersCodes = new Dictionary<string, List<string>>();
            if (File.Exists(filename))
            {
                using (StreamReader reader = new StreamReader(filename, System.Text.Encoding.UTF8))
                {
                    bool isMainFunc = true;
                    while (!reader.EndOfStream)
                    {
                        string line = reader.ReadLine();
                        if (!string.IsNullOrEmpty(nodeName))
                        {
                            if(isMainFunc)
                            {
                                if (line.Contains(CSHARP_CODE_END))
                                    nodeName = null;
                                else
                                    callCodes[nodeName].Add(line);
                            }
                            else
                            {
                                if(line.Contains(CSHARP_MEMBER_CODE_END))
                                    nodeName = null;
                                else
                                    membersCodes[nodeName].Add(line);
                            }
                        }
                        else if (line.Contains(CSHARP_CODE_BEGIN))
                        {
                            isMainFunc = true;
                            nodeName = line.Trim().Split(' ')[1];
                            callCodes.Add(nodeName, new List<string>());
                        }
                        else if (line.Contains(CSHARP_MEMBER_CODE_BEGIN))
                        {
                            isMainFunc = false;
                            nodeName = line.Trim().Split(' ')[1];
                            membersCodes.Add(nodeName, new List<string>());
                        }
                    }
                }
            }

            // Write c# file
            using (StreamWriter writer = new StreamWriter(filename))
            {
                writer.WriteLine("using UnityEngine;");
                writer.WriteLine("using UnityEngine.UI;");
                writer.WriteLine("using System;");
                writer.WriteLine("using System.Collections;");
                writer.WriteLine("using System.Collections.Generic;");
                writer.WriteLine("using SLua;");
                writer.WriteLine();

                writer.WriteLine("namespace Plato {");
                writer.WriteLine("\tpublic static class {0} {{", category.Current.Key);

                var node = category.Current.Value.GetEnumerator();
                while (node.MoveNext())
                {
                    // Simple export, do not need generate c# class
                    if (!string.IsNullOrEmpty(node.Current.Value.FormatCSharp))
                        continue;
                    if (node.Current.Value.Title == "Reroute")
                        continue;

                    writer.WriteLine("\t\tpublic static class {0} {{", node.Current.Value.Title);

                    // enum
                    node.Current.Value.GetAllInPins().FindAll((x) => x is DropdownPin && string.IsNullOrEmpty((x as DropdownPin).CallbackNodeName)).ForEach((p) =>
                    {
                        writer.WriteLine("\t\t\tpublic enum {0} {{", p.Title);
                        foreach (var item in (p as DropdownPin).DropdownList)
                        {
                            writer.WriteLine("\t\t\t\t{0}, ", item);
                        }
                        writer.WriteLine("\t\t\t}");
                    });

                    List<string> outputs = new List<string>();
                    node.Current.Value.GetAllOutPins().FindAll((o) => PinTypeUtil.IsValue(o)).ForEach((o) =>
                        { outputs.Add(string.Format("{0} {1}", PinTypeUtil.GetCSharpType(o.Type), o.Title)); });
                    string outputParam = string.Join(", ref ", outputs.ToArray());

                    // delegate
                    if(outputParam != "")
                        writer.WriteLine("\t\t\tpublic delegate void NodeTrigger(Arg args, ref {0});", outputParam);
                    else
                        writer.WriteLine("\t\t\tpublic delegate void NodeTrigger(Arg args);");

                    //后面的不需要 ref，去掉
                    outputParam = string.Join(", ", outputs.ToArray());
                    List<string> delegates = new List<string>();
                    node.Current.Value.GetAllOutPins().FindAll((p) => PinTypeUtil.IsExec(p) && (p as ExecPin).IsEvent).ForEach((p) =>
                    {
                        writer.WriteLine("\t\t\tpublic delegate void On{0}({1});", p.Title, outputParam);
                        delegates.Add(p.Title);
                    });

                    // dynamic delegate
                    List<string> delegateArray = new List<string>();
                    node.Current.Value.GetAllOutPins().FindAll((p) => (p is ButtonPin) && !string.IsNullOrEmpty((p as ButtonPin).CSharpArg)).ForEach((p) =>
                    {
                        ButtonPin btn = p as ButtonPin;
                        string[] items = btn.CSharpArg.Split(';');
                        foreach (var item in items)
                        {
                            string[] temp = item.Split(':');
                            if (temp[1] != "delegate")
                                continue;

                            writer.WriteLine("\t\t\tpublic delegate void On{0}({1});", temp[0], outputParam);
                            delegateArray.Add(temp[0]);
                        }
                    });

                    // arg
                    Dictionary<string, string> argDecl = new Dictionary<string, string>();
                    argDecl.Add("Plato", "PlatoCSharp");
                    argDecl.Add("NodeID", "int");
                    node.Current.Value.GetAllInPins().ForEach((p) =>
                    {
                        if (!PinTypeUtil.IsExec(p))
                        {
                            if (p is DropdownPin)
                            {
                                var drop = p as DropdownPin;
                                if (string.IsNullOrEmpty(drop.CallbackNodeName))
                                    argDecl.Add(p.Title, p.Title);
                                else
                                    argDecl.Add(p.Title, "string");

                                if (drop.PinDefines.Count > 0)
                                {
                                    foreach (var list in drop.PinDefines)
                                    {
                                        foreach (var pair in list)
                                        {
                                            if (!argDecl.ContainsKey(pair.Key))
                                                argDecl.Add(pair.Key, PinTypeUtil.GetCSharpType(pair.Value));
                                        }
                                    }
                                }
                            }
                            else if (p is ButtonPin)
                            {
                                var btn = p as ButtonPin;
                                if (!string.IsNullOrEmpty(btn.CSharpArg))
                                {
                                    string[] items = btn.CSharpArg.Split(';');
                                    foreach (var item in items)
                                    {
                                        string[] temp = item.Split(':');
                                        if (temp[1] == "delegate")
                                            continue;

                                        argDecl.Add(temp[0], temp[1] + "[]");
                                    }
                                }
                            }
                            else if (p is StringPin)
                            {
                                var str = p as StringPin;
                                if (!string.IsNullOrEmpty(str.TableName))
                                    argDecl.Add(p.Title, "int");
                                else
                                    argDecl.Add(p.Title, "string");
                            }
                            else if (!PinTypeUtil.IsUI(p))
                            {
                                if (!argDecl.ContainsKey(p.Title))
                                    argDecl.Add(p.Title, PinTypeUtil.GetCSharpType(p.Type));
                            }
                        }
                    });
                    writer.WriteLine("\t\t\tpublic struct Arg {");
                    var iter = argDecl.GetEnumerator();
                    while (iter.MoveNext())
                    {
                        writer.WriteLine("\t\t\t\tpublic {0} {1};", iter.Current.Value, iter.Current.Key);
                    }
                    foreach (var d in delegates)
                    {
                        writer.WriteLine("\t\t\t\tpublic On{0} {0};", d);
                    }
                    foreach (var d in delegateArray)
                    {
                        writer.WriteLine("\t\t\t\tpublic On{0}[] {0};", d);
                    }
                    writer.WriteLine("\t\t\t}");
                    writer.WriteLine();

                    // custom members
                    nodeName = string.Format("{0}.{1}", category.Current.Key, node.Current.Value.Title);
                    writer.WriteLine("\t\t\t{0} {1} MEMBERS//////", CSHARP_MEMBER_CODE_BEGIN, nodeName);
                    List<string> codes;
                    if (membersCodes.TryGetValue(nodeName, out codes))
                    {
                        foreach (string code in codes)
                        {
                            writer.WriteLine(code);
                        }
                    }
                    writer.WriteLine("\t\t\t{0} {1} MEMBERS//////", CSHARP_MEMBER_CODE_END, nodeName);

                    // call
                    node.Current.Value.GetAllInPins().FindAll((x) => PinTypeUtil.IsExec(x)).ForEach((x) =>
                    {
                        nodeName = string.Format("{0}.{1}.{2}", category.Current.Key, node.Current.Value.Title, x.Title);
                        List<string> args = new List<string>();
                        args.Add("Arg args");
                        node.Current.Value.GetAllOutPins().FindAll((p) => PinTypeUtil.IsValue(p)).ForEach((p) =>
                        { args.Add(string.Format("ref {0} {1}", PinTypeUtil.GetCSharpType(p.Type), p.Title)); });
                        writer.WriteLine("\t\t\tpublic static void Call{0}({1}) {{", x.Title, string.Join(",", args.ToArray()));
                        writer.WriteLine("\t\t\t\t{0} {1} CALL//////", CSHARP_CODE_BEGIN, nodeName);
                        if (callCodes.TryGetValue(nodeName, out codes))
                        {
                            if(codes.Count == 0)
                            {
                                writer.WriteLine("\t\t\t\tLogMgr.Instance.Log(\"{0} lack of implement!\", LogType.Error, \"Plato\");", nodeName);
                            }
                            foreach (string code in codes)
                            {
                                writer.WriteLine(code);
                            }
                        }
                        writer.WriteLine("\t\t\t\t{0} {1} CALL//////", CSHARP_CODE_END, nodeName);
                        writer.WriteLine("\t\t\t}");
                    });

                    writer.WriteLine("\t\t}");
                    writer.WriteLine();
                }

                // end of category
                writer.WriteLine("\t}");
                // end of namespace
                writer.WriteLine("}");
            }
        }
        AssetDatabase.Refresh();
    }

    /// <summary>
    /// 解析
    /// </summary>
    public static void Parse()
    {
        AllNodes.Clear();

        string[] assets = AssetDatabase.FindAssets("t:TextAsset", new string[] { "Assets/Editor Default Resources/PLATO/Defines" });
        foreach (string guid in assets)
        {
            string filename = AssetDatabase.GUIDToAssetPath(guid);
            Dictionary<string, PlatoNode> nodes = new Dictionary<string, PlatoNode>();
            Parse(filename, nodes);
            AllNodes.Add(Path.GetFileNameWithoutExtension(filename), nodes);
        }

        // Editor nodes
        Dictionary<string, PlatoNode> editorNodes = new Dictionary<string,PlatoNode>();
        var assembly = Assembly.Load("Assembly-CSharp-Editor");
        foreach (var type in assembly.GetTypes())
        {
            if (type.BaseType == typeof(EditorNode))
            {
                string name = type.Name.Substring(0, type.Name.Length - 4);
                editorNodes.Add(name, type.GetConstructor(Type.EmptyTypes).Invoke(null) as PlatoNode);
            }
        }
        AllNodes.Add("Editor", editorNodes);
    }

    /// <summary>
    /// 解析
    /// </summary>
    /// <param name="filename"></param>
    /// <param name="nodes"></param>
    static void Parse(string filename, Dictionary<string, PlatoNode> nodes)
    {
        TextAsset asset = AssetDatabase.LoadAssetAtPath<TextAsset>(filename);
        if (asset == null)
        {
            Debug.LogError(string.Format("Can not found file [{0}]", filename));
            return;
        }

        // 启动一个临时lua虚拟机来解析
        IntPtr L = LuaDLL.luaL_newstate();
        LuaDLL.luaL_openlibs(L);

        object table;
        if (LuaUtil.LoadLua(L, asset.bytes, filename, out table))
        {
            Color nodeColor = Color.white;
            LuaUtil.TravelTable(L, table as LuaTable, (key, value) =>
            {
                if (key == "Color")
                    ColorUtility.TryParseHtmlString((string)value, out nodeColor);
                else if (key == "Nodes")
                    ParseNodes(L, value as LuaTable, nodes);
            });

            // 后处理，为每个该类别下的节点设置类别和颜色
            foreach (PlatoNode node in nodes.Values)
            {
                node.Category = Path.GetFileNameWithoutExtension(filename);
                node.SetColor(nodeColor);
            }
        }

        LuaDLL.lua_close(L);
        L = IntPtr.Zero;
    }

    /// <summary>
    /// 解析节点表
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    /// <param name="nodes"></param>
    static void ParseNodes(IntPtr L, LuaTable table, Dictionary<string, PlatoNode> nodes)
    {
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            PlatoNode node = ParseNode(L, value as LuaTable);
            nodes.Add(node.Title, node);
        });
    }

    /// <summary>
    /// 解析节点
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    /// <returns></returns>
    static PlatoNode ParseNode(IntPtr L, LuaTable table)
    {
        PlatoNode node = new PlatoNode();
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            if (key == "Title")
                node.Title = (string)value;
            else if (key == "In")
                ParsePins(L, node, value as LuaTable, true);
            else if (key == "Out")
                ParsePins(L, node, value as LuaTable, false);
            else if (key == "Format")
                node.FormatLua = (string)value;
            else if (key == "FormatCpp")
                node.FormatCpp = (string)value;
            else if (key == "FormatCSharp")
                node.FormatCSharp = (string)value;
            else if (key == "Key")
                node.Key = (string)value;
            else if (key == "ExportCall")
                node.ExportCall = (bool)value;
            else if (key == "Sync")
                node.Sync = (bool)value;
        });
        return node;
    }

    /// <summary>
    /// 解析输入引脚
    /// </summary>
    /// <param name="L"></param>
    /// <param name="node"></param>
    /// <param name="table"></param>
    /// <param name="isInput"></param>
    static void ParsePins(IntPtr L, PlatoNode node, LuaTable table, bool isInput)
    {
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
			PlatoPin pin = ParsePin(L, value as LuaTable);
            pin.IsInput = isInput;
            node.AddPin(pin);
        });
    }

    /// <summary>
    /// 解析引脚数据
    /// </summary>
    /// <param name="L"></param>
    /// <param name="table"></param>
    /// <returns>名字和类型的Pair对</returns>
    static PlatoPin ParsePin(IntPtr L, LuaTable table)
    {
        PlatoPin pin = null;
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            if (key == "Type")
                pin = CreatePin(LuaObject.FindType(value as string));
		});
        LuaUtil.TravelTable(L, table, (key, value) =>
        {
            pin.Parse(key, value);
        });
        return pin;
    }
    
    /// <summary>
    /// 查找节点
    /// </summary>
    /// <param name="title">节点名</param>
    /// <returns></returns>
    public static PlatoNode FindPrototypeByTitle(string title)
    {
        var category = AllNodes.GetEnumerator();
        while (category.MoveNext())
        {
            var node = category.Current.Value.GetEnumerator();
            while (node.MoveNext())
            {
                if (node.Current.Value.Title == title)
                    return node.Current.Value;
            }
        }
        return null;
    }

    /// <summary>
    /// 查找某类别下的所有原型
    /// </summary>
    /// <param name="category">类别名</param>
    /// <returns></returns>
    public static List<PlatoNode> FindPrototypesByCategory(string category)
    {
        List<PlatoNode> result = new List<PlatoNode>();

        Dictionary<string, PlatoNode> prototypes;
        if (AllNodes.TryGetValue(category, out prototypes))
        {
            foreach (var prototype in prototypes.Values)
            {
                result.Add(prototype);
            }
        }
        return result;
    }

    /// <summary>
    /// 创建回调信息
    /// </summary>
    class CreateEntry
    {
        public PlatoNode node;
        public PLATO plato;
        public CreateEntry(PlatoNode node, PLATO plato)
        {
            this.node = node;
            this.plato = plato;
        }
    }

    /// <summary>
    /// 生成右键菜单
    /// </summary>
    /// <param name="menu"></param>
    public static void GenerateMenu(GenericMenu menu, PLATO plato)
    {
        var category = AllNodes.GetEnumerator();
        while (category.MoveNext())
        {
            if (category.Current.Key == "Editor")
                continue;

            string prefix = category.Current.Key + "/";
            var node = category.Current.Value.GetEnumerator();
            while (node.MoveNext())
            {
                menu.AddItem(new GUIContent(prefix + node.Current.Key),
                    false, CreateNode, new CreateEntry(node.Current.Value, plato));
            }
        }
    }

    /// <summary>
    /// 菜单回调，创建原型的克隆
    /// </summary>
    /// <param name="userData"></param>
    static void CreateNode(object userData)
    {
        CreateEntry entry = userData as CreateEntry;
        PlatoNode node = entry.node.Clone(entry.plato);
        PLATO.AddNode(node, entry.plato);
    }

    static Dictionary<Type, Type> AllPins = new Dictionary<Type, Type>()
    {
        { typeof(bool), typeof(BoolPin) },
        { typeof(bool[]), typeof(BoolArrayPin) },
        { typeof(int), typeof(IntPin) },
        { typeof(int[]), typeof(IntArrayPin) },
        { typeof(ulong), typeof(UInt64Pin) },
        { typeof(ulong[]), typeof(UInt64ArrayPin) },
        { typeof(float), typeof(FloatPin) },
        { typeof(float[]), typeof(FloatArrayPin) },
        { typeof(string), typeof(StringPin) },
        { typeof(Dictionary<Int32, Int32>), typeof(MapPin<Int32, Int32>) },
        { typeof(Dictionary<Int32, float>), typeof(MapPin<Int32, float>) },
        { typeof(Dictionary<UInt64, UInt64>), typeof(UInt64MapPin) },
        { typeof(GameObject), typeof(ObjectPin) },
        { typeof(Button), typeof(ButtonPin) },
        { typeof(Dropdown), typeof(DropdownPin) },
    };
    public static PlatoPin CreatePin(Type type)
    {
        Type prototype;
        if (type == null)
            prototype = typeof(ExecPin);
        else if (!AllPins.TryGetValue(type, out prototype))
            throw new Exception("Unknown pin type: " + type.ToString());
        PlatoPin pin = prototype.GetConstructor(Type.EmptyTypes).Invoke(null) as PlatoPin;
        pin.Type = type;
        PinTypeUtil.SetDefault(pin);
        return pin;
    }

    private static void WriteRequire(StreamWriter writer, List<string> list)
    {
        if (list != null)
        {
            foreach (var line in list)
            {
                writer.WriteLine(line);
            }
            writer.WriteLine();
        }
    }
}
