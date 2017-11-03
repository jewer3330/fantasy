using UnityEngine;
using UnityEngine.UI;
using UnityEditor;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;


/// <summary>
/// 节点
/// </summary>
public class PlatoNode : IComparable<PlatoNode>
{
    /// <summary>标题高度</summary>
    protected static readonly float HeadHeight = 18.0f;
    /// <summary>行高</summary>
    protected static readonly float LineHeight = 16.0f;


    /// <summary>输入引脚头</summary>
    protected PlatoPin inPinHead;
    /// <summary>输出引脚头</summary>
    protected PlatoPin outPinHead;
    /// <summary>输入或者输出的最大数量</summary>
    protected int maxPinCount = 0;
    /// <summary>动态引脚列表</summary>
    protected List<PlatoPin> dynamicPins = new List<PlatoPin>();

    /// <summary>窗口大小坐标</summary>
    protected Rect rect = new Rect(0, 0, 20, 20);
    /// <summary>设置坐标</summary>
    public Vector2 Position
    {
        get
        {
            return new Vector2(rect.x, rect.y);
        }
        set
        {
            rect = new Rect(rect) { x = value.x, y = value.y };
        }
    }
    /// <summary>窗口大小</summary>
    public Vector2 Size
    {
        get
        {
            return new Vector2(rect.width, rect.height);
        }
        set
        {
            rect = new Rect(rect) { width = value.x, height = value.y };
        }
    }

    public int CompareTo(PlatoNode other)
    {
        return ID - other.ID;
    }

    /// <summary>窗口颜色</summary>
    protected Color color;
    public void SetColor(Color color) { this.color = color; }

    /// <summary>所属Plato</summary>
    public PLATO plato;
    /// <summary>是否选中</summary>
    public bool IsFocus { get; set; }
    /// <summary>是否调试</summary>
    public bool IsDebug { get; set; }
    /// <summary>是否断点</summary>
    public bool IsBreak { get; set; }
    /// <summary>是否触发断点</summary>
    public bool IsBreaking { get; set; }
    /// <summary>是否同步</summary>
    public bool Sync { get; set; }
    /// <summary>标题</summary>
    public string Title { get; set; }
    /// <summary>类别</summary>
    public string Category { get; set; }
    /// <summary>导出格式</summary>
    public string FormatLua { get; set; }
    public string FormatCpp { get; set; }
    public string FormatCSharp { get; set; }
    /// <summary>导出索引</summary>
    public string Key { get; set; }
    /// <summary>是否导出Call调用</summary>
    public bool ExportCall { get; set; }
    /// <summary>ID属性</summary>
    private int id;
    public int ID
    {
        get { return id; }
        set
        {
            id = value;
            if (plato != null && id >= plato.MaxNodeID)
            {
                plato.MaxNodeID = value;
            }
        }
    }

    /// <summary>关卡编辑器专用GUI Skin</summary>
    public static GUISkin skin;
    static GUIStyle focusStyle;
    static PlatoNode()
    {
        skin = AssetDatabase.LoadAssetAtPath<GUISkin>("Assets/Editor/PROTOGONOS/PROTOGONOS.guiskin");
        focusStyle = new GUIStyle(skin.FindStyle("Window"));
        focusStyle.normal.background = focusStyle.onNormal.background;
    }
    /// <summary>
    /// 构造函数
    /// </summary>
    public PlatoNode()
    {
        if (plato != null)
            ID = ++plato.MaxNodeID;
        ExportCall = true;
    }

    /// <summary>
    /// 克隆
    /// </summary>
    /// <returns></returns>
    public PlatoNode Clone(PLATO plato)
    {
        PlatoNode node = null;
        if (this is EditorNode)
        {
            node = GetType().GetConstructor(Type.EmptyTypes).Invoke(null) as PlatoNode;
            node.plato = plato;
            node.ID = ++plato.MaxNodeID;
            return node;
        }

        node = new PlatoNode();
        node.plato = plato;
        node.ID = ++plato.MaxNodeID;
        node.Category = Category;
        node.Title = Title;
        node.Key = Key;
        node.FormatLua = FormatLua;
        node.FormatCpp = FormatCpp;
        node.FormatCSharp = FormatCSharp;
        node.color = color;
        node.ExportCall = ExportCall;
        node.Sync = Sync;

        // 设置输入引脚
        PlatoPin inPin = inPinHead;
        while (inPin != null)
        {
            node.AddPin(inPin.Clone());
			inPin = inPin.Sibling;
        }

        // 设置输出引脚
        PlatoPin outPin = outPinHead;
        while (outPin != null)
        {
            node.AddPin(outPin.Clone());
            outPin = outPin.Sibling;
        }

        node.CalcuRect();
        return node;
    }

    /// <summary>是否已经导出</summary>
    private bool isExported = false;
    /// <summary>重置导出</summary>
    public void ResetExported() { isExported = false; }

    /// <summary>
    /// 简单格式导出
    /// </summary>
    /// <returns></returns>
    string ExportFormat(string format)
    {
        // 解析形如print({Message})的格式，遇到{}对的时候
        // 将Message替换为ExportInPinByTitle("Message")
        try
        {
            List<char> code = new List<char>();
            int i = 0;
            while (i < format.Length)
            {
                char c = format[i];
                if (c == '{')
                {
                    // 一直遍历到}为止，将{}中间的内容作为pinName
                    List<char> pinNameList = new List<char>();
                    while (++i < format.Length)
                    {
                        c = format[i];
                        if (c == '}')
                        {
                            ++i;
                            break;
                        }
                        else
                        {
                            pinNameList.Add(c);
                        }
                    }

                    string pinName = new string(pinNameList.ToArray());
                    // 特殊标记，节点ID
                    if (pinName == "NODE_ID")
                    {
                        code.AddRange(ID.ToString());
                    }
                    // 特殊标记，所有动态输入引脚
                    else if (pinName == "DYNAMIC_INPUTS")
                    {
                        List<string> inputs = new List<string>();
                        for (int j = 0; j < GetDynamicPinCount(); ++j)
                        {
                            PlatoPin pin = FindDyanmicPinByIndex(j);
                            if (pin.IsInput == true)
                                inputs.Add(ExportInPinByTitleLua(pin.Title));
                        }
                        code.AddRange(string.Join(", ", inputs.ToArray()));
                    }
                    else
                    {
                        // 先从输入引脚开始查找
                        PlatoPin pin = FindPinByTitle(pinName, true);
                        if (pin == null)
                        {
                            // 没有找到就查找输出引脚
                            pin = FindPinByTitle(pinName, false);
                            if (pin != null)
                            {
                                if (format == FormatLua)
                                    code.AddRange(pin.ExportToLua());
                                else
                                    code.AddRange(pin.CppValue(string.Empty));
                            }
                            else
                                throw new System.Exception();
                        }
                        else
                        {
                            if (format == FormatLua)
                                code.AddRange(ExportInPinByTitleLua(pinName));
                            else
                                code.AddRange(ExportInPinByTitleCpp(pinName));
                        }
                    }
                }
                else
                {
                    code.Add(c);
                    ++i;
                }
            }
            return new string(code.ToArray());
        }
        catch
        {
            Debug.LogError(string.Format("Format error: [{0}.{1}] '{2}'", Category, Title, format));
        }
        return string.Empty;
    }

    /// <summary>
    /// 导出输入引脚
    /// </summary>
    /// <param name="title"></param>
    /// <returns></returns>
    public virtual string ExportInPinByTitleLua(string title)
    {
        PlatoPin pin = FindPinByTitle(title, true);
        // 如果有前驱，使用前驱的输出
        if (pin.Prevs.Count == 1)
        {
            PlatoPin prev = pin.Prevs[0];
            while (prev.ParentNode.Title == "Reroute")
            {
                prev = prev.Prevs[0];
            }
            return prev.ParentNode.ExportOutPinByTitleLua(prev.Title);
        }
        else
        {
            return pin.ExportToLua();
        }
    }

    /// <summary>
    /// 导出输出引脚
    /// </summary>
    /// <param name="title"></param>
    /// <returns></returns>
    public virtual string ExportOutPinByTitleLua(string title)
    {
        // 有格式，使用格式导出代码
        if (!string.IsNullOrEmpty(FormatLua))
            return ExportFormat(FormatLua);
        else if (Category == "Get" && !Title.Contains("Location") && !Title.Contains("Rotation") && !Title.Contains("State") && !(Title == "GetProjOwnerAttr")) // 变量类型，需要执行调用
            return string.Format("Local.{0}_{1}", Title, ID);
        else
            return string.Format("{0}_{1}", title, ID);
    }

    public void ExportCpp(PlatoWriter writer, string funcName)
    {
        if (isExported)
            return;
        if (inPinHead == null && outPinHead == null)
            return;

        // 有导出格式，则实用格式简单导出
        if (!string.IsNullOrEmpty(FormatCpp))
        {
            writer.Line(ExportFormat(FormatCpp));
            return;
        }

        List<string> inputs = new List<string>();
        inputs.Add(funcName);

        // TODO(kai.zou): 特殊处理的代码是没有灵魂的
        if (Title == "ObjectActive")
        {
            GameObject obj = FindPinByTitle("Target", true).Value as GameObject;
            if (obj != null && obj.GetComponent<DamageVolume>() != null)
            {
                PlatoNode damageNode = null;
                foreach (PlatoNode node in PROTOGONOS.Instance.plato.graph.GetAllNodes())
                {
                    if (node.Title != "OnDamageVolume")
                        continue;
                    if (node.FindPinByTitle("Target", true).Value == obj)
                    {
                        damageNode = node;
                        break;
                    }
                }
                if (damageNode != null)
                    writer.Line("DramaDamageVolumeActive* objectactive_{0} = new DramaDamageVolumeActive({1}, ondamagevolume_{2}, {3}, {4});", ID, funcName, damageNode.ID, FindPinByTitle("IsActive", true).CppValue(string.Empty), FindPinByTitle("Target", true).CppValue(string.Empty));
            }
            else
            {
                // 获取输入参数
                foreach (PlatoPin pin in GetAllInPins())
                {
                    if (!PinTypeUtil.IsValue(pin) || pin.IsDynamic || pin.IsCppSkip)
                        continue;
                    inputs.Add(ExportInPinByTitleCpp(pin.Title));
                }

                // DramaNode* node_id = new DramaNode(func, ...);
                writer.Line("Drama{0}* {1}_{2} = new Drama{0}({3});", Title, Title.ToLower(), ID, string.Join(", ", inputs.ToArray()));
            }
        }
        else
        {
            // 获取输入参数
            foreach (PlatoPin pin in GetAllInPins())
            {
                if (!PinTypeUtil.IsValue(pin) || pin.IsDynamic || pin.IsCppSkip)
                    continue;
                inputs.Add(ExportInPinByTitleCpp(pin.Title));
            }

            // DramaNode* node_id = new DramaNode(func, ...);
            writer.Line("Drama{0}* {1}_{2} = new Drama{0}({3});", Title, Title.ToLower(), ID, string.Join(", ", inputs.ToArray()));
        }

        isExported = true;
    }

    public void LinkCpp(PlatoWriter writer)
    {
        if (Title != "CallFunction")
        {
            foreach (PlatoPin pin in GetAllInPins())
            {
                // 值类型引脚
                if (pin.Type != null && pin.Prevs.Count == 1)
                {
                    writer.Line("{0}_{1}->set{2}ParamName({3});", Title.ToLower(), ID, pin.Title, ExportValueParamCpp(pin.Prevs[0].ParentNode, pin, pin.Prevs[0]));
                }
            }
        }
        else
        {
            foreach (PlatoPin pin in GetAllInPins())
            {
                if (!pin.IsDynamic)
                    continue;

                DropdownPin funcPin = FindPinByTitle<DropdownPin>("Function", true);
                string funcName = funcPin.DropdownList[(int)funcPin.Value];

                string prevName = string.Empty;
                if (pin.Prevs.Count == 1)
                    prevName = ExportValueParamCpp(pin.Prevs[0].ParentNode, pin, pin.Prevs[0]);

                writer.Line("{0}_{1}->addParam(\"{2}_{3}\", DramaVariable({4}), \"{5}\");", Title.ToLower(), ID, funcName, pin.Title, pin.Value, prevName);
            }
        }

        foreach (PlatoPin pin in GetAllOutPins())
        {
            // 事件引脚
            if (pin.Type == null)
            {
                if (pin.IsDynamic)
                {
                    bool hasNext = false;
                    foreach (PlatoPin next in pin.Nexts)
                    {
                        if (PLATO.FilterExport(next.ParentNode))
                            continue;
                        hasNext = true;
                        writer.Line("{0}_{1}->addPin(\"{2}\", {3}_{4});", Title.ToLower(), ID, pin.Title, next.ParentNode.Title.ToLower(), next.ParentNode.ID);
                    }
                    if (!hasNext)
                        writer.Line("{0}_{1}->addPin(\"{2}\", NULL);", Title.ToLower(), ID, pin.Title);
                }
                else
                {
                    foreach (PlatoPin next in pin.Nexts)
                    {
                        if (PLATO.FilterExport(next.ParentNode))
                            continue;
                        writer.Line("{0}_{1}->getOutput()->addNode(\"{2}\", {3}_{4});", Title.ToLower(), ID, pin.Title, next.ParentNode.Title.ToLower(), next.ParentNode.ID);
                    }
                }
            }
            // 值类型引脚
            else if (pin.Nexts.Count > 0)
            {
                writer.Line("{0}_{1}->set{2}ParamName({3});", Title.ToLower(), ID, pin.Title, ExportValueParamCpp(this, pin, pin));
            }
        }
    }

    string ExportValueParamCpp(PlatoNode node, PlatoPin pin, PlatoPin prev)
    {
        if (pin.Type == typeof(Button))
            return string.Empty;
        if (prev.ParentNode.Category == "Get")
            return string.Format("\"{0}\"", prev.ParentNode.FindPinByTitle("Name", true).Value);
        else if (prev.ParentNode.Title == "FunctionStart")
            return string.Format("\"{0}_{1}\"", prev.ParentNode.FindPinByTitle("Name", true).Value, pin.Title);
        else
            return string.Format("\"{0}_{1}_{2}\"", node.Title.ToLower(), node.ID, prev.Title);
    }

    public virtual string ExportInPinByTitleCpp(string title)
    {
        PlatoPin pin = FindPinByTitle(title, true);
        return pin.CppValue(string.Empty);
    }

    /// <summary>
    /// 清空引脚
    /// </summary>
    public void Clear()
    {
        PlatoPin inPin = inPinHead;
        while (inPin != null)
        {
            foreach (PlatoPin pin in inPin.Prevs)
            {
                pin.Nexts.Remove(inPin);
            }
            inPin.Prevs.Clear();
            inPin = inPin.Sibling;
        }

        PlatoPin outPin = outPinHead;
        while (outPin != null)
        {
            foreach (PlatoPin pin in outPin.Nexts)
            {
                pin.Prevs.Remove(outPin);
            }
            outPin.Nexts.Clear();
            outPin = outPin.Sibling;
        }
    }

    /// <summary>
    /// 删除引脚
    /// </summary>
    /// <param name="pin"></param>
    public void RemovePin(PlatoPin pin)
    {
        if (pin == null)
            return;

        if (pin.IsInput == true && pin == inPinHead)
        {
            inPinHead = pin.Sibling;
        }
        else if (pin.IsInput == false && pin == outPinHead)
        {
            outPinHead = pin.Sibling;
        }
        else
        {
            PlatoPin runner = pin.IsInput ? inPinHead : outPinHead;
            while (runner != null)
            {
                if (runner.Sibling == pin)
                {
                    runner.SetSibling(pin.Sibling);
                    break;
                }
                runner = runner.Sibling;
            }
        }
        CalcuRect();
    }

    public PlatoPin AddPin(PlatoPin pin)
    {
        pin.ParentNode = this;

        PlatoPin head = null;
        if (pin.IsInput)
            head = inPinHead;
        else
            head = outPinHead;

        if (head == null)
        {
            if (pin.IsInput)
                inPinHead = pin;
            else
                outPinHead = pin;
        }
        else
        {
            PlatoPin runner = head;
            while (runner.Sibling != null) runner = runner.Sibling;
            runner.SetSibling(pin);
        }

        CalcuRect();
        return pin;
    }
    /// <summary>
    /// 添加引脚
    /// </summary>
    /// <param name="name">名字</param>
    /// <param name="type">类型</param>
    /// <param name="isInput">是否是输入</param>
    /// <returns></returns>
    public PlatoPin AddPin(string name, Type type, bool isInput)
    {
        PlatoPin pin = PlatoNodeGenerator.CreatePin(type);
        pin.Title = name;
        pin.IsInput = isInput;
        return AddPin(pin);
    }

    public T AddPin<T>(string name, Type type, bool isInput) where T : PlatoPin
    {
        T pin = PlatoNodeGenerator.CreatePin(type) as T;
        pin.Title = name;
        pin.IsInput = isInput;
        return (AddPin(pin) as T);
    }

    /// <summary>
    /// 在指定位置后插入引脚
    /// </summary>
    /// <param name="pin"></param>
    /// <param name="target"></param>
    public void InsertPinAfter(PlatoPin pin, PlatoPin target)
    {
        pin.ParentNode = this;
        pin.SetSibling(target.Sibling);
        target.SetSibling(pin);
        CalcuRect();
    }

    public void InsertAsLastChild(PlatoPin pin, PlatoPin parentPin)
    {
        PlatoPin runner = parentPin;
        while (runner.Sibling != null && !string.IsNullOrEmpty(runner.Sibling.ParentPin))
            runner = runner.Sibling;
        InsertPinAfter(pin, runner);
    }

    /// <summary>
    /// 添加动态引脚
    /// </summary>
    /// <param name="name"></param>
    /// <param name="type"></param>
    /// <param name="isInput"></param>
    /// <returns></returns>
    public PlatoPin AddDynamicPin(string name, Type type, bool isInput)
    {
        PlatoPin result = PlatoNodeGenerator.CreatePin(type);
        result.Title = name;
        result.IsInput = isInput;
        result.IsDynamic = true;
        result.ParentNode = this;

        // 将动态引脚按输入类型分类
        List<PlatoPin> inPins = new List<PlatoPin>();
        List<PlatoPin> outPins = new List<PlatoPin>();
        foreach (PlatoPin pin in dynamicPins)
        {
            if (pin.IsInput)
                inPins.Add(pin);
            else
                outPins.Add(pin);
        }

        List<PlatoPin> pins = null;
        PlatoPin head = null;
        if (isInput)
        {
            pins = inPins;
            head = inPinHead;
        }
        else
        {
            pins = outPins;
            head = outPinHead;
        }

        if (pins.Count == 0)
        {
            // 在Button前插入，拥有动态引脚增加功能的，必然会有一个添加按钮
            PlatoPin pin = head;
            while (pin.Sibling != null && pin.Sibling.Type != typeof(Button))
                pin = pin.Sibling;
            if (pin == head && pin.Type == typeof(Button))
            {
                result.SetSibling(pin);
                if (isInput)
                    inPinHead = result;
                else
                    outPinHead = result;
                CalcuRect();
            }
            else
            {
                InsertPinAfter(result, pin);
            }
        }
        else
        {
            // 在最后一个动态引脚后插入
            InsertPinAfter(result, pins[pins.Count - 1]);
        }

        dynamicPins.Add(result);
        return result;
    }

    /// <summary>
    /// 移除动态引脚
    /// </summary>
    /// <param name="pin"></param>
    public void RemoveDynamicPin(PlatoPin pin)
    {
        dynamicPins.Remove(pin);
    }

    /// <summary>
    /// 获得动态引脚数量
    /// </summary>
    /// <returns></returns>
    public int GetDynamicPinCount()
    {
        return dynamicPins.Count;
    }

    /// <summary>
    /// 按索引查找动态引脚
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    public PlatoPin FindDyanmicPinByIndex(int index)
    {
        return dynamicPins[index];
    }

    /// <summary>
    /// 按名字查找动态引脚
    /// </summary>
    /// <param name="title"></param>
    /// <returns></returns>
    public PlatoPin FindDyanmicPinByTitle(string title)
    {
        foreach (PlatoPin pin in dynamicPins)
        {
            if (pin.Title == title)
                return pin;
        }
        return null;
    }

    /// <summary>
    /// 清空动态引脚
    /// </summary>
    public void ClearDynamicPins()
    {
        foreach (PlatoPin pin in dynamicPins)
        {
            pin.Clear();
            RemovePin(pin);
        }
        dynamicPins.Clear();
    }

    /// <summary>
    /// 获取所有输入引脚
    /// </summary>
    /// <returns></returns>
    public List<PlatoPin> GetAllInPins()
    {
        List<PlatoPin> result = new List<PlatoPin>();
        PlatoPin pin = inPinHead;
        while (pin != null)
        {
            result.Add(pin);
            pin = pin.Sibling;
        }
        return result;
    }

    /// <summary>
    /// 获取所有输出引脚
    /// </summary>
    /// <returns></returns>
    public List<PlatoPin> GetAllOutPins()
    {
        List<PlatoPin> result = new List<PlatoPin>();
        PlatoPin pin = outPinHead;
        while (pin != null)
        {
            result.Add(pin);
            pin = pin.Sibling;
        }
        return result;
    }

    /// <summary>
    /// 获取最后的引脚
    /// </summary>
    /// <returns></returns>
    public PlatoPin GetLastPin(bool isInput)
    {
        PlatoPin pinHead = null;
        if (isInput)
            pinHead = inPinHead;
        else
            pinHead = outPinHead;

        if (pinHead == null)
            return null;

        PlatoPin pin = pinHead;
        while (pin.Sibling != null)
        {
            pin = pin.Sibling;
        }
        return pin;
    }

    /// <summary>
    /// 计算窗口大小
    /// </summary>
    protected void CalcuRect()
    {
        maxPinCount = 0;
        PlatoPin inPin = inPinHead;
        PlatoPin outPin = outPinHead;

        while (inPin != null || outPin != null)
        {
            ++maxPinCount;
            if (inPin != null) inPin = inPin.Sibling;
            if (outPin != null) outPin = outPin.Sibling;
        }

        rect = new Rect(rect) { height = 50 + maxPinCount * EditorGUIUtility.singleLineHeight };
    }

    /// <summary>
    /// 获取引脚坐标大小
    /// </summary>
    /// <param name="target"></param>
    /// <param name="isInput"></param>
    /// <returns></returns>
    public Rect GetPinRect(PlatoPin target, bool isInput)
    {
        PlatoPin head = null;
        if (isInput)
            head = inPinHead;
        else
            head = outPinHead;

        PlatoPin pin = head;
        while (pin != null)
        {
            if (pin.Type != typeof(Button) && pin == target)
                return new Rect(pin.PinRect) { x = rect.x + pin.PinRect.x, y = rect.y + pin.PinRect.y };
            pin = pin.Sibling;
        }
        return new Rect();
    }

    /// <summary>
    /// 按鼠标位置查找拖拽引脚
    /// </summary>
    /// <param name="mousePos">鼠标位置</param>
    /// <returns></returns>
    public PLATO.DragPin FindDragPinByMouse(Vector2 mousePos)
    {
        PlatoPin pin = null;

        // 输入端
        pin = inPinHead;
        while (pin != null)
        {
            if (pin.Type != typeof(Button) && pin.PinRect.Contains(mousePos))
            {
                PLATO.DragPin dragPin = new PLATO.DragPin();
                dragPin.start = new Rect(pin.PinRect) { x = rect.x + pin.PinRect.x, y = rect.y + pin.PinRect.y };
                dragPin.pin = pin;
                return dragPin;
            }
            pin = pin.Sibling;
        }

        // 输出端
        pin = outPinHead;
        while (pin != null)
        {
            if (pin.Type != typeof(Button) && pin.PinRect.Contains(mousePos))
            {
                PLATO.DragPin dragPin = new PLATO.DragPin();
                dragPin.start = new Rect(pin.PinRect) { x = rect.x + pin.PinRect.x, y = rect.y + pin.PinRect.y };
                dragPin.pin = pin;
                return dragPin;
            }
            pin = pin.Sibling;
        }
        return null;
    }

    /// <summary>
    /// 按名字查找引脚
    /// </summary>
    /// <param name="title"></param>
    /// <returns></returns>
    public PlatoPin FindPinByTitle(string title, bool isInput)
    {
        PlatoPin head = null;
        if (isInput)
            head = inPinHead;
        else
            head = outPinHead;

        PlatoPin pin = head;
        while (pin != null)
        {
            if (pin.Title == title)
                return pin;
            pin = pin.Sibling;
        }
        return null;
    }
    public T FindPinByTitle<T>(string title, bool isInput) where T : PlatoPin
    {
        PlatoPin head = null;
        if (isInput)
            head = inPinHead;
        else
            head = outPinHead;

        PlatoPin pin = head;
        while (pin != null)
        {
            if (pin.Title == title)
                return pin as T;
            pin = pin.Sibling;
        }
        return null;
    }

    /// <summary>
    /// 按索引查找引脚
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    public PlatoPin FindPinByIndex(int index, bool isInput)
    {
        PlatoPin head = null;
        if (isInput)
            head = inPinHead;
        else
            head = outPinHead;

        int i = 0;
        PlatoPin pin = head;
        while (pin != null)
        {
            if (i == index)
                return pin;
            pin = pin.Sibling;
            ++i;
        }
        return null;
    }

    /// <summary>
    /// 查找引脚索引
    /// </summary>
    /// <param name="p"></param>
    /// <param name="isInput"></param>
    /// <returns></returns>
    public int GetPinIndex(PlatoPin p, bool isInput)
    {
        PlatoPin head = null;
        if (isInput)
            head = inPinHead;
        else
            head = outPinHead;

        int i = 0;
        PlatoPin pin = head;
        while (pin != null)
        {
            if (pin == p)
                return i;
            pin = pin.Sibling;
            ++i;
        }
        return -1;
    }

    /// <summary>
    /// 获取后续节点
    /// </summary>
    /// <returns></returns>
    public List<PlatoNode> GetNextNodes(bool onlyEventPin = true)
    {
        List<PlatoNode> result = new List<PlatoNode>();

        PlatoPin pin = outPinHead;
        while (pin != null)
        {
            foreach (PlatoNode node in GetNextNodesFromPin(pin, null, onlyEventPin))
            {
                if (!result.Contains(node))
                {
                    node.ResetExported();
                    result.Add(node);
                }
            }
            pin = pin.Sibling;
        }

        return result;
    }

    /// <summary>
    /// 按引脚获取后续节点
    /// </summary>
    /// <param name="pin"></param>
    /// <returns></returns>
    public List<PlatoNode> GetNextNodesFromPin(PlatoPin pin, PlatoPin nextPin = null, bool onlyEventPin = true)
    {
        List<PlatoNode> result = new List<PlatoNode>();

        if (pin.Type == null || !onlyEventPin)
        {
            foreach (PlatoPin next in pin.Nexts)
            {
                if (nextPin != null && next != nextPin)
                    continue;
                if (!result.Contains(next.ParentNode))
                {
                    next.ParentNode.ResetExported();
                    result.Add(next.ParentNode);
                }
            }
        }

        return result;
    }

    /// <summary>
    /// 获取所有后续节点
    /// </summary>
    /// <returns></returns>
    public List<PlatoNode> GetAllNextNodes(bool onlyEventPin = true)
    {
        List<PlatoNode> result = new List<PlatoNode>();
        GetAllNextNodes(result, onlyEventPin);
        return result;
    }

    /// <summary>
    /// 获取所有后续节点(递归)
    /// </summary>
    /// <param name="nodes"></param>
    private void GetAllNextNodes(List<PlatoNode> nodes, bool onlyEventPin)
    {
        foreach (PlatoNode node in GetNextNodes(onlyEventPin))
        {
            if (!nodes.Contains(node))
                nodes.Add(node);
            node.GetAllNextNodes(nodes, onlyEventPin);
        }
    }
    
    /// <summary>
    /// 按引脚获取所有后续节点
    /// </summary>
    /// <param name="pin"></param>
    /// <returns></returns>
    public List<PlatoNode> GetAllNextNodesFromPin(PlatoPin pin, bool onlyEventPin = true)
    {
        List<PlatoNode> result = new List<PlatoNode>();
        GetAllNextNodesFromPin(pin, result, onlyEventPin);
        return result;
    }

    /// <summary>
    /// 按引脚获取所有后续节点(递归)
    /// </summary>
    /// <param name="pin"></param>
    /// <param name="nodes"></param>
    private void GetAllNextNodesFromPin(PlatoPin pin, List<PlatoNode> nodes, bool onlyEventPin)
    {
        foreach (PlatoNode node in GetNextNodesFromPin(pin, null, onlyEventPin))
        {
            if (!nodes.Contains(node))
                nodes.Add(node);
            node.GetAllNextNodes(nodes, onlyEventPin);
        }
    }

    /// <summary>
    /// 绘制
    /// </summary>
    public void Draw(Rect wndRect, bool debug)
    {
        GUI.color = color;
        if (wndRect.Overlaps(rect, true))
        {
            string title = string.Format("{0}[{1}]", Title, ID);
            GUI.WindowFunction wndFunc = WindowFunction;
            if (debug)
                wndFunc = DebugWindowFunction;

            if (Title == "Reroute")
            {
                rect = GUILayout.Window(ID, rect, wndFunc, "R", "Reroute");
            }
            else
            {
                if (IsFocus || IsDebug)
                    rect = GUILayout.Window(ID, rect, wndFunc, title, focusStyle, GUILayout.MinWidth(150.0f));
                else
                    rect = GUILayout.Window(ID, rect, wndFunc, title, GUILayout.MinWidth(150.0f));
            }

            if (IsBreak)
            {
                GUI.color = Color.red;
                GUI.Box(new Rect(rect) { x = Position.x - 40, y = Position.y - 40 }, "", "Breakpoint");
            }
            if (IsBreaking)
            {
                GUI.color = Color.yellow;
                GUI.Box(new Rect(rect) { x = Position.x - 35, y = Position.y - 35 }, "", "Breaking");
            }
        }
        GUI.BringWindowToFront(ID);
        GUI.color = Color.white;

        Handles.BeginGUI();
        // 从所有输入引脚开始绘制连线，只对Function End起效
        PlatoPin inPin = inPinHead;
        while (inPin != null)
        {
            foreach (PlatoPin next in inPin.Nexts)
            {
                Rect left = inPin.ParentNode.GetPinRect(inPin, true);
                Rect right = next.ParentNode.GetPinRect(next, true);
                if (!IsCullPin(left, right, wndRect))
                    Handles.DrawBezier(left.center, right.center, new Vector2(left.xMax + 50f, left.center.y), new Vector2(right.xMin - 50f, right.center.y), inPin.GetColor(), null, 5f);
            }
            inPin = inPin.Sibling;
        }
        // 绘制输出引脚连线
        PlatoPin outPin = outPinHead;
        while (outPin != null)
        {
            foreach (PlatoPin next in outPin.Nexts)
            {
                Rect left = outPin.ParentNode.GetPinRect(outPin, false);
                Rect right = next.ParentNode.GetPinRect(next, true);
                float distance = Vector3.Distance(left.center, right.center);
                if (!IsCullPin(left, right, wndRect))
                {
                    if (outPin.IsDebug)
                        Handles.DrawBezier(left.center, right.center, new Vector2(left.xMax + distance * 0.2f, left.center.y), new Vector2(right.xMin - distance * 0.2f, right.center.y), Color.red, null, 10f);
                    else
                        Handles.DrawBezier(left.center, right.center, new Vector2(left.xMax + distance * 0.2f, left.center.y), new Vector2(right.xMin - distance * 0.2f, right.center.y), outPin.GetColor(), null, 5f);
                }
            }
            outPin = outPin.Sibling;
        }

        Handles.EndGUI();
    }

    bool IsCullPin(Rect left, Rect right, Rect wndRect)
    {
        if (left.xMax < wndRect.xMin && right.xMax < wndRect.xMin)
            return true;
        if (left.xMin > wndRect.xMax && right.xMin > wndRect.xMax)
            return true;
        if (left.yMax < wndRect.yMin && right.yMax < wndRect.yMin)
            return true;
        if (left.yMin > wndRect.yMax && right.yMin > wndRect.yMax)
            return true;
        return false;
    }

    /// <summary>
    /// 引脚绘制
    /// </summary>
    /// <param name="pin"></param>
    /// <param name="isInput"></param>
    protected void DrawPins(PlatoPin pin, bool isInput, bool debug = false) 
    {
        GUILayout.BeginVertical();
        int pinIndex = 0;
        while (pinIndex < maxPinCount)
        {
            GUILayout.BeginHorizontal();
            if (pin != null)
            {
                pin.Draw();
                pin = pin.Sibling;
            }
            GUILayout.EndHorizontal();
            ++pinIndex;
        }
        GUILayout.EndVertical();
    }

    /// <summary>
    /// 窗口处理函数
    /// </summary>
    /// <param name="id"></param>
    protected virtual void WindowFunction(int id)
    {
        // 绘制引脚
        GUILayout.BeginHorizontal();
        DrawPins(inPinHead, true);
        DrawPins(outPinHead, false);
        GUILayout.EndHorizontal();

        switch (Event.current.GetTypeForControl(id))
        {
            case EventType.MouseDown: // 鼠标按下
                {
                    PLATO.DragPin target = FindDragPinByMouse(Event.current.mousePosition);
                    if (target != null)
                    {
                        // left mouse button
                        if (Event.current.button == 0)
                        {
                            if (Event.current.alt) // delete
                            {
                                foreach (PlatoPin prev in target.pin.Prevs)
                                {
                                    prev.RemoveNext(target.pin);
                                }
                                target.pin.Prevs.Clear();
                                foreach (PlatoPin next in target.pin.Nexts)
                                {
                                    next.RemovePrev(target.pin);
                                }
                                target.pin.Nexts.Clear();
                                EditorWindow.focusedWindow.Repaint();
                            }
                            else if (Event.current.control) // move
                            {
                                foreach (PlatoPin prev in target.pin.Prevs)
                                {
                                    prev.RemoveNext(target.pin);
                                    PLATO.AddDrag(new PLATO.DragPin() { pin = prev, start = prev.ParentNode.GetPinRect(prev, false) });
                                }
                                target.pin.Prevs.Clear();
                            }
                            else if (target.pin.IsInput == false && plato.IsDragNode(target.pin.ParentNode) == false) // add
                            {
                                PLATO.AddDrag(target);
                            }
                        }
                        else if (Event.current.button == 1)
                        {
                            GenericMenu menu = new GenericMenu();
                            List<PlatoPin> pins;
                            if (target.pin.IsInput)
                                pins = target.pin.Prevs;
                            else
                                pins = target.pin.Nexts;

                            foreach (PlatoPin pin in pins)
                            {
                                PlatoPin fuck = pin;
                                string text = string.Format("Break link to {0}.{1}[{3}] ({2})", pin.Title, pin.ParentNode.Title, pin.Type == null ? "Exec" : pin.Type.ToString(), pin.ParentNode.ID);
                                menu.AddItem(new GUIContent(text), false, () =>
                                {
                                    if (target.pin.IsInput)
                                        target.pin.RemovePrev(fuck);
                                    else
                                        target.pin.RemoveNext(fuck);
                                });
                            }
                            menu.ShowAsContext();
                            Event.current.Use();
                        }
                    }
                }
                break;

            case EventType.MouseUp: // 鼠标弹起
                {
                    PLATO.DragPin target = FindDragPinByMouse(Event.current.mousePosition);
                    if (target != null && target.pin.IsInput)
                    {
                        // 连接引脚
                        PLATO.LinkDrag(target);
                    }
                    plato.HideTip();
                }
                break;

            case EventType.MouseDrag:
                {
                    PLATO.DragPin target = FindDragPinByMouse(Event.current.mousePosition);
                    if (target != null && target.pin.IsInput)
                    {
                        string result = PLATO.TryLink(target);
                        if (string.IsNullOrEmpty(result))
                            plato.ShowTip(target.pin.PinRect.center + target.pin.ParentNode.Position, "OK");
                        else
                            plato.ShowTip(target.pin.PinRect.center + target.pin.ParentNode.Position, result);
                        EditorWindow.focusedWindow.Repaint();
                    }
                    else
                    {
                        plato.HideTip();
                    }
                }
                break;

            case EventType.KeyDown:
                // 删除
                if (Event.current.keyCode == KeyCode.Delete)
                {
                    PLATO.RemoveNode(this, this.plato);
                    EditorWindow.focusedWindow.Repaint();
                }
                break;

            default:
                break;
        }
    }

    protected void DebugWindowFunction(int id)
    {
        // 绘制引脚
        GUILayout.BeginHorizontal();
        DrawPins(inPinHead, true, true);
        DrawPins(outPinHead, false, true);
        GUILayout.EndHorizontal();
    }

    public void PostLoad()
    {
        PlatoPin runner = null;
        
        runner = inPinHead;
        while (runner != null)
        {
            runner.PostLoad();
            runner = runner.Sibling;
        }

        runner = outPinHead;
        while (runner != null)
        {
            runner.PostLoad();
            runner = runner.Sibling;
        }
    }

    public string FindParentPin(string pin_title)
    {
        foreach (PlatoPin pin in GetAllInPins())
        {
            DropdownPin dropdown = pin as DropdownPin;
            if (dropdown == null)
                continue;

            foreach (var group in dropdown.PinDefines)
            {
                foreach (KeyValuePair<string, Type> pair in group)
                {
                    if (pair.Key == pin_title)
                        return dropdown.Title;
                }
            }
        }
        return string.Empty;
    }

    public List<PlatoPin> GetSameParentPins(string parentPin)
    {
        List<PlatoPin> result = new List<PlatoPin>();
        foreach (PlatoPin p in GetAllInPins())
        {
            if (p.ParentPin == parentPin)
                result.Add(p);
        }
        foreach (PlatoPin p in GetAllOutPins())
        {
            if (p.ParentPin == parentPin)
                result.Add(p);
        }
        result.Sort((PlatoPin a, PlatoPin b) =>
        {
            return a.ChildIndex - b.ChildIndex;
        });
        return result;
    }
}
