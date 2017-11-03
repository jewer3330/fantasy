using UnityEngine;
using UnityEditor;
using System;
using System.Collections;

public class IntPin : PlatoPin
{
    public override Color GetColor()
    {
        return new Color(0.2f, 0.88f, 0.72f);
    }

    public override void OnDraw()
    {
        if (!IsInput)
            GUILayout.Label(Title, IsInput ? "InPinFont" : "OutPinFont", GUILayout.MinWidth(50.0f), GUILayout.Height(PlatoPin.PinHeight));
        else
            Value = EditorGUILayout.IntField(Title, (int)Value, GUILayout.Height(PlatoPin.PinHeight));
    }

    public override string SaveValue()
    {
        return Value.ToString();
    }

    public override void LoadValue(object value)
    {
        Value = Convert.ToInt32(value);
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
        return new IntPin();
    }
}
