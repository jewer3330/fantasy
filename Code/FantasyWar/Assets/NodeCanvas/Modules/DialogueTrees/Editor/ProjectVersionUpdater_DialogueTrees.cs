#if UNITY_EDITOR

using UnityEditor;
using UnityEngine;
using UnityEditor.SceneManagement;
using System.Collections.Generic;
using System.Reflection;
using NodeCanvas.Framework;
using NodeCanvas.Framework.Internal;
using NodeCanvas.DialogueTrees;
using ParadoxNotion;

namespace NodeCanvas.Editor{

	///Used to update the project to newer versions in case it's needed due to some core change.
	//This partial part is only used for Dialogue Trees.
	public static partial class ProjectVersionUpdater {

		static partial void OnBeforeUpdatePrefab(GameObject go){
			TryPrepare(go);
		}

		static partial void OnBeforeUpdateScene(){
			var gos = Resources.FindObjectsOfTypeAll(typeof(GameObject)) as GameObject[];
			foreach(var go in gos){
				if ( !EditorUtility.IsPersistent(go) ){
					TryPrepare(go);
				}
			}			
		}

		static void TryPrepare(GameObject go){
			var attachedScriptable = go.GetComponent(typeof(IScriptableComponent)) as object as DialogueTree;
			if (attachedScriptable != null){
				var controller = go.AddComponent<DialogueTreeController>();
				controller.graph = attachedScriptable;
			}
		}
	}
}

#endif