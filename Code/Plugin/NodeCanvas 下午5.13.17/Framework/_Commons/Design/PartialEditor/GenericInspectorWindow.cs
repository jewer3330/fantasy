#if UNITY_EDITOR

using UnityEditor;
using UnityEngine;


namespace ParadoxNotion.Design{

	///A generic popup editor for all reference types
	public class GenericInspectorWindow : EditorWindow{

		public static GenericInspectorWindow current{get; private set;}
		public string inspectedID{get; private set;}
		public object value{get; private set;}

		private System.Type targetType;
		private Object context;
		private Vector2 scrollPos;

		void OnEnable(){
	        #if UNITY_5
	        titleContent = new GUIContent("Object Editor");
	        #else
	        title = "Object Editor";
	        #endif
			current = this;
			EditorApplication.playmodeStateChanged += PlaymodeStateChanged;
		}

		void OnDisable(){
			EditorApplication.playmodeStateChanged -= PlaymodeStateChanged;
			current = null;
		}

		void PlaymodeStateChanged(){
			Close();
		}

		void OnGUI(){

			if (targetType == null){
				return;
			}

			//Begin undo check
			GUI.skin.label.richText = true;
			UndoManager.CheckUndo(context, "Blackboard External Inspector");

			GUILayout.BeginHorizontal();
			GUILayout.FlexibleSpace();
			GUILayout.Label(string.Format("<size=14><b>{0}</b></size>", targetType.FriendlyName()) );
			GUILayout.FlexibleSpace();
			GUILayout.EndHorizontal();


			GUILayout.Space(10);
			scrollPos = GUILayout.BeginScrollView(scrollPos);
			value = EditorUtils.GenericField(targetType.FriendlyName(), value, targetType, null);
			GUILayout.EndScrollView();
			Repaint();

			//Check dirty
			UndoManager.CheckDirty(context);
		}

		public static void Show(string inspectedID, object o, System.Type t, Object context){
			var window = current == null? CreateInstance<GenericInspectorWindow>() : current;
			window.inspectedID = inspectedID;
			window.value = o;
			window.targetType = t;
			window.context = context;
			window.ShowUtility();
		}
	}
}

#endif