using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{

	/// <summary>
	/// 延时Action
	/// @warning 最小延迟1帧
	/// </summary>
	public class ActionDelay : Action
	{
		public float delay = 0;
		public float timeStart = 0;
		public bool isFinished = false;
		public Func func;

		public float delta = 0;
		public bool isPaused = false;
		public float timePause = 0;

		public ActionDelay (float time)
		{
			this.delay = time;
			this.timeStart = Timer.Instance.timeTick;
			//.Log("ActionDelay timeStart " + timeStart);
		}

		public ActionDelay (float time, Func func)
			: this (time)
		{
			if (func != null)
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

			if (!IsFinished ()) {
				delta = (Timer.Instance.timeTick - (delay + timeStart));
				if (delta >= 0) {
					isFinished = true;
					//.Log("ActionDelay run " + Timer.Instance.timeTick + " 延迟 " + delta);
					if (func != null) {
						func ();
					}
				}
			}
		}

		public override void Reset ()
		{
			//.Log("ActionDelay timeResetSpend " + timeResetSpend);
			timeStart = timeStart + delay;
			//Debug.Log("ActionDelay reset " + timeStart);
			isFinished = false;
		}

		public override void Pause ()
		{
			timePause = Timer.Instance.timeTick;
			//Debug.Log("ActionDelay timePause " + timePause);
			isPaused = true;
		}

		public override void Resume ()
		{
			float timeHasSpend = (timePause - timeStart);
			//Debug.Log("ActionDelay time " + Timer.Instance.timeTick);
			//Debug.Log("ActionDelay timeHasSpend " + timeHasSpend);
			timeStart = Timer.Instance.timeTick - timeHasSpend;
			//Debug.Log("ActionDelay timeReStart " + timeStart);
			isPaused = false;
		}
	}
}