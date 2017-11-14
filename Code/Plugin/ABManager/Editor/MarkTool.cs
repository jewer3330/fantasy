using UnityEngine;
using System.Collections;
using UnityEditor;
using System.Collections.Generic;
using System.IO;

namespace SuperBoBo
{
    public class MarkTool
    {

        /// <summary>
        /// asset/[Platform]/[Version]/assetrecord.dat
        /// </summary>
        static string m_markRecord
        {
            get
            {
                return GetRecordPath();
            }
        }

        public static string assetrecord_build = "config/assetrecord_build.dat";
        public static string recordPath = "config/record.txt";
        public static string record_diff = "config/record_diff.txt";
        public static string record_new = "config/record_new.txt";
        public static string record_del = "config/record_del.txt";
        public static string record_build = "config/record_build.txt";

        /// <summary>
        /// asset/[Platform]/[Version]/assetrecord.dat
        /// </summary>
        /// <returns></returns>
        public static string GetRecordPath()
        {
            string filePath = string.Format("{0}/{1}/{2}", ResSetting.build_root_path, Version.LoadVersionFromStreamingAsset(), "assetrecord.dat");
            return filePath;
        }


        [MenuItem("Package/测试/删除记录文件", false, 1)]
        public static void ClearMarkForce()
        {

            FileUtilTool.DelFile(m_markRecord);
            AssetDatabase.RemoveUnusedAssetBundleNames();
            AssetDatabase.Refresh();
            AssetDatabase.SaveAssets();
        }

        public static List<string> files = new List<string>();


        public static void FitterRecord(List<string> files)
        {
            List<Analysis.Info> results = new List<Analysis.Info>();

            files.Clear();


            foreach (var k in Analysis.fileInfos)
            {
                string lower = k.Value.fileName.ToLower();
                if (k.Value.ext == ".cs" || k.Value.ext == ".mask")
                {
                    continue;
                }
                else if (lower.EndsWith("jpg") || lower.EndsWith("png") || lower.EndsWith("psd"))
                {
                    results.Add(k.Value);
                }
                else if (k.Value.fileName.EndsWith("prefab") || k.Value.fileName.Contains("Resources"))
                {
                    results.Add(k.Value);
                }
                else
                {
                    if (k.Value.usedCount > 1)
                    {
                        results.Add(k.Value);
                    }
                }
            }



            foreach (var k in results)
            {
                files.Add(k.fileName);
            }


            //场景
            string[] scenes = MarkTool.GetSceneConfig();
            files.AddRange(scenes);
        }

        [MenuItem("Package/测试/生成记录文件", false, 2)]
        public static void GenRecord()
        {

            //遍历所有的Resource目录
            if (Analysis.fileInfos == null || Analysis.fileInfos.Count == 0)
            {
                Analysis.Analysing();
            }

            FitterRecord(files);

            //保存所有的记录文件到资源目录
            List<string> output = AssetAddBundleName(files);
            string filePath = GetRecordPath();
            WriteRecordFile(output.ToArray(), filePath);

            Analysis.fileInfos.Clear();
        }

        public static void SaveLog()
        {
            if (files != null && files.Count > 0)
            {
                //差异化打包
                List<RecordInfo> localRecords = LoadRecordFile(recordPath);
                List<RecordInfo> newRecords = GenRecords(files.ToArray());
                List<RecordInfo> rets = CompareRecord(newRecords, localRecords);


                SaveRecordFile(newRecords);


                //保存要打包的记录文件
                List<string> rets_tobuild = new List<string>();
                foreach (var k in rets)
                {
                    rets_tobuild.Add(k.fileName);
                }

                List<string> builds = AssetAddBundleName(rets_tobuild);
                WriteRecordFile(builds.ToArray(), assetrecord_build);
            }
        }


        public class RecordInfo
        {
            public string fileName;
            public string md5;

            public RecordInfo()
            {

            }

            public RecordInfo(string fileName, string md5)
            {
                this.fileName = fileName;
                this.md5 = md5;
            }

            public RecordInfo(string fileName)
            {
                this.fileName = fileName;
                this.md5 = ResCommon.GetFileMD5(fileName);
            }

            public override string ToString()
            {
                return this.fileName + "\t" + this.md5;
            }
        }



        public static List<RecordInfo> GenRecords(string[] files)
        {
            List<RecordInfo> records = new List<RecordInfo>();
            foreach (var k in files)
            {

                RecordInfo info = new RecordInfo(k);
                records.Add(info);
            }
            return records;
        }

        public static void SaveRecordFile(List<RecordInfo> records)
        {

            List<string> content = new List<string>();

            foreach (var k in records)
            {
                content.Add(k.ToString());
            }
            WriteRecordFile(content.ToArray(), recordPath);
        }

        public static List<RecordInfo> LoadRecordFile(string fileName)
        {

            List<RecordInfo> infos = null;
            if (!File.Exists(fileName))
            {
                return null;
            }

            try
            {

                string content = FileUtilTool.ReadFile(fileName);

                infos = new List<RecordInfo>();

                if (!string.IsNullOrEmpty(content))
                {
                    string[] lines = content.Split('\n');

                    foreach (var k in lines)
                    {
                        string[] kv = k.Split('\t');
                        RecordInfo info = new RecordInfo(kv[0], kv[1]);
                        infos.Add(info);
                    }
                }
            }
            catch (System.Exception e)
            {
                Debug.LogError(e.ToString());
                return null;
            }

            return infos;

        }

        public static List<RecordInfo> CompareRecord(List<RecordInfo> newer, List<RecordInfo> older)
        {
            List<RecordInfo> diff = new List<RecordInfo>();

            List<RecordInfo> newGened = new List<RecordInfo>();

            List<RecordInfo> deleted = new List<RecordInfo>();

            if (older != null && newer != null)
            {

                //对于每个新的在旧的查找
                foreach (var n in newer)
                {
                    bool find = false;

                    foreach (var o in older)
                    {
                        if (o.fileName == n.fileName)
                        {
                            find = true;
                            break;
                        }
                    }
                    if (!find)
                    {
                        newGened.Add(n);
                    }
                }

                //对于每个旧的在新的中查找
                foreach (var o in older)
                {
                    bool find = false;
                    foreach (var n in newer)
                    {
                        if (o.fileName == n.fileName)
                        {
                            find = true;
                            break;
                        }
                    }
                    if (!find)
                    {
                        deleted.Add(o);
                    }
                }

                //查找不同文件
                foreach (var n in newer)
                {
                    bool dif = false;
                    foreach (var o in older)
                    {
                        if (n.fileName == o.fileName)
                        {
                            if (n.md5 != o.md5)
                            {
                                dif = true;
                            }
                            break;
                        }
                    }
                    if (dif)
                        diff.Add(n);
                }
            }
            else if (newer == null)
            {
                Debug.LogError("error newer record info");
                return null;
            }
            else if (older == null)
            {
                newGened.AddRange(newer);
            }


            List<RecordInfo> rets = new List<RecordInfo>();

            rets.AddRange(diff);
            rets.AddRange(newGened);


            WriteRecordFile(diff, record_diff);
            WriteRecordFile(newGened, record_new);
            WriteRecordFile(deleted, record_del);
            WriteRecordFile(rets, record_build);

            return rets;
        }

        public static void WriteRecordFile(List<RecordInfo> records, string filePath)
        {
            List<string> lines = new List<string>();

            foreach (var k in records)
            {
                lines.Add(k.fileName + "\t" + k.md5);
            }
            WriteRecordFile(lines.ToArray(), filePath);
        }

        public static void WriteRecordFile(string[] lines, string filePath)
        {
            string data = string.Join("\n", lines);

            FileUtilTool.CreateFolderForFile(filePath);
            FileUtilTool.DelFile(filePath);
            FileUtilTool.WriteFile(filePath, data);
        }


        public static void DeleteNoNeedAssetBundle(List<RecordInfo> deleted)
        {
            foreach (var k in deleted)
            {
                string bundleName = GetAssetBundleName(k.fileName);

                FileUtilTool.DelFile(ResSetting.AssetBundlesPath() + "/" + bundleName);
            }
        }


        /// <summary>
        /// 获得场景文件的数组
        /// </summary>
        /// <returns></returns>
        public static string[] GetSceneArray()
        {
            List<string> sceneList = new List<string>();
            EditorBuildSettingsScene[] scenes = EditorBuildSettings.scenes;
            foreach (EditorBuildSettingsScene scene in scenes)
            {
                if (scene.enabled)
                {
                    sceneList.Add(scene.path);
                }
            }
            return sceneList.ToArray();
        }

        //[MenuItem("Package/读取场景信息")]

        public static string[] GetSceneConfig()
        {
            string content = FileUtilTool.ReadFile(BuildTool.sceneConfigPath);
            string[] scenes = content.Split('\n');
            //foreach (var s in scenes)
            //{
            //    Debug.Log(s);
            //}
            return scenes;
        }


        [MenuItem("Package/测试/全部打标签", false, 3)]
        public static void MarkAutoFromRecord()
        {
            ClearMarkDir("Assets");
            MarkFromRecord(m_markRecord);
        }

        //[MenuItem("Tools/打包/标签/差异化打标签", false, 3)]
        public static void MarkDiffFromRecord()
        {

            EditorUtility.DisplayProgressBar("清除标签...", "...", 0);

            ClearMarkDir("Assets");
            MarkFromRecord(assetrecord_build);

            EditorUtility.DisplayProgressBar("删除多余资源", "...", 0.33f);

            //删除多余资源
            List<RecordInfo> deletes = LoadRecordFile(record_del);
            DeleteNoNeedAssetBundle(deletes);


            EditorUtility.DisplayProgressBar("拷贝上次生成的资源", "...", 0.66f);

            //拷贝上次生成的资源
            if (!Directory.Exists("lastRes/"))
            {
                Debug.LogError("上次生成的资源不存在!");
                throw new System.Exception("上次生成的资源不存在--目录：lastRes/");
            }


            FileUtilTool.CopyFolder("lastRes/", ResSetting.AssetBundlesPath() + "/");

            EditorUtility.DisplayProgressBar("差异化打标签完成", "...", 1f);

            EditorUtility.ClearProgressBar();
        }


        public static void ClearMarkDir(string dir)
        {
            ClearMarkFile(dir);
            string[] arrDir = Directory.GetDirectories(dir);
            foreach (string d in arrDir)
            {
                ClearMarkDir(d);
            }
            string[] arrFile = Directory.GetFiles(dir);
            foreach (string file in arrFile)
            {
                if (Path.GetExtension(file) != ".meta")
                {
                    ClearMarkFile(file);
                }
            }
        }

        /// <summary>
        /// 清除单个文件的标签
        /// </summary>
        /// <param name="file">文件名称</param>
        public static void ClearMarkFile(string file)
        {
            MarkForFile(file, "");
        }


        [MenuItem("Package/测试/清除标签", false, 5)]
        public static void ClearAutoFromRecord()
        {
            MarkClearFromRecord(m_markRecord);
        }

        //[MenuItem("Tools/打包/清除标签/差异化清除", false, 5)]
        public static void ClearDiffFromRecord()
        {
            MarkClearFromRecord(assetrecord_build);
        }


        /// <summary>
        /// 从记录文件清除标记
        /// @warning 记录文件位置asset/[Platform]/[Version]/assetrecord.dat
        /// </summary>
        /// <param name="recordFile"></param>
        public static void MarkClearFromRecord(string recordFile)
        {
            EditorUtility.DisplayProgressBar("清除标签...", "...", 0);
            List<string> record = ReadRecord(recordFile);
            int i = 0;
            foreach (string r in record)
            {
                i++;
                string file = GetResourceNameFromRecord(r);
                string assetBundleName = GetPackageNameFromRecord(r);
                EditorUtility.DisplayProgressBar("清除标签...", file, (float)i / (float)record.Count);
                MarkForFile(file, "");
            }
            EditorUtility.ClearProgressBar();

            AssetDatabase.RemoveUnusedAssetBundleNames();

            AssetDatabase.Refresh();
            AssetDatabase.SaveAssets();
        }


        /// <summary>
        /// 从记录打标签
        /// </summary>
        /// <param name="recordFile"></param>
        public static void MarkFromRecord(string recordFile)
        {

            EditorUtility.DisplayProgressBar("打标签...", "...", 0);


            List<string> record = ReadRecord(recordFile);

            int i = 0;

            foreach (string r in record)
            {
                i++;
                string file = GetResourceNameFromRecord(r);
                string assetBundleName = GetPackageNameFromRecord(r);
                EditorUtility.DisplayProgressBar("打标签...", file, (float)i / (float)record.Count);

                MarkForFile(file, assetBundleName);
            }

            EditorUtility.ClearProgressBar();

            AssetDatabase.RemoveUnusedAssetBundleNames();

            AssetDatabase.Refresh();
            AssetDatabase.SaveAssets();
        }

        /// <summary>
        /// 标记一个文件的AssetBundle标签
        /// 文件不存在自动跳过
        /// </summary>
        /// <param name="file">文件名相对于Assets路径</param>
        /// <param name="assetBundleName">标签名称</param>
        public static void MarkForFile(string file, string assetBundleName)
        {
            AssetImporter ai = AssetImporter.GetAtPath(file);
            if (ai && ai.assetBundleName != assetBundleName)
            {
                ai.assetBundleName = assetBundleName;
            }

        }


        /// <summary>
        /// 返回资源名称
        /// @warning 从Assets开始
        /// 形如 Assets/Arts/Scene/School_elements.mat	assets/arts/scene/school_elements.mat.dat
        /// 返回 Assets/Arts/Scene/School_elements.mat
        /// </summary>
        /// <param name="record"></param>
        /// <returns></returns>
        public static string GetResourceNameFromRecord(string record)
        {
            string[] r = record.Split('\t');
            return r[0];
        }

        /// <summary>
        /// 返回包的名称
        /// @warning 从Assets开始
        /// 形如 Assets/Arts/Scene/School_elements.mat	assets/arts/scene/school_elements.mat.dat
        /// 返回 assets/arts/scene/school_elements.mat.dat 
        /// </summary>
        /// <param name="record"></param>
        /// <returns></returns>
        public static string GetPackageNameFromRecord(string record)
        {
            string[] r = record.Split('\t');
            return r[1];
        }


        /// <summary>
        /// 读取记录文件
        /// </summary>
        /// <param name="recordFile"></param>
        /// <returns></returns>
        public static List<string> ReadRecord(string recordFile)
        {

            if (!File.Exists(recordFile))
            {
                Debug.LogError(recordFile + " not exsits!");
                throw new FileNotFoundException(recordFile);
            }

            string content = FileUtilTool.ReadFile(recordFile);
            string[] lines = new string[0];
            if (!string.IsNullOrEmpty(content))
                lines = content.Split('\n');
            return new List<string>(lines);
        }


        public static List<string> AssetAddBundleName(List<string> listAsset)
        {
            List<string> listRecord = new List<string>();
            foreach (string asset in listAsset)
            {
                string r = string.Format("{0}\t{1}", asset.Replace("\\", "/").ToLower(), GetAssetBundleName(asset));
                listRecord.Add(r);
            }
            return listRecord;
        }


        /// <summary>
        /// 获得资源的包的名称
        /// @file 从Assets路径开始
        /// @warning 场景为 assets/scenes/*
        /// 普通资源 assets/resources/*.*
        /// shader资源 assets/shader/package.shader
        /// </summary>
        /// <param name="file"></param>
        /// <returns></returns>
        public static string GetAssetBundleName(string file)
        {
            string f = file.Replace("\\", "/");
            f = f.Replace(Application.dataPath.Replace("\\", "/"), "Assets");
            string name = AssetBundleFolder.GetAssetBundleName(f);
            name = ChineseHelper.GetPinyin(name);

            if (Path.HasExtension(name) && Path.GetExtension(name) == ".unity")
            {
                name = string.Format("Assets/Scenes/{0}", Path.GetFileNameWithoutExtension(name));
            }
            else if (Path.GetExtension(name) == ".shader")
            {
                name = string.Format("Assets/Shader/Package.shader");
            }
            else if (name.Contains("Resources"))
            {
                //name = string.Format("Assets/Resources/{0}", Path.GetFileName(file));

                name = string.Format("Assets/{0}", name.Substring(name.IndexOf("Resources")));
            }

            name = name.ToLower();
            name += ".dat";

            name = name.Replace("\\", "/");

            name = name.Replace("-", "_");
            name = name.Replace("#", "_");
            name = name.Replace("+", "_");


            while (name.IndexOf("/_") != -1)
            {
                name = name.Replace("/_", "/");
            }

            while (name.IndexOf(" ") != -1)
            {
                name = name.Replace(" ", "");
            }

            return name;
        }

    }
}