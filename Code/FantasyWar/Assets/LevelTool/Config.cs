using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.IO;
public class Config 
{
    public static Dictionary<string, string> configs = new Dictionary<string, string>();

    public static string configPath = "/LevelTool/";
    public static string configFileName = "Config.txt";
    public static void ReadData()
    {
        configs.Clear();
        string content = File.ReadAllText(Application.dataPath + configPath + configFileName,System.Text.Encoding.UTF8);

        content = content.Replace("\r", "").Replace(" ","");
        string[] lines = content.Split('\n');

        foreach (var key in lines)
        {
            if (key.StartsWith("//") || string.IsNullOrEmpty(key))
                continue;
            string[] k = key.Split('=');
            if (k.Length > 2)
            {
                Debug.LogError("错误配置 " + key);
                continue;
            }
            else
            {
                if(configs.ContainsKey(k[0]))
                {
                    Debug.LogError("重复配置 " + k[0]);
                }
                else
                    configs.Add(k[0], k[1]);
            }
        }

        Config.version = Config.configs["version"];

        //目录
        Config.pathNodePathAssets = Config.configs["pathNodePathAssets"];
        Config.scenePathAssets = Config.configs["scenePathAssets"];
        Config.dataPathAssets = Config.configs["dataPathAssets"];
        Config.birthPathAssets = Config.configs["birthPathAssets"];
        Config.propPathAssets = Config.configs["propPathAssets"];
        Config.doorPathAssets = Config.configs["doorPathAssets"];
        Config.monsterPathAssets = Config.configs["monsterPathAssets"];
        Config.sceneObjectPathAssets = Config.configs["sceneObjectPathAssets"];
        Config.batchPathAssets = Config.configs["batchPathAssets"];

       
        //计算属性
        Config.scenePath = Config.scenePathAssets.Replace("Assets", Application.dataPath);
        Config.dataPath = Config.dataPathAssets.Replace("Assets", Application.dataPath);
        Config.pathNodePath = Config.pathNodePathAssets.Replace("Assets", Application.dataPath);
        Config.birthPath = Config.birthPathAssets.Replace("Assets", Application.dataPath);
        Config.propPath = Config.propPathAssets.Replace("Assets", Application.dataPath);
        Config.doorPath = Config.doorPathAssets.Replace("Assets", Application.dataPath);
        Config.monsterPath = Config.monsterPathAssets.Replace("Assets", Application.dataPath);
        Config.sceneObjectPath = Config.sceneObjectPathAssets.Replace("Assets", Application.dataPath);
        Config.batchPath = Config.batchPathAssets.Replace("Assets", Application.dataPath);


        Config.propTypesCn = Config.configs["propTypesCn"].Split(',');
        Config.propConditionsCn = Config.configs["propConditionsCn"].Split(',');
        Config.areaTypesCn = Config.configs["areaTypesCn"].Split(',');
        Config.mode1StarTypeCns = Config.configs["mode1StarTypeCns"].Split(',');
        Config.conditionCns = Config.configs["conditionCns"].Split(',');
        Config.tagCns = Config.configs["tagCns"].Split(',');
        Config.triggleCondTypeCn = Config.configs["triggleCondTypeCn"].Split(',');
        Config.triggleActionTypeCn = Config.configs["triggleActionTypeCn"].Split(',');
        Config.sceneTypeCn = Config.configs["sceneTypeCn"].Split(',');
        Config.mainAIs = Config.configs["mainAIs"].Split(',');
        Config.subAIs = Config.configs["subAIs"].Split(',');


    }

    public static string version = "3.8.0";
    public static string[] areaTypesCn = { "中立区", "防御区", "基地"};
    public static string[] triggleCondTypeCn = { "无", "波次开始时间", "波次间隔时间", "事件间隔时间", "杀死一只怪", "杀死一组怪", "走到某个区域" };
    public static string[] triggleActionTypeCn = { "无", "召唤一只怪" };
    public static string[] propTypesCn = { "定点", "全场随机" };
    public static string[] propConditionsCn = { "时间刷新" };
    public static string[] sceneTypeCn = {"无","龙卷风","油桶","流沙"};

    public static string[] mode1StarTypeCns = { "可复活·全灭模式", "不可复活·全灭模式", "可复活·指定模式", "不可复活·指定模式", "不可复活·存活模式" };
    public static string[] conditionCns = { "血量", "坦克类型", "时间", "人数" };
    public static string[] tagCns = { "怪物", "物件", "波次", "区域", "出生点", "道具", "路径", "模式" };
    public static string[] mainAIs = { "AI1", "AI2", "AI3", "AI4", "AI5", "AI6", "AI7", "AI8", "AI9", "AI10" };
    public static string[] subAIs = { "AIa", "AIb", "AIc", "AId", "AIe", "AIf", "AIg", "AIh", "AIe", "AIf" };

    public static string scenePathAssets = "Assets/Arts/OutPutScene/";
    public static string dataPathAssets = "Assets/LevelTool/Level/";
    public static string pathNodePathAssets = "Assets/LevelTool/Objects/";
    public static string birthPathAssets = "Assets/LevelTool/Objects/";
    public static string propPathAssets = "Assets/LevelTool/Objects/";
    public static string doorPathAssets = "Assets/LevelTool/Objects/";
    public static string monsterPathAssets = "Assets/Resources/Tank/";
    public static string sceneObjectPathAssets = "Assets/Resources/SceneObjects/";
    public static string batchPathAssets = "Assets/LevelTool/Triggles/";

    public static string scenePath = Application.dataPath + "/Arts/OutPutScene/";
    public static string dataPath = Application.dataPath + "/LevelTool/Level/";
    public static string pathNodePath = Application.dataPath + "/LevelTool/Objects/";
    public static string birthPath = Application.dataPath + "/LevelTool/Objects/";
    public static string propPath = Application.dataPath + "/LevelTool/Objects/";
    public static string doorPath = Application.dataPath + "/LevelTool/Objects/";
    public static string monsterPath = Application.dataPath + "/Resources/Tank/";
    public static string sceneObjectPath = Application.dataPath + "/Resources/SceneObjects/";
    public static string batchPath = Application.dataPath + "/LevelTool/Triggles/";



}
