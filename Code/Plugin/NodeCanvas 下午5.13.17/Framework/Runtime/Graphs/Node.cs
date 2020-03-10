using System.Collections;
using System.Collections.Generic;
using System.Linq;
using NodeCanvas.Framework.Internal;
using ParadoxNotion;
using ParadoxNotion.Design;
using ParadoxNotion.Serialization;
using ParadoxNotion.Serialization.FullSerializer;
using ParadoxNotion.Services;
using UnityEngine;


namespace NodeCanvas.Framework{


	///The base class for all nodes that can live in a NodeCanvas Graph

	#if UNITY_EDITOR //handles missing Nodes
	[fsObject(Processor = typeof(fsRecoveryProcessor<Node, MissingNode>))]
	#endif

    [System.Serializable]
    [ParadoxNotion.Design.SpoofAOT]
	abstract public partial class Node {

		[SerializeField]
		private Vector2 _position = Vector2.zero;
		[SerializeField]
		private string _name;
		[SerializeField]
		private string _tag;
		[SerializeField]
		private string _comment;
		[SerializeField]
		private bool _isBreakpoint = false;

		//reconstructed OnDeserialization
		private Graph _graph;
		//reconstructed OnDeserialization
		private List<Connection> _inConnections = new List<Connection>();
		//reconstructed OnDeserialization
		private List<Connection> _outConnections = new List<Connection>();
		//reconstructed OnDeserialization
		private int _ID;

		[System.NonSerialized]
		private Status _status = Status.Resting;
		[System.NonSerialized]
		private string _nodeName;
		[System.NonSerialized]
		private string _nodeDescription;

		/////

		public Vector2 nodePosition{
			get {return _position;}
			set {_position = value;}
		}

		///The graph this node belongs to
		public Graph graph{
			get {return _graph;}
			set {_graph = value;}
		}

		///The node's ID in the graph
		public int ID {
			get {return _ID;}
			set {_ID = value;}
		}

		///All incomming connections to this node
		public List<Connection> inConnections{
			get {return _inConnections;}
			protected set {_inConnections = value;}
		}

		///All outgoing connections from this node
		public List<Connection> outConnections{
			get {return _outConnections;}
			protected set {_outConnections = value;}
		}

		//The custom title name of the node if any
		private string customName{
			get {return _name;}
			set {_name = value;}
		}

		///The node tag. Useful for finding nodes through code
		public string tag{
			get {return _tag;}
			set {_tag = value;}
		}

		///The comments of the node if any
		public string nodeComment{
			get {return _comment;}
			set {_comment = value;}
		}

		///Is the node set as a breakpoint?
		public bool isBreakpoint{
			get {return _isBreakpoint;}
			set {_isBreakpoint = value;}
		}


		///The title name of the node shown in the window if editor is not in Icon Mode. This is a property so title name may change instance wise
		virtual public string name{
			get
			{
				if (!string.IsNullOrEmpty(customName)){
					return customName;
				}

				if (string.IsNullOrEmpty(_nodeName) ){
					var nameAtt = this.GetType().RTGetAttribute<NameAttribute>(false);
					_nodeName = nameAtt != null? nameAtt.name : GetType().FriendlyName().SplitCamelCase();
				}
				return _nodeName;
			}
			set {customName = value;}
		}

		///The description info of the node
		virtual public string description{
			get
			{
				if (string.IsNullOrEmpty(_nodeDescription)){
					var descAtt = this.GetType().RTGetAttribute<DescriptionAttribute>(false);
					_nodeDescription = descAtt != null? descAtt.description : "No Description";
				}
				return _nodeDescription;
			}
		}

		///The numer of possible inputs. -1 for infinite
		abstract public int maxInConnections{get;}
		///The numer of possible outputs. -1 for infinite
		abstract public int maxOutConnections{get;}
		///The output connection Type this node has
		abstract public System.Type outConnectionType{get;}
		///Can this node be set as prime (Start)?
		abstract public bool allowAsPrime{get;}
		//show comments bottom or right?
		abstract public bool showCommentsBottom{get;}


		///The current status of the node
		public Status status{
			get {return _status;}
			protected set {_status = value;}
		}

		///The current agent. Taken from the graph this node belongs to
		public Component graphAgent{
			get {return graph != null? graph.agent : null;}
		}

		///The current blackboard. Taken from the graph this node belongs to
		public IBlackboard graphBlackboard{
			get {return graph != null? graph.blackboard : null;}
		}

		//Used to check recursion
		private bool isChecked{get;set;}

		/////////////////////
		/////////////////////
		/////////////////////

		//required
		public Node(){}


		///Create a new Node of type and assigned to the provided graph. Use this for constructor
		public static Node Create(Graph targetGraph, System.Type nodeType, Vector2 pos){

			if (targetGraph == null){
				Debug.LogError("Can't Create a Node without providing a Target Graph");
				return null;
			}

			var newNode = (Node)System.Activator.CreateInstance(nodeType);

			#if UNITY_EDITOR
			if (!Application.isPlaying){
				UnityEditor.Undo.RecordObject(targetGraph, "Create Node");
			}
			#endif

			newNode.graph = targetGraph;
			newNode.nodePosition = pos;
			BBParameter.SetBBFields(newNode, targetGraph.blackboard);

			newNode.OnValidate(targetGraph);
			return newNode;
		}

		///Duplicate node alone assigned to the provided graph
		public Node Duplicate(Graph targetGraph){

			if (targetGraph == null){
				Debug.LogError("Can't duplicate a Node without providing a Target Graph");
				return null;
			}

			//deep clone
			var newNode = JSONSerializer.Deserialize<Node>(  JSONSerializer.Serialize(typeof(Node), this )  );

			#if UNITY_EDITOR
			if (!Application.isPlaying){
				UnityEditor.Undo.RecordObject(targetGraph, "Duplicate");
			}
			#endif

			targetGraph.allNodes.Add(newNode);
			newNode.inConnections.Clear();
			newNode.outConnections.Clear();

			if (targetGraph == this.graph){
				newNode.nodePosition += new Vector2(50,50);
			}

			newNode.graph = targetGraph;
			BBParameter.SetBBFields(newNode, targetGraph.blackboard);

			var assignable = this as ITaskAssignable;
			if (assignable != null && assignable.task != null){
				(newNode as ITaskAssignable).task = assignable.task.Duplicate(targetGraph);
			}

			newNode.OnValidate(targetGraph);
			return newNode;
		}

		///Called when the Node is created, duplicated or otherwise needs validation.
		virtual public void OnValidate(Graph assignedGraph){}
		///Called when the Node is removed from the graph (always through graph.RemoveNode)
		virtual public void OnDestroy(){}


		///The main execution function of the node. Execute the node for the agent and blackboard provided. Default = graphAgent and graphBlackboard
		public Status Execute(Component agent, IBlackboard blackboard){

			if (isChecked){
				return Error("Infinite Loop. Please check for other errors that may have caused this in the log.");
			}

			#if UNITY_EDITOR
			if (isBreakpoint && status == Status.Resting){
				var breakEditor = NodeCanvas.Editor.NCPrefs.breakpointPauseEditor;
				var owner = agent as GraphOwner;
				var contextName = owner != null? owner.gameObject.name : graph.name;
				var contextObject = owner != null? (Object)owner : (Object)graph;
				Debug.LogWarning(string.Format("<b>Breakpoint Reached</b>: At Node: '{0}' | ID: '{1}' | Graph Type: '{2}' | Context Object: '{3}'", name, ID, graph.GetType().Name, contextName), contextObject);
				if (breakEditor || owner == null){
					StartCoroutine( YieldBreak(agent, blackboard) );
					status = Status.Running;
					return Status.Running;					
				}
				if (owner != null){
					owner.PauseBehaviour();
					status = Status.Running;
					return Status.Running;
				}
			}
			#endif

			isChecked = true;
			status = OnExecute(agent, blackboard);
			isChecked = false;

			return status;
		}

		///Helper for breakpoints
		IEnumerator YieldBreak(Component agent, IBlackboard blackboard){
			Debug.Break();
			yield return null;
			status = OnExecute(agent, blackboard);
		}

		///A little helper function to log errors easier
		protected Status Error(string log){
			Debug.LogError("<b>Graph Error:</b> '" + log + "' On node '" + name + "' ID " + ID + " | On graph '" + graph.name + "'");
			return Status.Error;
		}

		///Recursively reset the node and child nodes if it's not Resting already
		public void Reset(bool recursively = true){

			if (status == Status.Resting || isChecked)
				return;

			OnReset();
			status = Status.Resting;

			isChecked = true;
			for (var i = 0; i < outConnections.Count; i++){
				outConnections[i].Reset(recursively);
			}
			isChecked = false;
		}

		///Sends an event to the graph
		public void SendEvent(EventData eventData){
			graph.SendEvent(eventData);
		}

		///Subscribe the node to a unity message send to the agent
		public void RegisterEvents(params string[] eventNames){ RegisterEvents(graphAgent, eventNames); }
		public void RegisterEvents(Component targetAgent, params string[] eventNames){
			if (targetAgent == null){
				Debug.LogError("Null Agent provided for event registration");
				return;
			}
			var router = targetAgent.GetComponent<MessageRouter>();
			if (router == null){
				router = targetAgent.gameObject.AddComponent<MessageRouter>();
			}

			router.Register(this, eventNames);
		}

		///Unsubscribe from a specific message to the target agent
		public void UnRegisterEvents(params string[] eventNames){ UnRegisterEvents(graphAgent, eventNames); }
		public void UnRegisterEvents(Component targetAgent, params string[] eventNames){
			if (targetAgent == null)
				return;
			var router = targetAgent.GetComponent<MessageRouter>();
			if (router != null){
				router.UnRegister(this, eventNames);
			}
		}

		///Unsubscribe the node from all eventNames send to the target agent
		public void UnregisterAllEvents(){ UnregisterAllEvents(graphAgent); }
		public void UnregisterAllEvents(Component targetAgent){
			if (targetAgent == null)
				return;
			var router = targetAgent.GetComponent<MessageRouter>();
			if (router != null){
				router.UnRegister(this);
			}
		}



		///Returns if a new input connection should be allowed.
		public bool IsNewConnectionAllowed(){ return IsNewConnectionAllowed(null); }
		///Returns if a new input connection should be allowed from the source node.
		public bool IsNewConnectionAllowed(Node sourceNode){

			if (sourceNode != null){
				if (this == sourceNode){
					Debug.LogWarning("Node can't connect to itself");
					return false;
				}

				if (sourceNode.outConnections.Count >= sourceNode.maxOutConnections && sourceNode.maxOutConnections != -1){
					Debug.LogWarning("Source node can have no more out connections.");
					return false;
				}
			}

			if (this == graph.primeNode && maxInConnections == 1){
				Debug.LogWarning("Target node can have no more connections");
				return false;
			}

			if (maxInConnections <= inConnections.Count && maxInConnections != -1){
				Debug.LogWarning("Target node can have no more connections");
				return false;
			}

			return true;
		}

		//Updates the node ID in it's current graph. This is called in the editor GUI for convenience, as well as whenever a change is made in the node graph and from the node graph.
		public int AssignIDToGraph(int lastID){

			if (isChecked){
				return lastID;
			}
			
			isChecked = true;
			lastID++;
			ID = lastID;

			for (var i = 0; i < outConnections.Count; i++){
				lastID = outConnections[i].targetNode.AssignIDToGraph(lastID);
			}

			return lastID;
		}

		public void ResetRecursion(){

			if (!isChecked){
				return;
			}

			isChecked = false;
			for (var i = 0; i < outConnections.Count; i++){
				outConnections[i].targetNode.ResetRecursion();
			}
		}


		///Nodes can use coroutine as normal through MonoManager.
		protected Coroutine StartCoroutine(IEnumerator routine){
			return MonoManager.current.StartCoroutine(routine);
		}

		///Nodes can use coroutine as normal through MonoManager.
		protected void StopCoroutine(Coroutine routine){
			MonoManager.current.StopCoroutine(routine);
		}


		///Returns all parent nodes in case node can have many parents like in FSM and Dialogue Trees
		public List<Node> GetParentNodes(){
			if (inConnections.Count != 0)
				return inConnections.Select(c => c.sourceNode).ToList();
			return new List<Node>();
		}

		///Get all childs of this node, on the first depth level
		public List<Node> GetChildNodes(){
			if (outConnections.Count != 0)
				return outConnections.Select(c => c.targetNode).ToList();
			return new List<Node>();
		}

		///Override to define node functionality. The Agent and Blackboard used to start the Graph are propagated
		virtual protected Status OnExecute(Component agent, IBlackboard blackboard){ return status; }

		///Called when the node gets reseted. e.g. OnGraphStart, after a tree traversal, when interrupted, OnGraphEnd etc...
		virtual protected void OnReset(){}

		///Called when an input connection is connected
		virtual public void OnParentConnected(int connectionIndex){}

		///Called when an input connection is disconnected but before it actually does
		virtual public void OnParentDisconnected(int connectionIndex){}

		///Called when an output connection is connected
		virtual public void OnChildConnected(int connectionIndex){}

		///Called when an output connection is disconnected but before it actually does
		virtual public void OnChildDisconnected(int connectionIndex){}

		///Called when the parent graph is started. Use to init values or otherwise.
		virtual public void OnGraphStarted(){}

		///Called when the parent graph is stopped.
		virtual public void OnGraphStoped(){}

		///Called when the parent graph is paused.
		virtual public void OnGraphPaused(){}

		///Called when the parent graph is unpaused.
		virtual public void OnGraphUnpaused(){}

		sealed public override string ToString(){
			var assignable = this as ITaskAssignable;
			return string.Format("{0} ({1})", name, assignable != null && assignable.task != null? assignable.task.ToString() : "" );
		}

		public void OnDrawGizmos(){
			if (this is ITaskAssignable && (this as ITaskAssignable).task != null )
				(this as ITaskAssignable).task.OnDrawGizmos();
		}

		public void OnDrawGizmosSelected(){
			if (this is ITaskAssignable && (this as ITaskAssignable).task != null)
				(this as ITaskAssignable).task.OnDrawGizmosSelected();
		}
#if UNITY_EDITOR
        public bool DebugStatusChange(Status statusSet)
        {
            this.status = statusSet;
            return true;
        }
#endif //UNITY_EDITOR
    }
}