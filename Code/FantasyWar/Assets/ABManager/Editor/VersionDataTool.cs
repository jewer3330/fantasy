using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
public class VersionDataTool : EditorWindow
{
    [MenuItem("Package/工具/编辑版本信息")]
	static void Start () {
        VersionDataTool window = (VersionDataTool)EditorWindow.GetWindow(typeof(VersionDataTool));
        window.Show();
	}

    public string release = "1.0.0";
    public string beta = "1.0.0";
    public string current_beta = "1.0.0";
    

    void OnGUI()
    {
        release = EditorGUILayout.TextField("正式版本号", release);
        beta = EditorGUILayout.TextField("Beta版本号", beta);


        if (GUILayout.Button("保存"))
        {
            string path = EditorUtility.SaveFilePanel("保存地方", Application.dataPath,"version", "dat");
            VersionData data = new VersionData();
            data.beta = beta;
            data.relase = release;

            FileUtilTool.WriteFile(path, LitJson.JsonMapper.ToJson(data));
        }
    }

	


}
