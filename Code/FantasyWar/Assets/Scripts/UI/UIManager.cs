using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using SuperBoBo;

public class UIManager : MonoBehaviour
{
	public static UIManager Instance;


	public Camera UICamera;
    public Camera mainCamera;

	public Canvas hudRoot;

	public HashSet<GameObject> widgets = new HashSet<GameObject>();

    public EasyPool<UITips> tips = new EasyPool<UITips>();

    private GameObject tipRes;

	public enum Type
	{
        Background = 0,
        Page = 100,
    }

	public class Data
	{

    }

	public void AddWidget(GameObject ui)
	{
		if (!widgets.Contains(ui))
		{
			ui.transform.SetParent(hudRoot.transform, false);
			widgets.Add(ui);
		}
	}


    public void ShowTips(Vector2 localposition, string tip)
    {
        var uitip = tips.Get();
        if(uitip)
            uitip.DoAction(localposition,tip);
    }



    private void Awake()
    {
		DontDestroyOnLoad(this);
        
        if(Instance)
		{
			Debug.LogWarning("uimanager is aready exsit,please keep one");
        }
		Instance = this;
        mainCamera = Camera.main;

        
        ResManager.LoadAsync("UI/UITips", (res) =>
        {
            tipRes = res as GameObject;
        });

        tips.Init(() =>
        {
            if (tipRes)
            {
                var go = Instantiate(tipRes);
                var tip = go.GetComponent<UITips>();
                AddWidget(go);
                return tip;
            }
            return null;
        });
    }
    private void OnDestroy()
    {
		Instance = null;
    }

    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		Timer.Instance.Update();
	}

    public Vector3 WolrdToUICameraPostion(Vector3 world)
    {
        //Vector3 sceenPosition = mainCamera.WorldToScreenPoint(world);
        //if (sceenPosition.z < 0) //
        //    return Vector3.one * 1000;
        //Vector3 uiWorldPosition = UICamera.ScreenToWorldPoint(sceenPosition);

        //return hudRoot.transform.InverseTransformPoint(uiWorldPosition);

        return hudRoot.transform.InverseTransformPoint(UICamera.ViewportToWorldPoint(mainCamera.WorldToViewportPoint(world)));

        //return hudRoot.transform.worldToLocalMatrix * UICamera.cameraToWorldMatrix * mainCamera.worldToCameraMatrix * new Vector4(world.x, world.y, world.z, 1);

    }

}
