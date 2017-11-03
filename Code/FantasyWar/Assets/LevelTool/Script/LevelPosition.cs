using UnityEngine;
using System.Collections;



public class LevelPosition : LevelObjectBase 
{



    void OnDrawGizmos()
    {
        Gizmos.color = new Color(1, 0, 0.5f, 0.5f);
        Gizmos.DrawSphere(transform.position, 5);
    }

    public override string GetGizmoName()
    {
        return "";
    }
}
