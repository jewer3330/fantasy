using UnityEngine;
using System.Collections;
using System.Collections.Generic;

namespace SuperBoBo
{
    public class MultiWWW : MonoBehaviour
    {

        private static MultiWWW _instance;
        public static MultiWWW instance
        {
            get
            {
                if (_instance == null)
                {
                    GameObject go = new GameObject("MultiWWW");
                    _instance = go.AddComponent<MultiWWW>();
                }
                return _instance;
            }
        }

        public delegate void MutilDownloadCallback(WWW www, AssetbundleJsonData json);

        public class Job
        {
            public string url = null;
            public MutilDownloadCallback callback = null;
            public AssetbundleJsonData data = null;
            public bool isDone = false;
            public System.Action finishCallback = null;
            public Job(string url, MutilDownloadCallback callback, AssetbundleJsonData json)
            {
                this.url = url;
                this.callback = callback;
                this.data = json;
            }

            public IEnumerator Start(System.Action onFinish = null)
            {
                finishCallback = onFinish;
                yield return DownloadFile(url);
                isDone = true;
            }

            public IEnumerator DownloadFile(string url)
            {

                string u = FileUtils.url + "/" + url;
                WWW www = new WWW(u + "?time=" + System.DateTime.Now.Ticks + "&r=" + Random.Range(int.MinValue, int.MaxValue));
                string tip = "下载文件 " + u + " " + www.progress;
#if UNITY_EDITOR
                Debug.Log(tip);
#endif
                float timeStart = Time.time;

                yield return www;
                GameUpdater.networkSpeed = www.bytesDownloaded / (Time.time - timeStart);
                if (!string.IsNullOrEmpty(www.error))
                {
                    Debug.LogError(www.error);
                    if (FileUtils.IsAllCDNCantDownload())
                    {
                        string msg = string.Format("网络错误(error : 801)\r\n{0}", www.responseHeaders.ContainsKey("STATUS") ? www.responseHeaders["STATUS"] : www.error);
                        UIMessageBoxHelper.Show(msg,
                            () =>
                            {

                                UnityEngine.SceneManagement.SceneManager.LoadScene("Launcher");
                            }
                            );
                        yield return new WaitForSeconds(4f);

                    }
                    else
                    {
                        FileUtils.ChangeCDNState();
                        //u = FileUtils.url + "/" + url;
                        //www = new WWW(u + "?time=" + System.DateTime.Now.Ticks + "&r=" + Random.Range(int.MinValue, int.MaxValue));
                        //yield return www;
                        //tip = "下载文件 " + u + " " + www.progress;
                        //Debug.Log(tip);
                        MultiWWW.instance.StartCoroutine(DownloadFile(url));
                    }
                }

                if (www.isDone && string.IsNullOrEmpty(www.error))
                {
                    GameUpdater.networkAvgSpeed += www.bytes.Length;
                    if (callback != null) callback(www, data);
                    if (finishCallback != null) finishCallback();
                }
            }
        }

        public List<Job> jobs = new List<Job>();

        public int coreNum = 0;
        public int workNum = 0;

        public int currentDownload = 0;
        public void Init(int num)
        {
            this.coreNum = num;
        }

        public void AddJob(string resURL, MutilDownloadCallback callback, AssetbundleJsonData json)
        {
            bool find = false;
            foreach (var k in jobs)
            {
                if (k.url == resURL)
                {
                    find = true;
                }
            }
            if (!find)
                jobs.Add(new Job(resURL, callback, json));
        }

        public bool isFinished()
        {
            return jobs.Count == 0 && workNum == 0;
        }

        public Job current;


        public IEnumerator StartDownload()
        {

            while (jobs.Count > 0)
            {
                //Debug.Log("任务还剩 " +jobs.Count);
                current = jobs[0];
                if (workNum < coreNum)
                {
                    jobs.RemoveAt(0);
                    workNum++;
                    StartCoroutine(current.Start(() =>
                    {
                        workNum--;
                        currentDownload++;
                    //Debug.LogWarning("任务已经完成 " + currentDownload);
                }));
                }
                else
                {
                    //Debug.Log("下载线程已满 " + Time.time);
                    yield return null;
                }

            }

            yield return null;
        }

        void OnDestroy()
        {
            _instance = null;
        }

        // Use this for initialization
        void Start()
        {

        }

        // Update is called once per frame
        void Update()
        {

        }
    }
}
