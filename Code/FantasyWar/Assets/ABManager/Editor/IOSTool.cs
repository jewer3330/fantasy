using UnityEngine;
using System.Collections;
using UnityEditor;
using System.IO;

public class IOSTool 
{

    const string fullApkIdentify = "fullApkIdentify";

    [MenuItem("Package/苹果/生成本地资源")]
    public static void BuildIOSRes()
    {
		//AndroidOneKeyTool.UpdateStreaming();
		FileUtilTool.CopyFile ("IOS_Build/appleversion.dat", Application.streamingAssetsPath + "/appleversion.dat");
        Version v = AndroidOneKeyTool.versionRes;
        //v.UpgradeLittleVersion();
        Version.SaveVersion2StreamingAsset(v);
        //AndroidOneKeyTool.CallShellCommandForVersionRes();        
        EditorUserBuildSettings.SwitchActiveBuildTarget(BuildTarget.iOS);
        ResTool.BuildLocalRes();
    }

    [MenuItem("Package/苹果/苹果完整包--重新打资源")]
    public static void BuildIOSFull()
    {
		
        BuildIOSRes();
        Version v = Version.LoadVersionFromStreamingAsset();
        
        FileUtilTool.DeleteFolder("Assets/StreamingAssets/");

        //写入Version文件和写入fullApkIdentify文件
        Version.SaveVersion2StreamingAsset(v);

        //写入配置信息
        WriteIOSConfig();

        //拷贝除apk以外的资源
        ResTool.CopyResToStreaming();

        BuildIOSProject(v);


        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();

        //上传资源
        //ResTool.UploadRes();
    }


    public static void WriteIOSConfig()
    {
        FileUtils.WriteFile(Application.streamingAssetsPath + "/" + fullApkIdentify, "true", false);
//        FileUtils.WriteFile(Application.streamingAssetsPath + "/channel.dat", "0", false);
//        FileUtils.WriteFile(Application.streamingAssetsPath + "/url.dat",
//            @"http://zjlmcdn.joygame.cn/zjlm/close_beta
//http://zjlmdl.joygame.cn/zjlm/close_beta", false);
    }

    public static void BuildIOSProject(Version v)
    {
        //隐藏Resources目录
        AndroidTool.ShowResourcesFolder(false);

        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();

        string[] levels = new string[] { "Assets/Scenes/Launcher.unity" };
        try
        {
            string apkPath = string.Format("{0}/{1}",ResSetting.AssetBundlesOutputPath,ResSetting.GetChannelRes());
            string location = string.Format("{0}/{1}", apkPath, v);
            UnityEditor.PlayerSettings.bundleVersion = FileUtilTool.ReadFile("IOS_Build/appleversion.dat").Replace("\r\n","\n").Replace("\n","");
			UnityEditor.PlayerSettings.bundleIdentifier = "com.yxm.tankwar";
            UnityEditor.PlayerSettings.iOS.buildNumber = AndroidOneKeyTool.versionCode.ToString();
            FileUtilTool.CreateFolderForFile(location);
            if (AndroidOneKeyTool.isDev)
            {
                string result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.iOS, BuildOptions.Il2CPP | BuildOptions.ConnectWithProfiler | BuildOptions.Development);
                
            }
            else
            {
                string result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.iOS, BuildOptions.Il2CPP);
            }
        }
        catch (System.Exception e)
        {
            Debug.LogError("build ios error： " + e.ToString());
        }
        finally
        {
            //恢复
            AndroidTool.ShowResourcesFolder(true);
        }
    }



    [MenuItem("Package/苹果/苹果完整包--不重新打资源")]
    public static void BuildIOSWithoutRebuiltRes()
    {
        
        Version v = Version.LoadVersionFromStreamingAsset();

        FileUtilTool.DeleteFolder("Assets/StreamingAssets/");

        //写入Version文件和写入fullApkIdentify文件
        Version.SaveVersion2StreamingAsset(v);

        //写入配置信息
        WriteIOSConfig();

        //拷贝除apk以外的资源
        ResTool.CopyResToStreaming();

        BuildIOSProject(v);


        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();
    }

	
}
