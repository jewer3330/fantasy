using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;

public class LevelChooseWindow
{


    public static LevelObjectBase ObjectField(LevelObjectBase obj, System.Type type, List<LevelObjectBase> excepts = null)
    {

        List<ObjectChooseInfo> infos = new List<ObjectChooseInfo>();
        LevelObjectBase selectObj = null;
        EditorGUILayout.BeginHorizontal();

        infos.Add(new ObjectChooseInfo("None", null));


        Object[] objs = GameObject.FindObjectsOfType(type);

        foreach (var k in objs)
        {
            if (excepts != null && excepts.Count != 0)
            {
                if (!excepts.Contains((LevelObjectBase)k))
                {
                    infos.Add(new ObjectChooseInfo(k.name, k));
                }
            }
            else
            {
                infos.Add(new ObjectChooseInfo(k.name, k));
            }
        }

        List<string> ret = new List<string>();

        foreach (var k in infos)
        {
            ret.Add(k.name);
        }
        int select = 0;

        for (int i = 0; i < infos.Count; i++)
        {
            if (obj == infos[i].obj)
            {
                select = i;
            }
        }

        select = EditorGUILayout.Popup(select, ret.ToArray());
        if (select >= 0 && select < infos.Count && infos[select].obj)
            selectObj = (LevelObjectBase)infos[select].obj;


        EditorGUILayout.ObjectField(selectObj, type, true);
        EditorGUILayout.EndHorizontal();
        return selectObj;

    }

    public class ObjectChooseInfo
    {
        public string name;
        public Object obj;

        public ObjectChooseInfo(string name, Object ob)
        {
            this.name = name;
            this.obj = ob;
        }
    }

}
