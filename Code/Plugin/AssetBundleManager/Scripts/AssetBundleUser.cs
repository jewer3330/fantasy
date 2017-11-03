using UnityEngine;
using System.Collections;
using System.Collections.Generic;

[System.Serializable]
public class ObjectState
{
    public enum State
    {
        Normal,
        DontDestroyOnload,
    }

    public Object obj;
    public State state;
}

[System.Serializable]
public class AssetBundleInf
{
    public string assetbundleName;
    public List<ObjectState> watchList;
    public int refCount;
    
    public AssetBundleInf(string s)
    {
        assetbundleName = s;
        watchList = new List<ObjectState>();
        refCount = 0;
    }

    public void RemoveRef()
    {
        refCount--;
        ABsManager.Instance.loadedAssetBundles[assetbundleName].RemoveRef();
    }

    public void AddRef(Object o, ObjectState.State state = ObjectState.State.Normal)
    {
        ObjectState os = new ObjectState();
        os.obj = o;
        os.state = state;
        watchList.Add(os);
        refCount++;
        ABsManager.Instance.loadedAssetBundles[assetbundleName].AddRef();
    }
}


public class AssetBundleUser : MonoBehaviour
{


    public List<AssetBundleInf> list = new List<AssetBundleInf>();
    public static List<AssetBundleInf> lastSceneRemains = new List<AssetBundleInf>();
    static AssetBundleUser instance;

    public AssetBundleInf Find(string s)
    {
        foreach (var k in list)
        {
            if (s == k.assetbundleName)
            {
                return k;
            }
        }
        return null;
    }

    public void CheckInf(AssetBundleInf inf)
    {
        for (int i = 0; i < inf.watchList.Count; i++)
        {
            ObjectState os = inf.watchList[i];
            if (os.obj == null)
            {
                inf.watchList.RemoveAt(i);
                inf.RemoveRef();
            }
        }
    }


    public static AssetBundleUser GetInstance()
    {
        if (instance != null)
            return instance;
        else
        {    
            GameObject go = new GameObject("assetbundle");
            DontDestroyOnLoad(go);
            instance = go.AddComponent<AssetBundleUser>();
            instance.list.AddRange(lastSceneRemains);
            lastSceneRemains.Clear();
            return instance;
        }
    }




    public void SetBundle(string s, Object obj, ObjectState.State state = ObjectState.State.Normal)
    {
        if (obj != null)
        {
            var conf = Find(s);
            if (conf != null)
            {
                conf.AddRef(obj,state);
            }
            else
            {
                AssetBundleInf abf = new AssetBundleInf(s);
                abf.AddRef(obj, state);
                list.Add(abf);
            }
            
        }
    }

    float time = 0f;
    void LateUpdate()
    {
        if (Time.time - time > 0f)
        {
            time = Time.time + 1f;
            for (int i = 0; i < list.Count; i++)
            {
                CheckInf(list[i]);
                if (list[i].refCount == 0)
                {
                    ABsManager.Unload(list[i].assetbundleName);
                    list.RemoveAt(i);
                }
            }
        }
    }

    public bool isDontDestroyOnload(AssetBundleInf inf)
    {
        bool ret = false;
        for (int j = 0; j < inf.watchList.Count; j++)
        {
            if (inf.watchList[j].state == ObjectState.State.DontDestroyOnload)
            {
                ret = true;
                break;
            }
        }
        return ret;
    }


    public void OnDestroy()
    {
        for (int i = 0; i < list.Count; i++)
        {
            if (isDontDestroyOnload(list[i]))
                lastSceneRemains.Add(list[i]);
        }
    }

    public void Clear()
    {
        for (int i = 0; i < list.Count; i++)
        {
            if (!isDontDestroyOnload(list[i]))
                ABsManager.Unload(list[i].assetbundleName);
            else
                lastSceneRemains.Add(list[i]);
        }
    }

}
