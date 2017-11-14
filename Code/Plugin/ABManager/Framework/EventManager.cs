using UnityEngine;
using System.Collections;
using System.Collections.Generic;

namespace SuperBoBo
{

	public class Event
	{
		public string type;
		public object[] args;

		public Event (string type, object[] args)
		{
			this.type = type;
			this.args = args;
		}
	}


	public interface EventHandle
	{
		void HandleEvent (Event e);
	}

	/// <summary>
/// 只是为了兼容原来的接口
/// </summary>
public delegate void EventHandleDelegate (string e, object[] args);

	/// <summary>
	/// 只是为了兼容原来的接口
	/// </summary>
	public class DefaultHandle : EventHandle
	{
		public EventHandleDelegate handle;
		public string type;

		public DefaultHandle (string type, EventHandleDelegate h)
		{
			this.type = type;
			handle = h;
		}

		public void HandleEvent (string e, object[] args)
		{
			if (handle != null) {
				handle (e, args);
			}
		}

		public void HandleEvent (Event e)
		{
			HandleEvent (e.type, e.args);
		}
	}

	public class EventManager : Singleton<EventManager>
	{
		private Dictionary<string, List<EventHandle>> event_dics = new Dictionary<string, List<EventHandle>> ();

		private Queue<Event> events = new Queue<Event> ();

		private List<DefaultHandle> defaults = new List<DefaultHandle> ();

		public void Reg (string e, EventHandle handle)
		{
			if (event_dics.ContainsKey (e)) {
				var list_events = event_dics [e];
				if (list_events.Contains (handle)) {
					Debug.LogWarning (string.Format ("already contains handle key {0},handle {1}", e.ToString (), handle));
				} else {
					list_events.Add (handle);
				}
			} else { 
				var list_events = new List<EventHandle> ();
				list_events.Add (handle);
				event_dics.Add (e, list_events);
			}
		}

		public void Reg (string e, EventHandleDelegate handle)
		{
			bool find = false;
			foreach (var k in defaults) {
				if (k.handle == handle && k.type == e) {
					find = true;
					break;
				}
			}

			if (!find) {
				DefaultHandle eh = new DefaultHandle (e, handle);
				defaults.Add (eh);
				Reg (e, eh);
			} else {
				Debug.LogWarning (string.Format ("already contains handle key {0},handle {1}", e.ToString (), handle));                
			}
		}

		public void OnDestroy ()
		{
			event_dics.Clear ();
			events.Clear ();
			defaults.Clear ();
		}

		public void UnReg (string e, EventHandleDelegate handle)
		{

			

			for (int i = 0; i < defaults.Count; i++) {
				if (defaults [i].handle == handle && defaults [i].type == e) {
					UnReg (e, defaults [i]);
					defaults.Remove (defaults [i]);
					break;       
				}
			}

		}

		public void UnReg (string e, EventHandle handle)
		{
			if (event_dics.ContainsKey (e)) {
				var list_events = event_dics [e];
				if (!list_events.Contains (handle)) {
					Debug.LogWarning (string.Format ("not contains handle key {0},handle {1}", e.ToString (), handle));
				} else {
					list_events.Remove (handle);
				}
			} else {
				Debug.LogWarning (string.Format ("not contains handle key {0},handle {1}", e.ToString (), handle));
			}
		}

		public void Update ()
		{
			PostEvent ();
		}

		void PostEvent ()
		{
			if (events.Count > 0) {
				Event et = events.Dequeue ();
				HandleEvent (et);
			}
		}

		/// <summary>
		/// 这个方法将会延迟执行，具体延迟的时间看队列中的个数,一帧执行一个事件
		/// </summary>
		/// <param name="e"></param>
		/// <param name="args"></param>
		public void PushEvent (string e, params object[]args)
		{
			Event et = new Event (e, args);
			events.Enqueue (et);
		}

		/// <summary>
		/// 这个方法将会延迟执行，具体延迟的时间看队列中的个数,一帧执行一个事件
		/// </summary>
		/// <param name="et"></param>
		public void PushEvent (Event et)
		{
			if (et != null)
				events.Enqueue (et);
		}

		/// <summary>
		/// 立即发送事件，立刻执行
		/// </summary>
		/// <param name="e"></param>
		/// <param name="args"></param>
		public void FireEvent (string e, params object[] args)
		{
			Event et = new Event (e, args);
			HandleEvent (et);
			// PushEvent(et);
		}

		public void FireEvent (Event et)
		{
			if (et != null)
				HandleEvent (et);
		}


		void HandleEvent (Event et)
		{
			if (et != null) {
				if (event_dics.ContainsKey (et.type)) {
					var el = event_dics [et.type];
					foreach (var k in el) {
						k.HandleEvent (et);
					}
				}
			}
		}



	}
}