using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;

public partial class PlatoCppExporter<T> where T : IPlatoCppType, new()
{
    Dictionary<string, Action<PlatoWriter, PlatoNode>> CustomNodes = new Dictionary<string, Action<PlatoWriter, PlatoNode>>();
    Dictionary<string, string> ExportLinkPins = new Dictionary<string, string>();
    Dictionary<string, string> ExportVarPins = new Dictionary<string, string>();

    void InitCustomNodeExport()
    {
        InitCustomNodes();
        InitExportLinkPins();
        InitExportVarPins();
    }

    private void InitCustomNodes()
    {
        Action<PlatoWriter, PlatoNode> reviseMapAction = (PlatoWriter writer, PlatoNode node) =>
        {
            var pinList = node.GetAllInPins();
            int reviseIndex = 0;
            for (int index = 0; index < pinList.Count; ++index)
            {
                PlatoPin p = pinList[index];

                if (p.ParentPin == "Add")
                {
                    if (reviseIndex % 2 != 0)
                        writer.Line("        node{0}->reviseValue({1}, {2});", node.ID, pinList[index - 1].CppValue(cpp.Node), p.CppValue(cpp.Node));
                    ++reviseIndex;
                    continue;
                }
                else
                {
                    if (!IsIgnorePin(p))
                        p.ExportCppPin(writer, cpp.Node);
                }
            }
        };

        CustomNodes.Add("ReviseMapI32", reviseMapAction);
        CustomNodes.Add("SetObjAttribute", reviseMapAction);

        CustomNodes.Add("TriggerCheck", (PlatoWriter writer, PlatoNode node) =>
        {
            List<PlatoNode> updateNodes = node.plato.graph.FindNodesByTitle("TriggerUpdate");
            if (updateNodes.Count == 1)
            {
                writer.Line("        auto node{0} = GET_{1}_NODE({0}, {2}_TriggerUpdate);", updateNodes[0].ID, cpp.Type.ToUpper(), cpp.Node);
                writer.Line("        if (node{0} != nullptr) node{0}->addTriggerCheck(node{1});", updateNodes[0].ID, node.ID);
                writer.Line("        ");
            }
            else if (updateNodes.Count > 0)
            {
                Debug.LogError("TriggerUpdate节点太多!");
            }
            else
            {
                Debug.LogError("缺少TriggerUpdate节点!");
            }
        });
    }

    void InitExportLinkPins()
    {
        ExportLinkPins.Add("ReviseMapI32", "    if (node{0} != nullptr) node{1}->reviseValue({2}, {3});" );
        ExportLinkPins.Add("SetObjAttribute", "    if (node{0} != nullptr) node{1}->reviseValue({2}, {3});");
    }

    void InitExportVarPins()
    {
        ExportVarPins.Add("ReviseMapI32", "        node{0}->{1}({2}, variables->getVariable<{3}>(Variable_{4}_{5}));");
        ExportVarPins.Add("SetObjAttribute", "        node{0}->{1}({2}, variables->getVariable<{3}>(Variable_{4}_{5}));");
    }
}
