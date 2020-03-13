using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIHead : MonoBehaviour
{

    public Text playerName;
    public Text playerHp;

    public Player target;

    private Camera mainCamera;

    private LevelManager levelManager;

    public Vector3 targetPosition;
    public Vector3 offset;

    public const string HURT = "UIHEAD.HURT";

    private void Awake()
    {
        playerName = gameObject.GetComponent<Text>();
        SuperBoBo.EventManager.Instance.Reg<Player.HurtArgs>(HURT, OnDamage);
    }

    private void OnDestroy()
    {
        SuperBoBo.EventManager.Instance.UnReg<Player.HurtArgs>(HURT, OnDamage);
    }

    private void OnDamage(string arg1, Player.HurtArgs arg2)
    {
        if (arg1 == HURT)
        {
            if (target == arg2.target)
            {
                playerHp.text = target.Hp.ToString();
                UIManager.Instance.ShowTips(targetPosition, arg2.dmg.ToString());
            }
        }
    }

    public void SetTarget(Player player)
    {
        this.target = player;
        playerName.text = player.data.Name;
        playerHp.text = player.Hp.ToString();
    }

    

    private void LateUpdate()
    {
        targetPosition = UIManager.Instance.WolrdToUICameraPostion(target.transform.position + offset);
        //transform.position = Vector3.Lerp(transform.position, targetPosition, Time.deltaTime);
        RectTransform rect = transform as RectTransform;
        rect.localPosition = targetPosition;
    }
}
