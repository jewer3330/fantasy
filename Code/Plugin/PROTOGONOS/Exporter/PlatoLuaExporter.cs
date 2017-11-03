using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
using System.IO;

public class PlatoLuaExporter
{
    private PLATO plato;
    private string filename;
    private HashSet<PlatoPin> eventPins = new HashSet<PlatoPin>();
    private HashSet<string> exported = new HashSet<string>();

    static private bool profileExport = false;

    public PlatoLuaExporter(PLATO plato, string filename)
    {
        this.plato = plato;
        this.filename = filename;
    }

    public void Export()
    {
        if (!Directory.Exists(PLATO.LUA_SAVE_PATH))
           Directory.CreateDirectory(PLATO.LUA_SAVE_PATH);

        string platoName = Path.GetFileNameWithoutExtension(filename);

        PlatoWriter writer = null;
        try
        {
            writer = new PlatoWriter(filename);
            writer.Line("require('plato/Plato')");
            foreach (string category in plato.graph.GetUsedCategories())
            {
                writer.Line("require('plato/{0}')", category);
            }
            writer.Line(null);

            writer.Line("{0} = Slua.Class(Plato, nil,", platoName);
            writer.Line("{{");
            writer.PushIndent();

            // Awake
            writer.Line("Awake = function(self)");
            writer.PushIndent();
            writer.Line("Super(self, {0}, 'Awake')", platoName);
            ExportValues(writer);
            ExportEventDeclares(writer);
            writer.PopIndent();
            writer.Line("end,");

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

                    List<PlatoPin> valuePins = pin.ParentNode.GetAllOutPins().FindAll((x) => PinTypeUtil.IsValue(x));
                    writer.Line(null);
                    writer.Line("{0} = function(self{1})", funcName, GetEventOutParams(pin.ParentNode));
                    writer.PushIndent();
                    foreach (PlatoPin vp in valuePins)
                    {
                        writer.Line("self.{0}_{1}_{2} = {2}", pin.ParentNode.Title, pin.ParentNode.ID, vp.Title);
                    }
                    ExportNexts(writer, pin.ParentNode, pin);
                    writer.PopIndent();
                    writer.Line("end,");
                    eventPins.Remove(pin);
                    exported.Add(funcName);
                }
            }

            writer.PopIndent();
            writer.Line("}})");
        }
        finally
        {
            if (writer != null)
                writer.Close();
            AssetDatabase.Refresh();
        }
    }

    private void ExportValues(PlatoWriter writer)
    {
        List<PlatoNode> values = plato.graph.GetAllNodes().FindAll((x) => x.Category == "Value");
        values.Sort();
        if (values.Count == 0)
            return;

        writer.Line("--Values--------------------");
        foreach (PlatoNode node in values)
        {
            writer.Line("self['{0}'] = {1}", GetValueTitle(node), GetValueDefault(node));
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

        writer.Line("--Events--------------------");
        var iter = events.GetEnumerator();
        while (iter.MoveNext())
        {
            iter.Current.Value.Sort();
            writer.Line("self.{0}Decl = {{", iter.Current.Key);
            writer.PushIndent();
            for (int i = 0; i < iter.Current.Value.Count; ++i)
            {
                var node = iter.Current.Value[i];

                List<string> eventParams = new List<string>();
                node.GetAllOutPins().FindAll((x) => PinTypeUtil.IsExec(x) && x.Nexts.Count > 0).ForEach((x) =>
                {
                    eventParams.Add(string.Format("{0} = self.{1}_{2}_{0}", x.Title, node.Title, node.ID));
                });
                node.GetAllInPins().FindAll((x) => PinTypeUtil.IsValue(x) && x.Title != node.Key).ForEach((x) =>
                {
                    eventParams.Add(string.Format("{0} = function() return {1} end", x.Title, PlatoExportUtil.ExportInPinByTitleLua(node, x.Title)));
                });

                string eventNode = string.Join(", ", eventParams.ToArray());
                if (!string.IsNullOrEmpty(node.Key))
                    writer.Line("{0} = {{{1}}},", GetEventKey(node), string.Join(", ", eventParams.ToArray()));
                else
                    writer.Line("[{0}] = {{{1}}},", i + 1, string.Join(", ", eventParams.ToArray()));
            }
            writer.PopIndent();
            writer.Line("}}");
        }
    }

    private void ExportFunctions(PlatoWriter writer)
    {
        List<PlatoNode> functions = plato.graph.GetAllNodes().FindAll((x) => x.Title == "FunctionStart");
        functions.Sort();

        foreach (PlatoNode node in functions)
        {
            writer.Line(null);
            writer.Line("{0} = function(self{1})", GetFunctionTitle(node), GetFunctionParams(node));
            writer.PushIndent();
            foreach (PlatoPin pin in node.GetAllOutPins().FindAll((x) => x.IsDynamic))
            {
                writer.Line("self.FunctionStart_{0}_{1} = {1}", node.ID, pin.Title);
            }
            ExportNexts(writer, node, node.FindPinByTitle("Start", false));
            writer.PopIndent();
            writer.Line("end,");
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

            List<PlatoPin> valuePins = node.GetAllOutPins().FindAll((x) => PinTypeUtil.IsValue(x));

            foreach (PlatoPin pin in node.GetAllOutPins())
            {
                if (!PinTypeUtil.IsExec(pin) || pin.Nexts.Count == 0)
                    continue;

                writer.Line(null);
                writer.Line("{0}_{1}_{2} = function(self{3})", GetEventTitle(node), node.ID, pin.Title, GetEventOutParams(node));
                writer.PushIndent();

                foreach (PlatoPin vp in valuePins)
                {
                    writer.Line("self.{0}_{1}_{2} = {2}", node.Title, node.ID, vp.Title);
                }

                ExportNexts(writer, node, pin);
                writer.PopIndent();
                writer.Line("end,");
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
        string call;
        if (string.IsNullOrEmpty(node.FormatLua))
            call = string.Format("{0}.{1}.{2}{{ {3} }}", node.Category, node.Title, execPin.Title, GetParams(node));
        else
            call = PlatoExportUtil.ExportFormat(node, node.FormatLua);

        List<PlatoPin> outputs = node.GetAllOutPins().FindAll((x) => PinTypeUtil.IsValue(x));
        if(profileExport)
        {
            writer.Line("Profiling.Profiler.BeginSample(\"{0}.{1}\")", node.Category, node.Title);
        }
        if (outputs.Count > 0)
        {
            List<string> results = new List<string>();
            foreach (PlatoPin pin in outputs)
            {
                results.Add(string.Format("self.{0}_{1}_{2}", pin.ParentNode.Title, pin.ParentNode.ID, pin.Title));
            }
            writer.Line("{0} = {1}", string.Join(", ", results.ToArray()), call);
        }
        else
        {
            writer.Line("{0}", call);
        }
        if (profileExport)
        {
            writer.Line("Profiling.Profiler.EndSample()");
        }
    }


    private static string GetValueTitle(PlatoNode node)
    {
        PlatoPin pp = node.FindPinByTitle("Name", true);
        if(pp != null)
        {
            return pp.Value as string;
        }

        return "";
    }

    private static string GetValueDefault(PlatoNode node)
    {
        return node.FindPinByTitle("Default", true).ExportToLua();
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
                result.Add(pin.Title);
        }
        if (result.Count == 0)
            return string.Empty;
        return ", " + string.Join(", ", result.ToArray());
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
        return string.Format("[{0}]", pin.ExportToLua());
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

    private static string GetEventOutParams(PlatoNode node)
    {
        List<string> result = new List<string>();
        foreach (PlatoPin pin in node.GetAllOutPins())
        {
            if (pin.Title != node.Key && !PinTypeUtil.IsExec(pin))
                result.Add(pin.Title);
        }
        if (result.Count == 0)
            return string.Empty;
        return ", " + string.Join(", ", result.ToArray());
    }

    private static string GetParams(PlatoNode node)
    {
        List<string> result = new List<string>();
        result.Add("Plato=self");
        result.Add(string.Format("NodeID={0}", node.ID));
        foreach (PlatoPin pin in node.GetAllInPins())
        {
            if (PinTypeUtil.IsValue(pin))
            {
                string value = null;
                if (pin.Prevs.Count == 0)
                {
                    value = pin.ExportToLua();
                }
                else
                {
                    int tempInt;
                    if (!System.Int32.TryParse(pin.Title, out tempInt))
                    {
                        PlatoPin prev = pin.Prevs[0];
                        if (PlatoExportUtil.IsGetNode(prev.ParentNode))
                        {
                            string temp = GetValueTitle(prev.ParentNode);
                            if (!string.IsNullOrEmpty(temp))
                            {
                                value = string.Format("self['{0}']", temp);
                            }
                        }
                        else
                            value = string.Format("self.{0}_{1}_{2}", prev.ParentNode.Title, prev.ParentNode.ID, prev.Title);
                    }
                }

                if (!string.IsNullOrEmpty(value))
                    result.Add(string.Format("{0}={1}", pin.Title, value));
            }
        }
        foreach (PlatoPin pin in node.GetAllOutPins())
        {
            if (PinTypeUtil.IsExec(pin))
            {
                ExecPin exec = pin as ExecPin;
                if (exec.IsEvent)
                {
                    int tempInt;
                    if (System.Int32.TryParse(pin.Title, out tempInt))
                    {
                        if (exec.Nexts.Count == 0)
                            result.Add(string.Format("{0}_{1}=nil", node.Title, pin.Title));
                        else
                            result.Add(string.Format("{0}_{1}=self.{0}_{2}_{1}", node.Title, pin.Title, node.ID));
                    }
                    else
                    {
                        if (exec.Nexts.Count == 0)
                            result.Add(string.Format("{0}=nil", pin.Title));
                        else
                            result.Add(string.Format("{0}=self.{1}_{2}_{0}", pin.Title, node.Title, node.ID));
                    }
                }
            }
        }
        return string.Join(", ", result.ToArray());
    }
}
