using NodeCanvas.Framework;
using ParadoxNotion.Design;


namespace NodeCanvas.Tasks.Actions{

    [Category("IF")]
    [Description("Set a blackboard boolean variable")]
	public class SetBoolean : ActionTask{

		public enum BoolSetModes
		{
			False  = 0,
			True   = 1,
			Toggle = 2
		}

		[RequiredField] [BlackboardOnly]
		public BBParameter<bool> boolVariable;
		public BBParameter<BoolSetModes> setTo = BoolSetModes.True;

		protected override string info{
			get 
			{
				if (setTo.value == BoolSetModes.Toggle)
					return "Toggle " + boolVariable.ToString();

				return "Set " + boolVariable.ToString() + " to " + setTo.ToString();			
			}
		}

		protected override void OnExecute(){
			
			if (setTo.value == BoolSetModes.Toggle){
				
				boolVariable.value = !boolVariable.value;
		
			} else {

				var checkBool = ( (int)setTo.value == 1 );
				boolVariable.value = checkBool;
			}

			EndAction();
		}
	}
}