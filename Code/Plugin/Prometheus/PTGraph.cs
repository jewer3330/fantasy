using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEditor;
using Assets.Editor.AnimatorEditor;

[Serializable]
public class PTGraph : ScriptableObject
{
    public static readonly string EXPORT_LUA_PATH = "Assets/Scripts/Slua/Resources/prometheus";
    public static readonly string EXPORT_WEAPON_LUA_PATH = "Assets/Scripts/Slua/Resources/weapon";
    public static readonly string EXPORT_PROJECTILE_LUA_PATH = "Assets/Scripts/Slua/Resources/weapon/projectile/";
    public static readonly string EXPORT_CSHARP_PATH = "Assets/Scripts/Plato/Export/Skill";
    public static readonly string EXPORT_WEAPON_CSHARP = "Assets/Scripts/Plato/Export/Weapon";
    public static readonly string EXPORT_PROJECTILE_CSHARP_PATH = "Assets/Scripts/Plato/Export/Projectile/";
    public static readonly string EXPORT_CPP_PATH = "Assets/Editor Default Resources/prometheus";

	[SerializeField]
	public string assetName;

	public List<PTOneSkill> skillPhaseList = new List<PTOneSkill>();
    //public List<Skill> skillData = new List<Skill>();
    private string[] skillNames;
    private int skillIndex = 0;
	private Dictionary<string, string> typeKeyValue = new Dictionary<string, string>();
	public int characterID = 0;
	protected int originHeight = 30;

    //private struct Skill
    //{
    //    public int id;
    //    public string name;
    //}

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
        if (!typeKeyValue.ContainsKey("System.Int32[]"))
            typeKeyValue.Add("System.Int32[]", "int[]");
		foreach(var item in skillPhaseList)
		{
			item.Load();
		}
        UpdateSkillNames();
        isPreviewMacro = false;
	}

    private bool isHideAnimation;
    private bool isPreviewMacro;

	public void UpdateGUI(EditorWindow wnd)
	{
		GUILayout.BeginHorizontal();
        EditorGUI.BeginDisabledGroup(isPreviewMacro);
        if (GUILayout.Button("Save", GUILayout.MaxWidth(100))) {
            foreach(var item in skillPhaseList)
            {
                item.Save();
            }

            EditorUtility.SetDirty(this);
            AssetDatabase.SaveAssets();
            AssetDatabase.Refresh();
        }
        if (GUILayout.Button("Export", GUILayout.MaxWidth(100))) {
            ExportToLua();
#if PLATO_CS_DEBUG
            ExportToCSharp();
#endif //PLATO_CS_DEBUG
            ExportNode();
            ExportToCpp();
            ExportComponentToCpp();
        }
        if(GUILayout.Button("ExportSkillAnim", GUILayout.MaxWidth(100)))
        {
            AEUtil.AddSkillStates(PTCharacterWindow.curCharacter, skillPhaseList, PrometheusUtil.curCharacterType);
        }
        if (GUILayout.Button("Comment", GUILayout.MaxWidth(100)))
        {
            skillPhaseList[skillIndex].Comment();
        }
        EditorGUI.EndDisabledGroup();
        isHideAnimation = GUILayout.Toggle(isHideAnimation, "Hide Animation");
        bool value = GUILayout.Toggle(isPreviewMacro, "预览宏展开");
        if (value != isPreviewMacro)
        {
            if (value)
            {
                foreach(var item in skillPhaseList)
                {
                    item.PhaseItem.preview = new PLATO(item.PhaseItem.plato);
                    PLATO.ExpandMacro(item.PhaseItem.preview);
                }
            }
            else
            {
                foreach(var item in skillPhaseList)
                {
                    item.PhaseItem.preview = null;
                }
            }
        }
        isPreviewMacro = value;

		GUILayout.FlexibleSpace();
		GUILayout.EndHorizontal();

        if (skillNames == null)
            return;

        GUILayout.Label("Skills");
        int oldIndex = skillIndex;
        skillIndex = GUILayout.Toolbar(skillIndex, skillNames);
        if (oldIndex != skillIndex && skillPhaseList.Count > oldIndex)
        {
            if (AnimationMode.InAnimationMode())
                AnimationMode.StopAnimationMode();
            skillPhaseList[oldIndex].UnloadFX();
        }
        if(skillPhaseList.Count > skillIndex)
        {
	        if (!isHideAnimation)
	            skillPhaseList[skillIndex].UpdateGUI(wnd);
	        skillPhaseList[skillIndex].PhaseItem.UpdateGUI(wnd, isHideAnimation ? 75 : 420);
		}
	}

	/// <summary>
	/// 导出每个节点
	/// </summary>
	private void ExportComponentToCpp()
	{
		if (skillPhaseList == null)
			return;

        foreach (PTOneSkill skill in skillPhaseList)
        {
            SkillPhaseItem.ExportComponentToCpp(skill.PhaseItem.plato);
        }
	}

	/// <summary>
	/// 导出Cpp
	/// </summary>
	private void ExportToCpp()
	{
		if (skillPhaseList == null)
			return;

        foreach (PTOneSkill skill in skillPhaseList)
        {
            SkillPhaseItem.ExportCpp(skill.PhaseItem.plato, skill.DataSetting.skillID, skill.DataSetting);
        }
	}

	/// <summary>
	/// 导出Lua
	/// </summary>
	private void ExportToLua()
	{   
		if(skillPhaseList == null)
			return;

		foreach (PTOneSkill item in skillPhaseList) {
            string filename = string.Format("{0}/{1}{2}.txt", EXPORT_LUA_PATH, "SkillScript", item.DataSetting.skillID);
            item.PhaseItem.ExportLua(filename);
		}
	}

    private void ExportToCSharp()
    {
		if(skillPhaseList == null)
			return;

		foreach (PTOneSkill item in skillPhaseList) {
            string filename = string.Format("{0}/{1}{2}.cs", EXPORT_CSHARP_PATH, "SkillScript", item.DataSetting.skillID);
            item.PhaseItem.ExportCSharp(filename);
		}
    }

    private void ExportNode()
    {
        if (skillPhaseList == null)
            return;

        foreach (PTOneSkill item in skillPhaseList)
        {
            SkillPhaseItem.ExportNode(item.PhaseItem.plato, item.DataSetting.skillID);
        }
    }

	public bool AddSkillPhase(string mPath, SkilldataSetting dataSetting)
    {
        if (!skillPhaseList.Exists(x => x.DataSetting.skillID == dataSetting.skillID))
		{
            var item = new PTOneSkill {modelPath = mPath, SkillIndex = skillPhaseList.Count, DataSetting = dataSetting };
			skillPhaseList.Add(item);
            UpdateSkillNames();
			return true;
		}

        //改 skill name
        if (string.IsNullOrEmpty(skillPhaseList[dataSetting.skillIndex].DataSetting.skillName))
            skillNames[dataSetting.skillIndex] = skillPhaseList[dataSetting.skillIndex].DataSetting.skillID.ToString();
        else
            skillNames[dataSetting.skillIndex] = skillPhaseList[dataSetting.skillIndex].DataSetting.skillName;

		return false;
	}

	public void RemoveSkillPhase(int skillId)
	{
        skillPhaseList.RemoveAll(x => x.DataSetting.skillID == skillId);
        UpdateSkillNames();
	}

	public void ClearSkillList()
	{
		skillPhaseList.Clear();
        skillNames = null;
	}


    public void ClearSkillData()
    {
        //skillData.Clear();
    }

    public void UpdateSkillNames()
    {
        skillNames = new string[skillPhaseList.Count];
        for (int i = 0; i < skillPhaseList.Count; ++i)
        {
            if (string.IsNullOrEmpty(skillPhaseList[i].DataSetting.skillName))
                skillNames[i] = skillPhaseList[i].DataSetting.skillID.ToString();
            else
                skillNames[i] = skillPhaseList[i].DataSetting.skillName;
        }
    }
}










