using UnityEngine;
using UnityEditor;
using System.Collections;
using LitJson;
using System.Collections.Generic;
using System.IO;

public class LevelDataExportTool : Editor
{

    public class LevelBirthPositionToJson
    {
        public int x;
        public int y;
        public int z;
        public int rot;
        public int camp;

        public LevelBirthPositionToJson(LevelBirthPositionData source)
        {
            x = (int)source.pos.x;
            y = (int)source.pos.y;
            z = (int)source.pos.z;
            rot = (int)source.dir.y;
            camp = source.camp;
        }
    }

    public class LevelMonsterDropToJson
    {
        public int monsterID;

        public LevelMonsterDropToJson(LevelMonsterData source)
        {
            this.monsterID = source.ID;
        }
    }

    public class LevelMapModeToJson
    {
        public int type;
        public List<LevelMonsterDataToJson> killMonsters = new List<LevelMonsterDataToJson>();
        public int time;

        public List<LevelConditionDataToJson> condition2 = new List<LevelConditionDataToJson>();
        public List<LevelConditionDataToJson> condition3 = new List<LevelConditionDataToJson>();

        [System.Serializable]
        public class LevelConditionDataToJson
        {
            public int type;
            public int param;

            public LevelConditionDataToJson()
            {

            }

            public LevelConditionDataToJson(int type, int param)
            {
                this.type = type;
                this.param = param;
            }
        }

        [System.Serializable]
        public class LevelMonsterDataToJson
        {
            public int editorID;
            public int monsterID;

            public LevelMonsterDataToJson(int editorID, int monsterID)
            {
                this.editorID = editorID;
                this.monsterID = monsterID;
            }
        }
        public LevelMapModeToJson(LevelModeData source)
        {
            type = (int)source.condition1Star.conditionType;


            foreach (var k in source.condition1Star.selectMonsterDatas)
            {
                killMonsters.Add(new LevelMonsterDataToJson(k.editorID, k.ID));
            }

            time = (int)source.condition1Star.time;

            foreach (var k in source.condition2Star)
            {
                condition2.Add(new LevelConditionDataToJson(k.type + 1, k.param));
            }

            foreach (var k in source.condition3Star)
            {
                condition3.Add(new LevelConditionDataToJson(k.type + 1, k.param));
            }

        }
    }

    public class LevelAreaToJson
    {
        public int areaID;
        public int areaRadius;
        public int x;
        public int y;
        public int z;
        public LevelAreaData.NextArea[] nextAreas;
        public int areaType;
        public int camp;
        public LevelAreaToJson(LevelAreaData source)
        {
            x = (int)source.pos.x;
            y = (int)source.pos.y;
            z = (int)source.pos.z;
            areaID = source.editorID;
            areaRadius = source.radius;
            nextAreas = source.GetNextAreas();
            areaType = (int)source.type;
            camp = source.comp;
        }
    }

    public class LevelMonsterDataToJson
    {
        public int editorID;
        public int monsterID;
        public string name;
        public int x;
        public int y;
        public int z;
        public int dx;
        public int dy;
        public int dz;
        public int AIID;
        public int groupID;
        public int sequenceIdx;
        public int pathID;

        public LevelMonsterDataToJson()
        {

        }

        public LevelMonsterDataToJson(LevelMonsterData data)
        {
            editorID = data.editorID;
            monsterID = data.ID;
            name = data.name;
            x = (int)data.pos.x;
            y = (int)data.pos.y;
            z = (int)data.pos.z;
            dx = (int)data.dir.x;
            dy = (int)data.dir.y;
            dz = (int)data.dir.z;
            AIID = data.AIID;
            groupID = data.groupID;
            sequenceIdx = data.groupSequence;
            pathID = data.pathID;
        }
    }

    [System.Serializable]
    public class TriggerCondToJson
    {
        public int condType;
        public int interval;
        public int targetID;
        public int x;
        public int y;
        public int z;
        public int radius;

        public TriggerCondToJson()
        {

        }
        public TriggerCondToJson(TriggerCondition t)
        {
            condType = (int)t.type;
            interval = t.interval;
            targetID = t.targetID;
            x = (int)t.center.x;
            y = (int)t.center.y;
            z = (int)t.center.z;
            radius = t.radius;
        }
    }

    [System.Serializable]
    public class TriggerActionToJson
    {
        public int actionType;
        public int editorMonsterID;
        public int msgID;
        public int param;

        public TriggerActionToJson()
        {

        }

        public TriggerActionToJson(TriggerAction a)
        {
            actionType = (int)a.type;
            editorMonsterID = a.editorID;
            msgID = a.messageID;
            param = a.param;
        }
    }

    [System.Serializable]
    public class TriggerEventToJson
    {
        public TriggerCondToJson cond;
        public TriggerActionToJson action;

        public TriggerEventToJson()
        {

        }

        public TriggerEventToJson(TriggerEvent t)
        {
            cond = new TriggerCondToJson(t.cond);
            action = new TriggerActionToJson(t.action);
        }
    }

    public class LevelBatchDataToJson
    {
        public int loopCount;
        public int loopInterval;
        public int dropID;
        public List<TriggerEventToJson> events = new List<TriggerEventToJson>();

        public LevelBatchDataToJson()
        {

        }
        public LevelBatchDataToJson(LevelBatchData data)
        {
            loopCount = data.loopCount;
            loopInterval = data.loopInterval;
            dropID = data.dropID;

            foreach (var e in data.events)
            {
                events.Add(new TriggerEventToJson(e));
            }

        }
    }


    public class LevelAreaTrapToJson
    {
        public int x;
        public int y;
        public int z;
        public int id;
        public int type;
        public int radius;

        public LevelAreaTrapToJson()
        {

        }

        public LevelAreaTrapToJson(LevelSceneObjectData data)
        {
            if (data.type == LevelSceneObjectData.Type.Quicksand)
            {
                x = (int)data.pos.x;
                y = (int)data.pos.y;
                z = (int)data.pos.z;
                type = (int)data.type;
                radius = data.radius;
                id = data.ID;
            }
        }
    }


    public class LevelPailSceneObjectToJson
    {
        public int id;
        public int x;
        public int y;
        public int z;

        public LevelPailSceneObjectToJson()
        {

        }

        public LevelPailSceneObjectToJson(LevelSceneObjectData data)
        {
            if (data.type == LevelSceneObjectData.Type.Pail)
            {
                this.id = data.ID;
                this.x = (int)data.pos.x;
                this.y = (int)data.pos.y;
                this.z = (int)data.pos.z;
            }
        }
    }



    public class LevelPathDataToJson
    {
        public int editorID = 0;
        public List<LevelPositionToJson> points = new List<LevelPositionToJson>();
        public LevelPathDataToJson()
        { 
        
        }

        public LevelPathDataToJson(LevelPathData data)
        {
            Vector3[] ps = data.GetPoints();
            foreach (var p in ps)
            {
                points.Add(new LevelPositionToJson(p));
            }
            editorID = data.editorID;
        }
    }


    [System.Serializable]
    public class LevelPositionToJson
    {
        public int x;
        public int y;
        public int z;

        public LevelPositionToJson()
        {

        }

        public LevelPositionToJson(Vector3 position)
        {
            this.x = (int)position.x;
            this.y = (int)position.y;
            this.z = (int)position.z;

        }
    }

    //[System.Serializable]
    //public class LevelPathDataToJson
    //{
    //    public List<LevelPositionToJson> positions = new List<LevelPositionToJson>();

    //    public LevelPathDataToJson()
    //    { 

    //    }

    //    public LevelPathDataToJson(LevelPathData data)
    //    {

    //        Vector3[]poss = data.GetPoints();

    //        foreach (var p in poss)
    //        {
    //            positions.Add(new LevelPositionToJson(p));
    //        }
    //    }
    //}

    public class LevelTornadoSceneObjectToJson : LevelPailSceneObjectToJson
    {
        public List<LevelPositionToJson> path = new List<LevelPositionToJson>();

        public List<LevelPositionToJson> transmit = new List<LevelPositionToJson>();

        public LevelTornadoSceneObjectToJson()
        {

        }

        public LevelTornadoSceneObjectToJson(LevelSceneObjectData data)
        {

            if (data.type == LevelSceneObjectData.Type.Tornado)
            {
                this.id = data.ID;

                Vector3[] ps = data.pathData.GetPoints();
                foreach (var p in ps)
                {
                    this.path.Add(new LevelPositionToJson(p));
                }

                if (path.Count > 0)
                {
                    this.x = (int)path[0].x;
                    this.y = (int)path[0].y;
                    this.z = (int)path[0].z;
                }


                foreach (var k in data.transmitDatas)
                {
                    transmit.Add(new LevelPositionToJson(k.pos));
                }
            }
        }
    }

    class LevelDataToJson
    {
        public List<LevelBirthPositionToJson> birthPositions = new List<LevelBirthPositionToJson>();

        public List<LevelMonsterDropToJson> monsterDropItems = new List<LevelMonsterDropToJson>();

        public List<LevelAreaToJson> areaPass = new List<LevelAreaToJson>();





        public List<LevelMonsterDataToJson> monsters = new List<LevelMonsterDataToJson>();

        public List<LevelBatchDataToJson> batches = new List<LevelBatchDataToJson>();

        public List<LevelAreaTrapToJson> traps = new List<LevelAreaTrapToJson>();


        public List<LevelPailSceneObjectToJson> pails = new List<LevelPailSceneObjectToJson>();

        public List<LevelTornadoSceneObjectToJson> tornados = new List<LevelTornadoSceneObjectToJson>();



        public LevelMapModeToJson mapMode;


        public List<LevelPathDataToJson> paths = new List<LevelPathDataToJson>();
        
        public void AddBirthPosition(LevelBirthPositionData o)
        {
            LevelBirthPositionToJson l = new LevelBirthPositionToJson(o);
            birthPositions.Add(l);
        }

        public void AddMonsterDropItem(LevelMonsterData o)
        {
            LevelMonsterDropToJson l = new LevelMonsterDropToJson(o);
            monsterDropItems.Add(l);
        }

        public void AddAreaPass(LevelAreaData o)
        {
            LevelAreaToJson l = new LevelAreaToJson(o);
            areaPass.Add(l);
        }

    }



    public static void Save(LevelMapData data, string name)
    {
        LevelDataToJson jsonData = new LevelDataToJson();

        foreach (var d in data.birthDatas)
        {
            jsonData.AddBirthPosition(d);


        }

        foreach (var k in data.batchDatas)
        {
            foreach (var k1 in k.monsters)
            {
                jsonData.AddMonsterDropItem(k1);
            }
        }

        foreach (var d in data.initMonterDatas)
        {
            jsonData.AddMonsterDropItem(d);

        }

        foreach (var d in data.areaDatas)
        {
            //if (d.type != LevelAreaData.Type.Trap)
            //{
            jsonData.AddAreaPass(d);
            //}
        }

       

      

        foreach (var k in data.monterDatas)
        {
            jsonData.monsters.Add(new LevelMonsterDataToJson(k));
        }

        data.batchDatas.Sort((l, r) =>
        {
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

        foreach (var k in data.batchDatas)
        {
            
            jsonData.batches.Add(new LevelBatchDataToJson(k));
        }

        //foreach (var d in data.areaDatas)
        //{
        //    if (d.type == LevelAreaData.Type.Trap)
        //    {
        //        jsonData.traps.Add(new LevelAreaTrapToJson(d));
        //    }
        //}

        foreach (var d in data.sceneObjectDatas)
        {
            if (d.type == LevelSceneObjectData.Type.Pail)
            {
                jsonData.pails.Add(new LevelPailSceneObjectToJson(d));
            }
            else if (d.type == LevelSceneObjectData.Type.Tornado)
            {
                jsonData.tornados.Add(new LevelTornadoSceneObjectToJson(d));
            }
            else if (d.type == LevelSceneObjectData.Type.Quicksand)
            {
                jsonData.traps.Add(new LevelAreaTrapToJson(d));
            }
        }

        jsonData.mapMode = new LevelMapModeToJson(data.modeData);

        foreach (var k in data.pathDatas)
        {
            jsonData.paths.Add(new LevelPathDataToJson(k));
        }
        

        string str = JsonMapper.ToJson(jsonData);
        SaveJson(name, str);
    }

    static string path = Application.dataPath + "/LevelTool/Export/";
    static void SaveJson(string name, string content)
    {

        FileStream fs = new FileStream(path + name + ".txt", FileMode.Create);
        //获得字节数组  
        byte[] data = System.Text.Encoding.UTF8.GetBytes(content);
        fs.Write(data, 0, data.Length);
        fs.Flush();
        fs.Close();
    }
}
