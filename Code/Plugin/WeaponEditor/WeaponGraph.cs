using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEditor;
using System.Text.RegularExpressions;

[Serializable]
public class WeaponGraph : ScriptableObject
{
    public static readonly string EXPORT_LUA_PATH = "Assets/Scripts/Slua/Resources/weapon";
    public static readonly string EXPORT_CPP_PATH = "Assets/Editor Default Resources/Prometheus";
    public static readonly string PLATO_TEMPLATE_BASEPATH = "Assets/Editor Default Resources/PLATO/WeaponTemplate/";

	[SerializeField]
	public string assetName;

    public WeaponPhase weaponPhase = new WeaponPhase();
    private int weaponId;
    private string filename;
	private readonly Dictionary<string, string> typeKeyValue = new Dictionary<string, string>();

	public void Init()
	{
		if (!typeKeyValue.ContainsKey("System.String"))
			typeKeyValue.Add("System.String", "std::string");
		if (!typeKeyValue.ContainsKey("System.Int32"))
			typeKeyValue.Add("System.Int32", "int32_t");
		if (!typeKeyValue.ContainsKey("System.Single"))
			typeKeyValue.Add("System.Single", "float");
		if (!typeKeyValue.ContainsKey("System.Boolean"))
			typeKeyValue.Add("System.Boolean", "bool");

        weaponPhase.Load(weaponId);
        isPreviewMacro = false;
        filename = string.Format("{0}/{1}{2}.txt", EXPORT_LUA_PATH, "WeaponScript", weaponId);
	}

    private bool isPreviewMacro;

    /// <summary>
    /// 绘制编辑界面
    /// </summary>
    /// <param name="wnd"></param>
	public void UpdateGUI(EditorWindow wnd)
	{
        GUILayout.BeginHorizontal();
        EditorGUI.BeginDisabledGroup(isPreviewMacro);
        if (GUILayout.Button("Save", GUILayout.MaxWidth(100))) {
            weaponPhase.Save(weaponId);
        }
        if (GUILayout.Button("Export", GUILayout.MaxWidth(100))) {
            weaponPhase.ExportLua(filename);
            weaponPhase.ExportCSharp(Path.Combine(Path.Combine(PLATO.CSHARP_SAVE_PATH, "Weapon"), Path.GetFileNameWithoutExtension(filename)) + ".cs");
        }
        if (GUILayout.Button("Comment", GUILayout.MaxWidth(100)))
        {
            //skillPhaseList[skillIndex].Comment();
            weaponPhase.Comment();
        }
        EditorGUI.EndDisabledGroup();
        bool value = GUILayout.Toggle(isPreviewMacro, "预览宏展开");
        if (value != isPreviewMacro)
        {
            if (value)
            {
                weaponPhase.preview = new PLATO(weaponPhase.plato);
                PLATO.ExpandMacro(weaponPhase.preview);
            }
            else
            {
                weaponPhase.preview = null;
            }
        }
        isPreviewMacro = value;
		GUILayout.FlexibleSpace();
		GUILayout.EndHorizontal();

        //if (skillNames == null)
            //return;

        GUILayout.Label("Edit");

        //当前编辑武器的基础信息
        GUILayout.BeginHorizontal();
        GUILayout.Button("WeaponID", GUILayout.Width(80));
        GUILayout.Label(weaponId.ToString(),GUILayout.Width(50));

        GUILayout.FlexibleSpace();
        if (GUILayout.Button("LoadTemplate", GUILayout.Width(150))) {
            //TODO Load Model Template
            if (!Directory.Exists(PLATO.PLATO_SAVE_PATH + "WeaponTemplate/"))
                Directory.CreateDirectory(PLATO.PLATO_SAVE_PATH + "WeaponTemplate/");

            string fileName = EditorUtility.OpenFilePanel("Load Weapon Template File", PLATO.PLATO_SAVE_PATH + "WeaponTemplate/", "txt");
            Debug.Log("id = " + GetMidString(fileName, PLATO_TEMPLATE_BASEPATH, ".txt"));
            weaponPhase.LoadTemplate(GetMidString(fileName, PLATO_TEMPLATE_BASEPATH, ".txt"));
        }
        if (GUILayout.Button("SaveTemplate", GUILayout.Width(150))) {
            //TODO Save Model Template
            if (!Directory.Exists(PLATO.PLATO_SAVE_PATH + "WeaponTemplate/"))
                Directory.CreateDirectory(PLATO.PLATO_SAVE_PATH + "WeaponTemplate/");

            string fileName = EditorUtility.SaveFilePanel("Save Weapon Template File", PLATO.PLATO_SAVE_PATH + "WeaponTemplate/", "WeaponTemplate1", "txt");
            Debug.Log("id = " + GetMidString(fileName, PLATO_TEMPLATE_BASEPATH, ".txt"));
            weaponPhase.SaveTemplate(GetMidString(fileName, PLATO_TEMPLATE_BASEPATH, ".txt"));
        }
        GUILayout.EndHorizontal();

        weaponPhase.UpdateGUI(wnd, 100);
	}

    public int WeaponID
    {
        set { weaponId = value;}
        get { return weaponId; }
    }

    /// <summary>
    /// 正则表达式截取字符串 
    /// </summary>
    /// <param name="defString"></param>
    /// <param name="start"></param>
    /// <param name="end"></param>
    /// <returns></returns>
    private string GetMidString(string defString, string start, string end)
    {
        string str;
        try {
            Regex rg = new Regex("(?<=(" + start + "))[.\\s\\S]*?(?=(" + end + "))", RegexOptions.Multiline | RegexOptions.Singleline);
            str = rg.Match(defString).Value;
        }
        catch (Exception) {
            str = "0";
        }

        return str;
    }
}
