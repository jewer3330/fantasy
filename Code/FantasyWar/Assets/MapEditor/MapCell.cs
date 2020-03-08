using UnityEngine;
using System.Collections;
using System.Collections.Generic;
public class MapCell : MonoBehaviour
{
    public MapCellData data = new MapCellData();
    public int steps = int.MaxValue;
    public MapCell prev;

    public MapCellIndicator indicator;

    public void SetData(MapCellData data)
    {
        this.data = data;
    }

    public void SetData(MapCell data)
    {
        SetData(data.data);
    }

    public bool IsSame(MapCell cell)
    {
        return data.x == cell.data.x && data.y == cell.data.y && data.h == cell.data.h;
    }

    public static float Distance(MapCell left, MapCell right)
    {
        if (left && right)
        {
            return Vector3.Distance(left.transform.position, right.transform.position);
        }
        return 0;
    }

    public float Distance(MapCell cell)
    {
        return Distance(this, cell);
    }


    public LevelManager levelManager
    {
        get;set;
    }

    public MapCell left
    {
        get
        {
            if (levelManager == null || data.x == 0)
                return null;
            return levelManager.GetData(data.x - 1, data.y);
        }
    }

    public MapCell right
    {
        get
        {
            if (levelManager == null || data.x == levelManager.mapWidth - 1)
                return null;
            return levelManager.GetData(data.x + 1, data.y);
        }
    }


    public MapCell top
    {
        get
        {
            if (levelManager == null || data.y == levelManager.mapHeight - 1)
                return null;
            return levelManager.GetData(data.x , data.y + 1);
        }
    }

    public MapCell bottom
    {
        get
        {
            if (levelManager == null || data.y == 0)
                return null;
            return levelManager.GetData(data.x, data.y - 1);
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

    private void OnDrawGizmos()
    {
        Gizmos.color = Color.red;
        if (prev)
        {
            var end = prev.transform.position + 2 * Vector3.up;
            var start = transform.position + 2 * Vector3.up;
            var fwd = (end - start).normalized;
            Gizmos.DrawLine(start, end);
            Gizmos.DrawLine(start, start + Quaternion.Euler(0,45,0)  * fwd * 0.2f);
            Gizmos.DrawLine(start, start + Quaternion.Euler(0,-45,0) * fwd * 0.2f);
        }
    }

}
