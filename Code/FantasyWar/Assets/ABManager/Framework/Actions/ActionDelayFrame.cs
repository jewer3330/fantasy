using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
	public class ActionDelayFrame : Action
	{
		System.Action fun;
		int delayFrameCount;
		bool ispause = false;
		int currentFrame = 0;
		bool isFinished = false;

		public ActionDelayFrame (int frameCount, System.Action f)
		{
			fun = f;
			delayFrameCount = frameCount;
			currentFrame = 0;
		}

		public override void Update ()
		{
			if (ispause)
				return;
			if (!IsFinished ()) {
				currentFrame++;
				if (currentFrame > delayFrameCount) {
					isFinished = true;
					if (fun != null) {
						fun ();
					}
				}
			}
		}

		public override bool IsFinished ()
		{
			return isFinished;
		}

		public override void Pause ()
		{
			ispause = true;
		}

		public override void Resume ()
		{
			ispause = false;
		}
	}
}