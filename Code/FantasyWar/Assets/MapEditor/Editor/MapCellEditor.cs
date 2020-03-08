using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

[CustomEditor(typeof(MapCell))]
public class MapCellEditor : Editor {

    private GUIStyle style;

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
        if (Application.isPlaying)
            Handles.Label(cell.transform.position + Vector3.up * 2,cell.steps.ToString(), style);
        Handles.BeginGUI();
        GUILayout.BeginArea(new Rect(10, 10, 200, 400));
        if(Application.isPlaying)
            GUILayout.Label("cost " + cell.steps.ToString(), GUILayout.Width(100));
        else
            Draw(cell);
        GUILayout.EndArea();
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

    public static void Draw(MapCell cell)
    {
        cell.data.start = EditorGUILayout.Toggle("startpoint", cell.data.start);
        if (cell.data.start)
        {
            cell.data.ActorID = EditorGUILayout.IntField("actorID", cell.data.ActorID);
            cell.data.playerType = (MapCellData.PlayerType)EditorGUILayout.EnumPopup(cell.data.playerType);
        }
        cell.data.id = EditorGUILayout.IntField("id", cell.data.id);
        cell.data.cost = EditorGUILayout.IntField("cost", cell.data.cost);
        EditorGUILayout.LabelField(string.Format("pos ({0},{1})" ,cell.data.x.ToString(),cell.data.y.ToString()));
        //EditorGUILayout.LabelField(cell.y.ToString());
        //EditorGUILayout.LabelField(cell.h.ToString());
        EditorGUILayout.LabelField("res path : "+ cell.data.res);

    }
}
