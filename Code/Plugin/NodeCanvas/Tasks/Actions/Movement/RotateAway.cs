using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;


namespace NodeCanvas.Tasks.Actions{

	[Category("Movement")]
	public class RotateAway : ActionTask<Transform> {

		[RequiredField]
		public BBParameter<GameObject> target;
		public BBParameter<float> speed;
		[SliderField(1, 180)]
		public BBParameter<float> angleDifference = 5;
		public bool repeat;

		protected override void OnExecute(){Rotate();}
		protected override void OnUpdate(){Rotate();}

		void Rotate(){
			
			if (Vector3.Angle(target.value.transform.position - agent.position, -agent.forward) > angleDifference.value){
				var dir = target.value.transform.position - agent.position;
				agent.rotation = Quaternion.LookRotation(Vector3.RotateTowards(agent.forward, dir, -speed.value * Time.deltaTime, 0));
			} else {
				if (!repeat)
					EndAction();
			}
		}
	}
}