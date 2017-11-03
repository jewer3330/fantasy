using UnityEngine;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEditor.VersionControl;

public class Analysis
{

    public class Info
    {
        public string fileName;
        public long size;
        public int usedCount = 0;
        public string ext;
        public Asset.States st;
        public List<Info> dependInfos = new List<Info>();
    }

    public static Dictionary<string, Info> fileInfos = new Dictionary<string, Info>();

    [MenuItem("Tools/分析工具")]
    public static void Analysing()
    {
        List<string> folders = new List<string>();

        string[] dirs = Directory.GetDirectories(Application.dataPath, "*", SearchOption.AllDirectories);

        foreach (var k in dirs)
        {
            if (k.EndsWith("Resources") && !k.Contains("."))
            {
                folders.Add(k.Replace("\\", "/"));
            }
        }

        fileInfos.Clear();
        Analysing(folders.ToArray());

    }

    public static void Analysing(string[] folders)
    {
        List<string> names = new List<string>();

        foreach (var k in folders)
        {
            names.AddRange(Directory.GetFiles(k, "*", SearchOption.AllDirectories));
        }

        //场景
        //string[] scenes = MarkTool.GetSceneConfig();
        //names.AddRange(scenes);

        int i = 0;
        foreach (var k in names)
        {
            ++i;
            EditorUtility.DisplayProgressBar("分析资源中", "...", (float)i / (float)names.Count);

            GenInfo(k);

        }

        EditorUtility.ClearProgressBar();
        FileUtilTool.CreateFolderForFile(fileName);
        StreamWriter writer = new StreamWriter(fileName, false, System.Text.Encoding.Default);
        writer.WriteLine(@"文件名,子文件,文件后缀,文件大小(B),所有依赖文件个数,总大小(MB),引用次数,文件状态");
        foreach (var k in fileInfos)
        {
            PrintInfo(k.Value, writer);
        }
        writer.Flush();
        writer.Close();

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();
    }


    public static void PrintInfo(Info f, StreamWriter writer)
    {
        string line = "";


        double totalSize = 0;
        totalSize += f.size;

        foreach (var k in f.dependInfos)
        {
            totalSize += k.size;
        }

        line += f.fileName + ",," + f.ext + "," + f.size + "," + f.dependInfos.Count + "," + totalSize / 1024 / 1024 + "," + f.usedCount + "," + f.st;
        writer.WriteLine(line);

        foreach (var k in f.dependInfos)
        {
            line = "";
            line += ",";
            line += k.fileName + "," + k.ext + "," + k.size + "," + k.dependInfos.Count + "," + k.size / 1024 / 1024 + "," + k.usedCount + "," + f.st;
            writer.WriteLine(line);
        }
    }

    public static void GenInfo(string fileParent)
    {
        if (fileParent.Contains(".meta") || fileParent.Contains(".svn"))
            return;
        if (!string.IsNullOrEmpty(fileParent))
            fileParent = fileParent.Replace("\\", "/");

        fileParent = fileParent.Replace(Application.dataPath, "Assets");

        Info info = null;

        if (!fileInfos.ContainsKey(fileParent))
        {
            Asset ass = new Asset(fileParent);

            info = new Info();
            info.fileName = fileParent;
            info.st = ass.state;
            FileInfo fi = new FileInfo(fileParent);
            info.size = fi.Length;
            info.ext = fi.Extension.ToLower();
            fileInfos.Add(fileParent, info);
        }
        else
        {
            info = fileInfos[fileParent];
            info.usedCount++;
        }


        string[] depends = AssetDatabase.GetDependencies(fileParent);

        foreach (var f in depends)
        {
            if (f != fileParent.Replace(Application.dataPath, "Assets"))
            {


                Info sub = null;
                if (fileInfos.ContainsKey(f))
                {
                    sub = fileInfos[f];
                }
                else
                {
                    Asset ass = new Asset(f);
                    sub = new Info();
                    sub.fileName = f;
                    sub.st = ass.state;
                    FileInfo subfi = new FileInfo(Application.dataPath.Replace("Assets", "") + f);
                    sub.size = subfi.Length;
                    sub.ext = subfi.Extension.ToLower();
                    fileInfos.Add(sub.fileName, sub);
                }

                sub.usedCount++;
                fileInfos[fileParent].dependInfos.Add(sub);
            }
        }

    }

}
