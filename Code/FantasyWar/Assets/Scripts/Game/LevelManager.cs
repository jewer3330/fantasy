using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using SuperBoBo;

public class EasyPool<T>
{
    private Queue<T> caches = new Queue<T>();
    private HashSet<T> _caches = new HashSet<T>();
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
            _caches.Remove(ret);
        }
        else
        {
            ret = action();
        }
        return ret;
    }

    public void Return(T t)
    {
        if (t != null && !_caches.Contains(t))
        {
            caches.Enqueue(t);
            _caches.Add(t);
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

    public List<MapCell> startPositions = new List<MapCell>();
    //public MapCell start;
    public Player selectPlayer;

    public Dictionary<int,Player> players = new Dictionary<int,Player>();
    public Dictionary<int, Player> npcPlayers = new Dictionary<int, Player>();

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
       
        MapCell data = null;
        int key = x + y * (mapWidth);
        if (!caches.TryGetValue(key, out data))
        {
            
        }
        return data;
    }

    public MapCell GetData(int ID)
    {
        MapCell data = null;
        if (!caches.TryGetValue(ID, out data))
        {

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

        AutoSelectPlayer();
        state = State.Area;

    }

    void GenActors()
    {
        foreach (var k in startPositions)
        {
            GenActor(k);
        }
    }


    private GameObject uitaketurns;

    void ShowTurnStart(string title)
    {
        if (!uitaketurns)
        {
            ResManager.LoadAsync("UI/UITaketurns", (go) =>
            {
                var ins = Instantiate(go) as GameObject;
                uitaketurns = ins;
                UIManager.Instance.AddWidget(ins);
                SuperBoBo.EventManager.Instance.FireEvent(UITaketurns.ChangeName, title);
            });
        }
        else
        {
            uitaketurns.gameObject.SetActive(true);
            SuperBoBo.EventManager.Instance.FireEvent(UITaketurns.ChangeName, title);
        }

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
            cell.LevelManager = this;
            if (cell.data.start)
            {
                startPositions.Add(cell);
            }
            go.transform.parent = mapRoot.transform;
            
            caches.Add(cell.ID, cell);
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
        Player player;
        if (position.data.playerType == MapCellData.PlayerType.Player)
        {
            player = go.AddComponent<Player>();
            players.Add(player.GetInstanceID(), player);
        }
        else
        {
            player = go.AddComponent<NpcPlayer>();
            npcPlayers.Add(player.GetInstanceID(), player);
        }

        player.data = data;
        player.target = position;
        player.levelManager = this;
        var start = position;
        player.transform.position = new Vector3(start.data.x, start.data.h, start.data.y) + Vector3.up;
        
        var manager = player.gameObject.GetComponent<AnimationManager>();
        manager.player = player;
        all.Add(player.GetInstanceID(), player);
    }

    public enum StartType
    {
        Player,
        Npc,
    }

    public StartType startType;

    void AutoSelectPlayer()
    {
        StartType temp = startType;

        if (IsAllSelected())
        {
            ClearSelectPlayers();
            temp = startType;
            selectedCount = 0;
        }

        
        switch (temp)
        {
            case StartType.Player:
                if (!IsPlayerAllSelected())
                {
                    if(selectedCount == 0)
                        ShowTurnStart(Language.TAKETURNS_WE_START);
                    AutoSelectPlayer(players);
                }
                else
                {
                    ShowTurnStart(Language.TAKETURNS_THEY_START);
                    AutoSelectPlayer(npcPlayers);
                }
                break;
            case StartType.Npc:

                if (!IsNpcAllSelected())
                {
                    if (selectedCount == 0)
                        ShowTurnStart(Language.TAKETURNS_THEY_START);
                    AutoSelectPlayer(npcPlayers);
                }
                else
                {
                    ShowTurnStart(Language.TAKETURNS_WE_START);
                    AutoSelectPlayer(players);
                }
                break;
            default:
                break;
        }
        
    }

    void ClearSelectPlayers()
    {
        foreach (var k in all)
        {
            k.Value.isSelected = false;
        }
    }


    bool IsAllSelected()
    {
        return selectedCount == all.Count;
    }

    bool IsPlayerAllSelected()
    {
        bool ret = true;
        foreach (var k in players)
        {
            if (!k.Value.isSelected)
            {
                ret = false;
                break;
            }
        }
        return ret;
    }

    bool IsNpcAllSelected()
    {
        bool ret = true;
        foreach (var k in npcPlayers)
        {
            if (!k.Value.isSelected)
            {
                ret = false;
                break;
            }
        }
        return ret;
    }

    private int selectedCount = 0;

    void AutoSelectPlayer(Dictionary<int, Player> players)
    {
        foreach (var k in players)
        {
            if (k.Value.isSelected)
            {
                continue;
            }
            else
            {
                selectedCount++;
                selectPlayer = k.Value;
                selectPlayer.isSelected = true;
                PrepareCamera(selectPlayer);
                break;
            }
        }
    }


    void PrepareCamera(Player player)
    {
        playerCamera = Camera.main.GetComponent<PlayerCamera>();
        playerCamera.player = player;
    }

    public void ResetState()
    {
        state = State.Area;
        foreach (var k in canMoveArea)
        {
            k.indicator.gameObject.SetActive(false);
            k.steps = MapCell.MaxStep;
            k.prev = null;
            indicators.Return(k.indicator);
        }
        if(select)
            select.SetHighLight(false);
        select = null;
        AutoSelectPlayer();

    }

    public MapCellIndicator FindIndicator(MapCell cell)
    {
        foreach (var k in canMoveArea)
        {
            if (k == cell)
            {
                return k.indicator;
            }
        }
        return null;
    }

    public void HighLightIndicator(MapCellIndicator cellIndicator)
    {
        if (select != null)
            select.SetHighLight(false);
        select = cellIndicator;
    }


    // Update is called once per frame
    void Update ()
    {
	    switch(state)
        {
            case State.Area:
                canMoveArea.Clear();
                FindCanMoveArea(selectPlayer.target, selectPlayer.data.MV, ref canMoveArea);
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
                int count = 0;
                while (current.prev)
                {
                    if (count++ > 10)
                    {
                        Debug.LogError("endless loop");
                        break;
                    }
                    way.Add(current);
                    current = current.prev;
                }
                way.Reverse();
                state = State.WalkTo;
                break;
            case State.WalkTo:
                selectPlayer.Move(way);
                state = State.Idle;
                
                break;
                
        }
	}




    void FindCanMoveArea(MapCell start, int step, ref List<MapCell> way)
    {
        List<int> open = new List<int>();
        HashSet<int> walked = new HashSet<int>();

        open.Add(start.ID);
        walked.Add(start.ID);

        start.steps = 0;
        int count = 0;
        while(open.Count > 0)
        {
            count++;
            if (count > 10000) break;
            var id = open[0];
            open.RemoveAt(0);
            MapCell cell = GetData(id);
            if (cell.steps > step) 
            {
                cell.prev = null;
                cell.steps = MapCell.MaxStep;
                continue;
            }
            if (!way.Contains(cell))
            {
                way.Add(cell);
            }
            
            var closeCells = cell.GetCloseCells();
            foreach(var k in closeCells)
            {

                if (!walked.Contains(k.ID)) 
                {
                    open.Add(k.ID);
                    walked.Add(k.ID);
                }
                int G = cell.steps + k.Cost;
                if (G <= step && G < k.steps)
                {
                    k.steps = G;
                    k.prev = cell;
                    
                }
            }
        }
    }

    public MapCell FindNearByCell(List<MapCell> cells,Player player)
    {
        MapCell mapCell = null;
        if (cells != null && player != null)
        {
            mapCell = cells[0];
            int minlength = MapCell.MaxStep;
            foreach (var k in cells)
            {
                int length = Mathf.Abs (k.data.x - player.target.data.x) +
                    Mathf.Abs(k.data.y - player.target.data.y) ;

                if (length < minlength)
                {
                    minlength = length;
                    mapCell = k;
                }
            }
        }

        return mapCell;
    }

    public Player FindNearByPlayer(Player player,int maxBlock = 1)
    {
        Player ret = null;
        int min = MapCell.MaxStep;
        foreach (var k in all)
        {
            if (k.Value != player)
            {
                int length = Mathf.Abs( k.Value.target.data.x - player.target.data.x)
                    + Mathf.Abs(k.Value.target.data.y - player.target.data.y);
                if (length < min)
                {
                    ret = k.Value;
                    min = length;
                    if (min <= maxBlock)
                    {
                        break;
                    }
                }
            }
        }
        return ret;
    }

}
