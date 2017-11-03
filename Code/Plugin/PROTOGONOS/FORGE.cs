using UnityEngine;
using UnityEditor;
using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;


/// <summary>
/// 关卡编辑
/// </summary>
public class FORGE 
{
    /// <summary>
    /// 格子
    /// </summary>
    class Cell
    {
        public int level;
        public float bulletDmgCoef;
        public float exploDmgCoef;
        public bool halfCull;
        public string dynamicGo;
        public bool force;
    }
    private Cell[,] cells;

    enum EditMode
    {
        None,
        Brush,
    };

    enum SceneObjType
    {
        Invalid = 0,
        Wall = 1,
        Gate,
        Destruct,
        BuffItem,
        Shop,
        Portal,
        //DestructBuff, //场景掉落Buff点
        //Gold,          //场景钱罐
        FlagPoint,
		Bounty,
    }
    private int editMode;

    /// <summary>网格原点</summary>
    private Vector2 origin;
    /// <summary>行数</summary>
    private int rowCount = 50;
    /// <summary>列数</summary>
    private int colCount = 50;
    /// <summary>格子大小</summary>
    private float cellSize = 0.5f;
    /// <summary>显示网格</summary>
    private bool showGrid = true;
    /// <summary>预览</summary>
    private bool preview = true;
    /// <summary>文件名</summary>
    private string filename = string.Empty;
    /// <summary>鼠标指向的格子中心坐标</summary>
    private Vector3 hoverPos;
    /// <summary>预览用的四个坐标点</summary>
    private Vector3[] previewCorners = new Vector3[4];
    /// <summary>穿透格子的预览颜色</summary>
    private Color cellColor = new Color(0.93f, 0.49f, 0.19f, 0.5f);
    /// <summary>地面</summary>
    private Plane ground = new Plane(Vector3.up, Vector3.zero);
    /// <summary>相交检测阈值</summary>
    private float epsilon = 0.2f;
    /// <summary>画刷</summary>
    private static Cell[] brushes = new Cell[2];
    private const string dynamicColFilePostfix = "_Shape";

    static FORGE()
    {
        brushes[0] = new Cell();
        brushes[1] = new Cell();
        brushes[0].level = 0;
        brushes[1].level = 100;
    }

    public void DrawGUI(EditorWindow wnd)
    {   
        int controlID = GUIUtility.GetControlID(FocusType.Passive);
        switch (Event.current.GetTypeForControl(controlID))
        {
            case EventType.KeyDown:
                if (Event.current.keyCode == KeyCode.X)
                {
                    Cell temp = brushes[0];
                    brushes[0] = brushes[1];
                    brushes[1] = temp;
                    Event.current.Use();
                }
                else if (Event.current.keyCode == KeyCode.LeftAlt)
                {

                }
                break;

            case EventType.KeyUp:
                if (Event.current.keyCode == KeyCode.LeftAlt)
                {

                }
                break;

            default:
                break;
        }
        //====================================================================
        // 文件相关
        GUILayout.BeginHorizontal();
        //if (GUILayout.Button("NEW", EditorStyles.toolbarButton))
        //{
        //    New();
        //}
        //if (GUILayout.Button("OPEN", EditorStyles.toolbarButton))
        //{
        //    Open();
        //}
        //if (GUILayout.Button("SAVE", EditorStyles.toolbarButton))
        //{
        //    Save();
        //}
        if (GUILayout.Button("Export Static Collider", EditorStyles.toolbarButton))
        {
            //Export();
            ExportStatic();
        }
        if (GUILayout.Button("Export Scene Object", EditorStyles.toolbarButton))
        {
            //Export();
            ExportSceneObj();
        }
        GUILayout.EndHorizontal();

        //====================================================================
        // 如果当前文件不存在，后续的GUI不显示
        if (string.IsNullOrEmpty(filename))
            return;

        //====================================================================
        // 关卡相关
        GUILayout.Label("Level Size", EditorStyles.boldLabel);
        // 网格原点坐标，行数和列数不可修改
        GUILayout.Label(string.Format("Origin x: {0}, y: {1}", origin.x, origin.y));
        GUILayout.Label(string.Format("Row count: {0}", rowCount));
        GUILayout.Label(string.Format("Col count: {0}", colCount));
        // 网格大小
        cellSize = EditorGUILayout.FloatField("Cell Size", cellSize);
        // 自适应创建网格
        if (GUILayout.Button("Generate cells", EditorStyles.miniButtonMid))
        {
            if (PROTOGONOS.Instance.gaia == null || !PROTOGONOS.Instance.gaia.IsValid)
                EditorUtility.DisplayDialog("错误", "GAIA没有加载", "确定");
            else
                GenerateCells();
        }
        // 自动设置数据
        epsilon = EditorGUILayout.FloatField("Epsilon", epsilon);
        if (GUILayout.Button("Clear setting", EditorStyles.miniButtonMid))
        {
            CreateCells();
        }
        if (GUILayout.Button("Auto setting", EditorStyles.miniButtonMid))
        {
            AutoSetting();
        }

        //====================================================================
        // 网格设定
        GUILayout.Label("Grid Setting", EditorStyles.boldLabel);
        // 是否显示网格
        showGrid = EditorGUILayout.Toggle("Show Grid", showGrid);
        // 是否预览
        preview = EditorGUILayout.Toggle("Preview", preview);

        //====================================================================
        // 编辑相关
        GUILayout.Label("Edit Mode", EditorStyles.boldLabel);
        // 选择当前的编辑模式
        editMode = GUILayout.Toolbar(editMode, new string[] {
            EditMode.None.ToString(),
            EditMode.Brush.ToString(),
        });
        // 画刷模式
        if (editMode == (int)EditMode.Brush)
        {
            GUILayout.Label("Press 'X' to swap brush", EditorStyles.boldLabel);
            int row = (int)((hoverPos.z - origin.y + cellSize * 0.5f) / cellSize);
            int col = (int)((hoverPos.x - origin.x + cellSize * 0.5f) / cellSize);
            if (row >= 0 && row < rowCount && col >= 0 && col < colCount)
            {
                GUILayout.Label("Detail", EditorStyles.boldLabel);
                GUILayout.Label(string.Format("X: {0}, Y: {1}", row, col));
                GUILayout.Label("Penetration: " + cells[row, col].level);
                GUILayout.Label("Attenuation: " + cells[row, col].bulletDmgCoef);
                GUILayout.Label("Half Wall: " + cells[row, col].halfCull);
                wnd.Repaint();
            }
            GUILayout.Space(10);
            GUILayout.BeginVertical();

            GUILayout.BeginHorizontal();
            GUILayout.Label("Current", EditorStyles.boldLabel);
            GUILayout.Space(10);
            GUILayout.Label("Previous", EditorStyles.boldLabel);
            GUILayout.EndHorizontal();

            GUILayout.BeginHorizontal();
            if (brushes[0].level == 0)
                GUI.color = Color.clear;
            else
                GUI.color = Color.Lerp(new Color(0, 0, 1, 0.5f), new Color(1, 0, 0, 0.5f), brushes[0].level / 100.0f);
            GUILayout.Button("", EditorStyles.toolbarButton);
            GUILayout.Space(10);
            if (brushes[1].level == 0)
                GUI.color = Color.clear;
            else
                GUI.color = Color.Lerp(new Color(0, 0, 1, 0.5f), new Color(1, 0, 0, 0.5f), brushes[1].level / 100.0f);
            GUILayout.Button("", EditorStyles.toolbarButton);
            GUI.color = Color.white;
            GUILayout.EndHorizontal();

            GUILayout.BeginHorizontal();
            brushes[0].level = EditorGUILayout.IntField("Level", brushes[0].level);
            GUILayout.Space(10);
            brushes[1].level = EditorGUILayout.IntField("Level", brushes[1].level);
            GUILayout.EndHorizontal();

            GUILayout.BeginHorizontal();
            brushes[0].bulletDmgCoef = EditorGUILayout.FloatField("Bullet Coef", brushes[0].bulletDmgCoef);
            GUILayout.Space(10);
            brushes[1].bulletDmgCoef = EditorGUILayout.FloatField("Bullet Coef", brushes[1].bulletDmgCoef);
            GUILayout.EndHorizontal();

            GUILayout.BeginHorizontal();
            brushes[0].exploDmgCoef = EditorGUILayout.FloatField("Bomb Coef", brushes[0].exploDmgCoef);
            GUILayout.Space(10);
            brushes[1].exploDmgCoef = EditorGUILayout.FloatField("Bomb Coef", brushes[1].exploDmgCoef);
            GUILayout.EndHorizontal();

            GUILayout.BeginHorizontal();
            brushes[0].halfCull = EditorGUILayout.Toggle("Half Cull", brushes[0].halfCull);
            GUILayout.Space(10);
            brushes[1].halfCull = EditorGUILayout.Toggle("Half Cull", brushes[1].halfCull);
            GUILayout.EndHorizontal();

            GUILayout.EndVertical();
        }
    }

    /// <summary>
    /// 绘制编辑场景
    /// </summary>
    /// <param name="sceneView"></param>
    public void DrawSceneGUI(SceneView sceneView)
    {
        // 绘制网格
        if (showGrid)
        {
            Vector3 from = new Vector3();
            Vector3 to = new Vector3();

            // 绘制行
            for (int i = 0; i <= rowCount; ++i)
            {
                from.Set(origin.x, 0.0f, origin.y + i * cellSize);
                to.Set(origin.x + colCount * cellSize, 0.0f, origin.y + i * cellSize);

                Vector3 screenPos = sceneView.camera.WorldToScreenPoint(from);
                if (screenPos.y < 0.0f || screenPos.y > sceneView.position.yMax)
                    continue;

                Handles.color = new Color(0.0f, 1.0f, 0.0f, 0.25f);
                Handles.DrawLine(from, to);
            }

            // 绘制列
            for (int i = 0; i <= colCount; ++i)
            {
                from.Set(origin.x + i * cellSize, 0.0f, origin.y);
                to.Set(origin.x + i * cellSize, 0.0f, origin.y + rowCount * cellSize);

                Vector3 screenPos = sceneView.camera.WorldToScreenPoint(from);
                if (screenPos.x < 0.0f || screenPos.x > sceneView.position.xMax)
                    continue;

                Handles.color = new Color(0.0f, 1.0f, 0.0f, 0.25f);
                Handles.DrawLine(from, to);
            }
        }

        // 绘制预览
        if (preview && cells != null)
        {
            for (int i = 0; i < rowCount; ++i)
            {
                Vector3 rowTop = sceneView.camera.WorldToScreenPoint(new Vector3(0, 0, i * cellSize + origin.y));
                Vector3 rowBottom = sceneView.camera.WorldToScreenPoint(new Vector3(0, 0, i * cellSize + cellSize + origin.y));
                if (rowBottom.y < 0.0f || rowTop.y > sceneView.position.yMax)
                    continue;

                for (int j = 0; j < colCount; ++j)
                {
                    if (cells[i, j].level == 0)
                        continue;

                    // 坐标点需要加上原点偏移
                    previewCorners[0].x = j * cellSize + origin.x;
                    previewCorners[0].z = i * cellSize + origin.y;
                    previewCorners[1].x = j * cellSize + origin.x;
                    previewCorners[1].z = i * cellSize + cellSize + origin.y;
                    previewCorners[2].x = j * cellSize + cellSize + origin.x;
                    previewCorners[2].z = i * cellSize + cellSize + origin.y;
                    previewCorners[3].x = j * cellSize + cellSize + origin.x;
                    previewCorners[3].z = i * cellSize + origin.y;

                    Vector3 colLeft = sceneView.camera.WorldToScreenPoint(new Vector3(j * cellSize + origin.x, 0, 0));
                    Vector3 colRight = sceneView.camera.WorldToScreenPoint(new Vector3(j * cellSize + cellSize + origin.x, 0, 0));
                    if (colRight.x < 0.0f || colLeft.x > sceneView.position.xMax)
                        continue;

                    Handles.color = Color.Lerp(new Color(0, 0, 1, 0.5f), new Color(1, 0, 0, 0.5f), cells[i, j].level / 100.0f);
                    Handles.DrawSolidRectangleWithOutline(previewCorners, cellColor, cellColor);
                    Handles.color = Color.white;
                }
            }
        }

        // 高亮选中
        if (Selection.activeGameObject != null)
        {
            Collider collider = Selection.activeGameObject.GetComponent<Collider>();
            if (collider != null)
            {
                // 绘制吸附提示
                Vector3[] corners = GetCorners(collider.bounds, true);
                Handles.color = Color.yellow;
                Handles.DrawAAPolyLine(5.0f, corners);
            }
        }

        // 编辑模式
        if (editMode == (int)EditMode.Brush)
        {
            Event e = Event.current;
            if (e.type == EventType.MouseMove)
            {
                hoverPos = GetMousePosOnGround(e.mousePosition);
                // 减去原点坐标，相对于格子原点
                hoverPos.x -= origin.x;
                hoverPos.z -= origin.y;
                // 格子的中心(左下角)
                hoverPos.x = (int)(hoverPos.x / cellSize) * cellSize;
                hoverPos.z = (int)(hoverPos.z / cellSize) * cellSize;
                // 再加上原点坐标的偏移
                hoverPos.x += origin.x;
                hoverPos.z += origin.y;
            }

            // 点击鼠标左键
            if (e.type == EventType.MouseDown && e.button == 0)
            {
                HandleUtility.AddDefaultControl(GUIUtility.GetControlID(FocusType.Passive));
                int row = (int)((hoverPos.z - origin.y + cellSize * 0.5f) / cellSize);
                int col = (int)((hoverPos.x - origin.x + cellSize * 0.5f) / cellSize);

                cells[row, col].level = brushes[0].level;
                cells[row, col].bulletDmgCoef = brushes[0].bulletDmgCoef;
                cells[row, col].exploDmgCoef = brushes[0].exploDmgCoef;
                cells[row, col].halfCull = brushes[0].halfCull;
                sceneView.Repaint();
            }

            // 绘制指向的格子
            DrawHighlightCell(hoverPos, Color.red);
        }
        else
        {
            HandleUtility.Repaint();
        }

        SceneView.RepaintAll();
    }

    /// <summary>
    /// 自适应创建网格
    /// </summary>
    void GenerateCells()
    {
        // 查找静态碰撞体的父节点
        List<BlockParam> blocks = new List<BlockParam>();

        GameObject artGo = GameObject.Find(PROTOGONOS.Instance.gaia.ArtLevelName);
        blocks.AddRange(artGo.GetComponentsInChildren<BlockParam>());

        GameObject designGo = GameObject.Find(PROTOGONOS.Instance.gaia.DesignLevelName);
        blocks.AddRange(designGo.GetComponentsInChildren<BlockParam>());

        // 遍历所有BoxCollider和SphereCollider，计算最大最小坐标
        float minX = System.Single.MaxValue;
        float maxX = System.Single.MinValue;
        float minZ = System.Single.MaxValue;
        float maxZ = System.Single.MinValue;

        foreach (BlockParam block in blocks)
        {
            Collider c = block.GetComponent<Collider>();
            if (c == null)
                continue;

            if (c.bounds.min.x < minX) minX = c.bounds.min.x;
            if (c.bounds.max.x > maxX) maxX = c.bounds.max.x;
            if (c.bounds.min.z < minZ) minZ = c.bounds.min.z;
            if (c.bounds.max.z > maxZ) maxZ = c.bounds.max.z;
        }

        // 上下左右各增加5个格子的余量
        origin.x = minX - 5 * cellSize;
        origin.y = minZ - 5 * cellSize;
        rowCount = (int)((maxZ - minZ) / cellSize) + 10;
        colCount = (int)((maxX - minX) / cellSize) + 10;

        CreateCells();
    }

    /// <summary>
    /// 自动设置穿透属性
    /// </summary>
    void AutoSetting()
    {
        CreateCells();

        List<BlockParam> artBlocks = new List<BlockParam>();
        GameObject artGo = GameObject.Find(PROTOGONOS.Instance.gaia.ArtLevelName);
        artBlocks.AddRange(artGo.GetComponentsInChildren<BlockParam>());

        List<BlockParam> designBlocks = new List<BlockParam>();
        GameObject designGo = GameObject.Find(PROTOGONOS.Instance.gaia.DesignLevelName);
        designBlocks.AddRange(designGo.GetComponentsInChildren<BlockParam>());

        Vector2 min = new Vector3();
        Vector2 max = new Vector3();
        Vector2[] corners = new Vector2[4];

        int totalCount = rowCount * colCount;
        int count = 0;
        for (int i = 0; i < rowCount; ++i)
        {
            for (int j = 0; j < colCount; ++j)
            {
                ++count;
                EditorUtility.DisplayProgressBar("Auto setting", string.Format("setting...({0}/{1})", count, totalCount), (float)count / totalCount);
                // 格子左下角需要加上原点的偏移
                min.x = j * cellSize + origin.x;
                min.y = i * cellSize + origin.y;
                max.x = min.x + cellSize;
                max.y = min.y + cellSize;

                corners[0].Set(min.x, min.y);
                corners[1].Set(min.x, max.y);
                corners[2].Set(max.x, max.y);
                corners[3].Set(max.x, min.y);

                BlockParam block;
                block = IntersectCell(corners, artBlocks);
                if (block != null)
                {
                    cells[i, j].level = (int)block.blockMove;
                    cells[i, j].bulletDmgCoef = block.blockMove;
                    cells[i, j].exploDmgCoef = block.blockMove;
                    cells[i, j].halfCull = false;
                    continue;
                }

                block = IntersectCell(corners, designBlocks);
                if (block != null)
                {
                    cells[i, j].level = (int)block.blockMove;
                    cells[i, j].bulletDmgCoef = block.blockMove;
                    cells[i, j].exploDmgCoef = block.blockMove;
                    cells[i, j].halfCull = false;
                    cells[i, j].dynamicGo = PlatoUtil.GetFullName(block.gameObject);
                }
            }
        }
        EditorUtility.ClearProgressBar();
    }

    /// <summary>
    /// 判断格子是否和碰撞体相交
    /// </summary>
    /// <param name="corners">格子的四个坐标点</param>
    /// <returns>返回阻挡属性</returns>
    BlockParam IntersectCell(Vector2[] corners, List<BlockParam> blocks)
    {
        foreach (BlockParam block in blocks)
        {
            Collider c = block.GetComponent<Collider>();
            if (c == null)
                continue;

            // 盒形碰撞体
            if (c is BoxCollider)
            {
                OBB obb = new OBB(c as BoxCollider);
                if (obb.IsCollidWithOBB(new OBB(corners), epsilon))
                    return block;
            }
            // 圆形碰撞体
            else if (c is SphereCollider || c is CapsuleCollider)
            {
                Vector3 center;
                float radius;
                if (c is SphereCollider)
                {
                    center = (c as SphereCollider).center;
                    radius = (c as SphereCollider).radius;
                }
                else
                {
                    center = (c as CapsuleCollider).center;
                    radius = (c as CapsuleCollider).radius;
                }

                Bounds bounds = new Bounds();
                bounds.SetMinMax(new Vector3(corners[0].x, 0.0f, corners[0].y),
                                 new Vector3(corners[2].x, 0.0f, corners[2].y));

                // 计算圆心到格子的最近点，已经该点到圆心的距离，如果小于半径则说明相交
                Vector3 closest = bounds.ClosestPoint(center + c.transform.position);
                if (Vector3.Distance(closest, center + c.transform.position) < radius)
                    return block;
            }
        }

        return null;
    }

    bool IntersectCell(Vector2[] corners, List<Collider> blocks)
    {
        foreach (Collider c in blocks)
        {
            if (c is MeshCollider)
                continue;
            if (c.GetComponent<BlockParam>() != null)
                continue;
            if (c.isTrigger)
                continue;

            // 盒形碰撞体
            if (c is BoxCollider)
            {
                OBB obb = new OBB(c as BoxCollider);
                if (obb.IsCollidWithOBB(new OBB(corners), epsilon))
                    return true;
            }
            // 圆形碰撞体
            else if (c is SphereCollider || c is CapsuleCollider)
            {
                Vector3 center;
                float radius;
                if (c is SphereCollider)
                {
                    center = (c as SphereCollider).center;
                    radius = (c as SphereCollider).radius;
                }
                else
                {
                    center = (c as CapsuleCollider).center;
                    radius = (c as CapsuleCollider).radius;
                }

                Bounds bounds = new Bounds();
                bounds.SetMinMax(new Vector3(corners[0].x, 0.0f, corners[0].y),
                                 new Vector3(corners[2].x, 0.0f, corners[2].y));

                // 计算圆心到格子的最近点，已经该点到圆心的距离，如果小于半径则说明相交
                Vector3 closest = bounds.ClosestPoint(center + c.transform.position);
                if (Vector3.Distance(closest, center + c.transform.position) < radius)
                    return true;
            }
        }

        return false;
    }

    /// <summary>
    /// 获得AABB四个点的坐标
    /// </summary>
    /// <param name="bounds">AABB</param>
    /// <param name="loop">是否循环创建，如是会创建5个坐标点</param>
    /// <returns></returns>
    Vector3[] GetCorners(Bounds bounds, bool loop)
    {
        Vector3[] result = null;
        if (loop)
            result = new Vector3[5];
        else
            result = new Vector3[4];

        result[0].x = bounds.center.x - bounds.extents.x;
        result[0].z = bounds.center.z - bounds.extents.z;
        result[0].y = 0.0f;
        result[1].x = bounds.center.x + bounds.extents.x;
        result[1].z = bounds.center.z - bounds.extents.z;
        result[1].y = 0.0f;
        result[2].x = bounds.center.x + bounds.extents.x;
        result[2].z = bounds.center.z + bounds.extents.z;
        result[2].y = 0.0f;
        result[3].x = bounds.center.x - bounds.extents.x;
        result[3].z = bounds.center.z + bounds.extents.z;
        result[3].y = 0.0f;

        // 第五个坐标点等于起始点
        if (loop)
            result[4] = result[0];

        return result;
    }

    /// <summary>
    /// 新建文件
    /// </summary>
    void New()
    {
        filename = EditorUtility.SaveFilePanel("Create level file", "Assets", "", "level");
        if (string.IsNullOrEmpty(filename))
            return;

        // 禁用选择，不然在点击按钮后unity会莫名的移动选中物体
        Selection.activeGameObject = null;

        CreateCells();

        StreamWriter writer = new StreamWriter(filename, false, Encoding.UTF8);

        // 保存默认数据
        writer.WriteLine(origin.x);
        writer.WriteLine(origin.y);
        writer.WriteLine(rowCount);
        writer.WriteLine(colCount);
        writer.WriteLine(cellSize);

        writer.Close();
    }

    /// <summary>
    /// 打开文件
    /// </summary>
    void Open()
    {
        filename = EditorUtility.OpenFilePanel("Open level file", "Assets", "level");
        if (string.IsNullOrEmpty(filename))
            return;

        // 禁用选择，不然在点击按钮后unity会莫名的移动选中物体
        Selection.activeGameObject = null;

        StreamReader reader = new StreamReader(filename, Encoding.UTF8);

        // 读取关卡信息
        origin.x = System.Convert.ToSingle(reader.ReadLine());
        origin.y = System.Convert.ToSingle(reader.ReadLine());
        rowCount = System.Convert.ToInt32(reader.ReadLine());
        colCount = System.Convert.ToInt32(reader.ReadLine());
        cellSize = System.Convert.ToSingle(reader.ReadLine());

        EditorPrefs.SetFloat("MoveSnapX", cellSize);
        EditorPrefs.SetFloat("MoveSnapY", cellSize);
        EditorPrefs.SetFloat("MoveSnapZ", cellSize);

        CreateCells();

        string line = string.Empty;
        string[] str_array = null;
        while (!reader.EndOfStream)
        {
            line = reader.ReadLine();
            str_array = line.Split(new char[] { ',' });

            int i = Convert.ToInt32(str_array[0]);
            int j = Convert.ToInt32(str_array[1]);
            if (i < 0 || i >= rowCount)
                continue;
            if (j < 0 || j >= colCount)
                continue;

            cells[i, j].level = Convert.ToInt32(str_array[2]);
            cells[i, j].bulletDmgCoef = Convert.ToSingle(str_array[3]);
            cells[i, j].exploDmgCoef = Convert.ToSingle(str_array[4]);
            cells[i, j].halfCull = Convert.ToBoolean(str_array[5]);
            cells[i, j].dynamicGo = str_array[6];
        }

        reader.Close();
    }

    /// <summary>
    /// 按路径和类型加载对象
    /// </summary>
    /// <param name="path"></param>
    /// <param name="type"></param>
    /// <returns></returns>
    UnityEngine.Object LoadObject(string path, System.Type type)
    {
        if (path == "null")
            return null;
        return AssetDatabase.LoadAssetAtPath(path, type);
    }

    /// <summary>
    /// 保存文件
    /// </summary>
    public void Save()
    {
        if (string.IsNullOrEmpty(filename))
            return;

        try
        {
            StreamWriter writer = new StreamWriter(filename, false, Encoding.UTF8);
            StringBuilder builder = new StringBuilder(2048);

            writer.WriteLine(origin.x);
            writer.WriteLine(origin.y);
            writer.WriteLine(rowCount);
            writer.WriteLine(colCount);
            writer.WriteLine(cellSize);

            for (int i = 0; i < rowCount; ++i)
            {
                for (int j = 0; j < colCount; ++j)
                {
                    Cell c = cells[i, j];
                    if (c.level == 0 && c.halfCull == false)
                        continue;

                    builder.Remove(0, builder.Length);
                    builder.AppendFormat("{0},{1},{2},{3},{4},{5},{6}",
                        i, j, c.level, c.bulletDmgCoef, c.exploDmgCoef, c.halfCull, c.dynamicGo);

                    writer.WriteLine(builder);
                }
            }

            writer.Close();
        }
        catch(System.Exception ex)
        {
            EditorUtility.DisplayDialog("错误", ex.Message, "确定");
        }
    }

    /// <summary>
    /// 保存对象的路径
    /// </summary>
    /// <param name="obj"></param>
    /// <returns></returns>
    string SaveObject(UnityEngine.Object obj)
    {
        if (obj == null)
            return "null";
        return AssetDatabase.GetAssetPath(obj);
    }

    void ArrToString<T>(T[] arr, StringBuilder builder)
    {
        ArrToString<T>(arr, builder, arr.Length);
    }
    void ArrToString<T>(T[] arr, StringBuilder builder, int count)
    {
        if(count <= arr.Length)
        {
            for (int i = 0; i < count; i++)
            {
                if(i > 0)
                {
                    builder.Append(';');
                }
                builder.Append(arr[i]);
            }
        }
    }

    void InitExportParams(Collider c, out float[] arr, out int cType)
    {
        int len = 8;
        arr = new float[len];
        for (int i = 0; i < len; i++)
        {
            arr[i] = 0;
        }
        // 盒形碰撞体
        cType = 0;
        if (c is BoxCollider)
        {
            cType = 1;
            var box = (BoxCollider)c;
            var centerPt = c.transform.position;
            var lt = new Vector3(box.center.x - 0.5f * box.size.x * box.transform.localScale.x, 0.0f, box.center.z + 0.5f * box.size.z * box.transform.localScale.z);
            var lb = new Vector3(box.center.x - 0.5f * box.size.x * box.transform.localScale.x, 0.0f, box.center.z - 0.5f * box.size.z * box.transform.localScale.z);
            var rt = new Vector3(box.center.x + 0.5f * box.size.x * box.transform.localScale.x, 0.0f, box.center.z + 0.5f * box.size.z * box.transform.localScale.z);
            var rb = new Vector3(box.center.x + 0.5f * box.size.x * box.transform.localScale.x, 0.0f, box.center.z - 0.5f * box.size.z * box.transform.localScale.z);
            lt = box.transform.rotation * lt + centerPt;
            lb = box.transform.rotation * lb + centerPt;
            rt = box.transform.rotation * rt + centerPt;
            rb = box.transform.rotation * rb + centerPt;

            arr[0] = lt.x;
            arr[1] = lt.z;
            arr[2] = lb.x;
            arr[3] = lb.z;
            arr[4] = rb.x;
            arr[5] = rb.z;
            arr[6] = rt.x;
            arr[7] = rt.z;
        }
        // 圆形碰撞体
        else if (c is SphereCollider || c is CapsuleCollider)
        {
            cType = 2;
            Vector3 center;
            float radius = 0;
            if (c is SphereCollider)
            {
                center = (c as SphereCollider).center;
                radius = (c as SphereCollider).radius;
            }
            else
            {
                center = (c as CapsuleCollider).center;
                radius = (c as CapsuleCollider).radius;
            }
            arr[0] = center.x + c.transform.position.x;
            arr[1] = center.z + c.transform.position.z;
            arr[2] = radius;
        }
    }

    void ExportSceneObj()
    {
        string filename = EditorUtility.SaveFilePanel("Export file", "Assets/", "", "csv");
        if (!string.IsNullOrEmpty(filename))
        {
            string colFileName = filename.Substring(0, filename.Length - 4) + "_Shape.csv";
            try
            {
                using (StreamWriter writer = new StreamWriter(filename, false, Encoding.Default),
                       colliderWriter = new StreamWriter(colFileName, false, Encoding.Default) )
                {
                    var builder = new StringBuilder(2048);

					int itemIndex, type, logic, id, lv, hp, skill1, skill2, buffID, selfbuffid, targetID, camp, dropNum, allowRepeat = 0;
                    StringBuilder shapesIndexString = new StringBuilder(100);
					StringBuilder dropsIndexString = new StringBuilder(100);
					StringBuilder dropsWeightIndex = new StringBuilder(100);
					float halfBrokenHpRate, brokenHpRate, rebornTime, FirstUnLockTime, FlagScore, dropRadius = 0.0f;
                    int shapeIndex = 1, SpawnCount = 0,SpawnType = 0;
                    itemIndex = 1;
                    string itemName = null;
                    int[] shapeIndexArray = new int[21];
					writer.WriteLine("Index,Type,Shapes,Logic,ID,Level,HP,HBrokenSkillID,BrokenSkillID,HBrokenRatio,BrokenRatio,BuffID,RebornTime,TargetID,Camp,Name,SelfBuffID,FirstUnLockTime,FlagScore,SpawnCount,SpawnType,DropsPool,DropNum,DropWeight,DropRadius,AllowRepeat");
                    writer.WriteLine("序号,类型,形状ID,形状逻辑,ID,等级,生命,半损技能ID,全损技能ID,半损生命比例,全损生命比例,BuffID,刷新时间,传送门关联ID,阵营,别名,自带Buff,首次解锁时间,夺旗奖励分数,刷新次数,刷新类型,掉落物池,掉落个数,掉落权重,掉落位置半径,是否重复掉落");
					writer.WriteLine("index,int32,array-int32,int32,int32,int32,int32,int32,int32,float,float,int32,float,int32,int32,string,int32,float,float,int32,int32,array-int32,int32,array-int32,float,int32");

                    colliderWriter.WriteLine("ShapeID,Type,BlockMove,BlockProj,Params");
                    colliderWriter.WriteLine("形状序号,碰撞形状,移动阻挡值,子弹阻挡值,形状参数");
                    colliderWriter.WriteLine("index,int32,int32,int32,array-float");

                    var designGo = GameObject.Find(PROTOGONOS.Instance.gaia.DesignLevelName);
                    if(designGo == null)
                    {
                        EditorUtility.DisplayDialog("卧槽", "导出失败，DesignLevel不存在！", "OK");
                        return;
                    }
                    Transform[] objs = designGo.GetComponentsInChildren<Transform>();
                    foreach (Transform trans in objs)
                    {
                        GameObject obj = trans.gameObject;
                        //设置表格内默认值
						type = logic = id = lv = hp = skill1 = skill2 = buffID = selfbuffid = targetID = camp = dropNum = allowRepeat = 0;
						halfBrokenHpRate = brokenHpRate = rebornTime = FirstUnLockTime = FlagScore = dropRadius = 0f;
                        itemName = string.Empty;
                        shapesIndexString.Remove(0, shapesIndexString.Length);
						dropsIndexString.Remove(0, dropsIndexString.Length);
						dropsWeightIndex.Remove(0, dropsWeightIndex.Length);
                        bool needWrite = false;
                        if (obj.CompareTag(GlobalConst.DESTRUCT_TAG))
                        {
                            DestructController controller = obj.GetComponent<DestructController>();
							if (controller.destructMode == DestructMode.DestructBounty)
								type = (int)SceneObjType.Bounty;
							else
								type = (int)SceneObjType.Destruct;
                            if (controller != null)
                            {
                                //if (controller.bBuffContainer)
                                //    type = (int)SceneObjType.DestructBuff;
                                //else if (controller.bGoldContainer)
                                //    type = (int)SceneObjType.Gold;
                                //else
                                //    type = (int)SceneObjType.Destruct;

                                id = (int)controller.id;
                                lv = controller.Lv;
                                hp = controller.HealthBase;
                                skill1 = controller.HalfBrokenSkillID;
                                skill2 = controller.BrokenSkillID;
                                halfBrokenHpRate = controller.HalfBrokenHpPct;
                                brokenHpRate = controller.BrokenHpPct;
                                rebornTime = controller.RefreshTime;
                                buffID = controller.BuffID;
                                selfbuffid = controller.SelfBuffID;
								dropNum = controller.dropNum;
                                for (int i = 0; i < controller.subStateObject.Length; i++)
                                {
                                    Collider colliderDestruct = controller.subStateObject[i].GetComponent<Collider>();
                                    if(colliderDestruct != null)
                                    {
                                        WriteShapeLine(colliderDestruct, shapeIndex, builder, colliderWriter, false);
                                        shapeIndexArray[i] = shapeIndex;
                                        shapeIndex++;
                                    }
                                    else
                                    {
                                        shapeIndexArray[i] = -1;
                                    }
                                }
								ArrToString<int>(shapeIndexArray, shapesIndexString, controller.subStateObject.Length);

								ArrToString<int>((int[])controller.dropsPool.ToArray(), dropsIndexString, controller.dropsPool.Count);
								ArrToString<int>((int[])controller.dropsWeight.ToArray(), dropsWeightIndex, controller.dropsWeight.Count); 


								if (obj.GetComponent<SceneObj>()) {
                                    SceneObj actor = obj.GetComponent<SceneObj>();
                                    camp = actor.camp;
                                }
                                //if (controller.isOurBuliding)
                                //    camp = 1;
                                itemName = PlatoUtil.GetFullName(obj);
                                needWrite = true;
                            }
                            else
                                Debug.LogError(obj.name + " without DestructController");
                        }
                        else if (obj.CompareTag(GlobalConst.BUFF_ITEM_TAG))
                        {
                            type = (int)SceneObjType.BuffItem;
                            SupplyTrigger controller = null;
                            if (obj.GetComponent<SupplyTrigger>())
                            {
                                controller = obj.GetComponent<SupplyTrigger>();
                                Collider col = obj.GetComponent<Collider>();
                                if(col != null)
                                {
                                    WriteShapeLine(col, shapeIndex, builder, colliderWriter, false);
                                    shapeIndexArray[0] = shapeIndex;
                                    shapesIndexString.Append(shapeIndex);
                                    shapeIndex++;
                                }
                                buffID = controller.buffID;
                                rebornTime = controller.rebornTime;
                                needWrite = true;
                            }
                            else
                                Debug.LogError(obj.name + " without SupplyTrigger");
                        }
                        else if (obj.CompareTag(GlobalConst.BUY_MACHINE_TAG))
                        {
                            type = (int)SceneObjType.Shop;
                            if (obj.GetComponent<ShopTrigger>())
                            {
                                id = obj.GetComponent<ShopTrigger>().id;
                                Collider col = obj.GetComponent<Collider>();
                                if (col != null)
                                {
                                    WriteShapeLine(col, shapeIndex, builder, colliderWriter, false);
                                    shapeIndexArray[0] = shapeIndex;
                                    shapesIndexString.Append(shapeIndex);
                                    shapeIndex++;
                                }
                                needWrite = true;
                            }
                            else
                                Debug.LogError(obj.name + " without BuyMachine");
                        }
                        else if (obj.CompareTag(GlobalConst.PORTAL_TAG))
                        {
                            type = (int)SceneObjType.Portal;
                            PortalTrigger controller = obj.GetComponent<PortalTrigger>();
                            if (controller)
                            {
                                id = controller.ZoonId;
                                targetID = controller.TargetId;
                                rebornTime = controller.rebornTime;
                                Collider col = obj.GetComponent<Collider>();
                                if (col != null)
                                {
                                    WriteShapeLine(col, shapeIndex, builder, colliderWriter, false);
                                    shapeIndexArray[0] = shapeIndex;
                                    shapesIndexString.Append(shapeIndex);
                                    shapeIndex++;
                                }
                                needWrite = true;
                            }
                            else
                                Debug.LogError(obj.name + " without Portal");
                        }
                        else if (BattleUtil.IsGate(obj))
                        {
                            type = (int)SceneObjType.Gate;
                            shapeIndexArray[0] = 0;
                            shapeIndexArray[1] = 0;
                            int shapeCount = 0;
                            SpawnRegionController controller = obj.GetComponent<SpawnRegionController>();
                            if (controller)
                            {
                                for(int i = 0; i < controller.BlockGates.Length; i ++)
                                {
                                    Collider blockCollider = controller.BlockGates[i].GetComponent<Collider>();
                                    if (blockCollider != null)
                                    {
                                        WriteShapeLine(blockCollider, shapeIndex, builder, colliderWriter, false);
                                        shapeIndexArray[shapeCount] = shapeIndex;
                                        shapeIndex++;
                                        shapeCount++;
                                        break;
                                    }
                                }
                                for (int i = 0; i < controller.HealthyGates.Length; i++)
                                {
                                    Collider healthyCollider = controller.HealthyGates[i].GetComponent<Collider>();
                                    if (healthyCollider != null)
                                    {
                                        WriteShapeLine(healthyCollider, shapeIndex, builder, colliderWriter, false);
                                        shapeIndexArray[shapeCount] = shapeIndex;
                                        shapeIndex++;
                                        shapeCount++;
                                        break;
                                    }
                                }
                                ArrToString<int>(shapeIndexArray, shapesIndexString, shapeCount);
                                if(shapeCount <= 0)
                                {
                                    Debug.LogError(obj.name + " don't have any collider!");
                                }
                                camp = controller.Camp;
                                needWrite = true;
                                itemName = PlatoUtil.GetFullName(obj);
                            }
                            else
                                Debug.LogError(obj.name + " without Portal");
                        }
                        else if (obj.CompareTag(GlobalConst.FLAG_POINT_TAG)) {
                            type = (int)SceneObjType.FlagPoint;
                            OccupiedPoint controller = obj.GetComponent<OccupiedPoint>();
                            if (controller) {
                                rebornTime = controller.RebornTime;
                                FirstUnLockTime = controller.FirstUnLockTime;
                                FlagScore = controller.FlagScore;
                                SpawnCount = controller.SpawnCount;
                                SpawnType = controller.SpawnType;
                                id = controller.configID;
                                needWrite = true;
                                Collider col = obj.GetComponent<Collider>();
                                if (col != null) {
                                    WriteShapeLine(col, shapeIndex, builder, colliderWriter, false);
                                    shapeIndexArray[0] = shapeIndex;
                                    shapesIndexString.Append(shapeIndex);
                                    shapeIndex++;
                                }
                            }
                            else
                                Debug.LogError(obj.name + " without OccupiedPoint");
                        }
                        if(needWrite)
                        {
                            builder.Remove(0, builder.Length);
							builder.AppendFormat("{0},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{12},{13},{14},{15},{16},{17},{18},{19},{20},{21},{22},{23},{24},{25}",//array-int32,int32,array-int32,float,int32
								itemIndex, type, shapesIndexString, logic, id, lv, hp, skill1, skill2, halfBrokenHpRate, brokenHpRate, buffID, rebornTime, targetID, camp, itemName, selfbuffid, FirstUnLockTime, FlagScore, SpawnCount, SpawnType, dropsIndexString,dropNum,dropsWeightIndex,dropRadius,allowRepeat);

                            writer.WriteLine(builder);
                        }
                    }
                }
                EditorUtility.DisplayDialog("导出", "导出成功！", "确定");
            }
            catch (System.Exception ex)
            {
                EditorUtility.DisplayDialog("错误", ex.Message, "确定");
            }
        }
    }

    void ExportStatic()
    {
        string filename = EditorUtility.SaveFilePanel("Export File", "", "", "csv");
        if (!string.IsNullOrEmpty(filename))
        {
            try
            {
                int index = 0;
                using (StreamWriter writer = new StreamWriter(filename, false, Encoding.Default))
                {
                    var builder = new StringBuilder(2048);

                    writer.WriteLine("ShapeID,sType,Type,BlockMove,BlockProj,Params");
                    writer.WriteLine("形状序号,碰撞形状,类型,移动阻挡值,子弹阻挡值,形状参数");
                    writer.WriteLine("index,int32,int32,int32,int32,array-float");

                    var artGo = GameObject.Find(PROTOGONOS.Instance.gaia.ArtLevelName);
                    if(artGo == null)
                    {
                        EditorUtility.DisplayDialog("卧槽", "GAIA里缺少美术层！", "确定");
                        return;
                    }
                    foreach (var block in artGo.GetComponentsInChildren<BlockParam>())
                    {
                        var c = block.GetComponent<Collider>();
                        if (c == null)
                            continue;
                        WriteShapeLine(c, index, builder, writer, true);

                        index = index + 1;
                    }
                }
                EditorUtility.DisplayDialog("导出", "导出成功！", "确定");
            }
            catch (System.Exception ex)
            {
                EditorUtility.DisplayDialog("错误", ex.Message, "确定");
            }
        }
    }
    /// <summary>
    /// 导出为CSV文件
    /// </summary>
    void Export()
    {
        if (filename == string.Empty)
            return;

        SetObstacles();

        try
        {
            using (StreamWriter writer = new StreamWriter(filename.Replace(".level", ".csv"), false, Encoding.Default))
            {
                StringBuilder builder = new StringBuilder(2048);

                writer.WriteLine("Row,Col,Level,BulletCoef,ExploCoef,HallCull");
                writer.WriteLine("行,列,穿透等级,子弹衰减,爆炸衰减,半墙");
                writer.WriteLine("int32,int32,int32,float,float,int32");

                for (int i = 0; i < rowCount; ++i)
                {
                    for (int j = 0; j < colCount; ++j)
                    {
                        Cell c = cells[i, j];
                        if (!string.IsNullOrEmpty(c.dynamicGo))
                            continue;
                        if (c.level == 0 && c.halfCull == false && c.force == false)
                            continue;

                        builder.Remove(0, builder.Length);
                        builder.AppendFormat("{0},{1},{2},{3},{4},{5}",
                            i, j, c.level, c.bulletDmgCoef, c.exploDmgCoef, c.halfCull ? 1 : 0);

                        writer.WriteLine(builder);
                    }
                }
            }

            using (StreamWriter writer = new StreamWriter(filename.Replace(".level", "_gate.csv"), false, Encoding.Default))
            {
                Dictionary<string, List<int>> gates = new Dictionary<string, List<int>>();
                for (int i = 0; i < rowCount; ++i)
                {
                    for (int j = 0; j < colCount; ++j)
                    {
                        Cell c = cells[i, j];
                        if (string.IsNullOrEmpty(c.dynamicGo))
                            continue;

                        List<int> grids;
                        if (!gates.TryGetValue(c.dynamicGo, out grids))
                        {
                            grids = new List<int>();
                            gates.Add(c.dynamicGo, grids);
                        }
                        grids.Add(i);
                        grids.Add(j);
                    }
                }

                StringBuilder builder = new StringBuilder(2048);
                writer.WriteLine("Name,Grids");
                writer.WriteLine("门名称,网格数组");
                writer.WriteLine("string,string");

                var iter = gates.GetEnumerator();
                while (iter.MoveNext())
                {
                    List<string> temp = new List<string>();
                    for (int i = 0; i < iter.Current.Value.Count; i += 2)
                    {
                        temp.Add(string.Format("{0}:{1}", iter.Current.Value[i], iter.Current.Value[i + 1]));
                    }
                    builder.Remove(0, builder.Length);
                    builder.AppendFormat("{0},{1}", iter.Current.Key, string.Join(";", temp.ToArray()));
                    writer.WriteLine(builder);
                }
            }

            EditorUtility.DisplayDialog("导出", "导出成功！", "确定");
        }
        catch(System.Exception ex)
        {
            EditorUtility.DisplayDialog("错误", ex.Message, "确定");
        }
    }

    void SetObstacles()
    {
        List<Collider> blocks = new List<Collider>();

        GameObject artGo = GameObject.Find(PROTOGONOS.Instance.gaia.ArtLevelName);
        blocks.AddRange(artGo.GetComponentsInChildren<Collider>());

        GameObject designGo = GameObject.Find(PROTOGONOS.Instance.gaia.DesignLevelName);
        blocks.AddRange(designGo.GetComponentsInChildren<Collider>());

        Vector2 min = new Vector3();
        Vector2 max = new Vector3();
        Vector2[] corners = new Vector2[4];

        int totalCount = rowCount * colCount;
        int count = 0;
        for (int i = 0; i < rowCount; ++i)
        {
            for (int j = 0; j < colCount; ++j)
            {
                ++count;
                EditorUtility.DisplayProgressBar("Obstacles", string.Format("setting...({0}/{1})", count, totalCount), (float)count / totalCount);
                // 格子左下角需要加上原点的偏移
                min.x = j * cellSize + origin.x;
                min.y = i * cellSize + origin.y;
                max.x = min.x + cellSize;
                max.y = min.y + cellSize;

                corners[0].Set(min.x, min.y);
                corners[1].Set(min.x, max.y);
                corners[2].Set(max.x, max.y);
                corners[3].Set(max.x, min.y);

                bool result;
                result = IntersectCell(corners, blocks);
                if (result != false && cells[i, j].level == 0)
                {
                    cells[i, j].level = 0;
                    cells[i, j].bulletDmgCoef = 0.0f;
                    cells[i, j].exploDmgCoef = 0.0f;
                    cells[i, j].halfCull = false;
                    cells[i, j].force = true;
                    continue;
                }
            }
        }
        EditorUtility.ClearProgressBar();
    }

    /// <summary>
    /// 创建格子
    /// </summary>
    void CreateCells()
    {
        cells = new Cell[rowCount, colCount];
        for (int i = 0; i < rowCount; ++i)
        {
            for (int j = 0; j < colCount; ++j)
            {
                cells[i, j] = new Cell();
            }
        }
    }

    /// <summary>
    /// 获得鼠标射线在地面的交点
    /// </summary>
    /// <param name="screenPos">鼠标的屏幕坐标</param>
    /// <returns></returns>
    Vector3 GetMousePosOnGround(Vector2 screenPos)
    {
        Ray ray = Camera.current.ScreenPointToRay(new Vector3(screenPos.x, -screenPos.y + Camera.current.pixelHeight));
        float distance;
        ground.Raycast(ray, out distance);
        return ray.GetPoint(distance);
    }

    /// <summary>
    /// 绘制格子高亮
    /// </summary>
    /// <param name="cellPos"></param>
    /// <param name="color"></param>
    void DrawHighlightCell(Vector3 cellPos, Color color)
    {
        Vector3 halfSize = new Vector3(cellSize * 0.5f, 0.0f, cellSize * 0.5f);
        
        Bounds bounds = new Bounds(cellPos + halfSize, new Vector3(cellSize, 0, cellSize));
        Vector3[] corners = GetCorners(bounds, true);
        Handles.color = color;
        Handles.DrawAAPolyLine(5.0f, corners);
    }

    /// <summary>
    /// 重置格子数据
    /// </summary>
    /// <param name="cell"></param>
    void ResetCell(Cell cell)
    {
        cell.level = 0;
        cell.bulletDmgCoef = 0.0f;
        cell.exploDmgCoef = 0.0f;
        cell.halfCull = false;
    }

    void WriteShapeLine(Collider c, int index, StringBuilder builder, StreamWriter writer, bool fakeType)
    {
        BlockParam block = c.GetComponent<BlockParam>();
        int blockMove = 0;
        int blockProj = 0;
        int collideType = -1;
        float[] collideParams = null;
        if (block != null)
        {
            blockMove = block.blockMove;
            blockProj = block.blockProjectie;
        }

        InitExportParams(c, out collideParams, out collideType);

        builder.Remove(0, builder.Length);
        if(fakeType)
        {
            builder.AppendFormat("{0},{1},1,{2},{3},", index, collideType, blockMove, blockProj);
        }
        else
        {
            builder.AppendFormat("{0},{1},{2},{3},", index, collideType, blockMove, blockProj);
        }
        ArrToString<float>(collideParams, builder);

        writer.WriteLine(builder);
    }
}
