using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class PlatoCppSkillType : IPlatoCppType
{
    public string Type { get { return "Skill"; } }
    public string Node { get { return "PhaseNode"; } }
    public string Flow { get { return "SkillRunFlow"; } }
    public string ExportPath { get { return PTGraph.EXPORT_CPP_PATH; } }

    public void ExportCppHeader(PlatoWriter writer)
    {
        writer.Line(null);
        writer.Line("#include \"node.hpp\"");
        writer.Line("#include \"skill.h\"");
        writer.Line("#include \"skill_factory.h\"");
        writer.Line(null);
    }
    public void ExportComponentHeader(PlatoWriter writer)
    {
        writer.Line(null);
        writer.Line("#include \"node.hpp\"");
        writer.Line("#include \"skill.h\"");
        writer.Line(null);
    }

    public void ExportCreatorDeclare(PlatoWriter writer, PLATO plato, int id, object user_data)
    {
        writer.Line("    virtual bool getSkillExpend(int32_t& nType, int32_t& nValue);");
    }

    public void ExportCreatorImplement(PlatoWriter writer, PLATO plato, int id, object user_data)
    {
        SkilldataSetting setting = user_data as SkilldataSetting;

        writer.Line(null);
        writer.Line("bool SkillCreator_{0}::getSkillExpend(int32_t& nType, int32_t& nValue) {{", id);
        writer.Line("    return true;");
        writer.Line("}}");
    }

    public void ExportPhase(PlatoWriter writer, PlatoNode node, int index, List<PlatoNode> nodes)
    {
        if (node.Title == "CancelPhase")
            writer.Line("    phase->addCancelPhaseNode({0}, {1});", index, node.ID);
        else if (node.Title == "ConfirmPhase")
            writer.Line("    phase->addConfirmPhaseNode({0}, {1});", index, node.ID);
        else if (node.Title == "Detect")
            writer.Line("    phase->setDetectPhaseNode({0}, {1});", index, node.ID);
        else
            writer.Line("    phase->setRunPhaseNode({0}, {1});", index, node.ID);
    }
}

