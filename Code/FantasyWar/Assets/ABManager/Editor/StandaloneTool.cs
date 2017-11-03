using UnityEngine;
using System.Collections;
using UnityEditor;
using System.IO;

public class StandaloneTool 
{

    const string fullApkIdentify = "fullApkIdentify";

    [MenuItem("Package/Standalone/生成本地资源")]
    public static void BuildStandaloneRes()
    {
		FileUtilTool.CopyFile ("IOS_Build/appleversion.dat", Application.streamingAssetsPath + "/appleversion.dat");
        Version v = AndroidOneKeyTool.versionRes;
        Version.SaveVersion2StreamingAsset(v);
        EditorUserBuildSettings.SwitchActiveBuildTarget(BuildTarget.StandaloneWindows64);
        ResTool.BuildLocalRes();
    }

    [MenuItem("Package/Standalone/完整包--重新打资源")]
    public static void BuildStandaloneFull()
    {

        BuildStandaloneRes();
        Version v = Version.LoadVersionFromStreamingAsset();
        
        FileUtilTool.DeleteFolder("Assets/StreamingAssets/");

        //写入Version文件和写入fullApkIdentify文件
        Version.SaveVersion2StreamingAsset(v);

        //写入配置信息
        WriteStandaloneConfig();

        //拷贝除apk以外的资源
        ResTool.CopyResToStreaming();

        BuildStandaloneProject(v);


        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();

        //上传资源
        ResTool.UploadRes();
    }


    public static void WriteStandaloneConfig()
    {
        FileUtils.WriteFile(Application.streamingAssetsPath + "/" + fullApkIdentify, "true", false);

    }

    public static void BuildStandaloneProject(Version v)
    {
        //隐藏Resources目录
        AndroidTool.ShowResourcesFolder(false);

        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();

        string[] levels = new string[] { "Assets/Scenes/Launcher.unity" };
        try
        {
            string apkPath = string.Format("{0}/{1}",ResSetting.AssetBundlesOutputPath,ResSetting.GetChannelRes());
            string location = string.Format("{0}/{1}.exe", apkPath, v);
            UnityEditor.PlayerSettings.bundleVersion = FileUtilTool.ReadFile("IOS_Build/appleversion.dat");
			UnityEditor.PlayerSettings.bundleIdentifier = "com.yxm.tankwar";
            FileUtilTool.CreateFolderForFile(location);
            string result = BuildPipeline.BuildPlayer(levels, location, BuildTarget.StandaloneWindows64,BuildOptions.None);
        }
        catch (System.Exception e)
        {
            Debug.LogError("build StandaloneWindows64 error： " + e.ToString());
        }
        finally
        {
            //恢复
            AndroidTool.ShowResourcesFolder(true);
        }
    }



    [MenuItem("Tools/打包/Standalone/完整包--不重新打资源")]
    public static void BuildStandaloneWithoutRebuiltRes()
    {
        
        Version v = Version.LoadVersionFromStreamingAsset();

        FileUtilTool.DeleteFolder("Assets/StreamingAssets/");

        //写入Version文件和写入fullApkIdentify文件
        Version.SaveVersion2StreamingAsset(v);

        //写入配置信息
        WriteStandaloneConfig();

        //拷贝除apk以外的资源
        ResTool.CopyResToStreaming();

        BuildStandaloneProject(v);


        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();
    }

	
}
