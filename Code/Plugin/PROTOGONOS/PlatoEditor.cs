using UnityEngine;
using UnityEditor;
using System.Collections;
using System.IO;

public class PlatoEditor : EditorWindow
{
    private string currentFilename = string.Empty;
    private PLATO plato;

    public static void ShowEditor(string filename = null)
    {
        PlatoEditor wnd = EditorWindow.GetWindow<PlatoEditor>();
        if (!string.IsNullOrEmpty(filename))
        {
            wnd.currentFilename = filename;
            wnd.plato = new PLATO();
            PlatoLoader loader = new PlatoLoader(wnd.plato);
            loader.Load(wnd.currentFilename);
        }
        wnd.Show();
    }

    void OnGUI()
    {
        GUILayout.Label(currentFilename, EditorStyles.boldLabel);
        GUILayout.BeginHorizontal();
        if (GUILayout.Button("OPEN", EditorStyles.toolbarButton)) Open();
        if (GUILayout.Button("SAVE", EditorStyles.toolbarButton)) Save();
        if (GUILayout.Button("EXPORT", EditorStyles.toolbarButton)) Export();
        if (GUILayout.Button("COMMENT", EditorStyles.toolbarButton)) Comment();
        GUILayout.EndHorizontal();

        if (plato != null)
            plato.DrawGUI(this, new Vector2(0, 42));
    }

    void Open()
    {
        string filename = EditorUtility.OpenFilePanel("Load", PLATO.PLATO_SAVE_PATH, "txt");
        if (!string.IsNullOrEmpty(filename))
        {
            currentFilename = filename;
            plato = new PLATO();
            PlatoLoader loader = new PlatoLoader(plato);
            loader.Load(currentFilename);
        }
    }

    void Save()
    {
        if (plato != null)
        {
            PlatoSaver saver = new PlatoSaver(plato);
            saver.Save(currentFilename);
        }
    }

    void Export()
    {
    }

    void Comment()
    {

    }
}
