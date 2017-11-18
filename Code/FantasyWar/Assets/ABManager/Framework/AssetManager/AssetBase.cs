
using UnityEngine;
using System.Collections;
using System.Collections.Generic;
namespace SuperBoBo
{

   

    /// <summary>
    /// 专业处理AB加载物体
    /// </summary>
    public class AssetBase : MonoBehaviour
    {

        public const string basePath = "assets/resources/{0}";

        public Object LoadAsset(string path)
        {
            Object obj = null;
            path = string.Format(basePath, path.Replace("\\", "/"));
            string assetBundleName = AssetBundleAssetRecord.GetAssetBundleName(path);
            if (!string.IsNullOrEmpty(assetBundleName))
            {
                string assetName = string.Format("{0}", AssetBundleAssetRecord.GetAssetName(path));
                ABsManager.Load(assetBundleName);
                obj = ABsManager.Instance.loadedAssetBundles[assetBundleName].GetRes(assetName);

            }


            return obj;
        }

        public void UnloadAsset(string path)
        {
            path = path.Replace("\\", "/");
            path = string.Format(basePath, path.Replace("\\", "/"));
            string assetBundleName = AssetBundleAssetRecord.GetAssetBundleName(path);
            ABsManager.Unload(assetBundleName);
        }



        public class ObjectRequest
        {
            public string path;
            public List<System.Action<Object>> callbacks = new List<System.Action<Object>>();

            public ObjectRequest(string assetBundleName, System.Action<Object> callback)
            {
                this.path = assetBundleName;
                if (callback != null)
                    this.callbacks.Add(callback);
            }
        }

        public static List<ObjectRequest> ors = new List<ObjectRequest>();

        public ObjectRequest FindObjectRequest(string key)
        {
            foreach (var k in ors)
            {
                if (k.path == key)
                {
                    return k;
                }
            }
            return null;
        }












        public IEnumerator LoadAssetAsync(string path, System.Action<Object> callback)
        {
            path = string.Format(basePath, path.Replace("\\", "/"));
            string assetBundleName = AssetBundleAssetRecord.GetAssetBundleName(path);

            ObjectRequest or = FindObjectRequest(path);
            if (or == null)
            {
                or = new ObjectRequest(path, callback);
                ors.Add(or);

                yield return ABsManager.LoadAsync(assetBundleName);

                string assetName = string.Format("{0}", AssetBundleAssetRecord.GetAssetName(path));
                //yield return ABsManager.Find(assetBundleName).LoadFromMemeroyAsync();
                Object obj = ABsManager.Find(assetBundleName).GetRes(assetName);

                if (or == null)
                {
                    Debug.LogError("or is removed");
                };

                if (or.callbacks != null)
                {
                    Debug.Log("or callback count = " + or.callbacks.Count + "  " + or.path);
                    foreach (var k in or.callbacks)
                    {
                        k(obj);
                    }
                    or.callbacks.Clear();
                }
                ors.Remove(or);
            }
            else
            {
                or.callbacks.Add(callback);
            }



            //if (callback != null) callback(obj);
        }
    }
}

