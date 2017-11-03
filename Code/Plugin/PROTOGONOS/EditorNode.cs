using UnityEngine;
using UnityEngine.UI;
using UnityEditor;
using System.Collections;
using System.Collections.Generic;
using System.IO;

public class EditorNode : PlatoNode
{
    public EditorNode()
    {
        Category = "Editor";
        color = Color.white;
    }

    public PlatoPin SourcePin;

    public PlatoPin TargetPin { get; private set; }
    public virtual void SetTarget(PlatoPin target) { TargetPin = target; }

    public PlatoNode TargetNode { get; private set; }
    public virtual void SetTarget(PlatoNode target, bool isInput) { TargetNode = target; }
}

public class ContextMenuNode : EditorNode
{
    private string searchString = string.Empty;
    private Vector2 scrollPos;
    private Dictionary<string, Dictionary<string, PlatoNode>> filterNodes = new Dictionary<string, Dictionary<string, PlatoNode>>();
    private Dictionary<string, bool> foldouts = new Dictionary<string, bool>();
    private GUIStyle labelStyle;
    private GUIStyle hoverStyle;
    private GUIStyle foldStyle;
    private bool firstShow = true;
    private int current;
    private int total;
    private string currentTitle = string.Empty;

    public ContextMenuNode()
    {
        Title = "ContextMenu";
        filterNodes = new Dictionary<string, Dictionary<string, PlatoNode>>(PlatoNodeGenerator.AllNodes);
        Size = new Vector2(200, 300);
    }

    protected override void WindowFunction(int id)
    {
        GUI.skin = null;

        GUI.SetNextControlName("SearchField");
        GUILayout.BeginHorizontal(GUI.skin.FindStyle("Toolbar"));
        string newString = GUILayout.TextField(searchString, GUI.skin.FindStyle("ToolbarSeachTextField"));
        if (newString != searchString)
        {
            searchString = newString;
            filterNodes.Clear();
            foldouts.Clear();
            current = 0;
            total = 0;

            var categoryIter = PlatoNodeGenerator.AllNodes.GetEnumerator();
            while (categoryIter.MoveNext())
            {
                if (categoryIter.Current.Key == "Editor")
                    continue;

                Dictionary<string, PlatoNode> nodes = new Dictionary<string, PlatoNode>();
                var nodeIter = categoryIter.Current.Value.GetEnumerator();
                while (nodeIter.MoveNext())
                {
                    if (nodeIter.Current.Key.ToLower().Contains(searchString.ToLower()))
                        nodes.Add(nodeIter.Current.Key, nodeIter.Current.Value);
                }

                if (nodes.Count > 0)
                {
                    filterNodes.Add(categoryIter.Current.Key, nodes);
                    foldouts.Add(categoryIter.Current.Key, true);
                    total += nodes.Count;
                }
            }
        }
        if (GUILayout.Button("", GUI.skin.FindStyle("ToolbarSeachCancelButton")))
        {
            searchString = "";
            filterNodes = new Dictionary<string, Dictionary<string, PlatoNode>>(PlatoNodeGenerator.AllNodes);
            foldouts.Clear();
            foreach (var category in filterNodes.Keys)
            {
                foldouts.Add(category, false);
            }
            GUI.FocusControl(null);
        }
        GUILayout.EndHorizontal();

        scrollPos = GUILayout.BeginScrollView(scrollPos, GUILayout.Height(250));
        DrawNodes();
        GUILayout.EndScrollView();

        if (firstShow)
        {
            GUI.FocusWindow(id);
            GUI.FocusControl("SearchField");
            firstShow = false;
        }

        switch (Event.current.GetTypeForControl(GUIUtility.GetControlID(FocusType.Keyboard)))
        {
            case EventType.KeyUp:
                if (total > 0 && Event.current.keyCode == KeyCode.DownArrow)
                {
                    current = (current + 1) % total;
                    EditorWindow.focusedWindow.Repaint();
                }
                else if (total > 0 && Event.current.keyCode == KeyCode.UpArrow)
                {
                    current = current == 0 ? (total - 1) : (current - 1);
                    EditorWindow.focusedWindow.Repaint();
                }
                else if (Event.current.keyCode == KeyCode.Return)
                {
                    CreateNode(currentTitle);
                }
                break;
        }

        GUI.skin = PlatoNode.skin;
    }

    void DrawNodes()
    {
        if (labelStyle == null)
        {
            labelStyle = new GUIStyle(GUI.skin.label);
            labelStyle.normal.textColor = Color.white;
            labelStyle.hover.textColor = Color.blue;
            labelStyle.hover.background = Texture2D.whiteTexture;
        }
        if (hoverStyle == null)
        {
            hoverStyle = new GUIStyle(GUI.skin.label);
            hoverStyle.normal.textColor = Color.blue;
            hoverStyle.normal.background = Texture2D.whiteTexture;
        }
        if (foldStyle == null)
        {
            foldStyle = new GUIStyle(GUI.skin.FindStyle("Foldout"));
            foldStyle.normal.textColor = Color.white;
        }

        int index = 0;
        var categoryIter = filterNodes.GetEnumerator();
        while (categoryIter.MoveNext())
        {
            if (categoryIter.Current.Key == "Editor")
                continue;

            bool foldout;
            foldouts.TryGetValue(categoryIter.Current.Key, out foldout);
            foldout = EditorGUILayout.Foldout(foldout, categoryIter.Current.Key, foldStyle);
            foldouts[categoryIter.Current.Key] = foldout;

            if (foldout)
            {
                var nodeIter = categoryIter.Current.Value.GetEnumerator();
                while (nodeIter.MoveNext())
                {
                    GUIStyle style;
                    if (current == index)
                    {
                        currentTitle = nodeIter.Current.Key;
                        style = hoverStyle;
                    }
                    else
                    {
                        style = labelStyle;
                    }

                    if (GUILayout.Button("    " + nodeIter.Current.Key, style))
                        CreateNode(nodeIter.Current.Key);

                    ++index;
                }
            }
        }
        if (GUILayout.Button("Reroute", labelStyle))
            CreateNode("Reroute");
    }

    void CreateNode(string title)
    {
        PlatoNode prototype = PlatoNodeGenerator.FindPrototypeByTitle(title);

        PlatoNode node = prototype.Clone(plato);
        node.PostLoad();
        node.Position = Position;
        PLATO.AddNode(node, plato);

        if (PLATO.linkPins != null)
        {
            PlatoPin link = null;
            foreach (PlatoPin p in node.GetAllInPins())
            {
                if (PinTypeUtil.IsExec(p))
                {
                    link = p;
                    break;
                }
            }
            if (link != null)
            {
                foreach (PLATO.DragPin p in PLATO.linkPins)
                {
                    p.pin.AddNext(link);
                    link.AddPrev(p.pin);
                }
            }
            PLATO.linkPins = null;
        }

        plato.RemoveMenu();
        EditorWindow.focusedWindow.Repaint();
    }
}

public class AddPinNameNode : EditorNode
{
    public AddPinNameNode()
    {
        Title = "AddPinName";
        AddPin("Pin", null, true);
        AddPin("Title", typeof(string), true);
        AddPin<ButtonPin>("OK", typeof(Button), false).onClick = OnOKClick;
        AddPin<ButtonPin>("Cancel", typeof(Button), false).onClick = OnCancelClick;
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        PlatoPin newPin = TargetNode.AddDynamicPin("<new pin>", null, isInput);
        newPin.ParentPin = SourcePin.Title;
        (newPin as ExecPin).IsEvent = true;
        SetTarget(newPin);

        PlatoPin pin = FindPinByTitle("Pin", true);
        newPin.AddNext(pin);
        pin.AddPrev(newPin);

        PLATO.AddNode(this, this.plato);
    }


    void OnOKClick()
    {
        TargetPin.Title = (string)FindPinByTitle("Title", true).Value;
        PLATO.RemoveNode(this, this.plato);
    }

    void OnCancelClick()
    {
        TargetPin.ParentNode.RemoveDynamicPin(TargetPin);
        TargetPin.ParentNode.RemovePin(TargetPin);
        PLATO.RemoveNode(this, this.plato);
    }
}

public class AddPinNameTypeNode : EditorNode
{
    private bool isInput;

    public AddPinNameTypeNode()
    {
        Title = "AddPinNameType";
        AddPin("Title", typeof(string), true);
        AddPin<DropdownPin>("Type", typeof(Dropdown), true);
        AddPin<ButtonPin>("OK", typeof(Button), false).onClick = OnOKClick;
        AddPin<ButtonPin>("Cancel", typeof(Button), false).onClick = OnCancelClick;

        List<string> names = FindPinByTitle<DropdownPin>("Type", true).DropdownList;
        names.Clear();

        var iter = PinTypeUtil.CppTypes.GetEnumerator();
        while (iter.MoveNext())
        {
            names.Add(iter.Current.Value);
        }
        names.Add("GameObject");
        names.Add("Exec");
    }
    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        this.isInput = isInput;
        PLATO.AddNode(this, this.plato);
    }


    void OnOKClick()
    {
        string title = (string)FindPinByTitle("Title", true).Value;
        System.Type type = GetType(FindPinByTitle("Type", true).Value as string);
        PlatoPin newPin = TargetNode.AddDynamicPin(title, type, isInput);
        newPin.ParentPin = SourcePin.Title;
        PLATO.RemoveNode(this, this.plato);
    }

    void OnCancelClick()
    {
        PLATO.RemoveNode(this, this.plato);
    }

    System.Type GetType(string typeName)
    {
        if (typeName == "GameObject")
        {
            return typeof(GameObject);
        }
        else
        {
            var iter = PinTypeUtil.CppTypes.GetEnumerator();
            while (iter.MoveNext())
            {
                if (typeName == iter.Current.Value)
                    return iter.Current.Key;
            }
        }
        return null;
    }
}

public class RemovePinNode : EditorNode
{
    public RemovePinNode()
    {
        Title = "RemovePin";
        AddPin<DropdownPin>("Title", typeof(Dropdown), true);
        AddPin<ButtonPin>("OK", typeof(Button), false).onClick = OnOKClick;
        AddPin<ButtonPin>("Cancel", typeof(Button), false).onClick = OnCancelClick;
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        List<string> names = FindPinByTitle<DropdownPin>("Title", true).DropdownList;
        names.Clear();
        for (int i = 0; i < TargetNode.GetDynamicPinCount(); ++i)
        {
            names.Add(TargetNode.FindDyanmicPinByIndex(i).Title);
        }

        PLATO.AddNode(this, this.plato);
    }

    void OnOKClick()
    {
        string title = FindPinByTitle("Title", true).Value as string;
        PlatoPin pin = TargetNode.FindDyanmicPinByTitle(title);
        TargetNode.RemoveDynamicPin(pin);
        TargetNode.RemovePin(pin);
        PLATO.RemoveNode(this, this.plato);
    }

    void OnCancelClick()
    {
        PLATO.RemoveNode(this, this.plato);
    }
}

public class RefreshFunctionNode : EditorNode
{
    public RefreshFunctionNode()
    {
        Title = "RefreshFunction";
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        if (plato.graph == null)
            return;

        List<string> names = plato.graph.GetFunctionNames();

        DropdownPin pin = TargetNode.FindPinByTitle<DropdownPin>("Function", true);
        pin.DropdownList = names;

        int index = pin.DropdownList.IndexOf(pin.Value as string);
        if (index < 0 || index >= names.Count)
            return;

        List<PlatoPin> inPins = new List<PlatoPin>();
        List<PlatoPin> outPins = new List<PlatoPin>();
        plato.graph.GetFunctionIO(names[index], inPins, outPins);

        List<PlatoPin> oldDynamicPins = new List<PlatoPin>();
        for (int i = 0; i < target.GetDynamicPinCount(); ++i)
        {
            oldDynamicPins.Add(target.FindDyanmicPinByIndex(i).Clone());
        }

        TargetNode.ClearDynamicPins();
        foreach (PlatoPin p in inPins)
        {
            PlatoPin newPin = TargetNode.AddDynamicPin(p.Title, p.Type, true);
            PlatoPin oldPin = oldDynamicPins.Find((x) => x.Title == p.Title && x.IsInput);
            if (oldPin != null)
                newPin.Value = oldPin.Value;
        }
        foreach (PlatoPin p in outPins)
        {
            PlatoPin newPin = TargetNode.AddDynamicPin(p.Title, p.Type, false);
            PlatoPin oldPin = oldDynamicPins.Find((x) => x.Title == p.Title && !x.IsInput);
            if (oldPin != null)
                newPin.Value = oldPin.Value;
        }
    }
}

public class RefreshGAIANode : EditorNode
{
    public RefreshGAIANode()
    {
        Title = "RefreshGAIA";
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        DropdownPin pin = TargetNode.FindPinByTitle<DropdownPin>("GAIA", true);
        pin.DropdownList = GAIA.GetGaiaNames();
    }
}

public class RefreshCameraNode : EditorNode
{
    public RefreshCameraNode()
    {
        Title = "RefreshCamera";
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        DropdownPin pin = TargetNode.FindPinByTitle<DropdownPin>("Camera", true);
        pin.DropdownList.Clear();

        foreach (Camera camera in GameObject.FindObjectsOfType<Camera>())
        {
            pin.DropdownList.Add(camera.gameObject.name);
        }
        foreach (Camera camera in PlatoUtil.DesignLevel.GetComponentsInChildren<Camera>(true))
        {
            pin.DropdownList.Add(camera.gameObject.name);
        }
    }
}

public class RefreshCameraScriptNode : EditorNode
{
    public RefreshCameraScriptNode()
    {
        Title = "RefreshCameraScript";
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        DropdownPin pin = TargetNode.FindPinByTitle<DropdownPin>("Script", true);
        pin.DropdownList.Clear();
        pin.DropdownList.Add("null");
        foreach (string filename in Directory.GetFiles("Assets/Standard Assets/Camera/", "*.cs"))
        {
            pin.DropdownList.Add(Path.GetFileNameWithoutExtension(filename));
        }
    }
}

public class CommentNode : EditorNode
{
    public class ChildEntry
    {
        public PlatoNode child;
        public Vector2 offset;
    }
    public List<ChildEntry> childEntries = new List<ChildEntry>();

    public CommentNode()
    {
        Title = "Comment";
    }

    public void AddChilds(List<PlatoNode> childNodes)
    {
        // Calculate self rect
        Vector2 min = childNodes[0].Position;
        Vector2 max = childNodes[0].Position + childNodes[0].Size;
        for (int i = 1; i < childNodes.Count; ++i)
        {
            min.x = Mathf.Min(min.x, childNodes[i].Position.x);
            min.y = Mathf.Min(min.y, childNodes[i].Position.y);
            max.x = Mathf.Max(max.x, childNodes[i].Position.x + childNodes[i].Size.x);
            max.y = Mathf.Max(max.y, childNodes[i].Position.y + childNodes[i].Size.y);
        }
        min.x -= 20.0f;
        min.y -= 50.0f;
        max.x += 20.0f;
        max.y += 20.0f;
        rect = Rect.MinMaxRect(min.x, min.y, max.x, max.y);

        // Add children
        for (int i = 0; i < childNodes.Count; ++i)
        {
            ChildEntry entry = new ChildEntry();
            entry.child = childNodes[i];
            entry.offset.x = rect.x - childNodes[i].Position.x;
            entry.offset.y = rect.y - childNodes[i].Position.y;
            childEntries.Add(entry);
        }
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        if (plato.graph == null)
            return;

        List<PlatoNode> childNodes = plato.graph.GetAllNodes().FindAll((node) => { return node.IsFocus; });
        if (childNodes.Count == 0)
        {
            PLATO.RemoveNode(this, this.plato);
            return;
        }
        AddChilds(childNodes);

        EditorNode rename = PLATO.CreateNode("RenameComment", this.plato) as EditorNode;
        rename.SetTarget(this, true);
    }

    protected override void WindowFunction(int id)
    {
        // 在标题栏拖拽
        GUI.DragWindow(new Rect() { width = rect.width, height = 18 });

        // 绘制引脚
        GUILayout.BeginHorizontal();
        GUILayout.EndHorizontal();

        foreach (ChildEntry entry in childEntries)
        {
            entry.child.Position = Position - entry.offset;
        }
    }

    public void Save(PlatoWriter writer)
    {
        writer.Line("{{");
        writer.PushIndent();

        writer.Line("title = '{0}',", Title);
        writer.Line("id = {0},", ID);
        writer.Line("posX = {0},", Position.x);
        writer.Line("posY = {0},", Position.y);
        writer.Line("width = {0},", Size.x);
        writer.Line("height = {0},", Size.y);

        writer.Line("childs = {{");
        writer.PushIndent();
        foreach (ChildEntry entry in childEntries)
        {
            writer.Line("{{");
            writer.PushIndent();
            writer.Line("id = {0},", entry.child.ID);
            writer.Line("offsetX = {0},", entry.offset.x);
            writer.Line("offsetY = {0},", entry.offset.y);
            writer.PopIndent();
            writer.Line("}},");
        }
        writer.PopIndent();
        writer.Line("}},");

        writer.PopIndent();
        writer.Line("}},");
    }
}

public class RenameCommentNode : EditorNode
{
    public RenameCommentNode()
    {
        Title = "RenameComment";
        AddPin("Title", typeof(string), true);
        AddPin<ButtonPin>("OK", typeof(Button), false).onClick = OnOKClick;
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        PLATO.AddNode(this, this.plato);
    }

    void OnOKClick()
    {
        TargetNode.Title = (string)FindPinByTitle("Title", true).Value;
        PLATO.RemoveNode(this, this.plato);
    }
}

public class RefreshUINode : EditorNode
{
    public RefreshUINode()
    {
        Title = "RefreshUI";
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        DropdownPin pin = TargetNode.FindPinByTitle<DropdownPin>("UI", true);
        pin.DropdownList.Clear();
        pin.DropdownList.Add("MoveJoystick");
        pin.DropdownList.Add("ShootJoystick");
        pin.DropdownList.Add("Skill1");
        pin.DropdownList.Add("Skill2");
        pin.DropdownList.Add("Skill3");
        pin.DropdownList.Add("Reload");
        pin.DropdownList.Add("All");
    }
}

public class TriggerNode : EditorNode
{
    public TriggerNode()
    {
        Title = "Trigger";
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        PlatoPin pin = TargetNode.AddDynamicPin(TargetNode.GetDynamicPinCount().ToString(), typeof(ulong), true);
        pin.ParentPin = SourcePin.Title;
        pin.ChildIndex = TargetNode.GetDynamicPinCount() - 1;
        PLATO.RemoveNode(this, this.plato);
    }
}

public class RemoveTriggerNode : EditorNode
{
    public RemoveTriggerNode()
    {
        Title = "RemoveTrigger";
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        PlatoPin pin = TargetNode.FindDyanmicPinByIndex(TargetNode.GetDynamicPinCount() - 1);
        TargetNode.RemoveDynamicPin(pin);
        TargetNode.RemovePin(pin);
        PLATO.RemoveNode(this, this.plato);
    }
}

public class RerouteNode : EditorNode
{
    public RerouteNode()
    {
        Title = "Reroute";
        AddPin("", null, true);
        AddPin("", null, false);
        rect = new Rect(rect) { width = 30, height = 30 };
    }
}

public class AddReviseMapI32PinNode : EditorNode
{
    public AddReviseMapI32PinNode()
    {
        Title = "AddReviseMapI32Pin";
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        int count = TargetNode.GetDynamicPinCount() / 2;
        PlatoPin pin;
        pin = TargetNode.AddDynamicPin("type" + count, typeof(System.Int32), true);
        pin.ParentPin = SourcePin.Title;
        pin.ChildIndex = TargetNode.GetDynamicPinCount() - 1;
        pin = TargetNode.AddDynamicPin("value" + count, typeof(System.Single), true);
        pin.ParentPin = SourcePin.Title;
        pin.ChildIndex = TargetNode.GetDynamicPinCount() - 1;
        PLATO.RemoveNode(this, this.plato);
    }

    static public bool IsTypePin(PlatoPin p)
    {
        if (p != null)
        {
            return p.Title.Contains("type");
        }
        return false;
    }

    static public bool IsValuePin(PlatoPin p)
    {
        if (p != null)
        {
            return p.Title.Contains("value");
        }
        return false;
    }

    static public PlatoPin GetTypePin(PlatoNode node,PlatoPin p)
    {
        if (node != null && IsValuePin(p))
        {
            PlatoPin ret = null;
            for (int i = 0; i < node.GetDynamicPinCount(); ++i)
            {
                PlatoPin curPin = node.FindDyanmicPinByIndex(i);
                if (i % 2 == 0)
                {
                    ret = curPin;
                }
                else
                {
                    if (p == curPin)
                        return ret;
                }
            }
        }
        return null;
    }
}
public class RemoveReviseMapI32PinNode : EditorNode
{
    public RemoveReviseMapI32PinNode()
    {
        Title = "RemoveReviseMapI32Pin";
    }

    public override void SetTarget(PlatoNode target, bool isInput)
    {
        base.SetTarget(target, isInput);

        int count = TargetNode.GetDynamicPinCount();
        PlatoPin pin1 = TargetNode.FindDyanmicPinByIndex(count - 1);
        PlatoPin pin2 = TargetNode.FindDyanmicPinByIndex(count - 2);
        TargetNode.RemoveDynamicPin(pin1);
        TargetNode.RemovePin(pin1);
        TargetNode.RemoveDynamicPin(pin2);
        TargetNode.RemovePin(pin2);

        PLATO.RemoveNode(this, this.plato);
    }
}
