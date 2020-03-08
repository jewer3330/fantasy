using UnityEngine;
using System.Collections.Generic;
[System.Serializable]
public class MapCellData
{
    public int x;
    public int y;
    public int h;
    public int id;
    public string res;
    public bool start;
    public int cost = 1;

    public int ActorID = 0;

    public enum PlayerType
    {
        Player,
        Npc,
    }

    public PlayerType playerType;

    public MapCellData()
    {

    }

    public MapCellData(MapCell mo)
    {
        this.x = mo.data.x;
        this.y = mo.data.y;
        this.h = mo.data.h;
        this.id = mo.data.id;
        this.res = mo.data.res;
        this.start = mo.data.start;
        this.cost = mo.data.cost;
        this.ActorID = mo.data.ActorID;
        this.playerType = mo.data.playerType;

    }
}



public class MapData : ScriptableObject
{
    public List<MapCellData> cells = new List<MapCellData>();
    public int mapWidth;
    public int mapHeight;

   
}
