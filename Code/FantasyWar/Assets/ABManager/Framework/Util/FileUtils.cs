/*
 * FileUtil.cs
 * 开启 ;RUNTIME_ENCRYPT;CUSTOM_CHANNEL;
 *     
 *      会加密，运行时检查文件，
 */

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Security.Cryptography;
using System.Text;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace SuperBoBo
{
    public class FileUtils
    {
        public static Dictionary<string, AssetbundleJsonData> cdnFileInfos = new Dictionary<string, AssetbundleJsonData>();
#if RUNTIME_ENCRYPT
    public static bool isEncrypt = true;
#else
        public static bool isEncrypt = false;
#endif

        public static Encoding encoding = Encoding.GetEncoding("UTF-8");



        //public static string url = "http://192.168.2.85";
        //public static string url = "http://zjlmcdn.joygame.cn/zjlm/close_beta/";



        private static bool _isInternalNetwork = true;
        private static string _url = "http://116.236.180.14";

        //    private static bool _isReadNetworkConfig = false;
        private static bool _isReadUrl = false;
        private static bool _isTestedCDN = false;

        //去掉了内外网的判定
        //    public static bool isInternalNetwork
        //    {
        //        get
        //        {
        //#if UNITY_EDITOR
        //            string data = FileUtils.ReadStringFromStreaming("config.dat");
        //            if (string.IsNullOrEmpty(data)) return true;
        //            bool.TryParse(data, out _isInternalNetwork);

        //            return _isInternalNetwork;

        //#else
        //                if (!_isReadNetworkConfig)
        //                {
        //                    _isReadNetworkConfig = true;
        //                    string data = FileUtils.ReadStringFromStreaming("config.dat");
        //                    if (string.IsNullOrEmpty(data)) return true;
        //                    bool.TryParse(data, out _isInternalNetwork);

        //                    return _isInternalNetwork;
        //                }
        //                else
        //                {
        //                    return _isInternalNetwork;
        //                }
        //#endif

        //        }
        //    }

        public class URLData
        {
            public string url;
            public bool pingOK = true;
            public bool downloadOK = true;
            public bool isUsed = false;
        }

        public static Dictionary<string, URLData> urlDatas = new Dictionary<string, URLData>();

        ///// <summary>
        ///// 传入参数不规则
        ///// </summary>
        ///// <param name="url">eg."http://zjlmcdn.joygame.cn/zjlm/close_beta/"</param>
        ///// <returns></returns>
        //public static bool isCDNOK(string url)
        //{


        //    bool r = false;

        //    if (urlDatas.ContainsKey(url))
        //    {
        //        return urlDatas[url].pingOK;
        //    }
        //    else
        //    {
        //        try
        //        {
        //            //System.Net.NetworkInformation.Ping ping = new System.Net.NetworkInformation.Ping();
        //            //System.Net.NetworkInformation.PingReply res = ping.Send(ret,1);
        //            //if (res.Status != System.Net.NetworkInformation.IPStatus.Success)
        //            //{
        //            //    r = true;
        //            //}
        //            string ret = url.Replace("http://", "");
        //            if (ret.Contains("/"))
        //                ret = ret.Substring(0, ret.IndexOf("/"));
        //            IPAddress[] addresss = Dns.GetHostAddresses(ret);
        //            foreach (var k in addresss)
        //            {
        //                Ping p = new Ping(k.ToString());
        //                long statTime = System.DateTime.Now.Ticks;
        //                while (!p.isDone)
        //                {
        //                    long time = System.DateTime.Now.Ticks - statTime;
        //                    if (time >= 30000000)
        //                    {
        //                        break;
        //                    }
        //                }
        //                r = (p.time != -1 && p.time <= 3000);
        //                if (r) break;
        //            }

        //        }
        //        catch (System.Exception e)
        //        {
        //            Debug.LogError(e.ToString());
        //        }

        //        URLData d = new URLData();
        //        d.pingOK = r;
        //        d.url = url;

        //        urlDatas.Add(url, d);
        //    }

        //    return r;
        //}



        private static string[] urls = null;

        private static bool _isReadChannelID = false;
        //private static int _channelID = 85;
        private static int _channelID = 0;

        public static int ChannelID()
        {
            //   return 85;
#if UNITY_EDITOR
            string content = FileUtils.ReadStringFromStreaming("channel.dat", false);
            if (!string.IsNullOrEmpty(content))
            {

                if (int.TryParse(content, out _channelID))
                {
                    return _channelID;
                }
                else
                {
                    Debug.LogError("渠道号配置错误，使用默认0");
                    return _channelID;
                }
            }
            else
            {
                return _channelID;
            }


#else
        if (_isReadChannelID == false)
        {
            _isReadChannelID = true;    
            string content = FileUtils.ReadStringFromStreaming("channel.dat", false);
            if (!string.IsNullOrEmpty(content))
            {
               
                if (int.TryParse(content, out _channelID))
                {
                    return _channelID;
                }
                else
                {
                    Debug.LogError("渠道号配置错误，使用默认250");
                    return _channelID;
                }
            }
            else
            {
                return _channelID;
            }

        }
        return _channelID;
#endif
        }

        public static bool _isDev = false;

        public static string TestCDN()
        {
            if (_isDev)
            {
                return "http://116.236.180.14";
            }
#if UNITY_EDITOR
            string content = FileUtils.ReadStringFromStreaming("url.dat", false);

            if (!string.IsNullOrEmpty(content))
            {
                urls = content.Replace("\r\n", "\n").Split('\n');

                foreach (var k in urls)
                {
                    if (!urlDatas.ContainsKey(k))
                    {
                        URLData data = new URLData();
                        data.pingOK = true;
                        data.isUsed = false;
                        data.downloadOK = true;
                        data.url = k;
                        urlDatas.Add(k, data);
                    }
                }

            }
#else
        if (!_isReadUrl)
        {
            _isReadUrl = true;

            string content = FileUtils.ReadStringFromStreaming("url.dat",false);

            if (!string.IsNullOrEmpty(content))
            {
                urls = content.Replace("\r\n", "\n").Split('\n');
                foreach(var k in urls)
                 {
                    if(!urlDatas.ContainsKey(k))
                    {
                        URLData data = new URLData();
                        data.pingOK = true;
                        data.isUsed = false;
                        data.downloadOK = true;
                        data.url = k;
                        urlDatas.Add(k, data);
                    }   
                 }
            }
        }
#endif
            if (urls == null || urls.Length == 0)
                return null;
            //Common.ShowLoading();
            //#if UNITY_EDITOR
            //        foreach (var k in urls)
            //        {
            //            isCDNOK(k);
            //        }
            //#else
            //            if (!_isTestedCDN)
            //            {
            //                _isTestedCDN = true;
            //                foreach (var k in urls)
            //                {
            //                    isCDNOK(k);
            //                }
            //            }
            //#endif

            bool isAnyPingOk = true;
            //foreach (var k in urlDatas)
            //{
            //    if (k.Value.pingOK)
            //    {
            //        isAnyPingOk = true;
            //        break;
            //    }

            //}

            if (!isAnyPingOk)
            {
                //Common.HideLoading();
                UIMessageBoxHelper.Show("网络断开" + "(error : 701)", () =>
                {
                    SceneManager.LoadScene("Launcher");
                }
                );

                throw new System.Exception("网络断开(error : 701)");
            }
            else
            {
                //Common.HideLoading();
                URLData data = null;
                foreach (var k in urlDatas)
                {
                    if (!k.Value.isUsed && k.Value.downloadOK)
                    {
                        data = k.Value;
                        //Debug.LogError("CDN地址无效，切换新IP：" + data.url);
                        break;
                    }

                }
                if (data == null)
                    return urls[0];
                return data.url;
            }

        }



        public static bool IsAllCDNCantDownload()
        {
            bool ret = true;
            foreach (var k in urlDatas)
            {
                if (k.Value.downloadOK == true)
                {
                    ret = false;
                    break;
                }
            }
            return ret;
        }

        public static void ChangeCDNState()
        {
            string ret = _url;//如果不存在url.data 使用默认网址
            if (urlDatas.ContainsKey(ret))//存在url.data
            {
                urlDatas[ret].downloadOK = false;
                urlDatas[ret].isUsed = true;
            }
        }

        public static string url
        {
            get
            {
                _url = TestCDN();
                if (string.IsNullOrEmpty(_url)) _url = "http://116.236.180.14";

                //_url += IPConfigInfo.GetInstance().CDNPath();

#if UNITY_IOS
            _url = _url.Replace("http","https");
#endif
                return _url;
            }
            set
            {
                _url = value;
            }

        }

        static FileUtils()
        {

        }

        /// <summary>
        /// 返回Application.streamingAssetsPath
        /// </summary>
        /// <returns></returns>
        public static string StreamingPath()
        {
            string path = Application.streamingAssetsPath;
            return path;
        }



        public static void DeleteFolder(string dir)
        {
            if (Directory.Exists(dir))
                Directory.Delete(dir, true);
        }

        public static void DeleteFile(string dir)
        {
            if (Directory.Exists(dir))
                Directory.Delete(dir, true);
            else if (File.Exists(dir))
                File.Delete(dir);
        }


        public static string StreamingUrl()
        {

            string url = "file://" + Application.streamingAssetsPath;
#if UNITY_EDITOR
            url = "file://" + Application.streamingAssetsPath;
#elif UNITY_ANDROID
        url = Application.streamingAssetsPath;
#elif UNITY_IOS
        url ="file://" + Application.streamingAssetsPath;
#endif
            return url;
        }

        public static bool ExistsInPersistent(string name)
        {
            string filename = Application.persistentDataPath + "/" + name;
            if (!File.Exists(filename))
            {
                return false;
            }
            return true;
        }

        private static void CreateFolder(string dir)
        {
            dir = dir.Replace(@"\", "/");
            if (!Directory.Exists(dir))
            {
                if (dir.IndexOf(@"/") != -1)
                {
                    CreateFolder(dir.Substring(0, dir.LastIndexOf(@"/")));
                }

                Directory.CreateDirectory(dir);
            }
        }

        private static void CreateFolderForFile(string fileName)
        {
            fileName = fileName.Replace(@"\", "/");
            if (fileName.LastIndexOf("/") != -1)
            {
                string dir = fileName.Substring(0, fileName.LastIndexOf("/"));
                CreateFolder(dir);
            }
        }

        //--------------------------------------------------------------------------------------------------------------
        private static string sKey = "esnefeDe";
        private static string sIV = "esnefeDe";
        //����
        public static string Decrypt(string pToDecrypt)
        {
            if (string.IsNullOrEmpty(pToDecrypt))
            {
                return null;
            }
            using (DESCryptoServiceProvider des = new DESCryptoServiceProvider())
            {

                byte[] inputByteArray = new byte[pToDecrypt.Length / 2];
                //��ת
                for (int x = 0; x < pToDecrypt.Length / 2; x++)
                {
                    int i = (Convert.ToInt32(pToDecrypt.Substring(x * 2, 2), 16));
                    inputByteArray[x] = (byte)i;
                }
                //�趨���ܽ�Կ(תΪByte)
                des.Key = ASCIIEncoding.ASCII.GetBytes(sKey);
                //�趨��ʼ������(תΪByte)
                des.IV = ASCIIEncoding.ASCII.GetBytes(sIV);
                using (MemoryStream ms = new MemoryStream())
                {
                    using (CryptoStream cs = new CryptoStream(ms, des.CreateDecryptor(), CryptoStreamMode.Write))
                    {
                        //�쳣����
                        try
                        {
                            cs.Write(inputByteArray, 0, inputByteArray.Length);
                            cs.FlushFinalBlock();
                            //���
                            return System.Text.Encoding.Default.GetString(ms.ToArray());
                        }
                        catch (CryptographicException)
                        {
                            //���Կ����������
                            return "0";
                        }
                    }
                }
            }
        }

        //����
        public static string Encrypt(string pToEncrypt)
        {
            StringBuilder ret = new StringBuilder();
            using (DESCryptoServiceProvider des = new DESCryptoServiceProvider())
            {
                //����Ԫת��ΪByte
                byte[] inputByteArray = Encoding.Default.GetBytes(pToEncrypt);
                //�趨���ܽ�Կ(תΪByte)
                des.Key = ASCIIEncoding.ASCII.GetBytes(sKey);
                //�趨��ʼ������(תΪByte)
                des.IV = ASCIIEncoding.ASCII.GetBytes(sIV);

                using (MemoryStream ms = new MemoryStream())
                {
                    using (CryptoStream cs = new CryptoStream(ms, des.CreateEncryptor(), CryptoStreamMode.Write))
                    {
                        cs.Write(inputByteArray, 0, inputByteArray.Length);
                        cs.FlushFinalBlock();
                    }
                    //���
                    foreach (byte b in ms.ToArray())
                        ret.AppendFormat("{0:X2}", b);
                }
            }
            //����
            return ret.ToString();
        }

        static byte key = 0xab;
        //����
        public static void Decrypt(ref byte[] pToDecrypt)
        {
            int interval = (int)(pToDecrypt.Length * 0.001f) + 1;
            for (int i = 0; i < pToDecrypt.Length;)
            {
                pToDecrypt[i] ^= key;
                i += interval;
            }
            return;
        }

        //����
        public static void Encrypt(ref byte[] pToEncrypt)
        {
            int interval = (int)(pToEncrypt.Length * 0.001f) + 1;
            for (int i = 0; i < pToEncrypt.Length;)
            {
                pToEncrypt[i] ^= key;
                i += interval;
            }
            return;
        }


        public static void WriteFileInPersistent(string name, byte[] content, bool bEncrypt)
        {
            string filename = Application.persistentDataPath + "/" + name;
            WriteFile(filename, content, bEncrypt);
        }

        public static void WriteFileInPersistent(string name, byte[] content)
        {
            string filename = Application.persistentDataPath + "/" + name;
            WriteFile(filename, content, true);
        }

        public static void WriteFileInPersistent(string name, string content)
        {
            string filename = Application.persistentDataPath + "/" + name;
            WriteFile(filename, content, true);
        }

        public static void WriteFileInPersistent(string name, string content, bool bEncrypt)
        {
            string filename = Application.persistentDataPath + "/" + name;
            WriteFile(filename, content, bEncrypt);
        }

        public static void WriteFile(string filePath, string content, bool bEncrypt)
        {
            WriteFile(filePath, encoding.GetBytes(content), bEncrypt);
        }

        public static void WriteFile(string filePath, byte[] content, bool bEncrypt)
        {

            string filename = filePath;
            FileStream file = null;

            CreateFolderForFile(filename);
            try
            {

                if (File.Exists(filePath))
                {
                    file = new FileStream(filePath, FileMode.Truncate, FileAccess.ReadWrite);
                }
                else
                {
                    file = new FileStream(filePath, FileMode.Create, FileAccess.Write);
                }

                if (bEncrypt && isEncrypt)
                {
                    Encrypt(ref content);
                }

                file.Write(content, 0, content.Length);

                file.Close();
            }
            catch (Exception e)
            {
                Debug.Log("Save" + filename + " error : " + e.ToString());
                file.Close();
            }

        }

        public static FileStream WriteFileReturnFile(string filePath)
        {

            string filename = filePath;
            FileStream file = null;

            CreateFolderForFile(filename);
            if (File.Exists(filePath))
            {
                file = new FileStream(filePath, FileMode.Truncate, FileAccess.ReadWrite);
            }
            else
            {
                file = new FileStream(filePath, FileMode.Create, FileAccess.Write);
            }

            return file;
        }

        public static void ReadFileInPersistent(string name, ref string content, bool bDescrypt)
        {
            ReadFile(string.Format("{0}/{1}", Application.persistentDataPath, name), ref content, bDescrypt);
        }

        public static void ReadFileInPersistent(string name, ref string content)
        {
            ReadFile(string.Format("{0}/{1}", Application.persistentDataPath, name), ref content, true);
        }

        public static void ReadFile(string filePath, ref string content, bool bDescrypt)
        {
            byte[] bytes = null;
            ReadFile(filePath, ref bytes, bDescrypt);
            if (bytes == null || bytes.Length == 0)
            {
                content = null;
            }
            else
            {
                content = encoding.GetString(bytes);
            }
        }

        public static void ReadFile(string filePath, ref string content)
        {
            ReadFile(filePath, ref content, true);
        }

        public static void ReadFile(string filePath, ref byte[] content, bool bDecrypt)
        {
            string filename = filePath;
            if (!File.Exists(filename))
            {
                return;
            }

            try
            {
                FileStream file = new FileStream(filename, FileMode.Open);

                byte[] bytes = new byte[file.Length];
                file.Read(bytes, 0, bytes.Length);
                file.Close();

                if (bDecrypt && isEncrypt)
                {
                    Decrypt(ref bytes);
                }

                content = bytes;
            }
            catch (Exception e)
            {
                Debug.Log("Load" + filename + " error : " + e.ToString());
            }
        }

        public static void ReadFile(string filePath, ref byte[] content)
        {
            ReadFile(filePath, ref content, true);
        }

        public static string ReadString(string fullpath, bool bDescrypt)
        {
            byte[] bytes = ReadBytes(fullpath, bDescrypt);
            if (bytes == null)
                return null;
            return encoding.GetString(bytes);
        }

        public static string ReadString(string fullpath)
        {
            return ReadString(fullpath, true);
        }

        public static string ReadStringFromBytes(byte[] bytes, bool bDescrypt)
        {
            if (bytes == null)
                return null;
            if (bDescrypt && isEncrypt)
            {
                Decrypt(ref bytes);
            }
            return encoding.GetString(bytes);
        }


        public static string ReadStringFromBytes(byte[] bytes)
        {
            return ReadStringFromBytes(bytes, true);
        }

        public static byte[] ReadBytes(string fullpath, bool bDescrypt)
        {
            string filename = fullpath;
            FileStream file = null;
            if (!File.Exists(filename))
            {
                Debug.LogWarning("path not exit: " + fullpath);
                return null;
            }
            try
            {
                file = new FileStream(filename, FileMode.Open, FileAccess.Read);

                byte[] bytes = new byte[file.Length];
                file.Read(bytes, 0, bytes.Length);
                file.Close();

                if (bDescrypt && isEncrypt)
                {
                    Decrypt(ref bytes);
                }

                return bytes;
            }
            catch (Exception e)
            {
                Debug.LogError("Load" + filename + " error" + e.ToString());
            }
            finally
            {
                file.Close();
            }
            return null;
        }

        public static byte[] ReadBytes(string fullpath)
        {
            return ReadBytes(fullpath, true);
        }



        public static byte[] ReadBytesFromStreaming(string fileName)
        {
            return ReadBytesFromStreaming(fileName, true);
        }

        public static byte[] ReadBytesFromStreaming(string fileName, bool bDescrypt)
        {
#if UNITY_EDITOR || UNITY_STANDALONE_WIN
            string filePath = FileUtils.StreamingPath() + "/" + fileName;
            return ReadBytes(filePath, bDescrypt);
#elif UNITY_IOS
		string filePath = FileUtils.StreamingPath() + "/" + fileName;
		Debug.Log(filePath);
		return ReadBytes(filePath,bDescrypt);
#elif UNITY_ANDROID
         if (bDescrypt && isEncrypt)
        {
            byte[] bytes = AndroidHelper.GetBytesFromAsset(fileName);
            Decrypt(ref bytes);
            return bytes;
        }
        else
        {
            return AndroidHelper.GetBytesFromAsset(fileName);
        }     
#endif
        }

        public static string ReadStringFromStreaming(string fileName)
        {
            return ReadStringFromStreaming(fileName, true);
        }

        public static string ReadStringFromStreaming(string fileName, bool bDescrypt)
        {
#if UNITY_EDITOR || UNITY_STANDALONE_WIN
            string filePath = FileUtils.StreamingPath() + "/" + fileName;
            return ReadString(filePath, bDescrypt);
#elif UNITY_IOS
		string filePath = FileUtils.StreamingPath() + "/" + fileName;
		return ReadString(filePath,bDescrypt);
#elif UNITY_ANDROID
       if (bDescrypt && isEncrypt)
        {
            return ReadStringFromBytes(AndroidHelper.GetBytesFromAsset(fileName),bDescrypt);
        }
        else
        {
            return AndroidHelper.GetStringFromAsset(fileName);
        }         
#endif
        }


        public static bool Download(WWW www)
        {

            while (!www.isDone)
            {
                if (!string.IsNullOrEmpty(www.error))
                {
                    Debug.LogError(www.error);
                    return false;
                }

                if (Application.internetReachability == NetworkReachability.NotReachable)
                {
                    return false;
                }
            }
            return true;

            // return false;
        }

        public static IEnumerator Download(WWW www, System.Action<WWW> callback)
        {
            yield return www;

            if (!string.IsNullOrEmpty(www.error))
            {
                Debug.LogError(www.error);
            }
            else
            {
                if (callback != null) callback(www);
            }
        }


        public static byte[] LoadBytesFromUrl(string path, bool encryt = true)
        {
            string urlForFile = string.Format("{0}/{1}/{2}/{3}", url, ResSetting.GetChannelRes(), Version.LoadResVersion(), path)
                + "?time=" + System.DateTime.Now.Ticks + "&r=" + UnityEngine.Random.Range(int.MinValue, int.MaxValue);

#if UNITY_EDITOR
            Debug.LogError("LoadBytesFromUrl -> " + urlForFile);
#endif

            WWW www = new WWW(urlForFile);
            if (Download(www))
            {
                if (!encryt)
                    return www.bytes;
                else
                {
                    var bytes = www.bytes;
                    Decrypt(ref bytes);
                    return www.bytes;
                }
            }
            return null;
        }

        public static string LoadStringFromUrl(string path, bool encryt = true)
        {
            string urlForFile = string.Format("{0}/{1}/{2}/{3}", url, ResSetting.GetChannelRes(), Version.LoadResVersion(), path)
                 + "?time=" + System.DateTime.Now.Ticks + "&r=" + UnityEngine.Random.Range(int.MinValue, int.MaxValue);

#if UNITY_EDITOR
            Debug.LogError("LoadStringFromUrl -> " + urlForFile);
#endif
            WWW www = new WWW(urlForFile);
            if (Download(www))
            {
                if (!encryt)
                    return www.text;
                else
                    return Decrypt(www.text);
            }
            return null;
        }

        public static void DownloadFromUrl(string path)
        {
            string urlPath = string.Format("{0}/{1}/{2}/{3}", url, ResSetting.GetChannelRes(), Version.LoadResVersion(), path)
                + "?time=" + System.DateTime.Now.Ticks + "&r=" + UnityEngine.Random.Range(int.MinValue, int.MaxValue);
            string persistentPath = string.Format("{0}/{1}", Application.persistentDataPath, path);

#if UNITY_EDITOR
            Debug.LogError("DownloadFromUrl -> " + urlPath);
#endif
            CreateFolderForFile(persistentPath);

            WWW www = new WWW(urlPath);
            if (Download(www))
            {
                //下载的什么写什么，不用加解密
                WriteFileInPersistent(path, www.bytes, false);
            }
            else
            {
                return;
            }
        }



#if UNITY_EDITOR
        public static byte[] LoadBytesFromFileSystem(string path, bool isEncrypt)
        {
            //缓存目录
            string fullPathInPersistent = string.Format("{0}/{1}", Application.persistentDataPath, path);
            if (File.Exists(fullPathInPersistent))
            {
                byte[] content = null;
                ReadFile(fullPathInPersistent, ref content, isEncrypt);
                //Util.Log("缓存目录加载文件 : " + path);
                return content;

            }

            //流媒体目录
            string streamingPath = string.Format("{0}/{1}", Application.streamingAssetsPath, path);
            if (File.Exists(streamingPath))
            {
                byte[] content = null;
                content = ReadBytes(streamingPath, isEncrypt);
                //Util.Log("流媒体目录加载文件 : " + path);
                return content;
            }

            return null;
        }

#elif UNITY_ANDROID
    public static byte[] LoadBytesFromFileSystem(string path, bool isEncrypt)
    { 
        if (AndroidHelper.Exits(path))
        {
            byte[] content = null;
            content = ReadBytesFromStreaming(path, isEncrypt);             
            return content;            
        }
        return null;
    }
#else

    public static byte[] LoadBytesFromFileSystem(string path, bool isEncrypt)
    {

        //只检测字节的长度
        bool ret = false;
        //缓存目录
        string fullPathInPersistent = string.Format("{0}/{1}", Application.persistentDataPath, path);
        if (File.Exists(fullPathInPersistent))
        {
            byte[] content = null;
            ReadFile(fullPathInPersistent, ref content, isEncrypt);
            return content;
          
        }

        //流媒体目录
        string streamingPath = string.Format("{0}/{1}", Application.streamingAssetsPath, path);
        if (File.Exists(streamingPath))
        {
            byte[] content = null;
            content = ReadBytes(streamingPath, isEncrypt);
            if (cdnFileInfos.Count == 0 || (cdnFileInfos.ContainsKey(path) && content.Length == cdnFileInfos[path].length)) ret = true;
            if (true)
            {           
                return content;
            }
        }


        //以上目录读取失败则读CDN目录
        if (ret == false)
        {
            DownloadFromUrl(path);
            if (File.Exists(fullPathInPersistent))
            {
                byte[] content = null;
                ReadFile(fullPathInPersistent, ref content, isEncrypt);
                return content;
            }
        }


        Debug.LogError("致命错误 ==> 加载文件失败 : " + path);
        return null;
    }

#endif


        public static string LoadStringFromFileSystem(string path, bool isEncrypt)
        {

            byte[] content = LoadBytesFromFileSystem(path, isEncrypt);
            //上面的函数已经解密无需再做多余操作
            return ReadStringFromBytes(content, false);
        }

        public static byte[] LoadBytesFromFileSystem(string path)
        {
            return LoadBytesFromFileSystem(path, true);
        }

        public static string LoadStringFromFileSystem(string path)
        {
            return LoadStringFromFileSystem(path, true);
        }
    }
}
