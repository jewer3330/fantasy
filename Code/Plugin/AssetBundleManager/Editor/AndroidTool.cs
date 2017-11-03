using UnityEngine;
using UnityEditor;
using System.Collections;
using System.IO;
using System.Threading;

public class AndroidTool
{
    const string fullApkIdentify = "fullApkIdentify";

    public static void ShowResourcesFolder(bool b)
    {
        if (b)
        {
            if (Directory.Exists("Assets/Resources"))
            {
                Debug.LogError("存在目录Assets/Resources");
                AssetDatabase.SaveAssets();
                AssetDatabase.Refresh();
                throw new System.Exception("已经存在目录Assets/Resources，build失败");
            }

            Debug.Log(AssetDatabase.MoveAsset("Assets/ResourceTemp", "Assets/Resources"));
        }
        else
        {
            if (Directory.Exists("Assets/ResourceTemp"))
            {
                Debug.LogError("存在目录Assets/ResourceTemp");
                AssetDatabase.SaveAssets();
                AssetDatabase.Refresh();
                throw new System.Exception("已经存在目录Assets/ResourceTemp，是否上次build失败？请删除这个目录，并用svn更新");


            }
            Debug.Log(AssetDatabase.MoveAsset("Assets/Resources", "Assets/ResourceTemp"));
        }
    }

    [MenuItem("Tools/导出场景信息")]
    public static void ExportScene()
    {
        string[] scenes = MarkTool.GetSceneArray();
        string content = string.Join("\n", scenes);
        FileUtilTool.WriteFile("scenes.txt", content);
    }

    [MenuItem("Tools/打包/测试编译")]

    public static void RefreshAndWaitForCompile()
    {

        AssetDatabase.ImportAsset("Assets/Plugins/Android", ImportAssetOptions.ForceUpdate | ImportAssetOptions.ImportRecursive);
        AssetDatabase.ImportAsset("Assets/Scripts", ImportAssetOptions.ForceUpdate | ImportAssetOptions.ImportRecursive);
        AssetDatabase.ImportAsset("ProjectSettings", ImportAssetOptions.ForceUpdate | ImportAssetOptions.ImportRecursive);

        AssetDatabase.Refresh(ImportAssetOptions.ForceSynchronousImport);
        AssetDatabase.SaveAssets();
        EditorApplication.update += WaitCompile;


    }

    public static void WaitCompile()
    {
        if (!EditorApplication.isCompiling)
        {
            Debug.Log("编译结束");
            EditorApplication.update -= WaitCompile;

        }
    }

    public static string keystoreFilePath = "keystore.txt";


    public static void BuildAndroidProject(Version v)
    {

        string apkPath = string.Format("{0}/{1}", ResSetting.AssetBundlesOutputPath, ResSetting.GetChannelRes());
        string location = string.Format("{0}/{1}.Project", apkPath, v);





        //PlayerSettings.Android.keystoreName = "tankgirl";
        //PlayerSettings.Android.keystorePass = "O4ep2irA@Ule@X10";
        //PlayerSettings.Android.keyaliasName = "tankgirl";
        //PlayerSettings.Android.keyaliasPass = "O4ep2irA@Ule@X10";

        //Debug.LogError("PlayerSettings.Android.keystoreName " + PlayerSettings.Android.keystoreName);
        //Debug.LogError("PlayerSettings.Android.keystorePass " + PlayerSettings.Android.keystorePass);
        //Debug.LogError("PlayerSettings.Android.keyaliasName " + PlayerSettings.Android.keyaliasName);
        //Debug.LogError("PlayerSettings.Android.keyaliasPass " + PlayerSettings.Android.keyaliasPass);


        FileUtilTool.CreateFolderForFile(location);
        string[] levels = new string[] { "Assets/Scenes/Launcher.unity" };
        try
        {
            EditorUserBuildSettings.exportAsGoogleAndroidProject = true;


            if (AndroidOneKeyTool.isDev)
            {
                string result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.ConnectWithProfiler | BuildOptions.Development);
            }
            else
            {
                string result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.None);
            }

            if (AndroidOneKeyTool.isDev)
            {
                string result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.ConnectWithProfiler | BuildOptions.Development | BuildOptions.AcceptExternalModificationsToPlayer);
            }
            {
                UnityEditor.PlayerSettings.bundleVersion = v.ToString();
                string result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.AcceptExternalModificationsToPlayer);
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
        ShowResourcesFolder(false);

        string content = FileUtilTool.ReadFile(keystoreFilePath);
        string[] lines = content.Replace("\r\n", "\n").Split('\n');


        //PlayerSettings.Android.keystoreName = lines[0].Trim();
        //PlayerSettings.Android.keystorePass = "O4ep2irA@Ule@X10";
        //PlayerSettings.Android.keyaliasName = "tankgirl";
        //PlayerSettings.Android.keyaliasPass = "O4ep2irA@Ule@X10";

        //Debug.LogError("PlayerSettings.Android.keystoreName " + PlayerSettings.Android.keystoreName);
        //Debug.LogError("PlayerSettings.Android.keystorePass " + PlayerSettings.Android.keystorePass);
        //Debug.LogError("PlayerSettings.Android.keyaliasName " + PlayerSettings.Android.keyaliasName);
        //Debug.LogError("PlayerSettings.Android.keyaliasPass " + PlayerSettings.Android.keyaliasPass);


        FileUtilTool.CreateFolderForFile(location);
        string[] levels = new string[] { "Assets/Scenes/Launcher.unity" };
        try
        {
            if (AndroidOneKeyTool.type == AndroidOneKeyTool.Build.APK)
            {

                if (AndroidOneKeyTool.isDev)
                {
                    string result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.ConnectWithProfiler | BuildOptions.Development);
                }
                else
                {
                    string result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.None);
                }
            }
            else
            {
                if (AndroidOneKeyTool.isDev)
                {
                    string result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.ConnectWithProfiler | BuildOptions.Development | BuildOptions.AcceptExternalModificationsToPlayer);
                }
                else
                {
                    string result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.Android, BuildOptions.AcceptExternalModificationsToPlayer);
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
            ShowResourcesFolder(true);
        }


    }


    [MenuItem("Tools/打包/安卓/生成本地资源")]
    public static void BuildAndroidRes()
    {
        SwitchActiveBuildTarget(BuildTarget.Android);
        ResTool.BuildLocalRes();

    }

    [MenuItem("Tools/打包/安卓/默认配置信息")]
    public static void WriteApkConfig()
    {
        FileUtils.WriteFile(Application.streamingAssetsPath + "/" + fullApkIdentify, "false", false);
 //       FileUtils.WriteFile(Application.streamingAssetsPath + "/channel.dat", "0", false);
//        FileUtils.WriteFile(Application.streamingAssetsPath + "/url.dat",
//            @"http://zjlmcdn.joygame.cn/zjlm/close_beta
//http://zjlmdl.joygame.cn/zjlm/close_beta", false);
    }

    [MenuItem("Tools/打包/安卓/安卓完整包--不重新打资源")]
    public static void BuildApkNoGenRes()
    {

        Version v = AndroidOneKeyTool.versionRes;

        FileUtilTool.DeleteFolder("Assets/StreamingAssets/");

        //写入Version文件和写入fullApkIdentify文件
        Version.SaveVersion2StreamingAsset(v);

        //写入配置信息
        WriteApkConfig();

        //拷贝除apk以外的资源
        ResTool.CopyResToStreaming();


        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();

        //打包
        string apkPath = string.Format("{0}/{1}", ResSetting.AssetBundlesOutputPath, ResSetting.GetChannelRes());
        string location = "";
        if (AndroidOneKeyTool.type == AndroidOneKeyTool.Build.APK)
        {
            location = string.Format("{0}/{4}/TankGirl{1}({2}).res{3}.apk", apkPath, PlayerSettings.bundleVersion, PlayerSettings.Android.bundleVersionCode, v, System.DateTime.Now.ToString("yyyyMMddhhmmss"));
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


    [MenuItem("Tools/打包/安卓/安卓最小包--不重新打资源")]
    public static void BuildApkMiniNoGenRes()
    {
        Version v = Version.LoadVersionFromStreamingAsset();

        byte[] bytes = FileUtils.ReadBytesFromStreaming("Audio/GeneratedSoundBanks/Android/Init.bnk", false);

        FileUtilTool.DeleteFolder("Assets/StreamingAssets/");

        //写入Version文件和写入fullApkIdentify文件
        Version.SaveVersion2StreamingAsset(v);

        //写入配置信息
        WriteApkConfig();

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

    [MenuItem("Tools/生成apk.info文件")]
    public static void SaveApkSizeInfo()
    {
        string location = EditorUtility.OpenFilePanel("打开位置", Application.dataPath, "apk");

        string content = "";
        FileInfo info = new FileInfo(location);
        float size = (float)info.Length / (1 << 20);
        content += size.ToString() + "\n";
        content += ResCommon.GetFileMD5(location);

        string outputPath = EditorUtility.SaveFilePanel("保存位置", Application.dataPath, "apk", "info");
        FileUtilTool.WriteFile(outputPath, content);
    }

    public static void SaveApkSizeInfo(string location, string outputPath)
    {
        string content = "";
        FileInfo info = new FileInfo(location);
        float size = (float)info.Length / (1 << 20);
        content += size.ToString() + "\n";
        content += ResCommon.GetFileMD5(location);
        FileUtilTool.WriteFile(outputPath + "/apk.info", content);

        string sourcePath = outputPath + "/apk.info";
        string targetPath = string.Format("\\\\192.168.2.85\\FtpData\\{0}\\{1}\\{2}", ResSetting.GetChannelRes(), Version.LoadVersionFromStreamingAsset(), "apk.info");
        EditorUtility.DisplayProgressBar("上传apk.info", "...", 0);
        FileUtilTool.CopyFile(sourcePath, targetPath);
        EditorUtility.DisplayProgressBar("上传apk.info", "...", 1);
        EditorUtility.ClearProgressBar();
    }


    [MenuItem("Tools/打包/安卓/安卓完整包--不重新打资源--自动上传资源")]
    public static void BuildApkNoGenResUploadRes()
    {
        BuildApkNoGenRes();
        ResTool.UploadRes();
        AndroidTool.UploadAPK();
        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();
    }

    /// <summary>
    /// 这个接口外部脚本调用
    /// </summary>
    [MenuItem("Tools/打包/安卓/安卓完整包--不重新打资源--上传APK")]

    public static void BuildApkNoGenResUploadApk()
    {
        Debug.Log(AndroidOneKeyTool.versionName);
        Debug.Log(AndroidOneKeyTool.versionRes);
        Debug.Log(AndroidOneKeyTool.versionCode);
        BuildApkNoGenRes();
        ResTool.UploadRes();
        AndroidTool.UploadAPK();
        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();
    }

    /// <summary>
    /// 这个接口外部脚本会调用
    /// </summary>
    [MenuItem("Tools/打包/安卓/安卓完整包")]
    public static void BuildApkGenRes()
    {

        BuildAndroidRes();
        BuildApkNoGenResUploadRes();
    }


    [MenuItem("Tools/打包/安卓/上传APK")]
    public static void UploadAPK()
    {
        try
        {
            string apkPath = string.Format("{0}/{1}", ResSetting.AssetBundlesOutputPath, ResSetting.GetChannelRes());
            string sourcePath = string.Format("{0}/TankGirl{1}({2}).res{3}.apk", apkPath, PlayerSettings.bundleVersion, PlayerSettings.Android.bundleVersionCode, Version.LoadVersionFromStreamingAsset());
            string targetPath = string.Format("F:/nginx-1.10.3/html/tankwar/{0}/TankGirl_{1}_{2}({3}).res{4}_full.apk",
                ResSetting.GetChannelRes(),
                ResSetting.channelResName + "_" + "release",
                PlayerSettings.bundleVersion,
                PlayerSettings.Android.bundleVersionCode,
                Version.LoadVersionFromStreamingAsset());

            FileUtilTool.CopyFile(sourcePath, targetPath);
        }
        catch (System.Exception e)
        {
            Debug.LogError(e);
        }
    }

    public static void SwitchActiveBuildTarget(BuildTarget target)
    {
        EditorUserBuildSettings.SwitchActiveBuildTarget(target);
    }



}
