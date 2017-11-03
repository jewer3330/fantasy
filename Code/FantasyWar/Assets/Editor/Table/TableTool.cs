using UnityEngine;
using System.Collections;
using UnityEditor;
using System.IO;
using System;

using System.Threading;


public class TableEditorWindow : EditorWindow
{

    public class Config
    {
        public string sourcePath = "Resources/Table";
        public string tableCSPath = "Scripts/Table";
        public string svnpath = Application.dataPath + @"/../../../Design/配置文件/client";
        public string pluginPath = Application.dataPath + "/Editor/Table";
        static string key = "table config info";

        public static void Save(Config data)
        {
            string store = LitJson.JsonMapper.ToJson(data);
            EditorPrefs.SetString(key, store);
        }

        public static Config Load()
        {
            string store = EditorPrefs.GetString(key);
            Config config = LitJson.JsonMapper.ToObject<Config>(store);
            if (config == null)
                return new Config();
            return config;
        }
    }

    [MenuItem("Tools/表单设置")]
    public static void ShowWindow()
    {
        TableEditorWindow w =  (TableEditorWindow)EditorWindow.GetWindow(typeof(TableEditorWindow));
        w.Show();
        w.data = Config.Load();
    }
    public Config data = new Config();
    void OnGUI()
    {
        data.sourcePath = EditorGUILayout.TextField("csv资源存放路径",data.sourcePath);
        data.tableCSPath = EditorGUILayout.TextField("cs代码存放路径", data.tableCSPath);
        data.svnpath = EditorGUILayout.TextField("svn更新路径", data.svnpath);
        data.pluginPath = EditorGUILayout.TextField("插件路径", data.pluginPath);

        if (GUILayout.Button("Save"))
        {
            Config.Save(data);
        }
    }


    
}

public class TableTool
{
   
    public static TableEditorWindow.Config config = new TableEditorWindow.Config();
    public static string resPath;

    [MenuItem("Tools/表一键处理")]
    public static void GlobalTable()
    {
        try
        {
            config = TableEditorWindow.Config.Load();
            resPath = string.Format("{0}/{1}", Application.dataPath, config.sourcePath);

            Debug.ClearDeveloperConsole();

            float progress = 0f;
            EditorUtility.DisplayProgressBar("Table", "Table", progress);

            CallShellCommand();

            EditorUtility.DisplayProgressBar("Table", "Table", 0.8f);

            AutoGenTableResAndScript();

            EditorUtility.DisplayProgressBar("Table", "Table", 1f);

            Thread.Sleep(100);

            EditorUtility.ClearProgressBar();

        }
        catch (System.Exception e)
        {
            Debug.LogError(e);
            EditorUtility.ClearProgressBar();

        }

    }

    public static void CallShellCommand()
    {
        string srcdir = config.svnpath;

        if (Directory.Exists(srcdir))
        {

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
        else
        {
            Debug.LogError(string.Format("配置错误{0}",srcdir));
        }
    }


    public static void AutoGenTableResAndScript()
    {
        if (!Directory.Exists(resPath))
        {
            Directory.CreateDirectory(resPath);
        }
        foreach (var k in Directory.GetFiles(config.svnpath))
        {
            File.Copy(k, k.Replace(config.svnpath, resPath), true);
        }

        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();

        TableTool tool = new TableTool();

        string[] arrFileName = Directory.GetFiles(resPath);
        foreach (string fileName in arrFileName)
        {
            
                tool.GenerateCSharpClass(fileName);

                tool.GenerateCSharpClass_Handle(fileName);
            
            
        }

        tool.GenerateTableLoad(arrFileName);

        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();

    }

    public void GenerateCSharpClass(string filePath)
    {
        //Debug.Log("TableFile : " + filePath);
        if (!filePath.EndsWith(".csv")) return;
        filePath = filePath.Replace("\\", "/");
        string fileName = filePath.Substring(filePath.LastIndexOf("/") + 1);
        fileName = fileName.Substring(0, fileName.LastIndexOf('.'));

        string text = File.ReadAllText(filePath);

        string textTemplate = GetCSharpClassTemplate();

        string[] lines = text.Split('\n');

        if (string.IsNullOrEmpty(lines[lines.Length - 1]))
        {
            string[] newlines = new string[lines.Length - 1];
            for (int i = 0; i < lines.Length - 1; i++)
            {
                newlines[i] = lines[i];
            }
            lines = newlines;
        }

        string[] members = lines[0].Split('\t');
        string[] types = lines[1].Split('\t');
        for (int i = 0; i < types.Length; i++)
        {
            types[i] = types[i].Replace("\r", "");
        }

        for (int i = 0; i < members.Length; i++)
        {
            members[i] = members[i].Replace("\r", "");
        }

        string Name = fileName;
        string Struct_Name = Name;

        //for (char c = 'A'; c <= 'Z'; c++)
        //{
        //    Struct_Name = Struct_Name.Replace(c.ToString(),"_" + ((char)(c + 32)).ToString());
        //}
        //Struct_Name = "table" + Struct_Name;

        string templateGet = @"        public static {Struct_Name} Get({Key_Type} {Key_Name})
        {
#if UNITY_EDITOR
            if (!Contains({Key_Name}))
            {

                Debug.LogError(""表{Struct_Name}没有元素"" + {Key_Name} + "",检测一下Excel表"");
                #if UNITY_EDITOR
                      UnityEditor.EditorApplication.isPaused = true;
                #endif
                return null;
            }
#endif
            return datas[{Key_Name}];
        }
";

        string get = templateGet.Replace("{Struct_Name}", Struct_Name);
        string Key_Type = ConvertType(types[0]);
        string Key_Name = members[0];
        get = get.Replace("{Key_Type}", Key_Type);
        get = get.Replace("{Key_Name}", Key_Name);

        string templateContains = @"        public static bool Contains({Key_Type} {Key_Name})
        {    
            return datas.ContainsKey({Key_Name});
        }
";

        string contains = templateContains.Replace("{Struct_Name}", Struct_Name);

        contains = contains.Replace("{Key_Type}", Key_Type);
        contains = contains.Replace("{Key_Name}", Key_Name);

        string templateField = "        public {Type} {Name};\n";
        string templateStructParams = " {Type} {Name}";
        string templateStructAssign = "            this.{Name} = {Name};\n";
        string Struct_Field = "";
        string Struct_Params = "";
        string Struct_Assign = "";

        string templateGetField = @"        public static {Field_Type} Get{Field_Name}({Key_Type} {Key_Name})
        {
            return Get({Key_Name}).{Field_Name};
        }
";
        string Get_Field = "";
        for (int i = 0; i < members.Length; i++)
        {
            string member = members[i];
            member = member.Replace("\n", "");
            member = member.Replace("\r", "");
            string type = ConvertType(types[i]);

            string memberLower = member;
            //char[] memberChar = memberLower.ToCharArray();
            ////memberChar[0] = (char)(memberChar[0] >= 'A' && memberChar[0] <= 'Z' ? memberChar[0] + 32 : memberChar[0]);
            //Debug.Log(memberLower + "  "+ (int)memberChar[memberChar.Length - 1]);
            //memberLower = new string(memberChar);
            memberLower = memberLower.Replace("\n", "");

            string field = templateField;
            field = field.Replace("{Type}", type);
            field = field.Replace("{Name}", memberLower);
            Struct_Field += field;

            string structParams = templateStructParams;
            structParams = structParams.Replace("{Type}", type);
            structParams = structParams.Replace("{Name}", memberLower);
            Struct_Params += structParams;
            if (i != members.Length - 1)
            {
                Struct_Params += ",";
            }

            string structAssign = templateStructAssign;
            structAssign = structAssign.Replace("{Type}", type);
            structAssign = structAssign.Replace("{Name}", memberLower);
            Struct_Assign += structAssign;

            if (i != 0)
            {
                string getField = templateGetField.Replace("{Field_Name}", memberLower);
                getField = getField.Replace("{Field_Type}", type);
                getField = getField.Replace("{Key_Type}", Key_Type);
                getField = getField.Replace("{Key_Name}", Key_Name);
                Get_Field += getField;
            }
        }

        textTemplate = textTemplate.Replace("{Name}", Name);
        textTemplate = textTemplate.Replace("{Struct_Name}", Struct_Name);
        textTemplate = textTemplate.Replace("{Struct_Field}", Struct_Field);

        textTemplate = textTemplate.Replace("{Struct_Construct_Params}", Struct_Params);
        textTemplate = textTemplate.Replace("{Struct_Construct_Assign}", Struct_Assign);

        textTemplate = textTemplate.Replace("{Key_Type}", Key_Type);

        textTemplate = textTemplate.Replace("{Get}", get);
        textTemplate = textTemplate.Replace("{Get_Field}", Get_Field);
        textTemplate = textTemplate.Replace("{Contains}", contains);


        //LoadFromMemory
        string templateLoadFromMemory = @"        public static void LoadFromMemory()
        {
{data}
        }
";
        //string datas = "";
        //string templateData = "            datas.Add({Key}, new {Struct_Name}({data}));\n";
        //templateData = templateData.Replace("{Struct_Name}", Struct_Name);
        //for (int i = 2; i < lines.Length; i++)
        //{
        //    string data = templateData;
        //    string line = lines[i];
        //    string[] values = line.Split('\t');
        //    Debug.Log(types.Length + "   " + values.Length);
        //    for (int j = 0; j < types.Length; j++)
        //    {
        //        values[j] = values[j].Replace("\r", "");
        //        if (types[j] == "STRING")
        //        {
        //            values[j] = '"' + values[j] + '"';
        //        }
        //        else if (true)
        //        {
        //            if (values[j] == "" || values[j] == " ")
        //                values[j] = "0";
        //        }
        //        values[j] = values[j].Replace("\r", "");
        //        values[j] = values[j].Replace("\n", "");
        //    }
        //    //Debug.Log(values[0]);
        //    data = data.Replace("{Key}", values[0]);
        //    data = data.Replace("{data}", string.Join(", ", values));
        //    datas += data; 
        //    Thread.Sleep(100);
        //}

        //templateLoadFromMemory = templateLoadFromMemory.Replace("{data}", datas);
        //textTemplate = textTemplate.Replace("{LoadFromMemory}", templateLoadFromMemory);
        
        string templateLoadFromString = @"        public static void LoadFromString(string data)
        {

            string content = data;
            string[] lines = content.Split('\n');
       

            for (int i = 2; i < lines.Length; i++)
            {
                string line = lines[i];
                line = line.Replace(""\r"", """");
                if(string.IsNullOrEmpty(line)) continue;
                string[] values = line.Split('\t');
                if(values.Length != memberCount)
                {
                    Debug.LogError(""{Struct_Name}严重错误，表头和表数据长度不一样"");
#if UNITY_EDITOR
                     UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException(""{Struct_Name}严重错误，表头和表数据长度不一样"");
                    return;
                }
                {Struct_Name} data{Struct_Name} = new {Struct_Name}();
{Data_Field}
                if (datas.ContainsKey(data{Struct_Name}.{Key_Name}))
                {
               #if UNITY_EDITOR
                     UnityEditor.EditorApplication.isPaused = true;
                #endif
                    throw new ArgumentException(""数据有误,主键重复:"" + data{Struct_Name}.{Key_Name});
                }
                datas.Add(data{Struct_Name}.{Key_Name},data{Struct_Name});
            }

        }
";
       templateLoadFromString = templateLoadFromString.Replace("{Struct_Name}", Struct_Name);
        string dataParse = "";
        string[] dataParseList = new string[types.Length];
        for (int i = 0; i < types.Length; i++)
        {
            //Debug.Log(string.Format("data{0}.{1}", Struct_Name, members[i]));
            //Debug.Log(string.Format(string.Format("values[{0:d}]",i)));
            dataParseList[i] = Parse(types[i], string.Format("data{0}.{1}", Struct_Name, members[i]), string.Format("values[{0:d}]", i));
            //if (types[i] == "STRING")
            //{
            //    dataParseList[i] = string.Format("                data{0}.{1} = values[{2:d}];", Struct_Name, members[i], i);
            //}
            //else
            //{
            //    //dataParseList[i] = string.Format("{0}.Parse(values[{1}]);\n", ConvertType(types[i]), i);
            //    dataParseList[i] = string.Format("                {0}.TryParse(values[{1:d}],out data{2}.{3});", ConvertType(types[i]), i, Struct_Name, members[i]);
            //}

            //if (i == 0)
            //{
            //    templateLoadFromString = templateLoadFromString.Replace("{Key}", dataParseList[0]);
            //}
        }
        dataParse = string.Join("\n", dataParseList);
        templateLoadFromString = templateLoadFromString.Replace("{Struct_Name}", Struct_Name);
        templateLoadFromString = templateLoadFromString.Replace("{Key_Type}", Key_Type);
        templateLoadFromString = templateLoadFromString.Replace("{Key_Name}", Key_Name);
        templateLoadFromString = templateLoadFromString.Replace("{Data_Field}", dataParse);

        textTemplate = textTemplate.Replace("{LoadFromString}", templateLoadFromString);

        string path = "Table" + "/" + fileName;
        string iosPath = "Table_IOS" + "/" + fileName;
        //path = path.Replace(Application.dataPath, "");
        //path = path.Replace("Resources/", "");
        //path = path.Substring(0, path.LastIndexOf('.'));
        textTemplate = textTemplate.Replace("{Path}", path);
        textTemplate = textTemplate.Replace("{Path_IOS}", iosPath);
        //path = "Table" + "/" + fileName;
        //path = path.Replace(Application.dataPath, "");
        ////path = path.Replace("/Resources/", "");
        ////path = path.Substring(0, path.LastIndexOf('.'));
        //textTemplate = textTemplate.Replace("{StreamingPath}", path);

        textTemplate = textTemplate.Replace("{Member_Count}", "static int memberCount = " + members.Length + " ; ");

        string savePath = filePath.Replace(config.sourcePath, config.tableCSPath + "/Gen");
        savePath = savePath.Replace(".csv", ".cs");
        if (!Directory.Exists(Application.dataPath + "/" + config.tableCSPath + "/Gen")) Directory.CreateDirectory(Application.dataPath + "/" + config.tableCSPath + "/Gen");
        FileStream fs = new FileStream(savePath, FileMode.Create);
        byte[] tdata = System.Text.Encoding.UTF8.GetBytes(textTemplate);
        fs.Write(tdata, 0, tdata.Length);
        fs.Flush();
        fs.Close();

        //AssetDatabase.SaveAssets();
        //AssetDatabase.Refresh();
    }

    public void GenerateCSharpClass_Handle(string filePath)
    {
        if (!filePath.EndsWith(".csv")) return;
        filePath = filePath.Replace("\\", "/");
        string fileName = filePath.Substring(filePath.LastIndexOf("/") + 1);
        fileName = fileName.Substring(0, fileName.LastIndexOf('.'));

        string textTemplate = GetCSharpClassTemplateHandle();

        string Name = fileName;

        textTemplate = textTemplate.Replace("{Name}", Name);
        string dir = filePath.Replace(config.sourcePath, config.tableCSPath+ "/Handle");
        if (!Directory.Exists(Path.GetDirectoryName(dir)))
        {
            Directory.CreateDirectory(Path.GetDirectoryName(dir));
        }

        string savePath = filePath.Replace(config.sourcePath, config.tableCSPath + "/Handle");
        savePath = savePath.Replace(".csv", ".cs");
        if (!File.Exists(savePath))
        {
            StreamWriter sw = new StreamWriter(savePath, false, System.Text.Encoding.UTF8);
            sw.Write(textTemplate);
            sw.Flush();
            sw.Close();
            //FileStream fs = new FileStream(savePath, FileMode.Create);
            //byte[] tdata = System.Text.Encoding.UTF8.GetBytes(textTemplate);
            //fs.Write(tdata, 0, tdata.Length);
            //fs.Flush();
            //fs.Close();
        }
        else
        {
            StreamReader sr = new StreamReader(savePath);
            string data = sr.ReadToEnd();
            sr.Close();

            StreamWriter sw = new StreamWriter(savePath, false, System.Text.Encoding.UTF8);
            sw.Write(data);
            sw.Flush();
            sw.Close();
        }

        //AssetDatabase.SaveAssets();
        //AssetDatabase.Refresh();

    }

    public void GenerateTableLoad(string[] arrFileName)
    {
        string textTemplate = GetCSharpTableLoadTemplate();

        string loadFromMemory = "";
        string loadFromResource = "";
        string loadFromWWW = "";
        string clear = "";
        string[] files = Directory.GetFiles(Application.dataPath + "/" + config.sourcePath);
        
        foreach (string file in files)
        {
            if (!file.EndsWith(".csv")) continue;
            string fileName = file.Replace("\\", "/");
            fileName = fileName.Substring(fileName.LastIndexOf("/") + 1);
            fileName = fileName.Substring(0, fileName.LastIndexOf('.'));

            loadFromMemory += string.Format("            {0}.LoadFromMemory();\n", fileName);

            //            string resourceFile = "Table/" + fileName;
            //            loadFromResource += string.Format(@"        TextAsset data{0} = Resources.Load(""{1}"") as TextAsset;
            //        string text{0} = data{0}.text;
            //        {0}.InitFromString(text{0});
            //
            //", fileName,resourceFile);

            loadFromResource += string.Format("            {0}.LoadFromResources();\n", fileName);

            loadFromWWW += string.Format("            {0}.LoadFromStreaming();\n", fileName);


            clear += string.Format("            {0}.Clear();\n", fileName);
        }

        textTemplate = textTemplate.Replace("{LoadFromMemory}", loadFromMemory);
        textTemplate = textTemplate.Replace("{LoadFromResource}", loadFromResource);
        textTemplate = textTemplate.Replace("{LoadFromStreaming}", loadFromWWW);
        textTemplate = textTemplate.Replace("{Clear}", clear);

        string savePath = Application.dataPath + "/" + config.tableCSPath + "/TableLoad.cs";

        FileStream fs = new FileStream(savePath, FileMode.Create);
        byte[] tdata = System.Text.Encoding.UTF8.GetBytes(textTemplate);
        fs.Write(tdata, 0, tdata.Length);
        fs.Flush();
        fs.Close();

        //AssetDatabase.SaveAssets();
        //AssetDatabase.Refresh();
    }

    public string GetCSharpTableLoadTemplate()
    {
        string filePath = string.Format("{0}/{1}",config.pluginPath, "TableLoad.txt");
        return File.ReadAllText(filePath);
    }

    public string GetCSharpClassTemplate()
    {
        string filePath = string.Format("{0}/{1}", config.pluginPath, "Table.txt"); 
        return File.ReadAllText(filePath);
    }

    public string GetCSharpClassTemplateHandle()
    {
        string filePath = string.Format("{0}/{1}", config.pluginPath, "TableHandle.txt"); 
        return File.ReadAllText(filePath);
    }

    public string ConvertType(string type)
    {
        string value = type;
        switch (type)
        {
            case "UINT32":
                value = "uint";
                break;
            case "INT":
                value = "int";
                break;
            case "UINT":
                value = "uint";
                break;
            case "INT32":
                value = "int";
                break;
            case "STRING":
                value = "string";
                break;
            case "SHORT":
                value = "short";
                break;
            case "INT16":
                value = "short";
                break;
            case "UINT16":
                value = "ushort";
                break;
            case "INT8":
                value = "sbyte";
                break;
            case "UINT8":
                value = "byte";
                break;
            case "BOOLEAN":
            case "BOOL":
                value = "bool";
                break;
            default:
                value = null;
                break;
        }
        return value;
    }

    public string Parse(string type, string var, string val)
    {
        string value = null;
        switch (type)
        {
            case "STRING":
                value = string.Format("                {0} = {1};", var, val);
                break;
            case "UINT32":
            case "INT":
            case "UINT":
            case "INT32":
            case "SHORT":
            case "INT16":
            case "UINT16":
            case "INT8":
            case "UINT8":
                int start = val.IndexOf("[") + 1;
                int end = val.IndexOf("]");
                string lineNum = val.Substring(start, end - start);
                value = string.Format(
@"                if(!{0}.TryParse({1},out {2}))
                {{

#if UNITY_EDITOR
                    Debug.LogError(""数据有误:"" + {1} + "" to {0}"");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException(""数据有误:"" + {1} + "" to {0}"" + "" 第""+ i + ""行,第{3}列"");
                 
                }}"
                , ConvertType(type), val, var,lineNum);
                break;
            case "BOOLEAN":
            case "BOOL":
                int s = val.IndexOf("[") + 1;
                int e = val.IndexOf("]");
                string num = val.Substring(s, e - s);
                string one = val;
                string two = var;
                string three = var.Substring(var.IndexOf('.') + 1);
                value = 
                "\t\t int "+ three + " = 0; \r\n"
+ "\t\t if(!int.TryParse(" + one + ", out "+ three + ")) \r\n"
+ "\t\t  { \r\n"
+ "#if UNITY_EDITOR  \r\n"
+ "\t\t  Debug.LogError(\"数据有误:\" + " + one + " + \" to int\"); \r\n"
+ "\t\t\t UnityEditor.EditorApplication.isPaused = true; \r\n"
+ "#endif \r\n"
+ "\t\t\t throw new ArgumentException(\"数据有误:\" + " + one + " + \" to int\" + \" 第\"+ i + \"行,第" + num + "列\"); \r\n"
+ "\t\t } \r\n"
+ "\t\t " + two + " = " + three + " == 1;\r\n";
                Debug.Log(value);
                break;
            default:
                value = string.Format("                {0} = {1};", var, val);
                break;
        }
        return value;
    }
}
