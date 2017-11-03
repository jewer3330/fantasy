using UnityEngine;
using System;
using System.Collections;

public class UInt64Pin : PlatoPin
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
        return string.Format("'{0}'", Value.ToString());
    }

    public override void LoadValue(object value)
    {
        Value = Convert.ToString(value);
    }

    public override string ExportToLua()
    {
        return "0";
    }

    public override string ExportToCSharp()
    {
        return "0";
    }

    public override string CppValue(string cpp_node)
    {
        return "0U";
    }

    public override PlatoPin DoClone()
    {
        return new UInt64Pin();
    }
}
