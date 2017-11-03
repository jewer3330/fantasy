using UnityEngine;
using System.Collections;
using UnityEditor;
using System.IO;
using System.Collections.Generic;

public class BuildAssetBundleTool 
{

    public static string ab_basepath = ResSetting.build_root_path;
    
    /// <summary>
    /// lastRes/[Platform]/assetbundles
    /// </summary>
    public static string ab_version_path = ResSetting.build_ab_path;

    [MenuItem("Tools/打包/生成Assetbundle资源", false, 4)]

    
    public static void BuildAssetBundles()
    {

        EditorUtility.DisplayProgressBar("生成Assetbundle中", "...", 0);
//      string outputPath = ResSetting.AssetBundlesPath();
        
        BuildAssetBundles(ab_version_path);

//        DeleteMainfestFile();

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();

//        EditorUtility.DisplayProgressBar("拷贝lastRes到Assetbundle目录", "...", 0.5f);
        //if (!Directory.Exists(ab_basepath))
        //{
        //    Directory.CreateDirectory(ab_basepath);
        //}
//        FileUtilTool.CopyFolder(ab_version_path,outputPath);

        EditorUtility.DisplayProgressBar("生成Assetbundle中完成", "...", 1);

        EditorUtility.ClearProgressBar();

    }


    public static void BuildAssetBundles(string outputPath)
    {
        if (!Directory.Exists(outputPath))
        {
            Directory.CreateDirectory(outputPath);
            //Directory.Delete(outputPath, true);
        }

        BuildPipeline.BuildAssetBundles(outputPath, BuildAssetBundleOptions.DeterministicAssetBundle, EditorUserBuildSettings.activeBuildTarget);


        
    }

    
    [MenuItem("Tools/打包/测试生成场景文件", false, 4)]

    public static void BuildSceneAssetBundle()
    {
        MarkTool.ClearMarkDir("Assets");
        //场景
        string[] scenes = MarkTool.GetSceneConfig();

        //List<string> marks = new List<string>();
        //foreach (var k in scenes)
        //{
        //    marks.AddRange(AssetDatabase.GetDependencies(k));
        //}
        
        //foreach(var k in marks)
        //{
        //    if(!k.EndsWith(".cs"))
        //        MarkTool.MarkForFile(k, "scenes/" + new FileInfo(k).Name);
        //}

        foreach (var k in scenes)
        {
            if (!k.EndsWith(".cs"))
                MarkTool.MarkForFile(k, "scenes/" + new FileInfo(k).Name);
        }
       
        BuildPipeline.BuildAssetBundles("test/", BuildAssetBundleOptions.UncompressedAssetBundle, EditorUserBuildSettings.activeBuildTarget);



        GenMD5();

        //BuildPipeline.BuildStreamedSceneAssetBundle(new string[1] { file }, outname, BuildTarget.Android, BuildOptions.BuildAdditionalStreamedScenes);
    }
    
    [MenuItem("Tools/打包/测试生成场景文件のMD5", false, 4)]
    public static void GenMD5()
    {
        List<string> md5s = new List<string>();
        string [] files = Directory.GetFiles("test/","*.*",SearchOption.AllDirectories);
        foreach(var k in files)
        {
            md5s.Add(k + "\t" + ResCommon.GetFileMD5(k));
            //if(!k.EndsWith(".manifest"))
            //{ 
            //    byte[] bs = File.ReadAllBytes(k);
            //    AssetBundle ab = AssetBundle.LoadFromMemory(bs);
            //    string []assetNames = ab.GetAllAssetNames();
            //}
        }
        FileUtilTool.WriteFile("testscenes.md5", string.Join("\r\n", md5s.ToArray()));

        
    }


    public static void DeleteMainfestFile(string path)
    {

        string[] files = Directory.GetFiles(path, "*.manifest", SearchOption.AllDirectories);

        string output = "Manifest";

        FileUtilTool.DeleteFolder(output);

        foreach(var f in files)
        {
            FileUtilTool.DelFile(f);
        }
        
    }

  
}
