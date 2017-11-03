using UnityEngine;
using UnityEditor;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using SLua;

public class PlatoDebugger : EditorWindow
{
    private PLATO plato;
    private List<string> platos = new List<string>();
    private int platoIndex;
    private Vector2 scrollPos;
    private LuaTable debugNode;
    private int debugPinIndex = -100;
    private bool step;
    private string searchString = string.Empty;

    public static bool IsOpen { get; private set; }
    public static bool IsRunning { get; private set; }

    private static readonly string PLATO_PATH = "Assets/Editor Default Resources/PLATO/";
    private static readonly string PLATO_WEAPON_PATH = "Assets/Editor Default Resources/PLATO/WeaponEditor";

    class MemberEntry
    {
        public string title;
        public object value;
        public Type type;
        public int index;
    }

    //[MenuItem("Window/Plato Debugger")]
    public static void Open()
    {
        EditorWindow.GetWindow<PlatoDebugger>();
    }

    void OnEnable()
    {
        PlatoUtil.OnDebugInfoChanged = OnDebugInfoChanged;
        IsOpen = true;
        debugNode = null;

        platos.Clear();
        foreach (string file in Directory.GetFiles(PLATO_PATH, "*.txt", SearchOption.TopDirectoryOnly))
        {
            platos.Add(Path.GetFileName(file));
        }
		foreach (string file in Directory.GetFiles(PLATO_WEAPON_PATH, "*.txt", SearchOption.AllDirectories))
		{
			platos.Add(Path.GetFileName(file));
        }
    }

    void OnDisable()
    {
        PlatoUtil.OnDebugInfoChanged = null;
        IsOpen = false;
    }

    void OnDebugInfoChanged()
    {
        if (!Application.isPlaying)
            return;

        if (PlatoUtil.DebugNode == debugNode && PlatoUtil.DebugPinIndex == debugPinIndex)
            return;

        debugNode = PlatoUtil.DebugNode;
        debugPinIndex = PlatoUtil.DebugPinIndex;

        PlatoNode node = GetNodeByLua(PlatoUtil.DebugNode);
        if (node != null)
        {
            node.IsDebug = true;
            PlatoPin pin = node.FindPinByIndex(PlatoUtil.DebugPinIndex, false);
            if (pin != null)
                pin.IsDebug = true;

            EditorWindow.FocusWindowIfItsOpen<PlatoDebugger>();
            Repaint();

            if (node.IsBreak)
            {
                plato.Goto(node, this);
                plato.Break(node);
                EditorApplication.isPaused = true;
            }
            else if (step)
            {
                plato.Goto(node, this);
                plato.Break(node);
                EditorApplication.isPaused = true;
                step = false;
            }
        }
    }

    void OnGUI()
    {
        // Load Plato
        GUILayout.BeginHorizontal();
        // search bar
        GUILayout.BeginHorizontal(GUI.skin.FindStyle("Toolbar"));
        string newString = GUILayout.TextField(searchString, GUI.skin.FindStyle("ToolbarSeachTextField"));
        if (newString != searchString)
        {
            searchString = newString;
        }
        if (GUILayout.Button("", GUI.skin.FindStyle("ToolbarSeachCancelButton")))
        {
            searchString = "";
            GUI.FocusControl(null);
        }
        GUILayout.EndHorizontal();
		string[] tempPlatos;
        if (string.IsNullOrEmpty(searchString))
			tempPlatos = platos.ToArray();
		else
			tempPlatos = platos.FindAll((x) => x.Contains(searchString)).ToArray();
		if (platoIndex >= tempPlatos.Length)
			platoIndex = 0;
        platoIndex = EditorGUILayout.Popup("Plato", platoIndex, tempPlatos);
        if (GUILayout.Button("Load"))
        {
            plato = new PLATO();
			string filePath = Path.Combine(PLATO_PATH, tempPlatos[platoIndex]);
			if (!File.Exists(filePath))
				filePath = Path.Combine(PLATO_WEAPON_PATH, platos[platoIndex]);
            PlatoLoader loader = new PlatoLoader(plato);
            loader.Load(filePath);
        }
        GUILayout.EndHorizontal();
        GUILayout.Space(10);

        // Debug Buttons
        GUILayout.BeginHorizontal();
        if (GUILayout.Button("Continue"))
            Continue();
        if (GUILayout.Button("Step"))
            Step();
        GUILayout.EndHorizontal();
        GUILayout.Space(10);

        // Info
        scrollPos = GUILayout.BeginScrollView(scrollPos, GUILayout.Width(200));
        GUILayout.BeginVertical(GUILayout.Width(200));

        if (plato != null && plato.graph != null)
        {
            GUILayout.Label("Breakpoints", EditorStyles.boldLabel);
            foreach (PlatoNode node in plato.graph.GetAllNodes().FindAll((n) => { return n.IsBreak; }))
            {
                GUILayout.BeginHorizontal();
                EditorGUILayout.SelectableLabel(string.Format("{0}[{1}]", node.Title, node.ID));
                if (GUILayout.Button(">", GUILayout.Width(16))) plato.Goto(node, this);
                if (GUILayout.Button("X", GUILayout.Width(16))) node.IsBreak = false;
                GUILayout.Space(5);
                GUILayout.EndHorizontal();
            }

            if (Application.isPlaying)
            {
                // Values
                GUILayout.Label("Values", EditorStyles.boldLabel);
                DrawValues();

                if (debugNode != null)
                {
                    List<MemberEntry> inputs = new List<MemberEntry>();
                    List<MemberEntry> outputs = new List<MemberEntry>();
                    List<MemberEntry> privates = new List<MemberEntry>();
                    PlatoNode node = GetMembers(debugNode, inputs, outputs, privates);
                    if (node != null)
                    {
                        float oldLabelWidth = EditorGUIUtility.labelWidth;
                        float oldFieldWidth = EditorGUIUtility.fieldWidth;
                        EditorGUIUtility.labelWidth = 75.0f;
                        EditorGUIUtility.fieldWidth = 100.0f;

                        // Inputs
                        GUILayout.Label(string.Format("{0}[{1}].Inputs", node.Title, node.ID), EditorStyles.boldLabel);
                        EditorGUI.BeginDisabledGroup(true);
                        //foreach (var member in inputs) DrawPin(member);
                        EditorGUI.EndDisabledGroup();
                        // Outputs
                        GUILayout.Label(string.Format("{0}[{1}].Outputs", node.Title, node.ID), EditorStyles.boldLabel);
                        EditorGUI.BeginDisabledGroup(true);
                        //foreach (var member in outputs) DrawPin(member);
                        EditorGUI.EndDisabledGroup();
                        // Privates
                        GUILayout.Label(string.Format("{0}[{1}].Privates", node.Title, node.ID), EditorStyles.boldLabel);
                        EditorGUI.BeginDisabledGroup(true);
                        //foreach (var member in privates) DrawPin(member);
                        EditorGUI.EndDisabledGroup();

                        EditorGUIUtility.labelWidth = oldLabelWidth;
                        EditorGUIUtility.fieldWidth = oldFieldWidth;
                    }
                }
            }
        }

        GUILayout.EndVertical();
        GUILayout.EndScrollView();

        // Plato
        if (plato != null)
            plato.DrawGUI(this, new Vector2(200.0f, 50.0f), true);
    }

    PlatoNode GetMembers(LuaTable self, List<MemberEntry> inputs, List<MemberEntry> outputs, List<MemberEntry> privates)
    {
        PlatoNode node = GetNodeByLua(self);
        if (node == null)
            return null;

        var iter = self.GetEnumerator();
        while (iter.MoveNext())
        {
            PlatoPin pin = node.FindPinByTitle((string)iter.Current.key, true);
            if (pin != null)
            {
                inputs.Add(new MemberEntry() { title = (string)iter.Current.key, value = iter.Current.value, type = pin.Type, index = node.GetPinIndex(pin, true) });
            }
            else
            {
                pin = node.FindPinByTitle((string)iter.Current.key, false);
                if (pin != null)
                    outputs.Add(new MemberEntry() { title = (string)iter.Current.key, value = iter.Current.value, type = pin.Type, index = node.GetPinIndex(pin, false) });
                else
                    privates.Add(new MemberEntry() { title = (string)iter.Current.key, value = iter.Current.value });
            }
        }
        iter.Dispose();

        inputs.Sort((MemberEntry a, MemberEntry b) => { return a.index - b.index; });
        outputs.Sort((MemberEntry a, MemberEntry b) => { return a.index - b.index; });

        return node;
    }

    void DrawValues()
    {
        if (plato == null || plato.graph == null)
            return;

        EditorGUI.BeginDisabledGroup(true);
        List<PlatoNode> nodes = plato.graph.GetAllNodes().FindAll((n) => { return n.Category == "Value"; });
        foreach (PlatoNode node in nodes)
        {
            DrawValue(node);
        }
        EditorGUI.EndDisabledGroup();
    }

    void DrawValue(PlatoNode node)
    {
        if (node.Title == "Bool")
            EditorGUILayout.Toggle((string)node.FindPinByTitle("Name", true).Value, (bool)node.FindPinByTitle("Default", true).Value);
        else if (node.Title == "Float")
            EditorGUILayout.FloatField((string)node.FindPinByTitle("Name", true).Value, (float)node.FindPinByTitle("Default", true).Value);
        else if (node.Title == "Int")
            EditorGUILayout.IntField((string)node.FindPinByTitle("Name", true).Value, (int)node.FindPinByTitle("Default", true).Value);
        else if (node.Title == "Float")
            EditorGUILayout.TextField((string)node.FindPinByTitle("Name", true).Value, (string)node.FindPinByTitle("Default", true).Value);
        else if (node.Title == "Object")
            EditorGUILayout.ObjectField((string)node.FindPinByTitle("Name", true).Value, (GameObject)node.FindPinByTitle("Default", true).Value, typeof(GameObject));
    }

    void DrawPin(MemberEntry member)
    {
        Type type = member.type;
        if (member.type == null)
            type = member.value.GetType();

        if (type == typeof(bool))
            EditorGUILayout.Toggle(member.title, Convert.ToBoolean(member.value));
        else if (type == typeof(int))
            EditorGUILayout.IntField(member.title, Convert.ToInt32(member.value));
        else if (type == typeof(float) || type == typeof(double))
            EditorGUILayout.FloatField(member.title, Convert.ToSingle(member.value));
        else if (type == typeof(GameObject))
            EditorGUILayout.ObjectField(member.title, (GameObject)member.value, typeof(GameObject));
        else if (type == typeof(string) || type == typeof(int[]) )
        {
            try
            {
                byte[] bytes = Convert.FromBase64String((string)member.value);
                ulong uid = BitConverter.ToUInt64(bytes, 0);
                DrawObject(uid, member.title);
            }
            catch
            {
                EditorGUILayout.TextField(member.title, (string)member.value);
            }
        }
    }

    void DrawObject(ulong uid, string title)
    {
        GameObject result = PlayerManager.instance.GetPlayerByID(uid);
        if (result == null)
            result = EnemyManager.instance.GetExistingMonsterByID(uid);
        if (result == null)
        {
            PrometheusCollider c = PrometheusCollider.FindByID(uid);
            if (c != null)
                result = c.gameObject;
        }
        EditorGUILayout.ObjectField(title, result, typeof(GameObject));
    }

    PlatoNode GetNodeByLua(LuaTable self)
    {
        if (self == null || plato == null || plato.graph == null)
            return null;

        PlatoNode node = plato.graph.FindNodeByID(Convert.ToInt32(self["NodeID"]));
        return node;
    }

    void Continue()
    {
        step = false;
        EditorApplication.isPaused = false;
        if (plato != null && plato.graph != null)
            plato.Break(null);
    }

    void Step()
    {
        step = true;
        EditorApplication.isPaused = false;
        if (plato != null && plato.graph != null)
            plato.Break(null);
    }
}
