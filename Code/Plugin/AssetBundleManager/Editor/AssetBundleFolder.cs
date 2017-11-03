using UnityEngine;
using System.Collections;
using System.Collections.Generic;

/// <summary>
/// 假设是AssetBundle目录
/// </summary>
public class AssetBundleFolder
{
    static List<string> m_folderList;

    static AssetBundleFolder()
    {
        m_folderList = new List<string>();
        string dataFile = Application.dataPath + "/Libs/AssetBundleManager/Editor/folder.dat";
        string data = FileUtilTool.ReadFile(dataFile);
        string[] lines = data.Split('\n');
        foreach (string line in lines)
        {
            if (!string.IsNullOrEmpty(line))
            {
                string content = line.Replace("\r", "");
                m_folderList.Add(content);
            }
        }
    }


    /// <summary>
    /// 
    /// </summary>
    /// <param name="path"></param>
    /// <returns></returns>
    public static string GetAssetBundleName(string path)
    {
        foreach (string folder in m_folderList)
        {
            string[] f = folder.Split('\t');
            string folderName = f[0];
            string assetBundleName = f[1];
            if (path.Contains(folderName.ToLower()))
            {
                return assetBundleName;
            }

            if (path.Contains(folderName))
            {
                return assetBundleName;
            }
        }
        return path;
    }
}