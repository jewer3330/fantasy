using UnityEngine;
using System.Collections.Generic;

namespace NodeCanvas.Framework.Internal{

	//This component is only used for updating bound graphs (of GraphOwners) made before version 2.6.2
	public class VersionUpdateProxyGraph : MonoBehaviour {
		public string _serializedGraph; //this must be the same name as Graph.cs
		public List<Object> _objectReferences; //this must be the same name as Graph.cs
		public void GetSerializationData(out string json, out List<Object> references){
			json = this._serializedGraph;
			references = _objectReferences != null? new List<Object>(this._objectReferences) : null;
		}
	}
}