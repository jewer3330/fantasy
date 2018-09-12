using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using SuperBoBo;

public class LevelManager : MonoBehaviour
{
    
    public MapData mapData;
    public int mapWidth;
    public int mapHeight;

    public List<MapCell> cells = new List<MapCell>();
    public List<MapCell> startPositions = new List<MapCell>();
    public Player player;
    public PlayerCamera playerCamera;
    public string assetPath = "Map/level1";


    public Dictionary<int, MapCell> caches = new Dictionary<int, MapCell>();
    public List<MapCell> canMoveArea = new List<MapCell>();

    public MapCellIndicator select;

    public enum State
    {
        Idle,
        Move,
        DrawPath,
        SelectPath,
    }

    public State state = State.Idle;

    public MapCell GetData(int x, int y)
    {
        int key = x + y * (mapWidth);
        MapCell data = null;
        if (!caches.TryGetValue(key, out data))
        {
            data = cells.Find((obj) =>
            {
                if (obj.x == x && obj.y == y)
                    return true;
                return false;
            });
            caches.Add(key, data);
        }
        return data;
    }

    // Use this for initialization
    void Start ()
    {
        mapData = ResManager.Load(assetPath) as MapData;
        //string data = ta.text;
        //mapData = LitJson.JsonMapper.ToObject<MapData>(data);
        GenMap();
        GenActor(1);
        PrepareCamera();
    }

    void GenMap()
    {
        mapWidth = mapData.mapWidth;
        mapHeight = mapData.mapHeight;

        for (int i = 0; i < mapData.cells.Count; i++)
        {
            GameObject go = GameObject.Instantiate(ResManager.Load(mapData.cells[i].res.Replace("Assets/Resources/",string.Empty))) as GameObject;
            go.transform.position = new Vector3(mapData.cells[i].x, mapData.cells[i].h, mapData.cells[i].y);
            MapCell cell = go.AddComponent<MapCell>();
            cell.SetData(mapData.cells[i]);
            cell.levelManager = this;
            if (cell.start)
            {
                startPositions.Add(cell);
            }

            cells.Add(cell);
        }
    }

    void GenActor(int id)
    {
        var data = Table.Character.Get(id);
        GameObject go = Instantiate( ResManager.Load("Charactors/"+ data.Res)) as GameObject;

        player = go.AddComponent<Player>();
        player.data = data;

        player.transform.position = new Vector3(startPositions[0].x,  startPositions[0].h, startPositions[0].y) + Vector3.up;

        state = State.Move;

    }


    void PrepareCamera()
    {
        playerCamera = Camera.main.GetComponent<PlayerCamera>();
        playerCamera.player = player;
    }
	// Update is called once per frame
	void Update ()
    {
	    switch(state)
        {
            case State.Move:
                canMoveArea.Clear();
                startPositions[0].G = 0;
                FindCanMoveArea(startPositions[0], player.data.MV, ref canMoveArea);
                state = State.DrawPath;
                break;
            case State.DrawPath:
                foreach(var k in canMoveArea)
                {
                    GameObject go = Instantiate<GameObject>(ResManager.Load("CanMove") as GameObject);
                    var indicator = go.GetComponent<MapCellIndicator>();
                    indicator.mapCell = k;
                    indicator.levelManager = this;
                    go.transform.position = new Vector3(k.x, k.h, k.y) + Vector3.up * 1.1f;
                }
                state = State.SelectPath;
                break;
            case State.SelectPath:
                if(select != null)
                    select.SetHighLight(true);
                break;
                
        }
	}




    void FindCanMoveArea(MapCell start,int step,ref List<MapCell> cells)
    {
        List<MapCell> open = new List<MapCell>();
        open.Add(start);
        int count = 0;
        while(open.Count > 0)
        {
            count++;
            if (count > 10000) break;//break endless loop 
            var select = open[0];
            open.RemoveAt(0);

            if (select.G > step)
                continue;
            if(!cells.Contains(select))
                cells.Add(select);
            
            var closeCells = select.GetCloseCells();
            foreach(var k in closeCells)
            {
                
                if(open.Contains(k))
                {
                    int G = select.G + k.cost;
                    if(G < k.G)
                        k.G = G;
                    //Debug.LogWarning("(" + k.x + " " + k.y + ") " + k.G);

                }
                else
                {
                    if (k.G == 0)
                    {
                        k.G = select.G + k.cost;
                    }
                    else
                    {
                        int G = select.G + k.cost;
                        if (G < k.G)
                            k.G = G;
                    }
                    //Debug.Log("(" + k.x + " " + k.y + ") " + k.G);
                    if (cells.Contains(k))
                        continue;
                    open.Add(k);
                }
            }
        }
    }

    //猫会重复以下步骤来找到最短路径：
    //将方块添加到open列表中，该列表有最小的和值。且将这个方块称为S吧。
    //将S从open列表移除，然后添加S到closed列表中。
    //对于与S相邻的每一块可通行的方块T：
    //如果T在closed列表中：不管它。
    //如果T不在open列表中：添加它然后计算出它的和值。
    //如果T已经在open列表中：当我们使用当前生成的路径到达那里时，检查F 和值是否更小。如果是，更新它的和值和它的前继。
    void AStar(MapCell start)
    {
        List<MapCell> closed = new List<MapCell>();
        List<MapCell> open = new List<MapCell>();
        open.Add(start);
        do
        {
            MapCell s = open[0];
            foreach (var k in open)
            {
                int f = s.G + s.H;
                if (f > k.G + k.H)
                {
                    s = k;
                }
            }
            open.Remove(s);
            closed.Add(s);

            if (closed.Contains(start))
                break;

            var closeCells = s.GetCloseCells();

            foreach (var k in closeCells)
            {
                if (closed.Contains(k))
                {
                    continue;
                }

                if (!open.Contains(k))
                {
                    open.Add(k);
                    k.G = 0;
                    k.H = 0;
                }
                else
                {


                }
            }
        } while (open.Count != 0);
    }
}
