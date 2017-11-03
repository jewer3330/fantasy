using UnityEngine;
using UnityEditor;
using System;

public class FloatArrayPin : PlatoPin {
    public override string CppValue(string cpp_node)
    {
        if (PlatoExportUtil.IsEmptyString(Value as string))
            return "{}";
        else
            return "{" + String.Join(",", (Value as string).Split(';')) + "}";
    }

    public override PlatoPin DoClone()
    {
        return new FloatArrayPin();
    }

    public override string ExportToLua()
    {
        return string.Format("'{0}'", Value);
    }

    public override string ExportToCSharp()
    {
        if (PlatoExportUtil.IsEmptyString(Value as string))
            return "new List<float> {}";
        else
            return "new List<float> {" + String.Join(",", (Value as string).Split(';')) + "}";
    }

    public override Color GetColor()
    {
        return new Color(0.6f, 1.0f, 0.2f);
    }

    public override void LoadValue(object value)
    {
        if (value is string)
            Value = value as string;
        else
            Value = value.ToString();

    }

    public override void OnDraw()
    {
        if (!IsInput)
            GUILayout.Label(Title, IsInput ? "InPinFont" : "OutPinFont", GUILayout.MinWidth(50.0f), GUILayout.Height(PlatoPin.PinHeight));
        else
            Value = EditorGUILayout.TextField(Title, (string)Value, GUILayout.Height(PlatoPin.PinHeight));
    }

    public override string SaveValue()
    {
        return string.Format("'{0}'", Value.ToString());
    }

}
