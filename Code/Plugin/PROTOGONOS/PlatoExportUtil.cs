using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using UnityEngine;
using UnityEngine.UI;
using UnityEditor;
using SLua;

public class PlatoExportUtil
{
    /// <summary>
    /// 重新导出所有技能脚本
    /// </summary>
    [MenuItem("Export/Plato/Export All Skills")]
    public static void ExportAllSkill()
    {
        PlatoNodeGenerator.GenerateLua();

        // Client
        string[] filenames = Directory.GetFiles(PLATO.PLATO_SAVE_PATH, "*.txt", SearchOption.TopDirectoryOnly);
        for (int i = 0; i < filenames.Length; ++i)
        {
            string filename = filenames[i];
            EditorUtility.DisplayProgressBar("Export", filename, (float)i / filenames.Length);

            if (!filename.Contains("SkillScript"))
                continue;

            try
            {
                PLATO plato = new PLATO();
                PlatoLoader loader = new PlatoLoader(plato);
                loader.Load(filename);
                plato.ExportLua(Path.Combine(PTGraph.EXPORT_LUA_PATH, Path.GetFileName(filename)));
                string fileNameWithoutExt = Path.GetFileNameWithoutExtension(filename);
                plato.ExportCSharp(Path.Combine(Path.Combine(PLATO.CSHARP_SAVE_PATH, "Skill"), fileNameWithoutExt) + ".cs");
                int skillId = Convert.ToInt32(fileNameWithoutExt.Substring(fileNameWithoutExt.LastIndexOf("SkillScript", StringComparison.Ordinal) + 11));
                SkillPhaseItem.ExportNode(plato, skillId);
                SkillPhaseItem.ExportCpp(plato, skillId, null);
                SkillPhaseItem.ExportComponentToCpp(plato);
            }
            catch (Exception ex)
            {
                Debug.LogErrorFormat("{0}: {1}", filename, ex.Message);
            }
        }
        EditorUtility.ClearProgressBar();

        // Server
        //     IntPtr L = LuaDLL.luaL_newstate();
        //     LuaDLL.luaL_openlibs(L);

        //     List<SkilldataSetting> settings = new List<SkilldataSetting>();

        //     filenames = Directory.GetFiles(PTGraph.EXPORT_LUA_PATH, "*.txt", SearchOption.TopDirectoryOnly);
        //     foreach (string filename in filenames)
        //     {
        //         if (filename.Contains("SkillData") == false)
        //             continue;

        //         try
        //         {
        //             TextAsset asset = AssetDatabase.LoadAssetAtPath<TextAsset>(filename);

        //             object table;
        //             if (LuaUtil.LoadLua(L, asset.bytes, filename, out table) && table != null)
        //             {
        //                 (table as LuaTable).l = L;
        //                 var iter = (table as LuaTable).GetEnumerator();
        //                 while (iter.MoveNext())
        //                 {
        //                     LuaTable data = iter.Current.value as LuaTable;
        //                     if (data == null)
        //                         continue;

        //                     SkilldataSetting setting = new SkilldataSetting();
        //                     LuaUtil.TravelTable(L, data, (string key, object value) =>
        //                     {
        //                         switch (key)
        //                         {
        //                             case "skillID": setting.skillID = Convert.ToInt32(value); break;
        //                             case "skillName": setting.skillName = (string)value; break;
        //                             //case "cdType": setting.cdType = Convert.ToInt32(value); break;
        //                             //case "cdValue": setting.cdValue = Convert.ToInt32(value); break;
        //                             case "castType": setting.castType = (ReleaseMode)Convert.ToInt32(value); break;
        //                             case "rangeEffectID": setting.rangeEffectID = Convert.ToInt32(value); break;
        //                             case "rangeRadius": setting.rangeRadius = Convert.ToInt32(value); break;
        //                             case "indicatorEffectID": setting.indicatorEffectID = Convert.ToInt32(value); break;
        //                             case "indicatorType": setting.indicatorType = (PTIndicatorType)Convert.ToInt32(value); break;
        //                             case "indicatorRadius": setting.indicatorRadius = Convert.ToInt32(value); break;
        //                             case "indicatorAngle": setting.indicatorAngle = Convert.ToInt32(value); break;
        //                             case "indicatorLength": setting.indicatorLength = Convert.ToInt32(value); break;
        //                             case "indicatorWidth": setting.indicatorWidth = Convert.ToInt32(value); break;
        //                             case "indicatorFollowType": setting.indicatorFollowType = (ReleaseType)Convert.ToInt32(value); break;
        //                             case "touchDelay": setting.touchDelay = Convert.ToBoolean(value); break;
        //                             case "touchDelayTime": setting.touchDelayTime = Convert.ToInt32(value); break;
        //                             case "needCheckCollider": setting.needCheckCollider = Convert.ToBoolean(value); break;
        //                             case "needExtendIndicator": setting.needExtendIndicator = Convert.ToBoolean(value); break;
        //                             case "extendIndicatorA": setting.extendIndicatorA = Convert.ToInt32(value); break;
        //                             case "extendIndicatorB": setting.extendIndicatorB = Convert.ToInt32(value); break;
        //                             case "extendIndicatorRadius": setting.extendIndicatorRadius = Convert.ToInt32(value); break;
        //                             case "extendIndicatorWidth": setting.extendIndicatorWidth = Convert.ToInt32(value); break;


        //                             case "hasSecondPhase": setting.isSecondPhase = Convert.ToBoolean(value); break;
        //                             //case "secondTrigger": setting.secondTrigger = (SecondTrigger)Convert.ToInt32(value); break;
        //                             //case "secondEvent": setting.secondEvent = (SecondEvent)Convert.ToInt32(value); break;
        //                             case "srangeEffectID": setting.S_rangeEffectID = Convert.ToInt32(value); break;
        //                             case "srangeRadius": setting.S_rangeRadius = Convert.ToInt32(value); break;
        //                             case "sindicatorEffectID": setting.S_indicatorEffectID = Convert.ToInt32(value); break;
        //                             case "sindicatorType": setting.S_indicatorType = (PTIndicatorType)Convert.ToInt32(value); break;
        //                             case "sindicatorRadius": setting.S_indicatorRadius = Convert.ToInt32(value); break;
        //                             case "sindicatorAngle": setting.S_indicatorAngle = Convert.ToInt32(value); break;
        //                             case "sindicatorLength": setting.S_indicatorLength = Convert.ToInt32(value); break;
        //                             case "sindicatorWidth": setting.S_indicatorWidth = Convert.ToInt32(value); break;
        //                             case "sindicatorFollowType": setting.S_indicatorFollowType = (ReleaseType)Convert.ToInt32(value); break;
        //                             case "sneedCheckCollider": setting.S_needCheckCollider = Convert.ToBoolean(value); break;
        //                             case "sneedExtendIndicator": setting.S_needExtendIndicator = Convert.ToBoolean(value); break;
        //                             case "sextendIndicatorA": setting.S_extendIndicatorA = Convert.ToInt32(value); break;
        //                             case "sextendIndicatorB": setting.S_extendIndicatorB = Convert.ToInt32(value); break;
        //                             case "sextendIndicatorRadius": setting.S_extendIndicatorRadius = Convert.ToInt32(value); break;
        //                             case "sextendIndicatorWidth": setting.S_extendIndicatorWidth = Convert.ToInt32(value); break;
        //                         }
        //                     });
        //                     settings.Add(setting);
        //                 }
        //                 iter.Dispose();
        //             }
        //         }
        //         catch (Exception ex) {
        //	Debug.LogErrorFormat ("{0}: {1}", filename, ex.Message);
        //}
        //     }

        //     LuaDLL.lua_close(L);
        //     L = IntPtr.Zero;

        //foreach (SkilldataSetting setting in settings)
        //{
        //    PLATO plato = new PLATO();
        //    PlatoLoader loader = new PlatoLoader(plato);
        //    loader.Load(string.Format("{0}SkillScript{1}.txt", PLATO.PLATO_SAVE_PATH, setting.skillID));
        //    SkillPhaseItem.ExportNode(plato, setting.skillID);
        //    SkillPhaseItem.ExportCpp(plato, setting.skillID, setting);
        //    SkillPhaseItem.ExportComponentToCpp(plato);
        //}
        EditorUtility.DisplayDialog("Skill", "导出所有技能结束", "ok");
    }

    /// <summary>
    /// 重新导出所有武器脚本
    /// </summary>
    [MenuItem("Export/Plato/Export All Weapons")]
    public static void ExportAllWeapons()
    {
        PlatoNodeGenerator.GenerateLua();

        // Client
        string[] filenames = Directory.GetFiles(PLATO.PLATO_WEAPON_SAVE_PATH, "*.txt", SearchOption.TopDirectoryOnly);
        foreach (string filename in filenames)
        {
            if (!filename.Contains("WeaponScript"))
                continue;

            try
            {
                PLATO plato = new PLATO();
                PlatoLoader loader = new PlatoLoader(plato);
                loader.Load(filename);
                plato.ExportLua(Path.Combine(PTGraph.EXPORT_WEAPON_LUA_PATH, Path.GetFileName(filename)));
                plato.ExportCSharp(Path.Combine(Path.Combine(PLATO.CSHARP_SAVE_PATH, "Weapon"), Path.GetFileNameWithoutExtension(filename)) + ".cs");
            }
            catch (Exception ex)
            {
                Debug.LogErrorFormat("{0}: {1}", filename, ex.Message);
            }
        }
        EditorUtility.DisplayDialog("Weapon", "导出所有武器结束", "ok");

    }

    /// <summary>
	/// 重新导出所有Projectile脚本
	/// </summary>
	[MenuItem("Export/Plato/Export All Projectiles")]
    public static void ExportAllProjectiles()
    {
        PlatoNodeGenerator.GenerateLua();

        // Client
        string[] filenames = Directory.GetFiles(PLATO.PLATO_PROJECTILE_SAVE_PATH, "*.txt", SearchOption.TopDirectoryOnly);
        foreach (string filename in filenames)
        {
            if (!filename.Contains("Projectile"))
                continue;

            try
            {
                PLATO plato = new PLATO();
                PlatoLoader loader = new PlatoLoader(plato);
                loader.Load(filename);
                plato.ExportLua(Path.Combine(PTGraph.EXPORT_PROJECTILE_LUA_PATH, Path.GetFileName(filename)));
#if PLATO_CS_DEBUG
                plato.ExportCSharp(Path.Combine(Path.Combine(PLATO.CSHARP_SAVE_PATH, "Projectile"), Path.GetFileNameWithoutExtension(filename)) + ".cs");
#endif
            }
            catch (Exception ex)
            {
                Debug.LogErrorFormat("{0}: {1}", filename, ex.Message);
            }
        }
        EditorUtility.DisplayDialog("Projectile", "导出所有Projectile结束", "ok");

    }

    public static void ExportCppParam(List<PlatoPin> pins, PlatoWriter writer, ref int index)
    {
        for (int i = 0; i < pins.Count; ++i)
        {
            PlatoPin pin = pins[i];
            if (IsSkip(pin))
                continue;

            pin.ExportCppParam(writer, ref index);
        }
    }
    public static void ExportCppField(List<PlatoPin> pins, PlatoWriter writer)
    {
        for (int i = 0; i < pins.Count; ++i)
        {
            PlatoPin pin = pins[i];
            if (IsSkip(pin))
                continue;

            pin.ExportCppField(writer);
        }
    }

    private static bool IsSkip(PlatoPin pin)
    {
        if (PinTypeUtil.IsExec(pin))
            return true;
        if (!string.IsNullOrEmpty(pin.ParentPin))
            return true;
        return false;
    }

    public static void ExportLinkPins(List<PlatoPin> linkPins, PlatoWriter writer, Dictionary<string, string> ExportLinkPins)
    {
        foreach (PlatoPin p in linkPins)
        {
            PlatoPin dst = p;
            PlatoPin src = p.Prevs[0];

            string srcStr;
            if (string.IsNullOrEmpty(src.ParentPin))
                srcStr = string.Format("node{0}->get{1}()", src.ParentNode.ID, src.Title);
            else
                srcStr = string.Format("node{0}->{1}({2})", src.ParentNode.ID, GetSetParams(src, "get"), src.ChildIndex);

            string ret = null;
            if (!ExportLinkPins.TryGetValue(dst.ParentNode.Title, out ret))
            {
                ret = null;
            }
            if (ret != null && dst.ParentPin == "Add" && dst.ChildIndex % 2 == 1)
            {
                PlatoPin typePin = dst.ParentNode.GetSameParentPins(dst.ParentPin)[dst.ChildIndex - 1];
                writer.Line(ret, src.ParentNode.ID, dst.ParentNode.ID, typePin.Value, srcStr);
            }
            else
            {
                string dstStr;
                if (string.IsNullOrEmpty(dst.ParentPin))
                    dstStr = string.Format("node{0}->set{1}(", dst.ParentNode.ID, dst.Title);
                else
                    dstStr = string.Format("node{0}->{1}({2}, ", dst.ParentNode.ID, GetSetParams(dst, "set"), dst.ChildIndex);

                writer.Line("    if (node{0} != nullptr) {1}{2});", src.ParentNode.ID, dstStr, srcStr);
            }
        }
    }

    public static void ExportVarPin(PlatoPin pin, int nodeId, int id, PlatoWriter writer, Dictionary<string, string> ExportVarPins)
    {
        PlatoPin prev = pin.Prevs[0];

        PlatoPin pp = prev.ParentNode.FindPinByTitle("Name", true);
        if (pp != null)
        {
            string prevTitle = pp.Value as string;

            if (string.IsNullOrEmpty(pin.ParentPin))
                writer.Line("        node{0}->set{1}(variables->getVariable<{2}>(Variable_{3}_{4}));", nodeId, pin.Title, PinTypeUtil.GetCppType(prev.Type), id, prevTitle);
            else
            {
                string ret = null;
                if (!ExportVarPins.TryGetValue(pin.ParentNode.Title, out ret))
                {
                    ret = null;
                }
                if (ret != null)
                {
                    PlatoPin typePin = pin.ParentNode.GetSameParentPins(pin.ParentPin)[pin.ChildIndex - 1];
                    writer.Line(ret, nodeId, "reviseValue", typePin.Value, PinTypeUtil.GetCppType(prev.Type), id, prevTitle);
                }
                else
                {
                    writer.Line("        node{0}->{1}({2}, variables->getVariable<{3}>(Variable_{4}_{5}));", nodeId, GetSetParams(pin, "set"), pin.ChildIndex, PinTypeUtil.GetCppType(prev.Type), id, prevTitle);
                }
            }
        }

    }

    private static string GetSetParams(PlatoPin pin, string prefix)
    {
        PlatoPin parentPin = pin.ParentNode.FindPinByTitle(pin.ParentPin, true);
        if (parentPin is ButtonPin)
        {
            return string.Format("{1}{0}", (parentPin as ButtonPin).CallbackNodeName, prefix);
        }
        else if (parentPin is DropdownPin)
        {
            Type baseType;
            if (DropdownPin.IsSameType(parentPin as DropdownPin, out baseType))
                return string.Format("{1}{0}Params", parentPin.Title, prefix);
            else
                return string.Format("getVars().{1}Variable<{0}>", PinTypeUtil.GetCppType(pin.Type), prefix);
        }
        else
        {
            throw new Exception(string.Format("Invalid ParentPin: {0}.{1}", pin.ParentNode.Title, pin.Title));
        }
    }


    public static bool IsEmptyString(string str)
    {
        if (str == null || str == "")
            return true;
        return false;
    }

    public static bool IsGetNode(PlatoNode node)
    {
        if (node.Category != "Get")
        {
            return false;
        }
        else
        {
            if (node.Title.Contains("Location"))
                return false;
            else if (node.Title.Contains("Rotation"))
                return false;
            else if (node.Title.Contains("Input"))
                return false;
            else if (node.Title.Contains("State"))
                return false;
            else if (node.Title == "GetProjOwnerAttr")
                return false;
        }
        return true;
    }

    /// <summary>
    /// 简单格式导出
    /// </summary>
    /// <returns></returns>
    public static string ExportFormat(PlatoNode node, string format, bool isLua = true)
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
                        code.AddRange(node.ID.ToString());
                    }
                    // 特殊标记，所有动态输入引脚
                    else if (pinName == "DYNAMIC_INPUTS")
                    {
                        List<string> inputs = new List<string>();
                        foreach (PlatoPin pin in node.GetAllInPins().FindAll((x) => x.IsDynamic))
                        {
                            if (isLua)
                                inputs.Add(PlatoExportUtil.ExportInPinByTitleLua(node, pin.Title));
                            else
                                inputs.Add(PlatoExportUtil.ExportInPinByTitleCSharp(node, pin.Title));
                        }
                        if (inputs.Count > 0)
                            code.AddRange(string.Join(", ", inputs.ToArray()));
                        else if (isLua)
                            code.AddRange("nil");
                    }
                    else if (pinName == "VALUE_NAME")
                    {
                        PlatoPin pin = node.FindPinByTitle("Name", true);
                        if(pin != null)
                            code.AddRange(string.Format("_{0}", pin.Value));
                    }
                    else if (pinName == "EVENT_NAME")
                    {
                        PlatoPin pin = node.FindPinByTitle("Event", true);
                        if(pin != null)
                            code.AddRange(string.Format("{0}", pin.Value));
                    }
                    else if (pinName == "FUNCTION_NAME")
                    {
                        PlatoPin pin = node.FindPinByTitle("Function", true);
                        code.AddRange(pin.Value as string);
                    }
                    else
                    {
                        // 先从输入引脚开始查找
                        PlatoPin pin = node.FindPinByTitle(pinName, true);
                        if (pin == null)
                        {
                            // 没有找到就查找输出引脚
                            pin = node.FindPinByTitle(pinName, false);
                            if (pin != null)
                            {
                                if (isLua)
                                    code.AddRange(PlatoExportUtil.ExportOutPinByTitleLua(node, pinName));
                                else
                                    code.AddRange(PlatoExportUtil.ExportOutPinByTitleCSharp(node, pinName));
                            }
                            else
                                throw new System.Exception();
                        }
                        else
                        {
                            if (isLua)
                                code.AddRange(PlatoExportUtil.ExportInPinByTitleLua(node, pinName));
                            else
                                code.AddRange(PlatoExportUtil.ExportInPinByTitleCSharp(node, pinName));
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
        catch(Exception e)
        {
            Debug.LogError(string.Format("Format error: [{0}.{1}] '{2}'/nException: {3}", node.Category, node.Title, format, e));
        }
        return string.Empty;
    }

    /// <summary>
    /// 导出输入引脚
    /// </summary>
    /// <param name="title"></param>
    /// <returns></returns>
    public static string ExportInPinByTitleLua(PlatoNode node, string title)
    {
        PlatoPin pin = node.FindPinByTitle(title, true);
        // 如果有前驱，使用前驱的输出
        if (pin.Prevs.Count == 1)
        {
            PlatoPin prev = pin.Prevs[0];
            while (prev.ParentNode.Title == "Reroute")
            {
                prev = prev.Prevs[0];
            }
            return ExportOutPinByTitleLua(prev.ParentNode, prev.Title);
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
    public static string ExportOutPinByTitleLua(PlatoNode node, string title)
    {
        PlatoPin pin = node.FindPinByTitle(title, false);
        if (!string.IsNullOrEmpty(pin.PinFormat))
            return ExportFormat(node, pin.PinFormat);
        else
            return string.Format("self.{0}_{1}_{2}", node.Title, node.ID, title);
    }

    /// <summary>
    /// 导出输入引脚
    /// </summary>
    /// <param name="title"></param>
    /// <returns></returns>
    public static string ExportInPinByTitleCSharp(PlatoNode node, string title)
    {
        PlatoPin pin = node.FindPinByTitle(title, true);
        // 如果有前驱，使用前驱的输出
        if (pin.Prevs.Count == 1)
        {
            PlatoPin prev = pin.Prevs[0];
            while (prev.ParentNode.Title == "Reroute")
            {
                prev = prev.Prevs[0];
            }
            return ExportOutPinByTitleCSharp(prev.ParentNode, prev.Title);
        }
        else
        {
            return pin.ExportToCSharp();
        }
    }

    /// <summary>
    /// 导出输出引脚
    /// </summary>
    /// <param name="title"></param>
    /// <returns></returns>
    public static string ExportOutPinByTitleCSharp(PlatoNode node, string title)
    {
        PlatoPin pin = node.FindPinByTitle(title, false);
        if (!string.IsNullOrEmpty(pin.CSharpPinFormat))
            return ExportFormat(node, pin.CSharpPinFormat, false);
        else
            return string.Format("{0}_{1}_{2}", node.Title, node.ID, title);
    }
}
