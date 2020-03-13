using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using SuperBoBo;

public class UITaketurns : MonoBehaviour {

	public const string ChangeName = "ChangeName";

	public Text title;

    private Action act;

    private void Awake()
    {
		title = gameObject.GetComponent<Text>();
		SuperBoBo.EventManager.Instance.Reg<string>(ChangeName, OnChangeTitle);

	}


    private void OnDestroy()
    {
		SuperBoBo.EventManager.Instance.UnReg<string>(ChangeName, OnChangeTitle);

	}

	void OnChangeTitle(string eventName,string title)
	{
		SetTitle(title);
        act = new ActionDelay(3, () =>
        {
            gameObject.SetActive(false);
        });
        act.Reset();

        Timer.Instance.Run(act);
    }

	public void SetTitle(string title)
	{
		this.title.text = title;
    }
}
