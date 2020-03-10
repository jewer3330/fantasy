using System.Collections.Generic;
using UnityEngine;
using System.Linq;

namespace NodeCanvas.Framework{

    /// <summary>
    /// Global Blackboards are accessible from any BBParameter. Their name must be unique
    /// </summary>
    [ExecuteInEditMode]
	public class GlobalBlackboard : Blackboard {

		///A list of all the current active global blackboards in the scene
		public static List<GlobalBlackboard> allGlobals = new List<GlobalBlackboard>();
		///Flag to not destroy on load.
		public bool dontDestroy = true;

		///Name of the global blackboard
		new public string name{
			get {return base.name;}
			set
			{
				if (base.name != value){
					base.name = value;
					if (!IsUnique()){
						Debug.LogError("Another Blackboard has the same name. Please rename either.", gameObject);
					}
				}
			}
		}


		public static GlobalBlackboard Create(){
			var bb = new GameObject("@GlobalBlackboard").AddComponent<GlobalBlackboard>();
			bb.name = "Global";
			return bb;
		}		

		///A convenient way to find and get a global blackboard by it's name
		public static GlobalBlackboard Find(string name){
			if (!Application.isPlaying){
				return FindObjectsOfType<GlobalBlackboard>().Where(b => b.name == name).FirstOrDefault();
			}
			return allGlobals.Find(b => b.name == name);
		}

		void OnEnable(){

			if (!allGlobals.Contains(this)){
				allGlobals.Add(this);
			}

			if (Application.isPlaying){
				if (IsUnique()){
					if (dontDestroy){
						DontDestroyOnLoad(this.gameObject);
					}
				} else {
//					Debug.Log( string.Format("There exist more than one Global Blackboards with same name '{0}'. The old one will be destroyed and replaced with the new one.", name));
					DestroyImmediate(this.gameObject);
				}
			}

			if (!Application.isPlaying && !IsUnique()){
//				Debug.LogError(string.Format("There is a duplicate <b>GlobalBlackboard</b> named '{0}' in the scene. Please rename it.", name), this);
			}
		}

		void OnDestroy(){
			allGlobals.Remove(this);
		}

		bool IsUnique(){
			return allGlobals.Find(b => b.name == this.name && b != this) == null;
		}
	}
}