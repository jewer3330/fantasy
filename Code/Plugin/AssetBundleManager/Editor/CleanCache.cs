using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
using System.IO;

public class CleanCache
{

   

    [MenuItem("Tools/清空缓存目录")]
    public static void Main()
    {
        if (Directory.Exists(Application.persistentDataPath))
        {
            Directory.Delete(Application.persistentDataPath, true);
        }
    }


}
