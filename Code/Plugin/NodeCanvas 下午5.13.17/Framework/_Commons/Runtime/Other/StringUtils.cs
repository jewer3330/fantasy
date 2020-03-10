using UnityEngine;
using System.Collections;
using System.Linq;
using System;

namespace ParadoxNotion{

	public static class StringUtils {

		///Convert camelCase to words as the name implies.
		public static string SplitCamelCase(this string s){
			if (string.IsNullOrEmpty(s)) return s;
			s = s.Replace("_", " ");
			s = char.ToUpper(s[0]) + s.Substring(1);
			return System.Text.RegularExpressions.Regex.Replace(s, "(?<=[a-z])([A-Z])", " $1").Trim();
		}

		///Gets only the capitals of the string trimmed.
		public static string GetCapitals(this string s){
	    	if (string.IsNullOrEmpty(s)){
	    		return string.Empty;
	    	}
	    	var result = "";
	    	foreach(var c in s){
	    		if (char.IsUpper(c)){
	    			result += c.ToString();
	    		}
	    	}
	    	result = result.Trim();
	    	return result;			
		}

		///Returns the alphabet letter based on it's index.
		public static string GetAlphabetLetter(int index){
			if (index < 0){
				return null;
			}

			var letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			if (index >= letters.Length){
				return index.ToString();
			}

			return letters[index].ToString();
		}

		///A more complete ToString version
		public static string ToStringAdvanced(this object o) {

			if (o == null || o.Equals(null)){
				return "NULL";
			}

			if (o is string){
				return string.Format("\"{0}\"", (string)o);
			}

			if (o is UnityEngine.Object){
				return (o as UnityEngine.Object).name;
			}

			var t = o.GetType();
			if (t.RTIsSubclassOf(typeof(System.Enum))) {
				var flagAtt = t.RTGetAttribute<System.FlagsAttribute>(true);
				if (flagAtt != null) {
					var value = "";
					var cnt = 0;
					var list = System.Enum.GetValues(t);
					foreach (var e in list) {
						if ((Convert.ToInt32(e) & Convert.ToInt32(o)) == Convert.ToInt32(e)) {
							cnt++;
							if (value == "") {
								value = e.ToString();
							} else {
								value = "Mixed...";
							}
						}
					}
					if (cnt == 0) {
						return "Nothing";
					}
					if (cnt == list.Length){
						return "Everything";
					}
					return value;
				}
			}

			return o.ToString();
		}
	}
}