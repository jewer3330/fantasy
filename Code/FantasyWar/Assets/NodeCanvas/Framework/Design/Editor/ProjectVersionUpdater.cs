#if UNITY_EDITOR

using UnityEditor;
using UnityEngine;
using UnityEditor.SceneManagement;
using System.Collections.Generic;
using System.Reflection;
using NodeCanvas.Framework;
using NodeCanvas.Framework.Internal;

namespace NodeCanvas.Editor{

	///Used to update the project to newer versions in case it's needed due to some core change.
	public static partial class ProjectVersionUpdater {

		public static void DoVersionUpdate(){

			if ( !EditorUtility.DisplayDialog("Update Project To Framework Version 2.6.2 +", "Before continuing please MAKE A BACKUP of your project!\n\nContinue now?", "Yes", "No") ){
				return;
			}

			if ( !EditorSceneManager.SaveCurrentModifiedScenesIfUserWantsTo() ){
				return;
			}

			var currentScenePath = EditorSceneManager.GetActiveScene().path;


			//prefabs first
			Debug.Log( "<b>Updating GraphOwner Prefabs...</b>" );
			var prefabOwnerGUIDS = AssetDatabase.FindAssets("t:GameObject");
			foreach(var guid in prefabOwnerGUIDS){
				var path = AssetDatabase.GUIDToAssetPath(guid);
				var prefabGO = (GameObject)AssetDatabase.LoadAssetAtPath(path, typeof(GameObject));
				if (PrefabUtility.GetPrefabType(prefabGO) == PrefabType.Prefab){
					OnBeforeUpdatePrefab(prefabGO);
					foreach(var prefabOwner in prefabGO.GetComponentsInChildren<GraphOwner>()){
						prefabOwner.TryUpdateBoundGraphPriorToVersion2_6_2();
					}
				}
			}


			//scene instances
			var projectSceneGUIDS = AssetDatabase.FindAssets("t:SceneAsset");
			foreach(var guid in projectSceneGUIDS){
				var path = AssetDatabase.GUIDToAssetPath(guid);
				var sceneAsset = (SceneAsset)AssetDatabase.LoadAssetAtPath(path, typeof(SceneAsset));
				if (sceneAsset != null){
					Debug.Log( string.Format("<b>Updating Scene: '{0}'...</b>", sceneAsset.name) );
					EditorSceneManager.OpenScene(path);
					OnBeforeUpdateScene();
					var owners = Resources.FindObjectsOfTypeAll<GraphOwner>();
					foreach(var owner in owners){
						if ( !EditorUtility.IsPersistent(owner) ){ //exclude prefabs since they are already done above
							owner.TryUpdateBoundGraphPriorToVersion2_6_2();
						}
					}

					var scene = EditorSceneManager.GetActiveScene();
					EditorSceneManager.MarkSceneDirty(scene);
					if ( !EditorSceneManager.SaveScene(scene) ){
						Debug.LogError("Could not save scene " + scene.name);
					}
				}
			}


			//unlock prefabs
			var proxyField = typeof(GraphOwner).GetField("versionUpdateProxyGraph", BindingFlags.Instance | BindingFlags.NonPublic);
			foreach(var guid in prefabOwnerGUIDS){
				var path = AssetDatabase.GUIDToAssetPath(guid);
				var prefabGO = (GameObject)AssetDatabase.LoadAssetAtPath(path, typeof(GameObject));
				if (PrefabUtility.GetPrefabType(prefabGO) == PrefabType.Prefab){
					foreach(var prefabOwner in prefabGO.GetComponentsInChildren<GraphOwner>()){
						var proxyGraph = proxyField.GetValue(prefabOwner) as VersionUpdateProxyGraph;
						if (proxyGraph != null){
							Object.DestroyImmediate(proxyGraph, true);
							proxyField.SetValue(prefabOwner, null);
							prefabOwner.Validate();
							EditorUtility.SetDirty(prefabOwner);
							Debug.Log(string.Format("{0} Prefab Unlocked.", prefabOwner));
						}
					}
				}
			}


			AssetDatabase.SaveAssets();
			if (!string.IsNullOrEmpty(currentScenePath)){
				EditorSceneManager.OpenScene(currentScenePath);
			}

			Debug.Log("<b>Project Updated to NodeCanvas Framework Version 2.6.2+</b>");
		}


		static partial void OnBeforeUpdatePrefab(GameObject go);
		static partial void OnBeforeUpdateScene();
	}
}

#endif