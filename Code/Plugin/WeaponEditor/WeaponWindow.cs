using UnityEngine;
using UnityEditor;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System;
using System.Text;
using System.Text.RegularExpressions;

[Serializable]
public class WeaponDataSetting
{
	public int weaponID = 0;
	public string weaponName;
    public WeaponType weaponType;
}

/// <summary>
///   Load character, animation & set phases.
/// </summary>
public class WeaponWindow : EditorWindow
{
    #region public member
    #endregion public member

    #region private member
    /// <summary>Weapon编辑 文件路径</summary>
    private static readonly string WEAPON_PATH = "Assets/Editor Default Resources/PLATO/WeaponEditor";

    private readonly string BASE_WEAPON_PATH = "Assets/Editor Default Resources/PLATO/WeaponEditor/WeaponScript";

    private WeaponDataSetting weaponDataSetting = new WeaponDataSetting();
    private int weaponID;
	private bool enableDraw;
    #endregion private member

    #region mono
    private void Update()
	{

		return;
	}

	private void OnEnable()
	{

		return;
	}

	private void OnDestroy()
	{

		return;
	}

	private void OnGUI()
	{
		//if (!enableDraw)
		//	return;

        //新建 打开 相应Weapon
        GUILayout.BeginHorizontal();
        if (GUILayout.Button("NewWeapon",GUILayout.Width(150)))
            NewWeapon();
        if (GUILayout.Button("LoadWeapon",GUILayout.Width(150)))
            LoadWeapon();
        GUILayout.EndHorizontal();

		return;
	}
	#endregion mono

	#region private imp
    /// <summary>
    /// 新建Weapon
    /// </summary>
    private void NewWeapon()
    {
        if (!Directory.Exists(WEAPON_PATH))
            Directory.CreateDirectory(WEAPON_PATH);

        ///新建武器文件
        string filename = EditorUtility.SaveFilePanel("New Weapon File", WEAPON_PATH, "WeaponScript0", "txt");
        if (string.IsNullOrEmpty(filename))
            return;
        // 禁用选择，不然在点击按钮后unity会莫名的移动选中物体
        Selection.activeGameObject = null;
        StreamWriter writer = new StreamWriter(filename, false, Encoding.UTF8);
        writer.Close();

        ///打开武器编辑窗口
        Debug.Log("NewWeapon filename = " + filename);
        weaponDataSetting.weaponID = GetMidStringToInt(filename, BASE_WEAPON_PATH, ".txt");
        Debug.Log(" weaponDataSetting.weaponID = " + weaponDataSetting.weaponID);
        weaponID = weaponDataSetting.weaponID;
        var window = GetWindow<WeaponEditor>();
        if (window.curGraph == null) {
            window.curGraph = WeaponEditorUtil.LoadGraph(weaponID.ToString());
            window.curGraph.WeaponID = weaponID;
            window.curGraph.Init();
        }

        GetWindow<WeaponEditor>().Show();

        //EditorUtility.SetDirty(window.curGraph);
        //AssetDatabase.SaveAssets();
        //AssetDatabase.Refresh();

        return;
    }

    /// <summary>
    /// 打开Weapon
    /// </summary>
    private void LoadWeapon()
    {
        if (!Directory.Exists(WEAPON_PATH))
            Directory.CreateDirectory(WEAPON_PATH);

        string filename = EditorUtility.OpenFilePanel("Load Weapon File", WEAPON_PATH, "txt");

        if (string.IsNullOrEmpty(filename))
            return;

        ///打开武器编辑窗口
        Debug.Log("LoadWeapon filename = " + filename);
        weaponDataSetting.weaponID = GetMidStringToInt(filename, BASE_WEAPON_PATH, ".txt");
        Debug.Log(" weaponDataSetting.weaponID = " + weaponDataSetting.weaponID);
        weaponID = weaponDataSetting.weaponID;
        var window = GetWindow<WeaponEditor>();
        //if (window.curGraph == null) {
            window.curGraph = WeaponEditorUtil.LoadGraph(weaponID.ToString());
            window.curGraph.WeaponID = weaponID;
            window.curGraph.Init();
        //}

        GetWindow<WeaponEditor>().Show();

        //EditorUtility.SetDirty(window.curGraph);
        //AssetDatabase.SaveAssets();
        //AssetDatabase.Refresh();

        return;
    }

    private void OpenEditorWindow()
    {

    }

    private int GetMidStringToInt(string defString, string start,string end)
    {
        int temp = 0;
        string str = "";
        try {
            Regex rg = new Regex("(?<=(" + start + "))[.\\s\\S]*?(?=(" + end + "))", RegexOptions.Multiline | RegexOptions.Singleline);
            str = rg.Match(defString).Value;
        }
        catch {
            str = "000";
        }

        try {
            temp = Convert.ToInt32(str);
        }
        catch {

        }


        return temp;
    }
	#endregion private imp

	#region public interface
    /// <summary>
    /// 打开WeaponWindow
    /// </summary>
    /// <param name="title"></param>
	public static void Open(string title)
	{
		var window = GetWindow<WeaponWindow>(typeof(WeaponEditor));
		window.titleContent = new GUIContent(title);
		window.Show();
		return;
	}
	#endregion public interface
}
