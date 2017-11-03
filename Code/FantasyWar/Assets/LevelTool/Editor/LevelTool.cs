using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;






public class LevelTool : EditorWindow
{
    

    //scene
    public int sceneIndex;
    public List<string> sceneNames = new List<string>();

    //data
    public int dataIndex = -1;
    public List<string> dataNames = new List<string>();
    public string dataName;
    public bool isCreate;

    //pathnode
    public LevelPath currentPath;
    public Vector2 pathScollpos = Vector2.zero;


    //birthpos
    
    public LevelBirthPosition currentBirth;
    public string currentBirthName;
    public Vector2 birthScollpos = Vector2.zero;


    //proppos
    
    //public string currentPropName;
    public Vector2 propScollpos = Vector2.zero;
    public List<string> propIDs = new List<string>();


    //
    
    public string currentDoorName;
    public Vector2 doorScollpos = Vector2.zero;
    public List<string> doorNames = new List<string>();
    public List<GameObject> doorObjects = new List<GameObject>();
    public List<Texture2D> doorTextures = new List<Texture2D>();


    //
    public string currentAreaName;


    //init monster
    public LevelMonster currentSelectMonster;



    //tag
    public List<string> tags = new List<string>();


    public int tagIndex;

    //scroll
    public Vector2 scollpos = Vector2.zero;
    public int spaceX = 10;
    public int spaceY = 10;
    public int cellwidth = 100;
    public int cellHeight = 100;

    //gridmonster
    

    //public List<Monster> monsters = new List<Monster>();
    //public List<string> monsterNames = new List<string>();
    //public List<GameObject> monsterObjects = new List<GameObject>();
    //public List<Texture2D> monsterTextures = new List<Texture2D>();
    //public List<GUIContent> monsterContents = new List<GUIContent>();


    public class EditorUIGridData
    {
        public string tableIDString;
        public int tableIDInt;
        public string name;
        public string modleName;
        public GameObject go;
        public Texture texture;
        public GUIContent content;
    }

    /// <summary>
    /// 怪物模型数据
    /// </summary>
    List<EditorUIGridData> monsterGrids = new List<EditorUIGridData>();

    /// <summary>
    /// 场景物件数据
    /// </summary>
    List<EditorUIGridData> sceneGrids = new List<EditorUIGridData>();


    public static GUIContent[] GetGridContent(List<EditorUIGridData> data)
    {
        List<GUIContent> cs = new List<GUIContent>();
        foreach (var k in data)
        {
            cs.Add(k.content);
        }
        return cs.ToArray();
    }


    //gridnode
    public List<LevelPathNodeData> pathNodeDatas = new List<LevelPathNodeData>();
    public List<string> pathNames = new List<string>();
    public List<GameObject> pathObjects = new List<GameObject>();
    public List<Texture2D> pathTextures = new List<Texture2D>();

    //batch
    //public List<LevelTriggleData> batchDatas = new List<LevelTriggleData>();
    public List<string> batchNames = new List<string>();
    public List<GameObject> batchObjects = new List<GameObject>();
    public List<Texture2D> batchTextures = new List<Texture2D>();
    
    //taggroup
    private bool isOpenData = true;
    private bool isNewData = false;
    private int objIndex;



    //hitinfo
    public static RaycastHit hitInfo;
    public static Vector3 startPosition;

    //stuff
    public static List<GameObject> stuffs = new List<GameObject>();
    public bool isSaved = false;
    public bool isChanged = false;

    public float lineHeight = 132f;

    public float lineHeader = 100f;

    public static bool showArea = true;

    [MenuItem("Tools/场景编辑器新版")]
    static void Init()
    {
        LevelTool window = (LevelTool)EditorWindow.GetWindow(typeof(LevelTool));
        window.Show();

        SceneView.onSceneGUIDelegate += window.OnSceneFunc;

        window.minSize = new Vector2(300, 900);
        window.Start();

        Config.ReadData();




    }

    private void OnSceneFunc(SceneView sceneView)
    {

        Camera cameara = sceneView.camera;

        Ray ray = HandleUtility.GUIPointToWorldRay(sceneView.position.center);
        if (Physics.Raycast(ray, out hitInfo, 10000, -1))
        {

            Vector3 origin = hitInfo.point;
            origin.y += 100;
            if (Physics.Raycast(origin, Vector3.down, out hitInfo))
            {
                Handles.color = Color.red;
                Handles.DrawLine(hitInfo.point, origin);
                float arrowSize = 1;
                Vector3 pos = hitInfo.point;
                Quaternion quat;
                Handles.color = Color.green;
                quat = Quaternion.LookRotation(Vector3.up, Vector3.up);
                Handles.ArrowCap(0, pos, quat, arrowSize);
                Handles.color = Color.red;
                quat = Quaternion.LookRotation(Vector3.right, Vector3.up);
                Handles.ArrowCap(0, pos, quat, arrowSize);
                Handles.color = Color.blue;
                quat = Quaternion.LookRotation(Vector3.forward, Vector3.up);
                Handles.ArrowCap(0, pos, quat, arrowSize);
                startPosition = hitInfo.point + new Vector3(0, 3f, 0);


                GUIStyle style = new GUIStyle();
                style.richText = true;

                Handles.Label(hitInfo.point, string.Format("<size=15><color={0}>{1}</color></size>", "#FF0000", (int)hitInfo.point.x + "," + (int)hitInfo.point.y + "," + (int)hitInfo.point.z), style);

            }
        }


        DrawPath();
        DrawArea();
        DrawTrap();
    }



    public void DrawTrap()
    {

        LevelSceneObject[] areas = GameObject.FindObjectsOfType<LevelSceneObject>();
        foreach (var k in areas)
        {
            LevelSceneObjectData data = k.GetData() as LevelSceneObjectData;
            switch (data.type)
            {

                case LevelSceneObjectData.Type.Quicksand:
                    Handles.color = Color.magenta;
                    break;
            }
            LevelChooseInfo.DrawCircle(k.transform.position, data.radius);

        }


    }


    public void DrawArea()
    {

        LevelArea[] areas = GameObject.FindObjectsOfType<LevelArea>();
        foreach (var k in areas)
        {
            LevelAreaData data = k.GetData() as LevelAreaData;
            if (showArea && data!=null && k!=null)
            {
                k.gameObject.GetComponent<Renderer>().enabled = true;
                switch (data.type)
                {
                    default:
                    case LevelAreaData.Type.Base:
                        Handles.color = Color.green;
                        break;
                    case LevelAreaData.Type.Defend:
                        Handles.color = Color.red;
                        break;
                    case LevelAreaData.Type.Normal:
                        Handles.color = Color.blue;
                        break;
                    //case LevelAreaData.Type.Trap:
                    //    Handles.color = Color.magenta;
                    //    break;
                }


                LevelChooseInfo.DrawCircle(k.transform.position, data.radius);

                Handles.color = Color.magenta;


                foreach (var k2 in k.areas)
                {
                    List<Vector3> points = new List<Vector3>();
                    points.Add(k.transform.position);
                    points.Add(k2.transform.position);
                    Handles.DrawPolyLine(points.ToArray());
                }

                Handles.color = Color.white;
            }
            else
            {
                k.gameObject.GetComponent<Renderer>().enabled = false;
            }

        }


    }

    // Use this for initialization

    public enum LevelToolEditorType
    {
        Monster = 0,
        Scene,
        Batch,
        Area,
        BirthPos,
        SceneItem,
        Path,
        Mode
    }



    public delegate void OnGUIObject(LevelToolEditorType type);

    public OnGUIObject guiFunc;



    public static LevelModeData modeData;


    
    public void OnGUIMode(LevelToolEditorType type)
    {
        if (type == LevelToolEditorType.Mode)
        {
            GUILayout.Label("1星");
            if (modeData == null)
            {
                
                modeData = new LevelModeData();
            }

            modeData.condition1Star.selectIndex = EditorGUILayout.Popup("1星类型", modeData.condition1Star.selectIndex, Config.mode1StarTypeCns);
            modeData.condition1Star.conditionType = modeData.condition1Star.selectIndex + 1;
            modeData.condition1Star.time = EditorGUILayout.FloatField("时间", modeData.condition1Star.time);
            modeData.condition1Star.isKillMonsters = EditorGUILayout.Toggle("是否要杀死某怪物们？", modeData.condition1Star.isKillMonsters);

            if (modeData.condition1Star.isKillMonsters)
            {

                EditorGUILayout.BeginHorizontal();
                modeData.condition1Star.selectMonster = (LevelMonster)EditorGUILayout.ObjectField("怪物", modeData.condition1Star.selectMonster, typeof(LevelMonster));

                if (GUILayout.Button("添加目标"))
                {
                    if (modeData.condition1Star.selectMonster)
                    {
                        if (!modeData.condition1Star.selectMonsters.Contains(modeData.condition1Star.selectMonster))
                            modeData.condition1Star.selectMonsters.Add(modeData.condition1Star.selectMonster);
                    }
                }

                EditorGUILayout.EndHorizontal();

                for (int i = 0; i < modeData.condition1Star.selectMonsters.Count; i++)
                {
                    EditorGUILayout.BeginHorizontal();

                    EditorGUILayout.ObjectField(modeData.condition1Star.selectMonsters[i], typeof(LevelMonster));
                    GUI.backgroundColor = Color.red;
                    if (GUILayout.Button("删除"))
                    {
                        if (modeData.condition1Star.selectMonsters.Contains(modeData.condition1Star.selectMonsters[i]))
                        {
                            modeData.condition1Star.selectMonsters.Remove(modeData.condition1Star.selectMonsters[i]);
                            continue;
                        }
                    }
                    GUI.backgroundColor = Color.white;

                    EditorGUILayout.EndHorizontal();

                }

            } 
            

            EditorGUILayout.Space();

            GUILayout.Label("2星");

            EditorGUILayout.BeginHorizontal();

            modeData.conditionIndex2Star = EditorGUILayout.Popup("选择一个条件", modeData.conditionIndex2Star, Config.conditionCns);
            if (GUILayout.Button("添加"))
            {
                bool find = false;
                for (int i = 0; i < modeData.condition2Star.Count; i++)
                {
                    if (modeData.condition2Star[i].type == modeData.conditionIndex2Star)
                    {
                        EditorUtility.DisplayDialog("提示", "2星条件中有相同的类型", "确定");
                        find = true;
                        break;
                    }
                }
                for (int i = 0; i < modeData.condition3Star.Count; i++)
                {
                    if (modeData.condition3Star[i].type == modeData.conditionIndex2Star)
                    {
                        EditorUtility.DisplayDialog("提示", "3星条件中有相同的类型", "确定");
                        find = true;
                        break;
                    }
                }

                

                if (!find)
                {
                    switch (modeData.conditionIndex2Star)
                    {
                        case 0:
                            LevelModeData.Condition hpc = new LevelModeData.Condition();
                            hpc.type = 0;
                            modeData.condition2Star.Add(hpc);
                            break;
                        case 1:
                            LevelModeData.Condition tc = new LevelModeData.Condition();
                            tc.type = 1;
                            modeData.condition2Star.Add(tc);
                            break;
                        case 2:
                            LevelModeData.Condition ttc = new LevelModeData.Condition();
                            ttc.type = 2;
                            modeData.condition2Star.Add(ttc);
                            break;
                        case 3:
                            LevelModeData.Condition nc = new LevelModeData.Condition();
                            nc.type = 3;
                            modeData.condition2Star.Add(nc);
                            break;
                    }
                }
            }

            EditorGUILayout.EndHorizontal();
            for (int i = 0; i < modeData.condition2Star.Count; i++)
            {
                EditorGUILayout.BeginHorizontal();
                if (modeData.condition2Star[i].type == 0)
                {
                    var hpc = modeData.condition2Star[i];
                    hpc.param = EditorGUILayout.IntField("血量百分比", hpc.param);
                }
                if (modeData.condition2Star[i].type == 1)
                {
                    var hpc = modeData.condition2Star[i];
                    hpc.param = EditorGUILayout.IntField("携带坦克类型上场（", hpc.param);
                }
                if (modeData.condition2Star[i].type == 2)
                {
                    var hpc = modeData.condition2Star[i];
                    hpc.param = EditorGUILayout.IntField("通关时间小于", hpc.param);
                }
                if (modeData.condition2Star[i].type == 3)
                {
                    var hpc = modeData.condition2Star[i];
                    hpc.param = EditorGUILayout.IntField("团队存活人数个数", hpc.param);
                }
                GUI.backgroundColor = Color.red;
                if (GUILayout.Button("删除"))
                {
                    if (modeData.condition2Star.Contains(modeData.condition2Star[i]))
                    {
                        modeData.condition2Star.Remove(modeData.condition2Star[i]);
                        continue;
                    }
                }
                GUI.backgroundColor = Color.white;
                EditorGUILayout.EndHorizontal();
            }





            EditorGUILayout.Space();

            GUILayout.Label("3星");

            EditorGUILayout.BeginHorizontal();

            modeData.conditionIndex3Star = EditorGUILayout.Popup("选择一个条件", modeData.conditionIndex3Star, Config.conditionCns);
            if (GUILayout.Button("添加"))
            {
               bool find = false;
                for (int i = 0; i < modeData.condition2Star.Count; i++)
                {
                    if (modeData.condition2Star[i].type == modeData.conditionIndex3Star)
                    {
                        EditorUtility.DisplayDialog("提示", "2星条件中有相同的类型", "确定");
                        find = true;
                        break;
                    }
                }

                for (int i = 0; i < modeData.condition3Star.Count; i++)
                {
                    if (modeData.condition3Star[i].type == modeData.conditionIndex3Star)
                    {
                        EditorUtility.DisplayDialog("提示", "3星条件中有相同的类型", "确定");
                        find = true;
                        break;
                    }
                }

                if (!find)
                {
                    switch (modeData.conditionIndex3Star)
                    {
                        case 0:
                            LevelModeData.Condition hpc = new LevelModeData.Condition();
                            hpc.type = 0;
                            modeData.condition3Star.Add(hpc);
                            break;
                        case 1:
                            LevelModeData.Condition tc = new LevelModeData.Condition();
                            tc.type = 1;
                            modeData.condition3Star.Add(tc);
                            break;
                        case 2:
                            LevelModeData.Condition ttc = new LevelModeData.Condition();
                            ttc.type = 2;
                            modeData.condition3Star.Add(ttc);
                            break;
                        case 3:
                            LevelModeData.Condition nc = new LevelModeData.Condition();
                            nc.type = 3;
                            modeData.condition3Star.Add(nc);
                            break;
                    }
                }
            }

            EditorGUILayout.EndHorizontal();
            for (int i = 0; i < modeData.condition3Star.Count; i++)
            {
                EditorGUILayout.BeginHorizontal();
                if (modeData.condition3Star[i].type == 0)
                {
                    var hpc = modeData.condition3Star[i];
                    hpc.param = EditorGUILayout.IntField("血量百分比", hpc.param);
                }
                if (modeData.condition3Star[i].type == 1)
                {
                    var hpc = modeData.condition3Star[i];
                    hpc.param = EditorGUILayout.IntField("携带坦克类型上场（", hpc.param);
                }
                if (modeData.condition3Star[i].type == 2)
                {
                    var hpc = modeData.condition3Star[i];
                    hpc.param = EditorGUILayout.IntField("通关时间小于", hpc.param);
                }
                if (modeData.condition3Star[i].type == 3)
                {
                    var hpc = modeData.condition3Star[i];
                    hpc.param = EditorGUILayout.IntField("团队存活人数个数", hpc.param);
                }
                GUI.backgroundColor = Color.red;
                if (GUILayout.Button("删除"))
                {
                    if (modeData.condition3Star.Contains(modeData.condition3Star[i]))
                    {
                        modeData.condition3Star.Remove(modeData.condition3Star[i]);
                        continue;
                    }
                }
                GUI.backgroundColor = Color.white;
                EditorGUILayout.EndHorizontal();
            }
            EditorGUILayout.Space();

        }

    }

    List<LevelBatch> bchs = new List<LevelBatch>();
    public void OnGUIBatch(LevelToolEditorType type)
    {
        if (type == LevelToolEditorType.Batch)
        {
            #region
            scollpos = EditorGUILayout.BeginScrollView(scollpos);
            EditorGUILayout.BeginHorizontal();
            objIndex = GUILayout.SelectionGrid(objIndex, batchTextures.ToArray(), 3);
            OnSelectBatch(objIndex);
            EditorGUILayout.EndHorizontal();
            EditorGUILayout.Space();

            LevelBatch[] batches = GameObject.FindObjectsOfType<LevelBatch>();

            if (batches != null && batches.Length != 0 && bchs.Count != batches.Length)
            {
                bchs = new List<LevelBatch>(batches);


                bchs.Sort((left, right) =>
                {
                    LevelBatchData l = (LevelBatchData)left.GetData();
                    LevelBatchData r = (LevelBatchData)right.GetData();


                    if (l.index < r.index)
                    {
                        return -1;
                    }
                    else if (l.index == r.index)
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                });
            }

            if (GUILayout.Button("排序"))
            {
               

                bchs.Sort((left, right) =>
                {
                    LevelBatchData l = (LevelBatchData)left.GetData();
                    LevelBatchData r = (LevelBatchData)right.GetData();


                    if (l.index < r.index)
                    {
                        return -1;
                    }
                    else if (l.index == r.index)
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                });
            }
            

            EditorGUILayout.BeginHorizontal();
            EditorGUILayout.LabelField("所有波次", GUILayout.Width(100));
            EditorGUILayout.EndHorizontal();

            
            foreach (var k in bchs)
            {
                LevelBatchData ltd = (LevelBatchData)k.GetData();
                EditorGUILayout.BeginHorizontal();
                //EditorGUILayout.LabelField(ltd.name, GUILayout.Width(100));
                EditorGUILayout.LabelField("波次序号", GUILayout.Width(50));
                ltd.index = EditorGUILayout.IntField(ltd.index, GUILayout.Width(50));
                EditorGUILayout.LabelField("循环次数", GUILayout.Width(50));
                ltd.loopCount = EditorGUILayout.IntField(ltd.loopCount, GUILayout.Width(50));
                EditorGUILayout.LabelField("循环间隔", GUILayout.Width(50));
                ltd.loopInterval = EditorGUILayout.IntField(ltd.loopInterval, GUILayout.Width(50));
                EditorGUILayout.LabelField("奖励物品", GUILayout.Width(50));
                ltd.dropID = EditorGUILayout.IntField(ltd.dropID, GUILayout.Width(50));
                EditorGUILayout.ObjectField(k, typeof(LevelBatchData), true);
                EditorGUILayout.EndHorizontal();

            }

            EditorGUILayout.EndScrollView();

            
            #endregion
        }
    }

    public void OnGUIArea(LevelToolEditorType type)
    {
        if (type == LevelToolEditorType.Area)
        {
            #region
            showArea = EditorGUILayout.Toggle("显示", showArea);
            EditorGUILayout.BeginHorizontal();
            currentAreaName = EditorGUILayout.TextField(currentAreaName);
            GUI.backgroundColor = Color.yellow;

            if (GUILayout.Button("创建区域"))
            {
                OnAddArea();
            }
            GUI.backgroundColor = Color.white;
            EditorGUILayout.EndHorizontal();
            LevelArea[] areas = GameObject.FindObjectsOfType<LevelArea>();
            EditorGUILayout.LabelField("所有区域", GUILayout.Width(100));
            for (int i = 0; i < areas.Length; i++)
            {
                EditorGUILayout.BeginHorizontal();
                EditorGUILayout.ObjectField(areas[i], typeof(LevelArea), true);
                if (GUILayout.Button("删除"))
                {
                    GameObject.DestroyImmediate(areas[i].gameObject);
                }
                EditorGUILayout.EndHorizontal();
            }

            #endregion
        }
    }

    public void OnGUIBirthPos(LevelToolEditorType type)
    {
        if (type == LevelToolEditorType.BirthPos)
        {
            #region
            EditorGUILayout.BeginHorizontal();
            currentBirthName = EditorGUILayout.TextField(currentBirthName);
            GUI.backgroundColor = Color.yellow;
            if (GUILayout.Button("创建出生点"))
            {
                OnAddBirthPos();
            }
            GUI.backgroundColor = Color.white;
            EditorGUILayout.EndHorizontal();
            LevelBirthPosition[] births = GameObject.FindObjectsOfType<LevelBirthPosition>();
            EditorGUILayout.LabelField("所有出生点", GUILayout.Width(100));
            for (int i = 0; i < births.Length; i++)
            {
                EditorGUILayout.BeginHorizontal();
                EditorGUILayout.ObjectField(births[i], typeof(LevelBirthPosition), true);
                if (GUILayout.Button("删除"))
                {
                    GameObject.DestroyImmediate(births[i].gameObject);
                }
                EditorGUILayout.EndHorizontal();
            }
            #endregion
        }
    }

  
    public void OnGUIPath(LevelToolEditorType type)
    {
        if (type == LevelToolEditorType.Path)
        {
            #region
            //buttons
            EditorGUILayout.BeginHorizontal();

            GUI.backgroundColor = Color.yellow;
            if (GUILayout.Button("创建路径"))
            {
                OnAddPath();
            }
            GUI.backgroundColor = Color.white;
            EditorGUILayout.EndHorizontal();

            currentPath = (LevelPath)EditorGUILayout.ObjectField("当前编辑路径", currentPath, typeof(LevelPath), true);
            EditorGUILayout.BeginHorizontal();
            EditorGUILayout.LabelField("所有路径", GUILayout.Width(100));
            LevelPath[] paths = GameObject.FindObjectsOfType<LevelPath>();

            if (GUILayout.Button("全选"))
            {
                foreach (var k in paths)
                {
                    k.show = true;
                }
            }
            if (GUILayout.Button("反选"))
            {
                foreach (var k in paths)
                {
                    k.show = false;
                }
            }

            EditorGUILayout.EndHorizontal();

            pathScollpos = EditorGUILayout.BeginScrollView(pathScollpos);

            foreach (var k in paths)
            {
                LevelPathData lpd = (LevelPathData)k.GetData();
                EditorGUILayout.BeginHorizontal();
                k.show = EditorGUILayout.Toggle(k.show, GUILayout.Width(20));
                EditorGUILayout.LabelField(lpd.name);
                EditorGUILayout.ObjectField(k, typeof(LevelPath), true);
                if (k.show)
                {
                    LevelCommonFunc.OnVisibleNode(lpd, k.show);
                    currentPath = k;

                    if (GUILayout.Button("增加节点"))
                    {
                        OnSelectPathNode(0);
                    }

                    if (GUILayout.Button("删除"))
                    {
                        LevelCommonFunc.OnDestoryPath(k);
                    }
                }
                else
                {
                    //currentPath = null;

                    LevelCommonFunc.OnVisibleNode(lpd, k.show);
                }
                EditorGUILayout.EndHorizontal();

            }
            EditorGUILayout.EndScrollView();

            #endregion
        }
    }

    void Start()
    {

        foreach (var k in Config.tagCns)
        {
            tags.Add(k);
        }

        guiFunc += OnGUIBatch;
        guiFunc += OnGUIArea;
        guiFunc += OnGUIBirthPos;

        guiFunc += OnGUIPath;
        guiFunc += OnGUIMode;




        sceneNames.AddRange(LevelCommonFunc.GetDirectoryNames(Config.scenePath));
        dataNames.AddRange(LevelCommonFunc.GetFileNames(Config.dataPath, "*.asset"));
        pathNames.AddRange(LevelCommonFunc.GetFileNames(Config.pathNodePath, "*.prefab"));
        batchNames.AddRange(LevelCommonFunc.GetFileNames(Config.batchPath, "*.prefab"));
        doorNames.AddRange(LevelCommonFunc.GetFileNames(Config.doorPath, "*.prefab"));

        InitEditorGUIGrid();
        InitPathNode();
        InitTriggle();
        InitDoor();


        pathTextures.AddRange(GenPreviewTexture(pathObjects));
        batchTextures.AddRange(GenPreviewTexture(batchObjects));
        doorTextures.AddRange(GenPreviewTexture(doorObjects));

        //stuffs.Add(LevelInitMonster.Instance.gameObject);
    }

    void InitDoor()
    {
        foreach (string name in doorNames)
        {
            string path = Config.doorPathAssets + name;
            GameObject go = AssetDatabase.LoadAssetAtPath(path, typeof(GameObject)) as GameObject;
            doorObjects.Add(go);
        }

    }

    void InitTriggle()
    {

        //batchDatas.Add(new LevelTriggleData(LevelCommonFunc.GetID(), "简单触发器"));



        foreach (string name in batchNames)
        {
            string path = Config.batchPathAssets + name;
            GameObject go = AssetDatabase.LoadAssetAtPath(path, typeof(GameObject)) as GameObject;
            batchObjects.Add(go);
        }
    }

    void InitPathNode()
    {
        pathNodeDatas.Add(new LevelPathNodeData("点", LevelPathNodeData.NodeType.Start));
        pathNodeDatas.Add(new LevelPathNodeData("点", LevelPathNodeData.NodeType.Middle));
        pathNodeDatas.Add(new LevelPathNodeData("点", LevelPathNodeData.NodeType.End));


        foreach (string name in pathNames)
        {
            string path = Config.pathNodePathAssets + name;
            GameObject go = AssetDatabase.LoadAssetAtPath(path, typeof(GameObject)) as GameObject;
            pathObjects.Add(go);
        }
    }

    void InitEditorGUIGrid()
    {
       
    }

    public List<Texture2D> GenPreviewTexture(List<GameObject> gos)
    {
        List<Texture2D> tes = new List<Texture2D>();
        foreach (GameObject go in gos)
        {
            Texture2D t = AssetPreview.GetAssetPreview(go);

            tes.Add(t);
        }

        return tes;
    }

    // Update is called once per frame
    void Update()
    {
        if (Selection.activeGameObject)
        {
            LevelObjectBase m = Selection.activeGameObject.GetComponentInChildren<LevelObjectBase>();
            if (!m)
                m = Selection.activeGameObject.GetComponentInParent<LevelObjectBase>();
            if (!m)
                m = Selection.activeGameObject.GetComponent<LevelObjectBase>();
            if (m)
            {
                Selection.activeGameObject = m.gameObject;
                LevelDetailWindow.Init(m);
            }
        }


    }


    protected void OnGUI()
    {
        GUI.contentColor = Color.yellow;
        EditorGUILayout.LabelField("场景编辑版本号：" + Config.version);
        GUI.contentColor = Color.white;

        //load scene
        EditorGUILayout.BeginHorizontal();
        EditorGUILayout.LabelField("选择场景");
        sceneIndex = EditorGUILayout.Popup(sceneIndex, sceneNames.ToArray());
        if (GUILayout.Button("加载场景"))
        {
            string unitySceneName = Config.scenePathAssets + sceneNames[sceneIndex] + "/" + sceneNames[sceneIndex] + ".unity";
            Debug.Log(unitySceneName);
            LevelCommonFunc.OpenScene(unitySceneName);
        }
        EditorGUILayout.EndHorizontal();

        if (isOpenData)
        {
            EditorGUILayout.BeginHorizontal();
            EditorGUILayout.LabelField("选择数据");
            

            EditorGUILayout.LabelField(dataName);

            if (GUILayout.Button("加载数据"))
            {
                OnLoadDataAsset();
            }

            EditorGUILayout.EndHorizontal();
        }

        


        EditorGUILayout.BeginHorizontal();
        
        if (GUILayout.Button("新建!"))
        {
            OnCreateDataAsset();
        }
        GUI.backgroundColor = Color.green;

        if (GUILayout.Button("保存!"))
        {
            OnSaveDataAsset();
        }
        GUI.backgroundColor = Color.white;
        EditorGUILayout.EndHorizontal();

        //tag
        EditorGUILayout.BeginHorizontal();
        
        tagIndex = GUILayout.SelectionGrid(tagIndex, tags.ToArray(), tags.Count);
        EditorGUILayout.EndHorizontal();

        LevelToolEditorType t = (LevelToolEditorType)tagIndex;
        guiFunc(t);
        


    }


    protected void DrawPath()
    {
        LevelPath[] paths = GameObject.FindObjectsOfType<LevelPath>();


        for (int i = 0; i < paths.Length; i++)
        {

            LevelPathData data = (LevelPathData)paths[i].GetData();

            if (paths[i].show)
            {

                Handles.color = paths[i].color;
                Handles.DrawPolyLine(data.GetPoints());

                
            }
        }
    }





   

    


    public void OnAddBirthPos()
    {
        LevelBirthPosition path = LevelCommonFunc.AddLevelObject(typeof(LevelBirthPosition), currentBirthName, new LevelBirthPositionData(), pathObjects[1]) as LevelBirthPosition;
        if (!path) return;
        stuffs.Add(path.gameObject);
    }

    public void OnAddArea()
    {
        LevelArea path = LevelCommonFunc.AddLevelObject(typeof(LevelArea), currentAreaName, new LevelAreaData(), pathObjects[2]) as LevelArea;
        LevelArea[] areas = GameObject.FindObjectsOfType<LevelArea>();
        path.GetData().name = "区域" + areas.Length;
        path.name = path.GetData().name;
        if (!path) return;
        stuffs.Add(path.gameObject);

    }

    public void OnAddPath()
    {

        LevelPath path = LevelCommonFunc.AddLevelObject(typeof(LevelPath), null, new LevelPathData()) as LevelPath;
        if (!path) return;
        stuffs.Add(path.gameObject);

    }


    public void OnSelectPathNode(int index)
    {
        if (currentPath == null) return;

        if (index >= 0 && index < pathObjects.Count)
        {

            GameObject go = Instantiate(pathObjects[index]);
            LevelPathNode node = go.AddComponent<LevelPathNode>();
            LevelPathNodeData data = new LevelPathNodeData();

            data.pos = startPosition;
            data.scale = go.transform.localScale;
            data.dir = go.transform.eulerAngles;
            data.editorID = LevelCommonFunc.GetID();
            data.ID = data.editorID;
            data.name = "点" + data.editorID;

            node.SetData(data);

            go.transform.position = startPosition;
            go.name = data.name;

            ((LevelPathData)currentPath.GetData()).AddNode((LevelPathNodeData)node.GetData());
            stuffs.Add(go);
            Event.current.Use();

        }

    }



    public void OnSelectDoor(int index)
    {

        if (Event.current.clickCount == 2 && Event.current.mousePosition.y > lineHeader && (Event.current.mousePosition.y < (batchTextures.Count / 3 + 1) * 100 + lineHeight) && Event.current.type == EventType.Layout)
        {
            if (index >= 0 && index < doorObjects.Count)
            {
                LevelDoorData lbd = new LevelDoorData();
                lbd.index = index;
                LevelDoor lb = LevelCommonFunc.AddLevelObject(typeof(LevelDoor), null, lbd, doorObjects[index]) as LevelDoor;

                stuffs.Add(lb.gameObject);

            }
        }
    }

    public void OnSelectBatch(int index)
    {

        if (Event.current.clickCount == 2 && Event.current.mousePosition.y > lineHeader && (Event.current.mousePosition.y < (batchTextures.Count / 3 + 1) * lineHeight + lineHeader) && Event.current.type == EventType.Layout)
        {
            if (index >= 0 && index < batchObjects.Count)
            {
                LevelBatchData lbd = new LevelBatchData();
                LevelBatch lb = LevelCommonFunc.AddLevelObject(typeof(LevelBatch), null, lbd, batchObjects[index]) as LevelBatch;
                lbd.index = GameObject.FindObjectsOfType<LevelBatch>().Length;
                lbd.name = "波次" + lbd.index;
                lb.name = lbd.name;
                stuffs.Add(lb.gameObject);

            }
        }
    }




    public void OnSaveDataAsset()
    {
        string path = EditorUtility.SaveFilePanel("保存位置", Config.dataPath, "NewData", "asset");

        if (string.IsNullOrEmpty(path))
        {
            if (EditorUtility.DisplayDialog("文件不存在", "文件不存在", "确认"))
            {
                return;
            }
        }
        dataName = LevelCommonFunc.GetLastName(path);
      
        if (string.IsNullOrEmpty(dataName))
        {
            OnCreateDataAsset();
        }
        else
        {

            if (System.IO.File.Exists(Config.dataPath + dataName))
            {
                 System.IO.File.Delete(Config.dataPath + dataName);
            }

            AssetDatabase.Refresh();
            AssetDatabase.Refresh(ImportAssetOptions.ForceSynchronousImport);
            isSaved = true;
            LevelCommonFunc.SaveMap(LevelObjectBase.GetAllBaseDatas(), Config.dataPathAssets, dataName);

        }
    }

    public void OnCreateDataAsset()
    {

        string path = EditorUtility.SaveFilePanelInProject("保存", "NewData.asset", "asset", "保存地图配置", Config.dataPath);
        dataName = LevelCommonFunc.GetLastName(path);
        if (!string.IsNullOrEmpty(dataName))
        {
            LevelCommonFunc.SaveMap(LevelObjectBase.GetAllBaseDatas(), Config.dataPathAssets, dataName);
        }
        else
        {
            EditorGUILayout.HelpBox("文件名称不能为空", MessageType.Error);
            Debug.LogError("文件名称不能为空");
        }
    }


    public void OnLoadPathDatas(LevelMapData mapData)
    {
        foreach (LevelPathData p in mapData.pathDatas)
        {
            foreach (LevelPathNodeData n in p.nodes)
            {
                string name = "green.prefab";
                switch (n.type)
                {
                    case LevelPathNodeData.NodeType.Start:
                        name = "green.prefab";
                        break;
                    case LevelPathNodeData.NodeType.Middle:
                        name = "red.prefab";
                        break;
                    case LevelPathNodeData.NodeType.End:
                        name = "yellow.prefab";
                        break;
                }
                GameObject go = GameObject.Instantiate(AssetDatabase.LoadAssetAtPath(Config.pathNodePathAssets + name, typeof(GameObject))) as GameObject;
                go.AddComponent<LevelPathNode>().SetData(n);
                go.transform.position = n.pos;
                go.transform.eulerAngles = n.dir;
                go.transform.localScale = n.scale;
                stuffs.Add(go);
            }

            GameObject path = new GameObject(p.name);

            path.AddComponent<LevelPath>().SetData(p);

            stuffs.Add(path);
        }
    }

    public void OnLoadBatchDatas(LevelMapData mapData)
    {
        foreach (LevelBatchData b in mapData.batchDatas)
        {

            name = "redball.prefab";

            GameObject batch = GameObject.Instantiate(AssetDatabase.LoadAssetAtPath(Config.batchPathAssets + name, typeof(GameObject))) as GameObject;
            batch.AddComponent<LevelBatch>().SetData(b);
            batch.transform.position = b.pos;
            batch.transform.eulerAngles = b.dir;
            batch.transform.localScale = b.scale;
            batch.name = b.name;

            stuffs.Add(batch);

            foreach (var e in b.events)
            {
                if (e.cond.type == TriggerCondition.Type.KillMonster)
                    e.cond.selectMonster = LevelCommonFunc.FindLevelObjectByID(typeof(LevelMonster), e.cond.targetID) as LevelMonster;
                if (e.cond.type == TriggerCondition.Type.KillGroup)
                    e.cond.selectGroup = LevelCommonFunc.FindLevelObjectByID(typeof(LevelBatch), e.cond.targetID) as LevelBatch;
                if (e.cond.type == TriggerCondition.Type.MoveToArea)
                    e.cond.selectArea = LevelCommonFunc.FindLevelObjectByID(typeof(LevelArea), e.cond.areaID) as LevelArea;
                if (e.action.type == TriggerAction.Type.SpawnMonster)
                    e.action.selectMonster = LevelCommonFunc.FindLevelObjectByID(typeof(LevelMonster), e.action.editorID) as LevelMonster;
            }



            //foreach (LevelMonsterData bd in b.monsters)
            //{
            //    LevelMonsterData d = bd as LevelMonsterData;
            //    name = Tank.Get(Monster.Get(d.ID).EntityID).ModelID + ".prefab";
            //    GameObject monster = GameObject.Instantiate(AssetDatabase.LoadAssetAtPath(monsterPathAssets + name, typeof(GameObject))) as GameObject;
            //    monster.AddComponent<LevelMonster>().SetData(d.Clone());
            //    monster.transform.position = d.pos;
            //    monster.transform.eulerAngles = d.dir;
            //    monster.name = d.name;
            //    stuffs.Add(monster);
            //    batch.GetComponent<LevelBatch>().monsters.Add(monster.GetComponent<LevelMonster>());
            //}
        }
    }


    public void OnLoadAreaDatas(LevelMapData mapData)
    {
        foreach (var d in mapData.areaDatas)
        {
            string name = "green.prefab";

            GameObject monster = GameObject.Instantiate(AssetDatabase.LoadAssetAtPath(Config.pathNodePathAssets + name, typeof(GameObject))) as GameObject;
            monster.AddComponent<LevelArea>().SetData(d.Clone());

            monster.transform.position = d.pos;
            monster.transform.eulerAngles = d.dir;
            monster.name = d.name;
            stuffs.Add(monster);

        }

        //extra find area

        LevelArea[] areas = GameObject.FindObjectsOfType<LevelArea>();
        foreach (var key in areas)
        {
            foreach (LevelAreaData data in (key.GetData() as LevelAreaData).nextAreas)
            {
                key.areas.Add(GameObject.Find(data.name).GetComponent<LevelArea>());
            }
        }
    }

    public void OnLoadBirthDatas(LevelMapData mapData)
    {
        foreach (var b in mapData.birthDatas)
        {
            string name = "red.prefab";

            GameObject go = GameObject.Instantiate(AssetDatabase.LoadAssetAtPath(Config.pathNodePathAssets + name, typeof(GameObject))) as GameObject;
            go.AddComponent<LevelBirthPosition>().SetData(b);
            go.name = b.name;
            go.transform.position = b.pos;
            go.transform.eulerAngles = b.dir;
            go.transform.localScale = b.scale;
            stuffs.Add(go);
        }
    }





    public void OnLoadModeData(LevelMapData mapData)
    {
        
        modeData = mapData.modeData;

        mapData.modeData.condition1Star.selectMonsters.Clear();

        foreach (LevelMonsterData bd in mapData.modeData.condition1Star.selectMonsterDatas)
        {
            LevelMonster m = (LevelMonster)LevelCommonFunc.FindLevelObjectByID(typeof(LevelMonster), bd.editorID);
            if(m != null)
            {
                if (!mapData.modeData.condition1Star.selectMonsters.Contains(m))
                    mapData.modeData.condition1Star.selectMonsters.Add(m);
            }
        }

        

    }

  


    public void OnLoadDoorDatas(LevelMapData mapData)
    {
        foreach (var b in mapData.doorDatas)
        {
            //string name = "yellow.prefab";
            //AssetDatabase.LoadAssetAtPath(doorPathAsset + name, typeof(GameObject))
            GameObject go = GameObject.Instantiate(doorObjects[b.index]) as GameObject;
            go.AddComponent<LevelDoor>().SetData(b);
            go.name = b.name;
            go.transform.position = b.pos;
            go.transform.eulerAngles = b.dir;
            go.transform.localScale = b.scale;
            stuffs.Add(go);
        }
    }

    public void OnLoadDataAsset()
    {
        OnDestroyStuff();
        string path = EditorUtility.OpenFilePanel("打开位置", Config.dataPathAssets, "asset");
        if (string.IsNullOrEmpty(path)) return;
        dataName = LevelCommonFunc.GetLastName(path);
        LevelMapData mapData = LevelCommonFunc.LoadMap(Config.dataPathAssets + dataName);

        OnLoadPathDatas(mapData);
        
        OnLoadAreaDatas(mapData);
        OnLoadBirthDatas(mapData);
        OnLoadDoorDatas(mapData);
        OnLoadBatchDatas(mapData);
        OnLoadModeData(mapData);
    }


    public void OnDestroyStuff()
    {
        foreach (GameObject go in stuffs)
        {
            GameObject.DestroyImmediate(go);
        }
        stuffs.Clear();

        modeData = null;
    }

    public void OnDestroy()
    {

        if (EditorUtility.DisplayDialog("提示", "需要保存吗？", "确定", "取消"))
        {
            OnSaveDataAsset();
        }

        if (GameObject.FindObjectOfType<AssetScene>())
            GameObject.DestroyImmediate(GameObject.FindObjectOfType<AssetScene>().gameObject);
        if (GameObject.FindObjectOfType<ResManager>())
            GameObject.DestroyImmediate(GameObject.FindObjectOfType<ResManager>().gameObject);


        OnDestroyStuff();
        SceneView.onSceneGUIDelegate -= OnSceneFunc;

        if (LevelDetailWindow.instance != null)
            LevelDetailWindow.instance.Close();

    }
}
