using UnityEngine;
using System;
using System.Collections;
using System.IO;

public class PROTOGONSSave : UnityEditor.AssetModificationProcessor
{
    static string[] OnWillSaveAssets(string[] paths)
    {
        if (PROTOGONOS.Instance != null)
        {
            PROTOGONOS.Instance.Save();
            return Array.FindAll(paths, (x) => { return !x.Contains(".unity"); });
        }
        return paths;
    }
}
