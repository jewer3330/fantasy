using UnityEngine;
using System.Collections;
using System;
using System.Collections.Generic;
using System.IO;
namespace SuperBoBo
{

    [System.Serializable]
    public class LoadedAssetBundle
    {
        public string assetbundlename;
        public AssetBundle m_AssetBundle;
        public int m_ReferencedCount;
        protected Dictionary<string, UnityEngine.Object> objMap = new Dictionary<string, UnityEngine.Object>();
        public bool loaded = false;
        byte[] datas = null;



        public void AddRef()
        {


            m_ReferencedCount++;

            //string[] deps = ABsManager.m_AssetBundleManifest.GetAllDependencies(assetbundlename);
            //for (int i = 0; i < deps.Length; i++)
            //{
            //    string dep = deps[i];
            //    if (ABsManager.Instance.loadedAssetBundles.ContainsKey(dep))
            //        ABsManager.Instance.loadedAssetBundles[dep].AddRef();
            //    else
            //    {
            //        ABsManager.Load(dep);
            //    }
            //}

#if UNITY_EDITOR
            //Debug.LogWarning(assetbundlename + " addref = " + m_ReferencedCount);
#endif

        }



        public void RemoveRef()
        {


            m_ReferencedCount--;
//            string[] deps = ABsManager.m_AssetBundleManifest.GetAllDependencies(assetbundlename);
//            for (int i = 0; i < deps.Length; i++)
//            {
//                string dep = deps[i];
//                if (ABsManager.Instance.loadedAssetBundles.ContainsKey(dep))
//                    ABsManager.Instance.loadedAssetBundles[dep].RemoveRef();
//            }
//#if UNITY_EDITOR
//            //Debug.LogWarning(assetbundlename + " removeref = " + m_ReferencedCount);
//#endif

        }

        public LoadedAssetBundle(string s)
        {
            if (!ABsManager.Instance.loadedAssetBundles.ContainsKey(s))
            {
                m_ReferencedCount = 0;
                assetbundlename = s;
                ABsManager.Instance.loadedAssetBundles.Add(assetbundlename, this);
            }
        }

        public void Load()
        {
            m_AssetBundle = ABsManager.LoadInternal(assetbundlename);
            loaded = true;

        }





        public IEnumerator LoadAsync()
        {

            string path = string.Format("assetbundles/{0}", assetbundlename);
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



            var abcr = AssetBundle.LoadFromMemoryAsync(datas);
            if (abcr != null)
            {
                yield return abcr;
                m_AssetBundle = abcr.assetBundle;
                loaded = true;
            }
            else
            {
                Debug.LogError("error load " + assetbundlename);
            }
            loaded = true;

        }





        public UnityEngine.Object GetRes(string s)
        {

            if (objMap.ContainsKey(s))
            {
                return objMap[s];

            }
            else
            {
                UnityEngine.Object o = null;
                if (m_AssetBundle == null)
                {
                    Debug.LogError("assetbundle already unloaded " + assetbundlename);
                }
                else
                {
                    objMap.Add(s, m_AssetBundle.LoadAsset(s));
                    //Util.LogError("load " + s);
                    o = objMap[s];
                    ABsManager.objMap.Add(o, assetbundlename);
                    //if (o is GameObject)
                    //{
                    //    GameObject g = o as GameObject;
                    //    if (g.GetComponent<UIAtlas>() == null)
                    //        m_AssetBundle.Unload(false);
                    //    else
                    //    {
                    //        //Util.LogError("skip " + assetbundlename);
                    //    }
                    //}
                }

                return o;
            }

        }

        public void UnLoad(bool b)
        {
            datas = null;
            m_ReferencedCount = 0;
            loaded = false;

            List<string> keys = new List<string>(objMap.Keys);
            foreach (string key in keys)
            {
                if (ABsManager.objMap.ContainsKey(objMap[key]))
                    ABsManager.objMap.Remove(objMap[key]);
                objMap[key] = null;
            }

            objMap.Clear();

            if (m_AssetBundle != null)
            {
                m_AssetBundle.Unload(b);
            }
            else
            {
                Debug.LogError("error unloaded " + assetbundlename);
            }
        }
    }


    public class ABsManager : MonoBehaviour
    {
        static ABsManager m_instance;
        public static AssetBundleManifest m_AssetBundleManifest = null;
        public Dictionary<string, LoadedAssetBundle> loadedAssetBundles = new Dictionary<string, LoadedAssetBundle>();
        public static Dictionary<UnityEngine.Object, string> objMap = new Dictionary<UnityEngine.Object, string>();
        //Dictionary<string, LoadedAssetBundle> unusedAssetBundles = new Dictionary<string, LoadedAssetBundle>();
#if UNITY_EDITOR
        public List<LoadedAssetBundle> watches = new List<LoadedAssetBundle>();
#endif

        public static LoadedAssetBundle Find(string assetBundleName)
        {

            if (m_instance == null || !m_instance.loadedAssetBundles.ContainsKey(assetBundleName))
            {
                return null;
            }

            return m_instance.loadedAssetBundles[assetBundleName];
        }


#if UNITY_EDITOR
        void Update()
        {
            if (Input.GetKey(KeyCode.Tab))
            {
                foreach (KeyValuePair<string, LoadedAssetBundle> pair in loadedAssetBundles)
                {
                    Debug.Log(pair.Value.assetbundlename + "  " + pair.Value.m_ReferencedCount);
                }
            }
        }
#endif

        public static ABsManager Instance
        {
            get
            {
                if (m_instance == null)
                {
#if UNITY_EDITOR
                    if (!Application.isPlaying)
                    {
                        m_instance = new ABsManager();
                        m_instance.Init();
                        return m_instance;
                    }
#endif


                    m_instance = ResManager.Instance.gameObject.AddComponent<ABsManager>();

                }
                return m_instance;
            }
        }






        static void _Load(string assetbundleName, LoadedAssetBundle parent = null)
        {

            string[] deps = m_AssetBundleManifest.GetDirectDependencies(assetbundleName);
            LoadedAssetBundle lab = Find(assetbundleName);
            if (lab != null) return;
            if (lab == null)
            {
                lab = new LoadedAssetBundle(assetbundleName);

#if UNITY_EDITOR
                m_instance.watches.Add(lab);
#endif
                lab.Load();

            }
            for (int i = 0; i < deps.Length; i++)
            {
                string dep = deps[i];

                _Load(dep, parent);
            }
            

        }



        static int loadCallCount = 0;

        public static void Load(string assetBundleName)
        {
            //Debug.Log("load " +loadCallCount++ +" "+ assetBundleName);

            _Load(assetBundleName);
        }


        public class AsyncABLoader
        {
            public static AsyncABLoader Create(string path)
            {
                return new AsyncABLoader(path);
            }


            public string assetBundleName = "";

            protected string path;
            protected string orgPath;

            public AsyncABLoader(string path)
            {
                orgPath = path;
                path = string.Format("assets/resources/{0}", path.Replace("\\", "/"));
                this.path = path;
                assetBundleName = AssetBundleAssetRecord.GetAssetBundleName(path);

                if (assetBundleName != null && assetBundleName != "")
                {


                    this.assetBundleName = assetBundleName.ToLower();
                    AssetScene.Current.StartCoroutine(ABsManager.LoadAsync(assetBundleName));

                }
            }

            public bool Done()
            {
                if (m_instance.loadedAssetBundles.ContainsKey(assetBundleName) && m_instance.loadedAssetBundles[assetBundleName].m_AssetBundle)
                    return true;
                return false;
            }



            public GameObject Generate()
            {


                string assetName = string.Format("{0}", AssetBundleAssetRecord.GetAssetName(path));
                UnityEngine.Object obj = m_instance.loadedAssetBundles[assetBundleName].GetRes(assetName);

                if (obj != null)
                {
                    GameObject go = GameObject.Instantiate(obj) as GameObject;
                    AssetBundleUser.GetInstance().SetBundle(assetBundleName, go);
                    return go;
                }
                return null;

            }

        }



        static int loadAsyncCallCount = 0;

        static IEnumerator _LoadAsync(string assetbundleName, LoadedAssetBundle parent = null)
        {
            if (!string.IsNullOrEmpty(assetbundleName))
            {
                string[] deps = m_AssetBundleManifest.GetDirectDependencies(assetbundleName);

                LoadedAssetBundle lab = Find(assetbundleName);


                for (int i = 0; i < deps.Length; i++)
                {
                    string dep = deps[i];
                    yield return _LoadAsync(dep, lab);
                }

                if (lab == null)
                {
                    lab = new LoadedAssetBundle(assetbundleName);
#if UNITY_EDITOR
                    m_instance.watches.Add(lab);
#endif

                    yield return lab.LoadAsync();


                }
                else
                {
                    while (lab.m_AssetBundle == null)
                    {
                        yield return null;
                    }

                }
            }
        }

        //caohanzhi,异步加载接口
        public static IEnumerator LoadAsync(string assetBundleName)
        {

            //Debug.Log("async " + loadAsyncCallCount++ +" "+ assetBundleName);

            yield return _LoadAsync(assetBundleName);

        }



        static void _UnLoad(string assetBundleName)
        {

            LoadedAssetBundle lab = Find(assetBundleName);

            if (lab != null && lab.loaded)
            {

                if (lab.m_ReferencedCount == 0)
                {
#if UNITY_EDITOR
                    Debug.LogError("unload " + assetBundleName + " loaded=" + lab.loaded + "  ref = " + lab.m_ReferencedCount);
                    m_instance.watches.Remove(lab);
#endif

                    lab.UnLoad(true);
                    ABsManager.Instance.loadedAssetBundles.Remove(assetBundleName);

                }


                string[] deps = m_AssetBundleManifest.GetDirectDependencies(assetBundleName);
                foreach (string dep in deps)
                {

                    _UnLoad(dep);
                }

            }
        }

        public static void Unload(string assetBundleName)
        {



            _UnLoad(assetBundleName);


        }



        public static IEnumerator UnLoadUnused()
        {

            //        if (ResManager.Instance.pattern == ResManager.Pattern.AssetBundle)
            //        {
            //            if (m_AssetBundleManifest != null)
            //            {

            //                var listloading  = new Dictionary<string, LoadedAssetBundle>();

            //                foreach (LoadedAssetBundle ab in Instance.loadedAssetBundles.Values)
            //                {

            //                    if (ab.loaded)//caohanzhi 防异步加载时候还没完成就被清楚，导致内存的ab没释放
            //                    {
            //#if UNITY_EDITOR
            //                        Debug.LogError("UnLoadUnused " + ab.assetbundlename +"  ref = " + ab.m_ReferencedCount);
            //                        m_instance.watches.Remove(ab);
            //#endif
            //                        string []scenepaths = ab.m_AssetBundle.GetAllScenePaths();
            //                        foreach (var k in scenepaths)
            //                        {
            //                            Debug.Log(k);
            //                        }
            //                        ab.UnLoad(true);
            //                    }
            //                    else
            //                    {
            //#if UNITY_EDITOR
            //                        Debug.LogError("这个意料之外的 " + ab.assetbundlename + "  ref = " + ab.m_ReferencedCount);
            //                        listloading.Add(ab.assetbundlename, ab);
            //#endif
            //                    }

            //                }


            //                Instance.loadedAssetBundles = listloading;


            //                if (!string.IsNullOrEmpty(AssetScene.Current.assetBundleName))
            //                {
            //                    ABsManager.Unload(AssetScene.Current.assetBundleName);
            //                }
            //            }

            //            objMap.Clear();
            //            yield return null;
            AssetBundleUser.GetInstance().Clear();
            yield return null;
            Resources.UnloadUnusedAssets();
            yield return null;

            //}
        }


        public static string GetAssetName(AssetBundle ab, string assetName)
        {
            string[] assets = ab.GetAllAssetNames();
            string assetNameFull = assetName;
            foreach (string asset in assets)
            {
                if (asset.Replace(Path.GetExtension(asset), "") == assetName)
                {
                    assetNameFull = asset;
                    break;
                }
            }
            return assetNameFull;
        }

        public static AssetBundle LoadInternal(string assetBundleName)
        {
            string path = string.Format("assetbundles/{0}", assetBundleName);

            byte[] bs = FileUtils.LoadBytesFromFileSystem(path);

            if (bs != null && bs.Length > 0)
            {
                try
                {
                    AssetBundle ab = AssetBundle.LoadFromMemory(bs);
                    bs = null;
                    return ab;
                }
                catch (System.Exception e)
                {
                    Debug.LogError(e.ToString() + "  " + assetBundleName);
                    return null;
                }

            }
            else
            {
                Debug.LogError("Load AssetBundle:" + assetBundleName + " error");
                return null;
            }


        }


        void Awake()
        {
            //yield return Init();
        }

        void OnDestroy()
        {
            print("absmanager destroy");
            m_instance = null;
        }
        void Init()
        {

        }


    }
}