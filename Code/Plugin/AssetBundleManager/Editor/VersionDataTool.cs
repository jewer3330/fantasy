using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
public class VersionDataTool : EditorWindow
{ 
    [MenuItem("Tools/输出VersionData")]
	static void Start () {
        VersionDataTool window = (VersionDataTool)EditorWindow.GetWindow(typeof(VersionDataTool));
        window.Show();
	}

    public string release = "1.0.0";
    public string beta = "1.0.0";
    public string current_beta = "1.0.0";
    
    public List<string> betaList = new List<string>();

    void OnGUI()
    {
        release = EditorGUILayout.TextField("正式版本号", release);
        beta = EditorGUILayout.TextField("Beta版本号", beta);

        EditorGUILayout.BeginHorizontal();

        current_beta = EditorGUILayout.TextField("增加Beta版本号", current_beta);        
       
        if (GUILayout.Button("增加"))
        {
            if (!betaList.Contains(current_beta))
                betaList.Add(current_beta);
        }

        EditorGUILayout.EndHorizontal();
        scrollPosition = EditorGUILayout.BeginScrollView(scrollPosition);

        for (int i = 0; i < betaList.Count;i++)
        {
            EditorGUILayout.BeginHorizontal();

            betaList[i] = EditorGUILayout.TextField("Beta版本号", betaList[i]);
            if (GUILayout.Button("删除"))
            {
                betaList.RemoveAt(i);
            }
            EditorGUILayout.EndHorizontal();

        }
        EditorGUILayout.EndScrollView();


        if (GUILayout.Button("保存"))
        {
            string path = EditorUtility.SaveFilePanel("保存地方", Application.dataPath,"beta", "dat");
            GameUpdater.VersionData data = new GameUpdater.VersionData();
            data.beta = beta;
            data.betaList = betaList;
            data.relase = release;

            FileUtilTool.WriteFile(path, LitJson.JsonMapper.ToJson(data));
        }
    }

	void Update () {
	
	}


    public Vector2 scrollPosition { get; set; }
}
