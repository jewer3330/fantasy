using UnityEngine;
using System;
using System.Collections;

public class ExecPin : PlatoPin
{
    public bool IsEvent = false;

    public override void Parse(string key, object value)
    {
        base.Parse(key, value);

        if (key == "IsEvent")
        {
            IsEvent = Convert.ToBoolean(value);
        }
    }

    public override Color GetColor()
    {
        return Color.white;
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
        ExecPin ret = new ExecPin();
        ret.IsEvent = IsEvent;
        return ret;
    }
}
