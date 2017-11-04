using UnityEngine;
using NodeCanvas.Framework;
using ParadoxNotion.Design;

namespace NodeCanvas.Tasks.Actions{

	[Category("Movement")]
	[Description("Flees away from the target")]
	public class Flee : ActionTask<UnityEngine.AI.NavMeshAgent> {

		[RequiredField]
		public BBParameter<GameObject> target;
		public BBParameter<float> speed = 4f;
		public BBParameter<float> fledDistance = 10f;
		public BBParameter<float> lookAheadDistance = 5f;

		protected override void OnExecute(){
			agent.speed = speed.value;
			if ( (agent.transform.position - target.value.transform.position).magnitude >= fledDistance.value ){
				EndAction();
				return;
			}

			DoFlee();
		}

		protected override void OnUpdate(){

			if (!agent.pathPending && (agent.transform.position - target.value.transform.position).magnitude >= fledDistance.value ){
				EndAction();
				return;
			}

			DoFlee();
		}

		void DoFlee(){
			var fleePos = agent.transform.position + (agent.transform.position - target.value.transform.position).normalized * lookAheadDistance.value;
			agent.SetDestination( fleePos );
		}

		protected override void OnPause(){OnStop();}
		protected override void OnStop(){
			if (agent.gameObject.activeSelf)
				agent.ResetPath();
		}
	}
}