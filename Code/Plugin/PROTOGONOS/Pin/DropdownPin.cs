using UnityEngine;
using UnityEngine.UI;
using UnityEditor;
using System;
using System.Collections;
using System.Collections.Generic;
using SLua;

public class DropdownPin : PlatoPin
{
    /// <summary>
    /// 下拉框引脚的数据变动回调
    /// </summary>
    /// <param name="index"></param>
    public delegate void OnDropdownChanged(int index);
    public OnDropdownChanged onChanged;

    /// <summary>下拉框数据</summary>
    public List<string> DropdownList = new List<string>();
    public int oldIndex;
    public List<List<KeyValuePair<string, Type>>> PinDefines = new List<List<KeyValuePair<string, Type>>>();
    public bool IsOuputPins;

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
                onChanged = (int newIndex) =>
                {
                    if (oldIndex == newIndex)
                        return;
                    oldIndex = newIndex;

                    EditorNode node = PLATO.CreateNode(callbackNodeName, ParentNode.plato) as EditorNode;
                    node.SourcePin = this;
                    node.Position = new Vector2(ParentNode.Position.x + 150, ParentNode.Position.y);
                    node.SetTarget(ParentNode, IsInput);

                    EditorWindow.focusedWindow.Repaint();
                };
            }
        }
    }

    public override void Parse(string key, object value)
    {
        base.Parse(key, value);

        if (key == "Items")
        {
            DropdownList.Clear();
            foreach (string item in (value as string).Split(';'))
                DropdownList.Add(item);
        }
        else if (key == "PinDefines")
        {
            ParsePinDefines(value as string);
        }
        else if (key == "OutputPins")
        {
            IsOuputPins = Convert.ToBoolean(value);
        }
        else if (key == "Callback")
        {
            CallbackNodeName = value as string;
        }
    }

    private void ParsePinDefines(string pinDefines)
    {
        PinDefines.Clear();
        if (!string.IsNullOrEmpty(pinDefines))
        {
            try
            {
                char[] semicolon = { ';' };
                string[] defines = pinDefines.Split(semicolon, StringSplitOptions.RemoveEmptyEntries);
                foreach (string def in defines)
                {
                    List<KeyValuePair<string, Type>> defList = new List<KeyValuePair<string, Type>>();
                    ParsePinDefines(defList, def);
                    PinDefines.Add(defList);
                }
            }
            catch (Exception e)
            {
                Debug.LogError(e.Message);
            }
        }
    }

    private void ParsePinDefines(List<KeyValuePair<string, Type>> defList, string def)
    {
        char[] line = { '-' };
        string[] second = def.Split(line, StringSplitOptions.RemoveEmptyEntries);
        char[] colon = { ':' };
        for (int i = 0; i < second.Length; ++i)
        {
            string[] final = second[i].Split(colon, StringSplitOptions.RemoveEmptyEntries);
            if (final.Length == 2)
            {
                Type type = LuaObject.FindType(final[1]);
                if (type != null) // skip null
                {
                    defList.Add(new KeyValuePair<string, Type>(final[0], type));
                }
                else
                {
                    // type error
                    if (!final[1].Equals("null", StringComparison.OrdinalIgnoreCase))
                    {
                        throw new Exception(string.Format("ParsePinDefines error: type error {0}", final[1]));
                    }
                }
            }
            else
            {
                if (final.Length > 2)
                    throw new Exception("ParsePinDefines error: length error");
            }
        }
    }

    private void SetupPin(int newIndex)
    {
        if (PinDefines.Count <= 0)
            return;

        List<KeyValuePair<string, Type>> pins = PinDefines[oldIndex];
        foreach (KeyValuePair<string, Type> p in pins)
        {
            ParentNode.RemovePin(ParentNode.FindPinByTitle(p.Key, !IsOuputPins));
        }

        PlatoPin last = this;
        if (IsOuputPins && IsInput)
            last = ParentNode.GetLastPin(false);

        pins = PinDefines[newIndex];
        for (int i = 0; i < pins.Count; ++i)
        {
            if (pins[i].Value == null)
                continue;
            PlatoPin newPin = PlatoNodeGenerator.CreatePin(pins[i].Value);
            newPin.Title = pins[i].Key;
            newPin.IsInput = !IsOuputPins;
            newPin.ParentPin = Title;
            newPin.ChildIndex = i;
            ParentNode.InsertPinAfter(newPin, last);
            last = newPin;
        }
    }

    public override Color GetColor()
    {
        return Color.clear;
    }

    public override void OnDraw()
    {
        int newIndex = EditorGUILayout.Popup(Title, oldIndex, DropdownList.ToArray());
        if (newIndex < 0 || newIndex >= DropdownList.Count)
            return;
        Value = DropdownList[newIndex];

        if (PinDefines.Count > 0 && oldIndex != newIndex)
        {
            SetupPin(newIndex);
        }

        if (onChanged != null)
            onChanged(newIndex);
        else
            oldIndex = newIndex;
    }

    public override string SaveValue()
    {
        return string.Format("'{0}'", Value);
    }

    public override void LoadValue(object value)
    {
        Value = value as string;
    }

    public override string ExportToLua()
    {
        return SaveValue();
    }

    public override string ExportToCSharp()
    {
        if (!string.IsNullOrEmpty(CallbackNodeName))
            return string.Format("\"{0}\"", Value);
        else
            return string.Format("{0}.{1}.{2}.{3}", ParentNode.Category, ParentNode.Title, Title, Value);
    }

    public override void ExportCppPin(PlatoWriter writer, string cpp_node)
    {
        base.ExportCppPin(writer, cpp_node);

        List<PlatoPin> myPins = ParentNode.GetAllInPins().FindAll((p) => p.ParentPin == Title);
        if (myPins.Count == 0)
            return;

        if (IsSameType(this))
        {
            foreach (PlatoPin p in myPins)
            {
                writer.Line("        node{0}->set{1}Params({2}, {3});", ParentNode.ID, Title, p.ChildIndex, p.CppValue(cpp_node));
            }
        }
        else
        {
            writer.Line("        node{0}->getVars().reserve({1});", ParentNode.ID, myPins.Count);
            foreach (PlatoPin p in myPins)
            {
                writer.Line("        node{0}->getVars().setVariable<{1}>({2}, {3});", ParentNode.ID, PinTypeUtil.GetCppType(p.Type), p.ChildIndex, p.CppValue(cpp_node));
            }
        }
    }

    public override string CppValue(string cpp_node)
    {
        // Drama Export
        if (string.IsNullOrEmpty(cpp_node))
            return string.Format("\"{0}\"", Value);
        else
            return string.Format("{0}_{1}::{1}_{2}::{3}", cpp_node, ParentNode.Title, Title, Value);
    }

    public override PlatoPin DoClone()
    {
        DropdownPin pin = new DropdownPin();
        pin.CallbackNodeName = CallbackNodeName;
        pin.DropdownList = new List<string>(DropdownList);
        pin.PinDefines = new List<List<KeyValuePair<string,Type>>>(PinDefines);
        pin.IsOuputPins = IsOuputPins;
        pin.oldIndex = oldIndex;
        return pin;
    }

    public override void PostLoad()
    {
        base.PostLoad();

        if (!string.IsNullOrEmpty(callbackNodeName))
        {
            EditorNode node = PLATO.CreateNode(callbackNodeName, ParentNode.plato) as EditorNode;
            node.Position = new Vector2(ParentNode.Position.x + 150, ParentNode.Position.y);
            node.SetTarget(ParentNode, IsInput);
        }

        PlatoPin childPin = null;
        if (IsOuputPins)
            childPin = ParentNode.GetAllOutPins().Find((PlatoPin p) => { return p.ParentPin == Title; });
        else
            childPin = ParentNode.GetAllInPins().Find((PlatoPin p) => { return p.ParentPin == Title; });

        // 创建节点
        if (string.IsNullOrEmpty(Value as string))
        {
            Value = DropdownList[0];
            SetupPin(oldIndex);
        }
        // 加载节点
        else
        {
            oldIndex = DropdownList.IndexOf(Value as string);
        }
    }

    public override void ExportCppParam(PlatoWriter writer, ref int index)
    {
        if (PinDefines.Count > 0)
        {
            writer.Line("GETTER_SETTER_PLATO({0}, int32_t, {1}, {2});", Title, Title.ToLower(), index++);

            Type baseType;
            if (IsSameType(this, out baseType))
                writer.Line("GETTER_SETTER_REF_PLATO({0}Params, {1}, {2}params, {3});", Title, PinTypeUtil.GetCppVectorType(baseType), Title.ToLower(), index++);
            else
                writer.Line("GETTER_SETTER_REF_PLATO(Vars, VariableList, vars, {0});", index++);
        }
        else
        {
            base.ExportCppParam(writer, ref index);
        }
    }

    public override void ExportCppField(PlatoWriter writer)
    {
        if (PinDefines.Count > 0)
        {
            writer.Line("CLASS_FIELD({0}, int32_t);", Title.ToLower());
            Type baseType;
            if (IsSameType(this, out baseType))
                writer.Line("CLASS_FIELD({0}params, {1});", Title.ToLower(), PinTypeUtil.GetCppVectorType(baseType));
            else
                writer.Line("CLASS_FIELD(vars, VariableList);");
        }
        else
        {
            base.ExportCppField(writer);
        }
    }

    public static bool IsSameType(DropdownPin pin, out Type baseType)
    {
        baseType = null;
        if (pin.PinDefines.Count > 0)
        {
            foreach (var list in pin.PinDefines)
            {
                foreach (var it in list)
                {
                    if (baseType == null)
                    {
                        baseType = it.Value;
                        continue;
                    }
                    else
                    {
                        if (baseType != it.Value)
                        {
                            return false;
                        }
                    }
                }
            }
            if (baseType != null)
                return true;
        }
        return false;
    }

    private static bool IsSameType(DropdownPin pin)
    {
        Type baseType;
        return IsSameType(pin, out baseType);
    }
}
