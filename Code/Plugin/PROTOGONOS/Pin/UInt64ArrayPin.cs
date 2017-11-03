using UnityEngine;
using System;
using System.Collections;

public class UInt64ArrayPin : PlatoPin
{
    public override Color GetColor()
    {
        return Color.yellow;
    }

    public override void OnDraw()
    {
        GUILayout.Label(Title, IsInput ? "InPinFont" : "OutPinFont", GUILayout.MinWidth(50.0f), GUILayout.Height(PlatoPin.PinHeight));
    }

    public override string SaveValue()
    {
        return string.Empty;
    }

    public override void LoadValue(object value)
    {
        // Do nothing
    }

    public override string ExportToLua()
    {
        return "nil";
    }

    public override string ExportToCSharp()
    {
        return "null";
    }

    public override string CppValue(string cpp_node)
    {
        if (PlatoExportUtil.IsEmptyString(Value as string))
            return "{}";
        else
            return "{" + String.Join(",", (Value as string).Split(';')) + "}";
    }

    public override PlatoPin DoClone()
    {
        return new UInt64ArrayPin();
    }
}
