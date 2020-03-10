#if UNITY_EDITOR

using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using NodeCanvas.Framework;
using NodeCanvas.Framework.Internal;
using ParadoxNotion;
using ParadoxNotion.Design;
using UnityEditor;
using UnityEngine;


namespace NodeCanvas.Editor{

	/// <summary>
	/// Editor for IBlackboards
	/// </summary>
    public static class BlackboardEditor {

		class ReorderingState{
			public List<Variable> list;
			public bool isReordering = false;
			public ReorderingState(List<Variable> list){
				this.list = list;
			}
		}

		private static readonly Dictionary<IBlackboard, ReorderingState> tempStates = new Dictionary<IBlackboard, ReorderingState>();

		public static Variable pickedVariable{get;set;}
		public static IBlackboard pickedVariableBlackboard{get;set;}
		public static void ShowVariables(IBlackboard bb, UnityEngine.Object contextParent){

			GUI.skin.label.richText = true;
			var e = Event.current;
			var layoutOptions = new GUILayoutOption[]{GUILayout.MaxWidth(100), GUILayout.ExpandWidth(true), GUILayout.Height(16)};

			//Begin undo check
			UndoManager.CheckUndo(contextParent, "Blackboard Inspector");

			//Add variable button
			GUI.backgroundColor = new Color(0.8f,0.8f,1);
			if (GUILayout.Button("Add Variable")){
				System.Action<System.Type> AddNewVariable = (t)=>
				{
					var name = "my" + t.FriendlyName();
					while (bb.GetVariable(name) != null){
						name += ".";
					}
					bb.AddVariable(name, t);
				};

				System.Action<PropertyInfo> AddBoundProp = (p) =>
				{
					var newVar = bb.AddVariable(p.Name, p.PropertyType);
					newVar.BindProperty(p);
				};

				System.Action<FieldInfo> AddBoundField = (f) =>
				{
					var newVar = bb.AddVariable(f.Name, f.FieldType);
					newVar.BindProperty(f);
				};

				var menu = new GenericMenu();
				menu = EditorUtils.GetPreferedTypesSelectionMenu(typeof(object), AddNewVariable, true, menu, "New");

				if (bb.propertiesBindTarget != null){
					foreach (var comp in bb.propertiesBindTarget.GetComponents(typeof(Component)).Where(c => c.hideFlags != HideFlags.HideInInspector) ){
						menu = EditorUtils.GetPropertySelectionMenu(comp.GetType(), typeof(object), AddBoundProp, false, false, menu, "Bound (Self)/Property");
						menu = EditorUtils.GetFieldSelectionMenu(comp.GetType(), typeof(object), AddBoundField, menu, "Bound (Self)/Field");
					}
				}

				foreach (var type in UserTypePrefs.GetPreferedTypesList(typeof(object))){
					menu = EditorUtils.GetStaticPropertySelectionMenu(type, typeof(object), AddBoundProp, false, false, menu, "Bound (Static)/Property");
					menu = EditorUtils.GetStaticFieldSelectionMenu(type, typeof(object), AddBoundField, menu, "Bound (Static)/Field");
				}


				menu.AddSeparator("/");
				menu.AddItem(new GUIContent("Add Header Separator"), false, ()=>{ AddNewVariable(typeof(VariableSeperator)); } );

				menu.ShowAsContext();
				e.Use();
			}


			GUI.backgroundColor = Color.white;

			//Simple column header info
			if (bb.variables.Keys.Count != 0){
				GUILayout.BeginHorizontal();
				GUI.color = Color.yellow;
				GUILayout.Label("Name", layoutOptions);
				GUILayout.Label("Value", layoutOptions);
				GUI.color = Color.white;
				GUILayout.EndHorizontal();
			} else {
				EditorGUILayout.HelpBox("Blackboard has no variables", MessageType.Info);
			}

			if (!tempStates.ContainsKey(bb)){
				tempStates.Add(bb, new ReorderingState(bb.variables.Values.ToList()));
			}

			//Make temporary list for editing variables
			if (!tempStates[bb].isReordering){
				tempStates[bb].list = bb.variables.Values.ToList();
			}

			//store the names of the variables being used by current graph selection.
			var usedVariables = GetUsedVariablesBySelectionParameters();

			//The actual variables reorderable list
			EditorUtils.ReorderableList(tempStates[bb].list, delegate(int i){

				var data = tempStates[bb].list[i];
				if (data == null){
					GUILayout.Label("NULL Variable!");
					return;
				}

				var isUsed = usedVariables.Contains(data.name);
				var missingVariableType = data as MissingVariableType;

				GUILayout.Space( data.varType == typeof(VariableSeperator)? 5 : 0 );

				GUILayout.BeginHorizontal();

				if (missingVariableType == null){
					//Name of the variable GUI control
					if (!Application.isPlaying){

						//The small box on the left to re-order variables
						GUI.backgroundColor = new Color(1,1,1,0.8f);
						GUILayout.Box("", GUILayout.Width(6));
						GUI.backgroundColor = new Color(0.7f,0.7f,0.7f, 0.3f);

						if (e.type == EventType.MouseDown && e.button == 0 && GUILayoutUtility.GetLastRect().Contains(e.mousePosition) ){
							tempStates[bb].isReordering = true;
							if (data.varType != typeof(VariableSeperator)){
								pickedVariable = data;
								pickedVariableBlackboard = bb;
							}
						}
						
						//Make name field red if same name exists
						if (tempStates[bb].list.Where(v => v != data).Select(v => v.name).Contains(data.name)){
							GUI.backgroundColor = Color.red;
						}

						GUI.enabled = !data.isProtected;
						if (data.varType != typeof(VariableSeperator)){
                            switch (data.varType.ToString())
                            {
                                case "System.Int32":
                                    {
                                        data.name = EditorGUILayout.TextField("[I]" + data.name, layoutOptions).Split(']')[1];
                                        break;
                                    }
                                case "System.Decimal":
                                    {
                                        data.name = EditorGUILayout.TextField("[D]" + data.name, layoutOptions).Split(']')[1];
                                        break;
                                    }
                                case "System.Single":
                                    {
                                        data.name = EditorGUILayout.TextField("[F]" + data.name, layoutOptions).Split(']')[1];
                                        break;
                                    }
                                case "System.Int64":
                                    {
                                        data.name = EditorGUILayout.TextField("[L]" + data.name, layoutOptions).Split(']')[1];
                                        break;
                                    }
                                case "System.String":
                                    {
                                        data.name = EditorGUILayout.TextField("[S]" + data.name, layoutOptions).Split(']')[1];
                                        break;
                                    }
                                default:
                                    {
                                        data.name = EditorGUILayout.TextField(data.name, layoutOptions);
                                        break;
                                    }

                            }
							EditorGUI.indentLevel = 0;

						} else {

							var separator = (VariableSeperator)data.value;

							GUI.color = Color.yellow;
							if (separator.isEditingName){
								data.name = EditorGUILayout.TextField(data.name, layoutOptions);
							} else {
								GUILayout.Label(string.Format("<b>{0}</b>", data.name).ToUpper(), layoutOptions);
							}
							GUI.color = Color.white;

							if (!separator.isEditingName){
								if (e.type == EventType.MouseDown && e.button == 0 && e.clickCount == 2 && GUILayoutUtility.GetLastRect().Contains(e.mousePosition)){
									separator.isEditingName = true;
									GUIUtility.keyboardControl = 0;
								}
							}
							
							if (separator.isEditingName){
								if ( (e.isKey && e.keyCode == KeyCode.Return) || (e.rawType == EventType.MouseUp && !GUILayoutUtility.GetLastRect().Contains(e.mousePosition) )  ){
									separator.isEditingName = false;
									GUIUtility.keyboardControl = 0;
								}
							}

							data.value = separator;
						}

						GUI.enabled = true;
						GUI.backgroundColor = Color.white;

					} else {

						//Don't allow name edits in play mode. Instead show just a label
						if (data.varType != typeof(VariableSeperator)){
							GUI.backgroundColor = new Color(0.7f,0.7f,0.7f);
							GUI.color = new Color(0.8f,0.8f,1f);
							GUILayout.Label(data.name, layoutOptions);
						} else {
							GUI.color = Color.yellow;
							GUILayout.Label(string.Format("<b>{0}</b>", data.name.ToUpper()), layoutOptions);
							GUI.color = Color.white;						
						}
					}


					//reset coloring
					GUI.color = Color.white;
					GUI.backgroundColor = Color.white;

					//Highlight used variable by selection?
					if (isUsed){
						var r = GUILayoutUtility.GetLastRect();
						r.xMin += 2;
						r.xMax -= 2;
						r.yMax -= 4;
						GUI.Box(r, "", (GUIStyle)"LightmapEditorSelectedHighlight");
					}
					
					//Show the respective data GUI
					if (data.varType != typeof(VariableSeperator)){
						ShowDataGUI(data, bb, contextParent, layoutOptions);
					} else {
						if (!Application.isPlaying && GUILayout.Button("x", GUILayout.Width(17), GUILayout.Height(16))){
							tempStates[bb].list.Remove(data);
						}
						GUILayout.Space(0);
						GUILayout.Space(0);
					}

				} else {

					var internalTypeName = missingVariableType.missingType.Split(new string[]{"[[", "]]"}, System.StringSplitOptions.RemoveEmptyEntries )[1];
					internalTypeName = internalTypeName.Substring(0, internalTypeName.IndexOf(","));
					GUILayout.Box("", GUILayout.Width(6));
					GUILayout.Label(data.name, layoutOptions);
					GUILayout.Label(string.Format("<color=#ff6457>* {0} *</color>", internalTypeName), layoutOptions);
				}

				//reset coloring
				GUI.color = Color.white;
				GUI.backgroundColor = Color.white;

				GUILayout.EndHorizontal();

			}, contextParent);

			//reset coloring
			GUI.backgroundColor = Color.white;
			GUI.color = Color.white;


			if ( (GUI.changed && !tempStates[bb].isReordering) || e.rawType == EventType.MouseUp){
				tempStates[bb].isReordering = false;
				EditorApplication.delayCall += ()=>{ pickedVariable = null; pickedVariableBlackboard = null; };
				//reconstruct the dictionary
				try { bb.variables = tempStates[bb].list.ToDictionary(d => d.name, d => d); }
				catch { Debug.LogError("Blackboard has duplicate names!"); }
		    }

			//Check dirty
			UndoManager.CheckDirty(contextParent);
		}

		///Get a list of variable names used by the current selection of the current graph in the NC Editor window.
		static List<string> GetUsedVariablesBySelectionParameters(){
			if (Graph.currentSelection == null){
				return new List<string>();
			}
			return GetUsedVariablesBySelectionParameters(Graph.currentSelection);
		} 

		static List<string> GetUsedVariablesBySelectionParameters(object target){

			var result = new List<string>();
			if (target == null){
				return result;
			}

			result.AddRange( BBParameter.GetObjectBBParameters(target).Select(p => p.name) );

			var task = target as Task;
			if (task != null){
				result.AddRange( BBParameter.GetObjectBBParameters(task).Select(p => p.name) );
				if (!string.IsNullOrEmpty(task.overrideAgentParameterName) ){
					result.Add(task.overrideAgentParameterName);
				}
			}

			var taskActionList = target as ActionList;
			if (taskActionList != null){
				for (var i = 0; i < taskActionList.actions.Count; i++){
					var t = taskActionList.actions[i];
					result.AddRange( BBParameter.GetObjectBBParameters(t).Select(p => p.name) );
					if (!string.IsNullOrEmpty(t.overrideAgentParameterName) ){
						result.Add(t.overrideAgentParameterName);
					}
				}
			}

			var taskConditionList = target as ConditionList;
			if (taskConditionList != null){
				for (var i = 0; i < taskConditionList.conditions.Count; i++){
					var t = taskConditionList.conditions[i];
					result.AddRange( BBParameter.GetObjectBBParameters(t).Select(p => p.name) );
					if (!string.IsNullOrEmpty(t.overrideAgentParameterName) ){
						result.Add(t.overrideAgentParameterName);
					}
				}
			}

			var subContainer = target as ISubTasksContainer;
			if (subContainer != null){
				var subTasks = subContainer.GetTasks();
				for (var i = 0; i < subTasks.Length; i++){
					result.AddRange(GetUsedVariablesBySelectionParameters(subTasks[i]));
				}
			}

			var assignable = target as ITaskAssignable;
			if (assignable != null && assignable.task != null){
				result.AddRange(GetUsedVariablesBySelectionParameters(assignable.task));
			}

			return result;
		}


		static void ShowDataGUI(Variable data, IBlackboard bb, UnityEngine.Object contextParent, GUILayoutOption[] layoutOptions){

			//Bind info or value GUI control
			if (data.hasBinding){
			    var idx = data.propertyPath.LastIndexOf('.');
			    var typeName = data.propertyPath.Substring(0, idx);
			    var memberName = data.propertyPath.Substring(idx + 1);
				GUI.color = new Color(0.8f,0.8f,1);
				GUILayout.Label(string.Format(".{0} ({1})", memberName, typeName.Split('.').Last() ), layoutOptions);
				GUI.color = Color.white;
			} else {
				GUI.enabled = !data.isProtected;
                var fieldVar = VariableField(data, contextParent, layoutOptions);
                if (!Equals(fieldVar, data.value))
                {
                    data.value = fieldVar;
                    GraphOwner owner = ParadoxNotion.Services.MonoManager.current.debugingGraphOwner;
                    
                }
                GUI.enabled = true;
				GUI.backgroundColor = Color.white;
			}

			//Variable options menu
			if ( !Application.isPlaying && GUILayout.Button("●", GUILayout.Width(17), GUILayout.Height(16))){

				System.Action<PropertyInfo> SelectProp = (p) => {
					data.BindProperty(p);
				};

				System.Action<FieldInfo> SelectField = (f) => {
					data.BindProperty(f);
				};

				var menu = new GenericMenu();

				if (bb.propertiesBindTarget != null){
					foreach (var comp in bb.propertiesBindTarget.GetComponents(typeof(Component)).Where(c => c.hideFlags != HideFlags.HideInInspector) ){
						menu = EditorUtils.GetPropertySelectionMenu(comp.GetType(), data.varType, SelectProp, false, false, menu, "Bind (Self)/Property");
						menu = EditorUtils.GetFieldSelectionMenu(comp.GetType(), data.varType, SelectField, menu, "Bind (Self)/Field");
					}
				}

				foreach (var type in UserTypePrefs.GetPreferedTypesList(typeof(object))){
					menu = EditorUtils.GetStaticPropertySelectionMenu(type, data.varType, SelectProp, false, false, menu, "Bind (Static)/Property");
					menu = EditorUtils.GetStaticFieldSelectionMenu(type, data.varType, SelectField, menu, "Bind (Static)/Field");
				}


				menu.AddItem(new GUIContent("Protected"), data.isProtected, ()=>{ data.isProtected = !data.isProtected; });

				menu.AddSeparator("/");
				if (data.hasBinding){
					menu.AddItem(new GUIContent("UnBind"), false, ()=> {data.UnBindProperty();});
				} else {
					menu.AddDisabledItem(new GUIContent("UnBind"));
				}

				menu.AddItem(new GUIContent("Delete Variable"), false, ()=>
				{
					if (EditorUtility.DisplayDialog("Delete Variable '" + data.name + "'", "Are you sure?", "Yes", "No")){
						bb.RemoveVariable(data.name);
						GUIUtility.hotControl = 0;
						GUIUtility.keyboardControl = 0;
					}
				});
				
				menu.ShowAsContext();
				Event.current.Use();
			}
		}

		//While there is a similar method in EditorUtils, due to layouting and especialy no prefix name, this has to be redone a bit differently
		static object VariableField(Variable data, UnityEngine.Object context, GUILayoutOption[] layoutOptions){

			var o = data.value;
			var t = data.varType;

			//Check scene object type for UnityObjects. Consider Interfaces as scene object type. Assume that user uses interfaces with UnityObjects
			var isSceneObjectType = (typeof(Component).IsAssignableFrom(t) || t == typeof(GameObject) || t.IsInterface);
			if (typeof(UnityEngine.Object).IsAssignableFrom(t) || t.IsInterface){
				return EditorGUILayout.ObjectField((UnityEngine.Object)o, t, isSceneObjectType, layoutOptions);
			}

		    //Check Type second
			if (t == typeof(System.Type)){
				return EditorUtils.Popup<System.Type>(null, (System.Type)o, UserTypePrefs.GetPreferedTypesList(typeof(object), true), layoutOptions );
			}

			t = o != null? o.GetType() : t;
			if (t.IsAbstract){
				GUILayout.Label( string.Format("({0})", t.FriendlyName()), layoutOptions );
				return o;
			}

			if (o == null && !t.IsAbstract && !t.IsInterface && (t.GetConstructor(System.Type.EmptyTypes) != null || t.IsArray ) ){
				if (GUILayout.Button("(null) Create", layoutOptions)){
					if (t.IsArray){
						return System.Array.CreateInstance(t.GetElementType(), 0);
					}
					return System.Activator.CreateInstance(t);
				}
				return o;
			}			

			if (t == typeof(bool)){
				return EditorGUILayout.Toggle((bool)o, layoutOptions);
			}

			if (t == typeof(Color)){
				return EditorGUILayout.ColorField((Color)o, layoutOptions);
			}

			if (t == typeof(AnimationCurve)){
				return EditorGUILayout.CurveField((AnimationCurve)o, layoutOptions);
			}

			if (t.IsSubclassOf(typeof(System.Enum) )){
#if UNITY_5				
				if (t.GetCustomAttributes(typeof(System.FlagsAttribute), true).FirstOrDefault() != null ){
					return EditorGUILayout.EnumMaskPopup(GUIContent.none, (System.Enum)o, layoutOptions);
				}
#endif
				return EditorGUILayout.EnumPopup((System.Enum)o, layoutOptions);
			}

			if (t == typeof(float)){
				GUI.backgroundColor = UserTypePrefs.GetTypeColor(t);
				return EditorGUILayout.FloatField((float)o, layoutOptions);
            }

            if (t == typeof(short))
            {
                GUI.backgroundColor = UserTypePrefs.GetTypeColor(t);
                return System.Convert.ToInt16(EditorGUILayout.IntField((int)o, layoutOptions));
            }

            if (t == typeof(ushort))
            {
                GUI.backgroundColor = UserTypePrefs.GetTypeColor(t);
                return System.Convert.ToUInt16(EditorGUILayout.IntField(System.Convert.ToInt32(o), layoutOptions));
            }

            if (t == typeof(int))
            {
                GUI.backgroundColor = UserTypePrefs.GetTypeColor(t);
                return EditorGUILayout.IntField((int)o, layoutOptions);
            }

            if (t == typeof(long))
            {
                GUI.backgroundColor = UserTypePrefs.GetTypeColor(t);
                return EditorGUILayout.LongField((long)o, layoutOptions);
            }

            if (t == typeof(ulong))
            {
                GUI.backgroundColor = UserTypePrefs.GetTypeColor(t);
                return System.Convert.ToUInt64(EditorGUILayout.LongField(System.Convert.ToInt64(o), layoutOptions));
            }

            if (t == typeof(string)){
				GUI.backgroundColor = UserTypePrefs.GetTypeColor(t);
				return EditorGUILayout.TextField((string)o, layoutOptions);
			}

			if (t == typeof(Vector2)){
				return EditorGUILayout.Vector2Field("", (Vector2)o, layoutOptions);
			}

			if (t == typeof(Vector3)){
				return EditorGUILayout.Vector3Field("", (Vector3)o, layoutOptions);
			}

			if (t == typeof(Vector4)){
				return EditorGUILayout.Vector4Field("", (Vector4)o, layoutOptions);
			}

			if (t == typeof(Quaternion)){
				var q = (Quaternion)o;
				var v = new Vector4(q.x, q.y, q.z, q.w);
				v = EditorGUILayout.Vector4Field("", v, layoutOptions);
				return new Quaternion(v.x, v.y, v.z, v.w);
			}

			if (t == typeof(LayerMask)){
				return EditorUtils.LayerMaskField(null, (LayerMask)o, layoutOptions);
			}



			//If some other type, show it in the generic object editor window
			if (GUILayout.Button( string.Format("{0} {1}", t.FriendlyName(), (o is IList)? ((IList)o).Count.ToString() : "" ), layoutOptions)){
				GenericInspectorWindow.Show(data.ID, o, t, context);
			}

			//if we are externaly inspecting value and it's this one, get value from the external editor. This is basicaly done for structs
			if (GenericInspectorWindow.current != null && GenericInspectorWindow.current.inspectedID == data.ID){
				return GenericInspectorWindow.current.value;
			}

			return o;
		}
	}
}

#endif