using NodeCanvas.Framework;
using ParadoxNotion;
using ParadoxNotion.Design;
using UnityEngine;


namespace NodeCanvas.Tasks.Actions
{

    [Category("✫ Blackboard")]
    [Description("Set a blackboard Vector3 variable from floats")]
    public class SetVector3Floats : ActionTask
    {

        [BlackboardOnly]
        public BBParameter<float> valueA;
        public BBParameter<float> valueB;
        public BBParameter<float> valueC;
        public BBParameter<Vector3> valueD;

        protected override string info
        {
            get { return string.Format("({0},{1},{2}) => {3}", valueA,valueB,valueC ,valueD); }
        }

        protected override void OnExecute()
        {
            valueD.value = new Vector3(valueA.value, valueB.value, valueC.value); 
            EndAction();
        }
    }
}