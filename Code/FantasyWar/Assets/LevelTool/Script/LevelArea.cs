using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class LevelArea : LevelObjectBase {

    public int con_select = 0;



    public override string GetGizmoName()
    {
        return name + " $" + data.editorID;
    }

   
    public List<LevelArea> areas = new List<LevelArea>();

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
