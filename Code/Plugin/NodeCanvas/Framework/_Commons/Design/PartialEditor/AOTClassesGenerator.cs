#if UNITY_EDITOR && !UNITY_WEBPLAYER

using System;
using System.IO;
using System.Text;
using System.Linq;
using UnityEngine;
using UnityEditor;
using System.Collections.Generic;
using System.Reflection;
using ParadoxNotion;

namespace ParadoxNotion.Design{

	public static class AOTClassesGenerator {

		static readonly List<Type> defaultSpoofTypes = new List<Type>{
			typeof(bool),
			typeof(float),
			typeof(int),
			typeof(Vector2),
			typeof(Vector3),
			typeof(Vector4),
			typeof(Quaternion),
			typeof(Keyframe),
			typeof(Bounds),
			typeof(Color),
			typeof(Rect),
			typeof(ContactPoint),
			typeof(ContactPoint2D),
			typeof(Collision),
			typeof(Collision2D),
			typeof(RaycastHit),
			typeof(RaycastHit2D),
			typeof(Space),
		};

		
		public static void GenerateAOTClasses(string path){

			if (string.IsNullOrEmpty(path)){
				return;
			}

			var spoofTypes = defaultSpoofTypes;
			spoofTypes.AddRange(UserTypePrefs.GetPreferedTypesList(typeof(object), true).Where(t => t.IsValueType && !spoofTypes.Contains(t)) );
			var types = EditorUtils.GetAssemblyTypes(typeof(object)).Where(t => t.RTGetAttribute<SpoofAOTAttribute>(true) != null).ToList();

			var nClasses = 0;
			var nMethods = 0;

			var sb = new StringBuilder();

			sb.AppendLine("#pragma warning disable 0219, 0168, 0612");
			sb.AppendLine("namespace ParadoxNotion.Internal{");
			sb.AppendLine();
			sb.AppendLine("	//Auto generated classes for AOT support, where using undeclared generic classes with value types is limited. These are not actualy used but rather just declared for the compiler");
			sb.AppendLine("	class AOTDummy{");
			sb.AppendLine();
			sb.AppendLine("		object o = null;");



			foreach(var type in types){
				if (!type.IsAbstract && type.IsGenericTypeDefinition && type.GetGenericArguments().Length == 1){
					var constrains = type.GetGenericArguments()[0].GetGenericParameterConstraints();
					if ( constrains.Length == 0 || constrains[0].IsValueType ){

						if (typeof(Delegate).IsAssignableFrom(type)){
							nClasses++;
							sb.AppendLine(string.Format("		void {0}()", type.FriendlyName(true).Replace(".", "_").Replace("<T>", "_Delegate") ) + "{" );
							foreach(var spoofType in spoofTypes){
								var a = type.FriendlyName(true).Replace("<T>", "<" + spoofType.FullName + ">");
								var b = "_" + type.FriendlyName().Replace("<T>", "_" + spoofType.Name);
								sb.AppendLine(string.Format("			{0} {1} = null;", a, b ));
							}
							sb.AppendLine("		}");

						} else {

							foreach(var spoofType in spoofTypes){
								nClasses++;
								sb.AppendLine(string.Format("		class {0} : {1}",
									type.FriendlyName(true).Replace(".", "_").Replace("<T>", "_" + spoofType.Name),
									type.FriendlyName(true).Replace("<T>", "<" + spoofType.FullName + ">") ) + "{}");
							}
						}

						sb.AppendLine();
					}
				}				
			}

			foreach(var type in types){
				var index = 0;
				foreach(var method in type.GetMethods(BindingFlags.Instance | BindingFlags.Static | BindingFlags.Public | BindingFlags.DeclaredOnly)){
					if (method.IsGenericMethodDefinition && method.GetGenericArguments().Length == 1){

						var constrains = method.GetGenericArguments()[0].GetGenericParameterConstraints();
						if (constrains.Length == 0 || constrains[0].IsValueType){

							index++;

							var decType = method.DeclaringType;
							var varName = "_" + decType.Name;
							sb.AppendLine(string.Format("		void {0}_{1}_{2}()", decType.FullName.Replace(".", "_"), method.Name, index) + " {" );
							if (!method.IsStatic){
								sb.AppendLine(string.Format("			{0} {1} = null;", decType.FullName, varName));
							}

							foreach(var spoofType in spoofTypes){
								nMethods++;
								var a = method.IsStatic? decType.FullName : varName;
								var b = method.Name;
								var c = spoofType.FullName;
								var paramsString = "";
								var parameters = method.GetParameters();
								for (var i = 0; i < parameters.Length; i++){
									var parameter = parameters[i];
									var toString = parameter.ParameterType.FullName;
									if (parameter.ParameterType.IsGenericParameter){
										toString = spoofType.FullName;
									}
									if (parameter.ParameterType.IsGenericType){
										toString = parameter.ParameterType.FriendlyName(true).Replace("<T>", "<" + spoofType.FullName + ">");
										toString = toString.Replace("[[T]]", "");
									}
									paramsString += string.Format("({0})o", toString);
									if (i < parameters.Length-1){
										paramsString += ", ";
									}
								}
								var d = paramsString;
								sb.AppendLine(string.Format("			{0}.{1}<{2}>( {3} );", a, b, c, d));
							}

							sb.AppendLine("		}");
							sb.AppendLine();
						}
					}
				}
			}

			//custom stuff
			sb.AppendLine("		void CustomSpoof(){");
			foreach(var spoofType in spoofTypes){
				sb.AppendLine(string.Format("			System.Action<{0}> Action_{1};", spoofType.FullName, spoofType.Name));
				sb.AppendLine(string.Format("			System.Func<{0}> Func_{1};", spoofType.FullName, spoofType.Name));
				sb.AppendLine(string.Format("			System.Collections.Generic.IList<{0}> List_{1};", spoofType.FullName, spoofType.Name));
				sb.AppendLine(string.Format("			System.Collections.Generic.IDictionary<System.String, {0}> Dict_{1};", spoofType.FullName, spoofType.Name));
			}
			sb.AppendLine("		}");

			sb.AppendLine("	}");
			sb.AppendLine("}");
			sb.AppendLine();
			sb.AppendLine(string.Format("//{0} Classes | {1} Methods", nClasses, nMethods));
			sb.AppendLine("#pragma warning restore 0219, 0168, 0612");

			File.WriteAllText(path, sb.ToString());
		}





		public static void GenerateLinkXML(string path){

			if (string.IsNullOrEmpty(path)){
				return;
			}

			var spoofTypes = UserTypePrefs.GetPreferedTypesList(typeof(UnityEngine.Object), true);
			var pairs = new Dictionary<string, List<Type>>();
			foreach(var type in spoofTypes){
				var asmName = type.Assembly.GetName().Name;
				if (!pairs.ContainsKey(asmName)){
					pairs[asmName] = new List<Type>();
				}
				pairs[asmName].Add(type);
			}

			var sb = new StringBuilder();

			sb.AppendLine("<linker>");

			foreach(var pair in pairs){
				sb.AppendLine(string.Format("	<assembly fullname=\"{0}\">", pair.Key) );

				foreach(var type in pair.Value){
					sb.AppendLine("		<type fullname=\"" + type.FullName + "\" preserve=\"all\"/>");
				}

				sb.AppendLine("	</assembly>");
			}

			sb.AppendLine("</linker>");
			File.WriteAllText(path, sb.ToString());
		}
	}
}

#endif