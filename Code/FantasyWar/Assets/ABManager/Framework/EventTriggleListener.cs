using UnityEngine;
using System.Collections;
using UnityEngine.EventSystems;

public class EventTriggerListener : UnityEngine.EventSystems.EventTrigger
{
	public delegate void BaseDelegate (GameObject go, BaseEventData data);
	public delegate void PointerDelegate (GameObject go, PointerEventData data);

	public BaseDelegate onSelect;
	public BaseDelegate onUpdateSelect;

	public PointerDelegate onClick;
	public PointerDelegate onDown;
	public PointerDelegate onEnter;
	public PointerDelegate onExit;
	public PointerDelegate onUp;


	public PointerDelegate onDrag;
	public PointerDelegate onEndDrag;


	static public EventTriggerListener Get (GameObject go)
	{
		EventTriggerListener listener = go.GetComponent<EventTriggerListener> ();
		if (listener == null)
			listener = go.AddComponent<EventTriggerListener> ();
		return listener;
	}

	public override void OnPointerClick (PointerEventData eventData)
	{
		if (onClick != null)
			onClick (gameObject, eventData);
	}

	public override void OnPointerDown (PointerEventData eventData)
	{
		if (onDown != null)
			onDown (gameObject, eventData);
	}

	public override void OnPointerEnter (PointerEventData eventData)
	{
		if (onEnter != null)
			onEnter (gameObject, eventData);
	}

	public override void OnPointerExit (PointerEventData eventData)
	{
		if (onExit != null)
			onExit (gameObject, eventData);
	}

	public override void OnPointerUp (PointerEventData eventData)
	{
		if (onUp != null)
			onUp (gameObject, eventData);
	}

	public override void OnSelect (BaseEventData eventData)
	{
		if (onSelect != null)
			onSelect (gameObject, eventData);
	}

	public override void OnUpdateSelected (BaseEventData eventData)
	{
		if (onUpdateSelect != null)
			onUpdateSelect (gameObject, eventData);
	}

	public override void OnDrag (PointerEventData eventData)
	{
		if (onDrag != null)
			onDrag (gameObject, eventData);
	}

	public override void OnEndDrag (PointerEventData eventData)
	{
		if (onEndDrag != null) {
			onEndDrag (gameObject, eventData);
		}
	}
}