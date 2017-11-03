using UnityEngine;
using System;
using System.Linq;
using UnityEditor;
using UnityEditor.Animations;

namespace Assets.Editor.AnimatorEditor
{

    public class AECondition
    {
        private static string[] conditionModes;
        private int selectedConditionIndex;
        public AnimatorConditionMode ConditionMode { get; set; }
        public float Threshold { get; set; }
        public string ParameterName = string.Empty;

        public void SetConditionMode(string value)
        {
            switch (value)
            {
                case "If":
                    ConditionMode = AnimatorConditionMode.If;
                    break;
                case "IfNot":
                    ConditionMode = AnimatorConditionMode.IfNot;
                    break;
                case "Greater":
                    ConditionMode = AnimatorConditionMode.Greater;
                    break;
                case "Less":
                    ConditionMode = AnimatorConditionMode.Less;
                    break;
                case "Equals":
                    ConditionMode = AnimatorConditionMode.Equals;
                    break;
                case "NotEqual":
                    ConditionMode = AnimatorConditionMode.NotEqual;
                    break;
                default:
                    AEUtil.CurCreator.RemoveNotification();
                    AEUtil.CurCreator.ShowNotification(new GUIContent(string.Format("Can't Find ConditionMode {0}", value)));
                    break;
            }
            selectedConditionIndex = GetIndexByMode(ConditionMode);
        }

        public void ParseFromJson(LitJson.JsonData data)
        {
                SetConditionMode(data["ConditionMode"].ToString());
                Threshold = Convert.ToSingle(data["Threshold"].ToString());
                ParameterName = data["ParameterName"].ToString();

        }


        public void ExportToLua(ref string content)
        {
            content += "\t\t\t\t\t\t{ ";

            content += "ConditionMode = \"" + ConditionMode + "\", ";
            content += "Threshold = " + Threshold + ", ";
            content += "ParameterName = \"" + ParameterName + "\", ";

            content += "},\n";// Condition End
        }

        public void Draw()
        {
            EditorGUILayout.BeginVertical();
            EditorGUILayout.BeginHorizontal();

            EditorGUILayout.LabelField("Condition Mode:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            if (conditionModes == null)
            {
                conditionModes = Enum.GetValues(typeof(AnimatorConditionMode)).Cast<AnimatorConditionMode>().Select(v => v.ToString()).ToArray();
            }
            selectedConditionIndex = EditorGUILayout.Popup(selectedConditionIndex, conditionModes.ToArray(), GUILayout.Width(AEConfig.POPUP_COLUMN_WIDTH));
            ConditionMode = GetConditionModeByIndex(selectedConditionIndex);

            EditorGUILayout.LabelField("Threshold:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            Threshold = EditorGUILayout.FloatField(Threshold, GUILayout.Width(AEConfig.FLOAT_COLUMN_WIDTH));

            EditorGUILayout.LabelField("ParameterName:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            ParameterName = EditorGUILayout.TextField(ParameterName, GUILayout.Width(AEConfig.TEXT_COLUMN_WIDTH));

            EditorGUILayout.EndHorizontal();
            EditorGUILayout.EndVertical();
        }

        private AnimatorConditionMode GetConditionModeByIndex(int index)
        {
            switch (index)
            {
                case 0:
                    return AnimatorConditionMode.If;
                case 1:
                    return AnimatorConditionMode.IfNot;
                case 2:
                    return AnimatorConditionMode.Greater;
                case 3:
                    return AnimatorConditionMode.Less;
                case 4:
                    return AnimatorConditionMode.Equals;
                case 5:
                    return AnimatorConditionMode.NotEqual;
                default:
                    return AnimatorConditionMode.If;
            }
        }

        private int GetIndexByMode(AnimatorConditionMode mode)
        {
            switch (mode)
            {
                case AnimatorConditionMode.If:
                    return 0;
                case AnimatorConditionMode.IfNot:
                    return 1;
                case AnimatorConditionMode.Greater:
                    return 2;
                case AnimatorConditionMode.Less:
                    return 3;
                case AnimatorConditionMode.Equals:
                    return 4;
                case AnimatorConditionMode.NotEqual:
                    return 5;
                default:
                    return 0;
            }
        }
    }
}
