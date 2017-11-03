using UnityEngine;
using System.Collections;
using System;
using UnityEditor;
using System.Linq;
using SLua;

namespace Assets.Editor.AnimatorEditor
{
    public class AEParameter
    {
        private string[] parameterTypes;
        private int selectedIndex = 0;

        public string ParameterName = string.Empty;

        public AnimatorControllerParameterType ParameterType = AnimatorControllerParameterType.Trigger;
        private AnimatorControllerParameterType oldType = AnimatorControllerParameterType.Int;
        public object DefaultValue;

        public void SetParameterType(string value)
        {
            switch (value)
            {
                case "Float":
                    ParameterType = AnimatorControllerParameterType.Float;
                    break;
                case "Int":
                    ParameterType = AnimatorControllerParameterType.Int;
                    break;
                case "Bool":
                    ParameterType = AnimatorControllerParameterType.Bool;
                    break;
                case "Trigger":
                    ParameterType = AnimatorControllerParameterType.Trigger;
                    break;
            }
            selectedIndex = GetIndexByType(ParameterType);
            oldType = ParameterType;
        }

        public void ParseFromLua(IntPtr L, LuaTable table)
        {
            LuaUtil.TravelTable(L, table, (key, value) =>
            {
                if (key == "ParameterName")
                    ParameterName = value.ToString();
                else if (key == "Type")
                    SetParameterType(value.ToString());
                else if (key == "DefaultValue")
                    DefaultValue = value;
            });
        }

        public void ExportToLua(ref string content)
        {
            content += "\t\t{ ParameterName = \"" + ParameterName + "\"";
            content += ", Type = \"" + ParameterType + "\"";
            if (DefaultValue != null)
            {
                if (DefaultValue is Boolean)
                    content += ", DefaultValue = " + DefaultValue.ToString().ToLower();
                else
                    content += ", DefaultValue = " + DefaultValue;
            }
                
            content += " },\n";
        }

        public void Draw()
        {
            EditorGUILayout.BeginHorizontal();
            EditorGUILayout.LabelField("Parameter Type:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            if (parameterTypes == null)
            {
                parameterTypes = Enum.GetValues(typeof(AnimatorControllerParameterType)).Cast<AnimatorControllerParameterType>().Select(v => v.ToString()).ToArray();
            }
            selectedIndex = EditorGUILayout.Popup(selectedIndex, parameterTypes.ToArray(),
                GUILayout.Width(AEConfig.POPUP_COLUMN_WIDTH),
                GUILayout.Height(AEConfig.LINE_HEIGHT));
            ParameterType = GetTypeByIndex(selectedIndex);
            if(oldType != ParameterType)
            {
                EditorWindow.focusedWindow.Repaint();
                oldType = ParameterType;
                DefaultValue = InitDefaultValueByType(ParameterType);
                return;
            }
            EditorGUILayout.LabelField("Parameter Name:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            ParameterName = EditorGUILayout.TextField(ParameterName, GUILayout.Width(AEConfig.TEXT_COLUMN_WIDTH));
            if(DefaultValue != null)
            {
                EditorGUILayout.LabelField("Default Value:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
                switch (ParameterType)
                {
                    case AnimatorControllerParameterType.Float:
                        DefaultValue = EditorGUILayout.FloatField(Convert.ToSingle(DefaultValue), GUILayout.Width(AEConfig.FLOAT_COLUMN_WIDTH));
                        break;
                    case AnimatorControllerParameterType.Int:
                        DefaultValue = EditorGUILayout.IntField(Convert.ToInt32(DefaultValue), GUILayout.Width(AEConfig.INT_COLUMN_WIDTH));
                        break;
                    case AnimatorControllerParameterType.Bool:
                        DefaultValue = EditorGUILayout.Toggle(Convert.ToBoolean(DefaultValue), GUILayout.Width(AEConfig.BOOL_COLUMN_WIDTH));
                        break;
                    case AnimatorControllerParameterType.Trigger:
                        break;
                    default:
                        break;
                }
            }
            
            
            EditorGUILayout.EndHorizontal();
        }

        private AnimatorControllerParameterType GetTypeByIndex(int index)
        {
            switch (index)
            {
                case 0:
                    return AnimatorControllerParameterType.Float;
                case 1:
                    return AnimatorControllerParameterType.Int;
                case 2:
                    return AnimatorControllerParameterType.Bool;
                case 3:
                    return AnimatorControllerParameterType.Trigger;
                default:
                    return AnimatorControllerParameterType.Float;
            }
        }

        private int GetIndexByType(AnimatorControllerParameterType type)
        {
            switch (type)
            {
                case AnimatorControllerParameterType.Float:
                    return 0;
                case AnimatorControllerParameterType.Int:
                    return 1;
                case AnimatorControllerParameterType.Bool:
                    return 2;
                case AnimatorControllerParameterType.Trigger:
                    return 3;
                default:
                    return 0;
            }
        }

        private object InitDefaultValueByType(AnimatorControllerParameterType type)
        {
            switch (type)
            {
                case AnimatorControllerParameterType.Float:
                    return 0.0f;
                case AnimatorControllerParameterType.Int:
                    return 0;
                case AnimatorControllerParameterType.Bool:
                    return false;
                case AnimatorControllerParameterType.Trigger:
                    return null;
                default:
                    return null;
            }
        }
    }
}