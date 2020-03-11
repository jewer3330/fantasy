using System.Collections;
using System.Collections.Generic;
using NodeCanvas.BehaviourTrees;
using NodeCanvas.Framework;
using SuperBoBo;
using UnityEngine;

public class NpcPlayer : Player
{
    public BehaviourTreeOwner owner;
    public Blackboard blackboard;
    public string aiResPath = "AI/Simple";
    public string bbResPath = "AI/bb";

    protected override void Awake()
    {
        owner = GetComponent<BehaviourTreeOwner>();
        if (!owner)
        {
            owner = gameObject.AddComponent<BehaviourTreeOwner>();
        }

        blackboard = GetComponent<Blackboard>();
        if (!blackboard)
        {
            blackboard = gameObject.AddComponent<Blackboard>();
        }

        ResManager.LoadAsync(aiResPath, (obj) =>
        {
            BehaviourTree bt = obj as BehaviourTree;
            owner.behaviour = Instantiate(bt);

        });

        ResManager.LoadAsync(bbResPath, (obj) =>
        {
            TextAsset ta = obj as TextAsset;
            blackboard.Deserialize(ta.text);
        });

        type = Type.Npc;
    }

    protected override void Start()
    {
        
    }

    protected override void Update()
    {
        base.Update();
        blackboard.SetValue("State", levelManager.state);
    }

}
