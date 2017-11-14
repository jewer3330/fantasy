//#define ASSET_TEST

using System;
using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.IO.Compression;

using Object = UnityEngine.Object;

#if UNITY_EDITOR
using UnityEditor;
#endif

public class LoadedAssetBundle
{
    public AssetBundle assetBundle;

    public LoadedAssetBundle(AssetBundle assetBundle)
    {
        this.assetBundle = assetBundle;
    }

    public void OnUnload()
    {
        assetBundle.Unload(true);
    }
}

[SLua.CustomLuaClass]
public class AssetManager : MonoBehaviour
{
    [SLua.DoNotToLua]
    public delegate void CopyProgress(float progress);
    [SLua.DoNotToLua]
    public delegate void CopyDone();

    public delegate void OnAsyncLoading(float progress);
    public delegate void OnAsyncLoaded(Object[] allAssets, Object asset);

    public static bool ClearFlag = false;

    private Dictionary<string, LoadedAssetBundle> loadedAssetBundles = new Dictionary<string, LoadedAssetBundle>();
    private HashSet<string> loadingAssetBundles = new HashSet<string>();
    private Dictionary<string, string[]> dependencies = new Dictionary<string, string[]>();
    private List<AssetLoadOperation> inProgressOperations = new List<AssetLoadOperation>();
    private AssetBundleManifest manifest = null;
    private Dictionary<Type, Stack<AssetLoadOperation>> caches = new Dictionary<Type, Stack<AssetLoadOperation>>();
    private List<LoadedAssetBundle> addedAssetBundles = new List<LoadedAssetBundle>();

    private static StringBuilder PathSB;
    private static int PathLength;

    void Awake()
    {
        PathSB = new StringBuilder(Application.persistentDataPath + "/");
        PathLength = PathSB.Length;
        Caching.CleanCache();
        DontDestroyOnLoad(gameObject);
    }

    public void CopyAssetBundles(CopyProgress progress, CopyDone done)
    {
        StartCoroutine(DoCopyAssetBundles(progress, done));
    }

    IEnumerator DoCopyAssetBundles(CopyProgress progress, CopyDone done)
    {
        Debug.Log("Do Copy");
#if UNITY_EDITOR
        StringBuilder srcPath = new StringBuilder("file:///" + Application.streamingAssetsPath + "/ABS/");
#elif UNITY_ANDROID
        StringBuilder srcPath = new StringBuilder("jar:file://" + Application.dataPath + "!/assets/ABS/");
        //StringBuilder srcPath = new StringBuilder(Application.streamingAssetsPath);
#elif UNITY_IPHONE
        StringBuilder srcPath = new StringBuilder(Application.dataPath + "/Raw/ABS/");
#else
        StringBuilder srcPath = new StringBuilder(Application.streamingAssetsPath);
#endif
        StringBuilder dstPath = new StringBuilder(Application.persistentDataPath + "/");
        int srcLen = srcPath.Length;
        int dstLen = dstPath.Length;

        WWW wwwManifest = new WWW(srcPath.Append("ABS").ToString());
        yield return wwwManifest;
        if (string.IsNullOrEmpty(wwwManifest.error))
        {
            dstPath.Length = dstLen;
            dstPath.Append("ABS");
            CopyFile(dstPath.ToString(), wwwManifest.bytes);

            manifest = wwwManifest.assetBundle.LoadAsset("assetbundlemanifest") as AssetBundleManifest;
            var assets = manifest.GetAllAssetBundles();

            Debug.Log("------Assets Length:" + assets.Length);
            for (int i = 0; i < assets.Length; ++i)
            {
                Debug.Log("------Assets:" + assets[i]);
                dependencies.Add(assets[i], manifest.GetAllDependencies(assets[i]));
                srcPath.Length = srcLen;
                srcPath.Append(assets[i]);
                Debug.Log("------SrcPath:" + srcPath);

                WWW www = new WWW(srcPath.ToString());
                yield return www;
                if (string.IsNullOrEmpty(www.error))
                {
                    dstPath.Length = dstLen;
                    dstPath.Append(assets[i]);
                    Debug.Log("------DstPath.:" + dstPath);
                    CopyFile(dstPath.ToString(), www.bytes);
                    www.Dispose();
                }
                else
                {
                    Debug.LogError(www.error);
                    www.Dispose();
                    yield break;
                }

                if (progress != null)
                    progress((float)i / assets.Length);
                yield return null;
            }
        }
        else
        {
            Debug.LogError(wwwManifest.error);
        }
        wwwManifest.Dispose();
        System.GC.Collect();

        if (done != null)
            done();
    }

    private static void CopyFile(string dst, byte[] bytes)
    {
        string dstFolder = Path.GetDirectoryName(dst);
        if (!Directory.Exists(dstFolder))
            Directory.CreateDirectory(dstFolder);

        using (FileStream f = File.Create(dst.ToString()))
        {
            f.Write(bytes, 0, bytes.Length);
        }
    }

    public void Init()
    {
        //if (manifest == null)
        //{
        //    Debug.Log("===INIT===");
        //    string manifestPath = Path.Combine(Application.persistentDataPath, "ABS");
        //    Debug.Log("ManifestPath:" + manifestPath);
        //    if (File.Exists(manifestPath))
        //    {
        //        var bundle = AssetBundle.LoadFromFile(manifestPath);
        //        if (bundle != null)
        //        {
        //            manifest = bundle.LoadAsset("assetbundlemanifest") as AssetBundleManifest;
        //            var assets = manifest.GetAllAssetBundles();
        //            foreach (var asset in assets)
        //            {
        //                dependencies.Add(asset, manifest.GetAllDependencies(asset));
        //            }
        //        }
        //        Debug.Log("Manifest:" + manifest);
        //    }
        //}
    }

    void Update()
    {
        for (int i = 0; i < inProgressOperations.Count;)
        {
            var op = inProgressOperations[i];
            if (op.Update())
            {
                ++i;
            }
            else
            {
                inProgressOperations.RemoveAt(i);
                ProcessFinishedOperation(op);
            }
        }
    }

    public void Clear(List<string> future)
    {
        string assetBundleName;
        HashSet<string> bundleNames = new HashSet<string>();
        foreach (var filename in future)
        {
            assetBundleName = filename.ToLower();
            //if (!assetBundleName.Contains("content/map"))
            //{
            //    Debug.Log(string.Format("<color=blue>AB:{0}</color>", assetBundleName));
            //    assetBundleName = Path.GetDirectoryName(assetBundleName);
            //}
            if (assetBundleName.Contains("resources/") && (!assetBundleName.Contains("slua/")))
            {
                assetBundleName = assetBundleName.Replace("resources/", "res/");
            }
            bundleNames.Add(assetBundleName);

            string[] deps;
            if (dependencies.TryGetValue(assetBundleName, out deps))
            {
                foreach (var dep in deps)
                {
                    bundleNames.Add(dep);
                }
            }
        }

        for (int i = 0; i < addedAssetBundles.Count; ++i)
        {
            var ab = addedAssetBundles[i];
            if (ab.assetBundle == null)
                continue;
            if (bundleNames.Contains(ab.assetBundle.name))
            {
#if UNITY_EDITOR
                Debug.LogWarningFormat("无法删除重复使用的AssetBundle: {0}", ab.assetBundle.name);
#endif
                continue;
            }
            loadedAssetBundles.Remove(ab.assetBundle.name);
            //dependencies.Remove(ab.assetBundle.name);
            Debug.Log(string.Format("*===UNLOAD===*{0}", ab.assetBundle.name));
            ab.OnUnload();
        }
        addedAssetBundles.Clear();
        objCacheDic.Clear();
    }

    private static AssetManager instance = null;
    public static AssetManager Instance
    {
        get
        {
            if (instance == null)
            {
                if (GameObject.Find("AssetManager") == null)
                {
                    GameObject go = new GameObject("AssetManager");
                    instance = go.AddComponent<AssetManager>();
                }
                else
                {
                    var mgr = GameObject.Find("AssetManager");
                    if (mgr.GetComponent<AssetManager>() == null)
                    {
                        instance = mgr.AddComponent<AssetManager>();
                    }
                    else
                    {
                        instance = mgr.GetComponent<AssetManager>();
                    }
                }
            }
            return instance;
        }
    }

    [SLua.DoNotToLua]
    public T Load<T>(string filename) where T : Object
    {
        return Load(filename, typeof(T)) as T;
    }

    public Object Load(string filename)
    {
        return Load(filename, typeof(GameObject));
    }

    public Object Load(string filename, string type)
    {
        return Load(filename, SLua.LuaObject.FindType(type));
    }

    public Object Load(string filename, System.Type type)
    {
        //string assetBundleName = filename.ToLower();
        //if (!assetBundleName.Contains("content/map"))
        //    assetBundleName = Path.GetDirectoryName(assetBundleName);
        //if (assetBundleName.Contains("resources/") && (!assetBundleName.Contains("slua/")))
        //    assetBundleName = assetBundleName.Replace("resources/", "res/");
        //string assetName = Path.GetFileNameWithoutExtension(filename).ToLower();
        if (filename.Contains("Resources"))
            filename = filename.Replace("Resources/", "");
        if (filename.Contains("res"))
            filename = filename.Replace("res/", "");
        if (filename.Contains("Res"))
            filename = filename.Replace("Res/", "");
        filename = filename.ToLower();
        if (type == typeof(Scene))
        {
            SuperBoBo.ResManager.LoadLevel(filename);
        }
        else
        {
            return SuperBoBo.ResManager.Load(filename);
        }
        return null;
    }

    [SLua.DoNotToLua]
    private Object Load(string assetBundleName, string assetName, System.Type type)
    {        
        Object result = null;
#if UNITY_EDITOR && !ASSET_TEST
        string[] assetPaths = AssetDatabase.GetAssetPathsFromAssetBundleAndAssetName(assetBundleName, assetName);
        if (assetPaths.Length == 0)
        {
            Debug.LogErrorFormat("There is no asset with name \"{0}\" in {1}", assetName, assetBundleName);
            return null;
        }
        if (type == typeof(Scene))
            EditorApplication.LoadLevelInPlayMode(assetPaths[0]);
        else
            result = AssetDatabase.LoadMainAssetAtPath(assetPaths[0]);

#else
        Debug.Log("------AssetName:" + assetName);
        Debug.Log("------AssetBundleName:" + assetBundleName);

        AssetBundle assetBundle = LoadAssetBundle(assetBundleName);
        if (assetBundle != null)
        {
            if (assetBundle.isStreamedSceneAssetBundle)
            {
                SceneManager.LoadScene(assetName, LoadSceneMode.Single);
            }
            else
            {
                result = assetBundle.LoadAsset(assetName, type);
            }
        }
#endif
        return result;
    }

    [SLua.DoNotToLua]
    public T Load<T>(string assetBundleName, string assetName) where T : Object
    {
        return Load(assetBundleName.ToLower(), assetName.ToLower(), typeof(T)) as T;
    }

    public Object[] LoadAll(string filename)
    {
        return LoadAll(filename, typeof(GameObject));
    }

    public Object[] LoadAll(string filename, string type)
    {
        return LoadAll(filename, SLua.LuaObject.FindType(type));
    }

    public Object[] LoadAll(string filename, System.Type type)
    {
        Object[] result = null;

        string assetBundleName = Path.GetDirectoryName(filename).ToLower();
#if UNITY_EDITOR && !ASSET_TEST
        if (type != typeof(Scene))
        {
            result = AssetDatabase.LoadAllAssetsAtPath(filename);
        }
#else
        AssetBundle assetBundle = LoadAssetBundle(assetBundleName);
        if (assetBundle != null)
            result = assetBundle.LoadAllAssets(type);
#endif
        return result;
    }

    public void LoadAsync(string filename, OnAsyncLoading loading, OnAsyncLoaded loaded)
    {
        LoadAsync(filename, typeof(UnityEngine.GameObject), loading, loaded);
    }

    public void LoadAsync(string filename, string type, OnAsyncLoading loading, OnAsyncLoaded loaded)
    {
        LoadAsync(filename, SLua.LuaObject.FindType(type), loading, loaded);
    }

    public void LoadAsync(string filename, System.Type type, OnAsyncLoading loading, OnAsyncLoaded loaded)
    {
        string assetBundleName = filename.ToLower();
        if (!assetBundleName.Contains("content/map"))
            assetBundleName = Path.GetDirectoryName(assetBundleName);
        if (assetBundleName.Contains("resources/") && (!assetBundleName.Contains("slua/")))
            assetBundleName = assetBundleName.Replace("resources/", "res/");
        string assetName = Path.GetFileNameWithoutExtension(filename).ToLower();

#if UNITY_EDITOR && !ASSET_TEST
        if (type != typeof(Scene))
        {
            string[] assetPaths = AssetDatabase.GetAssetPathsFromAssetBundleAndAssetName(assetBundleName, assetName);
            if (assetPaths.Length == 0)
            {
                Debug.LogErrorFormat("There is no asset with name \"{0}\" in {1}", assetName, assetBundleName);
                return;
            }
            Object result = AssetDatabase.LoadMainAssetAtPath(assetPaths[0]);
            if (loaded != null)
                loaded(null, result);
        }
        else
        {
            AddOperation<EditorLoadSceneOperation>().Init(filename, loading, loaded);
            ClearFlag = true;
        }
#else
        LoadAssetBundleAsync(assetBundleName);
        if (type != typeof(Scene))
        {
            AddOperation<AssetBundleLoadAssetOperation>().Init(assetBundleName, assetName, type, loading, loaded);
        }
        else
        {
            AddOperation<AssetBundleLoadSceneOperation>().Init(assetBundleName, assetName, loading, loaded);
            ClearFlag = true;
        }
#endif
    }

    [SLua.DoNotToLua]
    public LoadedAssetBundle GetLoadedAssetBundle(string assetBundleName)
    {
        LoadedAssetBundle bundle = null;
        if (!loadedAssetBundles.TryGetValue(assetBundleName, out bundle))
            return null;

        string[] deps = null;
        if (!dependencies.TryGetValue(assetBundleName, out deps))
            return bundle;

        //foreach (var dep in deps)
        //{
        //    LoadedAssetBundle depBundle;
        //    if (!loadedAssetBundles.TryGetValue(dep, out depBundle))
        //        //return null;
        //        Debug.Log("!!!!!!!!!!!!!!!!!!!!!!!" + dep);
        //        LoadAssetBundle(dep);
        //}

        return bundle;
    }

    protected AssetBundle LoadAssetBundle(string assetBundleName)
    {
        LoadedAssetBundle bundle = GetLoadedAssetBundle(assetBundleName);
        if (bundle != null)
        {
            return bundle.assetBundle;
        }
        else
        {
            if (PathSB == null)
            {
                PathSB = new StringBuilder(Application.persistentDataPath + "/");
                PathLength = PathSB.Length;
            }
            PathSB.Length = PathLength;
            PathSB.Append(assetBundleName);
            bundle = AddAssetBundle(assetBundleName, PathSB.ToString());

            string[] deps;
            if (dependencies.TryGetValue(assetBundleName, out deps))
            {
                foreach (var dep in deps)
                {
                    LoadedAssetBundle depBundle;
                    if (!loadedAssetBundles.TryGetValue(dep, out depBundle))
                    {
                        PathSB.Length = PathLength;
                        PathSB.Append(dep);
                        AddAssetBundle(dep, PathSB.ToString());
                    }
                }
            }

            return bundle.assetBundle;
        }
    }

    protected LoadedAssetBundle AddAssetBundle(string assetBundleName, string path)
    {
        LoadedAssetBundle bundle = new LoadedAssetBundle(AssetBundle.LoadFromFile(path));
        AddAssetBundle(assetBundleName, bundle);
        return bundle;
    }

    protected void AddAssetBundle(string assetBundleName, LoadedAssetBundle bundle)
    {
        loadedAssetBundles.Add(assetBundleName, bundle);
        // FIXME(kai.zou): ugly
        if (!assetBundleName.Contains("slua") &&
            !assetBundleName.Contains("audio/mixer") &&
            !assetBundleName.Contains("releaseshader") &&
            !assetBundleName.Contains("content/ui/bg") &&
            !assetBundleName.Contains("content/ui/common") &&
            !assetBundleName.Contains("content/ui/sprites/heroprophead") &&
            !assetBundleName.Contains("content/ui/sprites/battleuiheadicon") &&
            !assetBundleName.Contains("content/ui/sprites/mix") &&
            !assetBundleName.Contains("content/ui/chatui") &&
            !assetBundleName.Contains("content/ui/loadingwindow") &&
            !assetBundleName.Contains("content/ui/pkmatchingteam") &&
            !assetBundleName.Contains("res/Prefabs/ui/roguebattleresult") &&
            !assetBundleName.Contains("res/Prefabs/ui/chatui") &&
            !assetBundleName.Contains("res/Prefabs/ui/main") &&
            !assetBundleName.Contains("res/Prefabs/ui/pkmatchingteam") &&
            !assetBundleName.Contains("res/Prefabs/ui/roguewindow") &&
            !assetBundleName.Contains("res/Prefabs/ui/loadinglevel") &&
            !assetBundleName.Contains("res/Prefabs/ui/pvebattleaccount") &&
            !assetBundleName.Contains("res/Prefabs/sfx/comon/ui") &&
            !assetBundleName.Contains("atlas"))
            addedAssetBundles.Add(bundle);
    }

    protected void LoadAssetBundleAsync(string assetBundleName)
    {
        LoadAssetBundleAsync(assetBundleName, false);
    }

    protected void LoadAssetBundleAsync(string assetBundleName, bool isManifest)
    {
        bool isAlreadyProcessed = LoadAssetBundleAsyncInternal(assetBundleName, isManifest);
        if (!isAlreadyProcessed && !isManifest)
            LoadDependencies(assetBundleName);
    }

    protected bool LoadAssetBundleAsyncInternal(string assetBundleName, bool isManifest)
    {
        LoadedAssetBundle bundle = null;
        if (loadedAssetBundles.TryGetValue(assetBundleName, out bundle))
            return true;
        if (loadingAssetBundles.Contains(assetBundleName))
            return true;
        loadingAssetBundles.Add(assetBundleName);
        AddOperation<AssetBundleLoadFromFileOperation>().Init(assetBundleName);
        return false;
    }

    protected void LoadDependencies(string assetBundleName)
    {
        if (manifest != null)
        {
            string[] deps = manifest.GetAllDependencies(assetBundleName);
            if (deps.Length == 0)
                return;

            for (int i = 0; i < deps.Length; ++i)
                LoadAssetBundleAsyncInternal(deps[i], false);
        }
    }

    protected void ProcessFinishedOperation(AssetLoadOperation op)
    {
        AssetBundleLoadFromFileOperation load = op as AssetBundleLoadFromFileOperation;
        if (load != null)
        {
            AddAssetBundle(load.assetBundleName, load.assetBundle);
            loadingAssetBundles.Remove(load.assetBundleName);
        }

        Return(op);
    }

    protected T AddOperation<T>() where T : AssetLoadOperation, new()
    {
        T op = Obtain<T>();
        inProgressOperations.Add(op);
        return op;
    }

    protected T Obtain<T>() where T : AssetLoadOperation, new()
    {
        Stack<AssetLoadOperation> ops;
        if (!caches.TryGetValue(typeof(T), out ops))
            caches.Add(typeof(T), ops = new Stack<AssetLoadOperation>());

        if (ops.Count > 0)
            return ops.Pop() as T;
        return new T();
    }

    protected void Return(AssetLoadOperation op)
    {
        op.Reset();
        caches[op.GetType()].Push(op);
    }

    #region Load Object And Cache
    private Dictionary<string, Object> objCacheDic = new Dictionary<string, Object>();
    public Object LoadAndCache(string filename)
    {
        return LoadAndCache(filename, typeof(GameObject));
    }
    public Object LoadAndCache(string filename, System.Type type)
    {        
        Object obj;
        if(!objCacheDic.TryGetValue(filename, out obj))
        {
            obj = Load(filename, type);
            if(obj == null)
            {
                Debug.LogErrorFormat("LoadAndCache Failed,filename:{0},type:{1}", filename, type);
                return null;
            }            
            objCacheDic.Add(filename, obj);
        }
        else
        {
            //Debug.LogErrorFormat("【LoadAndCache From Cache】filename:{0},type:{1}", filename, type);
            if (obj == null)
            {
                objCacheDic.Remove(filename);
                obj = LoadAndCache(filename, type);
            }            
        }

        return obj;
    }

    #endregion
}
