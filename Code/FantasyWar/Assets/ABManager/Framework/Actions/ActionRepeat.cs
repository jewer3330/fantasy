using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
	/// <summary>
	/// 重复动作
	/// </summary>
	public class ActionRepeat : Action
	{

		public List<Action> actions = new List<Action> ();

		public int repeatCount = 0;
		public int repeatTotal = 0;
		public bool isPaused = false;

		public ActionRepeat (params Action[] actions)
		{
			this.actions.AddRange (actions);
		}

		public ActionRepeat (int repeat, params Action[] actions)
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