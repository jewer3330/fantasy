using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;


namespace ParadoxNotion{

	///Helper extension methods to work with NETFX_CORE as well as some other reflection helper extensions and utilities
	public static class ReflectionTools {

		private const BindingFlags flagsEverything = BindingFlags.Instance | BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic;

		private static Assembly[] _loadedAssemblies;
		private static Assembly[] loadedAssemblies{
        	get
        	{
        		if (_loadedAssemblies == null){

	        		#if NETFX_CORE

				    _loadedAssemblies = new List<Assembly>();
		 		    var folder = Windows.ApplicationModel.Package.Current.InstalledLocation;
				    var folderFilesAsync = folder.GetFilesAsync();
				    folderFilesAsync.AsTask().Wait();

				    foreach (var file in folderFilesAsync.GetResults()){
				        if (file.FileType == ".dll" || file.FileType == ".exe"){
				            try
				            {
				                var filename = file.Name.Substring(0, file.Name.Length - file.FileType.Length);
				                AssemblyName name = new AssemblyName { Name = filename };
				                Assembly asm = Assembly.Load(name);
				                _loadedAssemblies.Add(asm);
				            }
				            catch { continue; }
				        }
				    }

				    _loadedAssemblies = _loadedAssemblies.ToArray();

	        		#else

	        		_loadedAssemblies = AppDomain.CurrentDomain.GetAssemblies();

	        		#endif
	        	}

	        	return _loadedAssemblies;
        	}
        }

		//Alternative to Type.GetType to work with FullName instead of AssemblyQualifiedName when looking up a type by string
		//This also handles Generics and their arguments, assembly changes and namespace changes to some extend.
		private static Dictionary<string, Type> typeMap = new Dictionary<string, Type>();
		public static Type GetType(string typeFullName, bool fallbackNoNamespace = false, Type fallbackAssignable = null){

			if (string.IsNullOrEmpty(typeFullName)){
				return null;
			}

			Type type = null;
			if (typeMap.TryGetValue(typeFullName, out type)){
				return type;
			}

			//direct look up
			type = GetTypeDirect(typeFullName);
            if (type != null){
            	return typeMap[typeFullName] = type;
            }			

			LateLog(string.Format("<b>(Type Request)</b> Trying Fallback Type match for type '{0}'...\n<i>(This happens if the type can't be resolved by it's full assembly/namespace name)</i>", typeFullName), UnityEngine.LogType.Warning);

            //handle generics now
            type = TryResolveGenericType(typeFullName, fallbackNoNamespace, fallbackAssignable);
            if (type != null){
            	LateLog(string.Format("<b>(Type Request)</b> Fallback Type Resolved to '{0}'", type.FullName));
            	return typeMap[typeFullName] = type;
            }

            //make use of DeserializeFromAttribute
            type = TryResolveDeserializeFromAttribute(typeFullName);
            if (type != null){
            	LateLog(string.Format("<b>(Type Request)</b> Fallback Type Resolved to '{0}'", type.FullName));
            	return typeMap[typeFullName] = type;
            }

            if (fallbackNoNamespace){
	            //get type regardless namespace
	            type = TryResolveWithoutNamespace(typeFullName, fallbackAssignable);
	            if (type != null){
	            	LateLog(string.Format("<b>(Type Request)</b> Fallback Type Resolved to '{0}'", type.FullName));
	            	//we store the found type's.FullName in the cache (instead of provided name), so that other types dont fail.
	            	return typeMap[type.FullName] = type;
		        }
		    }

		    LateLog(string.Format("<b>(Type Request)</b> Type with name '{0}' could not be resolved.", typeFullName), UnityEngine.LogType.Error);

            return typeMap[typeFullName] = null;
		}

		//Utility to log in delay. This is not because GetType above (where this is used), can be called in OnAfterDeserialized.
		//As such using DebugLog is not possible without this trick.
		static void LateLog(object logMessage, UnityEngine.LogType logType = UnityEngine.LogType.Log){
			#if UNITY_EDITOR
			UnityEditor.EditorApplication.delayCall += ()=> { UnityEngine.Debug.logger.Log(logType, logMessage); };
			#endif
		}

		//direct type look up with it's FullName
		static Type GetTypeDirect(string typeFullName){
			var type = Type.GetType(typeFullName);
			if (type != null){
				return type;
			}

            for (var i = 0; i < loadedAssemblies.Length; i++){
            	var asm = loadedAssemblies[i];
                try {type = asm.GetType(typeFullName);}
                catch { continue; }
                if (type != null) {
                    return type;
                }
            }

            return null;
		}

		//Resolve generic types by their .FullName or .ToString
		//Remark: a generic's type .FullName returns a string where it's arguments only are instead printed as AssemblyQualifiedName.
        static Type TryResolveGenericType(string typeFullName, bool fallbackNoNamespace = false, Type fallbackAssignable = null){

        	//ensure that it is a generic type implementation, not a definition
        	if (typeFullName.Contains('`') == false || typeFullName.Contains('[') == false){
        		return null;
        	}

            try //big try/catch block cause maybe there is a bug. Hopefully not.
            {
                var quoteIndex = typeFullName.IndexOf('`');
                var genericTypeDefName = typeFullName.Substring(0, quoteIndex + 2);
                var genericTypeDef = GetType(genericTypeDefName, fallbackNoNamespace, fallbackAssignable);
                if (genericTypeDef == null){
                    return null;
                }

                int argCount = Convert.ToInt32( typeFullName.Substring(quoteIndex + 1, 1) );
                var content = typeFullName.Substring(quoteIndex + 2, typeFullName.Length - quoteIndex - 2);
                string[] split = null;
                if (content.StartsWith("[[")){ //this means that assembly qualified name is contained. Name was generated with FullName.
                    var startIndex = typeFullName.IndexOf("[[") + 2;
                    var endIndex = typeFullName.LastIndexOf("]]");
                    content = typeFullName.Substring(startIndex, endIndex - startIndex);
                    split = content.Split(new string[]{"],["}, argCount, StringSplitOptions.RemoveEmptyEntries).ToArray();
                } else { //this means that the name was generated with type.ToString().
                    var startIndex = typeFullName.IndexOf('[') + 1;
                    var endIndex = typeFullName.LastIndexOf(']');
                    content = typeFullName.Substring(startIndex, endIndex - startIndex);
                    split = content.Split(new char[]{','}, argCount, StringSplitOptions.RemoveEmptyEntries).ToArray();

                }

                var argTypes = new Type[argCount];
                for (var i = 0; i < split.Length; i++){
                    var subName = split[i];
                    if (!subName.Contains('`') && subName.Contains(',')){ //remove assembly info since we work with FullName, but only if it's not yet another generic.
                        subName = subName.Substring(0, subName.IndexOf(','));
                    }
					
					#if !NETFX_CORE
					Type constrainType = null;
					if (fallbackNoNamespace){
						var arg = genericTypeDef.RTGetGenericArguments()[i];
						var constrains = arg.GetGenericParameterConstraints();
						constrainType = constrains.Length == 0? typeof(object) : constrains[0];
	                }
					var argType = GetType(subName, fallbackNoNamespace, constrainType);

					#else

					var argType = GetType(subName);

					#endif

                    if (argType == null){
                        return null;
                    }
                    argTypes[i] = argType;
                }

                return genericTypeDef.RTMakeGenericType(argTypes);                
            }

            catch (Exception e)
            {
                LateLog("<b>(Type Request)</b> BUG (Please report this): " + e.Message, UnityEngine.LogType.Error);
                return null;
            }
        }

        //uterly slow, but only happens when we have a null type
        static Type TryResolveDeserializeFromAttribute(string typeName){
            var allTypes = GetAllTypes();
            for (var i = 0; i < allTypes.Length; i++){
            	var t = allTypes[i];
            	var att = t.RTGetAttribute<Serialization.DeserializeFromAttribute>(false);
            	if (att != null && att.previousTypeNames.Any(n => n == typeName)){
            		return t;
            	}
            }
            return null;
        }

		//fallback type look up with it's FullName. This is slow.
		static Type TryResolveWithoutNamespace(string typeName, Type fallbackAssignable = null){

            //dont handle generic implementations this way (still handles definitions though).
            if (typeName.Contains('`') && typeName.Contains('[')){
            	return null;
            }

            //remove assembly info if any
            if (typeName.Contains(',')){
            	typeName = typeName.Substring(0, typeName.IndexOf(','));
            }

            //ensure strip namespace
    		if (typeName.Contains('.')){
	    		var dotIndex = typeName.LastIndexOf('.') + 1;
				typeName = typeName.Substring(dotIndex, typeName.Length - dotIndex);
			}

            //check all types
            var allTypes = GetAllTypes();
            for (var i = 0; i < allTypes.Length; i++){
            	var t = allTypes[i];
            	if (t.Name == typeName && (fallbackAssignable == null || fallbackAssignable.RTIsAssignableFrom(t)) ){
            		return t;
            	}
            }
	        return null;
		}


		///Get every single type in loaded assemblies
		private static Type[] _allTypes;
		public static Type[] GetAllTypes(){
			if (_allTypes != null){
				return _allTypes;
			}

			var result = new List<Type>();
			for (var i = 0; i < loadedAssemblies.Length; i++){
				var asm = loadedAssemblies[i];
				try {result.AddRange(asm.RTGetExportedTypes());}
				catch { continue; }
			}
			return _allTypes = result.ToArray();
		}

		private static Type[] RTGetExportedTypes(this Assembly asm){
			#if NETFX_CORE
			return asm.ExportedTypes.ToArray();
			#else
			return asm.GetExportedTypes();
			#endif
		}

		///Get a friendly name for the type
		public static string FriendlyName(this Type t, bool trueSignature = false){

			if (t == null){
				return null;
			}

			if (!trueSignature && t == typeof(UnityEngine.Object)){
				return "UnityObject";
			}

			var s = trueSignature? t.FullName : t.Name;
			if (!trueSignature){
				if (s == "Single"){ s = "Float"; }
				if (s == "Int32"){ s = "Integer"; }
			}

			if ( t.RTIsGenericParameter() ){
				s = "T";
			}

			if ( t.RTIsGenericType() ){
				
				// s = (trueSignature? t.Namespace + "." : "") + t.Name;
				s = trueSignature? t.FullName : t.Name;

				var args= t.RTGetGenericArguments();
				
				if (args.Length != 0){
				
					s = s.Replace("`" + args.Length.ToString(), "");

					s += "<";
					for (var i= 0; i < args.Length; i++){
						s += (i == 0? "":", ") + args[i].FriendlyName(trueSignature);
					}
					s += ">";
				}
			}

			return s;			
		}

		///Get a full signature string name for a method
		public static string SignatureName(this MethodInfo method){
			var parameters = method.GetParameters();
			var finalName = (method.IsStatic? "static " : "") + method.Name + " (";
			for (var i = 0; i < parameters.Length; i++){
				var p = parameters[i];
				finalName += (p.IsOut? "out " : "") + p.ParameterType.FriendlyName() + (i < parameters.Length-1? ", " : "");
			}
			finalName += ") : " + method.ReturnType.FriendlyName();
			return finalName;
		}


		public static Type RTReflectedType(this Type type){
			#if NETFX_CORE
			return type.GetTypeInfo().DeclaringType; //no way to get ReflectedType here that I know of...
			#else
			return type.ReflectedType;
			#endif			
		}

		public static Type RTReflectedType(this MemberInfo member){
			#if NETFX_CORE
			return member.DeclaringType; //no way to get ReflectedType here that I know of...
			#else
			return member.ReflectedType;
			#endif						
		}


		public static bool RTIsAssignableFrom(this Type type, Type second){
			#if NETFX_CORE
			return type.GetTypeInfo().IsAssignableFrom(second.GetTypeInfo());
			#else
			return type.IsAssignableFrom(second);
			#endif
		}

		public static bool RTIsAbstract(this Type type){
			#if NETFX_CORE
			return type.GetTypeInfo().IsAbstract;
			#else
			return type.IsAbstract;
			#endif			
		}

		public static bool RTIsValueType(this Type type){
			#if NETFX_CORE
			return type.GetTypeInfo().IsValueType;
			#else
			return type.IsValueType;
			#endif						
		}

		public static bool RTIsArray(this Type type){
			#if NETFX_CORE
			return type.GetTypeInfo().IsArray;
			#else
			return type.IsArray;
			#endif			
		}

		public static bool RTIsInterface(this Type type){
			#if NETFX_CORE
			return type.GetTypeInfo().IsInterface;
			#else
			return type.IsInterface;
			#endif			
		}

		public static bool RTIsSubclassOf(this Type type, Type other){
			#if NETFX_CORE
			return type.GetTypeInfo().IsSubclassOf(other);
			#else
			return type.IsSubclassOf(other);
			#endif						
		}

		public static bool RTIsGenericParameter(this Type type){
			#if NETFX_CORE
			return type.GetTypeInfo().IsGenericParameter;
			#else
			return type.IsGenericParameter;
			#endif									
		}

		public static bool RTIsGenericType(this Type type){
			#if NETFX_CORE
			return type.GetTypeInfo().IsGenericType;
			#else
			return type.IsGenericType;
			#endif						
		}


		public static MethodInfo RTGetGetMethod(this PropertyInfo prop){
			#if NETFX_CORE
			return prop.GetMethod;
			#else
			return prop.GetGetMethod();
			#endif			
		}

		public static MethodInfo RTGetSetMethod(this PropertyInfo prop){
			#if NETFX_CORE
			return prop.SetMethod;
			#else
			return prop.GetSetMethod();
			#endif
		}

		public static FieldInfo RTGetField(this Type type, string name){
			#if NETFX_CORE
			return type.GetRuntimeFields().FirstOrDefault(f => f.Name == name);
			#else
			return type.GetField(name, flagsEverything);
			#endif
		}

		public static PropertyInfo RTGetProperty(this Type type, string name){
			#if NETFX_CORE
			return type.GetRuntimeProperties().FirstOrDefault(p => p.Name == name);
			#else
			return type.GetProperty(name, flagsEverything);
			#endif
		}

		public static MethodInfo RTGetMethod(this Type type, string name){
			#if NETFX_CORE
			return type.GetRuntimeMethods().FirstOrDefault(m => m.Name == name);
			#else
			return type.GetMethod(name, flagsEverything);
			#endif
		}

		public static MethodInfo RTGetMethod(this Type type, string name, Type[] paramTypes){
			#if NETFX_CORE
			return type.GetRuntimeMethod(name, paramTypes);
			#else
			return type.GetMethod(name, paramTypes);
			#endif
		}

		public static EventInfo RTGetEvent(this Type type, string name){
			#if NETFX_CORE
			return type.GetRuntimeEvents().FirstOrDefault(e => e.Name == name);
			#else
			return type.GetEvent(name, flagsEverything);
			#endif			
		}

		public static MethodInfo RTGetDelegateMethodInfo(this Delegate del){
			#if NETFX_CORE
			return del.GetMethodInfo();
			#else
			return del.Method;
			#endif			
		}

		
		//cache the fields since it's used regularely
		private static Dictionary<Type, FieldInfo[]> _typeFields = new Dictionary<Type, FieldInfo[]>();
		public static FieldInfo[] RTGetFields(this Type type){

			FieldInfo[] fields;
			if (!_typeFields.TryGetValue(type, out fields)){

				#if NETFX_CORE
				fields = type.GetRuntimeFields().ToArray();
				#else
				fields = type.GetFields(flagsEverything);
				#endif

				_typeFields[type] = fields;
			}

			return fields;
		}

		public static PropertyInfo[] RTGetProperties(this Type type){
			#if NETFX_CORE
			return type.GetRuntimeProperties().ToArray();
			#else
			return type.GetProperties(flagsEverything);
			#endif
		}

		public static MethodInfo[] RTGetMethods(this Type type){
			#if NETFX_CORE
			return type.GetRuntimeMethods().ToArray();
			#else
			return type.GetMethods(flagsEverything);
			#endif
		}



		//
		public static T RTGetAttribute<T>(this Type type, bool inherited) where T : Attribute {
			#if NETFX_CORE
			return (T)type.GetTypeInfo().GetCustomAttributes(typeof(T), inherited).FirstOrDefault();
			#else
			return (T)type.GetCustomAttributes(typeof(T), inherited).FirstOrDefault();
			#endif			
		}

		public static T RTGetAttribute<T>(this MemberInfo member, bool inherited) where T : Attribute{
			#if NETFX_CORE
			return (T)member.GetCustomAttributes(typeof(T), inherited).FirstOrDefault();
			#else
			return (T)member.GetCustomAttributes(typeof(T), inherited).FirstOrDefault();
			#endif			
		}
		//

		public static Type RTMakeGenericType(this Type type, Type[] typeArgs){
			#if NETFX_CORE
            return type.GetTypeInfo().MakeGenericType(typeArgs);
			#else
            return type.MakeGenericType(typeArgs);
			#endif			
		}

        public static Type[] RTGetGenericArguments(this Type type){
			#if NETFX_CORE
            return type.GetTypeInfo().GenericTypeArguments;
			#else
            return type.GetGenericArguments();
			#endif
        }

        public static Type[] RTGetEmptyTypes(){
			#if NETFX_CORE
			return new Type[0];
			#else
            return Type.EmptyTypes;
			#endif
        }


        public static T RTCreateDelegate<T>(this MethodInfo method, object instance){
			return (T)(object)method.RTCreateDelegate(typeof(T), instance);
        }

        public static Delegate RTCreateDelegate(this MethodInfo method, Type type, object instance){
			#if NETFX_CORE
			return method.CreateDelegate(type, instance);
			#else
            return Delegate.CreateDelegate(type, instance, method);
			#endif
        }

        ///Utility to determine obsolete members quicker. Also handles property accessor methods.
        public static bool IsObsolete(this MemberInfo member){
        	if (member is MethodInfo){
        		var m = (MethodInfo)member;
	            if (m.Name.StartsWith("get_") || m.Name.StartsWith("set_")){
	                member = m.DeclaringType.RTGetProperty(m.Name.Replace("get_", "").Replace("set_", "") );
	            }
        	}
        	return member.RTGetAttribute<System.ObsoleteAttribute>(true) != null;
        }

		///Determines whether the field is read only
		public static bool IsReadOnly(this FieldInfo field){
			return field.IsInitOnly || field.IsLiteral;
		}

        //BaseDefinition for PropertyInfos.
	    public static PropertyInfo GetBaseDefinition(this PropertyInfo propertyInfo) {

	    	#if NETFX_CORE

	    	throw new NotImplementedException();

	    	#else

	        var method = propertyInfo.GetAccessors(true)[0];
	        if (method == null){
	            return null;
	        }
	 
	        var baseMethod = method.GetBaseDefinition();
	        if (baseMethod == method){
	            return propertyInfo;
	        }
	 
	        var arguments = propertyInfo.GetIndexParameters().Select(p => p.ParameterType).ToArray();
	        return baseMethod.DeclaringType.GetProperty(propertyInfo.Name, flagsEverything, null, propertyInfo.PropertyType, arguments, null);

	        #endif
	    }

	    //BaseDefinition for FieldInfo. Not exactly correct but here for consistency.
	    public static FieldInfo GetBaseDefinition(this FieldInfo fieldInfo){
	    	return fieldInfo.DeclaringType.RTGetField(fieldInfo.Name);
	    }

	}
}