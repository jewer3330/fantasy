using UnityEngine;
using System.Collections.Generic;
using System;
using System.IO;
using System.Linq;
using UnityEditor.Animations;
using UnityEditor;

namespace Assets.Editor.AnimatorEditor
{
    public class AETemplate
    {
        private Vector2 scrollPosition;
        private static readonly string[] CullingModes = {"AlwaysAnimate", "CullUpdateTransforms", "CullCompletely"};
        private int selectedIndex;

        public AnimatorCullingMode cullingMode;
        public List<AELayer> Layers = new List<AELayer>();
        public List<AEParameter> Parameters = new List<AEParameter>();

        public void SetCullingMode(string value)
        {
            switch (value)
            {
                case "AlwaysAnimate":
                    cullingMode = AnimatorCullingMode.AlwaysAnimate;
                    break;
                case "CullUpdateTransforms":
                    cullingMode = AnimatorCullingMode.CullUpdateTransforms;
                    break;
                case "CullCompletely":
                    cullingMode = AnimatorCullingMode.CullCompletely;
                    break;
            }
            selectedIndex = GetIndexByMode(cullingMode);
        }

        private static int GetIndexByMode(AnimatorCullingMode animatorCullingMode)
        {
            switch (animatorCullingMode)
            {
                case AnimatorCullingMode.AlwaysAnimate:
                    return 0;
                case AnimatorCullingMode.CullUpdateTransforms:
                    return 1;
                case AnimatorCullingMode.CullCompletely:
                    return 2;
                default:
                    return 0;
            }
        }

        private static AnimatorCullingMode GetModeByIndex(int index)
        {
            switch (index)
            {
                case 0:
                    return AnimatorCullingMode.AlwaysAnimate;
                case 1:
                    return AnimatorCullingMode.CullUpdateTransforms;
                case 2:
                    return AnimatorCullingMode.CullCompletely;
                default:
                    return AnimatorCullingMode.AlwaysAnimate;
            }
        }

        private static string GetModeString(AnimatorCullingMode cullingMode)
        {
            switch (cullingMode)
            {
                case AnimatorCullingMode.AlwaysAnimate:
                    return "AlwaysAnimate";
                case AnimatorCullingMode.CullUpdateTransforms:
                    return "CullUpdateTransforms";
                case AnimatorCullingMode.CullCompletely:
                    return "CullCompletely";
                default:
                    return "AlwaysAnimate";
            }
        }

        public void Draw(EditorWindow wnd)
        {
            Color oldColor = GUI.color;
            GUI.color = AEConfig.TEMPLATE_COLOR;

            EditorGUILayout.BeginVertical();
            scrollPosition = GUI.BeginScrollView(
                  new Rect() { x = 0f, y = AEConfig.SCROLL_HEIGHT_OFFSET, width = wnd.position.width, height = wnd.position.height - AEConfig.SCROLL_HEIGHT_OFFSET },
                  scrollPosition,
                  new Rect(0, AEConfig.SCROLL_HEIGHT_OFFSET - 20f, AEConfig.SCROLL_WIDTH, AEConfig.SCROLL_HEIGHT),
                  true,
                  true);
            EditorGUILayout.BeginVertical("window");
            EditorGUILayout.LabelField("Animator");

            // culling mode
            EditorGUILayout.BeginHorizontal();
            EditorGUILayout.LabelField("CullingMode :", GUILayout.Width(AEConfig.LABEL_COLUMN_WIDTH));
            selectedIndex = EditorGUILayout.Popup(selectedIndex, CullingModes.ToArray(),
                GUILayout.Width(AEConfig.POPUP_COLUMN_WIDTH),
                GUILayout.Height(AEConfig.LINE_HEIGHT));
            cullingMode = GetModeByIndex(selectedIndex);
            EditorGUILayout.EndHorizontal();

            DrawParameters();
            EditorGUILayout.Space();
            DrawLayers();
            EditorGUILayout.Space();

            EditorGUILayout.EndVertical();
            EditorGUILayout.EndScrollView();
            EditorGUILayout.EndVertical();

            GUI.color = oldColor;
        }

        public void ParseFromJson(LitJson.JsonData data)
        {
            ParseLayers(data["Layers"]);
            SetCullingMode(data["CullingMode"].ToString());
            ParseParameters(data["Parameters"]);
        }

        
        private void ParseLayers(LitJson.JsonData data)
        {
            AELayer layer = new AELayer();
            layer.ParseFromJson(data);
            Layers.Add(layer);
        }

        private void ParseParameters(LitJson.JsonData data)
        {
            AEParameter parameter = new AEParameter();
            parameter.ParseFromJson(data);
            Parameters.Add(parameter);
        }

        public void Save(string fileName)
        {

            string content = String.Empty;
            string tableName = Path.GetFileNameWithoutExtension(fileName);
            content += "local " + tableName + " = {\n";

            content += "\tCullingMode = \"" + GetModeString(cullingMode) + "\",\n";
            content += "\t";
            content += "Parameters = {\n";
            for (int i = 0;i < Parameters.Count;i++)
            {
                Parameters[i].ExportToLua(ref content);
            }
            content += "\t";
            content += "},\n";// Parameters End

            content += "\t";
            content += "Layers = {\n";
            for (int i = 0;i < Layers.Count;i++)
            {
                Layers[i].ExportToLua(ref content);
            }
            content += "\t";
            content += "},\n";// Layers End

            content += "}";//Table End
            content += "\n\n";

            content += "\nreturn " + tableName;
            bool ret = FileUtilTool.WriteFile(fileName, content);
            if (ret)
            {
                AEUtil.ShowNotification("Save Success");
            }
        }

        public void SaveInstance(PTCharacterType type, string index)
        {
            string content = String.Empty;
            string tableName = type + index + "Animator";
            content += "local " + tableName + " = {\n";

            content += "\tCullingMode = \"" + GetModeString(cullingMode) + "\",\n";
            content += "\t";
            content += "Parameters = {\n";
            for (int i = 0;i < Parameters.Count;i++)
            {
                Parameters[i].ExportToLua(ref content);
            }
            content += "\t";
            content += "},\n";// Parameters End

            content += "\t";
            content += "Layers = {\n";
            for (int i = 0;i < Layers.Count;i++)
            {
                Layers[i].ExportToLua(ref content);
            }
            content += "\t";
            content += "},\n";// Layers End

            content += "}";//Table End
            content += "\n\n";

            content += "\nreturn " + tableName;
            bool ret = FileUtilTool.WriteFile(string.Format("{0}{1}.txt", AEConfig.ANIMATOR_INSTANCE_PATH, tableName), content);
            if (ret)
            {
                AEUtil.ShowNotification("Save Success");
            }
        }

        private string curCharacterName;
        private string animBasePath;
        private string prefabName;
        private string controllerSavePath;
        private AnimatorController productController;
        public void Export(PTCharacterType type, string index)
        {
            switch (type)
            {
                case PTCharacterType.Hero:
                    curCharacterName = string.Format("Hero{0}", index);
                    animBasePath = Path.Combine(AEConfig.HERO_ANIM_ROOT_PATH, string.Format("{0}/Hero{1}@{2}", index, index, index));
                    controllerSavePath = AEConfig.HERO_CONTROLLER_BASE_PATH + "AutoAnimCtrl_" + curCharacterName + ".controller";
                    break;
                case PTCharacterType.Npc:
                    curCharacterName = string.Format("Npc{0}", index);
                    animBasePath = Path.Combine(AEConfig.NPC_ANIM_ROOT_PATH, string.Format("{0}/Npc{1}@{2}", index, index, index));
                    controllerSavePath = AEConfig.NPC_CONTROLLER_BASE_PATH + "AutoAnimCtrl_" + curCharacterName + ".controller";
                    break;
                default:
                    return;
            }
            prefabName = AEUtil.GetCharacterPrefabName(index, type);
            Debug.Log("CreateController to " + curCharacterName);

            productController = GetControllerByPath(controllerSavePath);
            AEUtil.BindControllerToPrefab(prefabName, productController, cullingMode);
        }

        private void DrawParameters()
        {
            Color oldColor = GUI.color;
            GUI.color = AEConfig.PARAMETER_COLOR;

            EditorGUILayout.BeginVertical("window");
            EditorGUILayout.LabelField("Parameters");
            for (int i = 0;i < Parameters.Count;i++)
            {
                Parameters[i].Draw();
            }
            EditorGUILayout.Space();
            EditorGUILayout.EndVertical();

            GUI.color = oldColor;
        }

        private void DrawLayers()
        {
            Color oldColor = GUI.color;
            GUI.color = AEConfig.LAYER_COLOR;

            EditorGUILayout.BeginVertical("window");
            EditorGUILayout.LabelField("Layers");
            for (int i = 0;i < Layers.Count;i++)
            {
                Layers[i].Draw();
                EditorGUILayout.Space();
            }
            EditorGUILayout.EndVertical();

            GUI.color = oldColor;
        }

        private AnimatorController GetControllerByPath(string savePath)
        {
            AnimatorController result = (AnimatorController)AssetDatabase.LoadAssetAtPath(savePath, typeof(AnimatorController));
            if (result == null)
            {
                result = AnimatorController.CreateAnimatorControllerAtPath(controllerSavePath);
                if (null == result)
                {
                    AEUtil.ShowNotification(string.Format("Can't create controller file, path = {0}", savePath));
                }
            }else{
                // 删除不包含Skill的状态
                // AEUtil.RemoveStatesByName(result, "Skill", false);
                // 删除非Skill并且不再状态列表的状态
                RemoveUseLessState(result, "Skill");
            }

            AddParameters(result);

            AddLayers(result);
            return result;
        }

        private void RemoveUseLessState(AnimatorController controller, string exclude)
        {
            for (int i = 0;i < controller.layers.Length;i++)
            {
                if (!AEUtil.HasLayer(controller, Layers[i].LayerName))
                    continue;
                var aeLayer = Layers[i];
                var curLayer = controller.layers[i];
                var machine = curLayer.stateMachine;
                // find need clear statemachine
                List<AnimatorStateMachine> clearMachineList = new List<AnimatorStateMachine>();
                for (int j = 0; j < machine.stateMachines.Length; j++)
                {
                    if(!aeLayer.ContainsState(machine.stateMachines[j].stateMachine.name) && 
                        !machine.stateMachines[j].stateMachine.name.Contains(exclude))
                    {
                        clearMachineList.Add(machine.stateMachines[j].stateMachine);
                    }
                }
                // remove from machine
                for (int j = 0; j < clearMachineList.Count; j++)
                {
                    machine.RemoveStateMachine(clearMachineList[j]);
                }
                // find need clear states
                int count = machine.states.Length;
                List<AnimatorState> clearStateList = new List<AnimatorState>();
                for (int j = 0; j < count; ++j)
                {
                    AnimatorState curState = machine.states[j].state;
                    if (!aeLayer.ContainsState(curState.name) &&
                        !curState.name.Contains(exclude))
                    {
                        clearStateList.Add(curState);
                    }
                }
                // remove from machine
                for (int j = 0; j < clearStateList.Count; ++j)
                {
                    machine.RemoveState(clearStateList[j]);
                }
            }
        }

        private void AddParameters(AnimatorController controller)
        {
            if (controller == null)
                return;

            for (int i = 0;i < Parameters.Count;i++)
            {
                if(AEUtil.HasParameter(controller, Parameters[i].ParameterName))
                    continue;
                AnimatorControllerParameter parameter = new AnimatorControllerParameter();
                parameter.name = Parameters[i].ParameterName;
                parameter.type = Parameters[i].ParameterType;
                switch (parameter.type)
                {
                    case AnimatorControllerParameterType.Float:
                        parameter.defaultFloat = Convert.ToSingle(Parameters[i].DefaultValue);
                        break;
                    case AnimatorControllerParameterType.Int:
                        parameter.defaultInt = Convert.ToInt32(Parameters[i].DefaultValue);
                        break;
                    case AnimatorControllerParameterType.Bool:
                        parameter.defaultBool = Convert.ToBoolean(Parameters[i].DefaultValue);
                        break;
                    case AnimatorControllerParameterType.Trigger:
                        break;
                    default:
                        break;
                }

                controller.AddParameter(parameter);
            }
        }

        private void AddLayers(AnimatorController controller)
        {
            if (controller == null)
                return;

            for (int i = 0;i < Layers.Count;i++)
            {
                if (i != 0 && !AEUtil.HasLayer(controller, Layers[i].LayerName))
                {
                    controller.AddLayer(Layers[i].LayerName);
                    Debug.LogFormat("layer not have {0},{1}",i, Layers[i].LayerName);
                }
                if (i >= controller.layers.Length)
                {
                    Debug.LogErrorFormat("layer error {0},{1}",i,Layers[i].LayerName);
                }
                Layers[i].Build(controller.layers[i].stateMachine, animBasePath, controller, i);
            }

            // 如果不止一层则设置高层的权重为1
            if (controller.layers.Length > 1)
            {
                AnimatorControllerLayer[] layers = controller.layers;
                layers[1].defaultWeight = 1f;
                layers[1].blendingMode = AnimatorLayerBlendingMode.Override;
                if (controller.layers.Length > 2) {
                    layers[2].defaultWeight = 1f;
                    layers[2].blendingMode = AnimatorLayerBlendingMode.Additive;
                }
                controller.layers = layers;
            }
        }
    }
}
