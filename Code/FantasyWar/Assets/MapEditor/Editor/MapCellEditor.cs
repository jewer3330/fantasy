using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

[CustomEditor(typeof(MapCell))]
public class MapCellEditor : Editor {

    public GUIStyle style;

    void OnSceneGUI()
    {
        if (null == style)
        {
            style = new GUIStyle();
            style.fontSize = 40;
        }
        MapCell cell = (MapCell)target;
        if (cell == null)
        {
            return;
        }

        Handles.color = Color.red;

        Handles.Label(cell.transform.position + Vector3.up * 2,
            cell.steps.ToString(),style);
        Handles.BeginGUI();

        if (GUILayout.Button(cell.steps.ToString(), GUILayout.Width(100)))
        {
        }
        Handles.EndGUI();


        //Handles.DrawWireArc(handleExample.transform.position,
        //    handleExample.transform.up,
        //    -handleExample.transform.right,
        //    180,
        //    handleExample.shieldArea);
        //handleExample.shieldArea =
        //    Handles.ScaleValueHandle(handleExample.shieldArea,
        //        handleExample.transform.position + handleExample.transform.forward * handleExample.shieldArea,
        //        handleExample.transform.rotation,
        //        1,
        //        Handles.ConeHandleCap,
        //        1);

        
    }
}
