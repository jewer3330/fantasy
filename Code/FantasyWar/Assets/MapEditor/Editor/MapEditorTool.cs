using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using System;
using SuperBoBo;

public class MapEditorTool : EditorWindow
{
    static string mapSavePath = "Assets/Resources/MapDatas/";

    [MenuItem("Tools/地图编辑器")]
    static void Init()
    {
        MapEditorTool window = (MapEditorTool)EditorWindow.GetWindow(typeof(MapEditorTool));
        window.Show();
        SceneView.onSceneGUIDelegate += window.OnSceneFunc;

        window.minSize = new Vector2(300, 400);
        window.Start();

    }

    public GameObject flag;
    public Material playerMat;
    public Material enemyMat;

    public void Start()
    {
    }

    private void OnSceneFunc(SceneView sceneView)
    {
        Repaint();
    }


    private GameObject CreateFlag()
    {
        if (!flag)
        {
            flag = AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Editor/flag.prefab");
            playerMat = Instantiate(flag.GetComponent<Renderer>().sharedMaterial);
            enemyMat = Instantiate(flag.GetComponent<Renderer>().sharedMaterial);
            playerMat.color = Color.green;
            enemyMat.color = Color.red;
        }
        var temp = Instantiate(flag);
        garbage.Add(temp);
        return temp;
    }


    private string mapName = string.Empty;
    private int mapWidth = 10;
    private int mapHeight = 10;
    private List<GameObject> garbage = new List<GameObject>();
    private GameObject currentSelect;
    private Vector2 scrollPosition;
    private bool draw;

    private void OnGUI()
    {

        EditorGUILayout.LabelField("mapName", mapName);
        mapWidth = EditorGUILayout.IntField("mapWidth", mapWidth);
        mapHeight = EditorGUILayout.IntField("mapHeight", mapHeight);
        flag = EditorGUILayout.ObjectField("flagObject", flag, typeof(GameObject), true) as GameObject;


        EditorGUILayout.BeginHorizontal();
        if (GUILayout.Button("create"))
        {
            CreateMap();
        }
        if (GUILayout.Button("load"))
        {
            Load();
        }
        if (GUILayout.Button("unload"))
        {
            Clean();
        }

        EditorGUILayout.EndHorizontal();

        draw = EditorGUILayout.ToggleLeft("draw ?", draw);
        currentSelect = EditorGUILayout.ObjectField("select go", currentSelect, typeof(GameObject), true) as GameObject;


        GUI.color = Color.green;
        if (GUILayout.Button("save"))
        {
            Save();
        }
        GUI.color = Color.white;
        GUILayout.Label("info");
        scrollPosition = EditorGUILayout.BeginScrollView(scrollPosition);
        if (Selection.gameObjects != null)
        {
            foreach (var k in Selection.gameObjects)
            {
                MapCell cell = k.gameObject.GetComponent<MapCell>();
                if (cell)
                {
                    
                    MapCellEditor.Draw(cell);
                }
            }
        }

        EditorGUILayout.EndScrollView();
    }



    private void Clean()
    {
        mapName = null;
        foreach (var k in garbage)
        {
            GameObject.DestroyImmediate(k);
        }
        flag = null;
        DestroyImmediate(playerMat);
        DestroyImmediate(enemyMat);
        Resources.UnloadUnusedAssets();
        AssetDatabase.Refresh();
    }

    private void Load()
    {
        Clean();

        string path = EditorUtility.OpenFilePanel("打开", mapSavePath, "asset");
        if (string.IsNullOrEmpty(path))
        {
            Debug.LogError("name is empty");
            return;
        }
        path = path.Substring(path.IndexOf("Assets/"));
        mapName = path;

        //Debug.Log(path);
        MapData data = AssetDatabase.LoadAssetAtPath<MapData>(path);

        if (data == null)
        {
            Debug.LogError("mapdata error");
            return;
        }

        //foreach (var k in garbage)
        //{
        //    GameObject.DestroyImmediate(k);
        //}

        mapWidth = data.mapWidth;
        mapHeight = data.mapHeight;

        for (int i = 0; i < data.cells.Count; i++)
        {
            GameObject go = GameObject.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>(data.cells[i].res));
            go.transform.position = new Vector3(data.cells[i].x, data.cells[i].h, data.cells[i].y);
            MapCell cell = go.AddComponent<MapCell>();
            cell.SetData(data.cells[i]);
            if (cell.data.start)
            {
                if (cell.data.playerType == MapCellData.PlayerType.Player)
                {
       
                    var temp = CreateFlag();
                    temp.transform.position = new Vector3(cell.data.x, cell.data.h, cell.data.y) + Vector3.up;
                    temp.GetComponent<Renderer>().sharedMaterial= playerMat;
                }
                else if (cell.data.playerType == MapCellData.PlayerType.Npc)
                {
                    var temp = CreateFlag();
                    temp.transform.position = new Vector3(cell.data.x, cell.data.h, cell.data.y) + Vector3.up;
                    temp.GetComponent<Renderer>().sharedMaterial = enemyMat;

                }
            }
            garbage.Add(go);
        }

        
    }

    void Save()
    {

        string mapName = EditorUtility.SaveFilePanelInProject("保存", "new.asset", "asset", "保存地图配置", mapSavePath);
        if (string.IsNullOrEmpty(mapName))
        {
            Debug.LogError("地图名称是空");
            return;
        }
        MapData map = ScriptableObject.CreateInstance<MapData>();
        foreach (var k in garbage)
        {
            MapCell mapCell = k.GetComponent<MapCell>();
            if (mapCell != null)
            {
                MapCellData data = new MapCellData(mapCell);
                map.cells.Add(data);
            }
        }
        map.mapHeight = mapHeight;
        map.mapWidth = mapWidth;
        var path = mapName.Substring(mapName.IndexOf("Assets/"));
        mapName = path;


        AssetDatabase.CreateAsset(map, mapName);
        AssetDatabase.Refresh();
        AssetDatabase.SaveAssets();
        
    }

    void CreateMap(int height = 0)
    {
        for (int i = 0; i < mapWidth; i++)
        {
            for (int j = 0; j < mapHeight; j++)
            {
                GameObject go = GameObject.CreatePrimitive(PrimitiveType.Cube);
                go.transform.position = new Vector3(i, height, j);
                MapCell cell = go.AddComponent<MapCell>();
                cell.data = new MapCellData();
                cell.data.x = i;
                cell.data.y = j;
                cell.data.h = height;
                cell.data.start = false;
                cell.data.cost = 1;
                garbage.Add(go);
            }
        }
    }

    private void OnDestroy()
    {
        Clean();
    }

    void Update()
    {
        if (Selection.gameObjects != null && draw)
        {
            ChangeGameObjectType(Selection.gameObjects);
        }


    }

    void ChangeGameObjectType(GameObject [] gos)
    {
        if (currentSelect != null)
        {
            foreach (var k in gos)
            {
                MapCell cell = k.GetComponent<MapCell>();
                if (cell != null && cell.data.res != AssetDatabase.GetAssetPath(currentSelect))
                {
                    GameObject go = GameObject.Instantiate(currentSelect) as GameObject;
                    go.transform.position = k.transform.position;
                    MapCell c = go.AddComponent<MapCell>();
                    c.SetData(cell);
                    c.data.res = AssetDatabase.GetAssetPath(currentSelect);
                    this.garbage.Remove(k);
                    this.garbage.Add(go);
                    GameObject.DestroyImmediate(k);
                }
            }
        }
    }

}
