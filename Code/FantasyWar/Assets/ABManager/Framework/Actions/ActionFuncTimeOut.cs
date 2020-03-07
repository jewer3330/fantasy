using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
	/// <summary>
	/// 在Func必须是抛出事件的不阻塞方法，否则请不要使用这个类
	/// </summary>
	public class ActionTimeOut : Action
	{
		/// <summary>
		/// 该方法必须是非阻塞方法，且成功后应发出事件，跳出当前的Action
		/// </summary>
		public System.Action func;

		public float timeout;

        public System.Action<float> timeoutFunc;
        
        public float timeStart;

        public bool isTimeoutFuncCalled;


        public bool isPaused;

        public bool isFinished;
        public ActionTimeOut(System.Action func, float timeout, System.Action<float> timeOutFunc = null)
		{
			this.func = func;
            this.timeout = timeout;
            this.timeoutFunc = timeOutFunc;
            this.timeStart = Timer.Instance.timeTick;
		}

       
      

		public override bool IsFinished ()
		{
            return Timer.Instance.timeTick > (timeStart + timeout) && isTimeoutFuncCalled;
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
            if (Timer.Instance.timeTick > (timeStart + timeout))
            {
                if (timeoutFunc != null && isTimeoutFuncCalled == false)
                {
                    isTimeoutFuncCalled = true;
                    timeoutFunc(Timer.Instance.timeTick - timeStart);
                }
            }
		}

		public override void Reset ()
		{
            this.timeStart = Timer.Instance.timeTick;
            isTimeoutFuncCalled = false;
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