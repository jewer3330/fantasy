using NodeCanvas.Framework;
using UnityEngine;


namespace NodeCanvas.StateMachines{

	/// <summary>
	/// Add this component on a gameobject to behave based on an FSM.
	/// </summary>
	[AddComponentMenu("NodeCanvas/FSM Owner")]
	public class FSMOwner : GraphOwner<FSM> {

		///The current state name
		public string currentStateName{
			get {return behaviour != null? behaviour.currentStateName : null;}
		}

		///The previous state name
		public string previousStateName{
			get {return behaviour != null? behaviour.previousStateName : null;}
		}

		///Enter an FSM state by it's name
		public FSMState TriggerState(string stateName){

			if (behaviour != null)
				return behaviour.TriggerState(stateName);
			return null;
		}

		///Get all state names, excluding non-named states
		public string[] GetStateNames(){
			if (behaviour != null)
				return behaviour.GetStateNames();
			return null;
		}
	}
}