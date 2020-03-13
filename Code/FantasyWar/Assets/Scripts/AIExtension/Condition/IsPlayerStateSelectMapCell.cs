using NodeCanvas.Framework;
using NodeCanvas.Framework.Internal;
using ParadoxNotion.Design;
using UnityEngine;


namespace NodeCanvas.Tasks.Conditions
{

    [Category("✫ Blackboard")]
    public class IsPlayerStateSelectMapCell : ConditionTask<Player>
    {


        protected override string info
        {
            get
            {
                return "player select map cell ";
            }
        }

        protected override bool OnCheck()
        {
            if (!agent)
                return false;
            return agent.action == Player.Action.SelectMapCell;
        }


    }
}