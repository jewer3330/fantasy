using System;
using System.Linq;
using System.Reflection;
using UnityEngine;
using ParadoxNotion.Serialization.FullSerializer.Internal;

namespace ParadoxNotion.Serialization{

	///Serialized MethodInfo
	[Serializable]
	public class SerializedMethodInfo : ISerializationCallbackReceiver{

		[SerializeField]
		private string _returnInfo;		
		[SerializeField]
		private string _baseInfo;
		[SerializeField]
		private string _paramsInfo;
		
		[NonSerialized]
		private MethodInfo _method;
		[NonSerialized]
		private bool _hasChanged;

		///serialize to strings info
		void ISerializationCallbackReceiver.OnBeforeSerialize(){
			_hasChanged = false;
			if (_method != null){
				_returnInfo = _method.ReturnType.FullName;
				_baseInfo = string.Format("{0}|{1}", _method.RTReflectedType().FullName, _method.Name);
				_paramsInfo = string.Join("|", _method.GetParameters().Select(p => p.ParameterType.FullName).ToArray() );
			}
		}

		//deserialize from strings info
		void ISerializationCallbackReceiver.OnAfterDeserialize(){
			_hasChanged = false;
			var split = _baseInfo.Split('|');
			var type = fsTypeCache.GetType(split[0], null);
			if (type == null){
				_method = null;
				return;
			}

			var name = split[1];
			var paramTypeNames = string.IsNullOrEmpty(_paramsInfo)? null : _paramsInfo.Split('|');
			var parameterTypes = paramTypeNames == null? new Type[0] : paramTypeNames.Select(n => fsTypeCache.GetType(n, null)).ToArray();
			if (parameterTypes.All(t => t != null)){
				_method = type.RTGetMethod(name, parameterTypes);
				if (!string.IsNullOrEmpty(_returnInfo)){ //it might be in case of older serialzations
					var returnType = fsTypeCache.GetType(_returnInfo, null);
					if (_method != null && returnType != _method.ReturnType){
						_method = null;
					}
				}
			}
			
			if (_method == null){
				_hasChanged = true;
				//resolve to first method found with same name. Do it this way insteaf of GetMethod to avoid ambigous reference
				_method = type.RTGetMethods().FirstOrDefault(m => m.Name == name);
			}
		}

		//required
		public SerializedMethodInfo(){}
		///Serialize a new MethodInfo
		public SerializedMethodInfo(MethodInfo method){
			_hasChanged = false;
			_method = method;
		}

		///Deserialize and return target MethodInfo.
		public MethodInfo Get(){
			return _method;
		}

		//Are the original and finaly resolve methods different?
		public bool HasChanged(){
			return _hasChanged;
		}
	
		///Returns the serialized method information.
		public string GetMethodString(){
			return string.Format("{0} ({1})", _baseInfo.Replace("|", "."), _paramsInfo.Replace("|", ", "));
		}
	}
}