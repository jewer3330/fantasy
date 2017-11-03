using UnityEngine;
using UnityEditor;
using System.Collections;

class AnimationClipInfoProperties
{
	private SerializedProperty m_Property;

	private SerializedProperty Get(string property)
	{
		return m_Property.FindPropertyRelative(property);
	}

	public AnimationClipInfoProperties(SerializedProperty prop)
	{
		m_Property = prop;
	}

	public string name
	{
		get {
			return Get("name").stringValue;
		}

		set {
			Get("name").stringValue = value;
		}
	}

	public string takeName
	{
		get {
			return Get("takeName").stringValue;
		}

		set {
			Get("takeName").stringValue = value;
		}
	}

	public float firstFrame
	{
		get {
			return Get("firstFrame").floatValue;
		}

		set {
			Get("firstFrame").floatValue = value;
		}
	}

	public float lastFrame
	{
		get {
			return Get("lastFrame").floatValue;
		}

		set {
			Get("lastFrame").floatValue = value;
		}
	}

	public int wrapMode
	{
		get {
			return Get("wrapMode").intValue;
		}

		set {
			Get("wrapMode").intValue = value;
		}
	}

	public bool loop
	{
		get {
			return Get("loop").boolValue;
		}

		set {
			Get("loop").boolValue = value;
		}
	}

	// Mecanim animation properties
	public float orientationOffsetY
	{
		get {
			return Get("orientationOffsetY").floatValue;
		}

		set {
			Get("orientationOffsetY").floatValue = value;
		}
	}

	public float level
	{
		get {
			return Get("level").floatValue;
		}

		set {
			Get("level").floatValue = value;
		}
	}

	public float cycleOffset
	{
		get {
			return Get("cycleOffset").floatValue;
		}

		set {
			Get("cycleOffset").floatValue = value;
		}
	}

	public bool loopTime
	{
		get {
			return Get("loopTime").boolValue;
		}

		set {
			Get("loopTime").boolValue = value;
		}
	}

	public bool loopBlend
	{
		get {
			return Get("loopBlend").boolValue;
		}

		set {
			Get("loopBlend").boolValue = value;
		}
	}

	public bool loopBlendOrientation
	{
		get {
			return Get("loopBlendOrientation").boolValue;
		}

		set {
			Get("loopBlendOrientation").boolValue = value;
		}
	}

	public bool loopBlendPositionY
	{
		get {
			return Get("loopBlendPositionY").boolValue;
		}

		set {
			Get("loopBlendPositionY").boolValue = value;
		}
	}

	public bool loopBlendPositionXZ
	{
		get {
			return Get("loopBlendPositionXZ").boolValue;
		}

		set {
			Get("loopBlendPositionXZ").boolValue = value;
		}
	}

	public bool keepOriginalOrientation
	{
		get {
			return Get("keepOriginalOrientation").boolValue;
		}

		set {
			Get("keepOriginalOrientation").boolValue = value;
		}
	}

	public bool keepOriginalPositionY
	{
		get {
			return Get("keepOriginalPositionY").boolValue;
		}

		set {
			Get("keepOriginalPositionY").boolValue = value;
		}
	}

	public bool keepOriginalPositionXZ
	{
		get {
			return Get("keepOriginalPositionXZ").boolValue;
		}

		set {
			Get("keepOriginalPositionXZ").boolValue = value;
		}
	}

	public bool heightFromFeet
	{
		get {
			return Get("heightFromFeet").boolValue;
		}

		set {
			Get("heightFromFeet").boolValue = value;
		}
	}

	public bool mirror { get { return Get("mirror").boolValue; } set { Get("mirror").boolValue = value; } }

	public AnimationEvent GetEvent(int index)
	{
		AnimationEvent evt = new AnimationEvent();
		SerializedProperty events = Get("events");

		if (events != null && events.isArray) {
			if (index < events.arraySize) {
				evt.floatParameter = events.GetArrayElementAtIndex(index).FindPropertyRelative("floatParameter").floatValue;
				evt.functionName = events.GetArrayElementAtIndex(index).FindPropertyRelative("functionName").stringValue;
				evt.intParameter = events.GetArrayElementAtIndex(index).FindPropertyRelative("intParameter").intValue;
				evt.objectReferenceParameter = events.GetArrayElementAtIndex(index).FindPropertyRelative("objectReferenceParameter").objectReferenceValue;
				evt.stringParameter = events.GetArrayElementAtIndex(index).FindPropertyRelative("data").stringValue;
				evt.time = events.GetArrayElementAtIndex(index).FindPropertyRelative("time").floatValue;
			}
			else
				Debug.LogWarning("Invalid Event Index");
		}

		return evt;
	}

	public void SetEvent(int index, AnimationEvent animationEvent)
	{
		SerializedProperty events = Get("events");

		if (events != null && events.isArray) {
			if (index < events.arraySize) {
				events.GetArrayElementAtIndex(index).FindPropertyRelative("floatParameter").floatValue = animationEvent.floatParameter;
				events.GetArrayElementAtIndex(index).FindPropertyRelative("functionName").stringValue = animationEvent.functionName;
				events.GetArrayElementAtIndex(index).FindPropertyRelative("intParameter").intValue = animationEvent.intParameter;
				events.GetArrayElementAtIndex(index).FindPropertyRelative("objectReferenceParameter").objectReferenceValue = animationEvent.objectReferenceParameter;
				events.GetArrayElementAtIndex(index).FindPropertyRelative("data").stringValue = animationEvent.stringParameter;
				events.GetArrayElementAtIndex(index).FindPropertyRelative("time").floatValue = animationEvent.time;
			}
			else
				Debug.LogWarning("Invalid Event Index");
		}

		return;
	}

	public void ClearEvents()
	{
		SerializedProperty events = Get("events");

		if (events != null && events.isArray)
			events.ClearArray();

		return;
	}

	public int GetEventCount()
	{
		int ret = 0;

		SerializedProperty curves = Get("events");

		if (curves != null && curves.isArray)
			ret = curves.arraySize;

		return ret;
	}

	public void SetEvents(AnimationEvent[] newEvents)
	{
		SerializedProperty events = Get("events");

		if (events != null && events.isArray) {
			events.ClearArray();

			foreach (AnimationEvent evt in newEvents) {
				events.InsertArrayElementAtIndex(events.arraySize);
				SetEvent(events.arraySize - 1, evt);
			}
		}

		return;
	}

	public void AddEvent(AnimationEvent newEvent)
	{
		SerializedProperty e = Get("events");

		if (e != null && e.isArray) {
			e.InsertArrayElementAtIndex(e.arraySize);
			e.GetArrayElementAtIndex(e.arraySize - 1).FindPropertyRelative("floatParameter").floatValue = newEvent.floatParameter;
			e.GetArrayElementAtIndex(e.arraySize - 1).FindPropertyRelative("functionName").stringValue = newEvent.functionName;
			e.GetArrayElementAtIndex(e.arraySize - 1).FindPropertyRelative("intParameter").intValue = newEvent.intParameter;
			e.GetArrayElementAtIndex(e.arraySize - 1).FindPropertyRelative("objectReferenceParameter").objectReferenceValue = newEvent.objectReferenceParameter;
			e.GetArrayElementAtIndex(e.arraySize - 1).FindPropertyRelative("data").stringValue = newEvent.stringParameter;
			e.GetArrayElementAtIndex(e.arraySize - 1).FindPropertyRelative("time").floatValue = newEvent.time;
		}

		return;
	}

	public AnimationEvent[] GetEvents()
	{
		AnimationEvent[] ret = new AnimationEvent[GetEventCount()];
		SerializedProperty events = Get("events");

		if (events != null && events.isArray) {
			for (int i = 0; i < GetEventCount(); ++i)
				ret[i] = GetEvent(i);
		}

		return ret;
    }
    public void MaskFromClip(UnityEngine.AvatarMask mask)
    {
        SerializedProperty serializedProperty2 = this.Get("transformMask");
        if (serializedProperty2 != null && serializedProperty2.isArray)
        {
            if (serializedProperty2.arraySize > 0 && mask.transformCount != serializedProperty2.arraySize)
            {
                mask.transformCount = serializedProperty2.arraySize;
            }
            int arraySize = serializedProperty2.arraySize;
            if (arraySize != 0)
            {
                SerializedProperty arrayElementAtIndex = serializedProperty2.GetArrayElementAtIndex(0);
                for (int i = 0; i < arraySize; i++)
                {
                    SerializedProperty serializedProperty3 = arrayElementAtIndex.FindPropertyRelative("m_Path");
                    SerializedProperty serializedProperty4 = arrayElementAtIndex.FindPropertyRelative("m_Weight");
                    mask.SetTransformPath(i, serializedProperty3.stringValue);
                    mask.SetTransformActive(i, (double)serializedProperty4.floatValue > 0.5);
                    arrayElementAtIndex.Next(false);
                }
            }
        }
    }
}
