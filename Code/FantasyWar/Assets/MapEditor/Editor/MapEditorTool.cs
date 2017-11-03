using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using System;

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

    public void Start()
    {
        string  [] dirs = System.IO.Directory.GetDirectories(Application.dataPath + "/Resources/MapRes");

        foreach (var k in dirs)
        {
            string []files = System.IO.Directory.GetFiles(k,"*.prefab");
            List<ObjectInfo> objects = new List<ObjectInfo>();
            string path = k.Replace("\\", "/");
            string y = path.Substring(path.LastIndexOf('/') + 1);
            int key = int.Parse(y);
            List<GUIContent> contents = new List<GUIContent>();
            foreach (var f in files)
            {
                ObjectInfo oi = new ObjectInfo();
                oi.path = f.Replace("\\", "/");
                string p = oi.path.Substring(oi.path.IndexOf("Resources") + "Resources".Length + 1);
                string prefab = p.Substring(0, p.LastIndexOf("."));
                oi.prefabName = prefab;
                oi.go = Resources.Load(prefab);
                Texture2D tex = AssetPreview.GetAssetPreview(oi.go);
                while (tex == null)
                {
                    tex = AssetPreview.GetAssetPreview(oi.go);
                    System.Threading.Thread.Sleep(1);
                }
                oi.texture = Instantiate(tex);
                oi.id = key;
                objects.Add(oi);
                contents.Add(new GUIContent(oi.texture, oi.prefabName));
            }


            ObjectPathInfo opi = new ObjectPathInfo();
            opi.id = key;
            opi.objInfos = objects;
            opi.contents = contents;
            paths.Add(opi);
        }


    }

    private void OnSceneFunc(SceneView sceneView)
    {
        Repaint();
    }

    public class ObjectInfo
    {
        public string path;
        public string prefabName;
        public UnityEngine.Object go;
        public Texture2D texture;
        public int id;
       
    }

    public class ObjectPathInfo
    {
        public int id;
        public List<ObjectInfo> objInfos = new List<ObjectInfo>();
        public int select = -1;
        public List<GUIContent> contents = new List<GUIContent>();

    }


    private int mapWidth = 10;
    private int mapHeight = 10;
    private List<GameObject> garbage = new List<GameObject>();

    public List<ObjectPathInfo> paths = new List<ObjectPathInfo>();

    private ObjectInfo currentSelect;
    private Vector2 scrollPosition;
    private void OnGUI()
    {
        mapWidth = EditorGUILayout.IntField("地图宽度", mapWidth);
        mapHeight = EditorGUILayout.IntField("地图高度", mapHeight);
        EditorGUILayout.BeginHorizontal();
        if (GUILayout.Button("create"))
        {
            CreateMap();
        }
        if (GUILayout.Button("load"))
        {
            Load();
        }
        EditorGUILayout.EndHorizontal();


        GUI.color = Color.green;
        if (GUILayout.Button("save"))
        {
            Save();
        }
        GUI.color = Color.white;
        GUILayout.Label("当前Cell信息");
        if (Selection.gameObjects != null)
        {
            foreach (var k in Selection.gameObjects)
            {
                MapCell cell = k.gameObject.GetComponent<MapCell>();

                cell.start = EditorGUILayout.Toggle("startpoint", cell.start);
            }
        }

        scrollPosition = GUILayout.BeginScrollView(scrollPosition);
        foreach (var k in paths)
        {

            
            GUILayout.BeginHorizontal();
            GUILayout.Label(Table.Map.Get(k.id).Name);
            GUILayout.EndHorizontal();

            EditorGUILayout.BeginHorizontal();

            int select = GUILayout.SelectionGrid(k.select, k.contents.ToArray(), 3);

            //foreach (var v in k.objInfos)
            //{
            //    if (v.texture == null )
            //    {
            //        v.texture = AssetPreview.GetAssetPreview(v.go);
            //    }
            //}
            

            if (k.select != select)
            {
                k.select = select;
                if (currentSelect != null)
                {
                    var pathInfo = FindPathInfo(currentSelect);
                    if (pathInfo != null && pathInfo != k)
                    {
                        pathInfo.select = -1;
                    }
                }

                currentSelect = k.objInfos[k.select];
            }

            EditorGUILayout.EndHorizontal();
            EditorGUILayout.Space();
        }

        GUILayout.EndScrollView();
    }

    private ObjectPathInfo FindPathInfo(ObjectInfo info)
    {
        foreach (var k in paths)
        {
            foreach (var v in k.objInfos)
            {
                if (v == info)
                {
                    return k;
                }
            }
        }
        return null;
    }

    private void Load()
    {
        
        string path = EditorUtility.OpenFilePanel("打开", mapSavePath, "json");
        if (string.IsNullOrEmpty(path))
        {
            Debug.LogError("地图名称是空");
            return;
        }
        string d = FileUtilTool.ReadFile(path);
        MapData data = LitJson.JsonMapper.ToObject<MapData>(d);

        if (data == null)
        {
            Debug.LogError("地图格式不正确");
            return;
        }

        foreach (var k in garbage)
        {
            GameObject.DestroyImmediate(k);
        }

        mapWidth = data.mapWidth;
        mapHeight = data.mapHeight;

        for (int i = 0; i < data.cells.Count; i++)
        {
            GameObject go = GameObject.Instantiate(Resources.Load(data.cells[i].res)) as GameObject;
            go.transform.position = new Vector3(data.cells[i].x, data.cells[i].h, data.cells[i].y);
            MapCell cell = go.AddComponent<MapCell>();
            cell.x = data.cells[i].x;
            cell.y = data.cells[i].y;
            cell.h = data.cells[i].h;
            cell.id = data.cells[i].id;
            cell.res = data.cells[i].res;
            cell.start = data.cells[i].start;
            garbage.Add(go);
        }

        
    }

    void Save()
    {

        string mapName = EditorUtility.SaveFilePanelInProject("保存", "new.json", "json", "保存地图配置", mapSavePath);
        if (string.IsNullOrEmpty(mapName))
        {
            Debug.LogError("地图名称是空");
            return;
        }
        MapData map = new MapData();
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

        string d = LitJson.JsonMapper.ToJson(map);

        FileUtilTool.WriteFile(mapName, d);

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
                cell.x = i;
                cell.y = j;
                cell.h = height;
                cell.start = false;
                garbage.Add(go);
            }
        }
    }

    private void OnDestroy()
    {
        foreach (var k in garbage)
        {
            GameObject.DestroyImmediate(k);
        }

        foreach (var k in paths)
        {
            foreach (var v in k.objInfos)
            {
                GameObject.DestroyImmediate(v.texture);
            }
        }

        paths.Clear();
        Resources.UnloadUnusedAssets();
        AssetDatabase.Refresh();
    }

    void Update()
    {
        if (Selection.gameObjects != null)
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
                if (cell != null && cell.res != currentSelect.prefabName)
                {
                    GameObject go = GameObject.Instantiate(currentSelect.go) as GameObject;
                    go.transform.position = k.transform.position;
                    MapCell c = go.AddComponent<MapCell>();
                    c.x = cell.x;
                    c.y = cell.y;
                    c.h = cell.h;
                    c.start = cell.start;
                    c.res = currentSelect.prefabName;
                    c.id = currentSelect.id;
                    this.garbage.Remove(k);
                    this.garbage.Add(go);
                    GameObject.DestroyImmediate(k);
                }
            }
        }
    }

}
