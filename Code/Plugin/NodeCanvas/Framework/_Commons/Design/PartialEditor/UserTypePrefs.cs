#if UNITY_EDITOR

using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using UnityEngine;
using System;
using System.Reflection;
using System.Collections;


namespace ParadoxNotion.Design{

	/// <summary>
	/// A collection of user prefered types and associated colors (stored in EditorPrefs)
	/// </summary>
    public static class UserTypePrefs {

		private static List<Type> _preferedTypes;


		//The default prefered types list to be shown wherever a type is important
		private static string defaultPreferedTypesList{
			get
			{
				var typeList = new List<Type>{

					typeof(object),

					//Primitives
					typeof(System.Type),
					typeof(string),
					typeof(float),
					typeof(int),
					typeof(bool),

					//Unity basics
					typeof(Vector2),
					typeof(Vector3),
					typeof(Vector4),
					typeof(Quaternion),
					typeof(Color),
					typeof(LayerMask),
					typeof(AnimationCurve),

					//Unity functional classes
					typeof(Debug),
					typeof(Application),
					typeof(Mathf),
					typeof(Physics),
					typeof(Physics2D),
					typeof(Input),
					typeof(UnityEngine.AI.NavMesh),
					typeof(PlayerPrefs),
					typeof(UnityEngine.Random),
					typeof(Time),

					//Unity Objects
					typeof(UnityEngine.Object),
					typeof(GameObject),
					typeof(Transform),
					typeof(Animation),
					typeof(Animator),
					typeof(Rigidbody),
					typeof(Rigidbody2D),
					typeof(Collider),
					typeof(Collider2D),
					typeof(UnityEngine.AI.NavMeshAgent),
					typeof(CharacterController),
					typeof(AudioSource),
					typeof(Camera),
					typeof(Light),

					//UGUI
					typeof(UnityEngine.UI.Button),
					typeof(UnityEngine.UI.Slider),

					//Unity Asset Objects
					typeof(Texture2D),
					typeof(Sprite),
					typeof(AudioClip),
					typeof(AnimationClip)
				};

				return string.Join("|", typeList.OrderBy(t => t.Name).OrderBy(t => t.Namespace).Select(t => t.FullName).ToArray() );
			}
		}

		//These types will be filtered out when requesting types with 'filterOutFunctionalOnlyTypes' true.
		private static readonly List<Type> filterFunctionalTypes = new List<Type>{
			typeof(Debug),
			typeof(Application),
			typeof(Mathf),
			typeof(Physics),
			typeof(Physics2D),
			typeof(Input),
			typeof(UnityEngine.AI.NavMesh),
			typeof(PlayerPrefs),
			typeof(UnityEngine.Random),
			typeof(Time)
		};

		/// Get the prefered types set by the user.
		public static List<Type> GetPreferedTypesList(Type baseType, bool filterOutFunctionalOnlyTypes = false){

			if (_preferedTypes == null){
				_preferedTypes = new List<Type>();
				foreach(var s in EditorPrefs.GetString("ParadoxNotion.PreferedTypes", defaultPreferedTypesList).Split('|')){
					var resolvedType = ReflectionTools.GetType(s, /*fallback?*/ true);
					if (resolvedType != null){
						_preferedTypes.Add( resolvedType );
					}
				}
				//re-write back, so that fallback type resolved are saved
				SetPreferedTypesList(_preferedTypes);
			}

			var types = _preferedTypes
			.Where(t => baseType.IsAssignableFrom(t) && !t.IsGenericType && (filterOutFunctionalOnlyTypes == false || !filterFunctionalTypes.Contains(t) ) )
			.OrderBy(t => t.Name)
			.OrderBy(t => t.Namespace)
			.ToList();

			return types;
		}

		///Set the prefered types list for the user
		public static void SetPreferedTypesList(List<Type> types){
			var joined = string.Join("|", types.Where(t => t != null).Select(t => t.FullName).ToArray() );
			EditorPrefs.SetString("ParadoxNotion.PreferedTypes", joined);
			_preferedTypes = types;
		}

		///Reset the prefered types to the default ones
		public static void ResetTypeConfiguration(){
			EditorPrefs.SetString("ParadoxNotion.PreferedTypes", defaultPreferedTypesList);
			_preferedTypes = null;
		}

		///Append a type to the list
		public static void AddType(Type type){
			var current = GetPreferedTypesList(typeof(object));
			if (!current.Contains(type)){
				current.Add(type);
			}
			SetPreferedTypesList(current);
		}

		//A Type to color lookup
		private static readonly Dictionary<Type, Color> typeColors = new Dictionary<Type, Color>()
		{
			{typeof(bool),              new Color(1,0.4f,0.4f)},
			{typeof(float),             new Color(0.6f,0.6f,1)},
			{typeof(int),               new Color(0.5f,1,0.5f)},
			{typeof(string),            new Color(0.7f,0.5f,0.5f)},
			{typeof(Vector2),           new Color(1f,0.7f,0.2f)},
			{typeof(Vector3),           new Color(1f,0.7f,0.2f)},
			{typeof(Vector4),           new Color(1f,0.7f,0.2f)},
			{typeof(Quaternion),		new Color(1f,0.7f,0.2f)},
			{typeof(GameObject),		new Color(0.537f, 0.415f, 0.541f)},
			{typeof(UnityEngine.Object), Color.grey}
		};

		///Get the color preference for a type
		public static Color GetTypeColor(Type type){
			
			if (!EditorGUIUtility.isProSkin)
				return Color.white;
			
			if (type == null)
				return Color.red;
			
			if (typeColors.ContainsKey(type))
				return typeColors[type];

			foreach (var pair in typeColors){
				
				if (pair.Key.IsAssignableFrom(type))
					return typeColors[type] = pair.Value;
				
				if (typeof(IEnumerable).IsAssignableFrom(type)){
					if (type.IsGenericType)
						return typeColors[type] = GetTypeColor( type.GetGenericArguments()[0] );
					if (type.IsArray)
						return typeColors[type] = GetTypeColor( type.GetElementType() );
				}
			}
			
			return typeColors[type] = new Color(1,1,1,0.8f);
		}

		///Get the hex color preference for a type
		public static string GetTypeHexColor(Type type){
			if (!EditorGUIUtility.isProSkin){
				return "#000000";
			}
			return ColorToHex(GetTypeColor(type));
		}

		static string ColorToHex(Color32 color){
			return ("#" + color.r.ToString("X2") + color.g.ToString("X2") + color.b.ToString("X2")).ToLower();
		}
		 
		static Color HexToColor(string hex){
			var r = byte.Parse(hex.Substring(0,2), System.Globalization.NumberStyles.HexNumber);
			var g = byte.Parse(hex.Substring(2,2), System.Globalization.NumberStyles.HexNumber);
			var b = byte.Parse(hex.Substring(4,2), System.Globalization.NumberStyles.HexNumber);
			return new Color32(r,g,b, 255);
		}
	}
}

#endif