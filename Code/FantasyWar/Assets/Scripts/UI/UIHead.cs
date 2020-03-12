using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIHead : MonoBehaviour
{

    public Text playerName;

    public Player target;

    private Camera mainCamera;

    private LevelManager levelManager;

    public Vector3 targetPosition;
    public Vector3 offset;

    private void Awake()
    {
        playerName = gameObject.GetComponent<Text>();
    }

    public void SetTarget(Player player)
    {
        this.target = player;
        playerName.text = player.data.Name;
    }


    private void LateUpdate()
    {
        targetPosition = UIManager.Instance.WolrdToUICameraPostion(target.transform.position + offset);
        //transform.position = Vector3.Lerp(transform.position, targetPosition, Time.deltaTime);
        RectTransform rect = transform as RectTransform;
        rect.localPosition = targetPosition;
    }
}
