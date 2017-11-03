using UnityEngine;
using System.Collections;



public class LevelPathNode : LevelObjectBase
    {
        public string nodeName;
        public Vector3 position;




        public override string GetGizmoName()
        {
            return  data.name + " $" + data.editorID;
        }

    }



