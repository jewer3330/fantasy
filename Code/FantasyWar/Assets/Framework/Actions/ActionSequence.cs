using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
	/// <summary>
	/// 顺序执行的Action
	/// </summary>
	public class ActionSequence : Action
	{
		public List<Action> actions = new List<Action> ();

		public List<Action> orgin = new List<Action> ();

		public bool isPaused = false;

		public ActionSequence (params Action[] actions)
		{
			this.actions.AddRange (actions);
			this.orgin.AddRange (actions);
		}

		public override void Update ()
		{
			if (isPaused)
				return;
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
