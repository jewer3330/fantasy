using UnityEngine;
using UnityEditor;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System;

public class ProjectileEditor : EditorWindow
{

    public static GUISkin PTSkin;
    public static GUISkin oldSkin;
    //public static GameObject characterObj;
    //public static string modelName;

    public ProjectileGraph curGraph = null;
    public void Init(string filePath)
    {
        PlatoNodeGenerator.Parse();
        PTSkin = AssetDatabase.LoadAssetAtPath<GUISkin>("Assets/Editor/WeaponEditor/WeaponEditorSkin.guiskin");

        string fileNameOnly = Path.GetFileNameWithoutExtension(filePath);
        curGraph = WeaponEditorUtil.LoadProjGraph(fileNameOnly);
        curGraph.Init(fileNameOnly);
        return;
    }

    private void OnDestroy()
    {
        WeaponEditorUtil.curCharacter = null;
        WeaponEditorUtil.modelName = "";
        curGraph = null;
    }

    private void OnGUI()
    {
        if (curGraph == null)
            return;
        GUI.skin = PTSkin;
        curGraph.UpdateGUI(this);
        GUI.skin = null;
    }
}
