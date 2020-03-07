using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using SuperBoBo;

public class UITaketurns : MonoBehaviour {

	public const string ChangeName = "ChangeName";

	public Text title;
    private void Awake()
    {
		title = gameObject.GetComponent<Text>();
		SuperBoBo.EventManager.Instance.Reg<string>(ChangeName, OnChangeTitle);

	}
	// Use this for initialization
	void Start ()
    {
		Timer.Instance.Run(new ActionDelay(3, () => {
			gameObject.SetActive(false);
		}));
	}

    private void OnDestroy()
    {
		SuperBoBo.EventManager.Instance.UnReg<string>(ChangeName, OnChangeTitle);

	}

	void OnChangeTitle(string eventName,string title)
	{
		SetTitle(title);
	}

	public void SetTitle(string title)
	{
		this.title.text = title;
    }
}
