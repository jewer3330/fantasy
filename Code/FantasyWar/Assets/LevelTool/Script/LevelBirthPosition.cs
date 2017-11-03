using UnityEngine;
using System.Collections;


public class LevelBirthPosition : LevelObjectBase
{

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    public override string GetGizmoName()
    {
        LevelBirthPositionData data = GetData() as LevelBirthPositionData;

        return "出生点" + " $" + data.editorID +  " 阵营 " + data.camp;
    }


    void OnDrawGizmos()
    {
        Gizmos.color = Color.green;
        Gizmos.DrawLine(transform.position,transform.position + transform.forward * 6);
    }


}
