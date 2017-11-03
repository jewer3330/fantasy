using UnityEngine;
using UnityEditor;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System;

public class PrometheusGeneralSkill : EditorWindow
{
    [SerializeField]
    private int editingPlatoId = -1;
    private SkillPhaseItem skillPhase = new SkillPhaseItem();

    const string SavePath = "Assets/Editor Default Resources/PLATO/CommonSkill/";

    public void Init(int id)
    {
        editingPlatoId = id;
        if (editingPlatoId == -1)
        {
            throw new ArgumentException("skill id error!");
        }
        else
        {
            skillPhase.Load(string.Format("{0}SkillScript{1}.txt", SavePath, editingPlatoId));
        }
    }
    
	private void OnGUI()
    {
        GUILayout.BeginHorizontal();
        if (GUILayout.Button("Save", GUILayout.MaxWidth(100)))
        {
            string platoPath = string.Format("{0}SkillScript{1}.txt", SavePath, editingPlatoId);
            skillPhase.Save(platoPath);
        }
        if (GUILayout.Button("Export", GUILayout.MaxWidth(100)))
        {
            string luatPath = string.Format("{0}/SkillScript{1}.txt", PTGraph.EXPORT_LUA_PATH, editingPlatoId);
            skillPhase.ExportLua(luatPath);
#if PLATO_CS_DEBUG
            string csPath = string.Format("{0}/SkillScript{1}.cs", PTGraph.EXPORT_CSHARP_PATH, editingPlatoId);
            skillPhase.ExportCSharp(csPath);
#endif
            SkillPhaseItem.ExportCpp(skillPhase.plato, editingPlatoId, null);
            SkillPhaseItem.ExportNode(skillPhase.plato, editingPlatoId);
            SkillPhaseItem.ExportComponentToCpp(skillPhase.plato);
        }
        if (GUILayout.Button("New", GUILayout.MaxWidth(100)))
        {
            string filename = EditorUtility.SaveFilePanel("New Skill File", SavePath, "SkillScript49999", "txt");
            if (filename != null && filename != "")
            {
                StreamWriter writer = new StreamWriter(filename, false, System.Text.Encoding.UTF8);
                writer.Close();
                Init(GetIdFromFileName(filename));
            }
        }
        if (GUILayout.Button("Load", GUILayout.MaxWidth(100)))
        {
            string filename = EditorUtility.OpenFilePanel("Load Skill File", SavePath, "txt");
            if (filename != null && filename != "")
            {
                Init(GetIdFromFileName(filename));
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

        skillPhase.UpdateGUI(this, 100);
    }
    int GetIdFromFileName(string fileName)
    {
        const string prefix = "SkillScript";
        string fileNameOnly = Path.GetFileNameWithoutExtension(fileName);
        string index = fileNameOnly.Substring(prefix.Length, fileNameOnly.Length - prefix.Length);
        int _index;
        int.TryParse(index, out _index);
        return _index;
    }
}