using UnityEngine;
using System.Collections;
using System.IO;

namespace SuperBoBo
{
    public class ResManager : MonoBehaviour
    {
        public enum Pattern : byte
        {
            Resources = 0,
            AssetBundle,

        }

        public bool inited = false;

        public static ResManager m_instance;
        public static ResManager Instance
        {
            get
            {
                if (m_instance == null)
                {
#if UNITY_EDITOR
                    if (!Application.isPlaying)
                    {
                        m_instance = new ResManager();
                        return m_instance;
                    }
#endif
                    GameObject obj = new GameObject("ResManager");
                    GameObject.DontDestroyOnLoad(obj);
                    m_instance = obj.AddComponent<ResManager>();

                }
                return m_instance;
            }
        }

        public Pattern m_pattern = Pattern.Resources;
        public Pattern pattern { get { return m_pattern; } }

        void Awake()
        {

        }

        void OnDestroy()
        {
            AssetBundleAssetRecord.Destroy();
            m_instance = null;
            inited = false;
        }

        public static string ConvertResToABPath(string path)
        {
            path = string.Format(AssetBase.basePath, path.Replace("\\", "/"));
            string assetBundleName = AssetBundleAssetRecord.GetAssetBundleName(path);
            return assetBundleName;
        }

        public static void AddABUser(Object o, string path, ObjectState.State state = ObjectState.State.Normal)
        {
            if (ResManager.Instance.m_pattern == ResManager.Pattern.AssetBundle)
            {
                string assetBundleName = ConvertResToABPath(path);
                if (!string.IsNullOrEmpty(assetBundleName))
                {

                    AssetBundleUser.GetInstance().SetBundle(assetBundleName, o, state);

                }
                else
                {
                    Debug.LogError("error add ab user = " + path);
                }
            }
        }


        public void Init(Pattern pattern = Pattern.Resources)
        {
            this.m_pattern = pattern;
            if (inited == false)
            {
                inited = true;
                Debug.Log("资源加载方式：" + m_pattern);
                if (pattern == Pattern.AssetBundle)
                {
                    ABsManager abs = ABsManager.Instance;
                }
            }
        }


        /// <summary>
        /// 和Resources一样使用
        /// </summary>
        /// <param name="path"></param>
        /// <returns></returns>
        public static Object Load(string path, Object user, ObjectState.State state = ObjectState.State.Normal)
        {
            Object obj = null;
            switch (Instance.pattern)
            {
                case Pattern.Resources:
                    obj = Resources.Load(GetResourcesName(path));
                    break;
                case Pattern.AssetBundle:
                    obj = AssetScene.Load(path);
                    if (user != null)
                        AddABUser(user, path, state);
                    break;
            }
            return obj;
        }


        public static Object Load(string path, ObjectState.State state = ObjectState.State.Normal)
        {
            Object obj = null;
            switch (Instance.pattern)
            {
                case Pattern.Resources:
                    obj = Resources.Load(GetResourcesName(path));
                    break;
                case Pattern.AssetBundle:
                    obj = AssetScene.Load(path);
                    AddABUser(obj, path, state);
                    break;
            }
            return obj;
        }


        public static void LoadAsync(string path, System.Action<Object> callback)
        {
            Object obj = null;
            switch (Instance.pattern)
            {
                case Pattern.Resources:
                    obj = Resources.Load(GetResourcesName(path));
                    if (callback != null) callback(obj);
                    break;
                case Pattern.AssetBundle:
                    Instance.StartCoroutine(AssetScene.LoadAsync(path, callback));

                    break;
            }

        }


        public static void Unload(string path)
        {
            AssetScene.Unload(path);
        }

        public static void LoadLevel(string name)
        {
            switch (Instance.pattern)
            {
                case Pattern.Resources:
                    UnityEngine.SceneManagement.SceneManager.LoadScene(name);
                    break;
                case Pattern.AssetBundle:
                    Instance.StartCoroutine(LoadLevelAsync(name));
                    break;
            }
        }

        public static IEnumerator LoadLevelAsync(string name)
        {
            yield return AssetScene.NewSceneAsync(name);
            UnityEngine.SceneManagement.SceneManager.LoadScene(name);
        }


        public static void LoadLevelAdditive(string name)
        {
            switch (Instance.pattern)
            {
                case Pattern.Resources:
                    UnityEngine.SceneManagement.SceneManager.LoadScene(name, UnityEngine.SceneManagement.LoadSceneMode.Additive);
                    break;
                case Pattern.AssetBundle:
                    Instance.StartCoroutine(LoadLevelAsync(name));
                    break;
            }
        }




        public static IEnumerator LoadLevelAssetBundleAsync(string name)
        {
            switch (Instance.pattern)
            {
                case Pattern.Resources:
                    yield return null;
                    break;
                case Pattern.AssetBundle:
                    yield return AssetScene.NewSceneAsync(name);
                    break;
            }
        }

        public static IEnumerator LoadLevelAdditiveAsync(string name, System.Action<AsyncOperation> callback = null)
        {
            switch (Instance.pattern)
            {
                case Pattern.Resources:
                    yield return UnityEngine.SceneManagement.SceneManager.LoadSceneAsync(name, UnityEngine.SceneManagement.LoadSceneMode.Additive);
                    break;
                case Pattern.AssetBundle:

                    yield return AssetScene.NewSceneAsync(name);
                    yield return UnityEngine.SceneManagement.SceneManager.LoadSceneAsync(name, UnityEngine.SceneManagement.LoadSceneMode.Additive);
                    break;
            }

        }

        public static string GetResourcesName(string path)
        {
            if (Path.HasExtension(path))
                path = path.Replace(Path.GetExtension(path), "");
            return path;
        }



        public static string GetAssetBundleNameOfScene(string path)
        {
            string assetBundleName = string.Format("assets/scenes/{0}.dat", path.ToLower());
            return assetBundleName;
        }
    }
}