using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
using System.IO;

public class PlatoSaver
{
    private PLATO plato;

    public PlatoSaver(PLATO plato)
    {
        this.plato = plato;
    }

    public void Save(string filename)
    {
        if (plato.graph == null)
            return;

        if (!Directory.Exists(PLATO.PLATO_SAVE_PATH))
            Directory.CreateDirectory(PLATO.PLATO_SAVE_PATH);

        PlatoWriter writer = null;
        try
        {
            writer = new PlatoWriter(filename);
            writer.Line("local {0} = {{", Path.GetFileNameWithoutExtension(filename));

            writer.PushIndent();
            writer.Line("nodes = {{");
            writer.PushIndent();
            foreach (PlatoNode node in plato.graph.GetAllNodes())
            {
                if (node is EditorNode)
                    continue;

                writer.Line("{{");
                writer.PushIndent();

                writer.Line("id = {0},", node.ID);
                writer.Line("type = '{0}',", node.Title);
                writer.Line("posX = {0},", node.Position.x);
                writer.Line("posY = {0},", node.Position.y);

                writer.Line("inPins = {{");
                writer.PushIndent();
                SavePins(node.GetAllInPins(), writer);
                writer.PopIndent();
                writer.Line("}},");

                writer.Line("outPins = {{");
                writer.PushIndent();
                SavePins(node.GetAllOutPins(), writer);
                writer.PopIndent();
                writer.Line("}},");

                writer.PopIndent();
                writer.Line("}},");
            }
            writer.PopIndent();
            writer.Line("}},");
            writer.PopIndent();

            writer.PushIndent();
            writer.Line("comments = {{");
            writer.PushIndent();
            foreach (PlatoNode node in plato.graph.GetAllNodes().FindAll((x) => { return x is CommentNode; }))
            {
                (node as CommentNode).Save(writer);
            }
            writer.PopIndent();
            writer.Line("}},");
            writer.PopIndent();

            writer.Line("}}");
            writer.Line("return {0}", Path.GetFileNameWithoutExtension(filename));
        }
        finally
        {
            if (writer != null)
                writer.Close();
            AssetDatabase.Refresh();
        }
    }

    /// <summary>
    /// 保存引脚
    /// </summary>
    /// <param name="pins"></param>
    /// <param name="writer"></param>
    void SavePins(List<PlatoPin> pins, PlatoWriter writer)
    {
        foreach (PlatoPin pin in pins)
        {
            writer.Line("{{");
            writer.PushIndent();

            pin.Save(writer);

			writer.Line("prevs = {{");
            writer.PushIndent();
            foreach (PlatoPin prev in pin.Prevs)
            {
                writer.Line("{{");
                writer.PushIndent();
                writer.Line("prevId = {0},", prev.ParentNode.ID);
                writer.Line("prevTitle = '{0}',", prev.Title);
                writer.PopIndent();
                writer.Line("}},");
            }
            writer.PopIndent();
            writer.Line("}},");

            writer.PopIndent();
            writer.Line("}},");
        }
    }
}
