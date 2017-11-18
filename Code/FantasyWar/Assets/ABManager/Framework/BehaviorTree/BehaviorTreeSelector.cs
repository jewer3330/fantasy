using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
    /// <summary>
    /// 并行执行的BehaviorTree
    /// </summary>
    public class BehaviorTreeSelector : BehaviorTreeBase
    {
        public List<BehaviorTreeBase> actions = new List<BehaviorTreeBase>();

        public BehaviorTreeBase currentSelect = null;

        public BehaviorTreeSelector(params BehaviorTreeBase[] actions)
        {
            this.actions.AddRange(actions);
        }

        public BehaviorTreeSelector(PreCondition preCondition,params BehaviorTreeBase[] actions)
        {
            this.preCondition = preCondition;
            this.actions.AddRange(actions);
        }

        public override void Update()
        {
            if (isPaused)
                return;
            if (preCondition != null)
            {
                if (preCondition() == false)
                {
                    return;
                }
            }
           
            if (currentSelect != null)
            {
                if (!currentSelect.IsFinished())
                {
                    currentSelect.Update();
                }
            }
        }

        public override bool IsFinished()
        {
            if (currentSelect == null)
            {
                foreach (var k in actions)
                {
                    if (k.preCondition != null)
                    {
                        if (k.preCondition())
                        {
                            currentSelect = k;
                            break;

                        }
                    }
                    else
                    {
                        currentSelect = k;
                        break;

                    }
                }
            }

            if (currentSelect != null)
            {
                if (!currentSelect.IsFinished())
                {
                    return false;
                }
            }

            return true;
        }

        public override void Reset()
        {
            foreach (var k in actions)
            {
                k.Reset();
            }
            currentSelect = null;
        }

        public override void Pause()
        {
            isPaused = true;
            foreach (var k in actions)
            {
                k.Pause();
            }
        }

        public override void Resume()
        {
            isPaused = false;
            foreach (var k in actions)
            {
                k.Resume();
            }
        }
    }
}