using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
	/// <summary>
	/// 顺序执行的Action
	/// </summary>
	public class ActionSwitch : Action
	{
		public List<Action> actions = new List<Action> ();

		public bool isPaused = false;

		public bool isFinished = false;

		public int random;

		public ActionSwitch (params Action[] actions)
		{
			this.actions.AddRange (actions);
			isFinished = false;
			random = Random.Range (0, actions.Length);
			//Debug.Log ("ActionSwitch " + random);
		}

		public override void Update ()
		{
			if (isPaused)
				return;
			if (actions.Count > 0) 
			{
				if (actions [random].IsFinished ()) {
					isFinished = true;
					//Debug.Log ("ActionSwitchFinished " + random);
				} else {
					actions [random].Update ();
				}
			}

		}

		public override bool IsFinished ()
		{
			

			return isFinished;
		}

		public override void Reset ()
		{
			random = Random.Range (0, actions.Count);
			//Debug.Log ("ActionSwitchReset " + random);
			isFinished = false;
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
