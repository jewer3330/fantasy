using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEditor;
using UnityEngine;

public enum AnimationEventFunc
{
    OnPlayEffect,
    OnPlaySound,
}
class PTEventConfigPopWindow : EditorWindow
{
    public static FrameEvent data;
    private AnimationEventFunc funcType = AnimationEventFunc.OnPlayEffect;
    public delegate void closeCallback(FrameEvent eventData);
    public closeCallback Callback;
    public static int skillIndex;

    public static PTEventConfigPopWindow PopUp(FrameEvent eventData, int skillIndex)
    {
        data = eventData;
        PTEventConfigPopWindow.skillIndex = skillIndex;
        return GetWindow<PTEventConfigPopWindow>(true);
    }

    void OnGUI()
    {
        EditorGUILayout.BeginVertical();
        
        EditorGUILayout.LabelField("functionName");
        funcType = (AnimationEventFunc)EditorGUILayout.EnumPopup(funcType);
        data.functionName = funcType.ToString();
        switch (funcType)
        {
            case AnimationEventFunc.OnPlayEffect:
                PlayEffectView();
                break;
            case AnimationEventFunc.OnPlaySound:
                PlaySoundView();
                break;
            default:
                break;
        }
        GUILayout.FlexibleSpace();

        if (GUILayout.Button("Confirm"))
        {
            if (Callback != null)
            {
                Callback(data);
                Callback = null;
            }
            Close();
        }

        EditorGUILayout.EndVertical();
    }

    private void PlayEffectView()
    {
        data.intParam = EditorGUILayout.IntField("EffectID", data.intParam);
        data.floatParam = EditorGUILayout.FloatField("Duration", data.floatParam);
        data.stringParam = EditorGUILayout.TextField("Slot", data.stringParam);
    }

    private void PlaySoundView()
    {
        data.stringParam = EditorGUILayout.TextField("SoundID", data.stringParam);
    }
}
