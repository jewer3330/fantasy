using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System;

namespace SuperBoBo
{
	interface IHandle
	{
		void HandleEvent(string e, object args);
	}

	public class EventHandle<T> : IHandle
	{
		public System.Action<string,T> handle;
		public string type;

		protected EventHandle()
		{

        }

		public EventHandle(string type, System.Action<string,T> h)
		{
			this.type = type;
			this.handle = h;
		}

		public virtual void HandleEvent(string e, object args)
		{
			if (e == type && handle != null)
			{
				handle(e,(T)args);
			}
		}
		
	}


	public class EventManager : Singleton<EventManager>
	{
		//private Dictionary<string, System.Action<object>> event_dics = new Dictionary<string, System.Action<object>> ();
		private Dictionary<string, IHandle> event_dics = new Dictionary<string, IHandle> ();


        public void Reg(string e, System.Action<string, object> handle)
        {
            Reg<object>(e, handle);
        }

        public void Reg<T>(string e, Action<string,T> handle)
		{
			IHandle ih = null;
			if (event_dics.TryGetValue(e, out ih))
			{
				if (ih is EventHandle<T>)
				{
					EventHandle<T> i = ih as EventHandle<T>;
					i.handle += handle;
				}
				else
				{
					Debug.LogError("same event name registed but the callback is not same that will have problem ,try remove one");
					throw new System.Exception("same event name registed but the callback is not same that will have problem ,try remove one");
				}
			}
			else
			{
				event_dics.Add(e, new EventHandle<T>(e, handle));
			}
		}

        public void UnReg(string e, System.Action<string,object> handle)
        {
			UnReg<object>(e, handle);

        }

        public void UnReg<T>(string e, Action<string,T> handle)
		{
			IHandle ih = null;
			if (event_dics.TryGetValue(e, out ih))
			{
				if (ih is EventHandle<T>)
				{
					EventHandle<T> i = ih as EventHandle<T>;
					i.handle -= handle;
				}
			}
		}


		public void OnDestroy()
		{
			event_dics.Clear();
		}

		public void FireEvent (string e,object args = null)
		{
            HandleEvent(e,args);
		}

		public void FireEvent<T>(string e, T args)
		{
			HandleEvent(e, args);
		}

		void HandleEvent<T> (string e, T args)
		{
			if (e != null) {
				IHandle ih = null;
				if (event_dics.TryGetValue(e,out ih))
				{
					ih.HandleEvent(e,args);
				}
			}
		}

    }
}