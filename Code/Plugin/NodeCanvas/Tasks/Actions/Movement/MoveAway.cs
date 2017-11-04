using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;


namespace NodeCanvas.Tasks.Actions{

	[Category("Movement")]
	public class MoveAway : ActionTask<Transform> {

		[RequiredField]
		public BBParameter<GameObject> target;
		public BBParameter<float> speed = 2;
		public BBParameter<float> stopDistance = 3;
		public bool repeat;

		protected override void OnExecute(){Move();}
		protected override void OnUpdate(){Move();}

		void Move(){
			
			if ( (agent.position - target.value.transform.position).magnitude < stopDistance.value ){
				agent.position = Vector3.MoveTowards(agent.position, target.value.transform.position, -speed.value * Time.deltaTime);
			} else {
				if (!repeat)
					EndAction();
			}
		}
	}
}