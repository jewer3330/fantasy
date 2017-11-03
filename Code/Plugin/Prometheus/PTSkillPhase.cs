using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using System;
using System.IO;

[Serializable]
public class AnimationEventData
{
    public float time;
    public string stringParam;
    public string functionName;
}
//one animation
[Serializable]
public class SkillOneAnimationState
{
	#region public member
	private static readonly int width = 500;
	private static readonly int height = 300;
	public AnimationState state;
    public string animationName = "";
	public List<SkillPhaseItem> itemList = new List<SkillPhaseItem>();
	public List<AnimationEventData> eventDataList = new List<AnimationEventData>();
    public int skillIndex;
    public bool fullBody = false;
    #endregion public member

    #region private member
    [SerializeField]
    private List<float> sampleArray = new List<float>();
	private int toRmEventIndex = 0;
	private float sampleTime = 0f;
    private AnimationClip clip = null;
	private Dictionary<Transform, float> FX = new Dictionary<Transform, float>();
    [SerializeField]
    private List<string> fDirs = new List<string>();
    [SerializeField]
    private int  animIdx = 0;
    [SerializeField]

    private float _overrideTransTime = -1f;
    public float overrideTransTime
    {
        get
        {
            return _overrideTransTime;
        }
        private set
        {
            _overrideTransTime = value;
        }
    }
    private string baseHeroModelPath = "Assets/Content/Character/Hero/";
    private string baseNpcModelPath = "Assets/Content/Character/Npc/";
    [SerializeField]
    private List<string> animationFiles = new List<string>();
	private bool playFlag = false;
	private float lastUpdateTime = 0f;
	// private List<bool> buttonPressed = new List<bool>();
	[NonSerializedAttribute]
	private List<bool> buttonPressed = new List<bool>(10);
    // private Dictionary<int, Rect> rects = new Dictionary<int, Rect>();
    [SerializeField]
    private List<int> idxs = new List<int>();
    [SerializeField]
    private List<Rect> rects = new List<Rect>();
    protected Rect posRect;
    [SerializeField]
    protected int skillStateIndex = 0;
    private Rect eventRect = new Rect();
	private bool animateToggle;
	private bool dragging = false;
	private List<AnimationEvent> eventList = new List<AnimationEvent>();
	#endregion private member

	public int SkillStateIndex
	{
		get { return skillStateIndex; }
		set { skillStateIndex = value; posRect = new Rect((width + 10) * skillStateIndex, 0, width, height); }
	}
    

	public SkillOneAnimationState()
	{
		itemList.Add(new SkillPhaseItem());
	}

    public void Init()
    {
        // remove old phases
        sampleArray.Clear();
        itemList.Clear();

        if (animIdx >= animationFiles.Count)
            animIdx = 0;

        if (PrometheusUtil.curCharacterType == PTCharacterType.Hero)
            clip = AssetDatabase.LoadAssetAtPath(baseHeroModelPath + PrometheusUtil.modelName + "/" + animationFiles[animIdx], typeof(AnimationClip)) as AnimationClip;
        else if (PrometheusUtil.curCharacterType == PTCharacterType.Npc)
            clip = AssetDatabase.LoadAssetAtPath(baseNpcModelPath + PrometheusUtil.modelName + "/" + animationFiles[animIdx], typeof(AnimationClip)) as AnimationClip;

        fullBody = IsClipFullBody(clip);

        List<AnimationEventData> removes = new List<AnimationEventData>();
        foreach (var ev in eventDataList)
        {
            if (ev.functionName == "OnSkillAnimNextPhase")
                removes.Add(ev);
        }
        if (removes.Count > 0)
        {
            foreach (var ev in removes)
            {
                eventDataList.Remove(ev);
            }
            UpdateAniEvents();
        }

        loadedAnimationName = animationName;
    }

	public void RemovePhaseItem(int index)
	{
		if(index < sampleArray.Count)
		{
			sampleArray.RemoveAt(index);
			itemList.RemoveAt(index+1);
		}
	}

	public void RemoveEventItem(int index)
	{
		if(index < eventDataList.Count)
		{
            eventDataList.RemoveAt(index);
            rects.RemoveAt(index);
			UpdateAniEvents();
		}
	}

    public void UnloadFX()
    {
        animateToggle = false;
        foreach (Transform sfx in FX.Keys)
        {
            GameObject.DestroyImmediate(sfx.gameObject);
        }
        FX.Clear();
    }

	public void UpdateAniEvents()
	{
		ModelImporter modelImporter =
			AssetImporter.GetAtPath(AssetDatabase.GetAssetPath(clip)) as ModelImporter;
		if (modelImporter == null)
			return;

		// get serialized clip array
		SerializedObject serializedObject = new SerializedObject(modelImporter);
		SerializedProperty clipAnimations = serializedObject.FindProperty("m_ClipAnimations");

		if (!clipAnimations.isArray)
			return;
		// get clip info
		// since we only have 1 clip in each animation so we only
		// need to get element at index 0
		AnimationClipInfoProperties clipInfoProperties =
			new AnimationClipInfoProperties(clipAnimations.GetArrayElementAtIndex(0));

        // set events
        eventList.Clear();
        foreach(var item in eventDataList)
        {
            AnimationEvent eventTemp = new AnimationEvent();
            eventTemp.time = item.time / clip.length;
            eventTemp.functionName = item.functionName;
            eventTemp.stringParameter = item.stringParam;
            eventTemp.messageOptions = SendMessageOptions.DontRequireReceiver;
            eventList.Add(eventTemp);
        }
		clipInfoProperties.SetEvents(eventList.ToArray());
		// serialize data
		serializedObject.ApplyModifiedProperties();
		AssetDatabase.ImportAsset(AssetDatabase.GetAssetPath(clip));

		return;
	}

	public void UpdateGUI()
	{
        GUI.Box(posRect, "");
        GUILayout.BeginArea(posRect);
        GUILayout.BeginVertical();
        SelectAnimation();
        if (clip != null)
            SampleAnimation();
        DrawEditPart();
        GUILayout.FlexibleSpace();
        GUILayout.EndVertical();
        GUILayout.EndArea();

        Update();
	}

	public void HandleEvent(Event e)
	{
	}

	protected void DrawEditPart()
	{
		if (clip == null || loadedAnimationName != animationName)
			return;

		GUILayout.BeginHorizontal();
		toRmEventIndex = EditorGUILayout.IntField(toRmEventIndex, GUILayout.MaxWidth(100));
		if (GUILayout.Button("RemoveEventItem", GUILayout.MaxWidth(160)))
		{
			//var control = GUI.GetNameOfFocusedControl();
			RemoveEventItem(toRmEventIndex);
		}
		GUILayout.EndHorizontal();

		// foreach (var item in eventList)
		for (int i = 0; i < eventDataList.Count; ++i) {
            //EditorGUI.BeginChangeCheck();
			eventDataList[i].time = EditorGUILayout.FloatField(eventDataList[i].time);
            //if (EditorGUI.EndChangeCheck())
            //    UpdateAniEvents();
			UpdateEventMarker(i, eventDataList[i].time);
		}
        if(GUILayout.Button("ApplyEventTimeModify"))
        {
            UpdateAniEvents();
        }
	}

	protected void UpdateSubPhases()
	{
        //if (itemList.Count > 1)
        //{
        //    if (sampleArray.Count == itemList.Count - 1)
        //    {
        //        float pre = 0;
        //        for (int i = 0; i < sampleArray.Count; i++)
        //        {
        //            pre += sampleArray[i];
        //            itemList[i+1].beginPercent = pre;
        //        }
        //    }
        //}
	}

	private void UpdateEventMarker(int idx, float time)
	{
		if (dragging)
			return;
		// rects[idx].Set((time / clip.length) * eventRect.width + 5f, eventRect.y + 2,
		// 			   rects[idx].width, rects[idx].height);
		rects[idx] = new Rect((time / clip.length) * eventRect.width, eventRect.y + 2,
							  rects[idx].width, rects[idx].height);

		return;
	}

	private void Update()
	{
		// sample animation clip & FX via slider value
		if (PrometheusUtil.curCharacter == null || clip == null)
			return;

		if (!EditorApplication.isPlaying && AnimationMode.InAnimationMode() && animateToggle) {
			AnimationMode.SampleAnimationClip(PrometheusUtil.curCharacter, clip, sampleTime * clip.length);
			foreach (KeyValuePair<Transform, float> item in FX)
				if (sampleTime >= item.Value)
					item.Key.GetComponent<SFXController>().Simulate(sampleTime - item.Value);

			 float curTime = Time.realtimeSinceStartup;
			 float dt = curTime - lastUpdateTime;
			 lastUpdateTime = curTime;

			if (playFlag)
			{
				sampleTime += (dt / clip.length);
			 	if (sampleTime > 1.0f)
			 		sampleTime = 0f;
			 }

			SceneView.RepaintAll();
		}

		return;
	}

	private string loadedAnimationName;

	private void SelectAnimation()
	{
		GUILayout.Label("Animation");
		GUILayout.BeginHorizontal();
        //如果保存name 和 当前通过序列得到的name不一致！ 则通过遍历找到更新后的序列 animIdx
        //暂不支持 Index 和 Name 同时改的情况
        if (animationFiles[animIdx] != animationName) {
            bool temp = true;
            for(int i = 0;i < animationFiles.Count; i++){
                if (animationFiles[i] == animationName) {
                    animIdx = i;
                    temp = false;
                }
            }
            if (temp && animationName != "")
                Debug.LogError("美术更新了动画的名字或顺序 策划同学注意啦 ！！！");
        }

		animIdx = EditorGUILayout.Popup(animIdx, animationFiles.ToArray());

		if (animIdx >= animationFiles.Count)
			animIdx = 0;

		animationName = animationFiles[animIdx];
		if (GUILayout.Button("Load Animation")) {
			Animator temp = PrometheusUtil.curCharacter.GetComponent<Animator>();
            AnimationClip TempClip = null;
            if (PrometheusUtil.curCharacterType == 0)
			    TempClip = AssetDatabase.LoadAssetAtPath(baseHeroModelPath + PrometheusUtil.modelName + "/" + animationFiles[animIdx], typeof(AnimationClip)) as AnimationClip;
            else
                TempClip = AssetDatabase.LoadAssetAtPath(baseNpcModelPath + PrometheusUtil.modelName + "/" + animationFiles[animIdx], typeof(AnimationClip)) as AnimationClip;

			if (TempClip == null)
				Debug.Log("Animation load failed");

			if (loadedAnimationName != animationName) {
				eventList.Clear();
				UpdateAniEvents();
				itemList.Clear();
				itemList.Add(new SkillPhaseItem());
			}

			clip = TempClip;
			UnityEditor.Animations.AnimatorController ac = UnityEditor.Animations.AnimatorController.CreateAnimatorControllerAtPath("Assets/AnimatorTest/act.controller");
			temp.runtimeAnimatorController = ac as RuntimeAnimatorController; ;
			AnimationMode.StopAnimationMode();
			loadedAnimationName = animationFiles[animIdx];

			ModelImporter modelImporter =
				AssetImporter.GetAtPath(AssetDatabase.GetAssetPath(clip)) as ModelImporter;
			if (modelImporter == null)
				return;

			// get serialized clip array
			SerializedObject serializedObject = new SerializedObject(modelImporter);
			SerializedProperty clipAnimations = serializedObject.FindProperty("m_ClipAnimations");

			if (!clipAnimations.isArray)
				return;

			// get clip info
			// since we only have 1 clip in each animation so we only
			// need to get element at index 0
			var anim = clipAnimations.GetArrayElementAtIndex(0);
			AnimationClipInfoProperties clipInfoProperties =
				new AnimationClipInfoProperties(anim);

            UnityEngine.AvatarMask mask = new UnityEngine.AvatarMask();
            clipInfoProperties.MaskFromClip(mask);
            for (int i = 0; i < mask.transformCount; i++)
            {
                if (mask.GetTransformActive(i) && mask.GetTransformPath(i) == "Bip001")
                {
                    fullBody = true;
                }
            }
            // get all events
            Texture eventImg = EditorGUIUtility.IconContent("Animation.EventMarker").image;
			AnimationEvent[] events = clipInfoProperties.GetEvents();
			for (int i = 0; i < events.Length; ++i) {
				AnimationEvent evt = events[i];
				Rect newRect = new Rect((evt.time / clip.length) * eventRect.width, eventRect.y + 2, eventImg.width, eventImg.height);
			}
		}
		GUILayout.EndHorizontal();
        overrideTransTime = EditorGUILayout.FloatField("Override Transition: ", overrideTransTime);
        // display wrap type -- once, loop & etc
        if (null != clip) {
			if (clip.isLooping)
				GUILayout.Label("Loop");
			else
				GUILayout.Label("Once");
        }
        if(fullBody)
        {
            GUILayout.Label("Full body");
        }
        else
        {
            GUILayout.Label("Upper body");
        }
        //GUILayout.EndVertical();
    }

    public static bool IsClipFullBody(AnimationClip clip)
    {
        ModelImporter modelImporter =
            AssetImporter.GetAtPath(AssetDatabase.GetAssetPath(clip)) as ModelImporter;
        if (modelImporter == null)
            return false;

        // get serialized clip array
        SerializedObject serializedObject = new SerializedObject(modelImporter);
        SerializedProperty clipAnimations = serializedObject.FindProperty("m_ClipAnimations");

        if (!clipAnimations.isArray)
            return false;

        // get clip info
        // since we only have 1 clip in each animation so we only
        // need to get element at index 0
        if(clipAnimations.arraySize > 0)
        {
            var anim = clipAnimations.GetArrayElementAtIndex(0);
            AnimationClipInfoProperties clipInfoProperties =
                new AnimationClipInfoProperties(anim);

            UnityEngine.AvatarMask mask = new UnityEngine.AvatarMask();
            clipInfoProperties.MaskFromClip(mask);
            for (int i = 0; i < mask.transformCount; i++)
            {
                if (mask.GetTransformActive(i) && mask.GetTransformPath(i) == "Bip001")
                {
                    return true;
                }
            }
        }
        return false;
    }

	/// <summary>
	///   Draw cascade slider.
	/// </summary>
	private void SampleAnimation()
	{
		GUILayout.Space(5f);
		GUILayout.Label("Sample Animation");
		float[] array = sampleArray.ToArray(); // stores normalized cascade partitions
        GUILayout.BeginHorizontal();
		ShadowCascadeSplitGUI.HandleCascadeSliderGUI(ref array);

		// get cascade rect
		if (Event.current.type == EventType.Repaint)
			eventRect = GUILayoutUtility.GetLastRect();

		// get event marker image
		Texture eventImg = EditorGUIUtility.IconContent("Animation.EventMarker").image;

		// initialize press flag for each event marker
		while (buttonPressed.Count < rects.Count)
			buttonPressed.Add(false);

		for (int i = 0; i < rects.Count; ++i) {
			if (rects[i].Contains(Event.current.mousePosition) && Event.current.type == EventType.MouseDown) {
				buttonPressed[i] = true;
				dragging = true;
			}

			if (Event.current.type == EventType.MouseUp) {
				UpdateAniEvents();
				buttonPressed[i] = false;
				dragging = false;
			}

			if (buttonPressed[i] && Event.current.type == EventType.MouseDrag) {
				Rect temp = new Rect(Mathf.Clamp(rects[i].x + Event.current.delta.x, 0.0f, eventRect.width), rects[i].y, rects[i].width, rects[i].height);
				rects[i] = temp;
				eventDataList[i].time = (temp.x / eventRect.width) * clip.length;
			}

			EditorWindow.focusedWindow.Repaint();
			// draw event image
			if (Event.current.type == EventType.Repaint)
				GUIStyle.none.Draw(rects[i], new GUIContent(eventImg), false,false,false,false);
		}

        GUILayout.Label(string.Format("Time: {0}", sampleTime * clip.length));
        GUILayout.EndHorizontal();

		EditorGUILayout.Space();
		GUILayout.BeginHorizontal();

		EditorGUI.BeginChangeCheck();
		animateToggle = GUILayout.Toggle(animateToggle, "Animate", EditorStyles.toolbarButton);
        if (EditorGUI.EndChangeCheck())
        {
            ToggleAnimationMode();

            if (animateToggle)
            {
                foreach (var item in eventDataList)
                {
                    if (item.functionName == "OnPlayEffect")
                    {
                        string[] splists = item.stringParam.Split(';');
                        if (splists.Length == 3)
                        {
                            string path = PrometheusUtil.GetEffect(Int32.Parse(splists[0]));
                            if (!string.IsNullOrEmpty(path))
                            {
                                GameObject go = GameObject.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Resources/Prefabs/SFX/" + path + ".prefab"));
                                if (!string.IsNullOrEmpty(splists[2]))
                                {
                                    Transform slot = null;
                                    Transform[] ts = PrometheusUtil.curCharacter.GetComponentsInChildren<Transform>(true);
                                    foreach (Transform t in ts) if (t.gameObject.name == splists[2]) slot = t;

                                    if (slot != null)
                                        go.transform.SetParent(slot, false);
                                }
                                else
                                {
                                    go.transform.SetParent(PrometheusUtil.curCharacter.transform, false);
                                }
                                go.GetComponent<SFXController>().Init();
                                FX.Add(go.transform, item.time / clip.length);
                            }
                        }
                    }
                }
            }
            else
            {
                UnloadFX();
            }
        }

		sampleTime = EditorGUILayout.Slider(sampleTime, 0f, 1f, GUILayout.MaxWidth(200));
        Handles.BeginGUI();
        Handles.color = Color.red;
        Handles.DrawLine(new Vector3(eventRect.xMin + sampleTime * eventRect.width, eventRect.yMin, 0), new Vector3(eventRect.xMin + sampleTime * eventRect.width, eventRect.yMax, 0));
        Handles.EndGUI();

		sampleArray = array.ToList<float>();

		if (!playFlag) {
			if (GUILayout.Button("Play"))
				playFlag = true;
		}
		else if (GUILayout.Button("Stop"))
			playFlag = false;

		GUILayout.EndHorizontal();
		GUILayout.Space(15f);

		GUILayout.BeginHorizontal();
		if (GUILayout.Button("Add Event")) {
			FrameEvent data = new FrameEvent { percent = sampleTime };
			var window = PTEventConfigPopWindow.PopUp(data, skillIndex);
			window.ShowPopup();
			window.Callback = AddEventMenuCallback;
		}

		if (GUILayout.Button("RemoveAllEvents")) {
            eventDataList.Clear();
            rects.Clear();
			UpdateAniEvents();
		}

		GUILayout.EndHorizontal();

		return;
	}

	private void AddEventMenuCallback(FrameEvent data)
	{
		ModelImporter modelImporter =
			AssetImporter.GetAtPath(AssetDatabase.GetAssetPath(clip)) as ModelImporter;
		if (modelImporter == null)
			return;

		// get serialized clip array
		SerializedObject serializedObject = new SerializedObject(modelImporter);
		SerializedProperty clipAnimations = serializedObject.FindProperty("m_ClipAnimations");

		if (!clipAnimations.isArray)
			return;

		// get clip info
		// since we only have 1 clip in each animation so we only
		// need to get element at index 0
		var anim = clipAnimations.GetArrayElementAtIndex(0);
		AnimationClipInfoProperties clipInfoProperties =
			new AnimationClipInfoProperties(anim);

		AnimationEvent evt = new AnimationEvent();
		evt.time = data.percent;
		evt.functionName = string.IsNullOrEmpty(data.functionName) ? "TakeEffect" : data.functionName;
        if (evt.functionName == "OnPlaySound")
            evt.stringParameter = data.stringParam;
        else
            evt.stringParameter = string.Format("{0};{1};{2}", data.intParam, data.floatParam, data.stringParam);
        eventDataList.Add(new AnimationEventData { time = data.percent * clip.length, stringParam = evt.stringParameter, functionName = evt.functionName});
		eventList.Add(evt);
		Texture eventImg = EditorGUIUtility.IconContent("Animation.EventMarker").image;
		Rect newRect = new Rect(evt.time * eventRect.width, eventRect.y + 2, eventImg.width, eventImg.height);
		idxs.Add(eventList.Count() - 1);
		rects.Add(newRect);

		//// get all events
		// AnimationEvent[] events = clipInfoProperties.GetEvents();

		// serializedObject.ApplyModifiedProperties();
		// AssetDatabase.ImportAsset(AssetDatabase.GetAssetPath(clip));
		// Debug.Log(clip.length);

		// set events
		// clipInfoProperties.ClearEvents();
		// clipInfoProperties.SetEvents(eventList.ToArray());

		clipInfoProperties.AddEvent(evt);

		// serialize data
		serializedObject.ApplyModifiedPropertiesWithoutUndo();
		try {
			AssetDatabase.StartAssetEditing();
			string path = AssetDatabase.GetAssetPath(clip);
			AssetDatabase.ImportAsset(path);
			serializedObject.SetIsDifferentCacheDirty();
			serializedObject.Update();
		}
		finally {
			AssetDatabase.StopAssetEditing();
		}

		return;
	}

	private void ToggleAnimationMode()
	{
		if (AnimationMode.InAnimationMode())
			AnimationMode.StopAnimationMode();
		else
			AnimationMode.StartAnimationMode();

		return;
	}


	public void UpdateAnimationList(string modelPath)
	{
		// find all animation files
		string[] aFiles = Directory.GetFiles(modelPath, "*@*");

		animationFiles.Clear();
		for (int i = 0; i < aFiles.Length; ++i) {
			if (aFiles[i].Contains("meta"))
				continue;
			int lastIdx = aFiles[i].LastIndexOf("\\");
			animationFiles.Add(aFiles[i].Substring(lastIdx + 1, aFiles[i].Length - lastIdx - 1));
		}

		return;
	}

	private void UpdateModelDirectory()
	{
		// get hero directory list
		string[] dirs = Directory.GetDirectories("Assets/Content/Character/Hero");

		// filter with directories' names
		System.Text.RegularExpressions.Regex searchTerm =
			new System.Text.RegularExpressions.Regex(@"\d{3}$");

		var filterdDirs = from dir in dirs
						  where (searchTerm.IsMatch(dir))
						  select dir;

		fDirs.Clear();
		fDirs = filterdDirs.ToList();

		return;
	}
}

//one skill
[Serializable]
public class PTOneSkill
{
	public List<SkillOneAnimationState> stateList = new List<SkillOneAnimationState>();
    public SkillPhaseItem PhaseItem = new SkillPhaseItem();
	public SkilldataSetting DataSetting;

    //skillName and skillID inside of DataSetting
	//public string skillName;
	//public int skillID;

	public string modelPath;
    public bool isEditing;

    [SerializeField]
    private int skillIndex = 0;
	private int toRemovePhaseIndex = 0;
    private Vector2 scrollPos;

	public int SkillIndex
	{
		get {
			return skillIndex;
		}

		set {
			skillIndex = value;
		}
	}

    public void Load()
    {
        foreach (var item in stateList) {
            item.Init();
            item.UpdateAnimationList(modelPath);
        }
        PhaseItem.Load(DataSetting.skillID);
        UpdateStateListItemIndex();
    }

    public void Save()
    {
        PhaseItem.Save(DataSetting.skillID);
    }
    
    public void Comment()
    {
        PhaseItem.Comment();
    }

    public void UnloadFX()
    {
        foreach (var state in stateList)
        {
            state.UnloadFX();
        }
    }

	public void UpdateGUI(EditorWindow wnd)
	{
		DrawSkillPhase();

        scrollPos = GUI.BeginScrollView(new Rect() { y = 100, width = wnd.position.width, height = 320 }, scrollPos, new Rect(0, 0, 4000, 400), true, false);
		for (int i = 0;i<stateList.Count;i++) {
			stateList[i].UpdateGUI();
		}
        GUI.EndScrollView();
	}

	private void DrawSkillPhase()
	{
		EditorGUILayout.BeginHorizontal();
		GUILayout.Label("SkillID:");
        DataSetting.skillID = EditorGUILayout.IntField(DataSetting.skillID, GUILayout.MaxWidth(80));
		if(GUILayout.Button("AddAnimState")) {
			var item = new SkillOneAnimationState { SkillStateIndex = stateList.Count, skillIndex = SkillIndex };
			stateList.Add(item);
			item.UpdateAnimationList(modelPath);
            UpdateStateListItemIndex();
		}

		toRemovePhaseIndex = EditorGUILayout.IntField(toRemovePhaseIndex, GUILayout.MaxWidth(80));
		if (GUILayout.Button("RemoveAnimState")) {
			if (toRemovePhaseIndex < stateList.Count ) {
				stateList.RemoveAt(toRemovePhaseIndex);
				UpdateStateListItemIndex();
			}
		}

		GUILayout.FlexibleSpace();
		EditorGUILayout.EndHorizontal();
	}

	private void UpdateStateListItemIndex()
	{
		for(int i = 0;i<stateList.Count;i++)
			stateList[i].SkillStateIndex = i;

		return;
	}

	private void LoadAimation()
	{
	}
}
