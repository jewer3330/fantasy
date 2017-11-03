using UnityEngine;
using System.Collections;



public class LevelObjectBase : MonoBehaviour
{



    protected LevelBaseData data;
    protected LevelBaseData dataOld;


    public LevelBaseData GetDataOld()
    {
        return dataOld;
    }

    public void SetDataOld(LevelBaseData b)
    {
        this.dataOld = b;
    }




    public virtual LevelBaseData GetData()
    {
        return data;
    }

    public virtual void SetData(LevelBaseData data)
    {
        this.data = data;

    }

    public virtual string GetGizmoName()
    {
        return data.name + " $" + data.editorID;
    }

    public static LevelBaseData[] GetAllBaseDatas()
    {
        BetterList<LevelBaseData> datas = new BetterList<LevelBaseData>();

        LevelObjectBase[] objs = GameObject.FindObjectsOfType<LevelObjectBase>();
        foreach (LevelObjectBase obj in objs)
        {
            datas.Add(obj.GetData());
        }
        return datas.ToArray();
    }
}

