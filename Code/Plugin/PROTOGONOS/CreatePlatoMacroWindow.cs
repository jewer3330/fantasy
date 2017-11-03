using UnityEngine;
using UnityEditor;
using System.Collections;
using System.IO;

public class CreatePlatoMacroWindow : EditorWindow
{
    private string macroFilename = string.Empty;

    public static void PopUp()
    {
        EditorWindow.GetWindow<CreatePlatoMacroWindow>(true);
    }

    void OnGUI()
    {
        GUILayout.BeginVertical();
        GUILayout.Label("Create Macro", EditorStyles.boldLabel);
        GUILayout.Space(10);
        macroFilename = GUILayout.TextField(macroFilename);
        GUILayout.Space(20);
        GUILayout.BeginHorizontal();
        if (GUILayout.Button("OK")) CreateMacro();
        if (GUILayout.Button("Cancel")) Close();
        GUILayout.EndHorizontal();
        GUILayout.EndVertical();
    }

    void CreateMacro()
    {
        string filename = Path.Combine(PLATO.MACRO_PATH, macroFilename) + ".txt";

        PLATO macro = new PLATO();
        macro.graph = new PlatoGraph();

        PlatoNode input = PlatoNodeGenerator.FindPrototypeByTitle("MacroInputs").Clone(macro);
        PlatoNode output = PlatoNodeGenerator.FindPrototypeByTitle("MacroOutputs").Clone(macro);
        input.Position = new Vector2(100.0f, 100.0f);
        output.Position = new Vector2(300.0f, 100.0f);

        macro.graph.AddNode(input);
        macro.graph.AddNode(output);
        PlatoSaver saver = new PlatoSaver(macro);
        saver.Save(filename);
        Close();

        PlatoEditor.ShowEditor(filename);
    }
}
