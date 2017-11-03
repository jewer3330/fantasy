using UnityEngine;
using UnityEditor;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using System;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using SLua;

[Serializable]
public class SkilldataSetting
{
    public string skillUID;
    public int skillIndex = 0;
	public int skillID = 0;
	public string skillName;
	public ReleaseMode castType;
	public string skillDescription;
	public int rangeEffectID = 1018;
	public float rangeRadius;
	public int indicatorEffectID = 1017;
	public PTIndicatorType indicatorType;
	public ReleaseType indicatorFollowType;
    //public SecondTrigger secondTrigger;
    //public SecondEvent secondEvent;
	public float indicatorRadius;
	public float indicatorAngle;
	public float indicatorLength;
	public float indicatorWidth;
    public bool touchDelay;
    public float touchDelayTime;
	public bool needCheckCollider;
    public bool needExtendIndicator;
    public int extendIndicatorA = 1018;
    public int extendIndicatorB = 1017;
    public float extendIndicatorRadius;
    public float extendIndicatorWidth;

    public bool isSecondPhase;


    //SecondPhase
    public int S_rangeEffectID = 1018;
    public float S_rangeRadius;
    public int S_indicatorEffectID = 1017;
    public PTIndicatorType S_indicatorType;
    public ReleaseType S_indicatorFollowType;
    public float S_indicatorRadius;
    public float S_indicatorAngle;
    public float S_indicatorLength;
    public float S_indicatorWidth;
    public bool S_needCheckCollider;
    public bool S_needExtendIndicator;
    public int S_extendIndicatorA = 1018;
    public int S_extendIndicatorB = 1017;
    public float S_extendIndicatorRadius;
    public float S_extendIndicatorWidth;

    public SkilldataSetting Clone()
    {
        MemoryStream stream = new MemoryStream();
        BinaryFormatter formatter = new BinaryFormatter();
        formatter.Serialize(stream, this);
        stream.Position = 0;
        return formatter.Deserialize(stream) as SkilldataSetting;
    }
}

/// <summary>
///   Load character, animation & set phases.
/// </summary>
public class PTCharacterWindow : EditorWindow
{
	#region const member
	private static readonly float innerSpacing = 3f;
	private static readonly float lineSpacing = 5f;
	private static readonly float doubleSpacing = lineSpacing * 2;
	#endregion const member

	#region private member
	private bool loadFlag = false;	// whether model has been loaded
	private bool dirtyFlag = false; // whether need to load animation
	private float sampleTime = 0f;
	public GameObject cha = null;
	private AnimationClip clip = null;
	private Dictionary<Transform, float> FX = new Dictionary<Transform, float>();
	private List<string> fDirs = new List<string>();
    private List<string> fEnemyDirs = new List<string>();
	private List<string> modelNames = new List<string>();
	private int idx = 0, animIdx = 0;
	private string baseHeroModelPath = "Assets/Content/Character/Hero/";
    private string baseNpcModelPath = "Assets/Content/Character/Npc/";
	private string modelNameIndex = "";
    private string modelName = "";
	private List<string> animationFiles = new List<string>();
	private bool playFlag = false;
	private float lastUpdateTime = 0f;
	private bool componentFlag = false;
	private Rect windowRect = new Rect(10f, 10f, 100f, 100f);
	public static string curCharacter { get; set; }

    private int selectedIndicatorType;
    private string[] characterTypes;
	private string[] castTypes;
	private string[] indicatorTypes;
	private string[] indicatorFollowTypes;
    private string[] secondTriggerTypes;
    private string[] secondEventTypes;

    private bool nameDictReady;
    private Dictionary<string, string> heroNameDict;
    private Dictionary<string, string> npcNameDict;
	#endregion private member

	#region public member
	public List<SkilldataSetting> skillList = new List<SkilldataSetting>();
	private Dictionary<int, HeroSkillIDs> heroSkillIDCache = new Dictionary<int, HeroSkillIDs>();
	protected int toRemoveSkillID = 0;
    protected int originSkillId = 0;
    protected int copySkillId = 0;
    private bool reInitGraph = false;
    public PTCharacterType selectedCharacterType;
	#endregion public member

	#region mono
	private void Update()
	{
		// sample animation clip & FX via slider value
		if (cha == null || clip == null)
			return;

		if (!EditorApplication.isPlaying && AnimationMode.InAnimationMode()) {
			AnimationMode.SampleAnimationClip(cha, clip, sampleTime);
			foreach (KeyValuePair<Transform, float> item in FX) {
				if (sampleTime >= item.Value)
					item.Key.GetComponent<SFXController>().Simulate(sampleTime - item.Value);
			}

			float curTime = Time.realtimeSinceStartup;
			float dt = curTime - lastUpdateTime;
			lastUpdateTime = curTime;

			if (playFlag) {
				sampleTime += dt;
				if (sampleTime > clip.length)
					sampleTime = 0f;
				Repaint();
			}

			SceneView.RepaintAll();
		}

		return;
	}

	private void OnEnable()
	{
		UpdateModelDirectory();
	    UpdateNameDict();

		return;
	}

	private void OnDestroy()
	{
		AnimationMode.StopAnimationMode();
		loadFlag = false;
		dirtyFlag = false;
	    nameDictReady = false;
		ClearModel();
		ClearFX();
	    ClearNameDictCache();

        return;
	}

	private void OnGUI()
	{
	    if (!nameDictReady)
	    {
	        GUILayout.BeginHorizontal();
	        GUILayout.Label("获取角色信息中…");
	        GUILayout.EndHorizontal();
	        return;
	    }

	    LoadCharacter();		// load character and skill datas

		GUILayout.Space(doubleSpacing);
		GUILayout.BeginHorizontal();
		GUILayout.FlexibleSpace();
		ExportButton();
		ResetButton();
		GUILayout.EndHorizontal();

		return;
	}
	#endregion mono

	#region private imp
	private void LoadCharacter()
	{
		// 获取角色类型
        if (characterTypes == null) {
			characterTypes = Enum.GetValues(typeof(PTCharacterType)).Cast<PTCharacterType>().Select(v => v.ToString()).ToArray();
        }
        selectedCharacterType = (PTCharacterType)EditorGUILayout.Popup((int)selectedCharacterType, characterTypes.ToArray());
        PrometheusUtil.curCharacterType = selectedCharacterType;
        LoadModel(PrometheusUtil.curCharacterType);

        if (loadFlag)
            SetSkillData();
    }

    /// <summary>
    /// 获取带有名称的 id 数组 
    /// + 暂时用于编辑窗口提示选取英雄/NPC的名称 
    /// </summary>
    private string[] GetTaggedIdArray(PTCharacterType modelType, IEnumerable<string> idGroup)
    {
        if (idGroup == null)
            return new string[] {};

        int count = idGroup.Count();
        List<string> output = new List<string>();
        Dictionary<string, string> refDict;

        if (modelType == PTCharacterType.Hero)
        {
            refDict = heroNameDict;
        }
        else // if (modelType == PTCharacterType.Npc)
        {
            refDict = npcNameDict;
        }

        foreach (string id in idGroup)
        {
            if (refDict.ContainsKey(id))
                output.Add(id + refDict[id]);
            else
                output.Add(id);
        }
        return output.ToArray();
    }

    private void LoadModel(PTCharacterType modelType)
	{
		GUILayout.Space(lineSpacing);
		GUILayout.BeginVertical("box");
		GUILayout.Label("Character");
		GUILayout.BeginHorizontal();
		modelNames.Clear();

	    if (modelType == PTCharacterType.Hero)
	    {
	        foreach (string dir in fDirs)
	            modelNames.Add(dir.Substring(dir.LastIndexOf("\\") + 1, 3));
	        idx = EditorGUILayout.Popup(idx, GetTaggedIdArray(modelType, modelNames));
	        modelNameIndex = modelNames[idx];
	        modelName = "Hero_" + modelNameIndex;
	    }
	    else if (modelType == PTCharacterType.Npc)
	    {
	        foreach (string dir in fEnemyDirs)
	            modelNames.Add(dir.Substring(dir.LastIndexOf("\\") + 1, 3));
	        idx = EditorGUILayout.Popup(idx, GetTaggedIdArray(modelType, modelNames));
	        modelNameIndex = modelNames[idx];
	        modelName = "Npc_" + modelNameIndex;
	    }

	    if (GUILayout.Button("Load Character")) {
            string loadPath = "";
            switch (modelType) {
                case PTCharacterType.Hero:
                    loadPath = baseHeroModelPath + modelNameIndex + "/Hero" + modelNameIndex + ".FBX";
                    break;
                case PTCharacterType.Npc:
                    loadPath = baseNpcModelPath + modelNameIndex + "/Npc" + modelNameIndex + ".FBX";
                    break;
            }

			GameObject test = AssetDatabase.LoadAssetAtPath(loadPath, typeof(GameObject)) as GameObject;
			cha = GameObject.Instantiate(test);
			loadFlag = true;
			dirtyFlag = true;
			var graph = PrometheusUtil.LoadGraph(modelName);
			PrometheusUtil.curCharacter = cha;
			PrometheusUtil.modelName = modelNameIndex;
			graph.Init();
			var window = GetWindow<Prometheus>("Null",false);
			AssetDatabase.SaveAssets();
			window.curGraph = graph;

            skillList.Clear();

            //foreach (var item in window.curGraph.skillPhaseList)
            //    skillList.Add(item.DataSetting);

            //读取文件 写入编辑器
            ReadFile(modelName);
            for (int i = 0; i < skillList.Count; ++i)
            {
                window.curGraph.skillPhaseList[i].DataSetting = skillList[i];
            }

			// focus on character
            if(SceneView.sceneViews.Count > 0)
			    ((SceneView)(SceneView.sceneViews[0])).Focus();
			Selection.activeGameObject = cha;
			if (SceneView.lastActiveSceneView != null)
				SceneView.lastActiveSceneView.LookAt(Vector3.zero, Quaternion.identity * Quaternion.Euler(45, 225, 0), 8f);

			// set current character name
			curCharacter = modelNameIndex;
		}
		GUILayout.EndHorizontal();
		GUILayout.EndVertical();

		return;
	}

    private void SetSkillData()
    {
        GUILayout.Space(lineSpacing);
        EditorGUILayout.BeginVertical();
        EditorGUILayout.BeginHorizontal();
        if (GUILayout.Button("AddSkill", GUILayout.MinWidth(100)))
            skillList.Add(new SkilldataSetting());
        GUILayout.FlexibleSpace();

        GUILayout.Label("Origin:");
        originSkillId = EditorGUILayout.IntField(originSkillId, GUILayout.MaxWidth(100));
        GUILayout.Label("Copy:");
        copySkillId = EditorGUILayout.IntField(copySkillId, GUILayout.MaxWidth(100));
        if (GUILayout.Button("CopySkill", GUILayout.MinWidth(100)))
        {
            var targetItem = skillList.FirstOrDefault(obj => obj.skillID.Equals(copySkillId));
            if (skillList.Count > 0 && originSkillId > 0 && targetItem == null)
            {
                var item = skillList.FirstOrDefault(obj => obj.skillID.Equals(originSkillId));
                if (null != item)
                {
                    SkilldataSetting newItem = item.Clone();
                    newItem.skillID = copySkillId;
                    newItem.skillName = originSkillId + "-Copy";
                    skillList.Add(newItem);
                    CopySkill(item, newItem);
                }
                else
                {
                    Debug.LogError("Can't find " + copySkillId + " in skill list.");
                }
            }
            else
            {
                Debug.LogError("SkillList is NULL or the given skill id is ILLEGAL.");
            }
        }

        toRemoveSkillID = EditorGUILayout.IntField(toRemoveSkillID);
        if (GUILayout.Button("RemoveSkill", GUILayout.MinWidth(100)))
        {
            if (skillList.Count > 0)
            {
                var item = skillList[skillList.Count - 1];
                var window = GetWindow<Prometheus>("Prometheus", false);
                window.curGraph.RemoveSkillPhase(item.skillID);
                skillList.Remove(item);
            }
        }
        EditorGUILayout.EndHorizontal();
        GUILayout.Space(lineSpacing);

        int countTi = -1;
        foreach (var item in skillList)
        {
            countTi++;
            //EditorGUILayout.BeginHorizontal();
            EditorGUILayout.LabelField("SkillID:", GUILayout.MaxWidth(50));
            item.skillID = EditorGUILayout.IntField(item.skillID);
            //EditorGUILayout.LabelField("SkillName:", GUILayout.MaxWidth(70));
            //item.skillName = EditorGUILayout.TextField(item.skillName);
            //item.skillIndex = countTi;
            //// 设置释放类型
            //SetCastType(item);
            //// 设置技能指示器
            //SetSkillIndicator(item);
            //SetTouchDelay(item);
            //EditorGUILayout.LabelField("hasSecondPhase:", GUILayout.MaxWidth(120));
            //item.isSecondPhase = EditorGUILayout.Toggle(item.isSecondPhase, GUILayout.MaxWidth(50));
            //EditorGUILayout.EndHorizontal();
            //if (item.isSecondPhase)
            //    SetSecondPhase(item);
            //EditorGUILayout.LabelField("SkillDescription:", GUILayout.MaxWidth(120));
            //item.skillDescription = EditorGUILayout.TextArea(item.skillDescription, GUILayout.MinHeight(60));
            EditorGUILayout.Space();
        }
        EditorGUILayout.EndVertical();

        return;
    }

    private void CopySkill(SkilldataSetting srcSkill, SkilldataSetting destSkill)
    {
        //拷贝技能柏拉图描述文件
        string srcFileName = "SkillScript" + srcSkill.skillID;
        string destFileName = "SkillScript" + destSkill.skillID;
        string srcFilePath = PLATO.PLATO_SAVE_PATH + srcFileName + ".txt";
        string destFilePath = PLATO.PLATO_SAVE_PATH + destFileName + ".txt";
        File.Copy(srcFilePath, destFilePath, true);

        //文件关键词替换
        string[] skillDefLines = File.ReadAllLines(destFilePath);
        for (int i = 0; i < skillDefLines.Length; i++)
        {
            skillDefLines[i] = skillDefLines[i].Replace(srcFileName, destFileName);
        }
        File.WriteAllLines(destFilePath, skillDefLines);

        AssetDatabase.Refresh();
        reInitGraph = true;
    }

    private void SetSecondPhase(SkilldataSetting skillSetting)
    {
        EditorGUILayout.BeginHorizontal();
        if (secondTriggerTypes == null) {
            //secondTriggerTypes = Enum.GetValues(typeof(SecondTrigger)).Cast<SecondTrigger>().Select(v => v.ToString()).ToArray();
        }

        EditorGUILayout.LabelField("SecTrigger:", GUILayout.MaxWidth(90));
        //skillSetting.secondTrigger = (SecondTrigger)EditorGUILayout.Popup((int)skillSetting.secondTrigger, secondTriggerTypes);

        //if (secondEventTypes == null) {
        //    secondEventTypes = Enum.GetValues(typeof(SecondEvent)).Cast<SecondEvent>().Select(v => v.ToString()).ToArray();
        //}

        //EditorGUILayout.LabelField("SecEvent:", GUILayout.MaxWidth(90));
        //skillSetting.secondEvent = (SecondEvent)EditorGUILayout.Popup((int)skillSetting.secondEvent, secondEventTypes);

        SetSecPhaseSkillIndicator(skillSetting);
        EditorGUILayout.EndHorizontal();


    }

	private void SetCastType(SkilldataSetting skillSetting)
	{
		// 获取释放类型
		if (castTypes == null)
		{
			castTypes = Enum.GetValues(typeof(ReleaseMode)).Cast<ReleaseMode>().Select(v => v.ToString()).ToArray();
		}
		// 设置释放类型
		skillSetting.castType = (ReleaseMode)EditorGUILayout.Popup((int)skillSetting.castType, castTypes);
	}

    private void SetTouchDelay(SkilldataSetting skillSetting)
    {
        if (skillSetting.castType == ReleaseMode.Touch) {
            EditorGUILayout.LabelField("TouchDelay:", GUILayout.MaxWidth(60));
            skillSetting.touchDelay = EditorGUILayout.Toggle(skillSetting.touchDelay, GUILayout.MaxWidth(50));
            if (skillSetting.touchDelay) {
                EditorGUILayout.LabelField("TDTime:", GUILayout.MaxWidth(60));
                skillSetting.touchDelayTime = EditorGUILayout.FloatField(skillSetting.touchDelayTime);
            }
        }
    }

	private void SetSkillIndicator(SkilldataSetting skillSetting)
	{
		// 范围指示器
		EditorGUILayout.LabelField("RangeEffectID:", GUILayout.MaxWidth(100));
		skillSetting.rangeEffectID = EditorGUILayout.IntField(skillSetting.rangeEffectID);
		EditorGUILayout.LabelField("RangeEffectRadius:", GUILayout.MaxWidth(120));
		skillSetting.rangeRadius = EditorGUILayout.FloatField(skillSetting.rangeRadius);
		// 释放指示器
		// 获取指示器类型
		if(indicatorTypes == null)
		{
			indicatorTypes = Enum.GetValues(typeof(PTIndicatorType)).Cast<PTIndicatorType>().Select(v => v.ToString()).ToArray();
		}
		// 设置指示器类型
		skillSetting.indicatorType = (PTIndicatorType)EditorGUILayout.Popup((int)skillSetting.indicatorType, indicatorTypes);
		// 指示器特效ID
		EditorGUILayout.LabelField("IndicatorEffectID:", GUILayout.MaxWidth(100));
		skillSetting.indicatorEffectID = EditorGUILayout.IntField(skillSetting.indicatorEffectID);
		// 根据类型显示参数列表
		switch (skillSetting.indicatorType)
		{
			case PTIndicatorType.Circle:
				EditorGUILayout.LabelField("IndicatorRadius:", GUILayout.MaxWidth(100));
				skillSetting.indicatorRadius = EditorGUILayout.FloatField(skillSetting.indicatorRadius);
				break;
			case PTIndicatorType.Sector:
				EditorGUILayout.LabelField("IndicatorRadius:", GUILayout.MaxWidth(100));
				skillSetting.indicatorRadius = EditorGUILayout.FloatField(skillSetting.indicatorRadius);
				EditorGUILayout.LabelField("IndicatorAngle:", GUILayout.MaxWidth(100));
				skillSetting.indicatorAngle = EditorGUILayout.FloatField(skillSetting.indicatorAngle);
				break;
			case PTIndicatorType.Rectangle:
				EditorGUILayout.LabelField("IndicatorLength:", GUILayout.MaxWidth(100));
				skillSetting.indicatorLength = EditorGUILayout.FloatField(skillSetting.indicatorLength);
				EditorGUILayout.LabelField("IndicatorWidth:", GUILayout.MaxWidth(100));
				skillSetting.indicatorWidth = EditorGUILayout.FloatField(skillSetting.indicatorWidth);
				break;
			default:
				break;
		}

		// 获取指示器跟随类型
		if (indicatorFollowTypes == null)
		{
			indicatorFollowTypes = Enum.GetValues(typeof(ReleaseType)).Cast<ReleaseType>().Select(v => v.ToString()).ToArray();
		}

		skillSetting.indicatorFollowType = (ReleaseType)EditorGUILayout.Popup((int)skillSetting.indicatorFollowType, indicatorFollowTypes);
		// 如果是选取位置的类型，需要设置是否能穿越碰撞体
		if(skillSetting.indicatorFollowType == ReleaseType.FollowReleasePos)
		{
			EditorGUILayout.LabelField("NeedCheckCollider:", GUILayout.MaxWidth(100));
			skillSetting.needCheckCollider = EditorGUILayout.Toggle(skillSetting.needCheckCollider,GUILayout.MaxWidth(50));
		}

        if (skillSetting.indicatorFollowType == ReleaseType.FollowReleasePos || skillSetting.indicatorFollowType == ReleaseType.FollowReleaseDir) {
            EditorGUILayout.LabelField("NeedExtInd:", GUILayout.MaxWidth(100));
            skillSetting.needExtendIndicator = EditorGUILayout.Toggle(skillSetting.needExtendIndicator, GUILayout.MaxWidth(50));
        }

        if (skillSetting.needExtendIndicator) {
            switch (skillSetting.indicatorFollowType) {
                case ReleaseType.FollowReleaseDir:
                    EditorGUILayout.LabelField("ExtendIndiA:", GUILayout.MaxWidth(100));
                    skillSetting.extendIndicatorA = EditorGUILayout.IntField(skillSetting.extendIndicatorA);
                    EditorGUILayout.LabelField("ExtRad:", GUILayout.MaxWidth(80));
                    skillSetting.extendIndicatorRadius = EditorGUILayout.FloatField(skillSetting.extendIndicatorRadius);
                    break;
                case ReleaseType.FollowReleasePos:
                    EditorGUILayout.LabelField("ExtendIndiB:", GUILayout.MaxWidth(100));
                    skillSetting.extendIndicatorB = EditorGUILayout.IntField(skillSetting.extendIndicatorB);
                    EditorGUILayout.LabelField("ExtWid:", GUILayout.MaxWidth(80));
		            skillSetting.extendIndicatorWidth = EditorGUILayout.FloatField(skillSetting.extendIndicatorWidth);
                    break;
            }
        }
    }

    private void SetSecPhaseSkillIndicator(SkilldataSetting skillSetting)
    {
        // 范围指示器
        EditorGUILayout.LabelField("SecRangeEffID:", GUILayout.MaxWidth(100));
        skillSetting.S_rangeEffectID = EditorGUILayout.IntField(skillSetting.S_rangeEffectID);
        EditorGUILayout.LabelField("SecRangeEffRadius:", GUILayout.MaxWidth(120));
        skillSetting.S_rangeRadius = EditorGUILayout.FloatField(skillSetting.S_rangeRadius);
        // 释放指示器
        // 获取指示器类型
        if (indicatorTypes == null) {
            indicatorTypes = Enum.GetValues(typeof(PTIndicatorType)).Cast<PTIndicatorType>().Select(v => v.ToString()).ToArray();
        }
        // 设置指示器类型
        skillSetting.S_indicatorType = (PTIndicatorType)EditorGUILayout.Popup((int)skillSetting.S_indicatorType, indicatorTypes);
        // 指示器特效ID
        EditorGUILayout.LabelField("SecIndicaEffID:", GUILayout.MaxWidth(100));
        skillSetting.S_indicatorEffectID = EditorGUILayout.IntField(skillSetting.S_indicatorEffectID);
        // 根据类型显示参数列表
        switch (skillSetting.S_indicatorType) {
            case PTIndicatorType.Circle:
                EditorGUILayout.LabelField("SecIndicaRadius:", GUILayout.MaxWidth(100));
                skillSetting.S_indicatorRadius = EditorGUILayout.FloatField(skillSetting.S_indicatorRadius);
                break;
            case PTIndicatorType.Sector:
                EditorGUILayout.LabelField("SecIndicaRadius:", GUILayout.MaxWidth(100));
                skillSetting.S_indicatorRadius = EditorGUILayout.FloatField(skillSetting.S_indicatorRadius);
                EditorGUILayout.LabelField("SecIndicaAngle:", GUILayout.MaxWidth(100));
                skillSetting.S_indicatorAngle = EditorGUILayout.FloatField(skillSetting.S_indicatorAngle);
                break;
            case PTIndicatorType.Rectangle:
                EditorGUILayout.LabelField("SecIndicaLength:", GUILayout.MaxWidth(100));
                skillSetting.S_indicatorLength = EditorGUILayout.FloatField(skillSetting.S_indicatorLength);
                EditorGUILayout.LabelField("SecIndicaWidth:", GUILayout.MaxWidth(100));
                skillSetting.S_indicatorWidth = EditorGUILayout.FloatField(skillSetting.S_indicatorWidth);
                break;
            default:
                break;
        }

        // 获取指示器跟随类型
        if (indicatorFollowTypes == null) {
            indicatorFollowTypes = Enum.GetValues(typeof(ReleaseType)).Cast<ReleaseType>().Select(v => v.ToString()).ToArray();
        }

        skillSetting.S_indicatorFollowType = (ReleaseType)EditorGUILayout.Popup((int)skillSetting.S_indicatorFollowType, indicatorFollowTypes);
        // 如果是选取位置的类型，需要设置是否能穿越碰撞体
        if (skillSetting.S_indicatorFollowType == ReleaseType.FollowReleasePos) {
            EditorGUILayout.LabelField("SecNeedCheckCollider:", GUILayout.MaxWidth(100));
            skillSetting.S_needCheckCollider = EditorGUILayout.Toggle(skillSetting.S_needCheckCollider, GUILayout.MaxWidth(50));
        }

        if (skillSetting.S_indicatorFollowType == ReleaseType.FollowReleasePos || skillSetting.S_indicatorFollowType == ReleaseType.FollowReleaseDir) {
            EditorGUILayout.LabelField("SNeedExtInd:", GUILayout.MaxWidth(100));
            skillSetting.S_needExtendIndicator = EditorGUILayout.Toggle(skillSetting.S_needExtendIndicator, GUILayout.MaxWidth(50));
        }

        if (skillSetting.S_needExtendIndicator) {
            switch (skillSetting.S_indicatorFollowType) {
                case ReleaseType.FollowReleaseDir:
                    EditorGUILayout.LabelField("SExtendIndiA:", GUILayout.MaxWidth(100));
                    skillSetting.S_extendIndicatorA = EditorGUILayout.IntField(skillSetting.S_extendIndicatorA);
                    EditorGUILayout.LabelField("SExtRad:", GUILayout.MaxWidth(80));
                    skillSetting.S_extendIndicatorRadius = EditorGUILayout.FloatField(skillSetting.S_extendIndicatorRadius);
                    break;
                case ReleaseType.FollowReleasePos:
                    EditorGUILayout.LabelField("SExtendIndiB:", GUILayout.MaxWidth(100));
                    skillSetting.S_extendIndicatorB = EditorGUILayout.IntField(skillSetting.S_extendIndicatorB);
                    EditorGUILayout.LabelField("SExtWid:", GUILayout.MaxWidth(80));
                    skillSetting.S_extendIndicatorWidth = EditorGUILayout.FloatField(skillSetting.S_extendIndicatorWidth);
                    break;
            }
        }
    }

	private void LoadAnimation()
	{
		if (dirtyFlag)
			UpdateAnimationList();

		GUILayout.Space(lineSpacing);
		GUILayout.BeginVertical("box");
		GUILayout.Label("Animation");
		GUILayout.BeginHorizontal();
		animIdx = EditorGUILayout.Popup(animIdx, animationFiles.ToArray());
		if (GUILayout.Button("Load Animation")) {
			Animator temp = cha.GetComponent<Animator>();
			clip = AssetDatabase.LoadAssetAtPath(baseHeroModelPath + modelNameIndex + "/" + animationFiles[animIdx], typeof(AnimationClip)) as AnimationClip;
			if (clip == null)
				Debug.Log("Animation load failed");
			UnityEditor.Animations.AnimatorController ac = UnityEditor.Animations.AnimatorController.CreateAnimatorControllerAtPath("Assets/AnimatorTest/act.controller");
			temp.runtimeAnimatorController = ac as RuntimeAnimatorController;;
			AnimationMode.StopAnimationMode();
		}
		GUILayout.EndHorizontal();
		GUILayout.EndVertical();

		return;
	}

	private void SampleAnimation()
	{
		GUILayout.Space(lineSpacing);
		GUILayout.BeginVertical("box");
		GUILayout.Label("Sample Animation");
		GUILayout.BeginHorizontal();
		EditorGUI.BeginChangeCheck();
		GUILayout.Toggle(AnimationMode.InAnimationMode(), "Animate", EditorStyles.toolbarButton);
		if (EditorGUI.EndChangeCheck())
			ToggleAnimationMode();
		sampleTime = EditorGUILayout.Slider(sampleTime, 0f, 1f);

		// add animation event
		if (GUILayout.Button("Add Event")) {
			// we set all animation events every time, so we have to prepare all animation
			// events first every time

			// get modelImporoter
			// we need modelImporter to set animations' events
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

			// get all events
			AnimationEvent[] events = clipInfoProperties.GetEvents();

			// create new event
			AnimationEvent evt = new AnimationEvent();
			evt.intParameter = 2;
			evt.time = sampleTime;
			evt.functionName = "PrintTest";

			// add new event to events array
			ArrayUtility.Add(ref events, evt);

			// set events
			clipInfoProperties.SetEvents(events);

			// serialize data
			serializedObject.ApplyModifiedProperties();
		}

		BeginWindows();
		if (GUILayout.Button("Add Component"))
			componentFlag = true;

		if (componentFlag)
			windowRect = GUI.Window(0, windowRect, winFun, "Component");
		EndWindows();

		GUILayout.EndHorizontal();
		GUILayout.Space(innerSpacing);

		// playback
		GUILayout.BeginHorizontal();
		if (!playFlag) {
			if (GUILayout.Button("Play"))
				playFlag = true;
		}
		else if (GUILayout.Button("Stop"))
			playFlag = false;
		GUILayout.EndHorizontal();

		GUILayout.EndVertical();

		return;
	}

	private void LoadFX()
	{
		GUILayout.Space(lineSpacing);
		GUILayout.BeginVertical("box");
		GUILayout.Label("FX");
		GUILayout.BeginHorizontal();
		if (GUILayout.Button("Add SFX")) {
			FX.Clear();
			Transform sfx = AssetDatabase.LoadAssetAtPath("Assets/Resources/Prefabs/SFX/Comon/Explode/Petroltank/Petroltank_001.prefab", typeof(Transform)) as Transform;
			Transform sfxTrans = GameObject.Instantiate(sfx);
			FX.Add(sfxTrans, sampleTime);
		}
		GUILayout.EndHorizontal();
		GUILayout.EndVertical();

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

    private void UpdateNameDict()
    {
        nameDictReady = false;

        heroNameDict = new Dictionary<string, string>();
        npcNameDict = new Dictionary<string, string>();

        CsvDataMgr.LoadInMainThread("Data/Hero", HandleHeroSheet, () =>
        {
            CsvDataMgr.LoadInMainThread("Data/Monster", HandleMonsterSheet, OnSheetLoaded);
        });
    }

    //HACK(wenyu.zhao):由于表段前部分少有改动，所以这里写死列数更方便 
    //规则：id 取表格主键后三位与模型编号对应 
    private void HandleHeroSheet(string[] lineData)
    {
        if (null == lineData || lineData.Length < 5) return;

        string key = lineData[0].Substring(lineData[0].Length - 3);
        string value = string.Format(" [{0}·{1}]", lineData[3], lineData[4]);

        if (heroNameDict.ContainsKey(key))
            heroNameDict[key] = value;
        else
            heroNameDict.Add(key, value);
    }

    //HACK(wenyu.zhao):由于表段前部分少有改动，所以这里写死列数更方便 
    //规则：不同名称拼接直至整体长度大于20
    private void HandleMonsterSheet(string[] lineData)
    {
        if (null == lineData || lineData.Length < 11 || string.IsNullOrEmpty(lineData[4])) return;

        string key = lineData[9];
        string value = string.Format(" [{0}]", lineData[4]);

        if (!npcNameDict.ContainsKey(key))
            npcNameDict.Add(key, value);
        else if (npcNameDict[key].Length < 20 && !npcNameDict[key].Contains(lineData[4]))
            npcNameDict[key] += value;
    }

    private void OnSheetLoaded()
    {
        nameDictReady = true;
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

        // get enmey directory list
        string[] enemydirs = Directory.GetDirectories("Assets/Content/Character/Npc");

        // filter with directories' names
        System.Text.RegularExpressions.Regex enmeysearchTerm =
            new System.Text.RegularExpressions.Regex(@"\d{3}$");

        var enemyFilterdDirs = from enemydir in enemydirs
                               where (enmeysearchTerm.IsMatch(enemydir))
                               select enemydir;

        fEnemyDirs.Clear();
        fEnemyDirs = enemyFilterdDirs.ToList();

		return;
	}

	private void UpdateAnimationList()
	{
		// get model path
		string modelPath = fDirs[idx];

		// find all animation files
		string[] aFiles = Directory.GetFiles(modelPath, "*@*");

		animationFiles.Clear();
		for (int i = 0; i < aFiles.Length; ++i) {
			if (aFiles[i].Contains("meta"))
				continue;
			int lastIdx = aFiles[i].LastIndexOf("\\");
			animationFiles.Add(aFiles[i].Substring(lastIdx + 1, aFiles[i].Length - lastIdx - 1));
		}
		dirtyFlag = false;

		return;
	}

	private void winFun(int id)
	{
		// if (GUILayout.Button("Modal")) {
		// 	Debug.Log("Modal window");
		// }
		GUI.BringWindowToFront(id);
		GUI.DragWindow();

		return;
	}

	private void ExportButton()
	{
		if (GUILayout.Button("ExportToLua"))
			ExportToLua();

		if (GUILayout.Button("ExportToCsv"))
			ExportToCsv();

		return;
	}

	private void ExportToLua()
	{
        
		var window = GetWindow<Prometheus>();
		PrometheusUtil.curCharacter = cha;
		PrometheusUtil.modelName = modelNameIndex;
		if(window.curGraph == null)
		{
			window.curGraph = PrometheusUtil.LoadGraph(modelName);
			window.curGraph.Init();
		}

        //TODO 导出英雄技能ID表
        string characterID = "";
        List<string> tempList = null;
        string typeTitle = "";
        if (selectedCharacterType == PTCharacterType.Hero)
        {
            characterID = modelNameIndex;// (1 + idx) > 9 ? "0" + (1 + idx) : "00" + (1 + idx);
            tempList = fDirs;
            typeTitle = "Hero";
        }
        else
        {
            characterID = modelNameIndex;
            tempList = fEnemyDirs;
            typeTitle = "Npc";
        }

        string content = String.Empty;
        content += "--Creat " + typeTitle + "SkillTable\n";
        string tableName = typeTitle + characterID + "SkillData";
        content += tableName + " = {}";

        content += "\n\n";

        content += "\n" + typeTitle + characterID + "SkillData" + ".HeroID = " + characterID;
        content += "\n\n";
        int skillCount = skillList.Count;// > 3 ? 3 : skillList.Count;
        for (int i = 0; i < skillCount; i++)
        {
            //skillUID 作为skill的唯一标识 而不是原来的skillID
            skillList[i].skillUID = typeTitle + characterID + skillList[i].skillIndex;
            window.curGraph.AddSkillPhase(tempList[idx], skillList[i]);
            //Debug.Log("skillIndex = " + skillList[i].skillIndex + "; skillID = " + skillList[i].skillID + "; skillName = " + skillList[i].skillName + "; skillUID = " + skillList[i].skillUID);
            int index = i + 1;
            content += "\n" + "table.insert(" + tableName + ",{})";
            content += "\n" + tableName + "[" + index + "].skillID = " + (int)skillList[i].skillID;
            //content += "\n" + tableName + "[" + index + "].skillName = " + "'" + skillList[i].skillName + "'";
            //content += "\n" + tableName + "[" + index + "].cdType = " + (int)skillList[i].cdType;
            //content += "\n" + tableName + "[" + index + "].cdValue = " + (float)skillList[i].cdValue;
            //content += "\n" + tableName + "[" + index + "].castType = " + (int)skillList[i].castType;
            //content += "\n" + tableName + "[" + index + "].releaseEffectID = " + skillList[i].rangeEffectID.ToString();
            //content += "\n" + tableName + "[" + index + "].rangeRadius = " + skillList[i].rangeRadius.ToString();
            //content += "\n" + tableName + "[" + index + "].indicatorEffectID = " + skillList[i].indicatorEffectID.ToString();
            //content += "\n" + tableName + "[" + index + "].indicatorType = " + (int)skillList[i].indicatorType;
            //content += "\n" + tableName + "[" + index + "].indicatorRadius = " + skillList[i].indicatorRadius.ToString();
            //content += "\n" + tableName + "[" + index + "].indicatorAngle = " + skillList[i].indicatorAngle.ToString();
            //content += "\n" + tableName + "[" + index + "].indicatorLength = " + skillList[i].indicatorLength.ToString();
            //content += "\n" + tableName + "[" + index + "].indicatorWidth = " + skillList[i].indicatorWidth.ToString();
            //content += "\n" + tableName + "[" + index + "].indicatorFollowType = " + (int)skillList[i].indicatorFollowType;
            //content += "\n" + tableName + "[" + index + "].touchDelay = " + skillList[i].touchDelay.ToString().ToLower();
            //content += "\n" + tableName + "[" + index + "].touchDelayTime = " + skillList[i].touchDelayTime.ToString();
            //content += "\n" + tableName + "[" + index + "].needCheckCollider = " + skillList[i].needCheckCollider.ToString().ToLower();
            //content += "\n" + tableName + "[" + index + "].needExtendIndicator = " + skillList[i].needExtendIndicator.ToString().ToLower();
            //content += "\n" + tableName + "[" + index + "].extendIndicatorA = " + skillList[i].extendIndicatorA.ToString();
            //content += "\n" + tableName + "[" + index + "].extendIndicatorB = " + skillList[i].extendIndicatorB.ToString();
            //content += "\n" + tableName + "[" + index + "].extendIndicatorRadius = " + skillList[i].extendIndicatorRadius.ToString();
            //content += "\n" + tableName + "[" + index + "].extendIndicatorWidth = " + skillList[i].extendIndicatorWidth.ToString();
            ////content += "\n" + tableName + "[" + index + "].secondTrigger = " + (int)skillList[i].secondTrigger;
            ////content += "\n" + tableName + "[" + index + "].secondEvent = " + (int)skillList[i].secondEvent;
            //content += "\n" + tableName + "[" + index + "].hasSecondPhase = " + skillList[i].hasSecondPhase.ToString().ToLower();


            //content += "\n" + tableName + "[" + index + "].sreleaseEffectID = " + skillList[i].S_rangeEffectID.ToString();
            //content += "\n" + tableName + "[" + index + "].srangeRadius = " + skillList[i].S_rangeRadius.ToString();
            //content += "\n" + tableName + "[" + index + "].sindicatorEffectID = " + skillList[i].S_indicatorEffectID.ToString();
            //content += "\n" + tableName + "[" + index + "].sindicatorType = " + (int)skillList[i].S_indicatorType;
            //content += "\n" + tableName + "[" + index + "].sindicatorRadius = " + skillList[i].S_indicatorRadius.ToString();
            //content += "\n" + tableName + "[" + index + "].sindicatorAngle = " + skillList[i].S_indicatorAngle.ToString();
            //content += "\n" + tableName + "[" + index + "].sindicatorLength = " + skillList[i].S_indicatorLength.ToString();
            //content += "\n" + tableName + "[" + index + "].sindicatorWidth = " + skillList[i].S_indicatorWidth.ToString();
            //content += "\n" + tableName + "[" + index + "].sindicatorFollowType = " + (int)skillList[i].S_indicatorFollowType;
            //content += "\n" + tableName + "[" + index + "].sneedCheckCollider = " + skillList[i].S_needCheckCollider.ToString().ToLower();
            //content += "\n" + tableName + "[" + index + "].sneedExtendIndicator = " + skillList[i].S_needExtendIndicator.ToString().ToLower();
            //content += "\n" + tableName + "[" + index + "].sextendIndicatorA = " + skillList[i].S_extendIndicatorA.ToString();
            //content += "\n" + tableName + "[" + index + "].sextendIndicatorB = " + skillList[i].S_extendIndicatorB.ToString();
            //content += "\n" + tableName + "[" + index + "].sextendIndicatorRadius = " + skillList[i].S_extendIndicatorRadius.ToString();
            //content += "\n" + tableName + "[" + index + "].sextendIndicatorWidth = " + skillList[i].S_extendIndicatorWidth.ToString();
            content += "\n\n";
        }

        content += "\nreturn " + tableName;
        bool ret = FileWriterProxy.Write("Assets/Scripts/Slua/Resources/prometheus" + "/" + typeTitle + characterID + "SkillData.txt", content);
        //if (CharacterType == 0)
        //{
        //    for (int i = 0; i < skillCount; i++)
        //    {
        //        window.curGraph.AddSkillPhase(skillList[i].skillID, skillList[i].skillName, fDirs[idx]);
        //        Debug.Log("idx = " + idx + "skillID = " + skillList[i].skillID);
        //        skillID[i] = skillList[i].skillID;
        //        content += "\n" + "Hero" + heroID + "SkillData" + ".skillID0" + (i + 1) + " = " + skillID[i].ToString();
        //    }
        //    bool ret = FileWriterProxy.Write("Assets/Scripts/Slua/Resources/prometheus" + "/" + "Hero" + heroID + "SkillData.txt", content);
        //}
        //else if (CharacterType == 1)
        //{
        //    for (int i = 0; i < skillCount; i++)
        //    {
        //        window.curGraph.AddSkillPhase(skillList[i].skillID, skillList[i].skillName, fEnemyDirs[idx]);
        //        Debug.Log("idx = " + idx + "skillID = " + skillList[i].skillID);
        //        skillID[i] = skillList[i].skillID;
        //        content += "\n" + "Hero" + heroID + "SkillData" + ".skillID0" + (i + 1) + " = " + skillID[i].ToString();
        //    }
        //    bool ret = FileWriterProxy.Write("Assets/Scripts/Slua/Resources/prometheus" + "/" + "Npc" + heroID + "SkillData.txt", content);
        //}

        if (reInitGraph)
	    {
            //当有技能复制操作的时候，命令Graph重新初始化，加载刚复制的新技能
	        reInitGraph = false;
            window.curGraph.Init();
	    }

		GetWindow<Prometheus>().Show();
        EditorUtility.SetDirty(window.curGraph);
        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();
	}

	private class HeroSkillIDs
	{
		public HeroSkillIDs()
		{
		}

		public int heroID;
		public int[] skillID;
	}

	private void ExportToCsv()
	{
		var window = GetWindow<Prometheus>();
		PrometheusUtil.curCharacter = cha;
        PrometheusUtil.modelName = modelNameIndex;

		//TODO 导出英雄技能ID表
		string filename = EditorUtility.SaveFilePanel("Save file", "Assets/", "", "csv");
		if (string.IsNullOrEmpty(filename))
			return;
		//StreamWriter writer = new StreamWriter(filename.Replace(".level", ".csv"), false, Encoding.UTF8);
		StreamWriter writer = new StreamWriter(filename, false, Encoding.UTF8);

		StringBuilder builder = new StringBuilder(2048);
		int heroID = 100101 + idx;
		int[] skillID = new int[3];

		for (int i = 0; i < skillList.Count; i++) {
			if (skillList[i].skillID > 0) {
                window.curGraph.AddSkillPhase(fDirs[idx], skillList[i]);
				Debug.Log("idx = " + idx + "skillID = " + skillList[i].skillID);
				skillID[i] = skillList[i].skillID;
			}
		}

		HeroSkillIDs heroSkillIDs = new HeroSkillIDs();
		heroSkillIDs.heroID = heroID;
		heroSkillIDs.skillID = skillID;

		if (heroSkillIDCache.ContainsKey(heroID)) {
			heroSkillIDCache.Remove(heroID);
		}
		heroSkillIDCache.Add(heroID, heroSkillIDs);

		writer.WriteLine("HeroID,SkillID01,SkillID02,SkillID03");
		writer.WriteLine("英雄编号,技能1,技能2,技能3");
		writer.WriteLine("Index,int32,int32,int32");

		foreach (var item in heroSkillIDCache.Values) {
			builder.Remove(0, builder.Length);
			builder.AppendFormat("{0},{1},{2},{3}", item.heroID, item.skillID[0], item.skillID[1], item.skillID[2]);
			writer.WriteLine(builder);
		}

		writer.Close();
		GetWindow<Prometheus>().Show();

		return;
	}

	private void ResetButton()
	{
		if (GUILayout.Button("Reset")) {
			if(EditorUtility.DisplayDialog("DeleteCharacterSkills", "Confirm to Delete!", "Ok", "Cacel"))
			{
				// clear model
				ClearModel();
				ClearFX();
				AnimationMode.StopAnimationMode();
				AssetDatabase.DeleteAsset(PrometheusUtil.GraphPath + modelName + ".asset");
			}
		}

		return;
	}

	private void ClearModel()
	{
		DestroyImmediate(cha);
		loadFlag = false;

		return;
	}

	private void ClearFX()
	{
		return;
	}

    private void ClearNameDictCache()
    {
        heroNameDict = null;
        npcNameDict = null;
        return;
    }

	#endregion private imp

	#region public interface
	public static void Open(string title)
	{
		var window = GetWindow<PTCharacterWindow>(typeof(Prometheus));
		window.titleContent = new GUIContent(title);
		window.Show();
		return;
	}

    private void ReadFile(string str)
    {
        string temp = "_";
        string modelID =  str.Replace(temp, "");
        string filename = PTGraph.EXPORT_LUA_PATH + "/" + modelID + "SkillData.txt";
        TextAsset asset = AssetDatabase.LoadAssetAtPath<TextAsset>(filename);
        if (asset == null)
            return;

        LuaState s = new LuaState();

        object table;
        if (LuaUtil.LoadLua(s.L, asset.bytes, filename, out table)) {
            if (table != null) {
                skillList.Clear();
                foreach (var item in (table as LuaTable)) {
                    if (item.key.Equals("HeroID"))
                        continue;

                    // 历史遗留问题，原来的导出文件记下了这个键
					if (item.key.Equals("RunPlaySpeed"))
						continue;

					LuaTable curSkill = item.value as LuaTable;
                    PTOneSkill oneskill = new PTOneSkill();
                    oneskill.DataSetting = new SkilldataSetting();
                    oneskill.DataSetting.skillID = Convert.ToInt32(curSkill["skillID"]);
                    oneskill.DataSetting.skillName = Convert.ToString(curSkill["skillName"]);
                    oneskill.DataSetting.castType = (ReleaseMode)Convert.ToInt32(curSkill["castType"]);
                    oneskill.DataSetting.rangeEffectID = Convert.ToInt32(curSkill["releaseEffectID"]);
                    oneskill.DataSetting.rangeRadius = Convert.ToSingle(curSkill["rangeRadius"]);
                    oneskill.DataSetting.indicatorEffectID = Convert.ToInt32(curSkill["indicatorEffectID"]);
                    oneskill.DataSetting.indicatorType = (PTIndicatorType)Convert.ToInt32(curSkill["indicatorType"]);
                    //oneskill.DataSetting.secondTrigger = (SecondTrigger)Convert.ToInt32(curSkill["secondTrigger"]);
                    //oneskill.DataSetting.secondEvent = (SecondEvent)Convert.ToInt32(curSkill["secondEvent"]);
                    oneskill.DataSetting.indicatorRadius = Convert.ToSingle(curSkill["indicatorRadius"]);
                    oneskill.DataSetting.indicatorAngle = Convert.ToSingle(curSkill["indicatorAngle"]);
                    oneskill.DataSetting.indicatorLength = Convert.ToSingle(curSkill["indicatorLength"]);
                    oneskill.DataSetting.indicatorWidth = Convert.ToInt32(curSkill["indicatorWidth"]);
                    oneskill.DataSetting.indicatorFollowType = (ReleaseType)Convert.ToInt32(curSkill["indicatorFollowType"]);
                    oneskill.DataSetting.touchDelay = Convert.ToBoolean(curSkill["touchDelay"]);
                    oneskill.DataSetting.touchDelayTime = Convert.ToSingle(curSkill["touchDelayTime"]);
                    oneskill.DataSetting.needCheckCollider = Convert.ToBoolean(curSkill["needCheckCollider"]);
                    oneskill.DataSetting.needExtendIndicator = Convert.ToBoolean(curSkill["needExtendIndicator"]);
                    oneskill.DataSetting.extendIndicatorA = Convert.ToInt32(curSkill["extendIndicatorA"]);
                    oneskill.DataSetting.extendIndicatorB = Convert.ToInt32(curSkill["extendIndicatorB"]);
                    oneskill.DataSetting.extendIndicatorRadius = Convert.ToSingle(curSkill["extendIndicatorRadius"]);
                    oneskill.DataSetting.extendIndicatorWidth = Convert.ToSingle(curSkill["extendIndicatorWidth"]);
                    oneskill.DataSetting.isSecondPhase = Convert.ToBoolean(curSkill["hasSecondPhase"]);
                    //oneskill.DataSetting.cdType = Convert.ToInt32(curSkill["cdType"]);
                    //oneskill.DataSetting.cdValue = Convert.ToSingle(curSkill["cdValue"]);

                    oneskill.DataSetting.S_rangeEffectID = Convert.ToInt32(curSkill["sreleaseEffectID"]);
                    oneskill.DataSetting.S_rangeRadius = Convert.ToSingle(curSkill["srangeRadius"]);
                    oneskill.DataSetting.S_indicatorEffectID = Convert.ToInt32(curSkill["sindicatorEffectID"]);
                    oneskill.DataSetting.S_indicatorType = (PTIndicatorType)Convert.ToInt32(curSkill["sindicatorType"]);
                    oneskill.DataSetting.S_indicatorRadius = Convert.ToSingle(curSkill["sindicatorRadius"]);
                    oneskill.DataSetting.S_indicatorAngle = Convert.ToSingle(curSkill["sindicatorAngle"]);
                    oneskill.DataSetting.S_indicatorLength = Convert.ToSingle(curSkill["sindicatorLength"]);
                    oneskill.DataSetting.S_indicatorWidth = Convert.ToInt32(curSkill["sindicatorWidth"]);
                    oneskill.DataSetting.S_indicatorFollowType = (ReleaseType)Convert.ToInt32(curSkill["sindicatorFollowType"]);
                    oneskill.DataSetting.S_needCheckCollider = Convert.ToBoolean(curSkill["sneedCheckCollider"]);
                    oneskill.DataSetting.S_needExtendIndicator = Convert.ToBoolean(curSkill["sneedExtendIndicator"]);
                    oneskill.DataSetting.S_extendIndicatorA = Convert.ToInt32(curSkill["sextendIndicatorA"]);
                    oneskill.DataSetting.S_extendIndicatorB = Convert.ToInt32(curSkill["sextendIndicatorB"]);
                    oneskill.DataSetting.S_extendIndicatorRadius = Convert.ToSingle(curSkill["sextendIndicatorRadius"]);
                    oneskill.DataSetting.S_extendIndicatorWidth = Convert.ToSingle(curSkill["sextendIndicatorWidth"]);

                    Debug.Log("oneskill.DataSetting.skillName = " + oneskill.DataSetting.skillName);
                    skillList.Add(oneskill.DataSetting);
                }
            }
        }
        s.Dispose();
    }

	#endregion public interface
    }
