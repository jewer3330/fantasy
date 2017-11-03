using UnityEngine;
using System.Collections;


/// <summary>
/// 专业处理AB加载物体，提供静态方法
/// </summary>
public class AssetScene : AssetBase
{
    static AssetScene m_pre;
    static AssetScene m_current;
    
    public string assetBundleName;

    public static AssetScene Current
    {
        get
        {
            if (m_current == null)
            {
                m_current = Create(null);
            }
            return m_current;
        }
        set
        {
            m_current = value;
        }
    }

    /// <summary>
    /// 自动清理缓存，释放内存
    /// </summary>
    /// <returns></returns>
    public static AssetScene NewScene(string name)
    {
        m_pre = m_current;
        RemovePre();
        m_current = Create(name);
        return m_current;
    }

    public static IEnumerator NewSceneAsync(string name)
    {
        m_pre = m_current;
        RemovePre();
        yield return CreateAsync(name);

        
     
    }


    public static void RemovePre()
    {
        if (m_pre)
        {
            if (!string.IsNullOrEmpty(m_pre.assetBundleName))
            {
                ABsManager.Unload(m_pre.assetBundleName);
            }
            GameObject.Destroy(m_pre.gameObject);

           
        }
        
    }

   


    public static IEnumerator CreateAsync(string name)
    {
        if (string.IsNullOrEmpty(name))//空场景
        {
            GameObject obj = new GameObject("AssetScene");
            if (Application.isPlaying)
            {
                GameObject.DontDestroyOnLoad(obj);
            }
            AssetScene assetScene = obj.AddComponent<AssetScene>();
            m_current = assetScene;

            yield return null; 
        }
        else
        {
            GameObject obj = new GameObject("AssetScene");//需要加载资源
            if (Application.isPlaying)
            {
                GameObject.DontDestroyOnLoad(obj);
            }
            AssetScene assetScene = obj.AddComponent<AssetScene>();
            assetScene.assetBundleName = GetAssetBundleNameOfScene(name);
            yield return ABsManager.LoadAsync(assetScene.assetBundleName);

            m_current = assetScene;
        }
    }

    public static AssetScene Create(string name)
    {
        if (string.IsNullOrEmpty(name))//空场景
        {
            GameObject obj = new GameObject("AssetScene");
            if (Application.isPlaying)
            {
                GameObject.DontDestroyOnLoad(obj);
            }
            return obj.AddComponent<AssetScene>();
        }
        else
        {
            GameObject obj = new GameObject("AssetScene");//需要加载资源
            if (Application.isPlaying)
            {
                GameObject.DontDestroyOnLoad(obj);
            }
            AssetScene assetScene = obj.AddComponent<AssetScene>();

            assetScene.assetBundleName = GetAssetBundleNameOfScene(name);

            Debug.Log("Load scene from AB " + assetScene.assetBundleName);
            ABsManager.Load(assetScene.assetBundleName);
            
            return assetScene;
        }
    }



    public static Object Load(string path)
    {
        return Current.LoadAsset(path);
    }



    public static void Unload(string path)
    {
        Current.UnloadAsset(path);
    }

    public static IEnumerator LoadAsync(string path, System.Action<Object> callback)
    {
        yield return Current.LoadAssetAsync(path, callback);
    }

    public static string GetAssetBundleNameOfScene(string path)
    {
        string assetBundleName = string.Format("assets/scenes/{0}.dat", path.ToLower());
        return assetBundleName;
    } 
}
