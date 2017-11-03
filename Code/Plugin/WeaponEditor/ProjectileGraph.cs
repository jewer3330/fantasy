using System;
using System.IO;
using UnityEngine;
using UnityEditor;
[Serializable]
public class ProjectileGraph : ScriptableObject
{
    public static readonly string EXPORT_LUA_PATH = "Assets/Scripts/Slua/Resources/weapon/projectile/";
    public static readonly string EXPORT_NODE_PATH = "Assets/Scripts/Slua/Resources/prometheus/";
    public static readonly string EXPORT_CPP_PATH = "Assets/Editor Default Resources/Prometheus/";

    public static readonly string PROJECTILE_PATH = "WeaponEditor/Projectile/";
    public static readonly string PROJECTILE = "Projectile";
    public static readonly int PROJECTILE_LENGTH = PROJECTILE.Length;
    public static readonly string PLATO_TEMPLATE_BASEPATH = "Assets/Editor Default Resources/PLATO/WeaponTemplate/";
    public const int ID_MAX = UInt16.MaxValue;
    public const int ID_MIN = 50000;

    [SerializeField]
	public string assetName;
    private string editingProjName;
    private int editingPlatoId = -1;
    private SkillPhaseItem skillPhase = new SkillPhaseItem();

	public void Init(string projName)
	{        
        int nIndex = projName.LastIndexOf(PROJECTILE);
        if (nIndex >= 0)
        {
            editingPlatoId = Convert.ToInt32(projName.Substring(nIndex + PROJECTILE_LENGTH));
            if (editingPlatoId >= ID_MIN && editingPlatoId <= ID_MAX)
            {
                editingProjName = projName;
            }
            else
            {
                editingPlatoId = -1;
            }
        }
        if (editingPlatoId == -1)
        {
            throw new ArgumentException("projectile id error!");
        }
        else
        {
            skillPhase.Load(PLATO.PLATO_SAVE_PATH + PROJECTILE_PATH + editingProjName + ".txt");
        }
	}

    /// <summary>
    /// 绘制编辑界面
    /// </summary>
    /// <param name="wnd"></param>
	public void UpdateGUI(EditorWindow wnd)
    {
        GUILayout.BeginHorizontal();
        if (GUILayout.Button("Save", GUILayout.MaxWidth(100))) {
            string platoPath = string.Format("{0}{1}{2}.txt", PLATO.PLATO_SAVE_PATH, PROJECTILE_PATH, editingProjName);
            skillPhase.Save(platoPath);
        }
        if (GUILayout.Button("Export", GUILayout.MaxWidth(100)))
        {
            string luatPath = string.Format("{0}{1}.txt", EXPORT_LUA_PATH, editingProjName);
            skillPhase.ExportLua(luatPath);
#if PLATO_CS_DEBUG
            skillPhase.ExportCSharp(Path.Combine(Path.Combine(PLATO.CSHARP_SAVE_PATH, "Projectile"), editingProjName) + ".cs");
#endif
        }
        if (GUILayout.Button("New", GUILayout.MaxWidth(100)))
        {
            string filename = EditorUtility.SaveFilePanel("New Projectile File", PROJECTILE_PATH, PROJECTILE, "txt");
            if (!string.IsNullOrEmpty(filename))
            {
                StreamWriter writer = new StreamWriter(filename, false, System.Text.Encoding.UTF8);
                writer.Close();
                Init(Path.GetFileNameWithoutExtension(filename));
            }
        }
        if (GUILayout.Button("Load", GUILayout.MaxWidth(100)))
        {
            string filename = EditorUtility.OpenFilePanel("Load Projectile File", PROJECTILE_PATH, "txt");
            if(!string.IsNullOrEmpty(filename))
            {
                Init(Path.GetFileNameWithoutExtension(filename));
            }
        }
        if (GUILayout.Button("Comment", GUILayout.MaxWidth(100)))
        {
            skillPhase.Comment();
        }
        GUILayout.FlexibleSpace();
        GUILayout.EndHorizontal();
        GUILayout.BeginHorizontal();
        GUILayout.Label("PLATO ID:" + editingPlatoId, GUILayout.Width(200));
        GUILayout.EndHorizontal();

        skillPhase.UpdateGUI(wnd, 100);
    }
}
