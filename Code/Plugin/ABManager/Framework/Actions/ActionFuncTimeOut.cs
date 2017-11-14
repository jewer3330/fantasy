using UnityEngine;
using System.Collections.Generic;
using System.Collections;

namespace SuperBoBo
{
	/// <summary>
	/// 在Func必须是抛出事件的不阻塞方法，否则请不要使用这个类
	/// </summary>
	public class ActionFuncTimeOut : Action
	{
        /// <summary>
        /// 该方法必须是非阻塞方法，且成功后应发出事件，跳出当前的Action
        /// </summary>
        public delegate void EventFunc();

		public float timeout;

        public TimeFunc timeoutFunc;
        
        public float timeStart;

        public bool isTimeoutFuncCalled;

        public EventFunc func;

        public bool isPaused;

        public bool isFinished;
        public ActionFuncTimeOut(EventFunc func, float timeout, TimeFunc timeOutFunc = null)
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