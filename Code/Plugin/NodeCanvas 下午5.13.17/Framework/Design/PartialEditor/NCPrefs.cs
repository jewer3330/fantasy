#if UNITY_EDITOR

using UnityEditor;
using ParadoxNotion.Serialization;

namespace NodeCanvas.Editor{

	///NC framework preferences
	public static class NCPrefs {

		[System.Serializable]
		class SerializedData{
			public bool showNodeInfo               = true;
			public bool isLocked                   = false;
			public bool showIcons                  = true;
			public ConnectionStyle connectionStyle = ConnectionStyle.Smooth;
			public bool doSnap                     = false;
			public bool showTaskSummary            = true;
			public bool showBlackboard             = true;
			public bool showNodePanel              = true;
			public bool showComments               = true;
			public bool hierarchicalMove           = false;
			public bool useExternalInspector       = false;
			public bool showWelcomeWindow          = true;
			public bool logEvents                  = true;
			public bool useBrowser                 = true;
			public bool breakpointPauseEditor      = true;
		}

		private static SerializedData _data;
		private static SerializedData data{
			get
			{
				if (_data == null){
					var pref = EditorPrefs.GetString("NodeCanvas.EditorPreferences");
					if (!string.IsNullOrEmpty(pref)){
						_data = JSONSerializer.Deserialize<SerializedData>(pref);
					}
					if (_data == null){
						_data = new SerializedData();
					}
				}
				return _data;
			}
		}

		public enum ConnectionStyle
		{
			Smooth,
			Stepped,
			Straight
		}

		public static bool showNodeInfo{
			get {return data.showNodeInfo;}
			set {if (data.showNodeInfo != value){ data.showNodeInfo = value; Save(); } }
		}

		public static bool isLocked{
			get {return data.isLocked;}
			set {if (data.isLocked != value){ data.isLocked = value; Save(); } }
		}

		public static bool showIcons{
			get {return data.showIcons;}
			set {if (data.showIcons != value){ data.showIcons = value; Save(); } }
		}

		public static ConnectionStyle connectionStyle{
			get {return data.connectionStyle;}
			set {if (data.connectionStyle != value){ data.connectionStyle = value; Save(); } }
		}

		public static bool doSnap{
			get {return data.doSnap;}
			set {if (data.doSnap != value){ data.doSnap = value; Save(); } }
		}

		public static bool showTaskSummary{
			get {return data.showTaskSummary;}
			set {if (data.showTaskSummary != value){ data.showTaskSummary = value; Save(); } }
		}

		public static bool showBlackboard{
			get {return data.showBlackboard;}
			set {if (data.showBlackboard != value){ data.showBlackboard = value; Save(); } }
		}

		public static bool showNodePanel{
			get {return data.showNodePanel;}
			set {if (data.showNodePanel != value){ data.showNodePanel = value; Save(); } }
		}

		public static bool showComments{
			get {return data.showComments;}
			set {if (data.showComments != value){ data.showComments = value; Save(); } }
		}

		public static bool hierarchicalMove{
			get {return data.hierarchicalMove;}
			set {if (data.hierarchicalMove != value){ data.hierarchicalMove = value; Save(); } }
		}

		public static bool useExternalInspector{
			get {return data.useExternalInspector;}
			set {if (data.useExternalInspector != value){ data.useExternalInspector = value; Save(); } }
		}

		public static bool showWelcomeWindow{
			get {return data.showWelcomeWindow;}
			set {if (data.showWelcomeWindow != value){ data.showWelcomeWindow = value; Save(); } }
		}

		public static bool logEvents{
			get {return data.logEvents;}
			set {if (data.logEvents != value){ data.logEvents = value; Save(); } }
		}

		public static bool useBrowser{
			get {return data.useBrowser;}
			set {if (data.useBrowser != value){ data.useBrowser = value; Save(); } }
		}

		public static bool breakpointPauseEditor{
			get {return data.breakpointPauseEditor;}
			set {if (data.breakpointPauseEditor != value){ data.breakpointPauseEditor = value; Save(); } }
		}

		static void Save(){
			EditorPrefs.SetString("NodeCanvas.EditorPreferences", JSONSerializer.Serialize(typeof(SerializedData), data));
		}
	}
}

#endif