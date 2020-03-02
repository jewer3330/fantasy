using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class SelectGameObject : MonoBehaviour
{
    public Dictionary<GameObject, System.Action<GameObject>> clickCallback = new Dictionary<GameObject, System.Action<GameObject>>();
    public static SelectGameObject instance;
    public RaycastHit hit;
    public void AddListener(GameObject gameObject, System.Action<GameObject> callback)
    {
        if (callback == null)
            return;
        System.Action<GameObject> func = null;
        if (clickCallback.TryGetValue(gameObject, out func))
        {
            func += callback;
        }
        else
        {
            clickCallback.Add(gameObject, callback);
        }
    }
    private void Awake()
    {
        instance = this;
    }

    private void OnDestroy()
    {
        instance = null;
    }
    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        
        Vector3 position = Vector3.zero;
#if UNITY_EDITOR
        if (Input.GetMouseButtonUp(0))
        {
            position = Input.mousePosition;
        }
#else
        if (Input.touchCount > 0 && Input.touches[0].phase == TouchPhase.Ended && !UICamera.isOverUI)
        {
            position = Input.touches[0].position;
        }

#endif  
        Ray ray = Camera.main.ScreenPointToRay(position);

        if (Physics.Raycast(ray, out hit))
        {
            //Debug.Log(hit.collider.gameObject);
            System.Action<GameObject> func = null;
            if (clickCallback.TryGetValue(hit.collider.gameObject, out func))
            {
                if (func != null)
                    func.Invoke(hit.collider.gameObject);
            }
        }
    }
}
