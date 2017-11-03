using UnityEngine;
using UnityEditor;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using SLua;

public class GAIA
{
    /// <summary>GAIA文件路径</summary>
    private static readonly string GAIA_PATH = "Assets/Scripts/Slua/Resources/gaia";
    /// <summary>层级显示是否折叠</summary>
    private bool foldout = true;
    /// <summary>美术关卡名</summary>
    private static string artLevelName;
    /// <summary>策划关卡名列表</summary>
    private static List<string> designLevelNames = new List<string>();

    public string ArtLevelName
    {
        get { return Path.GetFileName(artLevelName); }
    }

    public string DesignLevelName
    {
        get { return Path.GetFileName(designLevelNames[0]); }
    }

    public bool IsValid
    {
        get { return !string.IsNullOrEmpty(artLevelName) && designLevelNames.Count > 0; }
    }

    /// <summary>
    /// 当前场景是否是GAIA文件配置的场景
    /// </summary>
    /// <returns></returns>
    public bool IsSameScene()
    {
        // GAIA文件未打开
        if (string.IsNullOrEmpty(PROTOGONOS.Instance.LevelName))
            return false;

        string currentScenePath = UnityEditor.SceneManagement.EditorSceneManager.GetActiveScene().path;
        if (currentScenePath != "Assets/" + artLevelName + ".unity")
            return false;

        return true;
    }

    /// <summary>
    /// 自定义GUI绘制
    /// </summary>
    /// <param name="wnd"></param>
    public void DrawGUI(EditorWindow wnd)
    {
        // 按钮工具条
        GUILayout.BeginHorizontal();
        if (GUILayout.Button("NEW", EditorStyles.toolbarButton))
        {
            New();
        }
        if (GUILayout.Button("LOAD", EditorStyles.toolbarButton))
        {
            Load();
        }
        if (GUILayout.Button("SAVE", EditorStyles.toolbarButton))
        {
            Save();
        }
        GUILayout.EndHorizontal();

        // 关卡未打开
        if (string.IsNullOrEmpty(PROTOGONOS.Instance.LevelName))
            return;

        // 没有美术关卡和策划关卡，使用普通字符显示
        if (string.IsNullOrEmpty(artLevelName) && designLevelNames.Count == 0)
        {
            EditorGUILayout.SelectableLabel("  " + PROTOGONOS.Instance.LevelName);
        }
        else
        {
            // 折叠方式显示主关卡名
            foldout = EditorGUILayout.Foldout(foldout, PROTOGONOS.Instance.LevelName);
            if (foldout)
            {
                // 美术关卡
                if (!string.IsNullOrEmpty(artLevelName))
                    EditorGUILayout.SelectableLabel("   [ART]" + artLevelName, GUILayout.Height(16));
                // 策划关卡
                foreach (string designLevel in designLevelNames)
                {
                    EditorGUILayout.SelectableLabel("   [DESIGN]" + designLevel);
                }
            }
        }

        int controlId = GUIUtility.GetControlID(FocusType.Passive);
        switch (Event.current.GetTypeForControl(controlId))
        {
            case EventType.MouseDown:
                // 右键点击
                // TODO(kai.zou): GenericMenu
                if (Event.current.button == 1)
                {
                    GenericMenu menu = new GenericMenu();
                    menu.AddItem(new GUIContent("Set Art Level"), false, SetArtLevel);
                    menu.AddItem(new GUIContent("Set Design Level"), false, AddDesignLevel);
                    menu.ShowAsContext();
                }
                break;

            default:
                break;
        }
    }

    /// <summary>
    /// 自定义场景绘制
    /// </summary>
    /// <param name="sceneView"></param>
    public void DrawSceneGUI(SceneView sceneView)
    {
        // Empty
    }

    /// <summary>
    /// 新建主关卡
    /// </summary>
    public void New()
    {
        if (!Directory.Exists(GAIA_PATH))
            Directory.CreateDirectory(GAIA_PATH);

        string filename = EditorUtility.SaveFilePanel("New GAIA File", GAIA_PATH, "", "txt");
        if (!string.IsNullOrEmpty(filename))
        {
            artLevelName = null;
            designLevelNames.Clear();
            PROTOGONOS.Instance.LevelName = Path.GetFileNameWithoutExtension(filename);
            PlatoLoader loader = new PlatoLoader(PROTOGONOS.Instance.plato);
            loader.Load(Path.Combine(PLATO.PLATO_SAVE_PATH, PROTOGONOS.Instance.LevelName).Replace("GAIA_", "") + ".txt");
        }
    }

    /// <summary>
    /// 加载主关卡
    /// </summary>
    public void Load()
    {
        if (!Directory.Exists(GAIA_PATH))
            Directory.CreateDirectory(GAIA_PATH);

        string filename = EditorUtility.OpenFilePanel("Load GAIA File", GAIA_PATH, "txt");
        if (!string.IsNullOrEmpty(filename))
        {
            PROTOGONOS.Instance.LevelName = Path.GetFileNameWithoutExtension(filename);

            TextAsset asset = Resources.Load<TextAsset>(Path.Combine("gaia", PROTOGONOS.Instance.LevelName));

            // 使用一个临时的lua虚拟机解析文件
            IntPtr L = LuaDLL.luaL_newstate();
            LuaDLL.luaL_openlibs(L);

            object gaia;
            if (LuaUtil.LoadLua(L, asset.bytes, "@" + filename, out gaia))
            {
                artLevelName = null;
                designLevelNames.Clear();

                LuaUtil.TravelTable(L, gaia as LuaTable, (key, value) =>
                {
                    if (key == "art")
                        artLevelName = (string)value;
                    else if (key == "designs")
                        LoadDesigns(L, value as LuaTable);
                });

                // 打开美术关卡
                if (!string.IsNullOrEmpty(artLevelName))
                    UnityEditor.SceneManagement.EditorSceneManager.OpenScene("Assets/" + artLevelName + ".unity");

                string levelPath = "";
                // 加载策划关卡prefabs
                foreach (string designLevel in designLevelNames)
                {
                    if (designLevel.Contains("Resources"))
                    {
                        levelPath = designLevel.Replace("Resources", "Res");
                    }
                    else
                    {
                        levelPath = designLevel;
                    }
                    PlatoUtil.DesignLevel = PrefabUtility.InstantiatePrefab(AssetDatabase.LoadAssetAtPath("Assets/" + levelPath + ".prefab", typeof(GameObject))) as GameObject;
                }
            }
            LuaDLL.lua_close(L);
            L = IntPtr.Zero;

            // 打开对应的PLATO脚本
            PlatoLoader loader = new PlatoLoader(PROTOGONOS.Instance.plato);
            loader.Load(Path.Combine(PLATO.PLATO_SAVE_PATH, PROTOGONOS.Instance.LevelName).Replace("GAIA_", "") + ".txt");
        }
    }

    /// <summary>
    /// 解析策划关卡表
    /// </summary>
    /// <param name="L"></param>
    /// <param name="designs"></param>
    void LoadDesigns(IntPtr L, LuaTable designs)
    {
        LuaUtil.TravelTable(L, designs, (key, value) =>
        {
            designLevelNames.Add((string)value);
        });
    }

    /// <summary>
    /// 保存
    /// </summary>
    public void Save()
    {
        if (string.IsNullOrEmpty(PROTOGONOS.Instance.LevelName))
            return;
        
        // 保存为lua格式
        using(StreamWriter writer = new StreamWriter(Path.Combine(GAIA_PATH, PROTOGONOS.Instance.LevelName) + ".txt"))
        {
            writer.WriteLine("local {0} = {{", PROTOGONOS.Instance.LevelName);
            writer.WriteLine("\tart = '{0}',", string.IsNullOrEmpty(artLevelName) ? "empty" : artLevelName);
            writer.WriteLine("\tdesigns = {");
            foreach (string designLevel in designLevelNames)
            {
                writer.WriteLine("\t\t'{0}',", designLevel.Replace("Resources", "Res"));
            }
            writer.WriteLine("\t},");
            writer.WriteLine("}");
            writer.WriteLine("return {0}", PROTOGONOS.Instance.LevelName);
            writer.Flush();
            writer.Close();
            AssetDatabase.Refresh();
        }
    }

    /// <summary>
    /// 设置美术关卡
    /// </summary>
    static void SetArtLevel()
    {
        string filename = EditorUtility.OpenFilePanel("Set Art Level", "Assets/Content/Map", "unity");
        if (!string.IsNullOrEmpty(filename))
        {
            PROTOGONOS.Instance.gaia.SetArtLevel(filename);
            EditorWindow.focusedWindow.Repaint();
        }
    }
    void SetArtLevel(string filename)
    {
        artLevelName = filename.Substring(filename.IndexOf("Assets/") + "Assets/".Length).Replace(".unity", "");
    }

    /// <summary>
    /// 添加策划关卡
    /// </summary>
    static void AddDesignLevel()
    {
        string filename = EditorUtility.OpenFilePanel("Set Design Level", "Assets/Res", "prefab");
        if (!string.IsNullOrEmpty(filename))
        {
            PROTOGONOS.Instance.gaia.AddDesignLevel(filename);
            EditorWindow.focusedWindow.Repaint();
        }
    }
    void AddDesignLevel(string filename)
    {
        designLevelNames.Clear();
        designLevelNames.Add(filename.Substring(filename.IndexOf("Assets/") + "Assets/".Length).Replace(".prefab", ""));
    }

    // TODO(kai.zou): Remove design level

    /// <summary>
    /// 获得所有的GAIA文件名字
    /// </summary>
    /// <returns></returns>
    public static List<string> GetGaiaNames()
    {
        List<string> result = new List<string>();
        foreach (string filename in Directory.GetFiles(GAIA_PATH, "*.txt"))
        {
            result.Add(Path.GetFileNameWithoutExtension(filename));
        }

        return result;
    }
}
