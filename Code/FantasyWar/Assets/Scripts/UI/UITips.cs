using System.Collections;
using System.Collections.Generic;
using DG.Tweening;
using UnityEngine;
using UnityEngine.UI;

public class UITips : MonoBehaviour {

    public Text text;
    public Color from;
    public Color end;
    public float alpha = 0.5f;
    public float time = 1;
    public Vector2 offset = new Vector2(0, 15);
    private void Awake()
    {
        text = GetComponent<Text>();
    }

    public void DoAction(Vector2 local,string tip)
    {
        transform.localPosition = local;
        transform.DOLocalMove(local + offset, time).From(local);
        text.DOFade(alpha, time).From(1).onComplete =
            ()=>{
                UIManager.Instance.tips.Return(this);
            };
        text.text = tip;
        text.DOColor(this.end, time).From(this.from);
        text.DORestart();
        
    }
}
