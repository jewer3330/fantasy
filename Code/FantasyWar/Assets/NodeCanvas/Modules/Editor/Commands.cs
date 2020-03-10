#if UNITY_EDITOR

using UnityEngine;
using UnityEditor;
using ParadoxNotion.Design;
using NodeCanvas.Framework;

namespace NodeCanvas.Editor{

	static class Commands {
        
        [MenuItem("Tools/NodeCanvas/Medusa &n")]
        public static void OpenEditor()
        {
            GraphEditor.OpenWindow();
        }
        [MenuItem("Tools/NodeCanvas/Create/Scene Global Blackboard")]
		public static void CreateGlobalBlackboard(){
			Selection.activeObject = GlobalBlackboard.Create();
		}

		[MenuItem("Tools/NodeCanvas/Create/Standalone Action List")]
		static void CreateActionListPlayer(){
			Selection.activeObject = ActionListPlayer.Create();
		}

#if !UNITY_WEBPLAYER
		[MenuItem("Tools/NodeCanvas/Create/New Task")]
		[MenuItem("Assets/Create/ParadoxNotion/NodeCanvas/New Task")]
		public static void ShowTaskWizard(){
			TaskWizardWindow.ShowWindow();
		}
#endif

		[MenuItem("Tools/NodeCanvas/Update Project to Version 2.6.2 +")]
		public static void UpdateProject(){
			ProjectVersionUpdater.DoVersionUpdate();
		}

		[MenuItem("Tools/NodeCanvas/Preferred Types Editor")]
		public static void ShowPrefTypes(){
			PreferedTypesEditorWindow.ShowWindow();
		}

	    [MenuItem("Tools/NodeCanvas/External Inspector Panel")]
	    public static void ShowExternalInspector(){
	    	ExternalInspectorWindow.ShowWindow();
	    }

		[MenuItem("Tools/NodeCanvas/Welcome Window")]
		public static void ShowWelcome(){
			WelcomeWindow.ShowWindow(null);
		}

		[MenuItem("Tools/NodeCanvas/Visit Website")]
		public static void VisitWebsite(){
			Help.BrowseURL("http://nodecanvas.paradoxnotion.com");
		}
	}
}

#endif