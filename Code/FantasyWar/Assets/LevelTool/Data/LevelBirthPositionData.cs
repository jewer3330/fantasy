using UnityEngine;
using System.Collections;

[System.Serializable]
public class LevelBirthPositionData : LevelBaseData
{
    public int camp;


    public override void Save(LevelMapData data)
    {
        data.birthDatas.Add(this);
    }


}
