using UnityEngine;
using System.Collections;
using System.Collections.Generic;


public class LevelMapData : ScriptableObject
{
    /// <summary>
    /// 计数器仅内部使用
    /// </summary>
    public int ID;

    /// <summary>
    /// 所有怪物数据
    /// </summary>
    public List<LevelMonsterData> monterDatas = new List<LevelMonsterData>();

    /// <summary>
    /// 所有初始化怪物数据
    /// </summary>
    public List<LevelMonsterData> initMonterDatas = new List<LevelMonsterData>();

    /// <summary>
    /// 所有波次的怪物数据
    /// </summary>
    public List<LevelBatchData> batchDatas = new List<LevelBatchData>();

    /// <summary>
    /// 所有路径数据 
    /// </summary>
    public List<LevelPathData> pathDatas = new List<LevelPathData>();

    
    /// <summary>
    /// 所有的道具数据
    /// </summary>
    public List<LevelPropData> propDatas = new List<LevelPropData>();


    /// <summary>
    /// 所有的区域数据
    /// </summary>
    public List<LevelAreaData> areaDatas = new List<LevelAreaData>();

    /// <summary>
    /// 所有门的数据
    /// </summary>
    public List<LevelDoorData> doorDatas = new List<LevelDoorData>();
    
    /// <summary>
    /// 所有出生点的数据
    /// </summary>
    public List<LevelBirthPositionData> birthDatas = new List<LevelBirthPositionData>();

    /// <summary>
    /// 点的数据
    /// </summary>
    public List<LevelPositionData> positionDatas = new List<LevelPositionData>();

    /// <summary>
    /// 场景的数据保存
    /// </summary>
    public List<LevelSceneObjectData> sceneObjectDatas = new List<LevelSceneObjectData>();

    /// <summary>
    /// 模式数据
    /// </summary>
    public LevelModeData modeData;
}





