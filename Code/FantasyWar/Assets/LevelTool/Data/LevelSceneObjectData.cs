using UnityEngine;
using System.Collections;
using System.Collections.Generic;

[System.Serializable]
public class LevelSceneObjectData : LevelBaseData 
{
    /// <summary>
    /// 编辑器选择
    /// </summary>
    public LevelPath selectPath;

    /// <summary>
    /// 存储数据
    /// </summary>
    public LevelPathData pathData;

    /// <summary>
    /// 存储数据
    /// </summary>
    public List<LevelPositionData> transmitDatas = new List<LevelPositionData>();

    public enum Type
    { 
        None = 0,
        Tornado,
        Pail,
        Quicksand,
        HiddenArea = 4,
    }

    public Type type;
    public int typeSelect;


    public int radius;
    public override void Save(LevelMapData data)
    {
        data.sceneObjectDatas.Add(this);
    }
}
