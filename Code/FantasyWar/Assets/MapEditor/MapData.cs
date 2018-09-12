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

    public MapCellData()
    {

    }

    public MapCellData(MapCell mo)
    {
        this.x = mo.x;
        this.y = mo.y;
        this.h = mo.h;
        this.id = mo.id;
        this.res = mo.res;
        this.start = mo.start;
        this.cost = mo.cost;
    }
}



public class MapData : ScriptableObject
{
    public List<MapCellData> cells = new List<MapCellData>();
    public int mapWidth;
    public int mapHeight;

   
}
