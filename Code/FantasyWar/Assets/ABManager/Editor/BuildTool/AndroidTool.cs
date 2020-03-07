using UnityEngine;
using UnityEditor;
using System.Collections;
using System.IO;
using System.Threading;

namespace SuperBoBo
{
    public class AndroidTool
    {
        public static string keystoreFilePath = "config/keystore.txt";

        const string fullApkIdentify = "fullApkIdentify";


        public static void BuildAndroidProject(Version v)
        {

            string apkPath = string.Format("{0}/{1}", ResSetting.AssetBundlesOutputPath, ResSetting.GetChannelRes());
            string location = string.Format("{0}/{1}.Project", apkPath, v);


            FileUtilTool.CreateFolderForFile(location);
            string[] levels = new string[] { BuildTool.startScene };
            try
            {
                EditorUserBuildSettings.exportAsGoogleAndroidProject = true;


                if (BuildTool.isDev)
                {
                    var result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.ConnectWithProfiler | BuildOptions.Development);
                }
                else
                {
                    var result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.None);
                }

                if (BuildTool.isDev)
                {
                    var result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.ConnectWithProfiler | BuildOptions.Development | BuildOptions.AcceptExternalModificationsToPlayer);
                }
                {
                    UnityEditor.PlayerSettings.bundleVersion = v.ToString();
                    var result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.AcceptExternalModificationsToPlayer);
                }
            }
            catch (System.Exception e)
            {
                Debug.LogError("build android error： " + e.ToString());
                throw new System.Exception(e.ToString());
            }
        }

        public static void BuildApk(Version v, string location)
        {

            //隐藏Resources目录
            BuildTool.ShowResourcesFolder(false);

            string content = FileUtilTool.ReadFile(keystoreFilePath);
            if (!string.IsNullOrEmpty(content))
            {
                string[] lines = content.Replace("\r\n", "\n").Split('\n');


                PlayerSettings.Android.keystoreName = lines[0].Trim();
                PlayerSettings.Android.keystorePass = lines[1].Trim();
                PlayerSettings.Android.keyaliasName = lines[2].Trim();
                PlayerSettings.Android.keyaliasPass = lines[3].Trim();

                Debug.LogError("PlayerSettings.Android.keystoreName " + PlayerSettings.Android.keystoreName);
                Debug.LogError("PlayerSettings.Android.keystorePass " + PlayerSettings.Android.keystorePass);
                Debug.LogError("PlayerSettings.Android.keyaliasName " + PlayerSettings.Android.keyaliasName);
                Debug.LogError("PlayerSettings.Android.keyaliasPass " + PlayerSettings.Android.keyaliasPass);
            }

            FileUtilTool.CreateFolderForFile(location);
            string[] levels = new string[] { BuildTool.startScene };
            try
            {
                if (BuildTool.type == BuildTool.BuildType.APK)
                {

                    if (BuildTool.isDev)
                    {
                        var result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.ConnectWithProfiler | BuildOptions.Development);
                    }
                    else
                    {
                        var result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.None);
                    }
                }
                else
                {
                    if (BuildTool.isDev)
                    {
                        var result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.ConnectWithProfiler | BuildOptions.Development | BuildOptions.AcceptExternalModificationsToPlayer);
                    }
                    else
                    {
                        var result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.AcceptExternalModificationsToPlayer);
                    }
                }
            }
            catch (System.Exception e)
            {
                Debug.LogError("build android error： " + e.ToString());
            }
            finally
            {
                //显示Resources目录
                BuildTool.ShowResourcesFolder(true);
            }


        }


        [MenuItem("Package/安卓/生成本地资源")]
        public static void BuildAndroidRes()
        {
            BuildTool.SwitchActiveBuildTarget(BuildTarget.Android);
            ResTool.BuildLocalRes();

        }


        [MenuItem("Package/安卓/安卓完整包--不重新打资源")]
        public static void BuildApkNoGenRes()
        {

            Version v = BuildTool.versionRes;

            FileUtilTool.DeleteFolder("Assets/StreamingAssets/");

            //写入Version文件和写入fullApkIdentify文件
            Version.SaveVersion2StreamingAsset(v);

            //写入配置信息
            //WriteApkConfig();

            //拷贝除apk以外的资源
            ResTool.CopyResToStreaming();


            AssetDatabase.Refresh();
            AssetDatabase.SaveAssets();

            //打包
            string apkPath = string.Format("{0}/{1}", ResSetting.AssetBundlesOutputPath, ResSetting.GetChannelRes());
            string location = "";
            if (BuildTool.type == BuildTool.BuildType.APK)
            {
                location = string.Format("{0}/{4}/TankGirl{1}({2}).res{3}.apk", apkPath, PlayerSettings.bundleVersion, PlayerSettings.Android.bundleVersionCode, v,
                    string.Format("{0:yyyyMMddHHmm}", System.DateTime.Now));
            }
            else
            {
                location = string.Format("{0}/TankGirl_AndroidProject/", apkPath);

                string path = location.Replace(@"\", "/");
                if (path.Contains("/"))
                {
                    string dir = path.Substring(0, path.LastIndexOf("/"));
                    DeleteADirectory(dir);
                }
            }

            BuildApk(v, location);


            AssetDatabase.Refresh();
            AssetDatabase.SaveAssets();
        }

        public static bool DeleteADirectory(string strPath)
        {
            string[] strTemp;
            try
            {
                // Delete the files in the directory
                strTemp = System.IO.Directory.GetFiles(strPath);
                foreach (string str in strTemp)
                {
                    System.IO.File.Delete(str);
                }
                // Delete subdirectories, recursive
                strTemp = System.IO.Directory.GetDirectories(strPath);
                foreach (string str in strTemp)
                {
                    DeleteADirectory(str);
                }
                // Delete the directory
                System.IO.Directory.Delete(strPath);
                return true;
            }
            catch (System.Exception ex)
            {
                return false;
            }
        }


        [MenuItem("Package/安卓/安卓最小包--不重新打资源")]
        public static void BuildApkMiniNoGenRes()
        {
            Version v = Version.LoadVersionFromStreamingAsset();

            byte[] bytes = FileUtils.ReadBytesFromStreaming("Audio/GeneratedSoundBanks/Android/Init.bnk", false);

            FileUtilTool.DeleteFolder("Assets/StreamingAssets/");

            //写入Version文件和写入fullApkIdentify文件
            Version.SaveVersion2StreamingAsset(v);

            //写入配置信息
            //WriteApkConfig();

            //写入其他文件
            FileUtils.WriteFile(Application.streamingAssetsPath + "/Audio/GeneratedSoundBanks/Android/Init.bnk", bytes, false);
            string movePath = string.Format("{0}/{1}", ResSetting.build_root_path, v);
            FileUtilTool.CopyFolder(movePath + "/Movie", "Assets/StreamingAssets/Movie");


            AssetDatabase.Refresh();
            AssetDatabase.SaveAssets();

            string outputPath = string.Format("{0}/{1}/{2}", ResSetting.AssetBundlesOutputPath, ResSetting.GetChannelRes(), v);
            string location = string.Format("{0}/{1}", outputPath, "TankGirl.apk");
            BuildApk(v, location);


            AssetDatabase.Refresh();
            AssetDatabase.SaveAssets();
        }


        /// <summary>
        /// 这个接口外部脚本会调用
        /// </summary>
        [MenuItem("Package/安卓/安卓完整包")]
        public static void BuildApkGenRes()
        {

            BuildAndroidRes();
            BuildApkNoGenRes();
        }

    }
}
