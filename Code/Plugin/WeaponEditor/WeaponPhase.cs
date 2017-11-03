using System;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

using GunExporter = PlatoCppExporter<PlatoCppGunType>;

//weapon phase (min unit)
[Serializable]
public class WeaponPhase
{
    public PLATO plato = new PLATO();
    public PLATO preview;

    public void Load(int weaponID)
    {
        string filename = string.Format("{0}{1}{2}.txt", PLATO.PLATO_SAVE_PATH, "WeaponEditor/WeaponScript", weaponID);
        PlatoLoader loader = new PlatoLoader(plato);
        loader.Load(filename);
    }

    public void Save(int weaponID)
    {
        string filename = string.Format("{0}{1}{2}.txt", PLATO.PLATO_SAVE_PATH, "WeaponEditor/WeaponScript", weaponID);
        PlatoSaver saver = new PlatoSaver(plato);
        saver.Save(filename);
    }

    public void LoadTemplate(string ID)
    {
        string filename = string.Format("{0}{1}{2}.txt", PLATO.PLATO_SAVE_PATH, "WeaponTemplate/", ID);
        PlatoLoader loader = new PlatoLoader(plato);
        loader.Load(filename);
    }

    public void SaveTemplate(string ID)
    {
        string filename = string.Format("{0}{1}{2}.txt", PLATO.PLATO_SAVE_PATH, "WeaponTemplate/", ID);
        PlatoSaver saver = new PlatoSaver(plato);
        saver.Save(filename);
    }

    public void Comment()
    {
        plato.Comment();
    }

    public void UpdateGUI(EditorWindow wnd, float offset)
    {
        if (preview != null)
            preview.DrawGUI(wnd, new Vector2(0, offset), false);
        else
            plato.DrawGUI(wnd, new Vector2(0, offset), false);
    }

    public void ExportLua(string filename)
    {
        plato.ExportLua(filename,true);
    }

    public void ExportCSharp(string filename)
    {
        plato.ExportCSharp(filename, true);
    }

    public void ExportNode(int weaponID)
    {
        if (plato.graph == null)
            return;

        PLATO export = new PLATO(plato);
        PLATO.ExpandMacro(export);

        string filename = string.Format("{0}/WeaponNode{1}.txt", WeaponGraph.EXPORT_LUA_PATH, weaponID);
        PlatoWriter writer = new PlatoWriter(filename);
        writer.Line("require('plato/Weapon')");
        writer.Line("require('plato/Get')");

        List<PlatoNode> inputNodes = new List<PlatoNode>();
        foreach (PlatoNode node in export.graph.GetAllNodes()) {
            if (node.Category == "Weapon")
                inputNodes.Add(node);
        }

        List<PlatoNode> outputNodes = new List<PlatoNode>();
        foreach (PlatoNode node in plato.graph.GetAllNodes()) {
            if (node.Category == "Get" && !PlatoExportUtil.IsGetNode(node))
                outputNodes.Add(node);
        }

        writer.Line("local WeaponNode{0} = {{}}", weaponID);
        writer.Line(null);

        writer.Line("WeaponNode{0}.inputs = {{}}", weaponID);
        foreach (PlatoNode node in inputNodes) {
            writer.Line("WeaponNode{0}.inputs[{1}] = {2}.{3}", weaponID, node.ID, node.Category, node.Title);
        }
        writer.Line(null);

        writer.Line("WeaponNode{0}.outputs = {{}}", weaponID);
        foreach (PlatoNode node in outputNodes) {
            writer.Line("WeaponNode{0}.outputs[{1}] = '{2}.{3}'", weaponID, node.ID, node.Category, node.Title);
        }
        writer.Line(null);

        writer.Line("return WeaponNode{0}", weaponID);
        writer.Close();
    }

    public void ExportCpp(int weaponID)
    {
        if (plato.graph == null)
            return;

        PLATO export = new PLATO(plato);
        PLATO.ExpandMacro(export);

        GunExporter exporter = new GunExporter(export, weaponID, null);
        exporter.ExportCpp();
    }

    public void ExportComponentToCpp()
    {
        if (plato.graph == null)
            return;

        PLATO export = new PLATO(plato);
        PLATO.ExpandMacro(export);

        GunExporter exporter = new GunExporter(export, 0, null);
        exporter.ExportComponent();
    }
}
