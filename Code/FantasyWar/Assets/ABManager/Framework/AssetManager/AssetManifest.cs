using UnityEngine;
using System.Collections;

namespace SuperBoBo
{

    public class AssetManifest : MonoBehaviour
    {
        public static bool isDone = false;
        public static AssetBundleManifest manifest = null;

        public static IEnumerator Init()
        {
            yield return null;
            string path = string.Format("assetbundles/{0}", "assetbundles");
            byte[] datas = null;
            //缓存目录
            string fullPathInPersistent = string.Format("file://{0}/{1}", Application.persistentDataPath, path);
            WWW www = new WWW(fullPathInPersistent);
            yield return www;
            if (www.bytes != null && www.bytes.Length != 0)
            {
                datas = www.bytes;
                if (FileUtils.isEncrypt)
                {
                    FileUtils.Decrypt(ref datas);
                }
            }
            else
            {
#if UNITY_EDITOR
                string streamingPath = string.Format("file://{0}/{1}", Application.streamingAssetsPath, path);
#elif UNITY_ANDROID
                    string streamingPath = string.Format("{0}/{1}", Application.streamingAssetsPath, path);
#else
                string streamingPath = string.Format("file://{0}/{1}", Application.streamingAssetsPath, path);
#endif
                www = new WWW(streamingPath);
                yield return www;

                if (www.bytes != null && www.bytes.Length != 0)
                {
                    datas = www.bytes;
                    if (FileUtils.isEncrypt)
                    {
                        FileUtils.Decrypt(ref datas);
                    }
                }
            }
            var bs = datas;
            AssetBundle assetBundle = null;
            if (bs != null && bs.Length > 0)
            {

                AssetBundleCreateRequest abcr = AssetBundle.LoadFromMemoryAsync(bs);
                yield return abcr;
                assetBundle = abcr.assetBundle;
                bs = null;
            }
            else
            {
                Debug.LogError("Load AssetBundle: manifest  error");
            }
            isDone = true;
            manifest = (AssetBundleManifest)assetBundle.LoadAsset("assetbundlemanifest");
        }

    }
}