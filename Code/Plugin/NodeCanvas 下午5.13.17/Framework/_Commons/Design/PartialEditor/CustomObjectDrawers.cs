#if UNITY_EDITOR

using UnityEngine;
using System;
using System.Reflection;

namespace ParadoxNotion.Design{

	///Derive this to create custom attributes to be drawn with an ObjectAttributeDrawer<T>.
	[AttributeUsage(AttributeTargets.Field)]
	abstract public class CustomDrawerAttribute : Attribute{}

	///Do not derive this. Derive from it's generic version only, where T is the type we care for.
	abstract public class CustomDrawer {
		abstract public object DrawGUI(string label, object instance, FieldInfo fieldInfo, Attribute attribute, object context);
	}

	///Derive this to create custom drawers for T assignable object types.
	abstract public class ObjectDrawer<T> : CustomDrawer{

		///The instance of the object being drawn/serialized and for which this drawer is for
		public T instance{get; set;}
		///The reflected FieldInfo representation
		public FieldInfo fieldInfo{get; set;}
		///The object the instance is drawn/serialized within
		public object context{get; set;}

		///Begin GUI
		sealed public override object DrawGUI(string label, object instance, FieldInfo fieldInfo, Attribute attribute, object context){
			this.fieldInfo = fieldInfo;
			this.context = context;
			return OnGUI(label, (T)instance);
		}

		///Override to implement GUI. Return the modified instance at the end.
		abstract public T OnGUI(string label, T instance);
	}


	///Derive this to create custom drawers for T ObjectDrawerAttributes.
	abstract public class AttributeDrawer<T> : CustomDrawer where T:CustomDrawerAttribute{

		///The instance of the object being drawn/serialized
		public object instance{get; set;}
		///The reflection FieldInfo representation
		public FieldInfo fieldInfo{get; set;}
		///The attribute against this drawer is for.
		public T attribute{get; set;}
		///The object the instance is drawn/serialized within
		public object context{get; set;}

		///Begin GUI
		sealed public override object DrawGUI(string label, object instance, FieldInfo fieldInfo, Attribute attribute, object context){
			this.fieldInfo = fieldInfo;
			this.context = context;
			this.attribute = (T)attribute;
			return OnGUI(label, instance);
		}

		///Override to implement GUI. Return the modified instance at the end.
		abstract public object OnGUI(string label, object instance);
	}


	///A stub
	sealed public class NoDrawer : CustomDrawer{
		public override object DrawGUI(string label, object instance, FieldInfo fieldInfo, Attribute attribute, object context){return instance;}
	}
}

#endif