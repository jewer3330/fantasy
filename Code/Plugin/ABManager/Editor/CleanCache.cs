using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
using System.IO;
namespace SuperBoBo
{
    public class CleanCache
    {



        [MenuItem("Package/工具/清空缓存目录")]
        public static void Main()
        {
            if (Directory.Exists(Application.persistentDataPath))
            {
                Directory.Delete(Application.persistentDataPath, true);
            }
        }


    }
}
