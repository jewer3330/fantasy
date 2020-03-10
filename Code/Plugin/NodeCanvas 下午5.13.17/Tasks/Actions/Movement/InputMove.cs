using NodeCanvas.Framework;
using ParadoxNotion.Design;
using UnityEngine;


namespace NodeCanvas.Tasks.Actions{

	[Category("Movement")]
	[Description("Move & turn the agent based on input values provided ranging from -1 to 1. Per frame and in delta time")]
	public class InputMove : ActionTask<Transform> {

        [BlackboardOnly]
        public BBParameter<float> strafe;
		[BlackboardOnly]
        public BBParameter<float> turn;
        [BlackboardOnly]
        public BBParameter<float> forward;
        [BlackboardOnly]
        public BBParameter<float> up;
        public BBParameter<float> moveSpeed = 1;
        public BBParameter<float> rotationSpeed = 1;

        public bool repeat;

        protected override void OnExecute(){Move();}
		protected override void OnUpdate(){Move();}
        
        void Move() {
			var targetRotation = agent.rotation * Quaternion.Euler(Vector3.up * turn.value * 10);
			agent.rotation = Quaternion.Slerp(agent.rotation, targetRotation, rotationSpeed.value * Time.deltaTime);

			var forwardMovement = agent.forward * forward.value * moveSpeed.value * Time.deltaTime;
			var strafeMovement = agent.right * strafe.value * moveSpeed.value * Time.deltaTime;
			var upMovement = agent.up * up.value * moveSpeed.value * Time.deltaTime;
			agent.position += strafeMovement + forwardMovement + upMovement;

            if (!repeat)
	            EndAction();
        }
	}
}