using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using SuperBoBo;

public class Player : MonoBehaviour
{
    public enum Type
    {
        Player,
        Npc,
    }

    public enum Action
    {
        None,
        Idle,
        Moving,
        TurnToPlayer,
        Attack,
        Attacked,
    }

    public Action action = Action.None;


    public Type type = Type.Player;

    public Table.Character data;

    public float speed = 0.05f;
    public float currentSpeed;
    public Vector3 targetPos;
    public Vector3 targetDir;
    public float currentDis;

    public MapCell target;

    public LevelManager levelManager;

    private List<MapCell> path = new List<MapCell>();

    public bool isSelected = false;

    public bool IsPlayer
    {
        get
        {
            return type == Type.Player;
        }
    }

    private UIHead head;

    public Player playerNearBy;

    public AnimationManager manager;

    public int Hp = 100;


    protected virtual void Awake()
    {
        type = Type.Player;
        manager = GetComponent<AnimationManager>();
        
    }

    private void GenUI()
    {
        ResManager.LoadAsync("UI/UIHead", (obj) =>
        {
            var go = Instantiate(obj) as GameObject;
            head = go.GetComponent<UIHead>();
            head.SetTarget(this);
            UIManager.Instance.AddWidget(go);
        });
    }


    // Use this for initialization
    protected virtual void Start()
    {
        GenUI();
    }

    // Update is called once per frame
    protected virtual void Update()
    {
        switch (action)
        {
            case Action.Attack:
                if (playerNearBy)
                {
                    Attack(playerNearBy);
                }
                action = Action.Attacked;
                break;
            case Action.Idle:
                levelManager.ResetState();
                action = Action.None;
                break;
            case Action.Moving:
                currentSpeed = speed;
                if (path.Count > 0)
                {
                    var current = path[0];

                    WalkTo(current);
                    targetPos = current.transform.position + Vector3.up;
                    var dir = targetPos - transform.position;

                    currentDis = Vector3.Distance(transform.position, targetPos);
                    if (currentDis < speed && (dir.normalized == Vector3.zero || Vector3.Dot(dir.normalized, targetDir.normalized) < 0 ))
                    {
                        path.RemoveAt(0);
                        break;
                        
                    }
                    else
                    {
                        targetDir = dir;
                    }
                }
                else
                {
                    currentSpeed = 0;
                    action = Action.Idle;
                    if (IsNpcOneBlock(out playerNearBy))
                    {
                        targetDir = (playerNearBy.transform.position - transform.position).normalized;
                        action = Action.TurnToPlayer;
                    }
                }
                break;
            case Action.TurnToPlayer:
                if (Vector3.Angle(transform.forward, targetDir) < 1)
                {
                    action = Action.Attack;
                }
                break;
            case Action.Attacked:
            default:
                break;
        }
    }

    private void LateUpdate()
    {
        switch(action)
        {
            case Action.Moving:
                transform.position = targetDir.normalized * currentSpeed + transform.position;
                transform.rotation = Quaternion.Slerp(transform.rotation,  Quaternion.LookRotation(targetDir.normalized),Time.deltaTime * 10);
                break;
            case Action.TurnToPlayer:
                transform.rotation = Quaternion.Slerp(transform.rotation,  Quaternion.LookRotation(targetDir.normalized),Time.deltaTime * 10);
                break;
        }

    }


    

    public void Move(List<MapCell> way)
    {
        if (action == Action.None)
        {
            action = Action.Moving;
            path.Clear();
            if (path != way)
                path.AddRange(way);
        }
    }

    public void WalkTo(MapCell cell)
    {
        if (target != cell)
        {
            target.player = null;
            target = cell;
            target.player = this;
        }
    }

    public bool IsNpcOneBlock(out Player player)
    {
        player = null;
        if (target)
        {
            var cells = target.GetCloseCells();
            foreach (var k in cells)
            {
                if (k.player && k.player != this)
                {
                    player = k.player;
                    return true;
                }
            }
        }
        return false;
    }

    public void Attack(Player player)
    {
       
        if (player != this)
        {
            manager.Attack();
            int dmg = data.AT - player.data.DF;
            Timer.Instance.Run(
                new ActionDelay(1 ,
            ()=>{
                    player.OnHurt(dmg);
                    action = Action.Idle;
                }
            ));
            
        }
    }

    public struct HurtArgs
    {
        public Player target;
        public int dmg;
    }

    public void OnHurt(int dmg)
    {
        Hp -= dmg;
        manager.Hurt();
        SuperBoBo.EventManager.Instance.FireEvent(UIHead.HURT, new HurtArgs() { target = this,dmg = dmg});
    }


}
