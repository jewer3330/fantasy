using UnityEngine;
using UnityEngine.UI;
using UnityEditor;
using System;
using System.Collections;

public class ButtonPin : PlatoPin
{
    /// <summary>按钮引脚的点击回调</summary>
    public delegate void OnButtonClick();
    public OnButtonClick onClick { get; set; }

    /// <summary>UI引脚的回调节点名</summary>
    private string callbackNodeName;
    public string CallbackNodeName
    {
        get { return callbackNodeName; }
        set
        {
            callbackNodeName = value;
            if (!string.IsNullOrEmpty(callbackNodeName))
            {
                onClick = () =>
                {
                    EditorNode node = PLATO.CreateNode(callbackNodeName, ParentNode.plato) as EditorNode;
                    node.SourcePin = this;
                    node.Position = new Vector2(ParentNode.Position.x + 150, ParentNode.Position.y);
                    node.SetTarget(ParentNode, IsInput);

                    EditorWindow.focusedWindow.Repaint();
                };
            }
        }
    }

    private Type ExportType;
    public string CSharpArg;

    public override void Parse(string key, object value)
    {
        base.Parse(key, value);

        if (key == "Callback")
        {
            CallbackNodeName = value as string;
        }
        else if (key == "ExportType")
        {
            ExportType = SLua.LuaObject.FindType(value as string);
        }
        else if (key == "CSharpArg")
        {
            CSharpArg = value as string;
        }
    }
    public override Color GetColor()
    {
        return Color.clear;
    }

    public override void OnDraw()
    {
        if (GUILayout.Button(Title, GUILayout.Height(16)))
        {
            if (onClick != null)
                onClick();
        }
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
        return string.Empty;
    }

    public override string ExportToCSharp()
    {
        return string.Empty;
    }

    public override string CppValue(string cpp_node)
    {
        return string.Empty;
    }

    public override PlatoPin DoClone()
    {
        ButtonPin ret = new ButtonPin();
        ret.CallbackNodeName = CallbackNodeName;
        ret.ExportType = ExportType;
        ret.CSharpArg = CSharpArg;
        return ret;
    }

    public override void ExportCppParam(PlatoWriter writer, ref int index)
    {
        if (ExportType != null)
        {
            writer.Line("GETTER_SETTER_REF_PLATO({0}s, {1}, {2}s, {3});", CallbackNodeName, PinTypeUtil.GetCppVectorType(ExportType), CallbackNodeName.ToLower(), index++);
            writer.Line("void set{0}(uint32_t index, {1} value);", CallbackNodeName, PinTypeUtil.GetCppType(ExportType));
        }
    }

    public override void ExportCppField(PlatoWriter writer)
    {
        if (ExportType != null)
            writer.Line("CLASS_FIELD({0}s, {1});", CallbackNodeName.ToLower(), PinTypeUtil.GetCppVectorType(ExportType));
    }
}
