using System.Collections.Generic;
using System.Linq;
using ParadoxNotion;
using NodeCanvas.Framework.Internal;
using UnityEngine;

#if UNITY_EDITOR
using UnityEditor;
#endif


namespace NodeCanvas.Framework{

    /// A component that is used to control a Graph in respects to the gameobject attached to
	abstract public class GraphOwner : MonoBehaviour {

		[SerializeField] /*[HideInInspector]*/
		private string boundGraphSerialization;
		[SerializeField] /*[HideInInspector]*/
		private List<UnityEngine.Object> boundGraphObjectReferences;

		public enum EnableAction{
			EnableBehaviour,
            EnableDebugOnly,
            DoNothing
		}

		public enum DisableAction{
			DisableBehaviour,
			PauseBehaviour,
            DisableDebugOnly,
            DoNothing
		}

		[HideInInspector] ///What will happen OnEnable
		public EnableAction enableAction = EnableAction.EnableBehaviour;
		[HideInInspector] ///What will happen OnDisable
		public DisableAction disableAction = DisableAction.DisableBehaviour;

		private Dictionary<Graph, Graph> instances = new Dictionary<Graph, Graph>();
		private bool startCalled = false;
        private bool remoteDebug = false;

        private static bool isQuiting;
        
        abstract public Graph graph{get;set;}
		abstract public IBlackboard blackboard{get;set;}
		abstract public System.Type graphType{get;}

		///Is the assigned graph currently running?
		public bool isRunning{
			get {return graph != null? graph.isRunning : false;}
		}

		///Is the assigned graph currently paused?
		public bool isPaused{
			get {return graph != null? graph.isPaused : false;}
		}

		///The time is seconds the graph is running
		public float elapsedTime{
			get {return graph != null? graph.elapsedTime : 0;}
        }

        public bool isRemoteDebug
        {
            get
            {
                return remoteDebug;
            }
        }

        //Gets the instance graph for this owner of the provided graph
        protected Graph GetInstance(Graph originalGraph){

			if (originalGraph == null){
				return null;
			}

			//in editor the instance is always the original
			#if UNITY_EDITOR
			if (!Application.isPlaying){
				return originalGraph;
			}
			#endif

			//if its already an instance, return the instance
			if (instances.Values.Contains(originalGraph)){
				return originalGraph;
			}

			Graph instance = null;

			//if it's not an instance but rather an asset reference which has been instantiated before, return the instance stored,
			//otherwise create and store a new instance.
			if (!instances.TryGetValue(originalGraph, out instance)){
//				instance = Graph.Clone<Graph>(originalGraph);
				instances[originalGraph] = instance = originalGraph;
			}

			instance.agent = this;
			instance.blackboard = this.blackboard;
			return instance;
		}


		///Start the graph assigned
		public void StartBehaviour(){
            Utilities.BeginProfileLabel("AISystem_BT_Init");
            graph = GetInstance(graph);
			if (graph != null){
				graph.StartGraph(this, blackboard, true);
			}
            Utilities.EndProfileLabel();
        }

		///Start the graph assigned providing a callback for when it's finished if at all
		public void StartBehaviour(System.Action<bool> callback){
			graph = GetInstance(graph);
			if (graph != null){
				graph.StartGraph(this, blackboard, true, callback);
			}
        }
        ///Enable debugging graph
        public void EnableDebug()
        {
#if UNITY_EDITOR
            remoteDebug = true;
            StartDebug();
#endif //UNITY_EDITOR
        }
        ///Disable debugging graph
        public void DisableDebug()
        {
#if UNITY_EDITOR
            StopDebug();
            remoteDebug = false;
#endif //UNITY_EDITOR
        }

        ///Pause the current running graph
        public void PauseBehaviour(){
			if (graph != null){
				graph.Pause();
			}
		}

		///Stop the current running graph
		public void StopBehaviour(){
			if (graph != null){
				graph.Stop();
			}
		}

		///Manually update the assigned graph
		public void UpdateBehaviour(){
			if (graph != null){
				graph.UpdateGraph();
			}
		}


		///Send an event through the graph (To be used with CheckEvent for example). Same as .graph.SendEvent
		public void SendEvent(string eventName){ SendEvent(new EventData(eventName));}
		public void SendEvent<T>(string eventName, T eventValue) {SendEvent(new EventData<T>(eventName, eventValue)); }
		public void SendEvent(EventData eventData){
			if (graph != null){
				graph.SendEvent(eventData);
			}
		}

		///Thats the same as calling the static Graph.SendGlobalEvent
		public static void SendGlobalEvent(string eventName){
			Graph.SendGlobalEvent( new EventData(eventName) );
		}
		///Thats the same as calling the static Graph.SendGlobalEvent
		public static void SendGlobalEvent<T>(string eventName, T eventValue){
			Graph.SendGlobalEvent( new EventData<T>(eventName, eventValue) );
		}


		
		//just set the quit flag
		protected void OnApplicationQuit(){
			isQuiting = true;
		}

		//instantiate and deserialize the bound graph, or instantiate the asset graph reference
		protected void Awake(){

			if (graph == null){
				return;
			}

			#if UNITY_EDITOR
			if ( !hasUpdated2_6_2 ){
				Debug.LogWarning(string.Format("GraphOwner '{0}' is being used in runtime but has not been updated to version 2.6.2+ !", name), gameObject);
				enabled = false;
				return;
			}
			#endif


			//The graph is bound
			if (!string.IsNullOrEmpty(boundGraphSerialization)){

				//Case1: The graph is a bound instance in the scene.
				//Use it directly.
				if (graph.hideFlags == HideFlags.HideInInspector){
					instances[graph] = graph;
					return;
				}

				//Case2: The graph is a bound asset reference. This takes place when instantiating prefabs.
				//Set object references before GetInstance, so that graph deserialize with correct references.
				graph.SetSerializationObjectReferences(boundGraphObjectReferences);
				graph = GetInstance(graph);
				return;
			}

			//Case3: The graph is just a non-bound asset reference.
			//Instantiate and use it.
			graph = GetInstance(graph);
		}

		//mark as startCalled and handle enable behaviour setting
		protected void Start(){
			startCalled = true;
			switch (enableAction)
            {
                case EnableAction.EnableBehaviour:
                    StartBehaviour();
                    break;
                case EnableAction.EnableDebugOnly:
                    EnableDebug();
                    break;
			}
		}

		//handle enable behaviour setting
		protected void OnEnable(){
			if (startCalled)
            {
                switch (enableAction)
                {
                    case EnableAction.EnableBehaviour:
                        StartBehaviour();
                        break;
                    case EnableAction.EnableDebugOnly:
                        EnableDebug();
                        break;
                }
            }
		}

		//handle disable behaviour setting
		protected void OnDisable(){

			if (isQuiting){
				return;
			}

            switch (disableAction)
            {
                case DisableAction.DisableBehaviour:
                    StopBehaviour();
                    break;
                case DisableAction.PauseBehaviour:
                    PauseBehaviour();
                    break;
                case DisableAction.DisableDebugOnly:
                    DisableDebug();
                    break;
            }
		}

		//Destroy instanced graphs as well
		protected void OnDestroy(){

			if (isQuiting){
				return;
			}
            instances.Clear();
            graph = null;
            /*			StopBehaviour();
             			
                        foreach (var graph in instances.Values){
                                        foreach(var subGraph in graph.GetAllInstancedNestedGraphs()){
                                            Destroy(subGraph);
                                        }
                                        Destroy(graph);
                        }
                        */
        }





        ////////////////////////////////////////
        ///////////GUI AND EDITOR STUFF/////////
        ////////////////////////////////////////
#if UNITY_EDITOR

        [SerializeField]
		private VersionUpdateProxyGraph versionUpdateProxyGraph;
		private Graph boundGraphInstance;

		///Editor. Has owner been version updated?
		public bool hasUpdated2_6_2{
			get	{ return versionUpdateProxyGraph == null && GetComponents(typeof(IScriptableComponent)).Cast<Graph>().Contains(this.graph) == false; }
		}

		///Editor. Is the graph a bound one?
		public bool graphIsBound{
			get
			{
				if (graph != null){
					var prefabType = PrefabUtility.GetPrefabType(this);
					if (prefabType == PrefabType.Prefab){
						return AssetDatabase.IsSubAsset(graph) && AssetDatabase.GetAssetPath(graph) == AssetDatabase.GetAssetPath(this);
					}

					if (prefabType == PrefabType.PrefabInstance){
						var parent = (GraphOwner)PrefabUtility.GetPrefabParent(this);
						return graph.hideFlags == HideFlags.HideInInspector || (AssetDatabase.IsSubAsset(graph) && AssetDatabase.GetAssetPath(graph) == AssetDatabase.GetAssetPath(parent));
					}

					return graph.hideFlags == HideFlags.HideInInspector;
				}

				return !string.IsNullOrEmpty(boundGraphSerialization);
			}
		}

        //Called in editor only after assigned graph is serialized.
        //If the graph is bound, we store the serialization data here.
        public void OnGraphSerialized(Graph serializedGraph){
			if (graphIsBound && graph == serializedGraph){
				graph.GetSerializationData(out boundGraphSerialization, out boundGraphObjectReferences);
				EditorUtility.SetDirty(this);
			}
		}

		///Called from the editor.
		protected void OnValidate(){ Validate(); }
		public void Validate(){

			if (Application.isPlaying || EditorApplication.isPlayingOrWillChangePlaymode){
				return;
			}

			//check if has updated before everything else!
			if (!hasUpdated2_6_2){
				if (graph != null) graph.hideFlags = HideFlags.HideInInspector;
				return;
			}

			//everything bellow is relevant to bound graphs only
			if (!graphIsBound){
				return;
			}

			var prefabType = PrefabUtility.GetPrefabType(this);
			if (boundGraphInstance == null){

				if (prefabType == PrefabType.Prefab){

					if (graph == null){
						graph = (Graph)ScriptableObject.CreateInstance(graphType);
						AssetDatabase.AddObjectToAsset(graph, this);
						EditorApplication.delayCall += ()=>{ AssetDatabase.ImportAsset(AssetDatabase.GetAssetPath(graph)); };
					}

					boundGraphInstance = graph;

				} else {

					boundGraphInstance = (Graph)ScriptableObject.CreateInstance(graphType);
				}
			}

			boundGraphInstance.Deserialize(boundGraphSerialization, false, boundGraphObjectReferences);

			boundGraphInstance.hideFlags = prefabType == PrefabType.Prefab? HideFlags.None : HideFlags.HideInInspector;
			(boundGraphInstance as UnityEngine.Object).name = this.name + (AssetDatabase.IsSubAsset(boundGraphInstance)? "(SubAsset)" : "");
			boundGraphInstance.Validate();
			graph = boundGraphInstance;

			boundGraphSerialization = graph.Serialize(false, boundGraphObjectReferences);

			graph.agent = this;
			graph.blackboard = this.blackboard;
		}

		///Editor. Handles updating bound graphs from previous versions.
		public void TryUpdateBoundGraphPriorToVersion2_6_2(){

			if (hasUpdated2_6_2){
				return;
			}

			var scriptableComponents = GetComponents(typeof(IScriptableComponent)).Where(s => s != null && s.GetType() == graphType).Cast<Graph>();
			var prefabType = PrefabUtility.GetPrefabType(this);
			var thisTypeName = this.GetType().Name;

			if (prefabType == PrefabType.Prefab){
				//Replace monoscript reference thus keeping object reference the same as far as prefab system works.
				//VersionUpdateProxyGraph uses exactly the same field names, so Unity will still deserialize values but in the new script.
				foreach(var scriptable in scriptableComponents){
					if (scriptable == this.graph){
						scriptable.Serialize();
						scriptable.GetSerializationData(out boundGraphSerialization, out boundGraphObjectReferences);
						var monoscriptGUID = AssetDatabase.FindAssets("VersionUpdateProxyGraph")[0];
						var monoScript = (MonoScript)AssetDatabase.LoadAssetAtPath(AssetDatabase.GUIDToAssetPath(monoscriptGUID), typeof(MonoScript));
						var id = scriptable.GetInstanceID();
						var serObject = new SerializedObject(scriptable);
						var scriptProp = serObject.FindProperty("m_Script");
						scriptProp.objectReferenceValue = monoScript;
						serObject.ApplyModifiedProperties();
						serObject.UpdateIfRequiredOrScript();
						versionUpdateProxyGraph = (VersionUpdateProxyGraph)EditorUtility.InstanceIDToObject(id);
						versionUpdateProxyGraph.hideFlags = HideFlags.NotEditable;

						boundGraphInstance = null;
						graph = null;

						Debug.Log(string.Format("{0} '{1}' ({2}), Updated.", thisTypeName, name, prefabType), this);
						EditorUtility.SetDirty(this);

						break;
					}
				}
			}

			if (prefabType == PrefabType.PrefabInstance){
				if (versionUpdateProxyGraph != null){
					versionUpdateProxyGraph.GetSerializationData(out boundGraphSerialization, out boundGraphObjectReferences);

					Debug.Log(string.Format("{0} '{1}' (Linked {2}), Updated.", thisTypeName, name, prefabType), this);
					boundGraphInstance = null;
					graph = null;

					DestroyImmediate(versionUpdateProxyGraph, true);
					EditorUtility.SetDirty(this);
				}

				//This can happen if the graphowner (and it's bound graph) is not part of the prefab asset.
				foreach(var scriptable in scriptableComponents){
					if (scriptable == this.graph){
						scriptable.Serialize();
						scriptable.GetSerializationData(out boundGraphSerialization, out boundGraphObjectReferences);

						Debug.Log(string.Format("{0} '{1}' ({2}), Updated.", thisTypeName, name, prefabType), this);
						boundGraphInstance = null;
						graph = null;

						DestroyImmediate(scriptable, true);
						EditorUtility.SetDirty(this);
					}
					break;
				}
			}

			//All other PrefabType cases.
			if (prefabType != PrefabType.Prefab && prefabType != PrefabType.PrefabInstance){
				foreach(var scriptable in scriptableComponents){
					if (scriptable == this.graph){
						scriptable.Serialize();
						scriptable.GetSerializationData(out boundGraphSerialization, out boundGraphObjectReferences);

						Debug.Log(string.Format("{0} '{1}', Updated.", thisTypeName, name), this);
						boundGraphInstance = null;
						graph = null;

						DestroyImmediate(scriptable, true);
						EditorUtility.SetDirty(this);
					}
					break;
				}
			}
		}
		//////
		//////


		///Editor. Binds the target graph (null to unbind current).
		public void SetBoundGraphReference(Graph target){

			if (Application.isPlaying || EditorApplication.isPlayingOrWillChangePlaymode){
				return;
			}

			graph = null;
			boundGraphInstance = null;
			if (target == null){
				boundGraphSerialization = null;
				boundGraphObjectReferences = null;
				return;
			}
			target.Serialize();
			target.GetSerializationData(out boundGraphSerialization, out boundGraphObjectReferences);
			Validate(); //validate to handle bound graph instance
		}

		protected void Reset(){
			blackboard = gameObject.GetComponent<Blackboard>();
			if (blackboard == null){
				blackboard = gameObject.AddComponent<Blackboard>();		
			}
		}

		//forward the call
		protected void OnDrawGizmos(){
			Gizmos.DrawIcon(transform.position, "GraphOwnerGizmo.png", true);
			DoGizmos(graph);
		}

		void DoGizmos(Graph targetGraph){
			if (targetGraph != null){
				for (var i = 0; i < targetGraph.allNodes.Count; i++){
					var node = targetGraph.allNodes[i];
					node.OnDrawGizmos();
					if (Graph.currentSelection == node){
						node.OnDrawGizmosSelected();
					}
					var graphAssignable = node as IGraphAssignable;
					if (graphAssignable != null && graphAssignable.nestedGraph != null){
						DoGizmos(graphAssignable.nestedGraph);
					}
				}
			}			
		}

        ///start debugging this graph instance
        public void StartDebug()
        {
            if (isRemoteDebug)
            {
                ParadoxNotion.Services.MonoManager.current.debugingGraphOwner = this;
                SceneObj sceneObj = gameObject.GetComponent<SceneObj>();
                if (sceneObj != null)
                {
                    pvp.CSAIDebugReq req = ProtocolHandler.CreatePackage<pvp.CSAIDebugReq>();
                    req.id = sceneObj.id;

                    ProtocolHandler.SendToGameServer(req);
                }
            }
            else
            {
                StartBehaviour();
            }
        }

        ///Pause the current running graph
        ///暂时没有很大的需求，先没实现
        public void PauseDebug()
        {
            if (isRemoteDebug)
            {
                //OnSetBreakPoint(0, true);
            }
            else
            {
                PauseBehaviour();
            }
        }

        ///Stop the current running graph
        public void StopDebug()
        {
            if (isRemoteDebug)
            {
                pvp.CSAIDebugReq req = ProtocolHandler.CreatePackage<pvp.CSAIDebugReq>();
                req.id = 0;
                ProtocolHandler.SendToGameServer(req);
            }
            else
            {
                StopBehaviour();
            }
        }

        public void OnSetBreakPoint(int nodeId, bool bBreakPoint)
        {
            pvp.CSAIBreakPointReq req = ProtocolHandler.CreatePackage<pvp.CSAIBreakPointReq>();
            req.break_id = nodeId;
            req.break_type = bBreakPoint ? 1 : 2;
            ProtocolHandler.SendToGameServer(req);
        }
        public void OnSetBBVar(string varName, object bbValue)
        {
            pvp.CSAIResetNodeValReq req = ProtocolHandler.CreatePackage <pvp.CSAIResetNodeValReq>();
            req.val.Clear();
            pvp.AINodeVal bbVar = new pvp.AINodeVal();
            bbVar.key = varName;
            System.Type varType = bbValue.GetType();
            if(varType == typeof(float) || varType == typeof(double))
            {
                bbVar.float_val = (float)(bbValue);
            }
            else if(varType == typeof(int))
            {
                bbVar.int_val = (int)(bbValue);
            }
            else if (varType == typeof(ulong))
            {
                bbVar.uint64_val = (ulong)(bbValue);
            }
            else if (varType == typeof(string))
            {
                bbVar.str_val = bbValue.ToString();
            }

            req.val.Add(bbVar);
            ProtocolHandler.SendToGameServer(req);
        }
        public void OnSvrBBVar(string valName, object valValue)
        {
            Variable variable = blackboard.GetVariable(valName);
            if (variable != null)
            {
                bool needSceneObj = (variable.varType == typeof(SceneObj) || variable.varType.IsSubclassOf(typeof(SceneObj)));
                bool needGameObj = (!needSceneObj && (variable.varType == typeof(GameObject) || variable.varType.IsSubclassOf(typeof(GameObject))));
                if (needSceneObj || needGameObj)
                {
                    if(valValue.GetType() == typeof(ulong))
                    {
                        GameObject go = PlatoUtil.GetActorByID((ulong)valValue);
                        if(go != null)
                        {
                            if(needGameObj)
                            {
                                blackboard.SetValue(valName, go);
                            }
                            else if(needSceneObj)
                            {
                                blackboard.SetValue(valName, go.GetComponent<SceneObj>());
                            }
                        }
                    }
                }
                else
                {
                    blackboard.SetValue(valName, valValue);
                }
            }
        }
        public void OnSvrNodeStateChange(int nodeId, Status status)
        {
            
            Node nodeToSet = graph.FindNodeById(nodeId);
            if (nodeToSet != null)
            {
                if(nodeToSet == graph.primeNode)
                {
                    foreach(Node node in graph.allNodes)
                    {
                        node.DebugStatusChange(Status.Resting);
                    }
                }
                nodeToSet.DebugStatusChange(status);
            }
        }
#endif
    }






	///The class where GraphOwners derive from
	abstract public class GraphOwner<T> : GraphOwner where T:Graph{

		[SerializeField] /*[HideInInspector]*/
		private T _graph;
		[SerializeField] /*[HideInInspector]*/
		private Blackboard _blackboard;

		///The current behaviour Graph assigned
		sealed public override Graph graph{
			get {return _graph; }
			set {_graph = (T)value;}
		}

		///The current behaviour Graph assigned (same as .graph but of type T)
		public T behaviour{
			get { return _graph; }
			set { _graph = value; }
		}

		///The blackboard that the assigned behaviour will be Started with or currently using
		sealed public override IBlackboard blackboard{
			get
			{
				if (graph != null && graph.useLocalBlackboard){
					return graph.localBlackboard;
				}

				if (_blackboard == null){
					_blackboard = GetComponent<Blackboard>();
				}

				return _blackboard;
			}
			set
			{
				if ( !ReferenceEquals(_blackboard, value) ){
					_blackboard = (Blackboard)(object)value;
					if (graph != null && !graph.useLocalBlackboard){
						graph.blackboard = value;
					}
				}
			}
		}

		///The Graph type this Owner can be assigned
		sealed public override System.Type graphType{ get {return typeof(T);} }

		///Start a new behaviour on this owner
		public void StartBehaviour(T newGraph){
			SwitchBehaviour(newGraph);
		}

		///Start a new behaviour on this owner and get a call back for when it's finished if at all
		public void StartBehaviour(T newGraph, System.Action<bool> callback){
			SwitchBehaviour(newGraph, callback);
		}

		///Use to switch the behaviour dynamicaly at runtime
		public void SwitchBehaviour(T newGraph){
			SwitchBehaviour(newGraph, null);
		}

		///Use to switch or set graphs at runtime and optionaly get a callback when it's finished if at all
		public void SwitchBehaviour(T newGraph, System.Action<bool> callback){
			StopBehaviour();
			graph = newGraph;
			StartBehaviour(callback);
		}
	}
}