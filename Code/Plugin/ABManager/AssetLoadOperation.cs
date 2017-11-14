using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.SceneManagement;

public abstract class AssetLoadOperation
{
    public void Reset()
    {
        DoReset();
    }

    abstract public bool Update();
    abstract protected void DoReset();
}

public class EditorLoadSceneOperation : AssetLoadOperation
{
    protected string assetName;
    protected AsyncOperation request;
    protected AssetManager.OnAsyncLoading loading;
    protected AssetManager.OnAsyncLoaded loaded;

    public void Init(string assetName, AssetManager.OnAsyncLoading loading, AssetManager.OnAsyncLoaded loaded)
    {
        this.assetName = assetName;
        this.loading = loading;
        this.loaded = loaded;
        request = null;
    }

    public override bool Update()
    {
        if (request == null)
        {
            request = SceneManager.LoadSceneAsync(assetName, LoadSceneMode.Single);
            return true;
        }
        else
        {
            if (request.isDone)
            {
                if (loaded != null)
                    loaded(null, null);
                return false;
            }
            else
            {
                if (loading != null)
                    loading(request.progress);
                return true;
            }
        }
    }

    protected override void DoReset()
    {
        assetName = null;
        loading = null;
        loaded = null;
        request = null;
    }
}

public class AssetBundleLoadFromFileOperation : AssetLoadOperation
{
    public string assetBundleName { get; protected set; }
    public LoadedAssetBundle assetBundle { get; protected set; }
    protected AssetBundleCreateRequest request;

    public void Init(string assetBundleName)
    {
        this.assetBundleName = assetBundleName;
        this.request = AssetBundle.LoadFromFileAsync(Path.Combine(Application.persistentDataPath, assetBundleName));
    }

    public override bool Update()
    {
        if (request == null)
        {
            return true;
        }
        else if (request.isDone)
        {
            assetBundle = new LoadedAssetBundle(request.assetBundle);
            return false;
        }
        return true;
    }

    protected override void DoReset()
    {
        assetBundleName = null;
        assetBundle = null;
        request = null;
    }
}

public class AssetBundleLoadAssetOperation : AssetLoadOperation
{
    protected string assetBundleName;
    protected string assetName;
    protected System.Type type;
    protected AssetBundleRequest request;
    protected AssetManager.OnAsyncLoading loading;
    protected AssetManager.OnAsyncLoaded loaded;

    public void Init(string assetBundleName, string assetName, System.Type type, AssetManager.OnAsyncLoading loading, AssetManager.OnAsyncLoaded loaded)
    {
        this.assetBundleName = assetBundleName;
        this.assetName = assetName;
        this.type = type;
        this.loading = loading;
        this.loaded = loaded;
    }

    public override bool Update()
    {
        if (request == null)
        {
            LoadedAssetBundle bundle = AssetManager.Instance.GetLoadedAssetBundle(assetBundleName);
            if (bundle != null)
                request = bundle.assetBundle.LoadAssetAsync(assetName, type);
            return true;
        }
        else
        {
            if (request.isDone)
            {
                if (loaded != null)
                    loaded(request.allAssets, request.asset);
                return false;
            }
            else
            {
                if (loading != null)
                    loading(request.progress);
                return true;
            }
        }
    }

    protected override void DoReset()
    {
        assetBundleName = null;
        assetName = null;
        type = null;
        request = null;
    }
}

public class AssetBundleLoadSceneOperation : AssetLoadOperation
{
    protected string assetBundleName;
    protected string assetName;
    protected AsyncOperation request;
    protected AssetManager.OnAsyncLoading loading;
    protected AssetManager.OnAsyncLoaded loaded;

    public void Init(string assetBundleName, string assetName, AssetManager.OnAsyncLoading loading, AssetManager.OnAsyncLoaded loaded)
    {
        this.assetBundleName = assetBundleName;
        this.assetName = assetName;
        this.loading = loading;
        this.loaded = loaded;
        request = null;
    }

    public override bool Update()
    {
        if (request == null)
        {
            LoadedAssetBundle bundle = AssetManager.Instance.GetLoadedAssetBundle(assetBundleName);
            if (bundle != null)
                request = SceneManager.LoadSceneAsync(assetName, LoadSceneMode.Single);
            return true;
        }
        else
        {
            if (request.isDone)
            {
                if (loaded != null)
                    loaded(null, null);
                return false;
            }
            else
            {
                if (loading != null)
                    loading(request.progress);
                return true;
            }
        }
    }

    protected override void DoReset()
    {
        assetBundleName = null;
        assetName = null;
        loading = null;
        loaded = null;
        request = null;
    }
}
