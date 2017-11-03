using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

public interface IPlatoCppType
{
    string Type { get; }
    string Node { get; }
    string Flow { get; }
    string ExportPath { get; }

    void ExportCppHeader(PlatoWriter writer);
    void ExportComponentHeader(PlatoWriter writer);
    void ExportCreatorDeclare(PlatoWriter writer, PLATO plato, int id, object user_data);
    void ExportCreatorImplement(PlatoWriter writer, PLATO plato, int id, object user_data);
    void ExportPhase(PlatoWriter writer, PlatoNode node, int index, List<PlatoNode> nodes);
}


public partial class PlatoCppExporter<T> where T : IPlatoCppType, new()
{
    private PLATO plato;
    private int id;
    private object user_data;
    private T cpp = new T();

    private static HashSet<string> ignores;
    static PlatoCppExporter()
    {
        ignores = new HashSet<string>();

        Action<PlatoNode> add = (PlatoNode node) =>
        {
            ignores.Add(node.Title);
        };
        PlatoNodeGenerator.FindPrototypesByCategory("Value").ForEach(add);
        PlatoNodeGenerator.FindPrototypesByCategory("Editor").ForEach(add);

        foreach (PlatoNode node in PlatoNodeGenerator.FindPrototypesByCategory("Get"))
        {
            if (!PlatoExportUtil.IsGetNode(node))
                continue;
            ignores.Add(node.Title);
        }
    }
    private static bool IsIgnoreNode(PlatoNode node)
    {
        return ignores.Contains(node.Title);
    }

    private static bool IsIgnorePin(PlatoPin pin)
    {
        if (!PinTypeUtil.IsValue(pin))
            return true;
        if (pin.Prevs.Count > 0)
            return true;
        if (!string.IsNullOrEmpty(pin.ParentPin))
            return true;
        return false;
    }

    public PlatoCppExporter(PLATO plato, int id, object user_data)
    {
        this.plato = plato;
        this.id = id;
        this.user_data = user_data;

        InitCustomNodeExport();
    }

    public void ExportCpp()
    {
        if (plato == null || plato.graph == null)
            return;

        PlatoWriter writer = null;

        try
        {
            string filename = Path.Combine(PTGraph.EXPORT_CPP_PATH, string.Format("{0}_create_{1}.h", cpp.Type.ToLower(), id));
            writer = new PlatoWriter(filename);

            writer.Line("#pragma once");
            ExportHeader(writer);

            writer.Line(null);
            writer.Line("namespace pvp {{");
            writer.Line(null);

            List<PlatoNode> nodes;
            List<PlatoNode> varNodes;
            DeclareVariables(writer, out varNodes);
            ExportNodes(writer, out nodes);
            ExportCreatorDeclare(writer);
            ExportPhase(writer, nodes);
            ExportCreatorImplement(writer, nodes, varNodes);
            cpp.ExportCreatorImplement(writer, plato, id, user_data);

            writer.Line("}} // namespace pvp");
        }
        finally
        {
            if (writer != null)
                writer.Close();
        }
    }

    public void ExportComponent()
    {
        if (plato == null || plato.graph == null)
            return;

        HashSet<string> exported = new HashSet<string>();
        foreach (PlatoNode node in plato.graph.GetAllNodes())
        {
            PlatoNode proto = PlatoNodeGenerator.FindPrototypeByTitle(node.Title);
            if (IsIgnoreNode(proto))
                continue;
            if (exported.Contains(proto.Title))
                continue;

            PlatoWriter writer = new PlatoWriter(Path.Combine(cpp.ExportPath, string.Format("{1}_psnode_{0}.h", proto.Title.ToLower(), cpp.Type.ToLower())));
            writer.Line("#pragma once");
            cpp.ExportComponentHeader(writer);

            writer.Line("namespace pvp {{");
            writer.Line(null);

            writer.Line("class {1}_{0} : public {2}PhaseNode {{", proto.Title, cpp.Node, cpp.Type);

            writer.Line("public:");
            writer.PushIndent();
            // enum trigger
            List<PlatoPin> outPins = proto.GetAllOutPins().FindAll((p) => { return PinTypeUtil.IsExec(p); });
            if (outPins.Count > 0)
            {
                writer.Line("enum EType_Trigger {{");
                writer.PushIndent();
                for (int i = 0; i < outPins.Count; ++i)
                {
                    if (outPins[i].Type != null)
                        continue;
                    writer.Line("TRIGGER_{0} = {1},", outPins[i].Title.ToUpper(), i);
                }
                writer.Line("TRIGGER_MAX = {0},", outPins.Count);
                writer.PopIndent();
                writer.Line("}};");
            }
            // enum func
            List<PlatoPin> inPins = proto.GetAllInPins().FindAll((p) => { return PinTypeUtil.IsExec(p); });
            if (inPins.Count > 0)
            {
                writer.Line("enum EType_Func {{");
                writer.PushIndent();
                for (int i = 0; i < inPins.Count; ++i)
                {
                    if (inPins[i].Type != null)
                        continue;
                    writer.Line("FUNC_{0} = {1},", inPins[i].Title.ToUpper(), i);
                }
                writer.PopIndent();
                writer.Line("}};");
            }
            // enum dropdown
            foreach (PlatoPin p in proto.GetAllInPins())
            {
                DropdownPin dropdownPin = p as DropdownPin;
                if (dropdownPin == null)
                    continue;

                writer.Line("enum {0}_{1} {{", proto.Title, p.Title);
                writer.PushIndent();
                for (int i = 0; i < dropdownPin.DropdownList.Count; ++i)
                {
                    writer.Line("{0} = {1},", dropdownPin.DropdownList[i], i);
                }
                writer.PopIndent();
                writer.Line("}};");
            }
            writer.PopIndent();

            writer.Line("public:");
            writer.PushIndent();
            writer.Line("{1}_{0}(uint16_t id, {2}Phase* phase);", proto.Title, cpp.Node, cpp.Type);
            writer.Line("virtual ~{1}_{0}();", proto.Title, cpp.Node);
            writer.Line(null);
            writer.Line("//节点更新");
            writer.Line("virtual void update({0}* flow, uint32_t ms);", cpp.Flow);
            writer.Line(null);
            writer.Line("//序列化");
            writer.Line("virtual void serializeNode(const PlatoPhaseNodeSync* sync);");
            writer.Line(null);
            writer.Line("//反序列化");
            writer.Line("virtual void deSerializeNode(PlatoPhaseNodeSync* sync);");
            writer.Line(null);
            if (proto.Category == "Event")
            {
                writer.Line("//start接口");
                writer.Line("virtual bool start({0}* flow);", cpp.Flow);
            }
            // 自定义段
            if (!string.IsNullOrEmpty(proto.FormatCpp))
            {
                writer.Line(null);
                writer.Line(proto.FormatCpp);
            }

            // interface
            foreach (PlatoPin p in proto.GetAllInPins())
            {
                if (!PinTypeUtil.IsExec(p))
                    continue;
                writer.Line("DEFINE_INTERFACE({0});", p.Title);
            }
            writer.Line(null);

            int index = 1;
            PlatoExportUtil.ExportCppParam(proto.GetAllInPins(), writer, ref index);
            PlatoExportUtil.ExportCppParam(proto.GetAllOutPins(), writer, ref index);

            writer.PopIndent();
            writer.Line("private:");
            writer.PushIndent();
            PlatoExportUtil.ExportCppField(proto.GetAllInPins(), writer);
            PlatoExportUtil.ExportCppField(proto.GetAllOutPins(), writer);
            writer.PopIndent();

            writer.Line("}};");
            writer.Line(null);
            writer.Line("}} // namespace pvp");
            writer.Close();

            exported.Add(proto.Title);
        }
    }

    private void ExportHeader(PlatoWriter writer)
    {
        cpp.ExportCppHeader(writer);

        List<string> used_nodes = new List<string>();
        foreach (PlatoNode node in plato.graph.GetAllNodes())
        {
            if (IsIgnoreNode(node))
                continue;
            if (used_nodes.Contains(node.Title.ToLower()))
                continue;
            used_nodes.Add(node.Title.ToLower());
        }
        used_nodes.Sort();
        foreach (string title in used_nodes)
        {
            writer.Line("#include \"{0}_psnode_{1}.h\"", cpp.Type.ToLower(), title);
        }
    }

    private void DeclareVariables(PlatoWriter writer, out List<PlatoNode> varNodes)
    {
        varNodes = plato.graph.GetAllNodes().FindAll((n) => { return n.Category == "Value"; });
        varNodes.Sort();

        writer.Line("//变量声明");
        foreach (PlatoNode var in varNodes)
        {
            writer.Line("uint64_t Variable_{0}_{1} = 0;", id, var.FindPinByTitle("Name", true).Value);
        }
    }

    private void ExportNodes(PlatoWriter writer, out List<PlatoNode> nodes)
    {
        nodes = plato.graph.GetAllNodes().FindAll((n) =>
        {
            return !IsIgnoreNode(n);
        });

        List<PlatoNode> removes = new List<PlatoNode>();
        foreach (var n in nodes)
        {
            if (n.Category != "Event")
            {
                int prevs = 0;
                foreach (var p in n.GetAllInPins())
                {
                    prevs += p.Prevs.Count;
                }
                if (prevs == 0)
                {
                    removes.Add(n);
                    removes.AddRange(n.GetAllNextNodes());
                }
            }
        }
        foreach (var n in removes)
        {
            nodes.Remove(n);
        }
        nodes.Sort();

        foreach (PlatoNode node in nodes)
        {
            ExportNode(writer, node);
        }
    }

    private void ExportNode(PlatoWriter writer, PlatoNode node)
    {
        writer.Line("//--------------------------------------------------------------------------------");
        writer.Line("// {0}", node.Title);
        writer.Line("//");

        writer.Line("REGISTER_REGISTER_{TYPE}_NODE({ID}, {NODEID}) {{"
            .Replace("{TYPE}", cpp.Type.ToUpper())
            .Replace("{ID}", id.ToString())
            .Replace("{NODEID}", node.ID.ToString())
        );
        writer.PushIndent();
        List<PlatoPin> outPins = node.GetAllOutPins().FindAll((p) => { return PinTypeUtil.IsExec(p); });
        if (outPins.Count > 0 && outPins.FindAll((x) => x.Nexts.Count > 0).Count > 0)
        {
            if (outPins.Find((x) => x.IsDynamic) != null)
            {
                writer.Line("pnode->resizeTrigger({0});", outPins.Count);
            }
            else
            {
                writer.Line("pnode->resizeTrigger({TYPE}_{TITLE}::TRIGGER_MAX);"
                    .Replace("{TYPE}", cpp.Node)
                    .Replace("{TITLE}", node.Title)
                );
            }
        }
        outPins.Sort();
        foreach (PlatoPin p in outPins)
        {
            if (p.Nexts.Count == 0)
                continue;

            p.Nexts.Sort();
            foreach (PlatoPin n in p.Nexts)
            {
                if (p.IsDynamic)
                {
                    writer.Line("pnode->regTrigger<{6}_{0}>({2}, {3}, {6}_{0}::FUNC_{4}, &{6}_{0}::{5});",
                            n.ParentNode.Title, node.Title, p.Title.ToUpper(), n.ParentNode.ID, n.Title.ToUpper(), n.Title, cpp.Node);
                }
                else
                {
                    writer.Line("pnode->regTrigger<{6}_{0}>({6}_{1}::TRIGGER_{2}, {3}, {6}_{0}::FUNC_{4}, &{6}_{0}::{5});",
                        n.ParentNode.Title, node.Title, p.Title.ToUpper(), n.ParentNode.ID, n.Title.ToUpper(), n.Title, cpp.Node);
                }
            }
        }
        writer.PopIndent();
        writer.Line("}}");
        writer.Line(null);

        writer.Line(@"REGISTER_CREATE_{TYPE}_NODE({ID}, {NODEID}) {{
    auto node{NODEID} = GET_{TYPE}_NODE({NODEID}, {NODE}_{TITLE});
    if (node{NODEID} == nullptr) {{
        node{NODEID} = new {NODE}_{TITLE}({NODEID}, phase);"
            .Replace("{TYPE}", cpp.Type.ToUpper())
            .Replace("{ID}", id.ToString())
            .Replace("{NODEID}", node.ID.ToString())
            .Replace("{TITLE}", node.Title)
            .Replace("{NODE}", cpp.Node)
        );

        if (node.Sync) // 同步节点
        {
            if (node.GetAllOutPins().Exists((p) => { return PinTypeUtil.IsValue(p); }))
                writer.Line("        node{0}->setMark({1}PhaseNode::E_PhaseNodeMark_SyncWhenTrigger, true);", node.ID, cpp.Type);
            else
                writer.Line("        node{0}->setMark({1}PhaseNode::E_PhaseNodeMark_SyncTrigger, true);", node.ID, cpp.Type);
            writer.Line("        node{0}->setMark({1}PhaseNode::E_PhaseNodeMark_SyncTriggerInfo, true);", node.ID, cpp.Type);
        }
        else if (node.Category == "Get") // 上传节点
        {
            writer.Line("        node{0}->setMark({1}PhaseNode::E_PhaseNodeMark_SyncInfoClient, true);", node.ID, cpp.Type);
        }

        Action<PlatoWriter, PlatoNode> customNode;
        if (CustomNodes.TryGetValue(node.Title, out customNode))
        {
            customNode(writer, node);
        }
        else
        {
            foreach (PlatoPin p in node.GetAllInPins())
            {
                if (IsIgnorePin(p))
                    continue;

                p.ExportCppPin(writer, cpp.Node);
            }
        }

        writer.Line(@"        CALL_REGISTER_{TYPE}_NODE({ID}, {NODEID}, node{NODEID})
    }}
    if (noInit == true) {{
        return node{NODEID};
    }}"
            .Replace("{TYPE}", cpp.Type.ToUpper())
            .Replace("{ID}", id.ToString())
            .Replace("{NODEID}", node.ID.ToString())
        );

        // 变量类型
        List<PlatoPin> varPins = node.GetAllInPins().FindAll((p) =>
        {
            if (p.Title == null)
                return false;
            if (p.Prevs.Count == 0)
                return false;

            PlatoNode n = p.Prevs[0].ParentNode;
            if (n.Category == "Get")
            {
                if (!PlatoExportUtil.IsGetNode(n))
                    return false;
                else
                    return true;
            }
            return false;
        });
        if (varPins.Count > 0)
        {
            writer.Line("    auto variables = node{0}->getVariables();", node.ID);
            writer.Line("    if (variables != nullptr) {{");

            foreach (PlatoPin p in varPins)
            {
                PlatoExportUtil.ExportVarPin(p, node.ID, id, writer, ExportVarPins);
            }
            writer.Line("    }}");
        }

        // 直连类型
        List<PlatoPin> linkPins = node.GetAllInPins().FindAll((p) =>
        {
            if (PinTypeUtil.IsExec(p))
                return false;
            else if (p.Prevs.Count != 1)
                return false;
            if (p.Prevs[0].ParentNode.Category == "Get")
            {
                if ( !PlatoExportUtil.IsGetNode(p.Prevs[0].ParentNode))
                    return true;
                else
                    return false;
            }
            return true;
        });
        HashSet<int> prevNodes = new HashSet<int>();
        foreach (PlatoPin p in linkPins)
        {
            prevNodes.Add(p.Prevs[0].ParentNode.ID);
        }
        foreach (int nodeId in prevNodes)
            writer.Line("    auto node{0} = GET_{2}_NODE({0}, {3}_{1});", nodeId, plato.graph.FindNodeByID(nodeId).Title, cpp.Type.ToUpper(), cpp.Node);

        PlatoExportUtil.ExportLinkPins(linkPins, writer, ExportLinkPins);
        writer.Line("    return node{0};", node.ID);
        writer.Line("}}");
    }

    private void ExportCreatorDeclare(PlatoWriter writer)
    {
        writer.Line(null);
        writer.Line("//--------------------------------------------------------------------------------");
        writer.Line("// {1}Creator_{0}", id, cpp.Type);
        writer.Line("//");
        writer.Line("class {1}Creator_{0} : public {1}Creator {{", id, cpp.Type);
        writer.Line("public:");
        writer.Line("    {1}Creator_{0}() {{}}", id, cpp.Type);
        writer.Line("    virtual ~{1}Creator_{0}() {{}}", id, cpp.Type);
        writer.Line("    virtual {0}Logic* create{0}({0}* {1}, SkillableActor* owner, uint16_t nId);", cpp.Type, cpp.Type.ToLower());
        cpp.ExportCreatorDeclare(writer, plato, id, user_data);
        writer.Line("}}; // class {1}Create_{0}", id, cpp.Type);
    }

    private void ExportPhase(PlatoWriter writer, List<PlatoNode> nodes)
    {
        writer.Line(null);
        writer.Line("//--------------------------------------------------------------------------------");
        writer.Line("// {1}Phase_{0}", id, cpp.Type);
        writer.Line("//");
        writer.Line("class {1}Phase_{0} : public {1}Phase {{", id, cpp.Type);
        writer.Line("public:");
        writer.Line("    {1}Phase_{0}(uint16_t id, {1}Logic* logic, uint16_t nFlow) : {1}Phase(id, logic, nFlow) {{}}", id, cpp.Type);
        writer.Line("    virtual ~{1}Phase_{0}() {{}}", id, cpp.Type);
        writer.Line(null);
        writer.Line("    virtual {0}PhaseNode* createPhaseNode(uint16_t nId, bool noInit) {{", cpp.Type);
        writer.Line("        SWITCH_CREATE_{0}_START", cpp.Type.ToUpper());
        foreach (PlatoNode n in nodes)
            writer.Line("        CASE_CREATE_{3}_NODE({2}, {0}) // {1}", n.ID, n.Title, id, cpp.Type.ToUpper());
        writer.Line("        SWITCH_CREATE_{0}_END", cpp.Type.ToUpper());
        writer.Line("    }}");
        writer.Line("}}; // class {1}Phase_{0}", id, cpp.Type);
    }

    private void ExportCreatorImplement(PlatoWriter writer, List<PlatoNode> nodes, List<PlatoNode> varNodes)
    {
        List<PlatoNode> eventNodes = nodes.FindAll((n) => { return n.Category == "Event"; });

        Dictionary<string, List<PlatoNode>> titles = new Dictionary<string,List<PlatoNode>>();
        eventNodes.ForEach((x) =>
        {
            List<PlatoNode> events;
            if (!titles.TryGetValue(x.Title, out events))
                titles.Add(x.Title, events = new List<PlatoNode>());
            events.Add(x);
        });

        writer.Line(null);
        writer.Line("{1}Logic* {1}Creator_{0}::create{1}({1}* {2}, SkillableActor* owner, uint16_t nId) {{", id, cpp.Type, cpp.Type.ToLower());
        writer.Line("    //创建执行逻辑");
        writer.Line("    auto logic = new {0}Logic(nId, owner, {1});", cpp.Type, cpp.Type.ToLower());
        if (varNodes.Count > 0)
        {
            writer.Line("    //设置变量");
            foreach (PlatoNode n in varNodes)
            {
                PlatoPin vp = n.FindPinByTitle("Default", true);
                if (PinTypeUtil.IsDefault(vp))
                    writer.Line("    Variable_{2}_{0} = logic->getVariables().setVariable<{1}>(\"{0}\");", n.FindPinByTitle("Name", true).Value, PinTypeUtil.GetCppType(n.FindPinByTitle("Default", true).Type), id);
                else
                    writer.Line("    Variable_{2}_{0} = logic->getVariables().setVariable<{1}>(\"{0}\", {3});", n.FindPinByTitle("Name", true).Value, PinTypeUtil.GetCppType(n.FindPinByTitle("Default", true).Type), id, vp.CppValue(cpp.Node));
            }
        }
        writer.Line("    //创建阶段phase");
        writer.Line("    auto phase = new {2}Phase_{0}(1, logic, {1});", id, titles.Count, cpp.Type);
        writer.Line("    //设置phase执行器");

        int index = 1;
        var iter = titles.GetEnumerator();
        while (iter.MoveNext())
        {
            foreach (var node in iter.Current.Value)
            {
                cpp.ExportPhase(writer, node, index, iter.Current.Value);
            }
            ++index;
        }
        writer.Line("    //添加设置phase");
        writer.Line("    logic->addPhase(phase);");
        writer.Line("    return logic;");
        writer.Line("}}");
    }
}