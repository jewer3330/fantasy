using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
	/// <summary>
	/// 并行执行的Action
	/// </summary>
	public class ActionTogether : Action
	{
		public List<Action> actions = new List<Action> ();

		public bool isPaused = false;

		public ActionTogether (params Action[] actions)
		{
			this.actions.AddRange (actions);
		}

		public override void Update ()
		{
			if (isPaused)
				return;
			foreach (var k in actions) {
				if (!k.IsFinished ()) {
					k.Update ();
				}
			}
		}

		public override bool IsFinished ()
		{

			foreach (var k in actions) {
				if (!k.IsFinished ()) {
					return false;
				}
			}

			return true;
		}

		public override void Reset ()
		{
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