using UnityEngine;
using System.Collections;



public class LevelPath : LevelObjectBase
{

    public Color color = Color.white;
    public bool show = true;




    public override string GetGizmoName()
    {
        return "路径" + ((LevelPathData)data).ID;
    }

}

