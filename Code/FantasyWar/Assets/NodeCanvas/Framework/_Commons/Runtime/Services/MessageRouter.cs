using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using System;
using System.Reflection;

namespace ParadoxNotion.Services{

	///Automaticaly added to a gameobject when needed.
	///Handles forwarding Unity event messages to listeners that need them as well as Custom event forwarding.
	///Notice: this is a partial class! Add your own methods to forward events as you please.
	public partial class MessageRouter : MonoBehaviour
			, IPointerEnterHandler, IPointerExitHandler, IPointerDownHandler, IPointerUpHandler, IPointerClickHandler,
			IDragHandler, IScrollHandler, IUpdateSelectedHandler, ISelectHandler, IDeselectHandler, IMoveHandler, ISubmitHandler
	{


		//The event names and the objects subscribed to them
		private Dictionary<string, List<object>> listeners = new Dictionary<string, List<object>>(System.StringComparer.OrdinalIgnoreCase);


		public void OnPointerEnter(PointerEventData eventData){
			Dispatch("OnPointerEnter", eventData);
		}

		public void OnPointerExit(PointerEventData eventData){
			Dispatch("OnPointerExit", eventData);
		}

		public void OnPointerDown(PointerEventData eventData){
			Dispatch("OnPointerDown", eventData);
		}

		public void OnPointerUp(PointerEventData eventData){
			Dispatch("OnPointerUp", eventData);
		}

		public void OnPointerClick(PointerEventData eventData){
			Dispatch("OnPointerClick", eventData);
		}

		public void OnDrag(PointerEventData eventData){
			Dispatch("OnDrag", eventData);
		}

		public void OnDrop(BaseEventData eventData){
			Dispatch("OnDrop", eventData);
		}

		public void OnScroll(PointerEventData eventData){
			Dispatch("OnScroll", eventData);
		}

		public void OnUpdateSelected(BaseEventData eventData){
			Dispatch("OnUpdateSelected", eventData);
		}

		public void OnSelect(BaseEventData eventData){
			Dispatch("OnSelect", eventData);
		}

		public void OnDeselect(BaseEventData eventData){
			Dispatch("OnDeselect", eventData);
		}

		public void OnMove(AxisEventData eventData){
			Dispatch("OnMove", eventData);
		}

		public void OnSubmit(BaseEventData eventData){
			Dispatch("OnSubmit", eventData);
		}



		void OnAnimatorIK(int layerIndex){
			Dispatch("OnAnimatorIK", layerIndex);
		}

		void OnBecameInvisible(){
			Dispatch("OnBecameInvisible", null);
		}

		void OnBecameVisible(){
			Dispatch("OnBecameVisible", null);
		}

		void OnCollisionEnter(Collision collisionInfo){
			Dispatch("OnCollisionEnter", collisionInfo);
		}

		void OnCollisionExit(Collision collisionInfo){
			Dispatch("OnCollisionExit", collisionInfo);
		}

		void OnCollisionStay(Collision collisionInfo){
			Dispatch("OnCollisionStay", collisionInfo);
		}

		void OnCollisionEnter2D(Collision2D collisionInfo){
			Dispatch("OnCollisionEnter2D", collisionInfo);
		}

		void OnCollisionExit2D(Collision2D collisionInfo){
			Dispatch("OnCollisionExit2D", collisionInfo);
		}

		void OnCollisionStay2D(Collision2D collisionInfo){
			Dispatch("OnCollisionStay2D", collisionInfo);
		}

		void OnTriggerEnter(Collider other){
			Dispatch("OnTriggerEnter", other);
		}

		void OnTriggerExit(Collider other){
			Dispatch("OnTriggerExit", other);
		}

		void OnTriggerStay(Collider other){
			Dispatch("OnTriggerStay", other);
		}

		void OnTriggerEnter2D(Collider2D other){
			Dispatch("OnTriggerEnter2D", other);
		}

		void OnTriggerExit2D(Collider2D other){
			Dispatch("OnTriggerExit2D", other);
		}

		void OnTriggerStay2D(Collider2D other){
			Dispatch("OnTriggerStay2D", other);
		}

		void OnMouseDown(){
			Dispatch("OnMouseDown", null);
		}

		void OnMouseDrag(){
			Dispatch("OnMouseDrag", null);
		}

		void OnMouseEnter(){
			Dispatch("OnMouseEnter", null);
		}

		void OnMouseExit(){
			Dispatch("OnMouseExit", null);
		}

		void OnMouseOver(){
			Dispatch("OnMouseOver", null);
		}

		void OnMouseUp(){
			Dispatch("OnMouseUp", null);
		}

		void OnControllerColliderHit(ControllerColliderHit hit){
			Dispatch("OnControllerColliderHit", hit);
		}

		//This is used for custom events other than the above
		public void OnCustomEvent(EventData eventData){
			Dispatch("OnCustomEvent", eventData);
		}




		///Add a listener to several messages
		public void Register(object target, params string[] messages){

			if (target == null){
				return;
			}

			for (var i = 0; i < messages.Length; i++){
				
				if (target.GetType().RTGetMethod(messages[i]) == null){
					Debug.LogError(string.Format("Type '{0}' does not implement a method named '{1}', for the registered event to use.", target.GetType().FriendlyName(), messages[i]));
					continue;
				}

				List<object> targetObjects = null;
				if (!listeners.TryGetValue(messages[i], out targetObjects)){
					targetObjects = new List<object>();
					listeners[messages[i]] = targetObjects;
				}

				if (!targetObjects.Contains(target)){
					targetObjects.Add(target);
				}
			}
		}


		///...
		public void RegisterCallback(string message, Action callback){ Internal_RegisterCallback(message, callback); }
		public void RegisterCallback<T>(string message, Action<T> callback){ Internal_RegisterCallback(message, callback); }
		void Internal_RegisterCallback(string message, Delegate callback){
			List<object> targetObjects = null;
			if (!listeners.TryGetValue(message, out targetObjects)){
				targetObjects = new List<object>();
				listeners[message] = targetObjects;
			}
			if (!targetObjects.Contains(callback)){
				targetObjects.Add(callback);
			}			
		}


		///Remove a listener completely
		public void UnRegister(object target){

			if (target == null){
				return;
			}

			foreach (var message in listeners.Keys){
				foreach (var o in listeners[message].ToArray()){

					if (o == target){
						listeners[message].Remove(target);
						continue;
					}

					if (o is Delegate){
						var delTarget = (o as Delegate).Target;
						if (delTarget == target){
							listeners[message].Remove(o);
						}
					}
				}
			}
		}

		///Remove a listener from the specified messages
		public void UnRegister(object target, params string[] messages){

			if (target == null){
				return;
			}

			for (var i = 0; i < messages.Length; i++){

				var message = messages[i];
				if (!listeners.ContainsKey(message)){
					continue;
				}

				foreach (var o in listeners[message].ToArray()){
	
					if (o == target){
						listeners[message].Remove(target);
						continue;
					}

					if (o is Delegate){
						var delTarget = (o as Delegate).Target;
						if (delTarget == target){
							listeners[message].Remove(o);
						}
					}
				}
			}
		}



		///Call the functions assigned to the event
		public void Dispatch(string message, object arg){

			List<object> targets;
			if (!listeners.TryGetValue(message, out targets)){
				return;
			}

			for (var i = 0; i < targets.Count; i++){
				var target = targets[i];
				if (target == null){
					continue;
				}

				MethodInfo method = null;

				if (target is Delegate){
					method = (target as Delegate).RTGetDelegateMethodInfo();
				} else {
					method = target.GetType().RTGetMethod(message);
				}

				if (method == null){
					continue;
				}

				var args = method.GetParameters().Length == 1? new object[]{arg} : null;
				if (target is Delegate){
				
					(target as Delegate).DynamicInvoke(args);
				
				} else {

					if (method.ReturnType == typeof(IEnumerator)){
						MonoManager.current.StartCoroutine( (IEnumerator)method.Invoke(target, args) );
					} else {
						method.Invoke(target, args);
					}		
				}		
			}
		}
	}
}