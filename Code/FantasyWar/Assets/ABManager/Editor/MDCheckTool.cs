using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;

public class MDCheckTool  : EditorWindow
{

    [MenuItem("Package/工具/更新量大小测试")]
     public static void Init()
    {
        MDCheckTool window = (MDCheckTool)EditorWindow.GetWindow(typeof(MDCheckTool));
        window.Show();   
    }

    public string version1 = "1.0.0";
    public string version2 = "1.0.0";
    public Vector2 scroll;
    void OnGUI()
    { 
        EditorGUILayout.LabelField("比较版本号");

        version1 = EditorGUILayout.TextField(version1);
        version2 = EditorGUILayout.TextField(version2);

        if (GUILayout.Button("本地比较"))
        {
            string md1 = string.Format("{0}/{1}/{2}/{3}", "file://" + Application.dataPath.Replace("Assets",""), ResSetting.build_root_path, version1, "MD.dat");
            string md2 = string.Format("{0}/{1}/{2}/{3}", "file://" + Application.dataPath.Replace("Assets",""), ResSetting.build_root_path, version2, "MD.dat");

            DownloadFile(md1, OnMd1Finish);
            DownloadFile(md2, OnMd2Finish);
        }

        if (GUILayout.Button("远程比较"))
        {
            string md1 = string.Format("{0}/{1}/{2}/{3}", FileUtils.url, ResSetting.GetChannelRes(), version1, "MD.dat");
            string md2 = string.Format("{0}/{1}/{2}/{3}", FileUtils.url, ResSetting.GetChannelRes(), version2, "MD.dat");

            DownloadFile(md1, OnMd1Finish);
            DownloadFile(md2, OnMd2Finish);

            
        }

        int length = 0;
        scroll = EditorGUILayout.BeginScrollView(scroll);
        if (updates != null && updates.Count != 0)
        {
            EditorGUILayout.LabelField("需要更新的文件");
            length = OnGUIAssetbundleJsonData(updates);
            EditorGUILayout.LabelField("需要删除的文件");            
            OnGUIAssetbundleJsonData(deletes);
        }
        GUI.color = Color.white;
        EditorGUILayout.EndScrollView();

        string text = "总大小 " + (length >> 20) + "MB";
        
        if (updates != null && updates.Count != 0)
        {
            text += " 总文件个数 " + j2.arrayRes.Length;
            text += " 更新文件个数 " + updates.Count;
            text += " 更新占比 " + (float)updates.Count / (float)(j2.arrayRes.Length);
            text += " 删除文件个数 " + deletes.Count;
            text += " 新增文件个数 " + adds.Count;
        }
        EditorGUILayout.LabelField(text);
    }


    public AssetbundleJsonMap GetJson(byte[] bytes)
    {
        string md2data = FileUtils.ReadStringFromBytes(bytes, false);
        AssetbundleJsonMap json = LitJson.JsonMapper.ToObject<AssetbundleJsonMap>(md2data);
        return json;
    }

    AssetbundleJsonMap j2;
    AssetbundleJsonMap j1;
    List<AssetbundleJsonData> updates;
    List<AssetbundleJsonData> deletes;
    List<AssetbundleJsonData> adds;



    int OnGUIAssetbundleJsonData(List<AssetbundleJsonData> updates)
    {
        int length = 0;
        foreach (var k in updates)
        {
            
           
            EditorGUILayout.BeginHorizontal();
            string flag = "";
            if (deletes.Contains(k))
            {
                GUI.color = Color.red;
                flag = "-";
            }
            else if (adds.Contains(k))
            {
                flag = "+";
                GUI.color = Color.green;
            }
            else
            {
                flag = "";
                GUI.color = Color.yellow;
            }

            EditorGUILayout.LabelField(flag, GUILayout.Width(50));
            
            if ((k.length >> 20) >= 5)
            {
                GUI.color = Color.red;
            }
            else if ((k.length >> 20) >= 1)
            {
                GUI.color = Color.yellow;
            }
            else
            {
                GUI.color = Color.white;
            }
            
            EditorGUILayout.LabelField(k.resName ,GUILayout.Width(500));
            EditorGUILayout.LabelField((k.length >> 20) + " MB",GUILayout.Width(100));
            EditorGUILayout.LabelField((k.length >> 10) + " KB",GUILayout.Width(100));
            EditorGUILayout.LabelField(k.length.ToString() + " Byte");

            EditorGUILayout.EndHorizontal();

            length += k.length;


        }

        return length;
    }

    private void OnMd2Finish(WWW www)
    {
        j2 =  GetJson(www.bytes);
        updates = CompareMD(j2, j1);
        deletes = DeleteMD(j2, j1);
        adds = AddMD(j2, j1);

        updates.Sort(Sort);
        adds.Sort(Sort);
        deletes.Sort(Sort);
    }

    int Sort(AssetbundleJsonData l, AssetbundleJsonData r)
    {
        if (l.length > r.length)
        {
            return -1;
        }
        else if (l.length < r.length)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    private void OnMd1Finish(WWW www)
    {
       j1 = GetJson(www.bytes);
       
    }
    
    public delegate void OnDownloadFinish(WWW www);

    public void DownloadFile(string url, OnDownloadFinish callback)
    {
        Debug.Log("下载文件 " + url);

        WWW www = new WWW(url + "?time=" + System.DateTime.Now.Ticks + "&r=" + Random.Range(int.MinValue, int.MaxValue));

        while (true)
        {
            if (www.isDone || !string.IsNullOrEmpty(www.error))
            {
                break;
            }
        }
        
        if (string.IsNullOrEmpty(www.error))
            callback(www);

    }


    public List<AssetbundleJsonData> CompareMD(AssetbundleJsonMap cdn, AssetbundleJsonMap map2)
    {

        List<AssetbundleJsonData> updateFiles = new List<AssetbundleJsonData>();

        //long length = 0;
        for (int i = 0; i < cdn.arrayRes.Length; i++)
        {
            AssetbundleJsonData data = cdn.arrayRes[i];
            AssetbundleJsonData local = map2.GetJsonData(data.resName);
            if (local == null)
            {
                //length += data.length;
                updateFiles.Add(data);
            }
            else if (data.hashCode == local.hashCode)
            {

            }
            else
            {
                updateFiles.Add(data);
                //length += data.length;
            }
        }
        return updateFiles;
    }


    public List<AssetbundleJsonData> DeleteMD(AssetbundleJsonMap cdn, AssetbundleJsonMap map2)
    {

        List<AssetbundleJsonData> updateFiles = new List<AssetbundleJsonData>();

        
        foreach (var k in map2.arrayRes)
        {
            bool find = false;
            foreach (var j in cdn.arrayRes)
            {
                if (k.resName == j.resName)
                {
                    find = true;
                    break;
                }
            }
            if (!find)
            {
                updateFiles.Add(k);
            }
        }
        return updateFiles;
    }

    public List<AssetbundleJsonData> AddMD(AssetbundleJsonMap cdn, AssetbundleJsonMap map2)
    {

        List<AssetbundleJsonData> updateFiles = new List<AssetbundleJsonData>();


        foreach (var k in cdn.arrayRes)
        {
            bool find = false;
            foreach (var j in map2.arrayRes)
            {
                if (k.resName == j.resName)
                {
                    find = true;
                    break;
                }
            }
            if (!find)
            {
                updateFiles.Add(k);
            }
        }
        return updateFiles;
    }
}
