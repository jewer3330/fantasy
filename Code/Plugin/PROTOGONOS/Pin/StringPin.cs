using UnityEngine;
using UnityEditor;
using System;
using System.Collections;

public class StringPin : PlatoPin
{
	/// <summary>需要将字符串引脚转换成CSV表中的索引时对应的表名</summary>
    public string TableName;

    public override void Parse(string key, object value)
    {
        base.Parse(key, value);

        if (key == "TableName")
        {
            TableName = value as string;
        }
    }

    public override Color GetColor()
    {
        return Color.magenta;
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

    public override void LoadValue(object value)
    {
        Value = Convert.ToString(value);
    }

    public override string ExportToLua()
    {
        // 如果需要将属性转成索引
        if (string.IsNullOrEmpty(TableName))
            return SaveValue();
        else
            return string.Format("{0}", EditorUtil.GetCSVIndex(TableName, (string)Value));
    }

    public override string ExportToCSharp()
    {
        // 如果需要将属性转成索引
        if (string.IsNullOrEmpty(TableName))
            return string.Format("\"{0}\"", Value.ToString());
        else
            return string.Format("{0}", EditorUtil.GetCSVIndex(TableName, (string)Value));
    }

    public override string CppValue(string cpp_node)
    {
        // 如果需要将属性转成索引
        if (string.IsNullOrEmpty(TableName))
            return string.Format("\"{0}\"", Value);
        else
            return string.Format("{0}", EditorUtil.GetCSVIndex(TableName, (string)Value));
    }

    public override PlatoPin DoClone()
    {
        StringPin ret = new StringPin();
        ret.TableName = TableName;
        return ret;
    }

    public override void ExportCppParam(PlatoWriter writer, ref int index)
    {
        if (!string.IsNullOrEmpty(TableName))
            writer.Line("GETTER_SETTER_PLATO({0}, {1}, {2}, {3});", Title, PinTypeUtil.GetCppType(typeof(int)), Title.ToLower(), index++);
        else
            base.ExportCppParam(writer, ref index);
    }

    public override void ExportCppField(PlatoWriter writer)
    {
        if (!string.IsNullOrEmpty(TableName))
            writer.Line("CLASS_FIELD({0}, {1});", Title.ToLower(), PinTypeUtil.GetCppType(typeof(int)));
        else
            base.ExportCppField(writer);
    }
}
