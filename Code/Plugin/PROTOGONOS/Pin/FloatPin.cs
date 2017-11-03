using UnityEngine;
using UnityEditor;
using System;
using System.Collections;

public class FloatPin : PlatoPin
{
    public override Color GetColor()
    {
        return new Color(0.6f, 1.0f, 0.2f);
    }

    public override void OnDraw()
    {
        if (!IsInput)
            GUILayout.Label(Title, IsInput ? "InPinFont" : "OutPinFont", GUILayout.MinWidth(50.0f), GUILayout.Height(PlatoPin.PinHeight));
        else
            Value = EditorGUILayout.FloatField(Title, (float)Value, GUILayout.Height(PlatoPin.PinHeight));
    }

    public override string SaveValue()
    {
        return Value.ToString();
    }

    public override void LoadValue(object value)
    {
        Value = Convert.ToSingle(value);
    }

    public override string ExportToLua()
    {
        return SaveValue();
    }

    public override string ExportToCSharp()
    {
        return string.Format("{0:#.00}f", Value);
    }

    public override string CppValue(string cpp_node)
    {
        return string.Format("{0:#.00}f", Value);
    }

    public override PlatoPin DoClone()
    {
        return new FloatPin();
    }
}
