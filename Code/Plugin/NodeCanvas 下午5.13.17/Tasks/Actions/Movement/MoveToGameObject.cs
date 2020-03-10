using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;


namespace NodeCanvas.Tasks.Actions{

	[Name("Move To Target")]
	[Category("Movement")]
	public class MoveToGameObject : ActionTask<UnityEngine.AI.NavMeshAgent> {

		[RequiredField]
		public BBParameter<GameObject> target;
		public BBParameter<float> speed = 3;
		public float keepDistance = 0.1f;

		private Vector3? lastRequest;

		protected override string info{
			get {return "GoTo " + target.ToString();}
		}

		protected override void OnExecute(){

			agent.speed = speed.value;
			if ( (agent.transform.position - target.value.transform.position).magnitude < agent.stoppingDistance + keepDistance){
				EndAction(true);
				return;
			}

			Go();
		}

		protected override void OnUpdate(){
			Go();
		}

		void Go(){
			
			var pos = target.value.transform.position;

			if (lastRequest != pos){
				if ( !agent.SetDestination( pos) ){
					EndAction(false);
					return;
				}
			}

			lastRequest = pos;

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

		public override void OnDrawGizmos(){
			if (target.value != null){
				Gizmos.DrawWireSphere(target.value.transform.position, keepDistance);
			}
		}
	}
}