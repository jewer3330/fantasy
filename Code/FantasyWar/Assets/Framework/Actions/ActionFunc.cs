using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
	/// <summary>
	/// 执行某个函数Action
	/// 该类认为在回调函数执行之前，动作已经完成
	/// </summary>
	public class ActionFunc : Action
	{
		public Func func;
		public bool isFinished = false;
		public bool isPaused = false;

		public ActionFunc (Func func)
		{
			this.func = func;
		}

		public override bool IsFinished ()
		{
			return isFinished;
		}

		public override void Update ()
		{
			if (isPaused)
				return;
			if (!isFinished) {
				isFinished = true;
				if (func != null)
					func ();
			}
		}

		public override void Reset ()
		{
			isFinished = false;
		}

		public override void Pause ()
		{
			isPaused = true;
		}

		public override void Resume ()
		{
			isPaused = false;
		}
	}
}