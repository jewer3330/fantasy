using UnityEngine;
using UnityEditor;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System;

public class Prometheus : EditorWindow
{

    public static GUISkin PTSkin;
    public static GUISkin oldSkin;
    //public static GameObject characterObj;
    //public static string modelName;

    public PTGraph curGraph = null;
   
    protected Vector2 rightMousePos = Vector2.zero;
    protected Vector2 scrollPos;
    public enum PTTabType
    {
        Character,
        SkillEditor,
        HelloWorld,
    }

    [MenuItem("Window/Prometheus &p")]
    static void Init()
    {
        PlatoNodeGenerator.Parse();

        EditorWindow window = GetWindow<Prometheus>();
        window.Show();
        PrometheusGeneralSkill generalWindow = GetWindow<PrometheusGeneralSkill>("Hydra", typeof(Prometheus));
        generalWindow.Show();
        PTCharacterWindow.Open("Character");
        PTSkin = AssetDatabase.LoadAssetAtPath<GUISkin>("Assets/Editor/Prometheus/PrometheusSkin.guiskin");

		return;
    }

    private void OnDestroy()
    {
        PrometheusUtil.curCharacter = null;
        PrometheusUtil.modelName = "";
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
