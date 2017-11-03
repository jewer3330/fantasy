using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
using System.IO;

public class PlatoCSharpExporter
{
    private PLATO plato;
    private string filename;
    private HashSet<PlatoPin> eventPins = new HashSet<PlatoPin>();
    private HashSet<string> exported = new HashSet<string>();

    public PlatoCSharpExporter(PLATO plato, string filename)
    {
        this.plato = plato;
        this.filename = filename;
    }

    public void Export()
    {
        if (!Directory.Exists(PLATO.CSHARP_SAVE_PATH))
            Directory.CreateDirectory(PLATO.CSHARP_SAVE_PATH);

        string platoName = Path.GetFileNameWithoutExtension(filename);

        PlatoWriter writer = null;
        try
        {
            writer = new PlatoWriter(filename);
            writer.Line("using UnityEngine;");
            writer.Line("using UnityEngine.UI;");
            writer.Line("using System;");
            writer.Line("using System.Collections;");
            writer.Line("using System.Collections.Generic;");
            writer.Line(null);

            writer.Line("namespace Plato {{");
            writer.PushIndent();
            writer.Line("public class {0} : PlatoCSharp {{", platoName);
            writer.PushIndent();

            ExportValues(writer);
            ExportTemps(writer);

            // Awake
            writer.Line("public override void Awake() {{");
            writer.PushIndent();
            writer.Line("base.Awake();");
            ExportEventDeclares(writer);
            writer.PopIndent();
            writer.Line("}}");
            writer.Line(null);

            // Restart
            ExportRestartFunction(writer);

            ExportFunctions(writer);
            ExportEvents(writer);

            while (eventPins.Count > 0)
            {
                HashSet<PlatoPin> copy = new HashSet<PlatoPin>(eventPins);
                foreach (PlatoPin pin in copy)
                {
                    string funcName = string.Format("{0}_{1}_{2}", pin.ParentNode.Title, pin.ParentNode.ID, pin.Title);
                    if (exported.Contains(funcName))
                    {
                        eventPins.Remove(pin);
                        continue;
                    }

                    //List<PlatoPin> valuePins = pin.ParentNode.GetAllOutPins().FindAll((x) => PinTypeUtil.IsValue(x));
                    writer.Line(null);
                    writer.Line("void {0}({1}) {{", funcName, GetEventOutParams(pin.ParentNode));
                    writer.PushIndent();
                    ExportEventOutParamsAssignToMembers(writer, pin.ParentNode);
                    ExportNexts(writer, pin.ParentNode, pin);
                    writer.PopIndent();
                    writer.Line("}}");
                    eventPins.Remove(pin);
                    exported.Add(funcName);
                }
            }

            writer.PopIndent();
            writer.Line("}}");
            writer.PopIndent();
            writer.Line("}}");
        }
        finally
        {
            if (writer != null)
                writer.Close();
        }
    }

    private void ExportValues(PlatoWriter writer)
    {
        List<PlatoNode> values = new List<PlatoNode>();
        foreach (var node in plato.graph.GetAllNodes().FindAll((x) => x.Category == "Value"))
        {
            if (values.Find((n) => GetValueTitle(n) == GetValueTitle(node)) == null)
                values.Add(node);
        }
        values.Sort();
        if (values.Count == 0)
            return;

        writer.Line("// Values--------------------");
        foreach (PlatoNode node in values)
        {
            writer.Line("{0} {1} = {2};", GetValueType(node), GetValueTitle(node), GetValueDefault(node));
        }
        writer.Line(null);
    }

    private void ExportRestartFunction(PlatoWriter writer)
    {
        List<PlatoNode> values = new List<PlatoNode>();
        foreach (var node in plato.graph.GetAllNodes().FindAll((x) => x.Category == "Value"))
        {
            if (values.Find((n) => GetValueTitle(n) == GetValueTitle(node)) == null)
                values.Add(node);
        }
        values.Sort();
        if (values.Count == 0)
            return;

        writer.Line("public override void Restart()");
        writer.Line("{{");
        writer.PushIndent();
        writer.Line("base.Restart();");
        foreach (PlatoNode node in values)
        {
            string valueType = GetValueType(node);
            if (valueType.Contains("Dictionary") || valueType.Contains("List"))
                writer.Line("if ({0} != null) {0}.Clear();", GetValueTitle(node));
            else
                writer.Line("{0} = {1};", GetValueTitle(node), GetValueDefault(node));
        }
        writer.PopIndent();
        writer.Line("}}");
    }

    private void ExportTemps(PlatoWriter writer)
    {
        List<PlatoPin> temps = new List<PlatoPin>();
        foreach (var node in plato.graph.GetAllNodes())
        {
            foreach (var pin in node.GetAllOutPins())
            {
                if (!PinTypeUtil.IsValue(pin) || (pin.Nexts.Count == 0 && node.Category == "Event"))
                    continue;

                if (!temps.Contains(pin))
                    temps.Add(pin);
            }
        }

        if (temps.Count > 0)
        {
            temps.Sort();
            writer.Line("// Temps--------------------");
            foreach (var pin in temps)
            {
                writer.Line("{0} {1}_{2}_{3};", PinTypeUtil.GetCSharpType(pin.Type), pin.ParentNode.Title, pin.ParentNode.ID, pin.Title);
            }
            writer.Line(null);
        }
    }

    private void ExportEventDeclares(PlatoWriter writer)
    {
        Dictionary<string, List<PlatoNode>> events = new Dictionary<string, List<PlatoNode>>();
        plato.graph.GetAllNodes().FindAll((x) => x.Category == "Event").ForEach((x) =>
        {
            List<PlatoNode> nodes;
            if (!events.TryGetValue(x.Title, out nodes))
                events.Add(x.Title, nodes = new List<PlatoNode>());
            nodes.Add(x);
        });

        if (events.Count == 0)
            return;

        writer.Line("// Events--------------------");
        var iter = events.GetEnumerator();
        while (iter.MoveNext())
        {
            iter.Current.Value.Sort();
            writer.Line("{0}Decl.Clear();", iter.Current.Key);
            for (int i = 0; i < iter.Current.Value.Count; ++i)
            {
                var node = iter.Current.Value[i];

                List<string> eventParams = new List<string>();
                node.GetAllOutPins().FindAll((x) => PinTypeUtil.IsExec(x) && x.Nexts.Count > 0).ForEach((x) =>
                {
                    if (node.Title == "Detect")
                    {
                        var drop = node.FindPinByTitle("Type", true) as DropdownPin;
                        eventParams.Add(string.Format("On{0} = {1}_{2}_On", drop.Value, node.Title, node.ID));
                    }
                    else
                    {
                        eventParams.Add(string.Format("{0} = {1}_{2}_{0}", x.Title, node.Title, node.ID));
                    }
                });
                node.GetAllInPins().FindAll((x) => PinTypeUtil.IsValue(x) && x.Title != node.Key).ForEach((x) =>
                {
                    //Hack type导出导出为int
                    if(x.Title == "Type" && (node.Title == "Detect" || node.Title == "WeaponDetect"))
                    {
                        eventParams.Add(string.Format("{0} = () => {{ return (int){1}; }}", x.Title, PlatoExportUtil.ExportInPinByTitleCSharp(node, x.Title)));
                    }
                    else
                        eventParams.Add(string.Format("{0} = () => {{ return {1}; }}", x.Title, PlatoExportUtil.ExportInPinByTitleCSharp(node, x.Title)));
                });

                string eventNode = string.Join(", ", eventParams.ToArray());
                if (!string.IsNullOrEmpty(node.Key))
                    writer.Line("{0}Decl.Add({1}, new {0}Entry() {{ {2} }});", iter.Current.Key, GetEventKey(node), string.Join(", ", eventParams.ToArray()));
                else
                    writer.Line("{0}Decl.Add(new {0}Entry() {{ {1} }});", iter.Current.Key, string.Join(", ", eventParams.ToArray()));
            }
        }
    }

    private void ExportFunctions(PlatoWriter writer)
    {
        List<PlatoNode> functions = plato.graph.GetAllNodes().FindAll((x) => x.Title == "FunctionStart");
        functions.Sort();

        foreach (PlatoNode node in functions)
        {
            writer.Line(null);
            writer.Line("void {0}({1}) {{", GetFunctionTitle(node), GetFunctionParams(node));
            writer.PushIndent();
            ExportNexts(writer, node, node.FindPinByTitle("Start", false));
            writer.PopIndent();
            writer.Line("}}");
        }
    }

    private void ExportEvents(PlatoWriter writer)
    {
        Dictionary<string, int> nodesCount = new Dictionary<string, int>();

        List<PlatoNode> events = plato.graph.GetAllNodes().FindAll((x) => x.Category == "Event");
        events.Sort((PlatoNode a, PlatoNode b) =>
        {
            if (a.Title == b.Title)
                return a.ID - b.ID;
            else
                return string.Compare(a.Title, b.Title);
        });

        foreach (PlatoNode node in events)
        {
            int count;
            if (!nodesCount.TryGetValue(node.Title, out count))
            {
                nodesCount.Add(node.Title, count = 1);
            }

            //List<PlatoPin> valuePins = node.GetAllOutPins().FindAll((x) => PinTypeUtil.IsValue(x));

            foreach (PlatoPin pin in node.GetAllOutPins())
            {
                if (!PinTypeUtil.IsExec(pin) || pin.Nexts.Count == 0)
                    continue;

                writer.Line(null);
                writer.Line("void {0}_{1}_{2}({3}) {{", GetEventTitle(node), node.ID, pin.Title, GetEventOutParams(node));
                writer.PushIndent();
                ExportEventOutParamsAssignToMembers(writer, node);
                ExportNexts(writer, node, pin);
                writer.PopIndent();
                writer.Line("}}");
            }
        }
    }

    //节点的输出引脚需要保存到类的成员变量下，所以需要加这一层赋值
    //对于无引用的变量不做赋值
    private static void ExportEventOutParamsAssignToMembers(PlatoWriter writer, PlatoNode node)
    {
        foreach (PlatoPin pin in node.GetAllOutPins())
        {
            if (pin.Title != node.Key && PinTypeUtil.IsValue(pin) && !(pin.Nexts.Count == 0 && node.Category == "Event"))
            {
                writer.Line(string.Format("{0}_{1}_{2} = Arg_{0}_{1}_{2};", pin.ParentNode.Title, pin.ParentNode.ID,
                    pin.Title));
            }
        }
    }

    private void ExportNexts(PlatoWriter writer, PlatoNode node, PlatoPin pin)
    {
        List<PlatoNode> nexts = node.GetNextNodesFromPin(pin);
        nexts.Sort();
        foreach (PlatoNode next in nexts)
        {
            ExportCall(writer, next, next.GetAllInPins().Find((x) => x.Prevs.Contains(pin)));
        }

        foreach (PlatoNode next in nexts)
        {
            // 副触发引脚不做后续导出，回环专用
            PlatoPin link = next.GetAllInPins().Find((x) => PinTypeUtil.IsExec(x) && x.Prevs.Contains(pin));
            if (link != null && next.GetPinIndex(link, true) != 0)
                continue;

            foreach (PlatoPin p in next.GetAllOutPins())
            {
                if (!PinTypeUtil.IsExec(p))
                    continue;
                ExecPin exec = p as ExecPin;
                if (exec.IsEvent == false)
                    ExportNexts(writer, next, p);
                else if (p.Nexts.Count > 0)
                    eventPins.Add(p);
            }
        }
    }

    private static void ExportCall(PlatoWriter writer, PlatoNode node, PlatoPin execPin)
    {
        string result = string.Empty;
        List<PlatoPin> outputs = node.GetAllOutPins().FindAll((x) => PinTypeUtil.IsValue(x));
        foreach (PlatoPin pin in outputs)
        {
            result += string.Format(", ref {0}_{1}_{2}", pin.ParentNode.Title, pin.ParentNode.ID, pin.Title);
        }

        string call;
        if (string.IsNullOrEmpty(node.FormatCSharp))
            call = string.Format("{0}.{1}.Call{2}(new {0}.{1}.Arg() {{ {3} }}{4})", node.Category, node.Title, execPin.Title, GetParams(node), result);
        else
            call = PlatoExportUtil.ExportFormat(node, node.FormatCSharp, false);
        writer.Line("{0};", call);
    }

    private static string GetValueType(PlatoNode node)
    {
        PlatoPin p = node.FindPinByTitle("Default", true);
        if (p != null)
            return PinTypeUtil.GetCSharpType(p.Type);
        return "";
    }

    private static string GetValueTitle(PlatoNode node)
    {
        PlatoPin p = node.FindPinByTitle("Name", true);
        if (p != null)
        {
            return string.Format("_{0}", p.Value as string);
        }

        return "";
    }

    private static string GetValueDefault(PlatoNode node)
    {
        return node.FindPinByTitle("Default", true).ExportToCSharp();
    }

    private static string GetFunctionTitle(PlatoNode node)
    {
        return node.FindPinByTitle("Name", true).Value as string;
    }

    private static string GetFunctionParams(PlatoNode node)
    {
        List<string> result = new List<string>();
        foreach (PlatoPin pin in node.GetAllOutPins())
        {
            if (pin.IsDynamic)
                result.Add(string.Format("{0} FunctionStart_{1}_{2}", PinTypeUtil.GetCSharpType(pin.Type), pin.ParentNode.ID, pin.Title));
        }
        if (result.Count == 0)
            return string.Empty;
        return string.Join(", ", result.ToArray());
    }

    private static string GetEventTitle(PlatoNode node)
    {
        return node.Title;
    }

    private static string GetEventKey(PlatoNode node)
    {
        if (string.IsNullOrEmpty(node.Key))
            return string.Empty;

        PlatoPin pin = node.FindPinByTitle(node.Key, true);
        return string.Format("{0}", pin.ExportToCSharp());
    }

    private static string GetEventInParams(PlatoNode node)
    {
        List<string> result = new List<string>();
        foreach (PlatoPin pin in node.GetAllInPins())
        {
            if (pin.Title != node.Key && !PinTypeUtil.IsExec(pin))
                result.Add(string.Format("{0} = {1}", pin.Title, PlatoExportUtil.ExportInPinByTitleLua(node, pin.Title)));
        }
        if (result.Count == 0)
            return string.Empty;
        return string.Join(", ", result.ToArray());
    }

    //导出Event节点方法的实参列表
    private static string GetEventOutParams(PlatoNode node)
    {
        List<string> result = new List<string>();
        foreach (PlatoPin pin in node.GetAllOutPins())
        {
            if (pin.Title != node.Key && !PinTypeUtil.IsExec(pin) && !(pin is ButtonPin))
                result.Add(string.Format("{3} Arg_{0}_{1}_{2}", pin.ParentNode.Title, pin.ParentNode.ID, pin.Title, PinTypeUtil.GetCSharpType(pin.Type)));
        }
        if (result.Count == 0)
            return string.Empty;
        return string.Join(", ", result.ToArray());
    }

    private static string GetParams(PlatoNode node)
    {
        List<string> result = new List<string>();
        result.Add("Plato=this");
        result.Add(string.Format("NodeID={0}", node.ID));
        HashSet<string> groupPins = new HashSet<string>();
        foreach (PlatoPin pin in node.GetAllInPins())
        {
            if (PinTypeUtil.IsValue(pin))
            {
                bool isButtonPin = false;
                PlatoPin parent = null;
                if (!string.IsNullOrEmpty(pin.ParentPin))
                {
                    parent = node.FindPinByTitle(pin.ParentPin, true);
                    isButtonPin = (parent != null && parent is ButtonPin);
                }
                if(isButtonPin)
                {

                    if (!groupPins.Contains(pin.ParentPin))
                    {
                        // 由按钮创建的动态输入引脚
                        var btn = parent as ButtonPin;
                        var args = btn.CSharpArg.Split(';');
                        if (args.Length == 1)
                        {
                            var title = args[0].Split(':')[0];
                            var type = args[0].Split(':')[1];
                            var group = node.GetSameParentPins(pin.ParentPin);
                            var items = new List<string>();
                            foreach (var p in group)
                            {
                                string value = null;
                                if (p.Prevs.Count == 0)
                                {
                                    value = p.ExportToCSharp();
                                }
                                else
                                {
                                    PlatoPin prev = p.Prevs[0];
                                    if (PlatoExportUtil.IsGetNode(prev.ParentNode))
                                    {
                                        string getter = GetValueTitle(prev.ParentNode);
                                        if (!string.IsNullOrEmpty(getter))
                                            value = getter;
                                    }
                                    else
                                    {
                                        value = string.Format("{0}_{1}_{2}", prev.ParentNode.Title, prev.ParentNode.ID, prev.Title);
                                    }
                                }
                                if (!string.IsNullOrEmpty(value))
                                    items.Add(value);
                            }
                            result.Add(string.Format("{0}=new {1}[{2}]{{ {3} }}", title, type, items.Count, string.Join(",", items.ToArray())));
                        }
                        else
                        {
                            var group = node.GetSameParentPins(pin.ParentPin);
                            foreach (var arg in args)
                            {
                                var title = arg.Split(':')[0];
                                var type = arg.Split(':')[1];
                                var items = new List<string>();
                                foreach (var p in group)
                                {
                                    if (!p.Title.ToLower().Contains(title.ToLower()))
                                        continue;

                                    string value = null;
                                    if (p.Prevs.Count == 0)
                                    {
                                        value = p.ExportToCSharp();
                                    }
                                    else
                                    {
                                        PlatoPin prev = p.Prevs[0];
                                        if (PlatoExportUtil.IsGetNode(prev.ParentNode))
                                        {
                                            string getter = GetValueTitle(prev.ParentNode);
                                            if (!string.IsNullOrEmpty(getter))
                                                value = getter;
                                        }
                                        else
                                        {
                                            value = string.Format("{0}_{1}_{2}", prev.ParentNode.Title, prev.ParentNode.ID, prev.Title);
                                        }
                                    }
                                    if (!string.IsNullOrEmpty(value))
                                        items.Add(value);
                                }
                                result.Add(string.Format("{0}=new {1}[{2}]{{ {3} }}", title, type, items.Count, string.Join(",", items.ToArray())));
                            }
                        }
                        groupPins.Add(pin.ParentPin);
                    }
                }
                else
                {
                    string value = null;
                    if (pin.Prevs.Count == 0)
                    {
                        value = pin.ExportToCSharp();
                    }
                    else
                    {
                        PlatoPin prev = pin.Prevs[0];
                        if (PlatoExportUtil.IsGetNode(prev.ParentNode))
                        {
                            string getter= GetValueTitle(prev.ParentNode);
                            if (!string.IsNullOrEmpty(getter))
                                value = getter;
                        }
                        else
                        {
                            value = string.Format("{0}_{1}_{2}", prev.ParentNode.Title, prev.ParentNode.ID, prev.Title);
                        }
                    }

                    if (!string.IsNullOrEmpty(value))
                        result.Add(string.Format("{0}={1}", pin.Title, value));
                }
            }
        }
        groupPins.Clear();
        foreach (PlatoPin pin in node.GetAllOutPins())
        {
            if (PinTypeUtil.IsExec(pin))
            {
                ExecPin exec = pin as ExecPin;
                if (exec.IsEvent && exec.Nexts.Count > 0)
                {
                    if (!string.IsNullOrEmpty(pin.ParentPin))
                    {
                        if (!groupPins.Contains(pin.ParentPin))
                        {
                            // 由按钮创建的动态引脚
                            var parent = node.FindPinByTitle(pin.ParentPin, false);
                            if (parent != null && parent is ButtonPin)
                            {
                                var btn = parent as ButtonPin;
                                var args = btn.CSharpArg.Split(';');
                                if (args.Length == 1)
                                {
                                    var title = args[0].Split(':')[0];
                                    var group = node.GetSameParentPins(pin.ParentPin);
                                    var items = new List<string>();
                                    foreach (var p in group)
                                    {
                                        if (p.Nexts.Count == 0)
                                            items.Add("null");
                                        else
                                            items.Add(string.Format("{0}_{1}_{2}", node.Title, node.ID, p.Title));
                                    }
                                    result.Add(string.Format("{0}=new {1}.{2}.On{0}[{3}]{{ {4} }}", title, node.Category, node.Title, items.Count, string.Join(",", items.ToArray())));
                                }
                                else
                                {
                                    // TODO: 暂时没有这种节点
                                }
                                groupPins.Add(pin.ParentPin);
                            }
                        }
                    }
                    else
                    {
                        result.Add(string.Format("{0}={1}_{2}_{0}", pin.Title, node.Title, node.ID));
                    }
                }
            }
        }
        return string.Join(", ", result.ToArray());
    }
}
