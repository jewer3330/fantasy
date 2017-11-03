using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEditor;
using System.Collections;

public class ObjectPin : PlatoPin
{
    public override Color GetColor()
    {
        return Color.blue;
    }

    public override void OnDraw()
    {
        if (!IsInput)
            GUILayout.Label(Title, IsInput ? "InPinFont" : "OutPinFont", GUILayout.MinWidth(50.0f), GUILayout.Height(PlatoPin.PinHeight));
        else
            Value = EditorGUILayout.ObjectField(Title, (UnityEngine.Object)Value, typeof(GameObject), true, GUILayout.Height(PlatoPin.PinHeight));
    }

    public override string SaveValue()
    {
        if (Value == null)
        {
            return "nil";
        }
        else
        {
            // 判断是场景对象还是资源对象
            string path = AssetDatabase.GetAssetPath(Value as GameObject);
            if (path.Contains("Assets"))
                return string.Format("'{0}'", path.Replace("Assets/", "").Replace(".prefab", ""));
            else
                return string.Format("'{0}'", PlatoUtil.GetFullName(Value as GameObject));
        }
    }

    public override void LoadValue(object value)
    {
        if (value == null)
        {
            Value = null;
        }
        else
        {
            string objectName = value as string;
            if (objectName.Contains("Resources/"))
            {
                Value = Resources.Load(objectName.Replace("Resources/", ""));
            }
            else
            {
                if (PlatoUtil.DesignLevel == null)
                {
                    foreach (GameObject root in SceneManager.GetActiveScene().GetRootGameObjects())
                    {
                        Transform result = root.transform.Find(objectName);
                        if (result != null)
                            Value = result.gameObject;
                    }
                }
                else
                {
                    Transform result = PlatoUtil.DesignLevel.transform.Find(objectName);
                    if (result != null)
                        Value = result.gameObject;
                    else
                        Value = GameObject.Find(objectName);
                }
            }
        }
    }

    public override string ExportToLua()
    {
        if (Value == null)
        {
            return "''";
        }
        else
        {
            // 判断是场景对象还是资源对象
            string path = AssetDatabase.GetAssetPath(Value as GameObject);
            if (path.Contains("Assets"))
                return string.Format("AssetManager.Instance:Load('{0}')", path.Replace("Assets/", "").Replace(".prefab", ""));
            else
                return string.Format("'{0}'", PlatoUtil.GetFullName(Value as GameObject));
        }
    }

    public override string ExportToCSharp()
    {
        if (Value == null)
        {
            return "null";
        }
        else
        {
            // 判断是场景对象还是资源对象
            string path = AssetDatabase.GetAssetPath(Value as GameObject);
            if (path.Contains("Assets"))
                return string.Format("AssetManager.Instance.Load(\"{0}\")", path.Replace("Assets/", "").Replace(".prefab", ""));
            else
                return string.Format("PlatoUtil.DesignLevel.transform.Find(\"{0}\").gameObject", PlatoUtil.GetFullName(Value as GameObject));
        }
    }

    public override string CppValue(string cpp_node)
    {
        if (Value == null)
        {
            return "nullptr";
        }
        else
        {
            // 判断是场景对象还是资源对象
            string path = AssetDatabase.GetAssetPath(Value as GameObject);
            if (path.Contains("Assets"))
            {
                // Empty for cpp
                return "nullptr";
            }
            else
            {
                GameObject obj = Value as GameObject;

                if (ParentNode.Title == "OnTriggerVolume")
                {
                    BoxCollider box = obj.GetComponent<BoxCollider>();
                    Vector3 center = box.transform.position;
                    Vector3 lt = new Vector3(-0.5f * box.size.x * box.transform.localScale.x, 0.0f, +0.5f * box.size.z * box.transform.localScale.z);
                    Vector3 lb = new Vector3(-0.5f * box.size.x * box.transform.localScale.x, 0.0f, -0.5f * box.size.z * box.transform.localScale.z);
                    Vector3 rt = new Vector3(+0.5f * box.size.x * box.transform.localScale.x, 0.0f, +0.5f * box.size.z * box.transform.localScale.z);
                    Vector3 rb = new Vector3(+0.5f * box.size.x * box.transform.localScale.x, 0.0f, -0.5f * box.size.z * box.transform.localScale.z);
                    lt = box.transform.rotation * lt + center;
                    lb = box.transform.rotation * lb + center;
                    rt = box.transform.rotation * rt + center;
                    rb = box.transform.rotation * rb + center;
                    return string.Format("Pos2D({0:#.00}f, {1:#.00}f), Pos2D({2:#.00}f, {3:#.00}f), Pos2D({4:#.00}f, {5:#.00}f), Pos2D({6:#.00}f, {7:#.00}f), Pos2D({8:#.00}f, {9:#.00}f)", center.x, center.z, lt.x, lt.z, rt.x, rt.z, rb.x, rb.z, lb.x, lb.z);
                }
                else if (ParentNode.Title == "Spawn")
                {
                    Vector3 pos = obj.transform.position;
                    Spawner sp = obj.GetComponent<Spawner>();
                    PlatoPin lvPin = ParentNode.FindPinByTitle("ServerLv", true);
                    return string.Format("Pos2D({0:#.00}f, {1:#.00}f), {2:#.00}f, {3}, {4}", pos.x, pos.z, sp.Radius, sp.MonsterID, (int)lvPin.Value);
                }
                else if (ParentNode.Title == "OnBroken")
                {
                    Vector3 pos = obj.transform.position;
                    return string.Format("Pos2D({0:#.00}f, {1:#.00}f)", pos.x, pos.z);
                }
                else if (ParentNode.Title == "ObjectActive")
                {
                    return string.Format("\"{0}\"", PlatoUtil.GetFullName(obj));
                }
                else if (ParentNode.Title == "ColliderActive")
                {
                    return string.Format("\"{0}\"", PlatoUtil.GetFullName(obj));
                }
                else if (ParentNode.Title == "OnDamageVolume")
                {
                    Vector3 start = obj.transform.position;
                    BoxCollider box = obj.GetComponent<BoxCollider>();
                    DamageVolume volume = obj.GetComponent<DamageVolume>();
                    Vector3 end;
                    if (box.size.x > box.size.z)
                        end = start + obj.transform.right * box.size.x * obj.transform.localScale.x;
                    else
                        end = start + obj.transform.forward * box.size.z * obj.transform.localScale.z;
                    return string.Format("Pos2D({0:#.00}f, {1:#.00}f), Pos2D({2:#.00}f, {3:#.00}f), {4}, {5:#.00}f", start.x, start.z, end.x, end.z, volume.damage, volume.interval);
                }
                else if (ParentNode.Title == "TeleportAll")
                {
                    Vector3 pos = obj.transform.position;
                    return string.Format("Pos2D({0:#.00}f, {1:#.00}f)", pos.x, pos.z);
                }
                else if (ParentNode.Title == "LoopSpawn")
                {
                    Vector3 pos = obj.transform.position;
                    return string.Format("Pos2D({0:#.00}f, {1:#.00}f)", pos.x, pos.z);
                }
                else
                {
                    return "nullptr";
                }
            }
        }
    }

    public override PlatoPin DoClone()
    {
        return new ObjectPin();
    }
}
