using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class LevelManager : MonoBehaviour
{
    public MapData mapData;
    public int mapWidth;
    public int mapHeight;

    public List<MapCell> cells = new List<MapCell>();
    public List<MapCell> startPositions = new List<MapCell>();
    public Player player;
    public PlayerCamera playerCamera;

    // Use this for initialization
    void Start ()
    {
        TextAsset ta = ResManager.Load("MapDatas/" + "level1") as TextAsset;
        string data = ta.text;
        mapData = LitJson.JsonMapper.ToObject<MapData>(data);
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
            GameObject go = GameObject.Instantiate(Resources.Load(mapData.cells[i].res)) as GameObject;
            go.transform.position = new Vector3(mapData.cells[i].x, mapData.cells[i].h, mapData.cells[i].y);
            MapCell cell = go.AddComponent<MapCell>();
            cell.x = mapData.cells[i].x;
            cell.y = mapData.cells[i].y;
            cell.h = mapData.cells[i].h;
            cell.id = mapData.cells[i].id;
            cell.res = mapData.cells[i].res;
            cell.start = mapData.cells[i].start;

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
    }


    void PrepareCamera()
    {
        playerCamera = Camera.main.GetComponent<PlayerCamera>();
        playerCamera.player = player;
    }

	// Update is called once per frame
	void Update ()
    {
	
	}
}
