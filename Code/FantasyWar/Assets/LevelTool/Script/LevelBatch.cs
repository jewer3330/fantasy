using UnityEngine;
using System.Collections;
using System.Collections.Generic;




public class LevelBatch : LevelObjectBase
{


    public List<LevelMonster> monsters = new List<LevelMonster>();
    public Color color = Color.white;
    


    public override string GetGizmoName()
    {
        return "";//base.GetGizmoName() + " ID:" + data.ID;
    }
}

