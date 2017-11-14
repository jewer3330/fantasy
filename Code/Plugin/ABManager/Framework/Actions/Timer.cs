using UnityEngine;
using System.Collections;
using System.Collections.Generic;

namespace SuperBoBo
{
	/// <summary>
	/// 计时器
	/// by zj
	/// 2016-3-28 15:10:13
	/// </summary>
	public class Timer : Singleton<Timer>
	{

		public List<Action> actions = new List<Action> ();

		public float timeTick = 0;

        public Action current;
		public void Run (Action a)
		{
			if (a != null && !actions.Contains (a)) {
				this.actions.Add (a);
				//Debug.Log ("Timer run");
			}
		}

		public void Stop (Action a)
		{
			if (a != null && actions.Contains (a)) {
				this.actions.Remove (a);
				//Debug.Log ("Timer stop");
			}
		}

        public void Stop()
        {

            actions.Clear();
            
        }

		public void Update ()
		{
			timeTick = Time.time;
			for (int i = 0; i < actions.Count; i++) {
                if (!actions[i].IsFinished())
                {
                    current = actions[i];
                    actions[i].Update();
                }
                else
                {
                    actions.RemoveAt(i);
                }
			}
            current = null;
			//Debug.Log ("Timer Counter " + actions.Count);
		}

		public void Pause ()
		{
			foreach (var k in actions) {
				k.Pause ();
			}
		}

		public void Resume ()
		{
			foreach (var k in actions) {
				k.Resume ();
			}
		}

		public void Pause (Action a)
		{
			if (!actions.Contains (a))
				Debug.LogWarning (a + "dont exsits,please check!");
			if (a != null)
				a.Pause ();
		}


		public void Resume (Action a)
		{
			if (!actions.Contains (a))
				Debug.LogWarning (a + "dont exsits,please check!");
			if (a != null)
				a.Resume ();
		}
	}
}
