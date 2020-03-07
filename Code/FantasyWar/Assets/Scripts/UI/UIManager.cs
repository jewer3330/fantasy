using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using SuperBoBo;

public class UIManager : MonoBehaviour
{
	public static UIManager Instance;


	public Camera UICamera;

	public Canvas hudRoot;

	public List<GameObject> widgets = new List<GameObject>();

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

    private void Awake()
    {
		DontDestroyOnLoad(this);
        
        if(Instance)
		{
			Debug.LogWarning("uimanager is aready exsit,please keep one");
        }
		Instance = this;
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
}
