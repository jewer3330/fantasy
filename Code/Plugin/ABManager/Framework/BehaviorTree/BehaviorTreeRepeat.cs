using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
	/// <summary>
	/// 重复BehaviorTree,组重置
	/// </summary>
	public class BehaviorTreeRepeat : BehaviorTreeBase
	{

		public List<BehaviorTreeBase> actions = new List<BehaviorTreeBase> ();

		public int repeatCount = 0;
		public int repeatTotal = 0;

        /// <summary>
        /// 重复BehaviorTree,组重置当整个组都完成时，才会重置，单个使用和复合使用有区别
        /// </summary>
		public BehaviorTreeRepeat (params BehaviorTreeBase[] actions)
		{
			this.actions.AddRange (actions);
		}

		public BehaviorTreeRepeat (int repeat, params BehaviorTreeBase[] actions)
		{
			if (repeat <= this.repeatTotal) {
				Debug.Log ("error num");
			} else {
				this.repeatTotal = repeat;
			}
			this.actions.AddRange (actions);
		}

		public override bool IsFinished ()
		{
			if (repeatTotal == 0)
				return false;
			else
				return repeatCount == repeatTotal;
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
			
			bool isAllFinished = true;
			foreach (var k in actions) {
				if (!k.IsFinished ()) {
					k.Update ();
					isAllFinished = false;
				}
			}

			if (isAllFinished) {
				repeatCount++;
				foreach (var k in actions) {
					k.Reset ();
				}
			}
		}

		public override void Reset ()
		{

			repeatCount = 0;
			foreach (var k in actions) {
				k.Reset ();
			}
		}

		public override void Pause ()
		{
			isPaused = true;
			foreach (var k in actions) {
				k.Pause ();
			}
		}

		public override void Resume ()
		{
			isPaused = false;
			foreach (var k in actions) {
				k.Resume ();
			}
		}
	}
}
