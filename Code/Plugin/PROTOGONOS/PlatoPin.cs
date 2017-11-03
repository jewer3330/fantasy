using UnityEngine;
using UnityEngine.UI;
using UnityEditor;
using System;
using System.Collections;
using System.Collections.Generic;
using SLua;

/// <summary>
/// 节点引脚
/// </summary>
public abstract class PlatoPin : IComparable<PlatoPin>
{
    /// <summary>引脚绘制高度</summary>
    protected static readonly int PinHeight = 16;

    public virtual void Parse(string key, object value)
    {
        if (key == "Title")
            Title = value as string;
        else if (key == "Type")
            Type = LuaObject.FindType(value as string);
        else if (key == "PinFormat")
            PinFormat = value as string;
        else if (key == "CSharpPinFormat")
            CSharpPinFormat = value as string;
        else if (key == "CppSkip")
            IsCppSkip = Convert.ToBoolean(value);
    }
    public abstract Color GetColor();
    public abstract void OnDraw();
    public abstract string SaveValue();
    public abstract void LoadValue(object value);
    public abstract string ExportToLua();
    public abstract string ExportToCSharp();
    public abstract string CppValue(string cpp_node);
    public abstract PlatoPin DoClone();
    public virtual void PostLoad()
    {
        if (Value == null)
            PinTypeUtil.SetDefault(this);
    }
    public virtual void ExportCppParam(PlatoWriter writer, ref int index)
    {
        if (PinTypeUtil.IsRefType(this))
            writer.Line("GETTER_SETTER_REF_PLATO({0}, {1}, {2}, {3});", Title, PinTypeUtil.GetCppType(Type), Title.ToLower(), index++);
        else
            writer.Line("GETTER_SETTER_PLATO({0}, {1}, {2}, {3});", Title, PinTypeUtil.GetCppType(Type), Title.ToLower(), index++);
    }
    public virtual void ExportCppField(PlatoWriter writer)
    {
        writer.Line("CLASS_FIELD({0}, {1});", Title.ToLower(), PinTypeUtil.GetCppType(Type));
    }
    public virtual void ExportCppPin(PlatoWriter writer, string cpp_node)
    {
        writer.Line("        node{0}->set{1}({2});", ParentNode.ID, Title, CppValue(cpp_node));
    }

    public int CompareTo(PlatoPin other)
    {
        string A = string.Format("{0}_{1}_{2}", this.ParentNode.Title, this.ParentNode.ID, this.Title);
        string B = string.Format("{0}_{1}_{2}", other.ParentNode.Title, other.ParentNode.ID, other.Title);
        return string.Compare(A, B);
    }

    public void Save(PlatoWriter writer)
    {
        writer.Line("title = '{0}',", Title);
        writer.Line("type = '{0}',", Type == null ? "null" : Type.ToString());
        writer.Line("dynamic = {0},", IsDynamic ? "true" : "false");
        writer.Line("parent = '{0}',", ParentPin);
        writer.Line("index = {0},", ChildIndex);
        string value = SaveValue();
        if (!string.IsNullOrEmpty(value)) writer.Line("value = {0},", value);
    }

    public void Load(string key, object value)
    {
        if (key == "title")
            Title = value as string;
        else if (key == "type")
            Type = LuaObject.FindType(value as string);
        else if (key == "dynamic")
            IsDynamic = Convert.ToBoolean(value);
        else if (key == "parent")
            ParentPin = value as string;
        else if (key == "index")
            ChildIndex = Convert.ToInt32(value);
        else if (key == "value")
            LoadValue(value);
    }

    public PlatoPin Clone()
    {
        PlatoPin ret = DoClone();
        ret.Title = Title;
        ret.Type = Type;
        ret.Value = Value;
        ret.PinFormat = PinFormat;
        ret.CSharpPinFormat = CSharpPinFormat;
        ret.ParentPin = ParentPin;
        ret.ChildIndex = ChildIndex;
        ret.IsCppSkip = IsCppSkip;
        ret.IsDynamic = IsDynamic;
        ret.IsInput = IsInput;
        return ret;
    }

    /// <summary>是否是输入引脚</summary>
    public bool IsInput;
    /// <summary>引脚名</summary>
    public string Title;
    /// <summary>节点类型</summary>
    public Type Type;
    /// <summary>是否是动态引脚</summary>
    public bool IsDynamic;
    /// <summary>C++导出是否跳过</summary>
    public bool IsCppSkip;
    /// <summary>是否调试</summary>
    public bool IsDebug;
    /// <summary>引脚前驱列表</summary>
    public List<PlatoPin> Prevs = new List<PlatoPin>();
    /// <summary>引脚后继列表</summary>
    public List<PlatoPin> Nexts = new List<PlatoPin>();
    /// <summary>兄弟引脚</summary>
    public PlatoPin Sibling;
    /// <summary>所属节点</summary>
    public PlatoNode ParentNode;
    /// <summary>所属引脚</summary>
    public string ParentPin;
    /// <summary>所属引脚索引</summary>
    public int ChildIndex;
    /// <summary>引脚值</summary>
    public object Value;
    /// <summary>引脚坐标大小</summary>
    public Rect PinRect;
    /// <summary>引脚导出格式</summary>
    public string PinFormat;
    /// <summary>C#引脚导出格式</summary>
    public string CSharpPinFormat;

    /// <summary>
    /// 默认构造函数
    /// </summary>
    public PlatoPin()
    {

    }

    /// <summary>
    /// 构造函数
    /// </summary>
    /// <param name="title">名字</param>
    /// <param name="type">类型</param>
    /// <param name="isInput">是否是输入</param>
    /// <param name="parent">所属节点</param>
    public PlatoPin(string title, Type type, bool isInput, PlatoNode parent)
    {
        Title = title;
        Type = type;
        IsInput = isInput;
        ParentNode = parent;
    }

    /// <summary>
    /// 添加前驱
    /// </summary>
    /// <param name="pin"></param>
    public void AddPrev(PlatoPin pin)
    {
        Prevs.Add(pin);
    }

    /// <summary>
    /// 添加后继
    /// </summary>
    /// <param name="pin"></param>
    public void AddNext(PlatoPin pin)
    {
        Nexts.Add(pin);
        // 赋值
        pin.Value = Value;
    }

    /// <summary>
    /// 移除前驱
    /// </summary>
    /// <param name="pin"></param>
    public void RemovePrev(PlatoPin pin)
    {
        Prevs.Remove(pin);
    }

    /// <summary>
    /// 移除后继
    /// </summary>
    /// <param name="pin"></param>
    public void RemoveNext(PlatoPin pin)
    {
        Nexts.Remove(pin);
    }

    /// <summary>
    /// 清空所有前驱与后继
    /// </summary>
    public void Clear()
    {
        foreach (PlatoPin pin in Prevs)
        {
            pin.RemoveNext(this);
        }
        Prevs.Clear();

        foreach (PlatoPin pin in Nexts)
        {
            pin.RemovePrev(this);
        }
        Nexts.Clear();
    }

    /// <summary>
    /// 设置兄弟
    /// </summary>
    /// <param name="pin"></param>
    public void SetSibling(PlatoPin pin)
    {
        Sibling = pin;
    }

    public void Draw()
    {
        EditorGUIUtility.labelWidth = 75.0f;
        EditorGUIUtility.fieldWidth = 100.0f;

        GUILayout.BeginHorizontal();
        // 非UI输入引脚，绘制输入点
        if (IsInput && !PinTypeUtil.IsUI(this))
        {
            if (Type != null && Type.IsArray)
                DrawArrayPin();
            else
                DrawPin();
        }

        // 自定义绘制
        if (ParentNode.Title != "Reroute")
        {
            OnDraw();
        }

        // 非UI输出引脚，绘制输出点
        if (!IsInput && !PinTypeUtil.IsUI(this))
        {
            if (Type != null && Type.IsArray)
                DrawArrayPin();
            else
                DrawPin();
        }
        GUILayout.EndHorizontal();
    }

    /// <summary>
    /// 绘制圆点
    /// </summary>
    void DrawPin()
    {
        GUI.color = GetColor();
        GUILayout.Box("", "Pin", GUILayout.Height(16));
        if (GUILayoutUtility.GetLastRect().height == 16)
            PinRect = GUILayoutUtility.GetLastRect();
        GUI.color = Color.white;
    }

    /// <summary>
    /// 绘制数组引脚
    /// </summary>
    void DrawArrayPin()
    {
        GUI.color = GetColor();
        GUILayout.Box("", "ArrayPin", GUILayout.Height(12));
        if (GUILayoutUtility.GetLastRect().height == 12)
            PinRect = GUILayoutUtility.GetLastRect();
        GUI.color = Color.white;
    }
}
