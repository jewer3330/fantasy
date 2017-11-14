using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
	/// <summary>
	/// 行为树的基类
	/// </summary>
	public class BehaviorTreeBase : Action
	{

		public delegate bool PreCondition ();
		public delegate bool FinishCondition ();


		public Func func;
		public PreCondition preCondition = null;
		public FinishCondition finishCondition = null;

		public bool isFuncCalled = false;
		public bool isPaused = false;

		public BehaviorTreeBase()
		{
			
		}

		public BehaviorTreeBase(Func func)
		{
			this.func = func;
		}

		public BehaviorTreeBase (Func func,PreCondition preCondition)
		{
			this.func = func;
			this.preCondition = preCondition;
		}

		public BehaviorTreeBase (Func func,PreCondition preCondition,FinishCondition finishCondition)
		{
			this.func = func;
			this.preCondition = preCondition;
			this.finishCondition = finishCondition;
		}

		public override bool IsFinished ()
		{
            if (isFuncCalled)
            {
                if (finishCondition != null)
                    return finishCondition();
                else
                    return true;
            }
            else
                return false;
				
		}

		public override void Update ()
		{
            if (isPaused)
                return;
			if (preCondition != null) {
				if (preCondition () == false) {
					return;
				}
			}

            if (isFuncCalled == false)
            {
				isFuncCalled = true;
				if (func != null)
					func ();
			}
		}

		public override void Reset ()
		{
			isFuncCalled = false;
		}

		public override void Pause ()
		{
			isPaused = true;
		}

		public override void Resume ()
		{
			isPaused = false;
		}

        public override string ToString()
        {
            return func.Method.Name;
        }
	}
}
