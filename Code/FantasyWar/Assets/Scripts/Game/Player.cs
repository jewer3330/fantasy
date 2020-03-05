using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class Player : MonoBehaviour
{

    public Table.Character data;

    public float speed = 0.05f;
    public float currentSpeed;
    public Vector3 targetPos;
    public Vector3 targetDir;
    public float currentDis;

    public MapCell target;

    public LevelManager levelManager;

    private List<MapCell> path = new List<MapCell>();

    public bool isMoving = false;
    // Use this for initialization
    protected virtual void Start()
    {

    }

    // Update is called once per frame
    protected virtual void Update()
    {
        if (isMoving)
        {
            currentSpeed = speed;
            if (path.Count > 0)
            {
                var current = path[0];

                WalkTo(current);
                targetPos = current.transform.position + Vector3.up;
                var dir = targetPos - transform.position;
              
               
                currentDis = Vector3.Distance(transform.position, targetPos);
                //Debug.Log(currentDis);
                if (currentDis < speed)
                {
                    //Debug.Log("close to target position");

                    bool isOk = false;
                    if (dir.normalized == Vector3.zero)
                    {
                        //Debug.Log("zero dir");
                        isOk = true;
                    }
                    if (Vector3.Dot(dir.normalized, targetDir.normalized) < 0)
                    {
                        //Debug.Log("inverse dir");
                        isOk = true;
                    }
                    if (isOk)
                    {
                        path.RemoveAt(0);
                        return;
                    }
                    else
                    {
                        targetDir = dir;
                    }
                }
                else
                {

                    targetDir = dir;
                }


            }
            else
            {
                currentSpeed = 0;
                isMoving = false;
                levelManager.ResetState(target);
            }
        }
    }

    private void LateUpdate()
    {
        if (isMoving)
        {

            transform.position = targetDir.normalized * currentSpeed + transform.position;
            //transform.forward = targetDir.normalized;
            transform.rotation = Quaternion.Slerp(transform.rotation,  Quaternion.LookRotation(targetDir.normalized),Time.deltaTime * 10);
        }

    }


    public void Move(List<MapCell> way)
    {
        if (!isMoving)
        {
            isMoving = true;
            path.Clear();
            if (path != way)
                path.AddRange(way);
        }
    }

    public void WalkTo(MapCell cell)
    {
        if (target != cell)
        {
            target = cell;
        }
    }


}
