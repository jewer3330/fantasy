using UnityEngine;
using System.Collections;



public class LevelSceneObject : LevelObjectBase
{


	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    public override string GetGizmoName()
    {
        return data.name;
    }
}
