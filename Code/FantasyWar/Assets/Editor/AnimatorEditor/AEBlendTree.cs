using UnityEngine;
using System;
using System.Collections.Generic;
using UnityEditor.Animations;
using UnityEditor;

namespace Assets.Editor.AnimatorEditor
{
    public class AEBlendTree
    {
        public string StateName { get; set; }
        public float Speed;
        public string SpeedParameter;
        public string BehaviorName = string.Empty;
        public BlendTreeType BlendType { get; set; }
        public string[] Suffixs = null;
        public string[] Parameters = null;
        public List<List<float>> ParameterValues = new List<List<float>>();
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
            EditorGUILayout.LabelField("Speed:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            Speed = EditorGUILayout.FloatField(Speed, GUILayout.Width(AEConfig.FLOAT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("SpeedParameter:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            SpeedParameter = EditorGUILayout.TextField(SpeedParameter, GUILayout.Width(AEConfig.TEXT_COLUMN_WIDTH));
            EditorGUILayout.LabelField("BehaviorName:", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            BehaviorName = EditorGUILayout.TextField(BehaviorName, GUILayout.Width(AEConfig.TEXT_COLUMN_WIDTH));
            
            EditorGUILayout.EndHorizontal();
            EditorGUILayout.EndVertical();
        }

        public void SetBlendType(string type)
        {
            switch (type)
            {
                case "Simple1D":
                    BlendType = BlendTreeType.Simple1D;
                    break;
                case "SimpleDirectional2D":
                    BlendType = BlendTreeType.SimpleDirectional2D;
                    break;
                case "FreeformDirectional2D":
                    BlendType = BlendTreeType.FreeformDirectional2D;
                    break;
                case "FreeformCartesian2D":
                    BlendType = BlendTreeType.FreeformCartesian2D;
                    break;
                default:
                    BlendType = BlendTreeType.Simple1D;
                    break;
            }
        }

        public void ParseFromJson(LitJson.JsonData data)
        {
                StateName = data["StateName"].ToString();
                X = Convert.ToSingle(data["PosX"].ToString());
                Y = Convert.ToSingle(data["PosY"].ToString());
                Speed = Convert.ToSingle(data["Speed"].ToString());
                SpeedParameter = data["SpeedParameter"].ToString();
                BehaviorName = data["BehaviorName"].ToString();
                SetBlendType(data["BlendType"].ToString());
                SetSuffixs(data["Suffixs"].ToString());
                SetParameters(data["Parameters"].ToString());
                SetParameterValues(data["ParameterValues"].ToString());

        }
      
        public void ExportToLua(ref string content)
        {
            content += "\t\t\t\t{\n";

            content += "\t\t\t\t\tStateName = \"" + StateName + "\", \n";
            content += "\t\t\t\t\tPosX = " + X + ", \n";
            content += "\t\t\t\t\tPosY = " + Y + ", \n";
            content += "\t\t\t\t\tSpeed = " + Speed + ", \n";
            content += "\t\t\t\t\tSpeedParameter= \"" + SpeedParameter+ "\", \n";
            content += "\t\t\t\t\tBehaviorName = \"" + BehaviorName + "\", \n";
            content += "\t\t\t\t\tBlendType = \"" + BlendType + "\", \n";
            content += "\t\t\t\t\tSuffixs = \"";
            for (int i = 0; i < Suffixs.Length; i++)
            {
                content += Suffixs[i];
                if (i != Suffixs.Length - 1)
                    content += ";";
            }
            content += "\",\n";// Suffixs End

            content += "\t\t\t\t\tParameters = \"";
            for (int i = 0; i < Parameters.Length; i++)
            {
                content += Parameters[i];
                if (i != Parameters.Length - 1)
                    content += ";";
            }
            content += "\",\n";// Parameters End

            content += "\t\t\t\t\tParameterValues = \"";
            for (int i = 0; i < ParameterValues.Count; i++)
            {
                for (int j = 0; j < ParameterValues[i].Count; j++)
                {
                    content += ParameterValues[i][j];
                    if(j != ParameterValues[i].Count - 1)
                        content += ":";
                }
                if (i != ParameterValues.Count - 1)
                    content += ";";
            }
            content += "\",\n";// ParameterValues End

            content += "\t\t\t\t},\n";// State End
        }

        public AnimatorState Build(AnimatorStateMachine machine, string animBasePath, AnimatorController productController)
        {
            // create a tree
            BlendTree tree = new BlendTree();
            // Set blendtree parameters
            tree.name = StateName;
            tree.blendType = BlendType;
            if(Parameters.Length > 1)
            {
                tree.useAutomaticThresholds = true;
                tree.minThreshold = 0f;
                tree.maxThreshold = 1f;
                tree.blendParameter = Parameters[0];
                tree.blendParameterY = Parameters[1];
            }
            if((BlendType == BlendTreeType.Simple1D && ParameterValues.Count > 1) ||
                (BlendType != BlendTreeType.Simple1D && ParameterValues.Count <= 1) ||
                (BlendType != BlendTreeType.Simple1D && ParameterValues[0].Count != Suffixs.Length))
            {
                AEUtil.ShowNotification("BlendTree Parameters Error");
                return null;
            }

            if(BlendType == BlendTreeType.Simple1D)
            {
                for (int i = 0; i < Suffixs.Length; i++)
                {
                    // Load Animation
                    AnimationClip clip = AEUtil.LoadAnimClip(string.Format("{0}_{1}.FBX", animBasePath, Suffixs[i]));
                    // Add clip to BlendTree
                    tree.AddChild(clip, new Vector2(ParameterValues[0][i], 1f));
                }
            }
            else
            {
                for (int i = 0; i < Suffixs.Length; i++)
                {
                    // Load Animation
                    AnimationClip clip = AEUtil.LoadAnimClip(string.Format("{0}_{1}.FBX", animBasePath, Suffixs[i]));
                    // Add clip to BlendTree
                    tree.AddChild(clip, new Vector2(ParameterValues[0][i], ParameterValues[1][i]));
                }
            }

            AnimatorState state = AEUtil.GetStateByName(machine, tree.name);
            // add tree state & set state motion
            if(state == null)
                state = machine.AddState(tree.name);
            state.motion = tree;
            
            AEUtil.SetStatePosition(machine, state, new Vector3(X,Y,0f));
            if (Speed > 0f)
                state.speed = Speed;

            if (!string.IsNullOrEmpty(SpeedParameter))
            {
                state.speedParameterActive = true;
                state.speedParameter = SpeedParameter;
            }

            // add LuaStateMachineBehavior
            if (!string.IsNullOrEmpty(BehaviorName))
            {
                var luaSmb = state.AddStateMachineBehaviour<CustomStateMachineBehavior>();
                luaSmb.filename = BehaviorName;
                luaSmb.curState = StateName;
            }

            // Add tree to controller asset
            if (AssetDatabase.GetAssetPath(productController) != string.Empty)
            {
                AssetDatabase.AddObjectToAsset(tree, AssetDatabase.GetAssetPath(productController));
            }
            return state;
        }

        public void SetSuffixs(string suffixs)
        {
            Suffixs = suffixs.Split(';');
        }

        public void SetParameters(string parameters)
        {
            Parameters = parameters.Split(';');
        }

        public void SetParameterValues(string parameterValues)
        {
            string[] rows = parameterValues.Split(';');
            for (int i = 0; i < rows.Length; i++)
            {
                string[] cols = rows[i].Split(':');
                List<float> values = new List<float>();
                for (int j = 0; j < cols.Length; j++)
                {
                    values.Add(Convert.ToSingle(cols[j]));
                }
                ParameterValues.Add(values);
            }
        }
    }
}
