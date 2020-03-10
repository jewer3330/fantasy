using NodeCanvas.Framework;
using ParadoxNotion;
using ParadoxNotion.Design;


namespace NodeCanvas.Tasks.Conditions{

    [Category("IF")]
    public class CheckInt : ConditionTask{

		[BlackboardOnly]
		public BBParameter<int> valueA;
		public BBParameter<CompareMethod> checkType = CompareMethod.EqualTo;
		public BBParameter<int> valueB;

		protected override string info{
			get {return valueA + OperationTools.GetCompareString(checkType.value) + valueB;}
		}

		protected override bool OnCheck(){
			return OperationTools.Compare((int)valueA.value, (int)valueB.value, checkType.value);
		}
	}
}