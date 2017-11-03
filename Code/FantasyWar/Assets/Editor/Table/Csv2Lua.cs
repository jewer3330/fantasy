using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEditor;

public class Csv2Lua 
{
    [MenuItem("Tools/CSV2Lua")]
    public static void Run()
    {
        string[] files = Directory.GetFiles("Assets/Resources/Table","*.csv");
        foreach (var k in files)
        {
            string content = File.ReadAllText(k);
            string fileName = Path.GetFileNameWithoutExtension(k);
            Parse(fileName, content);
        }
    }

    /// <summary>
    /// 第一行是变量名称
    /// 第二行是类型
    /// 第三行至n行是数据
    /// </summary>
    /// <param name="content"></param>
    public static void Parse(string name,string content)
    {
        string[] lines = content.Replace("\r\n", "\n").Split('\n');
        string[] members = lines[0].Split('\t');
        string[] types = lines[1].Split('\t');

        List<string> all = new List<string>();

        for (int i = 2; i < lines.Length - 1;i++)
        {
            string lin = string.Empty;
            string[] datas = lines[i].Split('\t');
            string cen = string.Empty;
            for(int j = 0; j < datas.Length;j++)
            {
                string line = string.Empty;
                if(types[j] == "STRING")
                    line = luaLineFormatString.Replace("#Member", members[j]).Replace("#Data", datas[j]);
                else
                    line = luaLineFormatNum.Replace("#Member", members[j]).Replace("#Data", datas[j]);
                cen += line;
            }

            lin = luaFormat.Replace("#Key", datas[0]).Replace("#LineFormat", cen);
            all.Add(lin);
        }
        string r = string.Empty;
        foreach(var k in all)
        {
            r += k;
        }

        string ret = luaTableFormat.Replace("#Name", name).Replace("#Content", r);

        string path = string.Format("{0}/{1}.lua","Assets/Lua/Table",name);

        FileUtils.WriteFile(path,ret,false);
    }

    public static string luaTableFormat = @"
    #Name = {#Content
    }";

    public static string luaFormat = @"
        [#Key] = {#LineFormat
        }";

    public static string luaLineFormatNum =@"            
            #Member  = #Data";
    public static string luaLineFormatString = @"            
            #Member  = ""#Data""";
}
