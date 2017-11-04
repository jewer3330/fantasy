using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;


namespace NodeCanvas.StateMachines{

	[Name("Concurrent")]
	[Description("Execute a number of Action Tasks and in parallel to any other state, as soon as the FSM is started. All Action Tasks will prematurely be stoped if the FSM stops as well.\nThis is not a state per se and thus it has no transitions as well as it can't be Entered by transitions.")]
	[Color("ff64cb")]
	public class ConcurrentState : FSMState, IUpdatable, ITaskAssignable{

		[SerializeField]
		private ActionList _actionList;
		[SerializeField]
		private bool _repeatStateActions;

		public ActionList actionList{
			get {return _actionList; }
			set { _actionList = value;}
		}

		public Task task{
			get{return actionList;}
			set{actionList = (ActionList)value;}
		}

		public bool repeatStateActions{
			get {return _repeatStateActions;}
			set {_repeatStateActions = value;}
		}

		public override string name{
			get {return base.name.ToUpper();}
		}

		public override int maxInConnections{ get {return 0;} }
		public override int maxOutConnections{ get {return 0;} }
		public override bool allowAsPrime{ get {return false;} }

		public override void OnValidate(Graph assignedGraph){
			if (actionList == null){
				actionList = (ActionList)Task.Create(typeof(ActionList), assignedGraph);
				actionList.executionMode = ActionList.ActionsExecutionMode.ActionsRunInParallel;
			}
		}

		protected override void OnEnter(){ Update(); }

		new public void Update(){
			if (status == Status.Resting || status == Status.Running){
				if (actionList.ExecuteAction(graphAgent, graphBlackboard) != Status.Running){
					if (!repeatStateActions){
						Finish();
					}
				}
			}
		}

		protected override void OnExit(){
			actionList.EndAction(null);
		}

		protected override void OnPause(){
			actionList.PauseAction();
		}

		////////////////////////////////////////
		///////////GUI AND EDITOR STUFF/////////
		////////////////////////////////////////
		#if UNITY_EDITOR
	
		protected override void OnNodeGUI(){
			if (repeatStateActions)
				GUILayout.Label("<b>[REPEAT]</b>");
			base.OnNodeGUI();
		}

		protected override void OnNodeInspectorGUI(){

			if (actionList == null)
				return;

			EditorUtils.CoolLabel("Actions");
			repeatStateActions = UnityEditor.EditorGUILayout.ToggleLeft("Repeat Actions", repeatStateActions);
			actionList.ShowListGUI();
			actionList.ShowNestedActionsGUI();
		}

		#endif
	}
}