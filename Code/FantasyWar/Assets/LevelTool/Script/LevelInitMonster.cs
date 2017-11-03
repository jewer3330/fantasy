using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class LevelInitMonster : MonoBehaviour {

    private static LevelInitMonster instance;

    public static LevelInitMonster Instance
    {
        get
        {
            if (!instance)
            {
                GameObject go = new GameObject("LevelInitMonster");
                instance = go.AddComponent<LevelInitMonster>();
            }

            return instance;
        }
    }

    public void Save(LevelMapData mapData)
    { 
        //foreach(var key in monsters)
        //{
        //    mapData.initMonterDatas.Add(key.GetData() as LevelMonsterData);
        //} 
    }

  

    void OnDestroy()
    {
        instance = null;
    }

    public List<LevelMonster> monsters = new List<LevelMonster>();

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
