using UnityEngine;
using System.Collections;

[System.Serializable]
public class LevelMonsterData : LevelBaseData
{

    /// <summary>
    /// 组内排序
    /// </summary>
    public int groupSequence;

    /// <summary>
    /// 组的ID
    /// </summary>
    public int groupID;

    //public int groupOrderID;
    //public int level;
    //public int camp;

    public int AIID = 1;

    public int mainAIID = 0;

    public static int Gap = 100;
    public int subAIID = 0;


    [System.Obsolete]
    /// <summary>
    /// 原来客户端的数据
    /// </summary>
    public string aiID = "Normal";

    [System.Obsolete]
    /// <summary>
    /// 用来索引AIID
    /// </summary>
    public int aiIndex = 2;

    //public float delayBorn;
    //public byte monsterType;


    /// <summary>
    /// 寻路的ID
    /// </summary>
    public int pathID = -1;

    public LevelPath selectPath = null;

    
    [System.Obsolete]
    /// <summary>
    /// 原来客户端用来组队的ID
    /// </summary>
    public int teamID = -1;

    [System.Obsolete]
    /// <summary>
    /// 用来索引TeamID
    /// </summary>
    public int teamIndex = 0;

    ///no need
    //public int dropID;

    public override void Save(LevelMapData data)
    {
        data.monterDatas.Add(this);
    }

    public override LevelBaseData Clone()
    {
        return (LevelMonsterData)this.MemberwiseClone();
    }

    public override bool Equals(object o)
    {
        if (o == null) return false;
        LevelMonsterData obj = o as LevelMonsterData;
        return (this.ID == obj.ID
            && this.name == obj.name
            && this.pos == obj.pos
            //&& this.triggleParam == obj.triggleParam
            //&& this.triggleType == obj.triggleType
            //&& this.monsterType == obj.monsterType
            //&& this.groupOrderID == obj.groupOrderID
            && this.aiID == obj.aiID
            //&& this.delayBorn == obj.delayBorn
            && this.groupSequence == obj.groupSequence
            //&& this.dropID == obj.dropID
            && this.dir == obj.dir
            && this.pathID == obj.pathID
            );
    }


    public LevelMonsterData()
    {
        isVisible = true;
    }




    public override void Copy(LevelBaseData b)
    {
        base.Copy(b);
        LevelMonsterData obj = b as LevelMonsterData;
        this.pathID = obj.pathID;
        //this.dropID = obj.dropID;
        this.groupSequence = obj.groupSequence;
        this.aiID = obj.aiID;
        this.ID = obj.ID;
        //this.camp = obj.camp;
        this.name = obj.name;
        //this.delayBorn = obj.delayBorn;
        this.dir = obj.dir;
        this.pos = obj.pos;
        this.scale = obj.scale;
    }
}

