using UnityEngine;
using System.Collections;
using System.Collections.Generic;





public class MapCell : MonoBehaviour
{
    public int x;
    public int y;
    public int h;
    public int id;
    public string res;
    public bool start;
    public int cost;

    public int G;
    public int H;

    public void SetData(MapCellData data)
    {
        x = data.x;
        y = data.y;
        h = data.h;
        id = data.id;
        res = data.res;
        start = data.start;
        cost = data.cost;
    }

    public void SetData(MapCell data)
    {
        x = data.x;
        y = data.y;
        h = data.h;
        id = data.id;
        res = data.res;
        start = data.start;
        cost = data.cost;
    }

    public LevelManager levelManager
    {
        get;set;
    }

    public MapCell left
    {
        get
        {
            if (levelManager == null || x == 0)
                return null;
            return levelManager.GetData(x - 1, y);
        }
    }

    public MapCell right
    {
        get
        {
            if (levelManager == null || x == levelManager.mapWidth - 1)
                return null;
            return levelManager.GetData(x + 1, y);
        }
    }


    public MapCell top
    {
        get
        {
            if (levelManager == null || y == levelManager.mapHeight - 1)
                return null;
            return levelManager.GetData(x , y + 1);
        }
    }

    public MapCell bottom
    {
        get
        {
            if (levelManager == null || y == 0)
                return null;
            return levelManager.GetData(x, y - 1);
        }
    }

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    public List<MapCell> GetCloseCells()
    {
        List<MapCell> cells = new List<MapCell>();
        if(left != null)
        {
            cells.Add(left);
        }
        if(right != null)
        {
            cells.Add(right);
        }
        if(top != null)
        {
            cells.Add(top);
        }
        if(bottom != null)
        {
            cells.Add(bottom);
        }

        return cells;
    }
}
