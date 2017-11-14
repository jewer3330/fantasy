using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
namespace SuperBoBo
{
    public class URLConfigTool : EditorWindow
    {

        [MenuItem("Package/工具/CDN输出工具")]
        public static void Init()
        {
            URLConfigTool window = (URLConfigTool)EditorWindow.GetWindow(typeof(URLConfigTool));
            window.Show();
        }

        public string c_url = "http://116.236.180.14";
        public List<string> urls = new List<string>();

        public void OnGUI()
        {
            c_url = EditorGUILayout.TextField(c_url);
            if (GUILayout.Button("增加"))
            {
                if (!urls.Contains(c_url))
                {
                    urls.Add(c_url);
                }
            }
            scrollPosition = EditorGUILayout.BeginScrollView(scrollPosition);
            for (int i = 0; i < urls.Count; i++)
            {
                EditorGUILayout.BeginHorizontal();
                urls[i] = EditorGUILayout.TextField(urls[i]);
                if (GUILayout.Button("删除"))
                {
                    urls.RemoveAt(i);
                }
                EditorGUILayout.EndHorizontal();
            }

            EditorGUILayout.EndScrollView();

            if (GUILayout.Button("保存"))
            {
                string content = string.Join("\r\n", urls.ToArray());
                FileUtils.WriteFile(Application.streamingAssetsPath + "/url.dat", content, true);
                AssetDatabase.SaveAssets();
                AssetDatabase.Refresh();
            }
        }


        public Vector2 scrollPosition { get; set; }
    }
}