using UnityEngine;
using System.Collections;
using UnityEditor;
using System.IO;
using System.Collections.Generic;
using LitJson;
namespace SuperBoBo
{
    public class ResTool
    {

        public static bool m_bCompress = false;

        public static string[] keyNotEncryt = new string[]
        {
        "version.dat",
        ".apk",
        "MD.dat",
        "MD2.dat",
        "fullApkIdentify",
        "GeneratedSoundBanks",
        "logo.mp4",
        "update.txt",
        "apk.info",
        "channel.dat",
        "url.dat",
        "channel_res.dat",
        "ResVoice.dat",
        "Movie",
        "appleversion.dat",
        };

        public static string[] keyNotInclude = new string[]
        {
         "MD.dat" ,
         "MD2.dat" ,
         "TankGirl.apk" ,
         "fullApkIdentify",
         "apk.info",
         "channel.dat",
         "url.dat",
         "channel_res.dat",
        };

        public static string[] keyNotZip = new string[]
        {
         "MD.dat" ,
         "MD2.dat" ,
         "TankGirl.apk" ,
         "fullApkIdentify",
         "apk.info",
        };

        /// <summary>
        /// lastRes/[Version]/MD.dat
        /// </summary>
        static string mdFile
        {
            get
            {
                return ResSetting.build_res_path + "/MD.dat";
            }
        }

        /// <summary>
        /// lastRes/[Platform]/[Version]
        /// </summary>
        static string resFolder
        {
            get
            {
                return ResSetting.build_res_path;
            }
        }


        [MenuItem("Package/测试/压缩资源包", false, 7)]
        public static void CompressAssetBundle()
        {
            if (ResTool.m_bCompress)
            {
                //ResTool.CompressFolder(ResSetting.AssetBundlesPath());
            }
        }

        public static void CompressFolder(string folder)
        {
            string[] arrFile = Directory.GetFiles(folder);
            for (int i = 0; i < arrFile.Length; i++)
            {
                string file = arrFile[i];
                //ResSetting.Compress(file, string.Format("{0}.{1}", file, "lzma"));
                FileUtilTool.DelFile(file);
            }

            foreach (string d in Directory.GetDirectories(folder))
            {
                CompressFolder(d);
            }
        }

        [MenuItem("Package/测试/删除上次生成的文件 and 拷贝流媒体到版本资源目录", false, 9)]
        public static void CopyStreamingToRes()
        {

            FileUtilTool.DeleteFolder("Assets/StreamingAssets/assetbundles");
            FileUtilTool.DelFile("Assets/StreamingAssets/assetrecord.dat");
            FileUtilTool.DelFile("Assets/StreamingAssets/MD.dat");
            FileUtilTool.DelFile("Assets/StreamingAssets/MD2.dat");
            FileUtilTool.DelFile("Assets/StreamingAssets/fullApkIdentify");

            FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/Windows");
            FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/Android");
            FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/Android_Original");
            FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/iOS");
            FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/iOS_Original");
            //        #if UNITY_ANDROID
            ////		FileUtilTool.CopyFolder("WwiseProjects/OutPath/Android_Original", "Assets/StreamingAssets/Audio/GeneratedSoundBanks/Android_Original");
            //        FileUtilTool.CopyFolder("WwiseProjects/OutPath/Android", "Assets/StreamingAssets/Audio/GeneratedSoundBanks/Android");
            //        #elif UNITY_IOS
            ////		FileUtilTool.CopyFolder("WwiseProjects/OutPath/iOS_Original", "Assets/StreamingAssets/Audio/GeneratedSoundBanks/iOS_Original");
            //        FileUtilTool.CopyFolder("WwiseProjects/OutPath/iOS", "Assets/StreamingAssets/Audio/GeneratedSoundBanks/iOS");
            //        #endif

            //#if UNITY_ANDROID
            //		FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/Android");
            //		FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/iOS_Original");
            //		FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/iOS");
            //		FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/Windows");
            //#elif UNITY_IOS
            //        FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/Windows");
            //        FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/Android");
            //		FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/iOS");
            //		FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/Android_Original");
            //#else
            //		FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/Android_Original");
            //        FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/Android");
            //		FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/iOS");
            //		FileUtilTool.DeleteFolder("Assets/StreamingAssets/Audio/GeneratedSoundBanks/iOS_Original");
            //#endif

            FileUtilTool.CopyFolder(FileUtils.StreamingPath(), ResSetting.build_res_path);
            FileUtilTool.CopyFolder(ResSetting.build_ab_path, ResSetting.build_res_path + "/assetbundles");
            BuildAssetBundleTool.DeleteMainfestFile(ResSetting.build_res_path);
            ClearFileWithExtension(ResSetting.build_res_path, ".meta");

            //加密资源
            ResTool.GenEncrypt();
            ResTool.GenMD5();
            ResTool.GenMD5Second();
        }

        /// <summary>
        /// 递归清除特定文件
        /// </summary>
        /// <param name="dir"></param>
        /// <param name="extension"></param>
        public static void ClearFileWithExtension(string dir, string extension)
        {
            string[] arrFile = Directory.GetFiles(dir);
            for (int i = 0; i < arrFile.Length; i++)
            {
                string file = arrFile[i];
                if (Path.GetExtension(file) == extension)
                {
                    File.Delete(file);
                }
            }

            foreach (string d in Directory.GetDirectories(dir))
            {
                ClearFileWithExtension(d, extension);
            }
        }


        [MenuItem("Package/测试/生成资源的MD5文件", false, 11)]
        //[MenuItem("Tools/程序狗专用/Res/MD5")]
        public static void GenMD5()
        {
            FileUtilTool.DelFile(mdFile);
            string fresfolder = resFolder.Replace("\\", "/");
            List<AssetbundleJsonData> data = GetMD5ForFolder(resFolder, fresfolder);
            AssetbundleJsonMap map = new AssetbundleJsonMap();
            map.arrayRes = data.ToArray();
            string jsonStr = JsonMapper.ToJson(map);

            FileUtilTool.WriteFile(mdFile, jsonStr);
        }


        public static List<AssetbundleJsonData> GetMD5ForFolder(string folder, string relative)
        {
            List<AssetbundleJsonData> data = new List<AssetbundleJsonData>();
            string[] files = Directory.GetFiles(folder, "*", SearchOption.AllDirectories);

            EditorUtility.DisplayProgressBar("生成MD5", "...", 0);
            int i = 0;
            foreach (string file in files)
            {
                bool find = false;
                foreach (var k in keyNotInclude)
                {
                    if (Path.GetFileName(file) == k)
                    {
                        find = true;
                    }
                }
                if (find)
                    continue;

                string md5 = ResCommon.GetFileMD5(file);
                //Debug.Log("MD5 :" + file + ": " + resFolder);
                string ffile = file.Replace("\\", "/");

                string fileName = ffile.Replace(relative + "/", "");
                //Debug.Log("MD5 :" + fileName);

                FileInfo fileInfo = new FileInfo(file);

                AssetbundleJsonData jData = new AssetbundleJsonData(fileName, md5, fileInfo.Length);

                i++;
                EditorUtility.DisplayProgressBar("生成MD5", file, (float)i / (float)files.Length);
                data.Add(jData);
            }

            EditorUtility.ClearProgressBar();

            return data;
        }


        [MenuItem("Package/测试/生成MD5文件的MD5", false, 12)]
        public static void GenMD5Second()
        {
            string mdSecondFile = resFolder + "/MD2.dat";
            string fresfolder = resFolder.Replace("\\", "/");
            string jsonStr = "";
            if (File.Exists(mdSecondFile))
            {
                string data = FileUtilTool.ReadFile(mdSecondFile);
                MD2 md2 = JsonMapper.ToObject<MD2>(data);
                jsonStr = GetMD5SecondForFile(mdFile, fresfolder, md2.time);

            }
            else
            {

                jsonStr = GetMD5SecondForFile(mdFile, fresfolder);
            }
            FileUtilTool.DelFile(mdSecondFile);
            FileUtilTool.WriteFile(mdSecondFile, jsonStr);
        }


        public static void CopyResToStreaming()
        {
            //拷贝除apk以外的资源

            //FileUtilTool.DeleteFolder("Assets/StreamingAssets/");
            FileUtilTool.CopyFolder(ResSetting.build_res_path, "Assets/StreamingAssets/");

        }

        [System.Serializable]
        public class MD2
        {
            public string fileName = "";
            public string hashCode = "";
            public string time = "";
        }

        public static string GetMD5SecondForFile(string file, string relative)
        {
            string md5 = ResCommon.GetFileMD5(file);
            string fileName = file.Replace("\\", "/");
            fileName = fileName.Replace(relative + "/", "");
            MD2 md2 = new MD2();
            md2.fileName = fileName;
            md2.hashCode = md5;
            md2.time = System.DateTime.Now.ToString();
            return JsonMapper.ToJson(md2);
        }

        public static string GetMD5SecondForFile(string file, string relative, string time)
        {
            string md5 = ResCommon.GetFileMD5(file);
            string fileName = file.Replace("\\", "/");
            fileName = fileName.Replace(relative + "/", "");
            MD2 md2 = new MD2();
            md2.fileName = fileName;
            md2.hashCode = md5;
            md2.time = time.ToString();
            return JsonMapper.ToJson(md2);
        }

        [MenuItem("Package/测试/本地加密资源", false, 10)]
        public static void GenEncrypt()
        {
            string[] files = Directory.GetFiles(resFolder, "*", SearchOption.AllDirectories);

            int i = 0;
            foreach (var k in files)
            {
                i++;
                //if (k.Contains("version.dat") || k.Contains(".apk") || k.Contains("MD.dat") || k.Contains("MD2.dat") || k.Contains("fullApkIdentify"))
                //{
                //    continue;
                //}
                //if (k.Contains("GeneratedSoundBanks"))//跳过声音
                //{
                //    continue;
                //}
                //if (k.Contains("logo.mp4"))//跳过视频
                //{
                //    continue;
                //}
                //if (k.Contains("update.txt"))//跳过更新简介
                //{
                //    continue;
                //}
                bool flag = false;
                foreach (var v in keyNotEncryt)
                {
                    if (k.Contains(v))
                    {
                        flag = true;
                        break;
                    }

                }
                if (flag) continue;


                EncryptForFile(k);

                EditorUtility.DisplayProgressBar("加密中", k, (float)i / (float)files.Length);
            }
            EditorUtility.ClearProgressBar();
        }




        public static void EncryptForFile(string filePath)
        {
            if (FileUtils.isEncrypt)
            {
                byte[] data = FileUtilTool.ReadBytesOfFile(filePath);
                FileUtils.Encrypt(ref data);
                FileUtilTool.WriteBytesOfFile(filePath, data);
            }
        }

        [MenuItem("Package/测试/上传资源", false, 13)]
        public static void UploadRes()
        {
            string sourcePath = ResSetting.build_res_path;
            string targetPath = string.Format("\\\\192.168.2.85\\FtpData\\{0}\\{1}", ResSetting.GetChannelRes(), Version.LoadVersionFromStreamingAsset());
            EditorUtility.DisplayProgressBar("上传资源", "...", 0);
            FileUtilTool.CopyFolder(sourcePath, targetPath);
            EditorUtility.DisplayProgressBar("上传资源", "...", 1);
            EditorUtility.ClearProgressBar();

        }


        [MenuItem("Package/测试/本地解密资源", false, 14)]
        public static void GenDecrypt()
        {
            string[] files = Directory.GetFiles(resFolder, "*", SearchOption.AllDirectories);
            int i = 0;
            foreach (var k in files)
            {
                i++;
                //if (k.Contains("version.dat") || k.Contains(".apk") || k.Contains("MD.dat") || k.Contains("MD2.dat")||k.Contains("fullApkIdentify"))
                //{
                //    continue;
                //}
                //if (k.Contains("GeneratedSoundBanks"))//跳过声音
                //{
                //    continue;
                //}
                //if (k.Contains("logo.mp4"))//跳过视频
                //{
                //    continue;
                //}
                //if (k.Contains("update.txt"))//跳过更新简介
                //{
                //    continue;
                //}
                bool flag = false;
                foreach (var v in keyNotEncryt)
                {
                    if (k.Contains(v))
                    {
                        flag = true;
                        break;
                    }

                }
                if (flag) continue;

                DecryptForFile(k);
                EditorUtility.DisplayProgressBar("解密中", k, (float)i / (float)files.Length);
            }
            EditorUtility.ClearProgressBar();
        }



        public static void DecryptForFile(string filePath)
        {
            if (FileUtils.isEncrypt)
            {
                byte[] data = FileUtilTool.ReadBytesOfFile(filePath);
                FileUtils.Decrypt(ref data);
                FileUtilTool.WriteBytesOfFile(filePath, data);
            }
        }



        /// <summary>
        /// 生成本地资源不包括加密
        /// </summary>
        public static void BuildLocalRes()
        {
            try
            {

                BuildTool.buildLog.First();

                MarkTool.ClearMarkForce();

                BuildTool.buildLog.Next();

                MarkTool.GenRecord();

                BuildTool.buildLog.Next();

                MarkTool.MarkAutoFromRecord();

                BuildTool.buildLog.Next();

                BuildAssetBundleTool.BuildAssetBundles();

                BuildTool.buildLog.Next();

                MarkTool.ClearAutoFromRecord();

                BuildTool.buildLog.Next();

                //BuildAssetBundleTool.DeleteMainfestFile();

                BuildTool.buildLog.Next();

                ResTool.CompressAssetBundle();

                BuildTool.buildLog.Next();

                ResTool.CopyStreamingToRes();

                BuildTool.buildLog.End();
                BuildTool.SaveBuildLog(BuildTool.buildLog);


            }

            catch (System.Exception e)
            {
                BuildTool.buildLog.errorLog = e.ToString();
                BuildTool.SaveBuildLog(BuildTool.buildLog);
                Debug.LogError(e);
            }


        }




    }
}
