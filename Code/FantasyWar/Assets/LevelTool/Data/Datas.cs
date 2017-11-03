using UnityEngine;
using System.Collections;
using System.Collections.Generic;



    [System.Serializable]
    public class LevelBaseData
    {

        /// <summary>
        /// 编辑器唯一ID
        /// </summary>
        public int editorID;

        /// <summary>
        /// editor extra info isShow
        /// </summary>
        //public bool isShow = true;

        public bool isVisible = true;
        /// <summary>
        /// 显示的字体大小
        /// </summary>
        public int fontSize = 20;

        /// <summary>
        /// 显示的颜色
        /// </summary>
        public Color32 nameColor = Color.white;

      

        public Vector3 pos = Vector3.zero;
        public Vector3 dir = Vector3.zero;
        public Vector3 scale = Vector3.one;
        public int ID;
        public string name;
        public virtual LevelBaseData Clone()
        {

            return (LevelBaseData)this.MemberwiseClone();
        }

        public virtual void Save(LevelMapData data)
        {

        }

       

        public virtual void Copy(LevelBaseData b)
        {
            this.pos = b.pos;
            this.dir = b.dir;
            this.scale = b.scale;
        }

        public override bool Equals(object obj)
        {
            LevelBaseData o = obj as LevelBaseData;

            return (o.pos == this.pos
                && o.dir == this.dir
                && o.scale == this.scale);
        }
    }




    /// <summary>
    /// 触发器数据
    /// </summary>
    [System.Serializable]
    [System.Obsolete]
    public class LevelTriggleData : LevelBaseData
    {

        
        public List<LevelBatchData> batches = new List<LevelBatchData>();

        public LevelTriggleData()
        {

        }

        public LevelTriggleData(int id, string name)
        {
            this.ID = id;
            this.name = name;
        }

        public override void Copy(LevelBaseData b)
        {
            base.Copy(b);
            this.batches = (b as LevelTriggleData).batches;
        }

        public override void Save(LevelMapData data)
        {
            
        }

        //public override void Save(Level.LevelData data)
        //{
        
        //}


    }



    [System.Serializable]
    public class LevelDoorData : LevelBaseData
    {
        public int m_batchIndex;
        public string m_meshName;
        public int index;

        public override void Save(LevelMapData data)
        {
            //data.m_listMechanism.Add(DatasAdapter.ChangeToLevelMechanism(this));
            data.doorDatas.Add(this);
        }

        //public override void Save(Level.LevelData data)
        //{
        //    data.m_listMechanism.Add(DatasAdapter.ChangeToLevelMechanism(this));
        //}
    }

    

    [System.Serializable]

    public class LevelPropData : LevelBaseData
    {
        public int type;

        public int condition;
        public bool onWhenStart;
        public int timeInterval;
        public int loop;

        public List<Vector3> positions = new List<Vector3>();

        public LevelPropData()
        { 
            
        }


        public override void Save(LevelMapData data)
        {
            data.propDatas.Add(this);
        }

        //public override void Save(Level.LevelData data)
        //{
        //}
    }

   

    [System.Serializable]
    public class LevelPositionData : LevelBaseData
    {
        public enum Type
        { 
            Prop,
            Tornado
        }

        public Type type = Type.Prop;
        public override void Save(LevelMapData data)
        {
            data.positionDatas.Add(this);
        }
    }

