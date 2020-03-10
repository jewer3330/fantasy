using System;
using UnityEngine;

namespace NodeCanvas.Framework
{
    abstract public partial class Variable
    {
        public static string GetTypeName(Type valueType)
        {
            string varTypeName = "null";
            if (valueType == typeof(float) || valueType == typeof(Single))
            {
                varTypeName = "F";
            }
            else if (valueType == typeof(short) || valueType == typeof(Int16))
            {
                varTypeName = "I16";
            }
            else if (valueType == typeof(ushort) || valueType == typeof(UInt16))
            {
                varTypeName = "UI16";
            }
            else if (valueType == typeof(int) || valueType == typeof(Int32))
            {
                varTypeName = "I";

            }
            else if (valueType == typeof(uint) || valueType == typeof(UInt32))
            {
                varTypeName = "UI";
            }
            else if (valueType == typeof(ulong) || valueType == typeof(UInt64))
            {
                varTypeName = "UI64";
            }
            else if (valueType == typeof(long) || valueType == typeof(Int64))
            {
                varTypeName = "I64";
            }
            else if (valueType == typeof(string) || valueType == typeof(String))
            {
                varTypeName = "S";
            }
            else if (valueType == typeof(Vector3))
            {
                varTypeName = "V";
            }
            else if (valueType == typeof(bool) || valueType == typeof(Boolean))
            {
                varTypeName = "B";
            }
            else if (valueType.IsEnum)
            {
                varTypeName = "I";
            }
            else if (valueType == typeof(SceneObj) ||
                valueType.IsSubclassOf(typeof(SceneObj)) ||
                valueType == typeof(GameObject) ||
                valueType.IsSubclassOf(typeof(GameObject)))
            {
                varTypeName = "ActorID";
            }
            return varTypeName;
        }
    }
    public partial class Variable<T>
    {
        public override bool ToXmlElement(System.Xml.XmlElement varElement)
        {
            string varTypeName = GetTypeName(varType);
            string varValueString = Convert.ToString(value);
            if (varType == typeof(SceneObj) || varType.IsSubclassOf(typeof(SceneObj)))
            {
                SceneObj sceneObj = value as SceneObj;
                if (sceneObj != null)
                {
                    varValueString = Convert.ToString(sceneObj.id);
                }
                else
                {
                    varValueString = "0";
                }
            }
            else if (varType == typeof(GameObject) || varType.IsSubclassOf(typeof(GameObject)))
            {
                if (value != null)
                {
                    SceneObj sceneObj = (value as GameObject).GetComponent<SceneObj>();
                    if (sceneObj != null)
                    {
                        varValueString = Convert.ToString(sceneObj.id);
                    }
                }
                else
                {
                    varValueString = "0";
                }
            }
            varElement.SetAttribute("name", name);
            varElement.SetAttribute("type", varTypeName);
            varElement.SetAttribute("value", varValueString);
            return true;
        }
    }
}
