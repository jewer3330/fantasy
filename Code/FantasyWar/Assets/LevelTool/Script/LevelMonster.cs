using UnityEngine;
using System.Collections;



public class LevelMonster : LevelObjectBase
{



    public float fade;

    public LevelPath path;




    public override string GetGizmoName()
    {
        return ((LevelMonsterData)data).name + " $" + data.editorID;
    }
}
