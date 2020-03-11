using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;


namespace NodeCanvas.Tasks.Actions
{

    [Name("Random Select Cell")]
    [Category("Movement")]
    public class RandomCell : ActionTask<Player>
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
                    return "not find cell";
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
            if (null == agent.levelManager.canMoveArea)
            {
                EndAction(false);
            }

            int rand = UnityEngine.Random.Range(0, agent.levelManager.canMoveArea.Count);
            cell = agent.levelManager.canMoveArea[rand];

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