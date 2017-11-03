using UnityEngine;
using System.Collections;
using System.Collections.Generic;



[System.Serializable]
public class TriggerCondition
{
    public enum Type
    { 
        None = 0,
        BatchTimeStart,
        BatchTimeInterval,
        EventTimeInterval,
        KillMonster,
        KillGroup,
        MoveToArea = 6
    }

    public Type type;

    /// <summary>
    /// type 的索引
    /// </summary>
    public int typeIdx;


    public int interval;
    public int targetID;
    //public int areaId;
    public Vector3 center;
    public int radius;

    /// <summary>
    /// 编辑器用数据Extra
    /// </summary>
    public LevelMonster selectMonster;
    


    /// <summary>
    /// 编辑器用组数据Extra
    /// </summary>
    public LevelBatch selectGroup;

    /// <summary>
    /// 编辑器用组数据Extra
    /// </summary>
    public LevelArea selectArea;

    /// <summary>
    /// 编辑器用组数据Extra
    /// </summary>
    public int areaID;
}
[System.Serializable]
public class TriggerAction
{ 
    public enum Type
    {
        None = 0,
        SpawnMonster,
        SpawnBatchMessage,
        SpawnBossMessage,

    }
    public Type type;

    /// <summary>
    /// type 的索引器
    /// </summary>
    public int typeIdx;

    public int editorID;

    /// <summary>
    /// editor extra info
    /// </summary>
    public LevelMonster selectMonster;




    /// <summary>
    /// 触发消息ID
    /// </summary>
    public int messageID;

    /// <summary>
    /// 第几波来袭的参数
    /// </summary>
    public int param;
}
[System.Serializable]
public class TriggerEvent
{
    public TriggerCondition cond = new TriggerCondition();
    public TriggerAction    action = new TriggerAction();
    public int sort;
    public bool toggle = true;
    
}


/// <summary>
/// 一批怪物的数据
/// </summary>
[System.Serializable]
public class LevelBatchData : LevelBaseData
{
    //public float timeStart = -1;
    public int index;

    public int loopCount = 0;
    public int loopInterval = 0;

    public int dropID;

    public List<TriggerEvent> events = new List<TriggerEvent>();

    [System.Obsolete]
    /// <summary>
    /// 批次上的怪物
    /// </summary>
    public List<LevelMonsterData> monsters = new List<LevelMonsterData>();

    public override void Copy(LevelBaseData b)
    {
        this.events = (b as LevelBatchData).events;
        this.monsters = (b as LevelBatchData).monsters;
    }
    public override void Save(LevelMapData data)
    {
        data.batchDatas.Add(this);
    }


}


