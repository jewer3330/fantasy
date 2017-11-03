using UnityEngine;
using UnityEditor.Animations;
using UnityEditor;
using SLua;
using System;

namespace Assets.Editor.AnimatorEditor
{
    public class AEState
    {
        public string StateName = string.Empty;
        public string Suffix = string.Empty;
        public float Speed { get; set; }
        public string SpeedParameter = string.Empty;
        public string BehaviorName = string.Empty;
        public float X;
        public float Y;

        public void Draw()
        {
            EditorGUILayout.BeginVertical();
            EditorGUILayout.BeginHorizontal();
            EditorGUILayout.LabelField("StateName:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            StateName = EditorGUILayout.TextField(StateName, GUILayout.Width(AEConfig.TEXT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("PosX:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            X = EditorGUILayout.FloatField(X, GUILayout.Width(AEConfig.FLOAT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("PosY:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            Y = EditorGUILayout.FloatField(Y, GUILayout.Width(AEConfig.FLOAT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("AnimSuffix:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            Suffix = EditorGUILayout.TextField(Suffix, GUILayout.Width(AEConfig.TEXT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("Speed:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            Speed = EditorGUILayout.FloatField(Speed, GUILayout.Width(AEConfig.FLOAT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("SpeedParameter:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            SpeedParameter = EditorGUILayout.TextField(SpeedParameter, GUILayout.Width(AEConfig.TEXT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("BehaviorName:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            BehaviorName = EditorGUILayout.TextField(BehaviorName, GUILayout.Width(AEConfig.TEXT_COLUMN_WIDTH));
            EditorGUILayout.EndHorizontal();
            EditorGUILayout.EndVertical();
        }

        public AnimatorState Build(AnimatorStateMachine machine, string animBasePath)
        {
            // Load Animation
            AnimationClip clip = AEUtil.LoadAnimClip(string.Format("{0}_{1}.FBX", animBasePath, Suffix));

            AnimatorState state = AEUtil.GetStateByName(machine, StateName);

            // add tree state & set state motion
            if(null == state)
                state = machine.AddState(StateName);
            state.motion = clip;
            AEUtil.SetStatePosition(machine, state, new Vector3(X,Y,0f));

            if (Speed > 0f)
                state.speed = Speed;

            if (!string.IsNullOrEmpty(SpeedParameter))
            {
                state.speedParameterActive = true;
                state.speedParameter = SpeedParameter;
            }

            // 删除旧的behavior
            state.behaviours = new StateMachineBehaviour[0];
            // add LuaStateMachineBehavior
            if (!string.IsNullOrEmpty(BehaviorName))
            {
                var luaSmb = state.AddStateMachineBehaviour<LuaStateMachineBehavior>();
                luaSmb.filename = BehaviorName;
                luaSmb.curState = StateName;
            }
            
            return state;
        }

        public void ParseFromLua(IntPtr L, LuaTable table)
        {
            LuaUtil.TravelTable(L, table, (key, value) =>
            {
                if (key == "StateName")
                    StateName = value.ToString();
                else if (key == "PosX")
                    X = Convert.ToSingle(value);
                else if (key == "PosY")
                    Y = Convert.ToSingle(value);
                else if (key == "Suffix")
                    Suffix = value.ToString();
                else if (key == "Speed")
                    Speed = Convert.ToSingle(value);
                else if (key == "SpeedParameter")
                    SpeedParameter = value.ToString();
                else if (key == "BehaviorName")
                    BehaviorName = value.ToString();
            });
        }

        public void ExportToLua(ref string content)
        {
            content += "\t\t\t\t{ ";

            content += "StateName = \"" + StateName + "\", ";
            content += "PosX = " + X + ", ";
            content += "PosY = " + Y + ", ";
            if (!string.IsNullOrEmpty(Suffix))
                content += "Suffix = \"" + Suffix + "\", ";
            if (Speed > 0f)
                content += "Speed = " + Speed + ", ";
            if (!string.IsNullOrEmpty(SpeedParameter))
                content += "SpeedParameter = \"" + SpeedParameter + "\", ";
            if (!string.IsNullOrEmpty(BehaviorName))
                content += "BehaviorName = \"" + BehaviorName + "\", ";

            content += "},\n";// State End
        }
    }
}