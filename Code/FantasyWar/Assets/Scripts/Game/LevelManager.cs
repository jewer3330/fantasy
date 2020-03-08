using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using SuperBoBo;

public class EasyPool<T>
{
    private Queue<T> caches = new Queue<T>();
    private System.Func<T> action;
    public void Init(System.Func<T> gen)
    {
        action = gen;
    }

    public T Get()
    {
        T ret = default(T);
        if (caches.Count > 0)
        {
            ret = caches.Dequeue();
        }
        else
        {
            ret = action();
        }
        return ret;
    }

    public void Return(T t)
    {
        if (t != null && !caches.Contains(t))
        {
            caches.Enqueue(t);
        }
    }

}

public class LevelManager : MonoBehaviour
{


    private GameObject pool;
    private GameObject mapRoot;

    EasyPool<MapCellIndicator> indicators = new EasyPool<MapCellIndicator>();

    public MapData mapData;
    public int mapWidth;
    public int mapHeight;

    public List<MapCell> cells = new List<MapCell>();
    public List<MapCell> startPositions = new List<MapCell>();
    public MapCell start;
    public Player player;
    public PlayerCamera playerCamera;
    public string assetPath = "Map/level1";


    public Dictionary<int, MapCell> caches = new Dictionary<int, MapCell>();
    public Dictionary<int, Player> all = new Dictionary<int, Player>();
    [System.NonSerialized]
    public List<MapCell> canMoveArea = new List<MapCell>();

    public List<MapCell> way = new List<MapCell>();

    public MapCellIndicator select;

    public enum State
    {
        Idle,
        Area,
        DrawPath,
        Select,
        FindWay,
        WalkTo,
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
                if (obj.data.x == x && obj.data.y == y)
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
        indicators.Init(() =>
        {
            GameObject go = Instantiate<GameObject>(ResManager.Load("CanMove") as GameObject);
            var indicator = go.GetComponent<MapCellIndicator>();
            return indicator;
        });
        //string data = ta.text;
        //mapData = LitJson.JsonMapper.ToObject<MapData>(data);
        pool = new GameObject("pool");
        mapRoot = new GameObject("mapRoot");
        
        GenMap();

        GenActors();
        PrepareCamera();
        ShowTurnStart(Language.TAKETURNS_THEY_START);
    }

    void GenActors()
    {
        foreach (var k in startPositions)
        {
            GenActor(k);
        }
    }

    void ShowTurnStart(string title)
    {
        ResManager.LoadAsync("UI/UITaketurns", (go) =>
        {
            var ins = Instantiate(go);
            UIManager.Instance.AddWidget(ins as GameObject);
            SuperBoBo.EventManager.Instance.FireEvent(UITaketurns.ChangeName, title);
        });
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
            if (cell.data.start)
            {
                startPositions.Add(cell);
            }
            go.transform.parent = mapRoot.transform;
            cells.Add(cell);
        }
    }

    void GenActor(MapCell position)
    {
        if (position.data.ActorID == 0)
        {
            Debug.LogErrorFormat("({0},{1}) start position but ActorID 0", position.data.x, position.data.y);
            return;
        }
        var data = Table.Character.Get(position.data.ActorID);
        GameObject go = Instantiate( ResManager.Load("Charactors/"+ data.Res)) as GameObject;
        if (position.data.playerType == MapCellData.PlayerType.Player)
            player = go.AddComponent<Player>();
        else
            player = go.AddComponent<NpcPlayer>();
        player.data = data;
        player.levelManager = this;
        start = position;
        player.transform.position = new Vector3(start.data.x, start.data.h, start.data.y) + Vector3.up;

        state = State.Area;
        player.gameObject.AddComponent<AnimationManager>();
        all.Add(player.GetInstanceID(),player);
    }


    void PrepareCamera()
    {
        playerCamera = Camera.main.GetComponent<PlayerCamera>();
        playerCamera.player = player;
    }

    public void ResetState(MapCell at)
    {
        state = State.Area;
        foreach (var k in canMoveArea)
        {
            k.indicator.gameObject.SetActive(false);
            k.steps = int.MaxValue;
            k.prev = null;
            indicators.Return(k.indicator);
        }
        select.SetHighLight(false);
        select = null;
        start = at;
    }
    // Update is called once per frame
    void Update ()
    {
	    switch(state)
        {
            case State.Area:
                canMoveArea.Clear();
                FindCanMoveArea(start, player.data.MV, ref canMoveArea);
                state = State.DrawPath;
                break;
            case State.DrawPath:
                foreach(var k in canMoveArea)
                {
                    var indicator = indicators.Get();
                    indicator.gameObject.SetActive(true);
                    indicator.mapCell = k;
                    indicator.levelManager = this;
                    indicator.transform.position = new Vector3(k.data.x, k.data.h, k.data.y) + Vector3.up * 1.01f;
                    k.indicator = indicator;
                    indicator.transform.parent = pool.transform;
                }
                state = State.Select;
                break;
            case State.Select:
                if (select != null)
                {
                    select.SetHighLight(true);
                    state = State.FindWay;
                }
                break;
            case State.FindWay:
                way.Clear();
                var current = select.mapCell;
                while (current.prev)
                {
                    way.Add(current);
                    current = current.prev;
                }
                way.Reverse();
                state = State.WalkTo;
                break;
            case State.WalkTo:
                player.Move(way);
                state = State.Idle;
                
                break;
                
        }
	}




    void FindCanMoveArea(MapCell start, int step, ref List<MapCell> way)
    {
        List<MapCell> open = new List<MapCell>();
        open.Add(start);
        start.steps = 0;
        int count = 0;
        while(open.Count > 0)
        {
            count++;
            if (count > 10000) break;//break endless loop 
            var select = open[0];//从记录里找一个坑
            open.RemoveAt(0);

            if (select.steps > step) //如果当前的所有的步伐超过了能行走的步伐，则这个节点不能在往前走了
                continue;
            if (!way.Contains(select))//看看这个坑有没有踩过，踩过就不在踩了
            {
                way.Add(select);
            }//但是仍要去更新哦
            
            var closeCells = select.GetCloseCells();
            foreach(var k in closeCells)//记录前后左右的坑
            {

                if (!open.Contains(k)) //这个坑之前没记录过
                {
                    open.Add(k);
                }
                int G = select.steps + k.data.cost;
                if (G < k.steps)
                {
                    k.steps = G;
                    k.prev = select;
                    //Debug.LogWarningFormat("way ({0},{1}) G=> {2}", k.x, k.y, k.steps);
                }
            }
        }
    }

}
