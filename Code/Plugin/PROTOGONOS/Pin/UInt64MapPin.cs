using UnityEngine;
using System.Collections;

public class UInt64MapPin : PlatoPin
{
    public override Color GetColor()
    {
        return Color.cyan;
    }

    public override void OnDraw()
    {
        GUILayout.Label(Title, IsInput ? "InPinFont" : "OutPinFont", GUILayout.MinWidth(50.0f), GUILayout.Height(PlatoPin.PinHeight));
    }

    public override string SaveValue()
    {
        return "'nil'";
    }

    public override void LoadValue(object value)
    {
        // Do nothing
    }

    public override string ExportToLua()
    {
        return string.Empty;
    }

    public override string ExportToCSharp()
    {
        return string.Empty;
    }

    public override string CppValue(string cpp_node)
    {
        return "{{}}";
    }

    public override PlatoPin DoClone()
    {
        return new UInt64MapPin();
    }
}
