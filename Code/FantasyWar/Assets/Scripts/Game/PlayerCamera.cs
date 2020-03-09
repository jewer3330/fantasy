using UnityEngine;
using System.Collections;

public class PlayerCamera : MonoBehaviour {

    public Player player
    {
        set
        {
            if (value != _old)
            {
                _old = value;
                needMoveSmooth = true;
            }
        }
        get
        {
            return _old;
        }
    }
    private bool needMoveSmooth = false;
    private Player _old;
    public float delta_x;
    public float delta_y;

    public float x;
    public float y;

    public float xMinLimit;
    public float xMaxLimit;
    public float yMinLimit;
    public float yMaxLimit;
    public float targetDistance;

   
	
	// Update is called once per frame
	void Update () {
#if UNITY_EDITOR || UNITY_STANDALONE
        if (Input.GetMouseButton(0))
#else
        if (Input.touchCount == 1 && Input.GetTouch(0).phase == TouchPhase.Moved)
#endif
        {
            // if (UICamera.isOverUI)
            //     return;
            delta_x = Input.GetAxis("Mouse X") * 10;
            delta_y = Input.GetAxis("Mouse Y") * 10;
        }
        else
        {
            //xSpeed = -Input.acceleration.x * speed * 0.04f;
            //ySpeed = Input.acceleration.y * speed * 0.04f;
            delta_x = Mathf.Lerp(delta_x, 0, Time.deltaTime * 10);
            delta_y = Mathf.Lerp(delta_y, 0, Time.deltaTime * 10);
        }
    }

    public void LateUpdate()
    {
        //target为我们绑定的箱子变量，缩放旋转的参照物
        if (player)
        {
            x += delta_x;
            y += delta_y;

            x = ClampAngle(x, xMinLimit, xMaxLimit);
            //重置摄像机的位置，始终以目标为中心
            y = ClampAngle(y, yMinLimit, yMaxLimit);
            Quaternion rotation = Quaternion.Euler(y, x, 0); //绕x ,y轴 旋转相应的角度
            Vector3 position = rotation * (new Vector3(0, 0, -targetDistance)) + player.transform.position;

            //if (needMoveSmooth)
            //{
                
                transform.rotation = Quaternion.Lerp(transform.rotation, rotation, 3 * Time.deltaTime);//调整摄像机位置
                transform.position = Vector3.Lerp(transform.position, position, 3 * Time.deltaTime);
            //    if (Quaternion.Angle(transform.rotation, rotation) < 1)
            //    {
            //        if (Vector3.Distance(transform.position, position) < 0.1f)
            //        {
            //            needMoveSmooth = false;
            //        }
            //    }
            //}
            //else
            //{
            //    transform.rotation = rotation;
            //    transform.position = position;
            //}

            
        }
    }

    static float ClampAngle(float angle, float min, float max)
    {
        //规正角度
        if (angle < -360)
            angle += 360;
        if (angle > 360)
            angle -= 360;
        return Mathf.Clamp(angle, min, max);
    }
}
