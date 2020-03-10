#if UNITY_EDITOR

using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using NodeCanvas.Framework;
using UnityEditor;
using UnityEngine;
using ParadoxNotion;
using UnityObject = UnityEngine.Object;


namespace ParadoxNotion.Design{

    /// <summary>
    /// Flavor GUI and AutomaticInspector function
    /// </summary>

	partial class EditorUtils {

        private static Texture2D _tex;
        private static Texture2D tex
        {
            get
            {
                if (_tex == null){
                    _tex = new Texture2D(1, 1);
                    _tex.hideFlags = HideFlags.HideAndDontSave;
                }
                return _tex;
            }
        }

		//a cool label :-P (for headers)
		public static void CoolLabel(string text){
			GUI.skin.label.richText = true;
			GUI.color = lightOrange;
			GUILayout.Label("<b><size=14>" + text + "</size></b>");
			GUI.color = Color.white;
			GUILayout.Space(2);
		}

		//a thin separator
		public static void Separator(){
			GUI.backgroundColor = Color.black;
			GUILayout.Box("", GUILayout.MaxWidth(Screen.width), GUILayout.Height(2));
			GUI.backgroundColor = Color.white;
		}

		//A thick separator similar to ngui. Thanks
		public static void BoldSeparator(){
			var lastRect = GUILayoutUtility.GetLastRect();
			GUILayout.Space(14);
			GUI.color = new Color(0, 0, 0, 0.25f);
			GUI.DrawTexture(new Rect(0, lastRect.yMax + 6, Screen.width, 4), tex);
			GUI.DrawTexture(new Rect(0, lastRect.yMax + 6, Screen.width, 1), tex);
			GUI.DrawTexture(new Rect(0, lastRect.yMax + 9, Screen.width, 1), tex);
			GUI.color = Color.white;
		}

		//Combines the rest functions for a header style label
		public static void TitledSeparator(string title){
			GUILayout.Space(1);
			BoldSeparator();
			CoolLabel(title + " ▼");
			Separator();
		}

		//Just a fancy ending for inspectors
		public static void EndOfInspector(){
			var lastRect= GUILayoutUtility.GetLastRect();
			GUILayout.Space(8);
			GUI.color = new Color(0, 0, 0, 0.4f);
			GUI.DrawTexture(new Rect(0, lastRect.yMax + 6, Screen.width, 4), tex);
			GUI.DrawTexture(new Rect(0, lastRect.yMax + 4, Screen.width, 1), tex);
			GUI.color = Color.white;
		}

		//Used just after a textfield with no prefix to show an italic transparent text inside when empty
		public static void TextFieldComment(string check, string comment = "Comments..."){
			if (string.IsNullOrEmpty(check)){
				var lastRect = GUILayoutUtility.GetLastRect();
				GUI.color = new Color(1,1,1,0.3f);
				GUI.Label(lastRect, " <i>" + comment + "</i>");
				GUI.color = Color.white;
			}
		}


		///Custom Object and Attribute Drawers
		private static Dictionary<Type, CustomDrawer> objectDrawers = new Dictionary<Type, CustomDrawer>();
		static CustomDrawer GetCustomDrawer(Type type){
			CustomDrawer result = null;
			if (objectDrawers.TryGetValue(type, out result)){
				return result;
			}

			foreach( var drawerType in GetAssemblyTypes(typeof(CustomDrawer)) ){
				var args = drawerType.BaseType.GetGenericArguments();
				if (args.Length == 1 && args[0].IsAssignableFrom(type)){
					return objectDrawers[type] = Activator.CreateInstance(drawerType) as CustomDrawer;
				}
			}

			return objectDrawers[type] = new NoDrawer();
		}


		//Show an automatic editor gui for arbitrary objects, taking into account custom attributes
		public static void ShowAutoEditorGUI(object o){

			if (o == null){
				return;
			}

			foreach (var field in o.GetType().GetFields(BindingFlags.Instance | BindingFlags.Public)){
				field.SetValue(o, GenericField(field.Name, field.GetValue(o), field.FieldType, field, o));
				GUI.backgroundColor = Color.white;
			}

			GUI.enabled = Application.isPlaying;
			foreach (var prop in o.GetType().GetProperties(BindingFlags.Instance | BindingFlags.Public | BindingFlags.DeclaredOnly)){
				if (prop.CanRead && prop.CanWrite){
					if (prop.DeclaringType.GetField("<" + prop.Name + ">k__BackingField", BindingFlags.NonPublic | BindingFlags.Instance) != null){
						GenericField(prop.Name, prop.GetValue(o, null), prop.PropertyType, prop, o);
					}
				}
			}
			GUI.enabled = true;
		}


		//For generic automatic editors. Passing a MemberInfo will also check for attributes
		public static object GenericField(string name, object value, Type t, MemberInfo member = null, object context = null){

			if (t == null){
				GUILayout.Label("NO TYPE PROVIDED!");
				return value;
			}

			//Preliminary Hides
			if (typeof(Delegate).IsAssignableFrom(t)){
				return value;
			}

			name = name.SplitCamelCase();

			//

			IEnumerable<Attribute> attributes = new Attribute[0];
			if (member != null){

				//Hide class?
				if (t.GetCustomAttributes(typeof(HideInInspector), true ).FirstOrDefault() != null){
					return value;
				}

				attributes = member.GetCustomAttributes(true).Cast<Attribute>();

				//Hide field?
				if (attributes.Any(a => a is HideInInspector) ){
					return value;
				}

				//Is required?
				if (attributes.Any(a => a is RequiredFieldAttribute)){
					if ( (value == null || value.Equals(null) ) || 
						(t == typeof(string) && string.IsNullOrEmpty((string)value) ) ||
						(typeof(BBParameter).IsAssignableFrom(t) && (value as BBParameter).isNull) )
					{
						GUI.backgroundColor = lightRed;
					}
				}
			}


			if (member != null){
				var nameAtt = attributes.FirstOrDefault(a => a is NameAttribute) as NameAttribute;
				if (nameAtt != null){
					name = nameAtt.name;
				}

				if (context != null){
					var showAtt = attributes.FirstOrDefault(a => a is ShowIfAttribute) as ShowIfAttribute;
					if (showAtt != null){
						var targetField = context.GetType().GetField(showAtt.fieldName);
						if (targetField == null || targetField.FieldType != typeof(bool)){
							GUILayout.Label(string.Format("[ShowIf] Error: bool \"{0}\" does not exist.", showAtt.fieldName));
						} else {
							if ((bool)targetField.GetValue(context) != showAtt.show){
								return value;
							}
						}
					}
				}			
			}


			//Before everything check BBParameter
			if (typeof(BBParameter).IsAssignableFrom(t)){
				return BBParameterField(name, (BBParameter)value, false, member, context);
			}


			//Custom object drawers
			var objectDrawer = GetCustomDrawer(t);
			if (objectDrawer != null && !(objectDrawer is NoDrawer) ){
/*
				var field = member as FieldInfo;
				if (field != null && typeof(BBParameter).IsAssignableFrom(field.FieldType) ){
					var bbParam = field.GetValue(context);
					context = bbParam;
					member = bbParam.GetType().GetField("_value", BindingFlags.Instance | BindingFlags.NonPublic);
				}
*/
				return objectDrawer.DrawGUI(name, value, member as FieldInfo, null, context);
			}

			//Custom attribute drawers
			foreach(var att in attributes.OfType<CustomDrawerAttribute>()){
				var attributeDrawer = GetCustomDrawer(att.GetType());
				if (attributeDrawer != null && !(attributeDrawer is NoDrawer)){
					return attributeDrawer.DrawGUI(name, value, member as FieldInfo, att, context);
				}
			}
		

			//Then check UnityObjects
            if ( typeof(UnityObject).IsAssignableFrom(t) ) {
                if (t == typeof(Component) && (Component)value != null){
                    return ComponentField(name, (Component)value, typeof(Component));
                }
                return EditorGUILayout.ObjectField(name, (UnityObject)value, t, typeof(Component).IsAssignableFrom(t) || t == typeof(GameObject) );
		    }

		    //Force UnityObject field?
		    if (member != null && attributes.Any(a => a is ForceObjectFieldAttribute)){
		    	return EditorGUILayout.ObjectField(name, value as UnityObject, t, typeof(Component).IsAssignableFrom(t) || t == typeof(GameObject) );
		    }

			//Restricted popup values?
			if (member != null){
				var popAtt = attributes.FirstOrDefault(a => a is PopupFieldAttribute) as PopupFieldAttribute;
				if (popAtt != null){
					if (popAtt.staticPath != null){
						try
						{
							var typeName = popAtt.staticPath.Substring(0, popAtt.staticPath.LastIndexOf("."));
							var type = ReflectionTools.GetType( typeName, /*fallback?*/false );
							var start = popAtt.staticPath.LastIndexOf(".") + 1;
							var end = popAtt.staticPath.Length;
							var propName = popAtt.staticPath.Substring(start, end - start);
							var prop = type.GetProperty( propName, BindingFlags.Static | BindingFlags.Public );
							var propValue = prop.GetValue(null, null);
							var values = ((IEnumerable)propValue).Cast<object>().ToList();
							return Popup<object>(name, value, values);
						}
						catch
						{
							EditorGUILayout.LabelField(name, "[PopupField] attribute error!");
							return value;
						}
					}
					return Popup<object>(name, value, popAtt.values.ToList());
				}
			}


		    //Check Type of Type
			if (t == typeof(Type)){
				return Popup<Type>(name, (Type)value, UserTypePrefs.GetPreferedTypesList(typeof(object), true) );
			}

			//Check abstract
			if ( (value != null && value.GetType().IsAbstract) || (value == null && t.IsAbstract) ){
				EditorGUILayout.LabelField(name, string.Format("Abstract ({0})", t.FriendlyName()));
				return value;
			}

			//Create instance for some types
			if (value == null && !t.IsAbstract && !t.IsInterface && (t.IsValueType || t.GetConstructor(Type.EmptyTypes) != null || t.IsArray) ){
				if (t.IsArray){
					value = Array.CreateInstance(t.GetElementType(), 0);
				} else {
					value = Activator.CreateInstance(t);
				}
			}



			//Check the rest
			//..............
            if (t == typeof(string)){
				if (member != null){
					if (attributes.Any(a => a is TagFieldAttribute))
						return EditorGUILayout.TagField(name, (string)value);
					var areaAtt = attributes.FirstOrDefault(a => a is TextAreaFieldAttribute) as TextAreaFieldAttribute;
					if (areaAtt != null){
						GUILayout.Label(name);
						var areaStyle = new GUIStyle(GUI.skin.GetStyle("TextArea"));
						areaStyle.wordWrap = true;
						var s = EditorGUILayout.TextArea((string)value, areaStyle, GUILayout.Height(areaAtt.height));
						return s;
					}
				}

				return EditorGUILayout.TextField(name, (string)value);
			}

			if (t == typeof(bool))
				return EditorGUILayout.Toggle(name, (bool)value);

			if (t == typeof(int) || t == typeof(short) || t == typeof(uint) || t == typeof(ushort))
            {
				if (member != null){
					var sField = attributes.FirstOrDefault(a => a is SliderFieldAttribute) as SliderFieldAttribute;
					if (sField != null)
						return (int)EditorGUILayout.Slider(name, (int)value, (int)sField.left, (int)sField.right );
					if (attributes.Any(a => a is LayerFieldAttribute))
						return EditorGUILayout.LayerField(name, (int)value);
				}
                if(t == typeof(int))
                {
                    return EditorGUILayout.IntField(name, Convert.ToInt32(value));
                }
                else if (t == typeof(short))
                {
                    return Convert.ToInt16(EditorGUILayout.IntField(name, Convert.ToInt32(value)));
                }
                else if (t == typeof(uint))
                {
                    return Convert.ToUInt32(EditorGUILayout.IntField(name, Convert.ToInt32(value)));
                }
                else if (t == typeof(ushort))
                {
                    return Convert.ToUInt16(EditorGUILayout.IntField(name, Convert.ToInt32(value)));
                }
			}

			if (t == typeof(float)){
				if (member != null){
					var sField = attributes.FirstOrDefault(a => a is SliderFieldAttribute) as SliderFieldAttribute;
					if (sField != null)
						return EditorGUILayout.Slider(name, (float)value, sField.left, sField.right);
				}
				return EditorGUILayout.FloatField(name, (float)value);
			}

			if (t == typeof(byte)){
				return Convert.ToByte( Mathf.Clamp(EditorGUILayout.IntField(name, (byte)value), 0, 255) );
			}

			if (t == typeof(Vector2))
				return EditorGUILayout.Vector2Field(name, (Vector2)value);

			if (t == typeof(Vector3))
				return EditorGUILayout.Vector3Field(name, (Vector3)value);

			if (t == typeof(Vector4))
				return EditorGUILayout.Vector4Field(name, (Vector4)value);

			if (t == typeof(Quaternion)){
				var quat = (Quaternion)value;
				var vec4 = new Vector4(quat.x, quat.y, quat.z, quat.w);
				vec4 = EditorGUILayout.Vector4Field(name, vec4);
				return new Quaternion(vec4.x, vec4.y, vec4.z, vec4.w);
			}

			if (t == typeof(Color))
				return EditorGUILayout.ColorField(name, (Color)value);

			if (t == typeof(Rect))
				return EditorGUILayout.RectField(name, (Rect)value);

			if (t == typeof(AnimationCurve))
				return EditorGUILayout.CurveField(name, (AnimationCurve)value);

			if (t == typeof(Bounds))
				return EditorGUILayout.BoundsField(name, (Bounds)value);

			if (t == typeof(LayerMask))
				return LayerMaskField(name, (LayerMask)value);
            
			if (t.IsSubclassOf(typeof(System.Enum))){
#if UNITY_5				
				if (t.GetCustomAttributes(typeof(FlagsAttribute), true).FirstOrDefault() != null ){
					return EditorGUILayout.EnumMaskPopup(new GUIContent(name), (System.Enum)value);
				}
#endif
				return EditorGUILayout.EnumPopup(name, (System.Enum)value);
			}

			if (typeof(IList).IsAssignableFrom(t))
				return ListEditor(name, (IList)value, t, context);

			if (typeof(IDictionary).IsAssignableFrom(t))
				return DictionaryEditor(name, (IDictionary)value, t, context);


			//show nested class members recursively
			if (value != null && !t.IsEnum && !t.IsInterface){
	
				GUILayout.BeginVertical();
				EditorGUILayout.LabelField(name, t.FriendlyName());
				EditorGUI.indentLevel ++;
				ShowAutoEditorGUI(value);
				EditorGUI.indentLevel --;
				GUILayout.EndVertical();
		
			} else {

				EditorGUILayout.LabelField(name, string.Format("({0})", t.FriendlyName()));
			}
			
			return value;
		}
	}
}

#endif
