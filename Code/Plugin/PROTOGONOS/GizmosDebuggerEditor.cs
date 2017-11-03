using UnityEngine;
using UnityEditor;
using System.Collections;

[CustomEditor(typeof(GizmosDebugger))]
public class GizmosDebuggerEditor : Editor
{
    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();

        GizmosDebugger.Enable = GUILayout.Toggle(GizmosDebugger.Enable, "Enable");
        if (GUILayout.Button("Clear"))
            GizmosDebugger.Instance.Clear();
    }
}
