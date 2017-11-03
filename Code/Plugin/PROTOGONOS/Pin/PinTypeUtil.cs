using UnityEngine;
using UnityEngine.UI;
using System;
using System.Collections;
using System.Collections.Generic;

public static class PinTypeUtil
{
    /// <summary>特殊默认值</summary>
    private static readonly Dictionary<Type, object> DefaultValues = new Dictionary<Type, object>()
    {
        { typeof(bool), false },
        { typeof(int), 0 },
        { typeof(float), 0.0f },
        { typeof(string), "" },
        { typeof(GameObject), null },
        { typeof(ulong), "" },
        { typeof(ulong[]), "" },
        { typeof(int[]), "" },
        { typeof(float[]), "" },
        { typeof(Dropdown), "" },
    };

    public static readonly Dictionary<Type, string> CppTypes = new Dictionary<Type, string>()
    {
        { typeof(bool), "bool" },
        { typeof(bool[]), "Bools" },
        { typeof(int), "int32_t" },
        { typeof(int[]), "INT32s" },
        { typeof(float), "float" },
        { typeof(float[]), "Floats" },
        { typeof(ulong), "uint64_t" },
        { typeof(ulong[]), "UINT64s" },
        { typeof(string), "std::string" },
        { typeof(string[]), "Strings" },
        { typeof(Dropdown), "int32_t" },
        { typeof(Dictionary<Int32, Int32>), "IIMap" },
        { typeof(Dictionary<Int32, float>), "IFMap" },
        { typeof(Dictionary<UInt64, UInt64>), "UI64Map" },
    };

    private static readonly Dictionary<Type, string> CppVectorTypes = new Dictionary<Type, string>()
    {
        { typeof(bool), "Bools" },
        { typeof(int), "INT32s" },
        { typeof(float), "Floats" },
        { typeof(ulong), "UINT64s" },
        { typeof(string), "Strings" },
    };

    public static readonly Dictionary<Type, string> CSharpTypes = new Dictionary<Type, string>()
    {
        { typeof(GameObject), "GameObject" },
        { typeof(bool), "bool" },
        { typeof(bool[]), "List<bool>" },
        { typeof(int), "int" },
        { typeof(int[]), "List<int>" },
        { typeof(float), "float" },
        { typeof(float[]), "List<float>" },
        { typeof(ulong), "ulong" },
        { typeof(ulong[]), "List<ulong>" },
        { typeof(string), "string" },
        { typeof(string[]), "List<string>" },
        { typeof(Dropdown), "Enum" },
        { typeof(Dictionary<int, int>), "Dictionary<int, int>" },
        { typeof(Dictionary<int, float>), "Dictionary<int, float>" },
        { typeof(Dictionary<ulong, ulong>), "Dictionary<ulong, ulong>" },
    };

    private static readonly Dictionary<Type, string> CSharpVectorTypes = new Dictionary<Type, string>()
    {
        { typeof(bool), "bool[]" },
        { typeof(int), "int[]" },
        { typeof(float), "float[]" },
        { typeof(ulong), "ulong[]" },
        { typeof(string), "string[]" },
    };

    /// <summary>引脚是否为引用类型</summary>
    public static bool IsRefType(PlatoPin pin)
    {
        if (pin.Type == typeof(bool[]) ||
            pin.Type == typeof(int[]) ||
            pin.Type == typeof(float[]) ||
            pin.Type == typeof(ulong[]) ||
            pin.Type == typeof(string[]) ||
            pin.Type == typeof(Dictionary<int, int>) ||
            pin.Type == typeof(Dictionary<int, float>) ||
            pin.Type == typeof(Dictionary<ulong, ulong>))
            return true;
        return false;
    }

    /// <summary>引脚是否为值类型</summary>
    public static bool IsValue(PlatoPin pin)
    {
        if (pin.Type == null || pin.Type == typeof(Button))
            return false;
        return true;
    }

    /// <summary>引脚是否为函数类型</summary>
    public static bool IsExec(PlatoPin pin)
    {
        return pin.Type == null;
    }

    /// <summary>引脚是否为UI类型</summary>
    public static bool IsUI(PlatoPin pin)
    {
        return pin.Type == typeof(Button) || pin.Type == typeof(Dropdown);
    }

    /// <summary>
    /// CPP引脚类型
    /// </summary>
    /// <param name="type">类型名字符串</param>
    /// <returns></returns>
	public static string GetCppType(System.Type type)
	{
        string result;
        if (CppTypes.TryGetValue(type, out result))
            return result;
        throw new System.Exception("Unknown c++ type: " + type.ToString());
	}

    /// <summary>
    /// CPP引脚数组类型
    /// </summary>
    /// <param name="type">类型名字符串</param>
    /// <returns></returns>
	public static string GetCppVectorType(System.Type type)
	{
        string result;
        if (CppVectorTypes.TryGetValue(type, out result))
            return result;
        throw new Exception("Unknown c++ vector type: " + type.ToString());
	}

    /// <summary>
    /// C#引脚类型
    /// </summary>
    /// <param name="type">类型名字符串</param>
    /// <returns></returns>
	public static string GetCSharpType(System.Type type)
	{
        string result;
        if (CSharpTypes.TryGetValue(type, out result))
            return result;
        throw new System.Exception("Unknown c# type: " + type.ToString());
	}

    /// <summary>
    /// C#引脚数组类型
    /// </summary>
    /// <param name="type">类型名字符串</param>
    /// <returns></returns>
	public static string GetCSharpVectorType(System.Type type)
	{
        string result;
        if (CSharpVectorTypes.TryGetValue(type, out result))
            return result;
        throw new Exception("Unknown c# vector type: " + type.ToString());
	}

    /// <summary>
    /// 设置引脚默认值
    /// </summary>
    /// <param name="pin"></param>
    public static void SetDefault(PlatoPin pin)
    {
        if (pin.Type == null)
            return;

        object value;
        if (DefaultValues.TryGetValue(pin.Type, out value))
            pin.Value = value;
    }

    public static bool IsDefault(PlatoPin pin)
    {
        object value;
        if (DefaultValues.TryGetValue(pin.Type, out value))
            return pin.Value.Equals(value);
        return true;
    }

    public static string GetDefault(PlatoPin pin)
    {
        if (pin.Type == typeof(bool))
            return "false";
        else if (pin.Type == typeof(string))
            return "string.Empty";
        else if (pin.Type.IsPrimitive)
            return "0";
        else
            return "null";
    }
}
