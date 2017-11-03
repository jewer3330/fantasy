using UnityEngine;
using UnityEditor;
using UnityEditor.Callbacks;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using LitJson;

public class AndroidOneKeyTool
{



    static CustomBuildLog lastBuildLog;
    static CustomBuildLog newBuildLog;

    /// <summary>
    /// fileName,MD5
    /// </summary>
    static Dictionary<string, string> lastestCSMD5 = new Dictionary<string, string>();

    /// <summary>
    /// fileName,MD5
    /// </summary>
    static Dictionary<string, string> newCSMD5 = new Dictionary<string, string>();


    public static string versionNameFile = "buildVersion.txt";
    public static string versionResFile = "versionRes.txt";
    public static string versionCodeFile = "versionCode.txt";
    public static string isDevFile = "dev.txt";
    public static string tempDataFile = "buildLast.json";
    public static string buildLogFile = "buildLog.json";
    public static string diffLogFile = "buildDiff.json";



    static string buildLogContent;

    /// <summary>
    /// 资源版本号
    /// </summary>
    public static Version versionRes
    {
        get
        {
            if (_versionRes == null)
            {
                if (File.Exists(versionResFile))
                {
                    string content = FileUtilTool.ReadFile(versionResFile);

                    content = content.Replace("\r\n", "\n").Replace("\n", "");

                    _versionRes = new Version(content);
                }
                else
                {
                    _versionRes = new Version(1, 0, 0);
                }
            }

            return _versionRes;
        }
    }

    private static Version _versionRes;

    /// <summary>
    /// APP版本号
    /// </summary>
    public static Version versionName
    {
        get
        {
            if (_versionName == null)
            {
                if (File.Exists(versionNameFile))
                {
                    string content = FileUtilTool.ReadFile(versionNameFile);
                    _versionName = new Version(content);
                }
                else
                {
                    _versionName = new Version(1, 0, 0);
                }

                UnityEditor.PlayerSettings.bundleVersion = _versionName.ToString();
            }
            return _versionName;
        }
    }


    private static Version _versionName;

    public static int versionCode
    {
        get
        {

            string cont = FileUtilTool.ReadFile(versionCodeFile);
            int codeVersion = 1;
            if (!string.IsNullOrEmpty(cont))
            {
                string[] blines = cont.Replace("\r\n", "\n").Split('\n');
                codeVersion = int.Parse(blines[0]);
            }
            PlayerSettings.Android.bundleVersionCode = codeVersion;
            return codeVersion;
        }
    }

    private static bool _isDev;

    public static bool isDev
    {
        get
        {

            string cont = FileUtilTool.ReadFile(isDevFile);
            bool _isDev = false;
            if (!string.IsNullOrEmpty(cont))
            {
                string[] blines = cont.Replace("\r\n", "\n").Split('\n');
                _isDev = bool.Parse(blines[0]);
            }

            return _isDev;
        }
    }


    [System.Serializable]
    public class FileMD5Data
    {
        public string filename;
        public string md5;

        public FileMD5Data()
        {

        }

        public FileMD5Data(string f, string m)
        {
            filename = f;
            md5 = m;
        }
    }

    [System.Serializable]
    public class CustomBuildLog
    {
        public string version;

        public List<FileMD5Data> csmd5;

        public CustomBuildLog()
        {
            csmd5 = new List<FileMD5Data>();
        }
        public void AddData(FileMD5Data data)
        {
            csmd5.Add(data);
        }
    }

    public static string[] stepNames = 
    { 
        "①删除记录文件", 
        "②生成记录文件", 
        "③打标签",
        "④生成Assetbundle资源",
        "⑤清除标签", 
        "⑥清除清单文件", 
        "⑦压缩资源包", 
        "⑧拷贝流媒体到版本资源目录",
    };


    [System.Serializable]
    public class BuildLog
    {
        public static int allStep = 7;
        public int curentStep;
        public string errorLog;


        public void First()
        {
            curentStep = 0;
            EditorUtility.DisplayProgressBar("安卓打包", "打包资源 " + AndroidOneKeyTool.stepNames[AndroidOneKeyTool.buildLog.curentStep],
                    (float)AndroidOneKeyTool.buildLog.curentStep / (float)AndroidOneKeyTool.BuildLog.allStep);
        }

        public void Next()
        {
            AndroidOneKeyTool.buildLog.curentStep++;
            EditorUtility.DisplayProgressBar("安卓打包", "打包资源 " + AndroidOneKeyTool.stepNames[AndroidOneKeyTool.buildLog.curentStep],
                (float)AndroidOneKeyTool.buildLog.curentStep / (float)AndroidOneKeyTool.BuildLog.allStep);
        }

        public void End()
        {
            EditorUtility.ClearProgressBar();
        }


    }

    public static BuildLog buildLog = new BuildLog();


    public static void SaveBuildLog(BuildLog buildLog)
    {
        string data = JsonMapper.ToJson(buildLog);
        FileUtilTool.WriteFile(buildLogFile, data);
    }

    public static void ReadLastBuildLog()
    {
        try
        {

            Debug.Log(versionName);
            Debug.Log(versionRes);
            Debug.Log(versionCode);


            if (File.Exists(tempDataFile))
            {
                string content = FileUtilTool.ReadFile(tempDataFile);

                lastBuildLog = JsonMapper.ToObject<CustomBuildLog>(content);

                foreach (var k in lastBuildLog.csmd5)
                {
                    lastestCSMD5.Add(k.filename, k.md5);
                }
            }

        }
        catch (Exception e)
        {
            Debug.LogError(e.ToString());
        }
    }

    static void UpgradeAPKVer()
    {
        versionRes.UpgradeLittleVersion();

        UpgradeCodeVersion();
    }

    static void UpgradeResVer()
    {
        versionRes.UpgradeLittleVersion();

        UpgradeCodeVersion();
    }

    public static string svnpath = Application.streamingAssetsPath;

    public static void CallShellCommand()
    {
        string srcdir = svnpath;
        srcdir = srcdir.Replace("\\", "/");

        System.Diagnostics.Process p = new System.Diagnostics.Process();


        p.StartInfo.FileName = "svn";

        p.StartInfo.WorkingDirectory = srcdir;

        p.StartInfo.Arguments = "update";
        p.StartInfo.CreateNoWindow = true;
        Debug.Log("cmd-> " + p.StartInfo.FileName + p.StartInfo.Arguments);
        p.Start();
        p.WaitForExit();
    }

    public static void CallShellCommandForVersionCode()
    {

        System.Diagnostics.Process p = new System.Diagnostics.Process();
        p.StartInfo.FileName = "svn";
        p.StartInfo.Arguments = " commit " + versionCodeFile + " -m 【VersionCode】提交";
        p.StartInfo.CreateNoWindow = true;
        Debug.Log("cmd-> " + p.StartInfo.FileName + p.StartInfo.Arguments);
        p.Start();
        p.WaitForExit();
    }

    [MenuItem("Tools/打包/测试SVN提交VersionRes")]
    public static void CallShellCommandForVersionRes()
    {

        System.Diagnostics.Process p = new System.Diagnostics.Process();
        p.StartInfo.FileName = "svn";
        p.StartInfo.Arguments = " commit " + versionRes + " -m 【VersionRes】提交";
        p.StartInfo.CreateNoWindow = true;
        Debug.Log("cmd-> " + p.StartInfo.FileName + p.StartInfo.Arguments);
        p.Start();
        p.WaitForExit();
    }


    [MenuItem("Tools/打包/测试SVN提交VersionCode")]
    public static void UpgradeCodeVersion()
    {
        PlayerSettings.Android.bundleVersionCode = versionCode + 1;
        FileUtilTool.WriteFile(versionCodeFile, PlayerSettings.Android.bundleVersionCode.ToString());
        FileUtilTool.WriteFile(Application.streamingAssetsPath + "/" + versionCodeFile, PlayerSettings.Android.bundleVersionCode.ToString());
        CallShellCommandForVersionCode();
        CallShellCommandForVersionRes();
    }

    [MenuItem("Tools/打包/安卓/更新到最新")]
    public static void UpdateStreaming()
    {
        //确保svn最新
        FileUtilTool.DeleteFolder(Application.streamingAssetsPath);
        FileUtilTool.CreateFolder(Application.streamingAssetsPath);

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh(ImportAssetOptions.ForceSynchronousImport);

        CallShellCommand();

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh(ImportAssetOptions.ForceSynchronousImport);
    }



    public enum Build
    {
        Project,
        APK
    }

    public static Build type = Build.APK;

    [MenuItem("Tools/打包/安卓/静默打包")]
    public static void StartBuildQuiet()
    {
        Caching.CleanCache();
        lastestCSMD5.Clear();
        newCSMD5.Clear();
        ReadLastBuildLog();
        newBuildLog = new CustomBuildLog();
        type = Build.APK;
        Debug.LogError("开始静默打包");
        CheckScriptsQuiet();
    }

    [MenuItem("Tools/打包/安卓/安卓工程")]
    public static void StartBuildQuietProject()
    {
        Caching.CleanCache();
        lastestCSMD5.Clear();
        newCSMD5.Clear();
        ReadLastBuildLog();
        newBuildLog = new CustomBuildLog();
        type = Build.Project;
        Debug.LogError("开始静默打工程");
        CheckScriptsQuiet();
    }

    [MenuItem("Tools/打包/安卓/QA专用")]
    public static void StartBuild()
    {

        Caching.CleanCache();
        lastestCSMD5.Clear();
        newCSMD5.Clear();

        //Debug.Log(Application.version);



        if (EditorUtility.DisplayDialog("安卓打包", "请确认Resources目录和StreamingAssets目录为SVN最新资源", "是", "否"))
        {
            ReadLastBuildLog();
            newBuildLog = new CustomBuildLog();
            CheckScripts();
        }
    }

    static void BuildQuietScriptDiff()
    {

        UpgradeAPKVer();

        Version.SaveVersion2StreamingAsset(versionRes);

        BuildAPK();

        SaveLastBuildLog();

        MarkTool.SaveLog();




    }

    static void BuildQuietResources()
    {

        UpgradeResVer();

        Version.SaveVersion2StreamingAsset(versionRes);

        BuildAPK();

        SaveLastBuildLog();

        MarkTool.SaveLog();
    }

    static void ShowScriptDiff(List<string> datas)
    {
        string content = "程序差异清单:\r\n";
        foreach (string s in datas)
        {
            content += s + "\r\n";
        }

        content += "资源清单:\r\n";
        string rescontent = GetDiffRes();
        content += rescontent;

        CustomDialog.Show("安卓打包", content, "继续", "取消", () =>
        {

            UpgradeAPKVer();

            Version.SaveVersion2StreamingAsset(versionRes);

            BuildAPK();

            SaveLastBuildLog();

            MarkTool.SaveLog();

        }, () =>
        {



        });


    }


    static void BuildAPK()
    {

        AndroidTool.BuildApkGenRes();
    }

    static void SaveLastBuildLog()
    {
        newBuildLog.version = versionRes.ToString();
        string jSon = JsonMapper.ToJson(newBuildLog);
        FileUtilTool.WriteFile(tempDataFile, jSon);

        FileUtilTool.WriteFile(versionResFile, versionRes.ToString());

    }


    public static void CheckScriptsQuiet()
    {
        List<string> difList = new List<string>();

        List<string> checkFiles = new List<string>();
        string[] csFiles = Directory.GetFiles(Application.dataPath, "*.cs", SearchOption.AllDirectories);
        string ManifestFile = Application.dataPath + "/Plugins/Android/AndroidManifest.xml";
        string[] jarFiles = Directory.GetFiles(Application.dataPath, "*.jar", SearchOption.AllDirectories);

        checkFiles.AddRange(csFiles);
        checkFiles.AddRange(jarFiles);
        checkFiles.Add(ManifestFile);

        int i = 0;
        CustomBuildLog fl = new CustomBuildLog();
        foreach (string f in checkFiles)
        {
            string path = f.Replace('\\', '/');
            string md5 = ResCommon.GetFileMD5(path);

            if (lastestCSMD5.ContainsKey(path))
            {
                if (lastestCSMD5[path] != md5)
                {
                    difList.Add(path);
                }
            }
            else
            {
                difList.Add(path);
            }

            i++;
            newBuildLog.AddData(new FileMD5Data(path, md5));

            EditorUtility.DisplayProgressBar("安卓打包", "检查脚本 " + f, (float)i / (float)csFiles.Length);
        }

        EditorUtility.ClearProgressBar();

        if (difList.Count > 0)
        {
            BuildQuietScriptDiff();
        }
        else
        {
            BuildQuietResources();
        }

        string json = JsonMapper.ToJson(difList);
        FileUtilTool.DelFile(diffLogFile);
        FileUtilTool.WriteFile(diffLogFile, json);
    }


    public static void CheckScripts()
    {
        List<string> difList = new List<string>();

        List<string> checkFiles = new List<string>();
        string[] csFiles = Directory.GetFiles(Application.dataPath, "*.cs", SearchOption.AllDirectories);
        string ManifestFile = Application.dataPath + "/Plugins/Android/AndroidManifest.xml";
        string[] jarFiles = Directory.GetFiles(Application.dataPath, "*.jar", SearchOption.AllDirectories);

        checkFiles.AddRange(csFiles);
        checkFiles.AddRange(jarFiles);
        checkFiles.Add(ManifestFile);

        int i = 0;
        CustomBuildLog fl = new CustomBuildLog();
        foreach (string f in checkFiles)
        {
            string path = f.Replace('\\', '/');
            string md5 = ResCommon.GetFileMD5(path);

            if (lastestCSMD5.ContainsKey(path))
            {
                if (lastestCSMD5[path] != md5)
                {
                    difList.Add(path);
                }
            }
            else
            {
                difList.Add(path);
            }

            //Debug.Log(f + " md5:" + md5);
            i++;
            newBuildLog.AddData(new FileMD5Data(path, md5));

            EditorUtility.DisplayProgressBar("安卓打包", "检查脚本 " + f, (float)i / (float)csFiles.Length);
        }

        EditorUtility.ClearProgressBar();

        if (difList.Count > 0)
        {

            if (EditorUtility.DisplayDialog("安卓打包", string.Format("本次打包含程序和资源更新\r\n 原资源版本号:{0}", versionRes), "继续", "取消"))
            {
                ShowScriptDiff(difList);

            }
        }
        else
        {
            if (EditorUtility.DisplayDialog("安卓打包", string.Format("本次打包只包含资源更新\r\n 原资源版本号:{0}", versionRes), "继续", "取消"))
            {
                CheckResources();
            }
        }

        Debug.Log("diff list :");
        foreach (string str in difList)
        {
            Debug.Log(str);
        }

        string json = JsonMapper.ToJson(difList);
        FileUtilTool.DelFile(diffLogFile);
        FileUtilTool.WriteFile(diffLogFile, json);
    }

    /// <summary>
    /// 获得不同的资源，包括新增和修改
    /// </summary>
    /// <returns></returns>
    public static string GetDiffRes()
    {
        string rescontent = "";

        //遍历所有的Resource目录
        Analysis.Analysing();


        List<string> files = new List<string>();

        MarkTool.FitterRecord(files);


        string recordPath = "record.txt";
        //差异化打包
        List<MarkTool.RecordInfo> localRecords = MarkTool.LoadRecordFile(recordPath);
        List<MarkTool.RecordInfo> newRecords = MarkTool.GenRecords(files.ToArray());
        List<MarkTool.RecordInfo> rets = MarkTool.CompareRecord(newRecords, localRecords);

        List<string> resfiles = new List<string>();

        foreach (var k in rets)
        {
            resfiles.Add(k.fileName);
        }

        rescontent = string.Join("\n", resfiles.ToArray());

        return rescontent;
    }

    public static void CheckResources()
    {
        string rescontent = GetDiffRes();

        if (rescontent != "")
        {

            CustomDialog.Show("资源更新", rescontent, "继续", "取消", () =>
            {
                UpgradeResVer();

                Version.SaveVersion2StreamingAsset(versionRes);

                BuildAPK();

                SaveLastBuildLog();

                MarkTool.SaveLog();
            },

            () =>
            {



            });
        }
        else
        {

            if (EditorUtility.DisplayDialog("安卓打包", "本次无更新,仍要出资源？", "是", "否"))
            {
                UpgradeResVer();

                Version.SaveVersion2StreamingAsset(versionRes);

                BuildAPK();

                SaveLastBuildLog();

                MarkTool.SaveLog();
            }
        }


    }

}
