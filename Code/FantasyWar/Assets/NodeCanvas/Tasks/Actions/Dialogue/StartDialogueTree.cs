using UnityEngine;
using ParadoxNotion.Design;
using NodeCanvas.Framework;
using NodeCanvas.DialogueTrees;

namespace NodeCanvas.Tasks.Actions{

	[Category("Dialogue")]
	[Description("Starts the Dialogue Tree assigned on a Dialogue Tree Controller object with specified agent used for 'Instigator'.")]
	[Icon("Dialogue")]
	[AgentType(typeof(IDialogueActor))]
	public class StartDialogueTree : ActionTask {

		[RequiredField]
		public BBParameter<DialogueTreeController> dialogueTreeController;
		public bool waitActionFinish = true;

		protected override string info{
			get {return string.Format("Start Dialogue {0}", dialogueTreeController);}
		}

		protected override void OnExecute(){
			var actor = (IDialogueActor)agent;
			if (waitActionFinish){
				dialogueTreeController.value.StartDialogue(actor, (success)=> {EndAction(success);} );
			} else {
				dialogueTreeController.value.StartDialogue(actor);
				EndAction();
			}
		}
	}
}