using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
	/// <summary>
	/// 顺序执行的BehaviorTree
	/// </summary>
	public class BehaviorTreeSequence : BehaviorTreeBase
	{
		public List<BehaviorTreeBase> actions = new List<BehaviorTreeBase> ();

		public List<BehaviorTreeBase> orgin = new List<BehaviorTreeBase> ();


		public BehaviorTreeSequence (params BehaviorTreeBase[] actions)
		{
			this.actions.AddRange (actions);
			this.orgin.AddRange (actions);
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
			if (actions.Count > 0) {
				if (actions [0].IsFinished ()) {
					actions.RemoveAt (0);
				} else {
					actions [0].Update ();
				}
			}
		}

		public override bool IsFinished ()
		{

			return actions.Count == 0;
		}

		public override void Reset ()
		{
			actions.Clear ();
			foreach (var k in orgin) {
				actions.Add (k);
			}
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
