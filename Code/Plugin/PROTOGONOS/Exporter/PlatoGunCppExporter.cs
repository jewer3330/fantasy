using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class PlatoCppGunType : IPlatoCppType
{
    public string Type { get { return "Gun"; } }
    public string Node { get { return "GunPhaseNode"; } }
    public string Flow { get { return "PlatoRunFlow"; } }
    public string ExportPath { get { return WeaponGraph.EXPORT_CPP_PATH; } }

    public void ExportCppHeader(PlatoWriter writer)
    {
        writer.Line(null);
        writer.Line("#include \"node.hpp\"");
        writer.Line("#include \"gun_logic.h\"");
        writer.Line(null);
    }

    public void ExportComponentHeader(PlatoWriter writer)
    {
        ExportCppHeader(writer);
    }


    public void ExportCreatorDeclare(PlatoWriter writer, PLATO plato, int id, object user_data)
    {

    }
    public void ExportCreatorImplement(PlatoWriter writer, PLATO plato, int id, object user_data)
    {

    }

    public void ExportPhase(PlatoWriter writer, PlatoNode node, int index, List<PlatoNode> nodes)
    {
        writer.Line("    phase->set{0}Node({1}, {2});", node.Title, index, node.ID);
    }
}
