using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEditor;


public class LevelCommonFunc
{

    /// <summary>
    ///  获得路径下的所有文件夹的名称
    /// </summary>
    /// <param name="path">路径</param>
    /// <returns></returns>
    public static string[] GetDirectoryNames(string path)
    {

        BetterList<string> names = new BetterList<string>();
        string[] files = GetDirectories(path);
        foreach (string name in files)
        {
            names.Add(GetLastName(name));
        }

        return names.ToArray();

    }

    /// <summary>
    /// 获得目录下所有的文件名称
    /// </summary>
    /// <param name="path">路径</param>
    /// <returns></returns>
    public static string[] GetFileNames(string path, string ext)
    {

        List<string> names = new List<string>();
        string[] files = GetFiles(path, ext);
        foreach (string name in files)
        {
            names.Add(GetLastName(name));
        }

        return names.ToArray();

    }

    /// <summary>
    /// 返回文件夹或者文件的名称
    /// </summary>
    /// <param name="path">全路径</param>
    /// <returns></returns>
    public static string GetLastName(string path)
    {
        string file = path.Replace("\\", "/");
        file = file.Substring(path.LastIndexOf('/') + 1);
        return file;
    }

    /// <summary>
    /// 获得该路径下所有的文件，全路径
    /// </summary>
    /// <param name="path">全路径</param>
    /// <returns></returns>
    public static string[] GetDirectories(string path)
    {

        string[] dirs = Directory.GetDirectories(path);

        return dirs;
    }

    /// <summary>
    /// 获得路径下所有的文件路径
    /// </summary>
    /// <param name="path">路径</param>
    /// <param name="ext">拓展名</param>
    /// <returns></returns>
    public static string[] GetFiles(string path, string ext)
    {

        string[] dirs = Directory.GetFiles(path, ext);

        return dirs;
    }

    /// <summary>
    /// 打开场景
    /// </summary>
    /// <param name="path">路径</param>
    /// <returns></returns>
    public static bool OpenScene(string path)
    {

        return EditorApplication.OpenScene(path);
    }


    private static int ID = 0;



    /// <summary>
    /// 获得编辑器唯一ID
    /// </summary>
    /// <returns></returns>
    public static int GetID()
    {
        return ID++;
    }




    public static LevelMapData SaveMap(LevelBaseData[] datas, string path, string name)
    {
        LevelMapData data = ScriptableObject.CreateInstance<LevelMapData>();

        if (datas != null && datas.Length != 0)
        {
            for (int i = 0; i < datas.Length; i++)
            {
                datas[i].Save(data);
                //datas[i].Save(dataClient);
            }
        }
        if (LevelTool.modeData != null)
            LevelTool.modeData.Save(data);
        data.ID = ID;


        //LevelInitMonster.Instance.Save(data);
        AssetDatabase.CreateAsset(data, path + name);

        //client data

        //Level.LevelData dataClient = ScriptableObject.CreateInstance<Level.LevelData>();
        //DatasAdapter.FillLevelData(data, dataClient);
        //LevelInitMonster.Instance.Save(dataClient);
        //dataClient.m_scriptName = LevelTool.scriptName;
        //dataClient.m_mapID = LevelTool.mapID;
        //AssetDatabase.CreateAsset(dataClient, path.Replace("LevelTool", "Resources") + name);


        //server data
        LevelDataExportTool.Save(data, name.Replace(".asset", ""));

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();

        return data;
    }

    public static LevelMapData LoadMap(string path)
    {
        LevelMapData datas = AssetDatabase.LoadAssetAtPath(path, typeof(LevelMapData)) as LevelMapData;
        ID = datas.ID;

        return datas;
    }

    /// <summary>
    /// 检查名称是否合法
    /// </summary>
    /// <param name="type">类型</param>
    /// <param name="name">名称</param>
    /// <returns></returns>
    public static bool CheckNameInScene(System.Type type, string name)
    {
        if (string.IsNullOrEmpty(name))
        {
            EditorUtility.DisplayDialog("错误", "名称不能为空", "确定");
            return false;
        }

        Object[] paths = GameObject.FindObjectsOfType(type);
        foreach (var v in paths)
        {
            LevelBaseData d = (v as LevelObjectBase).GetData();
            if (d.name == name)
            {
                EditorUtility.DisplayDialog("错误", "名称不能重复-->" + name, "确定");
                return false;
            }

        }
        return true;
    }

    /// <summary>
    /// 增加LevelObject
    /// </summary>
    /// <param name="type">LevelObject的子类</param>
    /// <param name="name">名称</param>
    /// <returns></returns>
    public static Component AddLevelObject(System.Type type, string name, LevelBaseData data, GameObject go = null)
    {
        int count = LevelCommonFunc.GetID();

        if (string.IsNullOrEmpty(name))
            name = type.Name + " $" + count;
        else
            name = name + " $" + count;
        if (false == CheckNameInScene(type, name)) return null;

        Component current = null;


        if (go == null)
        {
            go = new GameObject(name);
        }
        else
        {
            go = GameObject.Instantiate(go);
        }
        go.transform.position = LevelTool.startPosition;

        current = go.AddComponent(type);

        data.name = name;
        data.editorID = count;
        data.pos = go.transform.position;
        data.scale = go.transform.localScale;
        data.dir = go.transform.eulerAngles;
        go.name = data.name;
        (current as LevelObjectBase).SetData(data);

        return current;
    }




    /// <summary>
    /// 查找物件
    /// </summary>
    /// <param name="type">类型</param>
    /// <param name="id">编辑器ID</param>
    /// <returns></returns>
    public static Component FindLevelObjectByID(System.Type type, int id)
    {
        Object[] ms = GameObject.FindObjectsOfType(type);

        foreach (var m in ms)
        {
            if (((LevelObjectBase)m).GetData().editorID == id)
            {
                return (Component)m;
            }
        }
        return null;
    }




    #region 界面方法
    public static Vector2 scollpos;
    public static void OnGUI(LevelObjectBase b, LevelBaseData data)
    {
        if (b is LevelMonster && data is LevelMonsterData)
        {
            OnGUI((LevelMonster)b, (LevelMonsterData)data);
        }
        else if (b is LevelPathNode && data is LevelPathNodeData)
        {
            OnGUI((LevelPathNode)b, (LevelPathNodeData)data);
        }
        else if (b is LevelPath && data is LevelPathData)
        {
            OnGUI((LevelPath)b, (LevelPathData)data);
        }
        else if (b is LevelTrigger && data is LevelTriggleData)
        {
            OnGUI((LevelTrigger)b, (LevelTriggleData)data);
        }
        else if (b is LevelBatch && data is LevelBatchData)
        {
            OnGUI((LevelBatch)b, (LevelBatchData)data);
        }
        else if (b is LevelArea && data is LevelAreaData)
        {
            OnGUI((LevelArea)b, (LevelAreaData)data);
        }
        else if (b is LevelBirthPosition && data is LevelBirthPositionData)
        {
            OnGUI((LevelBirthPosition)b, (LevelBirthPositionData)data);
        }
        
        else if (b is LevelDoor && data is LevelDoorData)
        {
            OnGUI((LevelDoor)b, (LevelDoorData)data);
        }
        else if (b is LevelSceneObject && data is LevelSceneObjectData)
        {
            OnGUI((LevelSceneObject)b, (LevelSceneObjectData)data);
        }
    }

    private static void OnGUI(LevelSceneObject b, LevelSceneObjectData data)
    {
        EditorGUILayout.LabelField("唯一ID：", data.editorID.ToString());
        EditorGUILayout.LabelField("表单ID：", data.ID.ToString());


        EditorGUILayout.LabelField(Config.sceneTypeCn[data.typeSelect]);

        data.type = (LevelSceneObjectData.Type)data.typeSelect;

        if ((LevelSceneObjectData.Type)data.typeSelect == LevelSceneObjectData.Type.Quicksand || (LevelSceneObjectData.Type)data.typeSelect == LevelSceneObjectData.Type.HiddenArea)
        {
            b.transform.position = EditorGUILayout.Vector3Field("坐标", b.transform.position);
            data.pos = b.transform.position;

            b.transform.eulerAngles = EditorGUILayout.Vector3Field("方向", b.transform.eulerAngles);
            data.dir = b.transform.eulerAngles;

            data.radius = EditorGUILayout.IntField("半径", data.radius);
        }
        else if ((LevelSceneObjectData.Type)data.typeSelect == LevelSceneObjectData.Type.Pail)
        {
            b.transform.position = EditorGUILayout.Vector3Field("坐标", b.transform.position);
            data.pos = b.transform.position;

            b.transform.eulerAngles = EditorGUILayout.Vector3Field("方向", b.transform.eulerAngles);
            data.dir = b.transform.eulerAngles;
        }
        else if ((LevelSceneObjectData.Type)data.typeSelect == LevelSceneObjectData.Type.Tornado)
        {
            data.selectPath = (LevelPath)EditorGUILayout.ObjectField("选择路径", data.selectPath, typeof(LevelPath));

            if (data.selectPath)
            {
                OnGUI(data.selectPath, data.selectPath.GetData());
                data.pathData = (LevelPathData)data.selectPath.GetData();
            }
            EditorGUILayout.LabelField("传送目标点");
            if (GUILayout.Button("增加节点"))
            {
                LevelPositionData lpd = OnAddPropPosition(LevelTool.startPosition, LevelPositionData.Type.Tornado);
                data.transmitDatas.Add(lpd);
            }

            List<LevelPosition> p = new List<LevelPosition>();


            foreach (var k in data.transmitDatas)
            {
                p.Add(LevelCommonFunc.FindLevelObjectByID(typeof(LevelPosition), k.editorID) as LevelPosition);
            }


            for (int i = 0; i < p.Count; i++)
            {
                LevelPositionData pd = (LevelPositionData)p[i].GetData();
                if (pd.type == LevelPositionData.Type.Tornado)
                {

                    EditorGUILayout.BeginHorizontal();
                    EditorGUILayout.ObjectField(p[i], typeof(LevelPosition));
                    p[i].transform.position = EditorGUILayout.Vector3Field("位置 ", p[i].transform.position);
                    if (GUILayout.Button("删除节点"))
                    {
                        data.transmitDatas.Remove(pd);
                        GameObject.DestroyImmediate(p[i].gameObject);
                        continue;

                    }
                    EditorGUILayout.EndHorizontal();


                }

            }


        }

    }

    private static void OnGUI(LevelArea b, LevelAreaData data)
    {



        EditorGUILayout.BeginHorizontal();


        EditorGUILayout.LabelField("ID：", data.ID.ToString());
        EditorGUILayout.EndHorizontal();
        data.name = EditorGUILayout.TextField("名称：", data.name);

        EditorGUILayout.BeginHorizontal();
        data.radius = EditorGUILayout.IntField("半径", data.radius);
        EditorGUILayout.EndHorizontal();

        data.typeSelect = EditorGUILayout.Popup("类型", data.typeSelect, Config.areaTypesCn);

        data.type = ((LevelAreaData.Type)data.typeSelect + 1);


        b.transform.position = EditorGUILayout.Vector3Field("坐标", b.transform.position);
        data.pos = b.transform.position;

        //if (data.type == LevelAreaData.Type.Trap)
        //{

        //    data.trapSelect = EditorGUILayout.Popup("陷阱类型", data.trapSelect, Config.trapTypesCn);
        //    data.trapType = data.trapSelect + 1;
        //    //EditorGUILayout.IntField(data.trapType);
        //}
        //else
        //{

        EditorGUILayout.BeginHorizontal();
        data.comp = EditorGUILayout.IntField("阵营", data.comp);
        EditorGUILayout.EndHorizontal();

        EditorGUILayout.BeginHorizontal();

        //area = (LevelArea)EditorGUILayout.ObjectField(area, typeof(LevelArea), true);

        LevelArea[] areas = GameObject.FindObjectsOfType<LevelArea>();

        List<LevelArea> can_connect = new List<LevelArea>();

        for (int i = 0; i < areas.Length; i++)
        {
            if (b != areas[i])
            {
                can_connect.Add(areas[i]);
            }
        }

        List<string> can_connect_s = new List<string>();
        foreach (var k in can_connect)
        {
            can_connect_s.Add(k.GetData().name);
        }

        b.con_select = EditorGUILayout.Popup(b.con_select, can_connect_s.ToArray());

        if (GUILayout.Button("添加可连接区域"))
        {
            if (b.con_select >= 0 && b.con_select < can_connect_s.Count)
            {
                LevelArea area = can_connect[b.con_select];
                b.areas.Add(area);
                LevelAreaData nextData = area.GetData() as LevelAreaData;
                data.nextAreas.Add(nextData);
            }

        }
        EditorGUILayout.EndHorizontal();



        EditorGUILayout.Space();
        //EditorGUILayout.LabelField("客户端数据");
        //data.m_teamID = EditorGUILayout.IntField("TeamID", data.m_teamID);
        //EditorGUILayout.LabelField("基地类型");
        //data.m_type = (Level.FoundationType)EditorGUILayout.EnumPopup(data.m_type);
        //data.m_meshName = EditorGUILayout.TextField("资源名称", data.m_meshName);
        //EditorGUILayout.Space();

        EditorGUILayout.LabelField("已经连接的区域");
        for (int i = 0; i < b.areas.Count; i++)
        {
            LevelArea aaa = b.areas[i];
            EditorGUILayout.BeginHorizontal();
            LevelAreaData nextData = aaa.GetData() as LevelAreaData;
            nextData.priority = EditorGUILayout.IntField("权重", nextData.priority);
            EditorGUILayout.ObjectField(aaa, typeof(LevelArea), true);
            if (GUILayout.Button("删除"))
            {
                b.areas.RemoveAt(i);
                data.nextAreas.Remove(nextData);
            }
            EditorGUILayout.EndHorizontal();
        }

        //}


    }

    public static List<LevelObjectBase> FindUsingLevelMonsterCondition(LevelObjectBase except)
    {
        List<LevelObjectBase> lob = new List<LevelObjectBase>();
        LevelBatch []batches = GameObject.FindObjectsOfType<LevelBatch>();
        foreach (var k in batches)
        { 
            LevelBatchData data =(LevelBatchData)k.GetData();
            if (data.events != null && data.events.Count != 0)
            {
                foreach (var j in data.events)
                {
                    if(j.cond.selectMonster && j.cond.selectMonster != except)
                        lob.Add(j.cond.selectMonster);
                    
                }

                
            }
        }
        return lob;
    }


    public static List<LevelObjectBase> FindUsingLevelMonsterAction(LevelObjectBase except)
    {
        List<LevelObjectBase> lob = new List<LevelObjectBase>();
        LevelBatch[] batches = GameObject.FindObjectsOfType<LevelBatch>();
        foreach (var k in batches)
        {
            LevelBatchData data = (LevelBatchData)k.GetData();
            if (data.events != null && data.events.Count != 0)
            {
                foreach (var j in data.events)
                {
                    
                    if (j.action.selectMonster && j.action.selectMonster != except)
                        lob.Add(j.action.selectMonster);
                }


            }
        }
        return lob;
    }

    private static void OnGUI(LevelBatch b, LevelBatchData data)
    {
        EditorGUILayout.BeginHorizontal();
        EditorGUILayout.LabelField("ID：", data.ID.ToString());
        data.name = EditorGUILayout.TextField("名称：", data.name);
        EditorGUILayout.EndHorizontal();

        EditorGUILayout.BeginHorizontal();
        data.pos = b.transform.position;
        data.dir = b.transform.eulerAngles;

        if (GUILayout.Button("添加事件"))
        {
            TriggerEvent e = new TriggerEvent();
            e.sort = data.events.Count;
            data.events.Add(e);
        }


        EditorGUILayout.EndHorizontal();

        GUI.backgroundColor = Color.green;
        if (GUILayout.Button("排序"))
        {
            data.events.Sort(
                (left, right) =>
                {
                    if (left.sort < right.sort)
                        return -1;
                    if (left.sort > right.sort)
                        return 1;
                    else
                        return 0;
                }
                );
        }
        GUI.backgroundColor = Color.white;
        scollpos = EditorGUILayout.BeginScrollView(scollpos);

        for (int i = 0; i < data.events.Count; i++)
        {
            EditorGUILayout.Space();
            //EditorGUILayout.LabelField("****  事件" + data.events[i].sort + "  ****");
            data.events[i].toggle = EditorGUILayout.BeginToggleGroup("****  事件" + data.events[i].sort + "  ****", data.events[i].toggle);

            data.events[i].sort = EditorGUILayout.IntField("事件序号", data.events[i].sort);
            GUI.backgroundColor = Color.red;
            if (GUILayout.Button("删除事件"))
            {
                data.events.RemoveAt(i);
                continue;
            }


            GUI.backgroundColor = Color.white;

            TriggerEvent e = data.events[i];

            EditorGUILayout.LabelField("条件");

            e.cond.typeIdx = EditorGUILayout.Popup("条件类型", e.cond.typeIdx, Config.triggleCondTypeCn);
            e.cond.type = (TriggerCondition.Type)e.cond.typeIdx;
            //e.cond.type = (TriggerCondition.Type)EditorGUILayout.EnumPopup("条件类型", e.cond.type);
            if (e.cond.type == TriggerCondition.Type.BatchTimeStart || e.cond.type == TriggerCondition.Type.BatchTimeInterval || e.cond.type == TriggerCondition.Type.EventTimeInterval)
            {
                e.cond.interval = EditorGUILayout.IntField("时间", e.cond.interval);
            }

            if (e.cond.type == TriggerCondition.Type.KillMonster)
            {


                e.cond.selectMonster = (LevelMonster)LevelChooseWindow.ObjectField(e.cond.selectMonster, typeof(LevelMonster));
            
                if (e.cond.selectMonster)
                {

                    e.cond.targetID = e.cond.selectMonster.GetData().editorID;
                    EditorGUILayout.LabelField("目标ID", e.cond.targetID.ToString());

                    LevelMonsterData md = e.cond.selectMonster.GetData() as LevelMonsterData;

                    md.groupID = data.editorID;
                    //md.groupSequence = i;



                    if (data.isVisible)
                        OnGUI(e.cond.selectMonster, md);
                }
            }

            if (e.cond.type == TriggerCondition.Type.KillGroup)
            {

                e.cond.selectGroup = (LevelBatch)EditorGUILayout.ObjectField(e.cond.selectGroup, typeof(LevelBatch), true);
                if (e.cond.selectGroup)
                {
                    e.cond.targetID = e.cond.selectGroup.GetData().editorID;
                    EditorGUILayout.LabelField("波次ID", e.cond.targetID.ToString());
                }
            }

            if (e.cond.type == TriggerCondition.Type.MoveToArea)
            {
                //e.cond.areaId = EditorGUILayout.IntField("区域ID", e.cond.areaId);
                e.cond.selectArea = (LevelArea)EditorGUILayout.ObjectField(e.cond.selectArea, typeof(LevelArea), true);
                if (e.cond.selectArea)
                {
                    e.cond.areaID = ((LevelAreaData)e.cond.selectArea.GetData()).editorID;
                    e.cond.radius = ((LevelAreaData)e.cond.selectArea.GetData()).radius;
                    e.cond.center = ((LevelAreaData)e.cond.selectArea.GetData()).pos;

                    EditorGUILayout.LabelField("中心点坐标", e.cond.center.ToString());
                    EditorGUILayout.LabelField("半径", e.cond.radius.ToString());
                }
            }
            EditorGUILayout.Space();
            EditorGUILayout.LabelField("动作");

            e.action.typeIdx = EditorGUILayout.Popup("动作类型", e.action.typeIdx, Config.triggleActionTypeCn);
            e.action.type = (TriggerAction.Type)e.action.typeIdx;
            //e.action.type = (TriggerAction.Type)EditorGUILayout.EnumPopup("动作类型", e.action.type);


            if (e.action.type == TriggerAction.Type.SpawnMonster)
            {
                e.action.selectMonster = (LevelMonster)LevelChooseWindow.ObjectField(e.action.selectMonster, typeof(LevelMonster), FindUsingLevelMonsterAction(e.action.selectMonster));
                if (e.action.selectMonster)
                {
                    e.action.editorID = e.action.selectMonster.GetData().editorID;
                    LevelMonsterData md = e.action.selectMonster.GetData() as LevelMonsterData;
                    md.groupID = data.editorID;
                    EditorGUILayout.LabelField("目标ID", e.action.editorID.ToString());

                    if (data.isVisible)
                        OnGUI(e.action.selectMonster, e.action.selectMonster.GetData());
                }
            }
            else if (e.action.type == TriggerAction.Type.SpawnBatchMessage)
            {
                e.action.messageID = EditorGUILayout.IntField("消息ID", e.action.messageID);
                e.action.param = EditorGUILayout.IntField("参数", e.action.param);
            }

            else if (e.action.type == TriggerAction.Type.SpawnBossMessage)
            {
                e.action.messageID = EditorGUILayout.IntField("消息ID", e.action.messageID);

            }
            EditorGUILayout.EndToggleGroup();
        }


        EditorGUILayout.EndScrollView();
    }

    private static void OnGUI(LevelMonster b, LevelMonsterData data)
    {


        if (data.isVisible)
        {
            LevelMonster tankobj = b;
            EditorGUILayout.LabelField("编辑器ID", data.editorID.ToString());
            EditorGUILayout.LabelField("坦克ID", data.ID.ToString());
            EditorGUILayout.LabelField("坦克名称", data.name);
            EditorGUILayout.LabelField("波次ID", data.groupID.ToString());

            data.mainAIID = EditorGUILayout.Popup("行走AI", data.mainAIID, Config.mainAIs);
            data.subAIID = EditorGUILayout.Popup("攻击AI", data.subAIID, Config.subAIs);
            data.AIID = LevelMonsterData.Gap * data.mainAIID + data.subAIID;
            EditorGUILayout.LabelField("AIID", data.AIID.ToString());

            data.groupSequence = EditorGUILayout.IntField("波次内序号", data.groupSequence);


            tankobj.transform.position = EditorGUILayout.Vector3Field("坐标", tankobj.transform.position);
            tankobj.transform.eulerAngles = EditorGUILayout.Vector3Field("方向", tankobj.transform.eulerAngles);


            data.selectPath = (LevelPath)EditorGUILayout.ObjectField("选择一条路径", data.selectPath, typeof(LevelPath));
            if (data.selectPath)
            {
                data.pathID = data.selectPath.GetData().editorID;
            }
            EditorGUILayout.LabelField("路径ID", data.pathID.ToString());


            data.pos = tankobj.transform.position;
            data.dir = tankobj.transform.eulerAngles;


        }



    }

    private static void OnGUI(LevelPathNode b, LevelPathNodeData data)
    {

        LevelPathNode obj = b;
        EditorGUILayout.LabelField("ID", data.ID.ToString());
        data.name = EditorGUILayout.TextField("节点名称", data.name);
        obj.transform.position = EditorGUILayout.Vector3Field("坐标", obj.transform.position);
        data.pos = obj.transform.position;
        data.type = (LevelPathNodeData.NodeType)EditorGUILayout.EnumPopup("节点类型", data.type);
        if (GUILayout.Button("删除"))
        {
            OnPathNodeRemove(b);
        }
    }

    public static void OnPathNodeRemove(LevelPathNode b)
    {
        LevelPathNodeData data = (LevelPathNodeData)b.GetData();
        LevelPath[] paths = GameObject.FindObjectsOfType<LevelPath>();
        foreach (LevelPath p in paths)
        {
            LevelPathNodeData find = null;
            LevelPathData pathData = (LevelPathData)p.GetData();
            foreach (var node in pathData.nodes)
            {
                if (node.ID == data.ID)
                {
                    find = node;
                    break;
                }
            }
            if (find != null)
            {
                pathData.nodes.Remove(find);

                Debug.Log(find);
                Debug.Log(pathData);
            }
        }

        GameObject.DestroyImmediate(b.gameObject);
    }

    private static void OnGUI(LevelBirthPosition b, LevelBirthPositionData data)
    {
        data.camp = EditorGUILayout.IntField("阵营", data.camp);
        b.transform.position = EditorGUILayout.Vector3Field("坐标", b.transform.position);
        data.pos = b.transform.position;
        b.transform.eulerAngles = EditorGUILayout.Vector3Field("方向", b.transform.eulerAngles);
        data.dir = b.transform.eulerAngles;


    }

    public static LevelPositionData OnAddPropPosition(Vector3 pos, LevelPositionData.Type type)
    {
        GameObject go = GameObject.CreatePrimitive(PrimitiveType.Cube);
        go.name = "position";
        LevelPosition lpp = go.AddComponent<LevelPosition>();
        LevelPositionData data = new LevelPositionData();
        data.pos = pos;
        data.ID = GetID();
        data.type = type;
        data.name = "position";
        lpp.SetData(data);
        go.transform.position = pos;

        //LevelPropData data = b.GetData() as LevelPropData;
        //b.positions.Add(lpp);
        //data.positions.Add(go.transform.position);

        LevelTool.stuffs.Add(go);
        return data;
    }




    public static bool onWhenStart = false;
    public static int timeInterval = 0;
    public static int loop = 0;
    public static int ItemID = 0;


    private static void OnGUI(LevelDoor b, LevelDoorData data)
    {
        data.m_batchIndex = EditorGUILayout.IntField("第几波后执行", data.m_batchIndex);
        EditorGUILayout.LabelField("资源名称在Resource(不含Resource带/)下的路径");
        data.m_meshName = EditorGUILayout.TextField(data.m_meshName);
    }

    [System.Obsolete]
    private static void OnGUI(LevelTrigger b, LevelTriggleData data)
    {

        EditorGUILayout.BeginHorizontal();
        EditorGUILayout.LabelField("ID：", data.ID.ToString());
        data.name = EditorGUILayout.TextField("名称：", data.name);
        EditorGUILayout.BeginHorizontal();
        if (GUILayout.Button("删除所有批次"))
        {
            OnDestroyAllBatch(b);
        }
        EditorGUILayout.EndHorizontal();
        EditorGUILayout.EndHorizontal();
        b = (LevelTrigger)EditorGUILayout.ObjectField("当前编辑触发器", b, typeof(LevelTrigger), true);
        scollpos = EditorGUILayout.BeginScrollView(scollpos);
        for (int i = 0; i < b.batches.Count; i++)
        {
            var batch = b.batches[i];
            if (!batch) continue;
            EditorGUILayout.BeginHorizontal();
            EditorGUILayout.LabelField("ID:" + batch.GetData().ID.ToString());

            EditorGUILayout.ObjectField(batch, typeof(LevelBatch), true);
            GUI.backgroundColor = Color.red;
            if (GUILayout.Button("删除"))
            {

                OnDestoryBatch(b, batch);
            }
            GUI.backgroundColor = Color.white;
            EditorGUILayout.EndHorizontal();
            LevelBatchData da = batch.GetData() as LevelBatchData;
            EditorGUILayout.LabelField("已经有怪物", da.monsters.Count.ToString());
            batch.color = EditorGUILayout.ColorField(batch.color);
            foreach (var m in batch.monsters)
            {
                Debug.DrawLine(batch.transform.position, m.transform.position, batch.color);
            }
        }
        EditorGUILayout.EndScrollView();
        EditorGUILayout.BeginHorizontal();
        if (GUILayout.Button("添加批次(Batch)"))
        {
            OnAddBatch(b);
        }

        EditorGUILayout.EndHorizontal();
    }

    public static void OnDestoryBatch(LevelTrigger t, LevelBatch b)
    {
        if (null == b) return;
        if (null == t) return;

        t.batches.Remove(b);
        LevelTool.stuffs.Remove(b.gameObject);
        GameObject.DestroyImmediate(b.gameObject);

    }

    public static void OnAddBatch(LevelTrigger b)
    {
        if (null == b) return;
        GameObject go = new GameObject();
        LevelBatch batch = go.AddComponent<LevelBatch>();
        LevelBatchData data = new LevelBatchData();
        data.ID = GetID();
        data.name = "批次";
        data.index = GameObject.FindObjectsOfType<LevelBatch>().Length;
        data.pos = b.transform.position;
        go.name = data.name;
        go.transform.position = b.transform.position;

        batch.SetData(data);
        b.batches.Add(batch);
        LevelTriggleData ltd = b.GetData() as LevelTriggleData;
        ltd.batches.Add(data);

        LevelTool.stuffs.Add(go);
    }

    public static void OnDestroyAllBatch(LevelTrigger b)
    {
        if (b)
        {
            foreach (var k in b.batches)
            {
                GameObject.DestroyImmediate(k.gameObject);
            }

            GameObject.DestroyImmediate(b.gameObject);
        }
    }

    public static void OnVisibleNode(LevelPathData p, bool visible)
    {
        foreach (LevelPathNodeData d in p.nodes)
        {
            LevelPathNode[] datas = GameObject.FindObjectsOfType<LevelPathNode>();
            foreach (var lpn in datas)
            {
                LevelPathNodeData lpnd = (LevelPathNodeData)lpn.GetData();
                if (lpnd.ID == d.ID)
                {
                    lpn.gameObject.GetComponent<Renderer>().enabled = visible;
                }
            }
        }
    }

    private static void OnGUI(LevelPath b, LevelPathData data)
    {

        LevelPath obj = b;

        EditorGUILayout.LabelField("路径ID", data.ID.ToString());
        EditorGUILayout.LabelField("路径详情", data.ToString());
        data.name = EditorGUILayout.TextField("路径名称", data.name);

        b.color = EditorGUILayout.ColorField("设置颜色", b.color);

        GUI.backgroundColor = Color.red;
        if (GUILayout.Button("删除"))
        {
            OnDestoryPath(b);
        }
        GUI.backgroundColor = Color.white;
    }

    public static void OnDestoryPath(LevelPath b)
    {
        LevelPathData data = (LevelPathData)b.GetData();
        GameObject.DestroyImmediate(b.gameObject);
        foreach (var k1 in data.nodes)
        {
            LevelPathNode[] nodes = GameObject.FindObjectsOfType<LevelPathNode>();
            foreach (var k2 in nodes)
            {
                LevelPathNodeData nodeData = (LevelPathNodeData)k2.GetData();

                if (k1.ID == nodeData.ID)
                {
                    GameObject.DestroyImmediate(k2.gameObject);
                }
            }
        }
    }

    #endregion
}
