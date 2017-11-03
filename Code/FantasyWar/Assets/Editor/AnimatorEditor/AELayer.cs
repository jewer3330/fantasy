using System.Collections.Generic;
using UnityEditor.Animations;
using UnityEditor;
using UnityEngine;
using System;

namespace Assets.Editor.AnimatorEditor
{
    public class AELayer
    {
        private Dictionary<string, AnimatorState> statesMap = new Dictionary<string, AnimatorState>();
        public string LayerName { get; set; }
        
        public List<AEState> States = new List<AEState>();
        public List<AEBlendTree> Trees = new List<AEBlendTree>();
        public List<AETransition> Transitions = new List<AETransition>();

        public bool ContainsState(string name)
        {
            foreach (var item in States)
            {
                if(item.StateName == name)
                    return true;
            }
            return false;
        }

        public void Draw()
        {
            EditorGUILayout.BeginVertical();
            EditorGUILayout.BeginVertical("window");
            EditorGUILayout.LabelField("LayerName: " + LayerName);

            DrawStates();
            EditorGUILayout.Space();

            DrawTrees();
            EditorGUILayout.Space();

            DrawTransitions();
            EditorGUILayout.Space();


            EditorGUILayout.EndVertical();
        }

        private void DrawStates()
        {
            Color oldColor = GUI.color;
            GUI.color = AEConfig.STATE_COLOR;
            
            EditorGUILayout.BeginVertical("box");
            EditorGUILayout.LabelField("States");
            for (int i = 0; i < States.Count; i++)
            {
                States[i].Draw();
            }
            EditorGUILayout.EndVertical();

            GUI.color = oldColor;
        }

        private void DrawTrees()
        {
            EditorGUILayout.BeginVertical("box");
            EditorGUILayout.LabelField("BlendTrees");
            for (int i = 0; i < Trees.Count; i++)
            {
                Trees[i].Draw();
            }
            EditorGUILayout.EndVertical();
        }

        private void DrawTransitions()
        {
            EditorGUILayout.BeginVertical("window");
            EditorGUILayout.LabelField("Transitions");
            for (int i = 0; i < Transitions.Count; i++)
            {
                Transitions[i].Draw();
                EditorGUILayout.Space();
            }
            EditorGUILayout.EndVertical();
        }

        public void Build(AnimatorStateMachine machine, string animBasePath, AnimatorController productController, int layerIndex)
        {
            machine.entryPosition = new Vector3(10f, -200f, 0f);
            machine.anyStatePosition = new Vector3(300f, 0f, 0f);
            machine.exitPosition = new Vector3(600f, 0f, 0f);
            statesMap.Clear();
            AddStates(machine, animBasePath);
            AddBlendTrees(machine, animBasePath, productController);
            // 删除不在构建列表中,而且非Skill的状态
            List<string> names = new List<string>();
            names.AddRange(statesMap.Keys);
            names.Add("Skill");
            AEUtil.RemoveStatesNotContainsNames(productController, names, layerIndex);
            // 删除不与Skill相关Transition
            RemoveTransitions(machine, "Skill");
            AddTransitions(machine);
        }

        public void ParseFromJson(LitJson.JsonData data)
        {
            LayerName = data["LayerName"].ToString();
            ParseStates(data["States"]);
            ParseBlendTrees(data["BlendTrees"]);
            ParseTransitions(data["Transitions"]);
        }

        
        private void ParseStates(LitJson.JsonData data)
        {
            AEState state = new AEState();
            state.ParseFromJson(data);
            States.Add(state);
        }

        private void ParseBlendTrees(LitJson.JsonData data)
        {
            AEBlendTree tree = new AEBlendTree();
            tree.ParseFromJson(data);
            Trees.Add(tree);
        }

        private void ParseTransitions(LitJson.JsonData data)
        {
            AETransition transition = new AETransition();
            transition.ParseFromJson(data);
            Transitions.Add(transition);
        }


        public void ExportToLua(ref string content)
        {
            content += "\t\t{\n";

            content += "\t\t\tLayerName = \"" + LayerName + "\",\n";

            content += "\t\t\tStates = {\n";
            for (int i = 0; i < States.Count; i++)
            {
                States[i].ExportToLua(ref content);
            }
            content += "\t\t\t},\n";// States End

            if(Trees.Count > 0)
            {
                content += "\t\t\tBlendTrees = {\n";
                for (int i = 0; i < Trees.Count; i++)
                {
                    Trees[i].ExportToLua(ref content);
                }
                content += "\t\t\t},\n";// Trees End
            }

            content += "\t\t\tTransitions = {\n";
            for (int i = 0; i < Transitions.Count; i++)
            {
                Transitions[i].ExportToLua(ref content);
            }
            content += "\t\t\t},\n";// States End

            content += "\t\t},\n";// Layer End
        }

        private void AddBlendTrees(AnimatorStateMachine machine, string animBasePath, AnimatorController productController)
        {
            for (int i = 0; i < Trees.Count; i++)
            {
                AnimatorState state = Trees[i].Build(machine, animBasePath, productController);
                AddStateToMap(Trees[i].StateName, state);
            }
        }

        private void AddStates(AnimatorStateMachine machine, string animBasePath)
        {
            for (int i = 0; i < States.Count; i++)
            {
                AnimatorState state = States[i].Build(machine, animBasePath);
                AddStateToMap(States[i].StateName, state);
            }
        }

        private void AddStateToMap(string name, AnimatorState state)
        {
            if(state == null)
            {
                AEUtil.ShowNotification(string.Format("State is null {0}", name));
                return;
            }
            if (statesMap.ContainsKey(name))
            {
                AEUtil.ShowNotification(string.Format("There is a same name state already {0}", name));
                return;
            }
            statesMap.Add(name, state);
        }

        /// <summary>
        /// 移除state中除了跟exclude相关的所有迁移
        /// </summary>
        /// <param name="state"></param>
        /// <param name="exclude"></param>
        private void RemoveTransitions(AnimatorStateMachine machine, string exclude = "Skill")
        {
            List<AnimatorStateTransition> needRemoves = new List<AnimatorStateTransition>();
            foreach (AnimatorStateTransition item in machine.anyStateTransitions)
            {
                if(item.destinationState.name.Contains(exclude))
                    continue;
                needRemoves.Add(item);
            }
            for (int i = 0; i < needRemoves.Count; i++)
            {
                machine.RemoveAnyStateTransition(needRemoves[i]);
            }
            foreach (var item in machine.states)
            {
                if(item.state.name.Contains(exclude))
                    continue;
                needRemoves.Clear();
                foreach (var transition in item.state.transitions)
                {
                    if(transition.destinationState != null && transition.destinationState.name.Contains(exclude))
                        continue;
                    needRemoves.Add(transition);
                }
                for (int i = 0; i < needRemoves.Count; i++)
                {
                    item.state.RemoveTransition(needRemoves[i]);
                }
            }
        }

        private void AddCondition(AnimatorStateTransition animatorTransition, AETransition transition)
        {
            if (animatorTransition == null)
                return;
            foreach (var item in transition.Conditions)
            {
                if (string.IsNullOrEmpty(item.ParameterName))
                    continue;
                animatorTransition.AddCondition(item.ConditionMode, item.Threshold, item.ParameterName);
            }
        }

        private void InitTransition(AnimatorStateTransition tempTrans, AETransition config)
        {
            AddCondition(tempTrans, config);
            if (tempTrans != null)
            {
                tempTrans.duration = 0f;
                tempTrans.interruptionSource = TransitionInterruptionSource.Destination;
                tempTrans.canTransitionToSelf = config.CanTransitionToSelf;

                if (config.ExitTime > 0f)
                {
                    tempTrans.hasExitTime = true;
                    tempTrans.exitTime = config.ExitTime;
                }

                if (config.Duration > 0f)
                {
                    tempTrans.duration = config.Duration;
                }
                if (config.Offset > 0f)
                {
                    tempTrans.offset = config.Offset;
                }
            }
        }

        private void AddTransitions(AnimatorStateMachine machine)
        {
            AnimatorState fromState;
            AnimatorState toState;
            
            for (int i = 0; i < Transitions.Count; i++)
            {
                AnimatorStateTransition tempTrans = null;
                switch (Transitions[i].Type)
                {
                    case TransitionType.Normal:
                        if (statesMap.TryGetValue(Transitions[i].FromStateName, out fromState))
                        {
                            if (statesMap.TryGetValue(Transitions[i].ToStateName, out toState))
                            {
                                tempTrans = fromState.AddTransition(toState);
                                InitTransition(tempTrans, Transitions[i]);
                            }
                            else
                            {
                                AEUtil.ShowNotification(string.Format("Can't Find To State {0}", Transitions[i].ToStateName));
                                break;
                            }
                        }
                        else
                            AEUtil.ShowNotification(string.Format("Can't Find From State {0}", Transitions[i].FromStateName));
                        break;
                    case TransitionType.Entry:
                        if (statesMap.TryGetValue(Transitions[i].ToStateName, out toState))
                            machine.defaultState = toState;
                        else
                            AEUtil.ShowNotification(string.Format("Can't Find Entry State {0}", Transitions[i].ToStateName));
                        break;
                    case TransitionType.Exit:
                        if (statesMap.TryGetValue(Transitions[i].FromStateName, out fromState))
                        {
                            tempTrans = fromState.AddExitTransition();
                            InitTransition(tempTrans, Transitions[i]);
                        }
                        else
                            AEUtil.ShowNotification(string.Format("Can't Find To Exit State {0}", Transitions[i].ToStateName));
                        break;
                    case TransitionType.AnyState:
                        if (statesMap.TryGetValue(Transitions[i].ToStateName, out toState))
                        {
                            tempTrans = machine.AddAnyStateTransition(toState);
                            InitTransition(tempTrans, Transitions[i]);
                        }
                        else
                            AEUtil.ShowNotification(string.Format("Can't Find Any To State {0}", Transitions[i].ToStateName));
                        break;
                    case TransitionType.All:
                        if (statesMap.TryGetValue(Transitions[i].ToStateName, out toState))
                        {
                            var enumState = statesMap.GetEnumerator();
                            while (enumState.MoveNext())
                            {
                                if (enumState.Current.Key != Transitions[i].ToStateName)
                                {
                                    tempTrans = enumState.Current.Value.AddTransition(toState);
                                    InitTransition(tempTrans, Transitions[i]);
                                }
                            }
                        }
                        else
                            AEUtil.ShowNotification(string.Format("Can't Find From All To State {0}", Transitions[i].ToStateName));
                        break;
                    default:
                        break;
                }                
            }
        }
    }
}