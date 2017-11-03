using UnityEngine;
using System.Collections;
using System.Collections.Generic;

[System.Serializable]
public class LevelModeData : LevelBaseData
{

    public MainConditon condition1Star = new MainConditon();

    public int conditionIndex2Star;
    public List<Condition> condition2Star = new List<Condition>();
    public int conditionIndex3Star;
    public List<Condition> condition3Star = new List<Condition>();
    public override void Save(LevelMapData data)
    {
        condition1Star.selectMonsterDatas.Clear();
        foreach (var k in condition1Star.selectMonsters)
        {
            condition1Star.selectMonsterDatas.Add((LevelMonsterData)k.GetData());
        }
       
        data.modeData = (LevelModeData)this.Clone();
    }

    [System.Serializable]
    public class Condition
    {
        public int type;
        public int param;
    }

    [System.Serializable]
    public class MainConditon : Condition
    {
      

        public int conditionType;

        public bool isKillMonsters;

        public int selectIndex;

        public List<LevelMonster> selectMonsters = new List<LevelMonster>();

        public LevelMonster selectMonster;

        public List<LevelMonsterData> selectMonsterDatas = new List<LevelMonsterData>();

        public float time;
    }

   
}
