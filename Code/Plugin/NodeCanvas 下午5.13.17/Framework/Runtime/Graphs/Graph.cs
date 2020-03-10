using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using NodeCanvas.Framework.Internal;
using ParadoxNotion;
using ParadoxNotion.Serialization;
using ParadoxNotion.Services;
using UnityEngine;

using ParadoxNotion.Serialization.FullSerializer;


namespace NodeCanvas.Framework{

	///This is the base and main class of NodeCanvas and graphs. All graph System are deriving from this.
	[System.Serializable]
	abstract public partial class Graph : ScriptableObject, ITaskSystem, ISerializationCallbackReceiver, IScriptableComponent {

		[SerializeField]
		private string _serializedGraph;
		[SerializeField]
		private List<Object> _objectReferences;
		[SerializeField]
		private bool _deserializationFailed = false;

		[System.NonSerialized]
		private bool hasEnabled = false;
		[System.NonSerialized]
		private bool hasDeserialized = false;


		//These are the data that are serialized and deserialized into/from a 'GraphSerializationData' object
		/////////////////////////////////////////////////////////////////////////////////////////////////////
		private string _name                      = string.Empty;
		private string _comments                  = string.Empty;
		private Vector2 _translation              = new Vector2(-5000, -5000);
		private float _zoomFactor                 = 1f;
		private List<Node> _nodes                 = new List<Node>();
		private Node _primeNode                   = null;
		private List<CanvasGroup> _canvasGroups   = null;
		private BlackboardSource _localBlackboard = null;
		/////////////////////////////////////////////////////////////////////////////////////////////////////


		///////////UNITY CALLBACKS///////////
		void ISerializationCallbackReceiver.OnBeforeSerialize(){ Serialize(); }
		void ISerializationCallbackReceiver.OnAfterDeserialize(){ Deserialize(); }


		///Serialize the Graph
		public void Serialize(){
			if (_objectReferences != null && _objectReferences.Count > 0 && _objectReferences.Any(o => o != null)){ //Unity requires double deserialize for UnityObject refs.
				hasDeserialized = false;
			}
			
			#if UNITY_EDITOR //we only serialize in the editor
			if (JSONSerializer.applicationPlaying){
				return;
			}
			
			_serializedGraph = this.Serialize(false, _objectReferences);

			//notify owner. This is used for bound graphs
			var owner = agent != null && agent is GraphOwner? (GraphOwner)agent : null;
			if (owner != null){
				owner.OnGraphSerialized(this);
			}
			#endif
		}

		///Deserialize the Graph
		public void Deserialize(){
			if (hasDeserialized && JSONSerializer.applicationPlaying){ //avoid double call if not needed (UnityObject refs).
				return;
			}
			hasDeserialized = true;
			this.Deserialize(_serializedGraph, false, _objectReferences);
		}


#if UNITY_EDITOR
		protected void OnValidate(){
			if (!Application.isPlaying && !UnityEditor.EditorApplication.isPlayingOrWillChangePlaymode){
				Validate();
			}
		}
#endif

		protected void OnEnable(){
			//Validate automaticaly though OnEnable, only the first time the graph is enabled.
			if (!hasEnabled){
				hasEnabled = true;
				Validate();
			}
		}
		protected void OnDisable(){}
		protected void OnDestroy(){}
		//////////////////////////////////////
		//////////////////////////////////////

		///Serialize the graph and returns the serialized json string
		public string Serialize(bool pretyJson, List<UnityEngine.Object> objectReferences){
			//if something went wrong on deserialization, dont serialize back, but rather keep what we had
			if (_deserializationFailed){
				_deserializationFailed = false;
				return _serializedGraph;
			}
			
			//the list to save the references in. If not provided externaly we save into the local list
			if (objectReferences == null){
				objectReferences = this._objectReferences = new List<Object>();
			}

			UpdateNodeIDs(true);
			return JSONSerializer.Serialize(typeof(GraphSerializationData), new GraphSerializationData(this), pretyJson, objectReferences);
		}

		///Deserialize the json serialized graph provided. Returns the structure or null if failed.
		public GraphSerializationData Deserialize(string serializedGraph, bool validate, List<UnityEngine.Object> objectReferences){
			if (string.IsNullOrEmpty(serializedGraph)){
				return null;
			}

			//the list to load the references from. If not provided externaly we load from the local list (which is the case most times)
			if (objectReferences == null){
				objectReferences = this._objectReferences;
			}

			try
			{
				//deserialize provided serialized graph into a new GraphSerializationData object and load it
				var data = JSONSerializer.Deserialize<GraphSerializationData>(serializedGraph, objectReferences);
				if (LoadGraphData(data, validate) == true){
					this._deserializationFailed = false;
					this._serializedGraph = serializedGraph;
					this._objectReferences = objectReferences;
					return data;
				}

				_deserializationFailed = true;
				return null;
			}
			catch (System.Exception e)
			{
				Debug.LogError(string.Format("<b>(Deserialization Error:)</b> {0}", e.ToString() ), this);
				_deserializationFailed = true;
				return null;
			}
		}

		//TODO: Move this in GraphSerializationData object Reconstruction?
		bool LoadGraphData(GraphSerializationData data, bool validate){

			if (data == null){
				Debug.LogError("Can't Load graph, cause of null GraphSerializationData provided");
				return false;
			}

			if (data.type != this.GetType()){
				Debug.LogError("Can't Load graph, cause of different Graph type serialized and required");
				return false;
			}

			data.Reconstruct(this);

			//grab the final data and set fields directly
			this._name            = data.name;
			this._comments        = data.comments;
			this._translation     = data.translation;
			this._zoomFactor      = data.zoomFactor;
			this._nodes           = data.nodes;
			this._primeNode       = data.primeNode;
			this._canvasGroups    = data.canvasGroups;
			this._localBlackboard = data.localBlackboard;

			//IMPORTANT: Validate should be called in all deserialize cases outside of Unity's 'OnAfterDeserialize',
			//like for example when loading from json, or manualy calling this outside of OnAfterDeserialize.
			if (validate){
				Validate();
			}

			return true;
		}

		///Graph can override this for derived data serialization if needed
		virtual public object OnDerivedDataSerialization(){return null;}
		///Graph can override this for derived data deserialization if needed
		virtual public void OnDerivedDataDeserialization(object data){}

		///Gets the json string along with the list of UnityObject references used for serialization by this graph.
		public void GetSerializationData(out string json, out List<UnityEngine.Object> references){
			json = _serializedGraph;
			references = _objectReferences != null? new List<UnityEngine.Object>(_objectReferences) : null;
		}

		///Sets the target list of UnityObject references. This is for internal use and highly not recomended to do.
		public void SetSerializationObjectReferences(List<UnityEngine.Object> references){
			this._objectReferences = references;
		}

		///Clones the graph and returns the new one. Currently exactly the same as Instantiate, but could change in the future
		public static T Clone<T>(T graph) where T:Graph{
			var newGraph = (T)Instantiate(graph);
			newGraph.name = newGraph.name.Replace("(Clone)", "");
			return (T)newGraph;
		}

		///Serialize the local blackboard of the graph alone
		public string SerializeLocalBlackboard(){
			return JSONSerializer.Serialize(typeof(BlackboardSource), _localBlackboard, false, _objectReferences);
		}

		///Deserialize the local blackboard of the graph alone
		public bool DeserializeLocalBlackboard(string json){
			try
			{
				_localBlackboard = JSONSerializer.Deserialize<BlackboardSource>(json, _objectReferences);
				if (_localBlackboard == null) _localBlackboard = new BlackboardSource();
				return true;
			}
			catch (System.Exception e)
			{
				Debug.LogError(string.Format("<b>(Deserialization Error:)</b> {0}", e.ToString()), this);
				return false;
			}
		}
		
		///Non-editor CopySerialized
		public void CopySerialized(Graph target){
			var json = this.Serialize(false, target._objectReferences);
			target.Deserialize( json, true, this._objectReferences );
		}

		///Validate the graph and it's nodes. Called both in editor OnValidate and in runtime OnEnable.
		public void Validate(){
			#if UNITY_EDITOR
			if (!Application.isPlaying && !UnityEditor.EditorApplication.isPlayingOrWillChangePlaymode){
				UpdateReferences();
			}
			#endif

			for (var i = 0; i < allNodes.Count; i++){
				try { allNodes[i].OnValidate(this); } //validation could be critical. we always continue
				catch (System.Exception e) { Debug.LogError(e.ToString()); continue; }
			}

			var allTasks = GetAllTasksOfType<Task>();
			for (var i = 0; i < allTasks.Count; i++){
				try { allTasks[i].OnValidate(this); } //validation could be critical. we always continue
				catch (System.Exception e) { Debug.LogError(e.ToString()); continue; }
			}
			
			OnGraphValidate();

			//in runtime and if graph uses local blackboard, initialize property/field binding.
			//'null' target gameObject (since localBlackboard can only have static bindings).
			//'false' so that setter is not called.
			if (Application.isPlaying && useLocalBlackboard){
				localBlackboard.InitializePropertiesBinding(null, false);
			}
		}

		///Use this for derived graph Validation
		virtual protected void OnGraphValidate(){}





		///Raised when the graph is Stoped/Finished if it was Started at all
		public event System.Action<bool> OnFinish;

		[System.NonSerialized]
		private Component _agent;
		[System.NonSerialized]
		private IBlackboard _blackboard;

		[System.NonSerialized]
		private static List<Graph> runningGraphs = new List<Graph>();
		[System.NonSerialized]
		private float timeStarted;
		[System.NonSerialized]
		private bool _isRunning;
		[System.NonSerialized]
		private bool _isPaused;
		/////


		///The base type of all nodes that can live in this system
		abstract public System.Type baseNodeType{get;}
		///Is this system allowed to start with a null agent?
		abstract public bool requiresAgent{get;}
		///Does the system needs a prime Node to be set for it to start?
		abstract public bool requiresPrimeNode{get;}
		///Should the the nodes be auto sorted on position x?
		abstract public bool autoSort{get;}
		///Force use the local blackboard vs propagated one?
		abstract public bool useLocalBlackboard{get;}

		///The friendly title name of the graph
		new public string name{
			get { return string.IsNullOrEmpty(_name)? GetType().Name : _name; }
			set { _name = value; }
		}

		///Graph Comments
		public string graphComments{
			get {return _comments;}
			set {_comments = value;}
		}
		
		///The time in seconds this graph is running
		public float elapsedTime{
			get {return isRunning || isPaused? Time.time - timeStarted : 0;}
		}

		///Is the graph running?
		public bool isRunning {
			get {return _isRunning;}
			private set {_isRunning = value;}
		}

		///Is the graph paused?
		public bool isPaused {
			get {return _isPaused;}
			private set {_isPaused = value;}
		}

		///All nodes assigned to this system
		public List<Node> allNodes{
			get {return _nodes;}
			private set {_nodes = value;}
		}

		///The node to execute first. aka 'START'
		public Node primeNode{
			get {return _primeNode;}
			set
			{
				if (_primeNode != value){

					if (value != null && value.allowAsPrime == false){
						return;
					}
					
					if (isRunning){
						if (_primeNode != null)	_primeNode.Reset();
						if (value != null) value.Reset();
					}

					RecordUndo("Set Start");
					
					_primeNode = value;
					UpdateNodeIDs(true);
				}
			}
		}

		///The canvas groups of the graph
		public List<CanvasGroup> canvasGroups{
			get {return _canvasGroups;}
			set {_canvasGroups = value;}
		}

		///The translation of the graph in the total canvas (Editor purposes)
		public Vector2 translation{
			get {return _translation;}
			set {_translation = value;}
		}

		///The zoom of the graph (Editor purposes)
		public float zoomFactor{
			get {return _zoomFactor;}
			set {_zoomFactor = value;}
		}

		///The agent currently assigned to the graph
		public Component agent{
			get {return _agent;}
			set {_agent = value;}
		}

		///The blackboard currently assigned to the graph
		public IBlackboard blackboard{
			get
			{
				if (useLocalBlackboard){ return localBlackboard; }
				#if UNITY_EDITOR
				if (_blackboard == null || _blackboard.Equals(null)){ //done for when user removes bb component in editor.
					return null;
				}
				#endif

				return _blackboard;
			}
			set
			{
				if (_blackboard != value){
					if (isRunning){ return; }
					if (useLocalBlackboard){ return; }
					_blackboard = value;
				}
			}
		}

		///The local blackboard of the graph
		public BlackboardSource localBlackboard{
			get
			{
				if (ReferenceEquals(_localBlackboard, null)){
					_localBlackboard = new BlackboardSource();
					_localBlackboard.name = "Local Blackboard";
				}
				return _localBlackboard;
			}
		}

		///The UnityObject of the ITaskSystem. In this case the graph itself
		Object ITaskSystem.contextObject{
			get {return this;}
		}



		///Copy all nodes provided within the target graph. Connections will duplicate only if target nodes of the connections are contained in the provided list
		public static List<Node> CopyNodesToGraph(List<Node> nodes, Graph targetGraph){
			
			if (targetGraph == null){
				return null;
			}

			var newNodes = new List<Node>();
			var linkInfo = new Dictionary<Connection, KeyValuePair<int, int>>();

			//duplicate all nodes first
			foreach (var node in nodes){
				var newNode = node.Duplicate(targetGraph);
				newNodes.Add(newNode);
				if (node == node.graph.primeNode && targetGraph != node.graph){
					targetGraph.primeNode = newNode;
				}
				//store the out connections that need dulpicate along with the indeces of source and target
				foreach (var c in node.outConnections){
					linkInfo[c] = new KeyValuePair<int, int>( nodes.IndexOf(c.sourceNode), nodes.IndexOf(c.targetNode) );
				}
			}

			//duplicate all connections that we stored as 'need duplicating' providing new source and target
			foreach (var linkPair in linkInfo){
				if (linkPair.Value.Value != -1){ //we check this to see if the target node is part of the duplicated nodes since IndexOf returns -1 if element is not part of the list
					var newSource = newNodes[ linkPair.Value.Key ];
					var newTarget = newNodes[ linkPair.Value.Value ];
					linkPair.Key.Duplicate(newSource, newTarget);
				}
			}

			return newNodes;
		}


		///Updates the required references: Setting the system to the tasks and blackboard to BBParameters.
		///This is done when the graph starts and in the editor for convenience.
		public void UpdateReferences(){
			UpdateNodeBBFields();
			SendTaskOwnerDefaults();
		}

		//Update all graph node's BBFields for current Blackboard.
		void UpdateNodeBBFields(){
			for (var i = 0; i < allNodes.Count; i++){
				BBParameter.SetBBFields(allNodes[i], blackboard);
			}
		}

		//Sets all graph Tasks' owner (which is this).
		public void SendTaskOwnerDefaults(){
			var tasks = GetAllTasksOfType<Task>();
			for (var i = 0; i < tasks.Count; i++){
				tasks[i].SetOwnerSystem(this);
			}
		}

		///Update the IDs of the nodes in the graph. Is automatically called whenever a change happens in the graph by the adding removing connecting etc.
		public void UpdateNodeIDs(bool alsoReorderList){

			var lastID = 0;

			//start from prime
			if (primeNode != null){
				lastID = primeNode.AssignIDToGraph(lastID);
			}

			//set the rest starting from nodes without parent(s)
			var tempList = allNodes.OrderBy(n => n.inConnections.Count != 0).ToList();
			for (var i = 0; i < tempList.Count; i++){
				lastID = tempList[i].AssignIDToGraph(lastID);
			}

			//reset the check
			for (var i = 0; i < allNodes.Count; i++){
				allNodes[i].ResetRecursion();
			}

			if (alsoReorderList){
				allNodes = allNodes.OrderBy(node => node.ID).ToList();
			}
		}


		///Start the graph for the agent and blackboard provided.
		///Optionally provide a callback for when the graph stops or ends
		public void StartGraph(Component agent, IBlackboard blackboard, bool autoUpdate, System.Action<bool> callback = null){

			#if UNITY_EDITOR //prevent the user to accidentaly start the graph while its an asset. At least in the editor
			if (UnityEditor.EditorUtility.IsPersistent(this)){
				Debug.LogError("<b>Graph:</b> You have tried to start a graph which is an asset, not an instance! You should Instantiate the graph first");
				return;
			}
			#endif

			if (isRunning){
				if (callback != null){
					OnFinish += callback;
				}
				Debug.LogWarning("<b>Graph:</b> Graph is already Active.");
				return;
			}

			if (agent == null && requiresAgent){
				Debug.LogWarning("<b>Graph:</b> You've tried to start a graph with null Agent.");
				return;
			}

			if (primeNode == null && requiresPrimeNode){
				Debug.LogWarning("<b>Graph:</b> You've tried to start graph without 'Start' node");
				return;
			}
			
			if (blackboard == null){
				if (agent != null){
					Debug.Log("<b>Graph:</b> Graph started without blackboard. Looking for blackboard on agent '" + agent.gameObject + "'...", agent.gameObject);
					blackboard = agent.GetComponent(typeof(IBlackboard)) as IBlackboard;
					if (blackboard != null){
//						Debug.Log("<b>Graph:</b> Blackboard found");
					}
				}
				if (blackboard == null){
					Debug.LogWarning("<b>Graph:</b> Started with null Blackboard. Using Local instead...");
					blackboard = localBlackboard;
				}
			}

			this.agent = agent;
			this.blackboard = blackboard;
			UpdateReferences();

			if (callback != null){
				this.OnFinish = callback;
			}

			isRunning = true;

			//
			runningGraphs.Add(this);

			if (autoUpdate){
				MonoManager.current.onUpdate += UpdateGraph;
			}

			if (!isPaused){
				timeStarted = Time.time;
				OnGraphStarted();
			} else {
				OnGraphUnpaused();
			}
			// place at the end?

			for (var i = 0; i < allNodes.Count; i++){
				if (!isPaused){
					allNodes[i].OnGraphStarted();
				} else {
					allNodes[i].OnGraphUnpaused();
				}
			}

			isPaused = false;
		}

		///Stops the graph completely and resets all nodes.
		public void Stop(bool success = true){

			if (!isRunning && !isPaused){
				return;
			}

			runningGraphs.Remove(this);
			MonoManager.current.onUpdate -= UpdateGraph;

			isRunning = false;
			isPaused = false;

			for (var i = 0; i < allNodes.Count; i++){
				allNodes[i].Reset(false);
				allNodes[i].OnGraphStoped();
			}

			OnGraphStoped();

			if (OnFinish != null){
				OnFinish(success);
				OnFinish = null;
			}
		}

		///Pauses the graph from updating as well as notifying all nodes and tasks.
		public void Pause(){

			if (!isRunning){
				return;
			}

			runningGraphs.Remove(this);
			MonoManager.current.onUpdate -= UpdateGraph;
			
			isRunning = false;
			isPaused = true;

			for (var i = 0; i < allNodes.Count; i++){
				allNodes[i].OnGraphPaused();
			}
			OnGraphPaused();
		}

		//This is updated through the MonoManager...
		public void UpdateGraph(){ OnGraphUpdate(); }

		///Override for graph specific stuff to run when the graph is started
		virtual protected void OnGraphStarted(){}

		///Override for graph specific per frame logic. Called every frame if the graph is running
		virtual protected void OnGraphUpdate(){}

		///Override for graph specific stuff to run when the graph is stoped
		virtual protected void OnGraphStoped(){}

		///Override this for when the graph is paused
		virtual protected void OnGraphPaused(){}

		///Override for graph stuff to run when the graph is unpause
		virtual protected void OnGraphUnpaused(){}


		///Sends an OnCustomEvent message to the tasks that needs them. Tasks subscribe to events using [EventReceiver] attribute.
		public void SendEvent(string name){SendEvent(new EventData(name));}
		public void SendEvent<T>(string name, T value){SendEvent(new EventData<T>(name, value));}
		public void SendEvent(EventData eventData){

			if (isRunning && eventData != null && agent != null){

				#if UNITY_EDITOR
				if (NodeCanvas.Editor.NCPrefs.logEvents){
					Debug.Log(string.Format("Event '{0}' Send to '{1}'", eventData.name, agent.gameObject.name), agent);
				}
				#endif

				var router = agent.GetComponent<MessageRouter>();
				if (router != null){
					router.Dispatch("OnCustomEvent", eventData);
					router.Dispatch(eventData.name, eventData.value);
				}
				//if router is null, it means that nothing has subscribed to any event, thus we dont care.
			}
		}

		///Sends an event to all graphs
		public static void SendGlobalEvent(string name){ SendGlobalEvent(new EventData(name)); }
		public static void SendGlobalEvent<T>(string name, T value){ SendGlobalEvent(new EventData<T>(name, value)); }
		public static void SendGlobalEvent(EventData eventData){
			var send = new List<GameObject>();
			foreach(var graph in runningGraphs.ToArray()){ //ToArray because an event may result in a graph stopping and thus messing with the enumeration.
				if (graph.agent != null){
					if (!send.Contains(graph.agent.gameObject)){
						send.Add(graph.agent.gameObject);
						graph.SendEvent(eventData);
					}
				}
			}
		}




		///Get a node by it's ID, null if not found
		public Node GetNodeWithID(int searchID){
			if (searchID <= allNodes.Count && searchID >= 0){
				return allNodes.Find(n => n.ID == searchID);
			}
			return null;
		}

		///Get all nodes of a specific type
		public List<T> GetAllNodesOfType<T>() where T:Node{
			return allNodes.OfType<T>().ToList();
		}

		///Get a node by it's tag name
		public T GetNodeWithTag<T>(string name) where T:Node{
			foreach (var node in allNodes.OfType<T>()){
				if (node.tag == name){
					return node;
				}
			}
			return default(T);
		}

		///Get all nodes taged with such tag name
		public List<T> GetNodesWithTag<T>(string name) where T:Node{
			var nodes = new List<T>();
			foreach (var node in allNodes.OfType<T>()){
				if (node.tag == name){
					nodes.Add(node);
				}
			}
			return nodes;
		}

		///Get all taged nodes regardless tag name
		public List<T> GetAllTagedNodes<T>() where T:Node{
			var nodes = new List<T>();
			foreach (var node in allNodes.OfType<T>()){
				if (!string.IsNullOrEmpty(node.tag)){
					nodes.Add(node);
				}
			}
			return nodes;
		}

		///Get a node by it's name
		public T GetNodeWithName<T>(string name) where T:Node{
			foreach(var node in allNodes.OfType<T>()){
				if (StripNameColor(node.name).ToLower() == name.ToLower()){
					return node;
				}
			}
			return default(T);
		}

		//removes the text color that some nodes add with html tags
		string StripNameColor(string name){
			if (name.StartsWith("<") && name.EndsWith(">")){
				name = name.Replace( name.Substring (0, name.IndexOf(">") + 1), "" );
				name = name.Replace( name.Substring (name.IndexOf("<"), name.LastIndexOf(">") + 1 - name.IndexOf("<")), "" );
			}
			return name;
		}

		///Get all nodes of the graph that have no incomming connections
		public List<Node> GetRootNodes(){
			return allNodes.Where(n => n.inConnections.Count == 0).ToList();
		}

		///Get all Nested graphs of this graph
		public List<T> GetAllNestedGraphs<T>(bool recursive) where T:Graph{
			var graphs = new List<T>();
			foreach (var node in allNodes.OfType<IGraphAssignable>()){
				if (node.nestedGraph is T){
					if (!graphs.Contains((T)node.nestedGraph)){
						graphs.Add( (T)node.nestedGraph );
					}
					if (recursive){
						graphs.AddRange( node.nestedGraph.GetAllNestedGraphs<T>(recursive) );
					}
				}
			}
			return graphs;
		}

		///Get all instance Nested graphs of this graph
		public List<Graph> GetAllInstancedNestedGraphs(){
			var instances = new List<Graph>();
			foreach (var node in allNodes.OfType<IGraphAssignable>()){
				var subInstances = node.GetInstances();
				instances.AddRange( subInstances );
				foreach(var subInstance in subInstances){
					instances.AddRange( subInstance.GetAllInstancedNestedGraphs() );
				}
			}
			return instances;
		}


		///Get ALL assigned node Tasks of type T, in the graph (including tasks assigned on Nodes and on Connections and within ActionList & ConditionList)
		public List<T> GetAllTasksOfType<T>() where T:Task{

			var tasks = new List<Task>();
			var resultTasks = new List<T>();
			for (var i = 0; i < allNodes.Count; i++){
				var node = allNodes[i];
				if (node is ITaskAssignable && (node as ITaskAssignable).task != null){
					tasks.Add( (node as ITaskAssignable).task );
				}
				
				if (node is ISubTasksContainer){
					tasks.AddRange( (node as ISubTasksContainer).GetTasks() );
				}

				for (var j = 0; j < node.outConnections.Count; j++){
					var c = node.outConnections[j];
					if (c is ITaskAssignable && (c as ITaskAssignable).task != null){
						tasks.Add( (c as ITaskAssignable).task );
					}
					if (c is ISubTasksContainer){
						tasks.AddRange( (c as ISubTasksContainer).GetTasks() );
					}
				}
			}

			for (var i = 0; i < tasks.Count; i++){
				var task = tasks[i];
				if (task is ActionList){
					resultTasks.AddRange( (task as ActionList).actions.OfType<T>());
				}
				if (task is ConditionList){
					resultTasks.AddRange( (task as ConditionList).conditions.OfType<T>());
				}
				if (task is T){
					resultTasks.Add((T)task);				
				}
			}

			return resultTasks;
		}

		///Get all defined BBParameters in the graph. Defined means that the BBParameter is set to read or write to/from a Blackboard and is not "|NONE|"
		public BBParameter[] GetDefinedParameters(){

			var bbParams = new List<BBParameter>();
			var objects = new List<object>();
			objects.AddRange(GetAllTasksOfType<Task>().Cast<object>());
			objects.AddRange(allNodes.Cast<object>());

			for (var i = 0; i < objects.Count; i++){
				var o = objects[i];
				if (o is Task){
					var task = (Task)o;
					if (task.agentIsOverride && !string.IsNullOrEmpty(task.overrideAgentParameterName) ){
						bbParams.Add( typeof(Task).RTGetField("overrideAgent").GetValue(task) as BBParameter );
					}
				}

				foreach(BBParameter bbParam in BBParameter.GetObjectBBParameters(o)){
					if (bbParam != null && bbParam.useBlackboard && !bbParam.isNone){
						bbParams.Add(bbParam);
					}
				}
			}

			return bbParams.ToArray();
		}


		///Utility function to create all defined parameters of this graph into the provided blackboard
		public void CreateDefinedParameterVariables(IBlackboard bb){
			foreach (var bbParam in GetDefinedParameters()){
				bbParam.PromoteToVariable(bb);
			}
		}



		///Add a new node to this graph
		public T AddNode<T>() where T : Node{
			return (T)AddNode(typeof(T));
		}

		public T AddNode<T>(Vector2 pos) where T : Node{
			return (T)AddNode(typeof(T), pos);
		}

		public Node AddNode(System.Type nodeType){
			return AddNode(nodeType, new Vector2(50,50));
		}

		///Add a new node to this graph
		public Node AddNode(System.Type nodeType, Vector2 pos){

			if (!nodeType.RTIsSubclassOf(baseNodeType)){
				Debug.LogWarning(nodeType + " can't be added to " + this.GetType().FriendlyName() + " graph");
				return null;
			}

			var newNode = Node.Create(this, nodeType, pos);

			RecordUndo("New Node");

			allNodes.Add(newNode);

			if (primeNode == null){
				primeNode = newNode;
			}
		
			UpdateNodeIDs(false);
			return newNode;
		}

		///Disconnects and then removes a node from this graph
		public void RemoveNode(Node node, bool recordUndo = true){
 
			if (!allNodes.Contains(node)){
				Debug.LogWarning("Node is not part of this graph");
				return;
			}

			#if UNITY_EDITOR
			if (!Application.isPlaying){
				//auto reconnect parent & child of deleted node. Just a workflow convenience
				if (autoSort && node.inConnections.Count == 1 && node.outConnections.Count == 1){
					var relinkNode = node.outConnections[0].targetNode;
					if (relinkNode != node.inConnections[0].sourceNode){
						RemoveConnection(node.outConnections[0]);
						node.inConnections[0].SetTarget(relinkNode);
					}
				}
			}

			//TODO: Fix this in the property accessors?
			currentSelection = null;

			#endif

			//callback
			node.OnDestroy();

			//disconnect parents
			foreach (var inConnection in node.inConnections.ToArray()){
				RemoveConnection(inConnection);
			}

			//disconnect children
			foreach (var outConnection in node.outConnections.ToArray()){
				RemoveConnection(outConnection);
			}

			if (recordUndo){
				RecordUndo("Delete Node");
			}

			allNodes.Remove(node);

			if (node == primeNode){
				primeNode = GetNodeWithID(2);
			}

			UpdateNodeIDs(false);
		}
		
		///Connect two nodes together to the next available port of the source node
		public Connection ConnectNodes(Node sourceNode, Node targetNode){
			return ConnectNodes(sourceNode, targetNode, sourceNode.outConnections.Count);
		}

		///Connect two nodes together to a specific port index of the source node
		public Connection ConnectNodes(Node sourceNode, Node targetNode, int indexToInsert){

			if (targetNode.IsNewConnectionAllowed(sourceNode) == false){
				return null;
			}

			RecordUndo("New Connection");

			var newConnection = Connection.Create(sourceNode, targetNode, indexToInsert);

			sourceNode.OnChildConnected(indexToInsert);
			targetNode.OnParentConnected(targetNode.inConnections.IndexOf(newConnection));

			UpdateNodeIDs(false);
			return newConnection;
		}

		///Removes a connection
		public void RemoveConnection(Connection connection, bool recordUndo = true){

			//for live editing
			if (Application.isPlaying){
				connection.Reset();
			}

			if (recordUndo){
				RecordUndo("Delete Connection");
			}

			//callbacks
			connection.OnDestroy();
			connection.sourceNode.OnChildDisconnected(connection.sourceNode.outConnections.IndexOf(connection));
			connection.targetNode.OnParentDisconnected(connection.targetNode.inConnections.IndexOf(connection));
			
			connection.sourceNode.outConnections.Remove(connection);
			connection.targetNode.inConnections.Remove(connection);

			#if UNITY_EDITOR
			//TODO: FIX in accessors?
			currentSelection = null;
			#endif

			UpdateNodeIDs(false);
		}

		//Helper function
		void RecordUndo(string name){
			#if UNITY_EDITOR
			if (!Application.isPlaying){
				UnityEditor.Undo.RecordObject(this, name);
			}
			#endif
		}

        public Node FindNodeById(int id)
        {
            Node found = null;
            foreach (Node node in allNodes)
            {
                if(node.ID == id)
                {
                    found = node;
                    break;
                }
            }
            return found;
        }
	}
}