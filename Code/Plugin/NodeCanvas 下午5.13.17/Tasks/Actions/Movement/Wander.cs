using UnityEngine;
using NodeCanvas.Framework;
using ParadoxNotion.Design;

namespace NodeCanvas.Tasks.Actions{

	[Category("Movement")]
	[Description("Makes the agent wander randomly within the navigation map")]
	public class Wander : ActionTask<UnityEngine.AI.NavMeshAgent> {

		public BBParameter<float> speed = 4;
		public BBParameter<float> stoppingDistance = 0.1f;
		public BBParameter<float> minWanderDistance = 5;
		public BBParameter<float> maxWanderDistance = 20;
		public bool repeat = true;

		protected override void OnExecute(){
			agent.speed = speed.value;
			agent.stoppingDistance = stoppingDistance.value;
			DoWander();
		}
		protected override void OnUpdate(){
			if (!agent.pathPending && agent.remainingDistance <= agent.stoppingDistance){
				if (repeat){
					DoWander();
				} else {
					EndAction();
				}
			}
		}

		void DoWander(){
			minWanderDistance.value = Mathf.Min(minWanderDistance.value, maxWanderDistance.value);
			var wanderPos = (Random.insideUnitSphere * maxWanderDistance.value) + agent.transform.position;
			while ( (wanderPos - agent.transform.position).sqrMagnitude < minWanderDistance.value )
				wanderPos = (Random.insideUnitSphere * maxWanderDistance.value) + agent.transform.position;

			agent.SetDestination(wanderPos);
		}

		protected override void OnPause(){ OnStop(); }
		protected override void OnStop(){
			if (agent.gameObject.activeSelf)
				agent.ResetPath();
		}
	}
}