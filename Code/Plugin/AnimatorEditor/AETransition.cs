using UnityEngine;
using System;
using System.Linq;
using UnityEditor;
using System.Collections.Generic;
using SLua;

namespace Assets.Editor.AnimatorEditor
{
    public enum TransitionType
    {
        Normal,
        Entry,
        Exit,
        AnyState,
        All,
    }

    public class AETransition
    {
        private string[] transitionTypes;
        private int selectedConditionIndex;

        public TransitionType Type { get; set; }
        public string FromStateName = string.Empty;
        public string ToStateName = string.Empty;
        public float ExitTime;
        public float Duration;
        public float Offset;
        public bool CanTransitionToSelf;
        public List<AECondition> Conditions = new List<AECondition>();

        public void SetTransitionType(string value)
        {
            switch (value)
            {
                case "Normal":
                    Type = TransitionType.Normal;
                    break;
                case "Entry":
                    Type = TransitionType.Entry;
                    break;
                case "Exit":
                    Type = TransitionType.Exit;
                    break;
                case "AnyState":
                    Type = TransitionType.AnyState;
                    break;
                case "All":
                    Type = TransitionType.All;
                    break;
                default:
                    AEUtil.ShowNotification(string.Format("Can't Find Transition type {0}", value));
                    break;
            }
        }

        public void ParseFromLua(IntPtr L, LuaTable table)
        {
            LuaUtil.TravelTable(L, table, (key, value) =>
            {
                if (key == "Type")
                    SetTransitionType(value.ToString());
                else if (key == "FromStateName")
                    FromStateName = value.ToString();
                else if (key == "ToStateName")
                    ToStateName = value.ToString();
                else if (key == "ExitTime")
                    ExitTime = Convert.ToSingle(value);
                else if (key == "Duration")
                    Duration = Convert.ToSingle(value);
                else if (key == "CanTransitionToSelf")
                    CanTransitionToSelf = Convert.ToBoolean(value);
                else if (key == "Conditions")
                    ParseConditions(L, value as LuaTable);
            });
        }

        private void ParseConditions(IntPtr L, LuaTable table)
        {
            LuaUtil.TravelTable(L, table, (key, value) =>
            {
                AECondition condition = new AECondition();
                condition.ParseFromLua(L, value as LuaTable);
                Conditions.Add(condition);
            });
        }

        public void ExportToLua(ref string content)
        {
            content += "\t\t\t\t{ ";

            content += "Type = \"" + Type + "\", ";
            if (!string.IsNullOrEmpty(FromStateName))
                content += "FromStateName = \"" + FromStateName + "\", ";
            if (!string.IsNullOrEmpty(ToStateName))
                content += "ToStateName = \"" + ToStateName + "\", ";
            if (ExitTime > 0f)
                content += "ExitTime = " + ExitTime + ", ";
            if (Duration > 0f)
                content += "Duration = " + Duration + ", ";
            if (Offset > 0f)
                content += "Offset = " + Offset + ", ";
            if (Type == TransitionType.AnyState)
                content += "CanTransitionToSelf = " + CanTransitionToSelf.ToString().ToLower() + ", ";

            if (Type != TransitionType.Entry)
            {
                content += "\n";
                content += "\t\t\t\t\tConditions = {\n";
                for (int i = 0; i < Conditions.Count; i++)
                {
                    Conditions[i].ExportToLua(ref content);
                }
                content += "\t\t\t\t\t},\n";// Conditions End
            }

            if(Conditions.Count > 0)
                content += "\t\t\t\t},\n";// Transition End
            else
                content += "},\n";// Transition End
        }

        public void Draw()
        {
            EditorGUILayout.BeginVertical("window");
            EditorGUILayout.BeginHorizontal();

            EditorGUILayout.LabelField("Transition Type:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            if (transitionTypes == null)
            {
                transitionTypes = Enum.GetValues(typeof(TransitionType)).Cast<TransitionType>().Select(v => v.ToString()).ToArray();
            }
            Type = (TransitionType)EditorGUILayout.Popup((int)Type, transitionTypes.ToArray(), GUILayout.Width(AEConfig.POPUP_COLUMN_WIDTH));

            EditorGUILayout.LabelField("FromState:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            FromStateName = EditorGUILayout.TextField(FromStateName, GUILayout.Width(AEConfig.TEXT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("ToState:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            ToStateName = EditorGUILayout.TextField(ToStateName, GUILayout.Width(AEConfig.TEXT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("ExitTime:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            ExitTime = EditorGUILayout.FloatField(ExitTime, GUILayout.Width(AEConfig.FLOAT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("Duration:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            Duration = EditorGUILayout.FloatField(Duration, GUILayout.Width(AEConfig.FLOAT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("Offset:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            Offset = EditorGUILayout.FloatField(Offset, GUILayout.Width(AEConfig.FLOAT_COLUMN_WIDTH));

            if (Type == TransitionType.AnyState)
            {
                EditorGUILayout.LabelField("CanTansitToSelf", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
                CanTransitionToSelf = EditorGUILayout.Toggle(CanTransitionToSelf, GUILayout.Width(AEConfig.TOGGLE_COLUMN_WIDTH));
            }

            EditorGUILayout.EndHorizontal();

            if (Type != TransitionType.Entry)
            {
                DrawConditions();
            }
            EditorGUILayout.Space();

            EditorGUILayout.EndVertical();
        }

        private void DrawConditions()
        {
            EditorGUILayout.BeginVertical("box");
            EditorGUILayout.LabelField("Conditions", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            for (int i = 0; i < Conditions.Count; i++)
            {
                Conditions[i].Draw();
            }
            EditorGUILayout.EndVertical();
        }
    }
}
