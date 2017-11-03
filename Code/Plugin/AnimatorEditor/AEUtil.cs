using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEditor.Animations;
using UnityEngine;

namespace Assets.Editor.AnimatorEditor
{
    public static class AEUtil
    {
        private const float transitionTime = 0.1f;
        private const float fullBodyToRunTransTime = 0.05f;
        private const float lowerMoveToRunTransTime = 0.2f;
        public static AnimatorCreatorWindow CurCreator { get; set; }

        public static void SetStatePosition(AnimatorStateMachine machine, AnimatorState state, Vector3 position)
        {
            ChildAnimatorState[] states = machine.states;
            for (int i = 0; i < states.Length; i++)
            {
                if (state == states[i].state)
                {
                    states[i].position = position;
                    machine.states = states;
                    return;
                }
            }
        }

        public static void ShowNotification(string msg)
        {
            Debug.Log(msg);
            if (null != CurCreator)
                CurCreator.ShowNotification(new UnityEngine.GUIContent(msg));
        }

        public static AnimationClip LoadAnimClip(string path)
        {
            return (AnimationClip)AssetDatabase.LoadAssetAtPath(path, typeof(AnimationClip));
        }

        public static void RemoveStatesByName(AnimatorController controller, string name, bool containName)
        {
            if (null == controller || string.IsNullOrEmpty(name))
                return;

            for (int i = 0; i < controller.layers.Length; i++)
            {
                AnimatorStateMachine machine = controller.layers[i].stateMachine;
                if (null == machine)
                    continue;
                // find need clear statemachine
                List<AnimatorStateMachine> clearMachineList = new List<AnimatorStateMachine>();
                for (int j = 0; j < machine.stateMachines.Length; j++)
                {
                    if (machine.stateMachines[j].stateMachine.name.Contains(name) == containName)
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
                    if (curState.name.Contains(name) == containName)
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

        /// <summary>
        /// 删除不在names中的状态
        /// </summary>
        /// <param name="controller"></param>
        /// <param name="names"></param>
        public static void RemoveStatesNotContainsNames(AnimatorController controller, List<string> names, int layerIndex)
        {
            if (null == controller || names.Count == 0)
                return;

            AnimatorStateMachine machine = controller.layers[layerIndex].stateMachine;
            if (null == machine)
                return;
            // find need clear statemachine
            List<AnimatorStateMachine> clearMachineList = new List<AnimatorStateMachine>();
            for (int j = 0; j < machine.stateMachines.Length; j++)
            {
                bool contain = false;
                foreach (var name in names)
                {
                    if (machine.stateMachines[j].stateMachine.name.Contains(name))
                    {
                        contain = true;
                        break;
                    }
                }
                if (!contain)
                    clearMachineList.Add(machine.stateMachines[j].stateMachine);
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
                bool contain = false;
                foreach (var name in names)
                {
                    if (curState.name.Contains(name))
                    {
                        contain = true;
                        break;
                    }
                }
                if (!contain)
                    clearStateList.Add(curState);
            }
            // remove from machine
            for (int j = 0; j < clearStateList.Count; ++j)
            {
                machine.RemoveState(clearStateList[j]);
            }
        }

        public static AnimatorState FindStateByName(AnimatorStateMachine machine, string name)
        {
            if (null == machine || string.IsNullOrEmpty(name))
            {
                Debug.LogError("PTAnimatorUtil FindStateByName parameter error");
                return null;
            }

            for (int i = 0; i < machine.states.Length; i++)
            {
                AnimatorState curState = machine.states[i].state;
                if (curState.name.Equals(name))
                    return curState;
            }
            return null;
        }

        public static bool HasParameter(AnimatorController controller, string parameterName)
        {
            if (null == controller)
            {
                ShowNotification("HaveParameter controller is null!");
                return false;
            }
            int parameterCount = controller.parameters.Length;
            for (int i = 0; i < parameterCount; i++)
            {
                if (controller.parameters[i].name.Equals(parameterName))
                    return true;
            }
            return false;
        }

        public static bool HasLayer(AnimatorController controller, string layerName)
        {
            if (null == controller)
            {
                ShowNotification("HasLayer controller is null!");
                return false;
            }
            int layerCount = controller.layers.Length;
            for (int i = 0; i < layerCount; i++)
            {
                if (controller.layers[i].name.Equals(layerName))
                    return true;
            }
            return false;
        }

        public static bool HasState(AnimatorStateMachine machine, string stateName)
        {
            if (null == machine)
            {
                ShowNotification("HasState machine is null!");
                return false;
            }
            foreach (var item in machine.states)
            {
                if (item.state.name == stateName)
                    return true;
            }
            return false;
        }

        public static AnimatorState GetStateByName(AnimatorStateMachine machine, string stateName)
        {
            if (null == machine)
            {
                ShowNotification("GetStateByName machine is null!");
                return null;
            }
            foreach (var item in machine.states)
            {
                if (item.state.name == stateName)
                    return item.state;
            }
            return null;
        }

        public static bool HasAnyStateTransToState(AnimatorStateMachine machine, AnimatorState destinationState)
        {
            int transCount = machine.anyStateTransitions.Length;
            if (transCount == 0)
                return false;

            for (int i = 0; i < transCount; i++)
            {
                if (machine.anyStateTransitions[i].destinationState == destinationState)
                    return true;
            }
            return false;
        }

        public static void RemoveAnyStateTransitionContainTrigger(AnimatorStateMachine machine, string triggerName)
        {
            int transCount = machine.anyStateTransitions.Length;
            if (transCount == 0)
                return;

            for (int i = 0; i < transCount; i++)
            {
                int conditionCount = machine.anyStateTransitions[i].conditions.Length;
                for (int j = 0; j < conditionCount; j++)
                {
                    if (machine.anyStateTransitions[i].conditions[j].parameter.Contains(triggerName))
                    {
                        machine.RemoveAnyStateTransition(machine.anyStateTransitions[i]);
                        break;
                    }
                }
            }
        }

        public static void RemoveParameterContainName(AnimatorController controller, string parameterName)
        {
            int parameterCount = controller.parameters.Length;
            List<AnimatorControllerParameter> removeIndexs = new List<AnimatorControllerParameter>();
            for (int i = 0; i < parameterCount; i++)
            {
                if (controller.parameters[i].name.Contains(parameterName))
                {
                    removeIndexs.Add(controller.parameters[i]);
                }
            }
            for (int j = 0; j < removeIndexs.Count; j++)
            {
                controller.RemoveParameter(removeIndexs[j]);
            }
        }

        public static string GetCharacterPrefabName(string characterName, PTCharacterType type)
        {
            string result = string.Empty;
            string dir = string.Empty;
            string matchStr = string.Empty;
            if (type == PTCharacterType.Hero)
            {
                dir = Path.Combine("Assets/Res/", AEConfig.HERO_PREFAB_PATH);
                dir = Path.Combine(dir, string.Format("Hero{0}", characterName));
                result = dir;
                matchStr = "*Hero*";
            }
            else if (type == PTCharacterType.Npc)
            {
                dir = Path.Combine("Assets/Res/", AEConfig.NPC_PREFAB_PATH);
                result = dir;
                matchStr = "*Npc*";
            }

            if (!Directory.Exists(dir))
            {
                Directory.CreateDirectory(dir);
            }

            DirectoryInfo dirInfo = new DirectoryInfo(dir);
            FileInfo[] files = dirInfo.GetFiles(matchStr);
            for (int i = 0; i < files.Length; i++)
            {
                if (files[i].Name.Contains(characterName))
                {
                    result = Path.Combine(result, Path.GetFileNameWithoutExtension(files[i].FullName));
                    break;
                }
            }
            return result;
        }

        public static void BindControllerToPrefab(string prefabName, AnimatorController productController, AnimatorCullingMode? cullingMode = null)
        {
            if (string.IsNullOrEmpty(prefabName))
            {
                AEUtil.ShowNotification(string.Format("Can not find character:", prefabName));
                return;
            }

            UnityEngine.Object prefab;
            GameObject go;
            Animator animator;
            string path = string.Format("{0}.prefab", prefabName);
            prefab = AssetDatabase.LoadAssetAtPath(path, typeof(GameObject));
            if (prefab == null)
            {
                AEUtil.ShowNotification(string.Format("Can not load prefab {0}", prefabName));
                return;
            }
            go = UnityEngine.Object.Instantiate(prefab) as GameObject;

            if (go == null)
            {
                AEUtil.ShowNotification(string.Format("Can not instantiate prefab {0}", prefabName));
                return;
            }

            animator = go.GetComponent<Animator>();
            if (null == animator)
            {
                animator = go.AddComponent<Animator>();
            }
            if (cullingMode != null)
            {
                animator.cullingMode = (AnimatorCullingMode)cullingMode;
            }

            animator.runtimeAnimatorController = productController;
            PrefabUtility.ReplacePrefab(go, prefab);
            UnityEngine.Object.DestroyImmediate(go);
        }

        public static void AddSkillStates(string characterName, List<PTOneSkill> skills, PTCharacterType characterType)
        {
            // Init base path
            string skillAnimBasePath;
            string controllerPath;
            int skillLayerIndex = 0;
            if (characterType == PTCharacterType.Hero)
            {
                skillAnimBasePath = string.Format("{0}{1}/", AEConfig.HERO_ANIM_ROOT_PATH, characterName);
                controllerPath = AEConfig.HERO_CONTROLLER_BASE_PATH + "AutoAnimCtrl_Hero" + characterName + ".controller";
                skillLayerIndex = 1;
            }
            else
            {
                skillAnimBasePath = string.Format("{0}{1}/", AEConfig.NPC_ANIM_ROOT_PATH, characterName);
                controllerPath = AEConfig.NPC_CONTROLLER_BASE_PATH + "AutoAnimCtrl_Npc" + characterName + ".controller";
            }
            var productController = (AnimatorController)AssetDatabase.LoadAssetAtPath(controllerPath, typeof(AnimatorController));
            if (productController == null)
            {
                ShowNotification("Can't find existing controller. Hero code = " + characterName);
                return;
            }

            if (null == skills)
            {
                ShowNotification("PTAnimatorFactroy AddSkillStates skills is null");
                return;
            }

            if (characterType == PTCharacterType.Hero && productController.layers.Length < 2)
            {
                ShowNotification("PTAnimatorFactroy AddSkillStates controller layer less than 2");
                return;
            }

            AnimatorStateMachine machine = productController.layers[skillLayerIndex].stateMachine;
            // 移除旧有的技能状态
            RemoveStatesByName(productController, "Skill", true);

            // 移除旧有的ToIdle， ToIdleOrRun迁移
            RemoveAnyStateTransitionContainTrigger(machine, "To");
            RemoveParameterContainName(productController, "To");
            // Create skill states
            for (int skillIndex = 0; skillIndex < skills.Count; ++skillIndex)
            {
                int skillDisplayNo = skillIndex + 1;
                var curSkill = skills[skillIndex];
                if ((null == curSkill.stateList || 0 == curSkill.stateList.Count))
                {
                    Debug.Log("PTAnimatorFactroy AddSkillStates stateList is null or empty. Please check your config");
                    continue;
                }
                for (int i = 0; i < curSkill.stateList.Count; i++)
                {
                    float transTime = curSkill.stateList[i].overrideTransTime;
                    if (transTime < 0)
                    {
                        if (!curSkill.stateList[i].fullBody)
                        {
                            transTime = lowerMoveToRunTransTime;
                        }
                        else
                        {
                            transTime = fullBodyToRunTransTime;
                        }
                    }
                    CreateSkillStateImp(skillAnimBasePath, productController, machine, curSkill.stateList[i].animationName, skillDisplayNo, transTime, i + 1);
                }
            }

            BindControllerToPrefab(GetCharacterPrefabName(characterName, characterType), productController);
        }

        public static void SetAllTransitionInterruptType(TransitionInterruptionSource interruptSource)
        {
            // 获取所有导出过的文件
            string[] files = Directory.GetFiles(AEConfig.ANIMATOR_INSTANCE_PATH);
            foreach (var filePath in files)
            {
                if (Path.GetExtension(filePath) != ".txt")
                    continue;

                string fileName = Path.GetFileName(filePath);
                if (fileName.ToLower().Contains("npc"))
                    continue;

                string indexStr = fileName.Substring(4, 3);
                string controllerPath = string.Format("{0}AutoAnimCtrl_Hero{1}.controller", AEConfig.HERO_CONTROLLER_BASE_PATH, indexStr);
                AnimatorController result = AssetDatabase.LoadAssetAtPath<AnimatorController>(controllerPath);
                string prefabFileName = AEUtil.GetCharacterPrefabName(indexStr, PTCharacterType.Hero);
                foreach (var layer in result.layers)
                {
                    foreach (var trans in layer.stateMachine.anyStateTransitions)
                    {
                        trans.interruptionSource = interruptSource;
                    }
                    foreach (var trans in layer.stateMachine.defaultState.transitions)
                    {
                        trans.interruptionSource = interruptSource;
                    }
                    foreach (var animState in layer.stateMachine.states)
                    {
                        foreach (var trans in animState.state.transitions)
                        {
                            trans.interruptionSource = interruptSource;
                        }
                    }
                }
                AEUtil.BindControllerToPrefab(prefabFileName, result);

            }
        }

        private static void CreateSkillStateImp(
            string skillAnimBasePath,
            AnimatorController productController,
            AnimatorStateMachine machine,
            string animName,
            int skillDisplayNo,
            float transTime,
            int innerIndex)
        {
            // load clip
            var animClip = AssetDatabase.LoadAssetAtPath(skillAnimBasePath + animName, typeof(AnimationClip)) as AnimationClip;
            string stateName = "Skill" + skillDisplayNo + "S" + innerIndex;
            var animState = machine.AddState(stateName);
            animState.motion = animClip;
            //contact with parent machine
            // AnyState to skill
            string triggerName = stateName;
            if (!HasParameter(productController, triggerName))
                productController.AddParameter(triggerName, AnimatorControllerParameterType.Trigger);
            var trans = machine.AddAnyStateTransition(animState);
            trans.AddCondition(AnimatorConditionMode.If, 0, triggerName);
            trans.hasExitTime = false;
            trans.duration = transitionTime;
            trans.interruptionSource = TransitionInterruptionSource.Destination;
            trans.canTransitionToSelf = false;

            //半身动画需要不一样的融合时间，Run因为有不同需求只能各拉一根
            var states = machine.states;
            for (int i = 0; i < states.Length; i++)
            {
                var stateRun = states[i].state;
                if (stateRun.name == "Run" || stateRun.name == "Run2")
                {
                    var transToRun = animState.AddTransition(states[i].state);
                    transToRun.AddCondition(AnimatorConditionMode.If, 0, stateRun.name);
                    transToRun.hasExitTime = false;
                    transToRun.interruptionSource = TransitionInterruptionSource.Destination;
                    transToRun.duration = transTime;
                    transToRun.canTransitionToSelf = false;
                }
            }
        }
    }
}
