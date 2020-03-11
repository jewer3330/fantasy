using NodeCanvas.Framework;
using NodeCanvas.Framework.Internal;
using ParadoxNotion.Design;
using UnityEngine;


namespace NodeCanvas.Tasks.Conditions
{

    [Category("✫ Blackboard")]
    public class IsNpcTurn : ConditionTask<Player>
    {


        protected override string info
        {
            get
            {
                if (!agent)
                    return "agent null";
                return "ai start ";
            }
        }

        protected override bool OnCheck()
        {
            if (!agent)
                return false;
            if (!agent.levelManager)
                return false;
            if (!agent.IsPlayer)
            {
                return agent.levelManager.selectPlayer == agent;
            }
            return false;
        }


    }
}