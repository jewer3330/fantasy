#if UNITY_EDITOR

using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityObject = UnityEngine.Object;

namespace ParadoxNotion.Design{

    /// <summary>
    /// A simple reorderable list. Pass the list and a function to call for GUI. The callback comes with the current iterated element index in the list
    /// </summary>

	partial class EditorUtils {

		private static readonly Dictionary<IList, object> pickedObjectList = new Dictionary<IList, object>();
        
		public static void ReorderableList(IList list, System.Action<int> GUICallback, UnityObject unityObject = null){

			if (list.Count == 1){
				GUICallback(0);
				return;
			}

			if (!pickedObjectList.ContainsKey(list)){
				pickedObjectList[list] = null;
			}

			var e = Event.current;
			var lastRect = new Rect();
			var picked = pickedObjectList[list];
			GUILayout.BeginVertical();
			for (var i= 0; i < list.Count; i++){

				GUILayout.BeginVertical();
				GUICallback(i);
				GUILayout.EndVertical();

				GUI.color = Color.white;
				GUI.backgroundColor = Color.white;

				lastRect = GUILayoutUtility.GetLastRect();
				EditorGUIUtility.AddCursorRect(lastRect, MouseCursor.MoveArrow);

				if (picked != null && picked == list[i]){
					GUI.Box(lastRect, "");
				}

				if (picked != null && lastRect.Contains(e.mousePosition) && picked != list[i]){

					var markRect = new Rect(lastRect.x,lastRect.y-2,lastRect.width, 2);
					if (list.IndexOf(picked) < i){
						markRect.y = lastRect.yMax - 2;
					}

					GUI.Box(markRect, "");
					if (e.type == EventType.MouseUp){
						if (unityObject != null){
							Undo.RecordObject(unityObject, "Reorder");
						}
						list.Remove(picked);
						list.Insert(i, picked);
						pickedObjectList[list] = null;
						if (unityObject != null){
							EditorUtility.SetDirty(unityObject);
						}
					}
				}

				if (lastRect.Contains(e.mousePosition) && e.type == EventType.MouseDown){
					pickedObjectList[list] = list[i];
				}
			}

			GUILayout.EndVertical();

			if (e.type == EventType.MouseUp){
				pickedObjectList[list] = null;
			}
		}
	}
}

#endif