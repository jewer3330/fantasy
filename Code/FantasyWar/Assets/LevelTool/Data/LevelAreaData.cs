using UnityEngine;
using System.Collections;
using System.Collections.Generic;

/// <summary>
/// 区域数据
/// </summary>
[System.Serializable]
public class LevelAreaData : LevelBaseData
{
    public enum Type
    {
        Normal = 1,
        Defend = 2,
        Base = 3,
        FlagPoint = 4
        //Trap = 4,
    }
    public int typeSelect = 0;
    public Type type = Type.Normal;
    public int radius = 10;
    public bool isEnd = false;

    public int priority;

    public int comp;

    public int trapSelect;

    public int trapType;




    [System.Obsolete]
    public int m_teamID = -1;
    [System.Obsolete]
    public string m_meshName;
    /// <summary>
    /// 链接的区域
    /// </summary>
    public List<LevelAreaData> nextAreas = new List<LevelAreaData>();


    [System.Serializable]
    public class NextArea
    {
        public int nextAreaID;
        public int weight;

        public NextArea(int id, int w)
        {
            this.nextAreaID = id;
            this.weight = w;
        }

    }

    public NextArea[] GetNextAreas()
    {
        List<NextArea> areas = new List<NextArea>();
        foreach (var k in nextAreas)
        {
            areas.Add(new NextArea(k.editorID, k.priority));
        }

        return areas.ToArray();
    }


    public override void Save(LevelMapData data)
    {
        data.areaDatas.Add(this);
    }

    //public override void Save(Level.LevelData data)
    //{
    //    data.m_listFoundation.Add(DatasAdapter.ChangeToLevelFoundation(this));
    //}

    public override void Copy(LevelBaseData b)
    {
        base.Copy(b);
        LevelAreaData d = b as LevelAreaData;
        this.type = d.type;
        this.radius = d.radius;
        this.isEnd = d.isEnd;
    }

}

