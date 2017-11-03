using UnityEngine;
using UnityEditor;
using System;
using System.Collections;

public class BoolPin : PlatoPin
{
    public override Color GetColor()
    {
        return Color.red;
    }

    public override void OnDraw()
    {
        if (!IsInput)
            GUILayout.Label(Title, IsInput ? "InPinFont" : "OutPinFont", GUILayout.MinWidth(50.0f), GUILayout.Height(PlatoPin.PinHeight));
        else
            Value = EditorGUILayout.Toggle(Title, (bool)Value, GUILayout.Height(PlatoPin.PinHeight));
    }

    public override string SaveValue()
    {
        return Value.ToString().ToLower();
    }

    public override void LoadValue(object value)
    {
        Value = Convert.ToBoolean(value);
    }

    public override string ExportToLua()
    {
        return SaveValue();
    }

    public override string ExportToCSharp()
    {
        return SaveValue();
    }

    public override string CppValue(string cpp_node)
    {
        return SaveValue();
    }

    public override PlatoPin DoClone()
    {
        return new BoolPin();
    }
}
