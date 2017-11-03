using System;
using System.Collections.Generic;
using System.Text;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

using SkillExporter = PlatoCppExporter<PlatoCppSkillType>;

enum TargetLang
{
    Lua,
    CSharp
}

//one phase (min unit)
[Serializable]
public class SkillPhaseItem
{
    public PLATO plato = new PLATO();
    public PLATO preview;

    public void Load(int skillID)
    {
        string filename = string.Format("{0}{1}{2}.txt", PLATO.PLATO_SAVE_PATH, "SkillScript", skillID);
        PlatoLoader loader = new PlatoLoader(plato);
        loader.Load(filename);
    }

    public void Load(string fileName)
    {
        PlatoLoader loader = new PlatoLoader(plato);
        loader.Load(fileName);
    }

    public void Save(int skillID)
    {
        string filename = string.Format("{0}{1}{2}.txt", PLATO.PLATO_SAVE_PATH, "SkillScript", skillID);
        PlatoSaver saver = new PlatoSaver(plato);
        saver.Save(filename);
    }

    public void Save(string fileName)
    {
        PlatoSaver saver = new PlatoSaver(plato);
        saver.Save(fileName);
    }

    public void Comment()
    {
        plato.Comment();
    }

    public void UpdateGUI(EditorWindow wnd, float offset)
    {
        if (preview != null)
            preview.DrawGUI(wnd, new Vector2(0, offset));
        else
            plato.DrawGUI(wnd, new Vector2(0, offset));
    }

    public void ExportLua(string filename)
    {
        plato.ExportLua(filename);
    }

    public void ExportCSharp(string filename)
    {
        plato.ExportCSharp(filename);
    }

    public static void ExportNode(PLATO plato, int skillID)
    {
        if (plato.graph == null)
            return;

        PLATO export = new PLATO(plato);
        PLATO.ExpandMacro(export);

        ExportNodeLua(export, skillID);
#if PLATO_CS_DEBUG
        ExportNodeCSharp(export, skillID);
#endif
    }


    public static void ExportNodeLua(PLATO export, int skillID)
    {
        string filename = string.Format("{0}/SkillNode{1}.txt", PTGraph.EXPORT_LUA_PATH, skillID);
        PlatoWriter writer = new PlatoWriter(filename);
        writer.Line("require('plato/Skill')");
        writer.Line("require('plato/Get')");

        List<PlatoNode> inputNodes = new List<PlatoNode>();
        foreach (PlatoNode node in export.graph.GetAllNodes())
        {
            if (node.Sync)
                inputNodes.Add(node);
        }

        List<PlatoNode> outputNodes = new List<PlatoNode>();
        foreach (PlatoNode node in export.graph.GetAllNodes())
        {
            if (node.Category == "Get" && !PlatoExportUtil.IsGetNode(node))
                outputNodes.Add(node);
        }

        writer.Line("local SkillNode{0} = {{}}", skillID);
        writer.Line(null);

        writer.Line("SkillNode{0}.inputs = {{}}", skillID);
        foreach (PlatoNode node in inputNodes)
        {
            writer.Line("SkillNode{0}.inputs[{1}] = function(sync, actorid, skillid, nodeid, callid, plato)", skillID, node.ID);
            writer.PushIndent();
            writer.Line("local args = {{}}");
            writer.Line("args._IsSync = true");
            writer.Line("args._ActorID = actorid");
            writer.Line("args.Plato = plato");
            writer.Line("args.NodeID = nodeid");
            writer.Line("if sync.marks == nil then");
            writer.PushIndent();
            ExportSyncArgs(writer, node, TargetLang.Lua);
            writer.PopIndent();
            writer.Line("else");
            writer.PushIndent();
            ExportSyncArgsNew(writer, node, TargetLang.Lua);
            writer.PopIndent();
            writer.Line("end");
            List<PlatoPin> inPins = node.GetAllInPins();
            if (inPins.Count > 0)
            {
                writer.Line("local nodeCalls = {{");
                writer.PushIndent();
                for (int i = 0; i < inPins.Count; i++)
                {
                    if (PinTypeUtil.IsExec(inPins[i]))
                    {
                        writer.Line("[{0}] = {1}.{2}.{3},", i + 1, node.Category, node.Title, inPins[i].Title);
                    }
                }
                writer.PopIndent();
                writer.Line("}}");
            }
            writer.Line("nodeCalls[callid](args)");
            writer.PopIndent();
            writer.Line("end");
        }
        writer.Line(null);

        writer.Line("SkillNode{0}.outputs = {{}}", skillID);
        foreach (PlatoNode node in outputNodes)
        {
            writer.Line("SkillNode{0}.outputs[{1}] = '{2}.{3}'", skillID, node.ID, node.Category, node.Title);
        }
        writer.Line(null);

        List<PlatoNode> confirms = export.graph.FindNodesByTitle("ConfirmPhase");
        if (confirms.Count > 0)
            writer.Line("SkillNode{0}.ConfirmPhase = {1}", skillID, confirms[0].ID);

        HashSet<int> effects = new HashSet<int>();
        HashSet<int> buffs = new HashSet<int>();
        HashSet<int> projectiles = new HashSet<int>();
        HashSet<int> weapons = new HashSet<int>();

        // Preload Effects
        foreach (PlatoNode node in export.graph.GetAllNodes().FindAll((x) => x.Title == "PlayEffect" || x.Title == "SpawnCollider"))
        {
            PlatoPin pin = node.FindPinByTitle("EffectID", true);
            int effect = (int)pin.Value;
            if (effect != 0)
                effects.Add(effect);
        }

        // Preload Buffs
        foreach (PlatoNode node in export.graph.GetAllNodes().FindAll((x) => x.Title == "AddSkillBuff"))
        {
            PlatoPin pin = node.FindPinByTitle("ConfigID", true);
            int buff = (int)pin.Value;
            if (buff != 0)
                buffs.Add(buff);
            pin = node.FindPinByTitle("ConfigIDs", true);
            string temp = (string)pin.Value;
            foreach (string b in temp.Split(';'))
            {
                if (int.TryParse(b, out buff))
                    buffs.Add(buff);
            }
        }
        foreach (PlatoNode node in export.graph.GetAllNodes().FindAll((x) => x.Title == "AddSkillBuffs"))
        {
            PlatoPin pin = node.FindPinByTitle("ConfigID", true);
            string temp = (string)pin.Value;
            foreach (string b in temp.Split(';'))
            {
                int buff;
                if (int.TryParse(b, out buff))
                    buffs.Add(buff);
            }
        }

        // Preload Projectiles
        foreach (PlatoNode node in export.graph.GetAllNodes().FindAll((x) => x.Title == "SpawnProjectile"))
        {
            PlatoPin pin = node.FindPinByTitle("DataId", true);
            int id = (int)pin.Value;
            if (id != 0)
                projectiles.Add(id);
        }

        // Preload Weapons
        foreach (PlatoNode node in export.graph.GetAllNodes().FindAll((x) => x.Title == "SwitchWeapon"))
        {
            PlatoPin pin = node.FindPinByTitle("WeaponID", true);
            int id = (int)pin.Value;
            if (id != 0)
                weapons.Add(id);
        }

        writer.Line("SkillNode{0}.effects = {{}}", skillID);
        foreach (int id in effects)
        {
            writer.Line("table.insert(SkillNode{0}.effects, {1})", skillID, id);
        }

        writer.Line("SkillNode{0}.buffs = {{}}", skillID);
        foreach (int id in buffs)
        {
            writer.Line("table.insert(SkillNode{0}.buffs, {1})", skillID, id);
        }

        writer.Line("SkillNode{0}.projectiles = {{}}", skillID);
        foreach (int id in projectiles)
        {
            writer.Line("table.insert(SkillNode{0}.projectiles, {1})", skillID, id);
        }

        writer.Line("SkillNode{0}.weapons = {{}}", skillID);
        foreach (int id in weapons)
        {
            writer.Line("table.insert(SkillNode{0}.weapons, {1})", skillID, id);
        }

        writer.Line("return SkillNode{0}", skillID);
        writer.Close();
    }

    public static void ExportNodeCSharp(PLATO export, int skillID)
    {
        string filename = string.Format("{0}/SkillNode{1}.cs", PTGraph.EXPORT_CSHARP_PATH, skillID);
        PlatoWriter writer = new PlatoWriter(filename);

        List<PlatoNode> inputNodes = new List<PlatoNode>();
        foreach (PlatoNode node in export.graph.GetAllNodes())
        {
            if (node.Sync)
                inputNodes.Add(node);
        }

        List<PlatoNode> outputNodes = new List<PlatoNode>();
        foreach (PlatoNode node in export.graph.GetAllNodes())
        {
            if (node.Category == "Get" && !PlatoExportUtil.IsGetNode(node))
                outputNodes.Add(node);
        }

        writer.Line("using System;");
        writer.Line("using System.Collections.Generic;");
        writer.Line(null);
        writer.Line("namespace Plato {{");

        writer.PushIndent();
        writer.Line("public class SkillNode{0} : PlatoNodeSync {{", skillID);
        writer.PushIndent();
        writer.Line("public SkillNode{0}(){{", skillID);
        writer.PushIndent();
        writer.Line("nodeTriggers = new Dictionary<int, PlatoNodeTrigger>();");
        foreach(PlatoNode node in inputNodes)
        {
            writer.Line("nodeTriggers.Add({0}, PlatoNodeTrigger_{0});", node.ID);
        }
        writer.Line("outputs = new OutputInfo[] {{");
        writer.PushIndent();
        foreach (PlatoNode node in outputNodes)
        {
            writer.Line("new OutputInfo {{ nodeId = {0}, name = \"{1}.{2}\" }},", node.ID, node.Category, node.Title);
        }
        writer.PopIndent();
        writer.Line("}};");

        List<PlatoNode> confirms = export.graph.FindNodesByTitle("ConfirmPhase");
        if (confirms.Count > 0)
            writer.Line("confirmPhase = {0};", confirms[0].ID);

        HashSet<int> effects = new HashSet<int>();
        HashSet<int> buffs = new HashSet<int>();
        HashSet<int> projectiles = new HashSet<int>();
        HashSet<int> weapons = new HashSet<int>();

        // Preload Effects
        foreach (PlatoNode node in export.graph.GetAllNodes().FindAll((x) => x.Title == "PlayEffect" || x.Title == "SpawnCollider"))
        {
            PlatoPin pin = node.FindPinByTitle("EffectID", true);
            int effect = (int)pin.Value;
            if (effect != 0)
                effects.Add(effect);
        }

        // Preload Buffs
        foreach (PlatoNode node in export.graph.GetAllNodes().FindAll((x) => x.Title == "AddSkillBuff"))
        {
            PlatoPin pin = node.FindPinByTitle("ConfigID", true);
            int buff = (int)pin.Value;
            if (buff != 0)
                buffs.Add(buff);
            pin = node.FindPinByTitle("ConfigIDs", true);
            string temp = (string)pin.Value;
            foreach (string b in temp.Split(';'))
            {
                if (int.TryParse(b, out buff))
                    buffs.Add(buff);
            }
        }
        foreach (PlatoNode node in export.graph.GetAllNodes().FindAll((x) => x.Title == "AddSkillBuffs"))
        {
            PlatoPin pin = node.FindPinByTitle("ConfigID", true);
            string temp = (string)pin.Value;
            foreach (string b in temp.Split(';'))
            {
                int buff;
                if (int.TryParse(b, out buff))
                    buffs.Add(buff);
            }
        }

        // Preload Projectiles
        foreach (PlatoNode node in export.graph.GetAllNodes().FindAll((x) => x.Title == "SpawnProjectile"))
        {
            PlatoPin pin = node.FindPinByTitle("DataId", true);
            int id = (int)pin.Value;
            if (id != 0)
                projectiles.Add(id);
        }

        // Preload Weapons
        foreach (PlatoNode node in export.graph.GetAllNodes().FindAll((x) => x.Title == "SwitchWeapon"))
        {
            PlatoPin pin = node.FindPinByTitle("WeaponID", true);
            int id = (int)pin.Value;
            if (id != 0)
                weapons.Add(id);
        }

        if(effects.Count > 0)
        {
            StringBuilder sb = new StringBuilder("");
            foreach (int id in effects)
            {
                sb.AppendFormat("{0},", id);
            }
            writer.Line("effects = new int[] {{{0}}};", sb);
        }
        
        if (buffs.Count > 0)
        {
            StringBuilder sb = new StringBuilder("");
            foreach (int id in buffs)
            {
                sb.AppendFormat("{0},", id);
            }
            writer.Line("buffs = new int[] {{{0}}};", sb);
        }

        if (projectiles.Count > 0)
        {
            StringBuilder sb = new StringBuilder("");
            foreach (int id in projectiles)
            {
                sb.AppendFormat("{0},", id);
            }
            writer.Line("projectiles = new int[] {{{0}}};", sb);
        }

        if (weapons.Count > 0)
        {
            StringBuilder sb = new StringBuilder("");
            foreach (int id in weapons)
            {
                sb.AppendFormat("{0},", id);
            }
            writer.Line("weapons = new int[] {{{0}}};", sb);
        }
        writer.PopIndent();
        writer.Line("}}");
        writer.Line(null);

        foreach (PlatoNode node in inputNodes)
        {
            writer.Line("private static readonly {0}.{1}.NodeTrigger[] NodeCalls_{2} = new {0}.{1}.NodeTrigger[] {{",
                node.Category, node.Title, node.ID);
            writer.PushIndent();
            foreach (var inPin in node.GetAllInPins())
            {
                if(PinTypeUtil.IsExec(inPin))
                    writer.Line("{0}.{1}.Call{2},", node.Category, node.Title, inPin.Title);
            }
            writer.PopIndent();
            writer.Line("}};");
            writer.Line("static void PlatoNodeTrigger_{0}(pvp.PlatoPhaseNodeSync sync, ulong actorId, ushort skillId, ushort nodeId, uint callId, PlatoBehavior plato) {{",
                node.ID);
            writer.PushIndent();
            writer.Line("{0}.{1}.Arg args = new {0}.{1}.Arg();", node.Category, node.Title);
            writer.Line("args.Plato = plato.csharp;");
            writer.Line("args.NodeID = nodeId;");
            //writer.Line("if (!sync.marksSpecified) {{");
            //writer.PushIndent();
            //ExportSyncArgs(writer, node, TargetLang.CSharp);
            //writer.PopIndent();
            //writer.Line("}} else {{");
            //writer.PushIndent();
            //ExportSyncArgsNew(writer, node, TargetLang.CSharp);
            //writer.PopIndent();
            //writer.Line("}}");
            ExportSyncArgsCSharp(writer, node);

            StringBuilder outParams = new StringBuilder();
            node.GetAllOutPins().FindAll((o) => PinTypeUtil.IsValue(o)).ForEach((o) =>
                {
                    outParams.AppendFormat(", ref {0}", o.Title);
                }
            );

            writer.Line("NodeCalls_{0}[callId](args{1});", node.ID, outParams.ToString());
            writer.PopIndent();
            writer.Line("}}");
        }
        writer.PopIndent();
        writer.Line("}}");
        writer.PopIndent();
        writer.Line("}}");
        writer.Close();
    }

    static void ExportSyncArgs(PlatoWriter writer, PlatoNode node, TargetLang targetLang)
    {
        Dictionary<Type, int> indices = null;
        if(targetLang == TargetLang.Lua)
        {
            indices = new Dictionary<Type, int>() {
                { typeof(string), 1 },
                { typeof(float), 1 },
                { typeof(int), 1 },
                { typeof(ulong), 1 },
                { typeof(bool), 1 },
            };
        }
        else
        {
            indices = new Dictionary<Type, int>() {
                { typeof(string), 0 },
                { typeof(float), 0 },
                { typeof(int), 0 },
                { typeof(ulong), 0 },
                { typeof(bool), 0 },
            };
        }

        foreach (PlatoPin pin in node.GetAllInPins())
        {
            if (PinTypeUtil.IsExec(pin) || !string.IsNullOrEmpty(pin.ParentPin))
                continue;

            if (pin is DropdownPin)
            {
                DropdownPin dropdown = pin as DropdownPin;

                if(targetLang == TargetLang.Lua)
                {
                    writer.Line("local {0}s = {{", pin.Title);
                    writer.PushIndent();
                    for (int i = 0; i < dropdown.DropdownList.Count; ++i)
                    {
                        writer.Line("[{0}] = '{1}',", i, dropdown.DropdownList[i]);
                    }
                    writer.PopIndent();
                    writer.Line("}}");
                    writer.Line("args.{0} = {0}s[sync.int32s[{1}]]", pin.Title, indices[typeof(int)]++);
                }
                else
                {
                    writer.Line("args.{0} = ({1}.{2}.{0})(sync.int32s[{3}]);", pin.Title, node.Category, node.Title, indices[typeof(int)]++);
                }

                if (dropdown.PinDefines.Count > 0)
                {
                    if (targetLang == TargetLang.Lua)
                    {
                        writer.Line("local params = string.split(sync.strings[{0}], ',')", indices[typeof(string)]++);
                        for (int i = 0; i < dropdown.PinDefines.Count; ++i)
                        {
                            writer.Line("if args.{0} == '{1}' then", pin.Title, dropdown.DropdownList[i]);
                            writer.PushIndent();
                            for (int j = 0; j < dropdown.PinDefines[i].Count; ++j)
                            {
                                var x = dropdown.PinDefines[i][j];
                                if (x.Value == typeof(bool))
                                    writer.Line("args.{0} = params[{1}] == 'true' and true or false", x.Key, j + 1);
                                else if (x.Value == typeof(int) || x.Value == typeof(float))
                                    writer.Line("args.{0} = tonumber(params[{1}])", x.Key, j + 1);
                                else if (x.Value == typeof(ulong))
                                    writer.Line("args.{0} = LuaUtil.StringToUInt64(params[{1}])", x.Key, j + 1);
                                else
                                    writer.Line("args.{0} = params[{1}]", x.Key, j + 1);
                            }
                            writer.PopIndent();
                            writer.Line("end");
                        }
                    }
                    else
                    {
                        writer.Line("string[] strParams = sync.strings[{0}].Split(',');", indices[typeof(string)]++);
                        for (int i = 0; i < dropdown.PinDefines.Count; ++i)
                        {
                            writer.Line("if(args.{0} == {1}.{2}.{0}.{3}) {{", pin.Title, node.Category, node.Title, dropdown.DropdownList[i]);
                            writer.PushIndent();
                            for (int j = 0; j < dropdown.PinDefines[i].Count; ++j)
                            {
                                var x = dropdown.PinDefines[i][j];
                                if (x.Value == typeof(bool))
                                    writer.Line("args.{0} = strParams[{1}] == \"true\";", x.Key, j);
                                else if (x.Value == typeof(int))
                                    writer.Line("args.{0} = Convert.ToInt(strParams[{1}]);", x.Key, j);
                                else if (x.Value == typeof(float))
                                    writer.Line("args.{0} = Convert.ToSingle(strParams[{1}]);", x.Key, j);
                                else if (x.Value == typeof(ulong))
                                    writer.Line("args.{0} = Convert.ToUInt64(strParams[{1}]);", x.Key, j);
                                else
                                    writer.Line("args.{0} = strParams[{1}];", x.Key, j);
                            }
                            writer.PopIndent();
                            writer.Line("}}");
                        }
                    }
                }
            }
            else
            {
                if (targetLang == TargetLang.Lua)
                {
                    if (pin.Type.IsArray)
                        writer.Line("args.{0} = string.split(sync.strings[{1}], ';')", pin.Title, indices[typeof(string)]++);
                    else
                        writer.Line("args.{0} = sync.{1}[{2}]", pin.Title, PinTypeUtil.GetCppVectorType(pin.Type).ToLower(), indices[pin.Type]++);
                }
                else
                {
                    if (pin.Type.IsArray)
                        writer.Line("args.{0} = PlatoUtil.StringSplitToIntList(sync.strings[{1}], ';');", pin.Title, indices[typeof(string)]++);
                    else
                        writer.Line("args.{0} = sync.{1}[{2}];", pin.Title, PinTypeUtil.GetCppVectorType(pin.Type).ToLower(), indices[pin.Type]++);
                }
            }
        }

        if (targetLang == TargetLang.Lua)
        {
            foreach (PlatoPin pin in node.GetAllOutPins())
            {
                if (PinTypeUtil.IsExec(pin) || !string.IsNullOrEmpty(pin.ParentPin))
                    continue;
                if (pin.Type.IsArray)
                    writer.Line("args.{0} = string.split(sync.strings[{1}], ';')", pin.Title, indices[typeof(string)]++);
                else
                    writer.Line("args.{0} = sync.{1}[{2}]", pin.Title, PinTypeUtil.GetCppVectorType(pin.Type).ToLower(), indices[pin.Type]++);
            }
        }
    }

    static void ExportSyncArgsNew(PlatoWriter writer, PlatoNode node, TargetLang targetLang)
    {
        Dictionary<Type, int> indices = null;
        if (targetLang == TargetLang.Lua)
        {
            indices = new Dictionary<Type, int>() {
                { typeof(string), 1 },
                { typeof(float), 1 },
                { typeof(int), 1 },
                { typeof(ulong), 1 },
                { typeof(bool), 1 },
            };
        }
        else
        {
            indices = new Dictionary<Type, int>() {
                { typeof(string), 0 },
                { typeof(float), 0 },
                { typeof(int), 0 },
                { typeof(ulong), 0 },
                { typeof(bool), 0 },
            };
        }
        string lineEnding;
        string strSplit;
        if (targetLang == TargetLang.Lua)
        {
            strSplit = "local params = string.split(sync.strings[{0}], {1})";
            lineEnding = "";
        }
        else
        {
            strSplit = "string[] strParams = sync.strings[{0}].Split({1});";
            lineEnding = ";";
        }

        foreach (PlatoPin pin in node.GetAllInPins())
        {
            if (PinTypeUtil.IsExec(pin) || !string.IsNullOrEmpty(pin.ParentPin))
                continue;

            if (pin is DropdownPin)
            {
                DropdownPin dropdown = pin as DropdownPin;
                if (targetLang == TargetLang.Lua)
                {
                    writer.Line("args.{0} = {1}", pin.Title, pin.ExportToLua());
                }
                else
                {
                    writer.Line("args.{0} = {1};", pin.Title, pin.ExportToCSharp());
                }

                if (dropdown.PinDefines.Count > 0)
                {
                    if (node.Title == "SpawnCollider")
                    {
                        writer.Line(strSplit, indices[typeof(string)]++, "';'");
                    }
                    else
                    {
                        writer.Line(strSplit, indices[typeof(string)]++, "','");
                    }

                    //修改导出的写法
                    //writer.Line("local params = string.split(sync.strings[{0}], ',')", indices[typeof(string)]++);

                    for (int i = 0; i < dropdown.PinDefines.Count; ++i)
                    {
                        if (!pin.Value.Equals(dropdown.DropdownList[i]))
                            continue;
                        for (int j = 0; j < dropdown.PinDefines[i].Count; ++j)
                        {
                            var x = dropdown.PinDefines[i][j];
                            if (targetLang == TargetLang.Lua)
                            {
                                if (x.Value == typeof(bool))
                                    writer.Line("args.{0} = params[{1}] == '1' and true or false", x.Key, j + 1);
                                else if (x.Value == typeof(int) || x.Value == typeof(float))
                                    writer.Line("args.{0} = tonumber(params[{1}])", x.Key, j + 1);
                                else if (x.Value == typeof(ulong))
                                    writer.Line("args.{0} = LuaUtil.StringToUInt64(params[{1}])", x.Key, j + 1);
                                else
                                    writer.Line("args.{0} = params[{1}]", x.Key, j + 1);
                            }
                            else
                            {
                                if (x.Value == typeof(bool))
                                    writer.Line("args.{0} = (strParams[{1}] == \"1\");", x.Key, j);
                                else if (x.Value == typeof(int))
                                    writer.Line("args.{0} = Convert.ToInt(strParams[{1}]);", x.Key, j);
                                else if (x.Value == typeof(float))
                                    writer.Line("args.{0} = Convert.ToSingle(strParams[{1}]);", x.Key, j);
                                else if (x.Value == typeof(ulong))
                                    writer.Line("args.{0} = Convert.ToUInt64(strParams[{1}]);", x.Key, j);
                                else
                                    writer.Line("args.{0} = strParams[{1}];", x.Key, j);
                            }
                        }
                    }
                }
            }
            else
            {
                if (pin.Prevs.Count == 0)
                {
                    if (targetLang == TargetLang.Lua)
                    {
                        writer.Line("args.{0} = {1}", pin.Title, pin.ExportToLua());
                    }
                    else
                    {
                        writer.Line("args.{0} = {1};", pin.Title, pin.ExportToCSharp());
                    }
                }
                else
                {
                    if (pin.Type.IsArray)
                    {
                        if (targetLang == TargetLang.Lua)
                        {
                            writer.Line("args.{0} = string.split(sync.strings[{1}], ';')", pin.Title, indices[typeof(string)]++);
                        }
                        else
                        {
                            writer.Line("args.{0} = PlatoUtil.StringSplitToIntList(sync.strings[{1}], ';');", pin.Title, indices[typeof(string)]++);
                        }
                    }
                    else
                        writer.Line("args.{0} = sync.{1}[{2}]{3}", pin.Title, PinTypeUtil.GetCppVectorType(pin.Type).ToLower(), indices[pin.Type]++, lineEnding);
                }
            }
        }

        if(targetLang == TargetLang.Lua)
        {
            foreach (PlatoPin pin in node.GetAllOutPins())
            {
                if (PinTypeUtil.IsExec(pin) || !string.IsNullOrEmpty(pin.ParentPin))
                    continue;
                if (pin.Type.IsArray)
                {
                    writer.Line("args.{0} = string.split(sync.strings[{1}], ';')", pin.Title, indices[typeof(string)]++);
                }
                else
                    writer.Line("args.{0} = sync.{1}[{2}]", pin.Title, PinTypeUtil.GetCppVectorType(pin.Type).ToLower(), indices[pin.Type]++);
            }
        }
    }

    static void ExportSyncPinCSharp(PlatoWriter writer, PlatoPin pin, bool isOutPin)
    {
        string prefix = "args.";
        if (isOutPin)
        {
            Dictionary<Type, string> dicPrefixes = new Dictionary<Type, string>
            {
                {typeof(bool),  "bool "},
                {typeof(int),  "int "},
                {typeof(float),  "float "},
                {typeof(ulong),  "ulong "},
                {typeof(string[]),  "string "},
                {typeof(int[]),  "List<int> "},
                {typeof(float[]),  "List<float> "},
                {typeof(ulong[]),  "List<ulong> "},
            };

            prefix = dicPrefixes[pin.Type];
        }
        if (pin.Type == typeof (bool))
            writer.Line(((bool) pin.Value) ? "{0}{1} = true;" : "{0}{1} = false;", prefix, pin.Title);
        else if (pin.Type == typeof (int))
            writer.Line("{0}{1} = {2};", prefix, pin.Title, Convert.ToInt32(pin.Value));
        else if (pin.Type == typeof (float))
            writer.Line("{0}{1} = {2}f;", prefix, pin.Title, Convert.ToSingle(pin.Value));
        else if (pin.Type == typeof (ulong))
            writer.Line("{0}{1} = {2};", prefix, pin.Title, pin.ExportToCSharp());
        else if (pin.Type == typeof (int[]))
        {
            if (!isOutPin)
                writer.Line("{0}{1} = new List<int>{{ {2} }};", prefix, pin.Title, pin.Value);
            else
                writer.Line("{0}{1} = {2};", prefix, pin.Title, pin.Value, pin.ExportToCSharp());
        }
        else if (pin.Type == typeof (float[]))
        {
            if (!isOutPin)
                writer.Line("{0}{1} = new List<float>{{ {2} }};", prefix, pin.Title, pin.Value);
            else
                writer.Line("{0}{1} = {2};", prefix, pin.Title, pin.ExportToCSharp());
        }
        else if (pin.Type == typeof (ulong[]))
            writer.Line("{0}{1} = {2};", prefix, pin.Title, pin.ExportToCSharp());
        else if (pin.Type == typeof (string))
        {
            if (!isOutPin)
                writer.Line("{0}{1} = \"{2}\";", prefix, pin.Title, pin.Value);
            else
                writer.Line("{0}{1} = {2};", prefix, pin.Title, pin.ExportToCSharp());
        }
    }

    static void ExportSyncArgsCSharp(PlatoWriter writer, PlatoNode node)
    {
        PlatoWriter temp = new PlatoWriter(writer);

        ulong marks = 1;
        Dictionary<Type, string> dicIndexerStr = new Dictionary<Type, string>
        {
            {typeof(bool),  "indexBool"},
            {typeof(int),  "indexInt"},
            {typeof(float),  "indexFloat"},
            {typeof(ulong),  "indexULong"},
            {typeof(string),  "indexStr"},
        };
        Dictionary<Type, int> dicIndexerRef = new Dictionary<Type, int>
        {
            {typeof(bool),  0},
            {typeof(int),  0},
            {typeof(float),  0},
            {typeof(ulong),  0},
            {typeof(string),  0},
        };

        string spliter = null;
        if (node.Title == "SpawnCollider")
        {
            spliter = "';'";
        }
        else
        {
            spliter = "','";
        }

        foreach (PlatoPin pin in node.GetAllInPins())
        {
            if (PinTypeUtil.IsExec(pin) || !string.IsNullOrEmpty(pin.ParentPin))
                continue;
            if (pin is DropdownPin)
            {
                DropdownPin dropdown = pin as DropdownPin;
                temp.Line("args.{0} = {1}.{2}.{0}.{3};", pin.Title, node.Category, node.Title, pin.Value);
                if (dropdown.PinDefines.Count > 0)
                {
                    marks = marks << 1;
                    temp.Line("if(({0} & sync.marks) != 0) {{", marks);
                    temp.PushIndent();
                    temp.Line("string[] strParams = sync.strings[indexStr ++].Split({0});", spliter);
                    dicIndexerRef[typeof(string)]++;

                    for (int i = 0; i < dropdown.PinDefines.Count; ++i)
                    {
                        if (!pin.Value.Equals(dropdown.DropdownList[i]))
                            continue;
                        for (int j = 0; j < dropdown.PinDefines[i].Count; ++j)
                        {
                            var x = dropdown.PinDefines[i][j];
                            if (x.Value == typeof(bool))
                                temp.Line("args.{0} = (strParams[{1}] == \"1\");", x.Key, j);
                            else if (x.Value == typeof(int))
                                temp.Line("args.{0} = Convert.ToInt32(strParams[{1}]);", x.Key, j);
                            else if (x.Value == typeof(float))
                                temp.Line("args.{0} = Convert.ToSingle(strParams[{1}]);", x.Key, j);
                            else if (x.Value == typeof(ulong))
                                temp.Line("args.{0} = Convert.ToUInt64(strParams[{1}]);", x.Key, j);
                            else
                                temp.Line("args.{0} = strParams[{1}];", x.Key, j);
                        }
                    }
                    temp.PopIndent();
                    temp.Line("}} else {{");
                    temp.PushIndent();

                    foreach (PlatoPin childPin in node.GetAllInPins())
                    {
                        if (childPin.ParentPin != dropdown.Title)
                            continue;
                        ExportSyncPinCSharp(temp, childPin, false);
                    }
                    temp.PopIndent();
                    temp.Line("}}");
                }
            }
            else if(string.IsNullOrEmpty(pin.ParentPin))
            {
                temp.Line("if(({0} & sync.marks) != 0) {{", marks);
                temp.PushIndent();
                if (pin.Type.IsArray)
                {
                    temp.Line("args.{0} = PlatoUtil.StringSplitToIntList(sync.strings[indexStr ++], ';');", pin.Title);
                    dicIndexerRef[typeof(string)]++;
                }
                else
                {
                    temp.Line("args.{0} = sync.{1}[{2} ++];", pin.Title, PinTypeUtil.GetCppVectorType(pin.Type).ToLower(), dicIndexerStr[pin.Type]);
                    dicIndexerRef[pin.Type]++;
                }
                temp.PopIndent();
                temp.Line("}} else {{");
                temp.PushIndent();
                ExportSyncPinCSharp(temp, pin, false);
                temp.PopIndent();
                temp.Line("}}");
            }

            marks = marks << 1;
        }

        node.GetAllOutPins().FindAll((outPin) => PinTypeUtil.IsValue(outPin)).ForEach((outPin) =>
            {
                ExportSyncPinCSharp(temp, outPin, true);
                temp.Line("if(({0} & sync.marks) != 0) {{", marks);
                temp.PushIndent();
                temp.Line("{0} = sync.{1}[{2} ++];", outPin.Title, PinTypeUtil.GetCppVectorType(outPin.Type).ToLower(), dicIndexerStr[outPin.Type]);
                dicIndexerRef[outPin.Type]++;
                temp.PopIndent();
                temp.Line("}}");
                marks = marks << 1;
            }
        );

        var iter = dicIndexerRef.GetEnumerator();
        while (iter.MoveNext())
        {
            if (iter.Current.Value == 0)
                continue;
            writer.Line("int {0} = 0;", dicIndexerStr[iter.Current.Key]);
        }
        writer.WriteWithoutIndent(temp.GetText());
    }

    public static void ExportCpp(PLATO plato, int skillID, SkilldataSetting setting)
    {
        if (plato.graph == null)
            return;

        PLATO export = new PLATO(plato);
        PLATO.ExpandMacro(export);

        SkillExporter exporter = new SkillExporter(export, skillID, setting);
        exporter.ExportCpp();
    }

    public static void ExportComponentToCpp(PLATO plato)
    {
        if (plato.graph == null)
            return;

        PLATO export = new PLATO(plato);
        PLATO.ExpandMacro(export);

        SkillExporter exporter = new SkillExporter(export, 0, null);
        exporter.ExportComponent();
    }

}

public class FrameEvent
{
    public float percent;
    public int intParam;
    public float floatParam;
    public string stringParam;
    public string functionName;
}