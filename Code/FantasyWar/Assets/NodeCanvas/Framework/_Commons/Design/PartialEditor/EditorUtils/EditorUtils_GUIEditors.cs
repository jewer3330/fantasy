#if UNITY_EDITOR

using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using UnityEngine;
using UnityObject = UnityEngine.Object;

namespace ParadoxNotion.Design{

    /// <summary>
    /// Specific Editor GUIs
    /// </summary>

	partial class EditorUtils {

        private static readonly Dictionary<object, bool> registeredEditorFoldouts = new Dictionary<object, bool>();

		private static List<int> layerNumbers = new List<int>();
		public static LayerMask LayerMaskField(string prefix, LayerMask layerMask, params GUILayoutOption[] layoutOptions){
		    var layers = UnityEditorInternal.InternalEditorUtility.layers;
		    layerNumbers.Clear();
		 
		    for (int i = 0; i < layers.Length; i++)
		        layerNumbers.Add(LayerMask.NameToLayer(layers[i]));
		 
		     var maskWithoutEmpty = 0;
		     for (int i = 0; i < layerNumbers.Count; i++) {
		        if (((1 << layerNumbers[i]) & layerMask.value) > 0){
		            maskWithoutEmpty |= (1 << i);
		        }
		    }
			
			if (!string.IsNullOrEmpty(prefix)) maskWithoutEmpty = UnityEditor.EditorGUILayout.MaskField(prefix, maskWithoutEmpty, layers, layoutOptions);
			else maskWithoutEmpty = UnityEditor.EditorGUILayout.MaskField(maskWithoutEmpty, layers, layoutOptions);
		 
		    var mask = 0;
		    for (int i = 0; i < layerNumbers.Count; i++){
		        if ((maskWithoutEmpty & (1 << i)) > 0){
		            mask |= (1 << layerNumbers[i]);
		        }
		    }
		    layerMask.value = mask;
		    return layerMask;
		}

		//An IList editor (List<T> and Arrays)
		public static IList ListEditor(string prefix, IList list, Type listType, object contextInstance){

			var argType = listType.IsArray? listType.GetElementType() : listType.GetGenericArguments()[0];

			//register foldout
			if (!registeredEditorFoldouts.ContainsKey(list))
				registeredEditorFoldouts[list] = false;

			GUILayout.BeginVertical();

			var foldout = registeredEditorFoldouts[list];
			foldout = EditorGUILayout.Foldout(foldout, prefix);
			registeredEditorFoldouts[list] = foldout;

			if (!foldout){
				GUILayout.EndVertical();
				return list;
			}

			if (list.Equals(null)){
				GUILayout.Label("Null List");
				GUILayout.EndVertical();
				return list;
			}

			if (GUILayout.Button("Add Element")){
				
				if (listType.IsArray){
				
					list = ResizeArray( (Array)list, list.Count + 1);
					registeredEditorFoldouts[list] = true;
				
				} else {

					var o = argType.IsValueType? Activator.CreateInstance(argType) : null;
					list.Add(o);
				}
			}

			EditorGUI.indentLevel ++;

			for (var i = 0; i < list.Count; i++){
				GUILayout.BeginHorizontal();
				list[i] = GenericField("Element " + i, list[i], argType, null);
				if (GUILayout.Button("X", GUILayout.Width(18))){
					
					if (listType.IsArray){
						
						list = ResizeArray( (Array)list, list.Count - 1 );
						registeredEditorFoldouts[list] = true;

					} else{

						list.RemoveAt(i);
					}
				}
				GUILayout.EndHorizontal();				
			}

			EditorGUI.indentLevel --;
			Separator();

			GUILayout.EndVertical();
			return list;
		}

		static System.Array ResizeArray (System.Array oldArray, int newSize) {
			int oldSize = oldArray.Length;
			System.Type elementType = oldArray.GetType().GetElementType();
			System.Array newArray = System.Array.CreateInstance(elementType,newSize);
			int preserveLength = System.Math.Min(oldSize,newSize);
			if (preserveLength > 0){
				System.Array.Copy (oldArray,newArray,preserveLength);
			}
			return newArray;
		}

		//A dictionary editor
		public static IDictionary DictionaryEditor(string prefix, IDictionary dict, Type dictType, object contextInstance){

			var keyType = dictType.GetGenericArguments()[0];
			var valueType = dictType.GetGenericArguments()[1];

			//register foldout
			if (!registeredEditorFoldouts.ContainsKey(dict))
				registeredEditorFoldouts[dict] = false;

			GUILayout.BeginVertical();

			var foldout = registeredEditorFoldouts[dict];
			foldout = EditorGUILayout.Foldout(foldout, prefix);
			registeredEditorFoldouts[dict] = foldout;

			if (!foldout){
				GUILayout.EndVertical();
				return dict;
			}

			if (dict.Equals(null)){
				GUILayout.Label("Null Dictionary");
				GUILayout.EndVertical();
				return dict;
			}

			var keys = dict.Keys.Cast<object>().ToList();
			var values = dict.Values.Cast<object>().ToList();

			if (GUILayout.Button("Add Element")) {
			    if (!typeof(UnityObject).IsAssignableFrom(keyType)){
					object newKey = null;
					if (keyType == typeof(string))
						newKey = string.Empty;
					else newKey = Activator.CreateInstance(keyType);
					if (dict.Contains(newKey)){
						Debug.LogWarning(string.Format("Key '{0}' already exists in Dictionary", newKey.ToString()));
						return dict;
					}

					keys.Add(newKey);

				} else {
					Debug.LogWarning("Can't add a 'null' Dictionary Key");
					return dict;
				}

			    values.Add(valueType.IsValueType? Activator.CreateInstance(valueType) : null);
			}

		    //clear before reconstruct
			dict.Clear();

			for (var i = 0; i < keys.Count; i++){
				GUILayout.BeginHorizontal("box");
				GUILayout.Box("", GUILayout.Width(6), GUILayout.Height(35));
				GUILayout.BeginVertical();

				keys[i] = GenericField("K:", keys[i], keyType, null);
				values[i] = GenericField("V:", values[i], valueType, null);
				GUILayout.EndVertical();
				GUILayout.EndHorizontal();

				try {dict.Add(keys[i], values[i]);}
				catch{ Debug.Log("Dictionary Key removed due to duplicate found"); }
			}

			Separator();

			GUILayout.EndVertical();
			return dict;
		}


		//An editor field where if the component is null simply shows an object field, but if its not, shows a dropdown popup to select the specific component
		//from within the gameobject
		public static Component ComponentField(string prefix, Component comp, Type type, bool allowNone = true){

			if (!comp){
				if (!string.IsNullOrEmpty(prefix)){
					comp = EditorGUILayout.ObjectField(prefix, comp, type, true, GUILayout.ExpandWidth(true)) as Component;
				} else {
					comp = EditorGUILayout.ObjectField(comp, type, true, GUILayout.ExpandWidth(true)) as Component;
				}

				return comp;
			}

			var allComp = new List<Component>(comp.GetComponents(type));
			var compNames = new List<string>();

			foreach (var c in allComp.ToArray()){
				if (c == null) continue;
				compNames.Add(c.GetType().FriendlyName() + " (" + c.gameObject.name + ")");
			}

			if (allowNone)
				compNames.Add("|NONE|");

			int index;
			if (!string.IsNullOrEmpty(prefix))
				index = EditorGUILayout.Popup(prefix, allComp.IndexOf(comp), compNames.ToArray(), GUILayout.ExpandWidth(true));
			else
				index = EditorGUILayout.Popup(allComp.IndexOf(comp), compNames.ToArray(), GUILayout.ExpandWidth(true));
			
			if (allowNone && index == compNames.Count - 1)
				return null;

			return allComp[index];
		}


		public static string StringPopup(string selected, List<string> options, bool showWarning = true, bool allowNone = false, params GUILayoutOption[] GUIOptions){
			return StringPopup(string.Empty, selected, options, showWarning, allowNone, GUIOptions);
		}

		//a popup that is based on the string rather than the index
		public static string StringPopup(string prefix, string selected, List<string> options, bool showWarning = true, bool allowNone = false, params GUILayoutOption[] GUIOptions){

			EditorGUILayout.BeginVertical();
			if (options.Count == 0 && showWarning){
				EditorGUILayout.HelpBox("There are no options to select for '" + prefix + "'", MessageType.Warning);
				EditorGUILayout.EndVertical();
				return null;
			}

			var index = 0;
			var copy = new List<string>(options);
			if (allowNone){
				copy.Insert(0, "|NONE|");
			}

			if (copy.Contains(selected)) index = copy.IndexOf(selected);
			else index = allowNone? 0 : -1;

			if (!string.IsNullOrEmpty(prefix)) index = EditorGUILayout.Popup(prefix, index, copy.ToArray(), GUIOptions);
			else index = EditorGUILayout.Popup(index, copy.ToArray(), GUIOptions);

			if (index == -1 || (allowNone && index == 0)){

				if (showWarning){
					if (!string.IsNullOrEmpty(selected)){
						EditorGUILayout.HelpBox("The previous selection '" + selected + "' has been deleted or changed. Please select another", MessageType.Warning);
					} else {
						EditorGUILayout.HelpBox("Please make a selection", MessageType.Warning);
					}
				}
			}

			EditorGUILayout.EndVertical();
			if (allowNone){
				return index == 0? string.Empty : copy[index];
			}

			return index == -1? string.Empty : copy[index];
		}

		///Generic Popup for selection of any element within a list
		public static T Popup<T>(string prefix, T selected, List<T> options, params GUILayoutOption[] GUIOptions){

			var index = 0;
			if (options.Contains(selected)){
				index = options.IndexOf(selected) + 1;
			}

			var stringedOptions = new List<string>();
			if (options.Count == 0){
				stringedOptions.Add("|NONE AVAILABLE|");
			} else {
				stringedOptions.Add("|NONE|");
				stringedOptions.AddRange( options.Select(o => o != null? o.ToString() : "|NONE|") );
			}

			GUI.enabled = stringedOptions.Count > 1;
			if (!string.IsNullOrEmpty(prefix)) index = EditorGUILayout.Popup(prefix, index, stringedOptions.ToArray(), GUIOptions);
			else index = EditorGUILayout.Popup(index, stringedOptions.ToArray(), GUIOptions);		
			GUI.enabled = true;

			return index == 0? default(T) : options[index - 1];
		}
	}
}

#endif