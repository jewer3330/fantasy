using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;


namespace NodeCanvas.Tasks.Actions{

	[Name("Move To Target Position")]
	[Category("Movement")]
	public class MoveToPosition : ActionTask<UnityEngine.AI.NavMeshAgent> {

		public BBParameter<Vector3> targetPosition;
		public BBParameter<float> speed = 3;
		public float keepDistance = 0.1f;

		private Vector3? lastRequest;

		protected override string info{
			get {return "GoTo " + targetPosition.ToString();}
		}

		protected override void OnExecute(){

			agent.speed = speed.value;
			if ( (agent.transform.position - targetPosition.value).magnitude < agent.stoppingDistance + keepDistance){
				EndAction(true);
				return;
			}

			Go();
		}

		protected override void OnUpdate(){
			Go();
		}

		void Go(){

			if (lastRequest != targetPosition.value){
				if ( !agent.SetDestination( targetPosition.value) ){
					EndAction(false);
					return;
				}
			}

			lastRequest = targetPosition.value;

			if (!agent.pathPending && agent.remainingDistance <= agent.stoppingDistance + keepDistance){
				EndAction(true);
			}
		}

		protected override void OnStop(){
			if (lastRequest != null && agent.gameObject.activeSelf){
				agent.ResetPath();
			}
			lastRequest = null;
		}

		protected override void OnPause(){
			OnStop();
		}
	}
}