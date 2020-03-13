using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;


namespace NodeCanvas.Tasks.Actions
{

    [Name("Move To Player Cell")]
    [Category("Movement")]
    public class MoveToPlayerCell : ActionTask<Player>
    {

        private MapCell cell;

        protected override string info
        {
            get
            {
                if (cell)
                {
                    return string.Format("Go to ({0},{1})", cell.data.x, cell.data.y);
                }
                else
                {
                    return "Go to player";
                }

            }
        }

        protected override void OnExecute()
        {
            Select();
        }

        void Select()
        {
            if (!agent)
            {
                EndAction(false);
            }
            if (!agent.levelManager)
            {
                EndAction(false);
            }
            var area = agent.levelManager.canMoveArea;
            if (null == area)
            {
                EndAction(false);
            }
            var player = agent.levelManager.FindNearByPlayer(agent);
            cell = agent.levelManager.FindNearByCell(area, player);

            var select = agent.levelManager.FindIndicator(cell);
            agent.levelManager.HighLightIndicator(select);
            EndAction(true);
        }

        protected override void OnUpdate()
        {
            Select();
        }


    }
}