using UnityEngine;
using System.Collections;
using System.IO;
using LitJson;
using System.Collections.Generic;
using System.Text;

namespace SuperBoBo
{
    public class AppConfig
    {
        /// <summary>
        /// 资源版本号
        /// </summary>
        public Version resVersion = new Version(0, 0, 0);

        /// <summary>
        /// 代码版本号
        /// </summary>
        public Version codeVersion = new Version(0, 0, 0);

        /// <summary>
        /// APP显示版本号
        /// </summary>
        public Version appVersion = new Version(0, 0, 0);

        public static AppConfig Load()
        {
            var c = new AppConfig();
            c.resVersion = Version.LoadResVersion();
            c.codeVersion = Version.LoadCodeVersion();
            c.appVersion = new Version(Application.version);
            return c;
        }
    }


    public class VersionData
    {
        public string relase = "1.0.0";
        public string beta = "1.0.0";
    }


    public class AssetbundleJsonData
    {
        public string resName;
        public string hashCode;
        public int length;

        public AssetbundleJsonData(string name, string code, long len)
        {
            resName = name;
            hashCode = code;
            length = (int)len;

        }

        public AssetbundleJsonData()
        {
        }
    }

    public class AssetbundleJsonMap
    {
        public AssetbundleJsonData[] arrayRes;
        public AssetbundleJsonMap()
        {
        }

        public AssetbundleJsonData GetJsonData(string name)
        {
            foreach (AssetbundleJsonData data in arrayRes)
            {
                if (data.resName == name)
                    return data;
            }

            return null;
        }

        public void SetJsonData(string resName, AssetbundleJsonData resData)
        {
            bool exist = false;
            List<AssetbundleJsonData> listRes = new List<AssetbundleJsonData>(arrayRes);
            for (int i = 0; i < listRes.Count; i++)
            {
                AssetbundleJsonData data = listRes[i];
                if (data.resName == resName)
                {
                    listRes[i] = resData;
                    exist = true;
                }
            }
            if (!exist)
            {
                listRes.Add(resData);
            }

            arrayRes = listRes.ToArray();
        }
    }


    public class GameUpdater : MonoBehaviour
    {
        public Version currentResVersion = new Version(0, 0, 0);
        public Version currentCodeVersion = new Version(0, 0, 0);
        public Version newVersion;

        public AssetbundleJsonMap cdnMapHash;

        public JsonData cdnMD2;

        public string mdFile = "MD.dat";
        public string md2File = "MD2.dat";

        public float progress = 0;

        List<AssetbundleJsonData> updates = null;

        public string updateTip = null;
        public bool finished = false;
        //Byte/秒
        public static float networkAvgSpeed = 0f;
        public static float timeStart = 0f;
        public static float networkSpeed = 0f;

        //protected bool updateAPK = false;
        //public string apkName = "TankGirl.apk";
        //public static bool needUpdateAPK = false;
        //public static bool needUpdateRes = false;
        //public static GameUpdater instance = null;
        //public static System.Action onFinishUpdate;

        void ReStart()
        {
            UnityEngine.SceneManagement.SceneManager.LoadScene("Launcher");
        }

        #region 协程下载

        public delegate void OnDownloadFinish(WWW www);
        public delegate void OnDownloadFinish2(WWW www, AssetbundleJsonData json);

        public IEnumerator DownloadFile(string url, OnDownloadFinish callback)
        {
            CheckNetStatus();
            string u = FileUtils.url + "/" + url;
            WWW www = new WWW(u + "?time=" + System.DateTime.Now.Ticks + "&r=" + Random.Range(int.MinValue, int.MaxValue));
            tip = "下载文件 " + u + " " + www.progress;
#if UNITY_EDITOR
            Debug.Log(tip);
#endif
            float timeStart = Time.time;

            yield return www;
            networkSpeed = www.bytesDownloaded / (Time.time - timeStart);
            if (!string.IsNullOrEmpty(www.error))
            {
                Debug.LogError(www.error);

                if (FileUtils.IsAllCDNCantDownload())
                {
                    string msg = string.Format("网络错误(error : 801)\r\n{0}", www.responseHeaders.ContainsKey("STATUS") ? www.responseHeaders["STATUS"] : www.error);
                    UIMessageBoxHelper.Show(msg,
                        () =>
                        {
                            ReStart();
                        }
                        );
                    yield return new WaitForSeconds(4f);
                }
                else
                {
                    FileUtils.ChangeCDNState();
                    StartCoroutine(DownloadFile(url, callback));
                    Debug.Log(tip);
                }
            }

            if (www.isDone && string.IsNullOrEmpty(www.error))
            {
                callback(www);
            }

        }

        //    public IEnumerator DownloadAPKFile(string url, OnDownloadFinish callback)
        //    {

        //        CheckIsWifi();
        //        CheckNetStatus();

        //        string u = FileUtils.url + "/" + url;
        //        WWW www = new WWW(u + "?time=" + System.DateTime.Now.Ticks + "&r=" + Random.Range(int.MinValue, int.MaxValue));
        //        tip = "下载文件 " + u + " " + www.progress;
        //#if UNITY_EDITOR
        //        Debug.Log(tip);
        //#endif

        //        float timeStart = Time.time;

        //        yield return www;
        //        networkSpeed = www.bytesDownloaded / (Time.time - timeStart);
        //        UILoadingHelper.SetProgress(www.progress * apkSize / (resSize + apkSize) + resSize / (apkSize + resSize));


        //        if (!string.IsNullOrEmpty(www.error))
        //        {
        //            Debug.LogError(www.error);

        //            if (FileUtils.IsAllCDNCantDownload())
        //            {
        //                string msg = string.Format("网络错误(error : 801)\r\n{0}", www.responseHeaders.ContainsKey("STATUS") ? www.responseHeaders["STATUS"] : www.error);
        //                UIMessageBoxHelper.Show(msg,
        //                    () =>
        //                    {
        //                        ReStart();
        //                    }
        //                   );
        //                yield return new WaitForSeconds(4f);

        //            }
        //            else
        //            {
        //                FileUtils.ChangeCDNState();
        //                //u = FileUtils.url + "/" + url;
        //                //www = new WWW(u + "?time=" + System.DateTime.Now.Ticks + "&r=" + Random.Range(int.MinValue, int.MaxValue));
        //                //yield return www;
        //                //tip = "下载文件 " + u + " " + www.progress;
        //                //Debug.Log(tip);
        //                StartCoroutine(DownloadAPKFile(url, callback));
        //            }
        //        }

        //        if (www.isDone && string.IsNullOrEmpty(www.error))
        //        {
        //            networkAvgSpeed += www.bytes.Length;
        //            callback(www);
        //        }
        //    }

        void CheckIsWifi()
        {
            if (Application.internetReachability == NetworkReachability.ReachableViaCarrierDataNetwork)
            {
                if (ignore4g == false)
                {

                    string msg = "你当前处于运营商网络，下载会产生额外流量，是否继续更新？";
                    UIMessageBoxHelper.Show(msg,
                    () =>
                    {
                        ignore4g = true;
                    },
                    () =>
                    {
                        ReStart();
                    });
                }
            }
        }

        void CheckNetStatus()
        {

            if (Application.internetReachability == NetworkReachability.NotReachable)
            {

                string msg = string.Format("网络断开，请重试...");
                UIMessageBoxHelper.Show(
                    msg,
                    () =>
                    {

                    },
                    () =>
                    {
                        ReStart();
                    });

            }
        }


        #endregion
        void Start()
        {
            //instance = this;
            AppConfig config = AppConfig.Load();
            currentResVersion = config.resVersion;
            currentCodeVersion = config.codeVersion;
            tip = "当前资源版本号 ：" + currentResVersion;
            Debug.Log(tip);
            tip = "当前代码版本号 ：" + currentCodeVersion;
            Debug.Log(tip);


            CheckPersistDir();
        }


        void CheckPersistDir()
        {

            if (File.Exists(Application.persistentDataPath))
            {
                Debug.LogError("缓存文件夹和文件同名");
                File.Delete(Application.persistentDataPath);
            }
            if (!Directory.Exists(Application.persistentDataPath))
            {
                Debug.LogError("缓存文件夹不存在");
                Directory.CreateDirectory(Application.persistentDataPath);
            }

            if (File.Exists(Application.persistentDataPath))
            {
                UIMessageBoxHelper.Show("文件夹创建失败，请关闭安全软件或者重启",
                    () =>
                    {
                        Application.Quit();
                    });
            }

            Debug.Log(Application.persistentDataPath);

        }

        public void CheckIsFirstStart()
        {
            if (IsFullApkFirstStart())
            {

                SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_ApkFirstStart, null);
            }
            else
            {
                SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_ApkNormalStart, null);

            }
        }


        public void DownloadResVersionList()
        {
            string versionURL = string.Format("{0}/{1}", ResSetting.GetChannelRes(), "version.dat");

            if (Application.internetReachability == NetworkReachability.NotReachable)
            {
                string msg = string.Format("无法链接到网络");
                UIMessageBoxHelper.Show(
                    msg,
                    () =>
                    {
                        ReStart();
                    });
            }
            else
            {

                StartCoroutine(DownloadFile(versionURL, OnLoadVersionList));
            }
        }

        void OnLoadVersionList(WWW www)
        {
            bool b = string.IsNullOrEmpty(www.error);
            byte[] data = www.bytes;
            if (b)
            {

                Debug.Log("version.dat --> " + www.text);
                VersionData vesion_data = null;
                try
                {
                    vesion_data = JsonMapper.ToObject<VersionData>(www.text);
                }
                catch (System.Exception e)
                {
                    Debug.LogError(e.ToString());
                    UIMessageBoxHelper.Show("CDN版本号配置错误,请联系官方", () =>
                    {
                        ReStart();
                    });
                }
                Version cdn_release = new Version(vesion_data.relase);
                Version cdn_beta = new Version(vesion_data.beta);

                if (currentResVersion > cdn_beta)//最高版本，程序版本
                {
                    newVersion = currentResVersion;
                }

                else if (currentResVersion > cdn_release) //beta 先行版本
                {
                    newVersion = cdn_beta;
                }
                else // 外网版本
                {
                    newVersion = cdn_release;
                }

            }

            SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_DownloadVersionListDone, null);



        }

        public void DownLoadTips()
        {
            string urlUpdateTip = string.Format("{0}/{1}/{2}", ResSetting.GetChannelRes(), newVersion, "update.txt")
                + "?time=" + System.DateTime.Now.Ticks + "&r=" + UnityEngine.Random.Range(int.MinValue, int.MaxValue);
            tip = "从CDN下载更新Tips";
            Debug.LogError(tip);



            StartCoroutine(DownloadFile(urlUpdateTip, (www) =>
            {

                if (string.IsNullOrEmpty(www.error))
                {
                    updateTip = FileUtils.ReadStringFromBytes(www.bytes, false);
                }

                SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_DownloadUpdateTipDone);
            }));


        }



        public void CompareVersion()
        {

            if (currentResVersion < newVersion)
            {
                SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_CompareVersion);
            }
            else
            {
                SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_CompareVersion);
            }
        }


        /// <summary>
        /// 是否是该版本第一次启动
        /// </summary>
        /// <returns></returns>
        bool IsFullApkFirstStart()
        {
            //is full apk
            string filename = "firstStart";
            string version = Version.LoadVersionFromStreamingAsset().ToString();
            string content = "";
            FileUtils.ReadFileInPersistent(filename, ref content, false);
            if (string.IsNullOrEmpty(content)) //没有这个文件
            {

                FileUtils.WriteFileInPersistent(filename, version, false);
                return true;
            }
            else
            {
                if (content == version) //有这个文件并且内容相同，不是第一次启动
                    return false;
                else
                {
                    FileUtils.WriteFileInPersistent(filename, version, false);
                    return true;
                }
            }

        }


        public static void SafeWriteFileInPersistent(string fileName, byte[] content)
        {

#if UNITY_ANDROID && !UNITY_EDITOR
        long sizeB = AndroidHelper.GetSystemSize();
        if (sizeB == 0)
        {
            sizeB = AndroidHelper.GetSdCardSize();
        }
        int contB = (content.Length) + 10;
        //Debug.LogError("磁盘大小 " + (sizeB >> 20));
        if (sizeB < contB)
        {
            UIMessageBoxHelper.Show("磁盘空间不足，清理磁盘后再尝试！", () =>
            {
                Application.Quit();
                throw new System.Exception("磁盘空间不足");
            });
        }
        else
        {
             FileUtils.WriteFileInPersistent(fileName, content, false);
        }
#else

            FileUtils.WriteFileInPersistent(fileName, content, false);
#endif
        }

        public static void SafeWriteFileInPersistent(string fileName, string content)
        {

            Encoding encoding = Encoding.GetEncoding("UTF-8");
            byte[] cs = encoding.GetBytes(content);
            SafeWriteFileInPersistent(fileName, cs);
        }



        public void DownloadMD2File()
        {

            string urlMD2 = string.Format("{0}/{1}/{2}", ResSetting.GetChannelRes(), newVersion, "MD2.dat");

            tip = "  下载MD2文件 ";
            Debug.LogError(tip);

            StartCoroutine(DownloadFile(urlMD2, OnDownloadMD2Finish));


        }

        private void OnDownloadMD2Finish(WWW www)
        {
            bool success = string.IsNullOrEmpty(www.error);
            byte[] data = www.bytes;
            if (success)
            {

                string cdnMD2string = FileUtils.ReadStringFromBytes(data, false);
                cdnMD2 = JsonMapper.ToObject<JsonData>(cdnMD2string);


                JsonData cacheMD2 = null;
                string md2Cache = "";
                FileUtils.ReadFileInPersistent(md2File, ref md2Cache, false);

                try
                {
                    if (!string.IsNullOrEmpty(md2Cache))
                        cacheMD2 = JsonMapper.ToObject<JsonData>(md2Cache);
                }
                catch (System.Exception e)
                {
                    Debug.LogError(e.ToString());
                    cacheMD2 = null;
                }


                JsonData streamingMD2 = null;
                string mdSecondStreaming = FileUtils.ReadStringFromStreaming(md2File, false);

                try
                {

                    if (!string.IsNullOrEmpty(mdSecondStreaming))
                        streamingMD2 = JsonMapper.ToObject<JsonData>(mdSecondStreaming);
                }
                catch (System.Exception e)
                {
                    Debug.LogError(e.ToString());
                    streamingMD2 = null;
                }

                if (cacheMD2 == null && streamingMD2 == null)
                {

                    tip = "  缓存目录和流媒体目录 不存在MD2文件 ";
                    Debug.LogError(tip);

                    SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_DownloadMD2Done, null);
                }

                if (cacheMD2 != null && streamingMD2 == null)
                {

                    tip = "  缓存目录 存在MD2文件 ";
                    Debug.LogError(tip);


                    CompareMD2(cacheMD2, cdnMD2);
                }

                if (cacheMD2 == null && streamingMD2 != null)
                {
                    tip = "  流媒体目录 存在MD2文件 ";
                    Debug.LogError(tip);
                    CompareMD2(streamingMD2, cdnMD2);
                }

                if (cacheMD2 != null && streamingMD2 != null)
                {

                    tip = "  缓存目录和流媒体目录都 存在MD2文件 ";
                    Debug.LogError(tip);
                    System.DateTime streamingtime;
                    bool p = System.DateTime.TryParse(streamingMD2["time"].ToString(), out streamingtime);
                    System.DateTime cachetime;
                    bool localP = System.DateTime.TryParse(cacheMD2["time"].ToString(), out cachetime);

                    if (p && localP && streamingtime > cachetime)//比较stream下MD2文件
                    {


                        tip = "  缓存目录中的资源过旧,删除缓存目录 ";
                        Debug.LogError(tip);
                        //                    FileUtils.DeleteFolder(Application.persistentDataPath);

                        //避免语音二次下载
                        string[] pathList = Directory.GetFiles(Application.persistentDataPath);
                        for (int i = 0; i < pathList.Length; i++)
                        {
                            if (!pathList[i].Contains("Audio"))
                                FileUtils.DeleteFile(pathList[i]);
                        }

                        CompareMD2(streamingMD2, cdnMD2);

                    }
                    else//比较cache下的md2
                    {
                        CompareMD2(cacheMD2, cdnMD2);
                    }
                }


            }
        }


        public void CompareMD2(JsonData j1, JsonData j2)
        {

            if (j1["hashCode"].ToString() == j2["hashCode"].ToString()) //不需要下载MD文件
            {
                //tip = "  不用下载MD文件,直接比较APK ";
                //Debug.LogError(tip);

                //if (updateAPK)
                //{
                //    if (FileUtils.ExistsInPersistent(apkName) && apkMd5 == ResCommon.GetFileMD5(Application.persistentDataPath + "/" + apkName))
                //    {
                //        updateAPK = false;
                //        InstallApk(Application.persistentDataPath + "/" + apkName);
                //        tip = " 更新完毕,保存版本号  ";
                //        Debug.LogError(tip);
                //        currentResVersion = newVersion;
                //        Version.SaveVersion(currentResVersion);
                //        //StartGame();
                //        SuperBoBo.EventManager.Instance.FireEvent(GameEventType.Updater_UpdateDone, null);

                //    }
                //    else
                //    {
                //        ShowTip(apkSize, () =>
                //        {
                //            StartCoroutine(DownloadAPK(() =>
                //            {
                //                tip = " 更新完毕,保存版本号  ";
                //                Debug.LogError(tip);
                //                currentResVersion = newVersion;
                //                Version.SaveVersion(currentResVersion);
                //                //StartGame();
                //                SuperBoBo.EventManager.Instance.FireEvent(GameEventType.Updater_UpdateDone, null);
                //                //UILoadingStupid.instacne.logo.gameObject.SetActive(false);
                //            }));
                //        });
                //    }
                //}
                //else
                //{
                tip = " 更新完毕,保存版本号  ";
                Debug.LogError(tip);
                currentResVersion = newVersion;
                Version.SaveVersion(currentResVersion);
                //StartGame();
                SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_UpdateDone, null);
                //}



            }
            else//需要下载MD文件
            {
                SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_DownloadMD2Done, null);
                //            DownLoadMD();
            }

        }

        public void DownloadMD()
        {
            string urlMD = string.Format("{0}/{1}/{2}", ResSetting.GetChannelRes(), newVersion, mdFile);

            tip = "  下载MD文件 ";
            Debug.LogError(tip);
            StartCoroutine(DownloadFile(urlMD, OnDownloadMDFinish));
        }


        AssetbundleJsonMap LoadMDFromPersistent()
        {
            //read presistent
            string mdCache = "";
            AssetbundleJsonMap cacheMapHash = null;

            try
            {
                FileUtils.ReadFileInPersistent(mdFile, ref mdCache, false);
                if (!string.IsNullOrEmpty(mdCache))
                    cacheMapHash = JsonMapper.ToObject<AssetbundleJsonMap>(mdCache);
            }
            catch (System.Exception e)
            {
                Debug.LogError(e.ToString());
                mdCache = "";
                cacheMapHash = null;
            }

            return cacheMapHash;
        }

        AssetbundleJsonMap LoadMDFromStreaming()
        {
            //read streaming          
            string mdStreaming = "";
            AssetbundleJsonMap streamingMapHash = null;

            try
            {
                mdStreaming = FileUtils.ReadStringFromStreaming(mdFile, false);

                if (!string.IsNullOrEmpty(mdStreaming))
                    streamingMapHash = JsonMapper.ToObject<AssetbundleJsonMap>(mdStreaming);

            }
            catch (System.Exception e)
            {
                Debug.LogError(e.ToString());
                mdStreaming = "";
                streamingMapHash = null;
            }

            return streamingMapHash;
        }

        void CheckMD(byte[] data)
        {
            //read cdn
            string cdnMDstring = FileUtils.ReadStringFromBytes(data, false);

            if (!string.IsNullOrEmpty(cdnMDstring))
                cdnMapHash = JsonMapper.ToObject<AssetbundleJsonMap>(cdnMDstring);
            else
            {
                cdnMapHash = new AssetbundleJsonMap();
            }

            //read presistent
            AssetbundleJsonMap cacheMapHash = LoadMDFromPersistent();

            AssetbundleJsonMap streamingMapHash = LoadMDFromStreaming();


            if (cacheMapHash == null && streamingMapHash == null)//直接更新资源
            {

                tip = "   缓存目录和流媒体目录都 不存在MD文件 ";
                Debug.LogError(tip);

                updates = new List<AssetbundleJsonData>();
                updates.AddRange(cdnMapHash.arrayRes);
            }

            if (cacheMapHash == null && streamingMapHash != null)
            {
                tip = "  流媒体目录 存在MD文件 ";
                Debug.LogError(tip);
                updates = CompareMD(cdnMapHash, streamingMapHash);
            }

            if (cacheMapHash != null && streamingMapHash == null)
            {
                tip = "  缓存目录 存在MD文件 ";
                Debug.LogError(tip);
                updates = CompareMD(cdnMapHash, cacheMapHash);
            }

            //以缓存目录为准 
            //why？ 
            //因为第一步比较MD2的过程中，已经把资源过旧的问题排除了
            //出现这种情况,只可能是缓存目录是最新的资源
            if (cacheMapHash != null && streamingMapHash != null)
            {
                tip = "  缓存目录和流媒体目录都 存在MD文件 ";
                Debug.LogError(tip);
                updates = CompareMD(cdnMapHash, cacheMapHash);
            }


            SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_DownloadMDDone);

        }




        /// <summary>
        /// 检测更新大小的弹窗
        /// </summary>
        public void ShowUpdateTip()
        {
            if (updates == null || updates.Count == 0)
            {
                SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_UpdateDone);
            }
            else
            {
                float ret = 0;
                foreach (var k in updates)
                {
                    resSize += k.length;
                }
                resSize = resSize / (1 << 20);

                //if (FileUtils.ExistsInPersistent(apkName) && apkMd5 == ResCommon.GetFileMD5(Application.persistentDataPath + "/" + apkName))
                //{
                //    ret = resSize;
                //}
                //else
                //{
                //    ret = resSize + apkSize;
                //}
                ret = resSize;
                ShowTip(ret, () => { StartCoroutine(UpdateRes(updates)); });
            }
        }

        private void OnDownloadMDFinish(WWW www)
        {

            bool success = string.IsNullOrEmpty(www.error);
            byte[] data = www.bytes;
            if (success)
            {
                CheckMD(data);
            }
        }

        float resSize = 0;

        public List<AssetbundleJsonData> updateFiles = null;


        public int downFileCount = 0;
        public bool condition = true;

        public bool ignore4g = false;

        static int download = 0;


        public IEnumerator UpdateRes(List<AssetbundleJsonData> updateFiles)
        {
            download = 0;
            tip = " 更新资源中 文件个数 " + updateFiles.Count;
            Debug.LogError(tip);
            this.updateFiles = updateFiles;
            UILoadingHelper.Start(1, null);
            int taskNum = 10;

            MultiWWW.instance.Init(20);
            while (MultiWWW.instance.currentDownload < updateFiles.Count)
            {
                if ((downFileCount - MultiWWW.instance.currentDownload) <= (taskNum / 2) && downFileCount < updateFiles.Count)
                {
                    for (int i = 0; i < taskNum; i++)
                    {
                        if (downFileCount < updateFiles.Count)
                        {
                            string urlFile = string.Format("{0}/{1}/{2}", ResSetting.GetChannelRes(), newVersion, updateFiles[downFileCount].resName);
                            MultiWWW.instance.AddJob(urlFile, OnDonwloadResFinish, updateFiles[downFileCount]);
                            downFileCount++;
                        }
                    }
                }

                if (condition)
                {
                    UIMessageBoxHelper.Cancel();
                    if (MultiWWW.instance.current != null)
                        tip = "下载文件 " + MultiWWW.instance.current.url;
                    yield return MultiWWW.instance.StartDownload();
                }

                if (Application.internetReachability == NetworkReachability.ReachableViaLocalAreaNetwork)
                {
                    condition = true;
                }

                if (Application.internetReachability == NetworkReachability.ReachableViaCarrierDataNetwork)
                {
                    if (ignore4g == false)
                    {
                        condition = false;

                        string msg = "你当前处于运营商网络，下载会产生额外流量，是否继续更新？";
                        UIMessageBoxHelper.Show(msg,
                        () =>
                        {
                            ignore4g = true;
                            condition = true;
                        },
                        () =>
                        {

                            condition = false;
                            ReStart();
                        });
                    }
                }

                if (Application.internetReachability == NetworkReachability.NotReachable)
                {
                    condition = false;
                    string msg = string.Format("网络断开，尝试重连中...");
                    UIMessageBoxHelper.Show(
                        msg,
                        () =>
                        {

                        },
                        () =>
                        {
                            ReStart();
                        });
                }

                if (condition == false)
                {
                    yield return new WaitForSeconds(2f);
                }
                UILoadingHelper.SetProgress((float)MultiWWW.instance.currentDownload / (float)updateFiles.Count * (resSize / (resSize)));
            }

            UILoadingHelper.SetProgress(resSize / (resSize));

        }


        private void OnDonwloadResFinish(WWW www, AssetbundleJsonData json)
        {
            bool success = string.IsNullOrEmpty(www.error);
            byte[] data = www.bytes;

            if (success)
            {
                if (json.resName.Contains("version.dat"))
                {
                    tip = " 忽略version.dat ";
                    Debug.LogError(tip);

                }
                else
                {
                    SafeWriteFileInPersistent(json.resName, data);
                }

                download++;
                if (download == updateFiles.Count)
                {
                    StartCoroutine(DoLastJob());
                }

            }
            else
            {
                UIMessageBoxHelper.onShow0("error: 801");
            }


            //else
            //{
            //    downFileCount--;
            //}

        }

        //public IEnumerator DownloadAPK(System.Action callback = null)
        //{
        //    if (updateAPK)
        //    {
        //        //todo
        //        if (FileUtils.ExistsInPersistent(apkName) && apkMd5 == ResCommon.GetFileMD5(Application.persistentDataPath + "/" + apkName))
        //        {
        //            updateAPK = false;
        //            InstallApk(Application.persistentDataPath + "/" + apkName);
        //        }
        //        else
        //        {
        //            string urlNewApk = "";
        //            yield return GetChannelApk((ret) =>
        //            {
        //                urlNewApk = string.Format("{0}/{1}/{2}", ret, newVersion, apkName);
        //            });
        //            yield return DownloadAPKFile(urlNewApk, OnLoadedApk);
        //        }
        //    }

        //    yield return new WaitForEndOfFrame();

        //    if (callback != null) callback();
        //}


        /// <summary>
        /// 这个下载APK的时候要注意quick渠道的资源是quick，母包的大小包也在quick目录下，但是子包APK路径不一样
        /// </summary>
        /// <returns></returns>
        //    private IEnumerator GetChannelApk(System.Action<string> callback)
        //    {
        //        string tag = "_release/";
        //        string channelName = ResSetting.channelResName;

        //#if SDK_Quick
        //        int id = quicksdk.QuickSDK.getInstance().channelType();
        //        yield return GetChannelNameByID(id, (ret) =>
        //        {
        //            channelName = ret;
        //        });
        //#endif



        //        //if (FileUtils.isInternalNetwork)
        //        //{
        //        //    tag = "_debug/";
        //        //}
        //        //else
        //        //{
        //        //    tag = "_release/";
        //        //}
        //        if (callback != null)
        //        {
        //            callback(channelName + tag + ResSetting.GetPlatformName());
        //        }

        //        yield return null;
        //    }

        //private Dictionary<int, string> paths = new Dictionary<int, string>();
        //private IEnumerator GetChannelNameByID(int id, System.Action<string> callback)
        //{
        //    if (paths != null && paths.Count == 0)
        //    {
        //        string urlForFile = string.Format("{0}", "channel.txt")
        //            + "?time=" + System.DateTime.Now.Ticks + "&r=" + UnityEngine.Random.Range(int.MinValue, int.MaxValue);
        //        yield return DownloadFile(urlForFile,
        //             (www) =>
        //             {
        //                 if (string.IsNullOrEmpty(www.error))
        //                 {
        //                     string content = www.text;
        //                     content = content.Replace("\r\n", "\n").Replace(" ", "");
        //                     string[] lines = content.Split('\n');
        //                     foreach (var k in lines)
        //                     {
        //                         if (k.Contains("="))
        //                         {
        //                             string[] kv = k.Split('=');
        //                             paths.Add(int.Parse(kv[0]), kv[1]);
        //                             Debug.LogError("channel id " + kv[0] + " res path " + kv[1]);
        //                         }
        //                     }
        //                     if (paths.ContainsKey(id))
        //                     {
        //                         Debug.LogError("use channel id " + id + " apk path " + paths[id]);
        //                         if (callback != null)
        //                             callback(paths[id]);
        //                     }
        //                     else
        //                         throw new System.Exception("channel path not find id -> " + id);
        //                 }
        //                 else
        //                 {
        //                     //没网络
        //                     UIMessageBoxHelper.Show("获取channel.txt资源失败",
        //                         () =>
        //                         {
        //                             ReStart();

        //                         }
        //                     );

        //                 }

        //             });

        //    }
        //    else
        //    {
        //        if (paths.ContainsKey(id))
        //        {
        //            if (callback != null)
        //                callback(paths[id]);
        //        }
        //        else
        //            throw new System.Exception("channel path not find id -> " + id);

        //    }
        //}


        public IEnumerator DoLastJob()
        {


            tip = " 缓存目录保存MD文件 ";
            Debug.LogError(tip);
            SafeWriteFileInPersistent(mdFile, JsonMapper.ToJson(cdnMapHash));

            tip = " 缓存目录保存MD2文件 ";
            Debug.LogError(tip);
            SafeWriteFileInPersistent(md2File, cdnMD2.ToJson());

            //if (updateAPK)
            //{
            //    yield return DownloadAPK();
            //}

            tip = " 更新完毕,保存版本号  ";
            Debug.LogError(tip);
            currentResVersion = newVersion;
            Version.SaveVersion(currentResVersion);

            SetFileUtilInfos();

            yield return null;

            SuperBoBo.EventManager.Instance.FireEvent(UpdateEvent.Updater_UpdateDone, null);

            finished = true;
        }

        public List<AssetbundleJsonData> CompareMD(AssetbundleJsonMap cdn, AssetbundleJsonMap map2)
        {

            List<AssetbundleJsonData> updateFiles = new List<AssetbundleJsonData>();


            for (int i = 0; i < cdn.arrayRes.Length; i++)
            {
                AssetbundleJsonData data = cdn.arrayRes[i];
                AssetbundleJsonData local = map2.GetJsonData(data.resName);
                if (local == null)
                {

                    updateFiles.Add(data);
                }
                else if (data.hashCode == local.hashCode)
                {

                }
                else
                {
                    updateFiles.Add(data);
                }

            }
            return updateFiles;
        }


        void SetFileUtilInfos()
        {
            FileUtils.cdnFileInfos.Clear();

        }

        //public static void StartGame()
        //{
        //    if (instance.isInstalled)//默认都是走这个，除非安装失败
        //    {

        //        GameObject.Destroy(instance.gameObject, 1f);
        //        if (onFinishUpdate != null) onFinishUpdate();
        //    }
        //    else
        //    {
        //        instance.ReStart();
        //    }
        //}

        delegate void OnDo();

        void ShowTip(float size, OnDo dofunc)
        {
            string msg = null;
            switch (Application.internetReachability)
            {
                //4g or 3g
                case NetworkReachability.ReachableViaCarrierDataNetwork:
                    msg = string.Format(" 本次更新约{0:F2}MB，你当前处于运营商网络，是否开始更新？", size);
                    break;
                //wifi
                case NetworkReachability.ReachableViaLocalAreaNetwork:
                    msg = string.Format(" 本次更新约{0:F2}MB，你当前处于wifi网络，是否开始更新？", size);
                    break;
                default:
                    break;
            }

            if (string.IsNullOrEmpty(updateTip))
            {
                UIMessageBoxHelper.Show(msg,
                () =>
                {
                    dofunc();
                },
                () =>
                {
#if UNITY_EDITOR
                UnityEditor.EditorApplication.isPlaying = false;
#else

                Application.Quit();
#endif
            });
            }
            else
            {
                UIMessageBoxHelper.ShowUpdate(updateTip, msg,
                    () =>
                    {
                        timeStart = Time.time;
                        dofunc();
                    },
                    () =>
                    {
#if UNITY_EDITOR
                    UnityEditor.EditorApplication.isPlaying = false;
#else

                Application.Quit();
#endif
                });

            }



        }

        //void UpdateAPK(string version)
        //{
        //    updateAPK = true;
        //    DownloadAPKInfo(version);
        //}
        //private float apkSize = 0;
        //private string apkMd5 = "";
        //void DownloadAPKInfo(string version)
        //{
        //    if (updateAPK)
        //    {

        //        StartCoroutine(GetChannelApk(
        //            (ret) =>
        //            {
        //                string urlNewApkSize = string.Format("{0}/{1}/{2}", ret, newVersion, "apk.info") + "?time=" + System.DateTime.Now.Ticks + "&r=" + UnityEngine.Random.Range(int.MinValue, int.MaxValue);

        //                StartCoroutine(DownloadFile(urlNewApkSize, (www) =>
        //                {
        //                    if (string.IsNullOrEmpty(www.error))
        //                    {
        //                        if (www.text != null && www.text != "")
        //                        {
        //                            string[] lines = www.text.Replace("\r\n", "\n").Split('\n');
        //                            bool bad = false;
        //                            if (lines.Length != 2)
        //                            {
        //                                bad = true;
        //                            }
        //                            else
        //                            {
        //                                bad = !float.TryParse(lines[0], out apkSize);
        //                                apkSize = float.Parse(lines[0]);
        //                                apkMd5 = lines[1];

        //                            }
        //                            if (bad)
        //                            {
        //                                UIMessageBoxHelper.Show("APKINFO 错误 " + urlNewApkSize, () =>
        //                                {
        //                                    ReStart();
        //                                });

        //                            }
        //                        }

        //                        DownloadMD2File();
        //                    }
        //                    else
        //                    {
        //                        UIMessageBoxHelper.Show("APKINFO 下载失败 " + urlNewApkSize, () =>
        //                        {
        //                            ReStart();
        //                        });
        //                    }
        //                }));

        //            }));

        //    }
        //}

        //    public bool isInstalled = true;

        //    public void InstallApk(string url)
        //    {
        //        Debug.LogError("InstallApk ……");
        //#if UNITY_EDITOR
        //        Version.SaveVersion2StreamingAsset(newVersion);
        //        //UnityEditor.EditorApplication.isPlaying = false;
        //        //UnityEditor.EditorApplication.isPlaying = true;
        //#elif UNITY_ANDROID
        //        AndroidJavaClass jc = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
        //        AndroidJavaObject jo = jc.GetStatic<AndroidJavaObject>("currentActivity");
        //        jo.Call("InstallApk", url);

        //        //应该不调用，如果调用了，就是安装失败
        //        //Application.Quit(); 
        //        isInstalled = false;        
        //        //Version.SaveVersion(currentVersion);

        //#endif
        //    }

        //    void OnLoadedApk(WWW www)
        //    {
        //        bool success = string.IsNullOrEmpty(www.error);
        //        byte[] data = www.bytes;

        //        if (success)
        //        {
        //            FileStream fs = new FileStream(Application.persistentDataPath + "/" + apkName, FileMode.Create);
        //            fs.Write(data, 0, data.Length);
        //            fs.Flush();
        //            fs.Close();
        //#if UNITY_EDITOR
        //            tip = " 缓存版本号 " + newVersion;
        //            Version.SaveVersion(newVersion);
        //#endif
        //            updateAPK = false;
        //            InstallApk(Application.persistentDataPath + "/" + apkName);

        //        }

        //    }



        public string tip = "";

        void OnGUI()
        {
#if UNITY_EDITOR
            if (!finished)
            {
                GUI.color = Color.red;
                GUILayout.Space(10);
                GUILayout.Label("资源版本号：" + currentResVersion.ToString());
                GUILayout.Label("代码版本号：" + currentCodeVersion.ToString());
                GUILayout.Label("工作内容：" + tip);
                //GUILayout.Label("CDN地址：" + FileUtils.url);
                GUILayout.Label(string.Format("平均速度 ：{0:F2} MB/S", networkAvgSpeed / 1024 / 1024 / (Time.time - timeStart)));
                GUI.color = Color.white;
            }
#endif
        }


    }
}