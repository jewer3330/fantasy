#if UNITY_EDITOR

using UnityEngine;
using UnityEditor;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Reflection;
using System.Linq;
using ParadoxNotion.Serialization;

namespace ParadoxNotion.Design{

	///Proviving a GenericMenu, shows a complete popup browser.
	public class CompleteContextMenu : PopupWindowContent {

		enum SearchMode{
			Contains,
			StartsWith
		}

		//class node used in browser
		class Node {
			public EditorUtils.MenuItemInfo item = null;
			public Node parent = null;
			public Dictionary<string, Node> children = new Dictionary<string, Node>();
			public string name = null;
			public bool unfolded = true;

			private string _fullPath = null;
			public string fullPath{
				get
				{
					if (_fullPath != null){
						return _fullPath;
					}

					_fullPath = name;
					var p = parent;
					while (p != null){
						_fullPath = p.name + "/" + _fullPath;
						p = p.parent;
					}
					return _fullPath;					
				}
			}

			public bool isLeaf{ //only leafs have menu items
				get {return item != null;}
			}

			private bool? _isFavorite;
			public bool isFavorite{
				get
				{	
					if (_isFavorite != null){
						return (bool)_isFavorite;
					}
					_isFavorite = CompleteContextMenu.favorites.Contains(fullPath);
					return (bool)_isFavorite;
				}
				private set {_isFavorite = value;}
			}

			public bool HasAnyFavoriteChild(){
				foreach(var child in children.Values){
					if (child.isFavorite || child.HasAnyFavoriteChild()){
						return true;
					}
				}

				return false;
			}

			public void ToggleFavorite(){
				SetFavorite(!isFavorite);
				if (!isFavorite){
					if (parent != null && !parent.HasAnyFavoriteChild()){
						CompleteContextMenu.RemoveFavorite(parent.fullPath);
					}
				}
			}

			void SetFavorite(bool fav){
				isFavorite = fav;
				if (fav == true){
					CompleteContextMenu.AddFavorite(fullPath);
					foreach(var child in children.Values){
						child.SetFavorite(fav);
					}
				}
				
				if (fav == false){
					CompleteContextMenu.RemoveFavorite(fullPath);
					foreach(var child in children.Values){
						child.SetFavorite(fav);
					}
				}
			}
		}


		///Browser preferences and saved favorites per key
		class SerializationData{
			public Dictionary<string, List<string>> allFavorites = new Dictionary<string, List<string>>();
			public SearchMode searchMode = SearchMode.Contains;
			public bool filterFavorites = false;
		}

		private static SerializationData data;

		private static System.Type currentKeyType;
		private static List<string> favorites;
		private static SearchMode searchMode = SearchMode.Contains;
		private static bool filterFavorites = false;

		private Color hoverColor = new Color(0.5f,0.5f,1, 0.3f);
		private string title;
		private EditorUtils.MenuItemInfo[] items;
		private Node rootNode = new Node();
		private List<Node> leafNodes;
		private Node currentNode = null;
		private Vector2 scrollPos;
		private string lastSearch;
		private string search;
		private GUIStyle headerStyle;
		private float helpRectHeight = 58;
		private int hoveringIndex;
		private Rect mainRect;
		private bool init;
		

		//////////////
		//////////////


		public override Vector2 GetWindowSize(){ return new Vector2(480, 500); }
		///Shows the popup menu at position and with title
		public static void Show(GenericMenu menu, Vector2 pos, string title, System.Type keyType){
			PopupWindow.Show( new Rect(pos.x, pos.y, 0, 0), new CompleteContextMenu(menu, title, keyType) );
		}



		//init
		public CompleteContextMenu(GenericMenu menu, string title, System.Type keyType){
			this.title = title;
			currentKeyType = keyType;
			items = EditorUtils.GetMenuItems(menu);
			rootNode = new Node();
			currentNode = rootNode;
			headerStyle = new GUIStyle("label");
			headerStyle.alignment = TextAnchor.UpperCenter;
			GenerateTree();
			hoveringIndex = -1;
		}

		public override void OnOpen(){ LoadPrefs(); }
		public override void OnClose(){ SavePrefs(); }

		//...
		private static void LoadPrefs(){
			if (data == null){
				var json = EditorPrefs.GetString("ParadoxNotion.ContextBrowserPreferences");
				if (!string.IsNullOrEmpty(json)){ data = JSONSerializer.Deserialize<SerializationData>(json); }
				if (data == null){ data = new SerializationData(); }
				
				searchMode = data.searchMode;
				filterFavorites = data.filterFavorites;
				if (!data.allFavorites.TryGetValue(currentKeyType.Name, out favorites)){
					favorites = new List<string>();
				}
			}
		}

		//...
		private static void SavePrefs(){
			data.searchMode = searchMode;
			data.filterFavorites = filterFavorites;
			data.allFavorites[currentKeyType.Name] = favorites;
			EditorPrefs.SetString("ParadoxNotion.ContextBrowserPreferences", JSONSerializer.Serialize(typeof(SerializationData), data));
		}

		//...
		public static void AddFavorite(string path){
			if (!favorites.Contains(path)){
				favorites.Add(path);
			}
		}

		//...
		public static void RemoveFavorite(string path){
			if (favorites.Contains(path)){
				favorites.Remove(path);
			}
		}


		//Generate the tree node structure out of the items
		void GenerateTree(){
			leafNodes = new List<Node>();
			foreach (var item in items){
				var itemPath = item.content.text;
				var parts = itemPath.Split( new char[]{'/'}, System.StringSplitOptions.RemoveEmptyEntries );
				Node current = rootNode;
				foreach (var part in parts){
					Node child = null;
					if (!current.children.TryGetValue(part, out child)){
						child = new Node{name = part, parent = current};
						current.children[part] = child;
						if (part == parts.Last()){
							child.item = item;
							leafNodes.Add(child);
						}
					}
					current = child;
				}
			}		
		}


		//Show stuff
		public override void OnGUI(Rect rect){

			var e = Event.current;
			EditorGUIUtility.SetIconSize(Vector2.zero);
			hoveringIndex = Mathf.Clamp(hoveringIndex, -1, currentNode.children.Count-1);

			///MAIN AREA
			mainRect = new Rect(rect.x, rect.y, rect.width, rect.height - helpRectHeight);
			GUI.Box(mainRect, "", (GUIStyle)"PreBackground");
			GUILayout.BeginArea(mainRect);

			//HEADER
			GUILayout.Space(2);
			GUILayout.Label(string.Format("<color=#dddddd><size=15><b>{0}</b></size></color>", title), headerStyle);

			///SEARCH
			if (e.keyCode == KeyCode.DownArrow){GUIUtility.keyboardControl = 0;}
			if (e.keyCode == KeyCode.UpArrow){GUIUtility.keyboardControl = 0;}
			// GUILayout.Space(2);
			GUILayout.BeginHorizontal();
			GUI.SetNextControlName("SearchToolbar");
			search = EditorGUILayout.TextField(search, (GUIStyle)"ToolbarSeachTextField");
			if (GUILayout.Button("", (GUIStyle)"ToolbarSeachCancelButton")){
				search = string.Empty;
				GUIUtility.keyboardControl = 0;
			}
			GUILayout.EndHorizontal();

			GUILayout.BeginHorizontal();
			searchMode = (SearchMode)EditorGUILayout.EnumPopup(searchMode);
			filterFavorites = EditorGUILayout.ToggleLeft("Filter Favorites", filterFavorites);
			GUILayout.EndHorizontal();

			EditorUtils.BoldSeparator();

			///BACK
			if (currentNode.parent != null && string.IsNullOrEmpty(search)){
				GUILayout.BeginHorizontal("box");
				if (GUILayout.Button(string.Format("<b><size=14>◄ {0}/{1}</size></b>", currentNode.parent.name, currentNode.name), (GUIStyle)"label" )){
					currentNode = currentNode.parent;
				}
				GUILayout.EndHorizontal();
				var lastRect = GUILayoutUtility.GetLastRect();
				if (lastRect.Contains(e.mousePosition)){
					GUI.color = hoverColor;
					GUI.DrawTexture(lastRect, EditorGUIUtility.whiteTexture);
					GUI.color = Color.white;
					base.editorWindow.Repaint();
					hoveringIndex = -1;
				}
			}

			//Go back with right click as well...
			if (e.type == EventType.MouseDown && e.button == 1){
				e.Use();
				if (currentNode.parent != null){
					currentNode = currentNode.parent;
				}
			}


			///TREE
			scrollPos = EditorGUILayout.BeginScrollView(scrollPos, false, false);
			GUILayout.BeginVertical();

			if (search != lastSearch){
				hoveringIndex = 0;
				if (!string.IsNullOrEmpty(search) && search.Length >= 2 ){
					var searchRootNode = new Node(){name = "Search Root"};
					var a = GetCleanSearchString(search);
					foreach (var node in leafNodes){
						var b = GetCleanSearchString(node.name);
						var match = false;
						if ( searchMode == SearchMode.Contains && b.Contains(a) ){ match = true; }
						if ( searchMode == SearchMode.StartsWith && b.StartsWith(a) ){ match = true; }
						if (match){
							searchRootNode.children[node.name] = node;
						}
					}
					currentNode = searchRootNode;
				} else {
					currentNode = rootNode;
				}
				lastSearch = search;
			}



			var i = 0;
			var itemAdded = false;
			Node lastParent = null;
			foreach (var childPair in currentNode.children){

				var node = childPair.Value;

				if (search != null && search.Length >= 2){
					var currentParent = node.parent;
					if (currentParent != lastParent){
						lastParent = currentParent;
						GUI.color = EditorGUIUtility.isProSkin? Color.black : Color.white;
						GUILayout.BeginHorizontal("box");
						GUI.color = Color.white;
						if (GUILayout.Button( currentParent.unfolded? "▼" : "▶", (GUIStyle)"label", GUILayout.Width(16))){
							currentParent.unfolded = !currentParent.unfolded;
						}
						GUILayout.Label(string.Format("<size=12><b>{0}</b></size>", currentParent.fullPath) );
						GUILayout.EndHorizontal();
					}

					if (!node.parent.unfolded){
						continue;
					}
				}

				if (filterFavorites && !node.isFavorite && !node.HasAnyFavoriteChild()){
					continue;
				}

				itemAdded = true;
				var leafItem = node.item;
				var icon = leafItem != null? leafItem.content.image : EditorUtils.folderIcon;
				var itemDisabled = leafItem != null && leafItem.func == null && leafItem.func2 == null;

				GUI.color = EditorGUIUtility.isProSkin? Color.white : new Color(0.8f,0.8f,0.8f,1);
				GUILayout.BeginHorizontal("box");
				GUI.color = Color.white;

				//Prefix icon
				GUILayout.Label(icon, GUILayout.Width(32), GUILayout.Height(16));

				GUI.enabled = !itemDisabled;
				
				//Favorite
				GUI.color = node.isFavorite? Color.white : (node.HasAnyFavoriteChild()? new Color(1,1,1,0.2f) : new Color(0f,0f,0f,0.4f));
				if (GUILayout.Button(EditorUtils.favoriteIcon, GUIStyle.none, GUILayout.Width(16), GUILayout.Height(16)) ){
					node.ToggleFavorite();
				}
				GUI.color = Color.white;

				//Content
				var label = node.name;
				if (search != null && search.Length >= 2){ //simple highlight
					label = Regex.Replace(label, search, "<b>$&</b>", RegexOptions.IgnoreCase);
				}

				if (GUILayout.Button(string.Format("<size=10>{0}</size>",
					(leafItem == null? string.Format("<b>{0}</b>", label) : label) ),
					(GUIStyle)"label", GUILayout.Width(0), GUILayout.ExpandWidth(true) ))
				{

					if (leafItem != null){
						
						ExecuteItemFunc(leafItem);
						break;

					} else {

						currentNode = node;
						hoveringIndex = 0;
						break;
					}
				}

				//Suffix icon
				GUILayout.Label(leafItem != null? "<b>+</b>" : "►", GUILayout.Width(20));

				GUILayout.EndHorizontal();
				var lastRect = GUILayoutUtility.GetLastRect();

				if (lastRect.Contains(e.mousePosition) && e.type == EventType.MouseMove ){
					hoveringIndex = i;
				}

				if (hoveringIndex == i){
					GUI.color = hoverColor;
					GUI.DrawTexture(lastRect, EditorGUIUtility.whiteTexture);
					GUI.color = Color.white;
					base.editorWindow.Repaint();
				}

				i++;

				GUI.enabled = true;
			}


			if (!itemAdded){
				GUILayout.Label("No results to display with current search and filter combination");
			}

			GUILayout.EndVertical();
			EditorGUILayout.EndScrollView();
			GUILayout.EndArea();


			GUILayout.FlexibleSpace();


			///HELP AREA
			var hoveringNode = hoveringIndex >= 0 && currentNode.children.Count > 0? currentNode.children.Values.ToList()[hoveringIndex] : null;
			var helpRect = new Rect(rect.x + 2, rect.yMax-helpRectHeight + 2, rect.width - 4, helpRectHeight - 2);
			GUI.color = new Color(0,0,0,0.3f);
			GUI.Box(helpRect, "", (GUIStyle)"TextField");
			GUI.color = Color.white;
			GUILayout.BeginArea(helpRect);
			GUILayout.BeginVertical();
			var doc = string.Empty;
			if (hoveringNode != null && hoveringNode.item != null){
				doc = hoveringNode.item.content.tooltip;
				var memberInfo = hoveringNode.item.userData as MemberInfo;
				if (memberInfo != null && string.IsNullOrEmpty(doc)){
					doc = DocsByReflection.GetMemberSummary(memberInfo);
				}
			}
			GUILayout.Label(doc, EditorStyles.wordWrappedLabel);
			GUILayout.EndVertical();
			GUILayout.EndArea();


			//handle the events
			HandeEvents(e);
			if (!init){
				init = true;
				EditorGUI.FocusTextInControl("SearchToolbar");
			}

			EditorGUIUtility.SetIconSize(Vector2.zero);
		}

		string GetCleanSearchString(string s){
			s = s.ToUpper().Replace(" ", "").Replace("_", "");
			string regex = "(\\[.*\\])|(\".*\")|('.*')|(\\(.*\\))";
			return Regex.Replace(s, regex, "");
		}

		//Executes the item's registered delegate
		void ExecuteItemFunc(EditorUtils.MenuItemInfo item){
			if (item.func != null){
				item.func();
			} else {
				item.func2(item.userData);
			}
			base.editorWindow.Close();
		}


		//Handle events
		void HandeEvents(Event e){

			if (e.type == EventType.KeyDown){

				if (e.keyCode == KeyCode.RightArrow || e.keyCode == KeyCode.Return){
					var next = currentNode.children.Values.ToList()[hoveringIndex];
					if (e.keyCode == KeyCode.Return && next.item != null){
						ExecuteItemFunc(next.item);
					} else if (next.item == null){
						currentNode = next;
						hoveringIndex = 0;							
					}
					return;
				}
				
				if (e.keyCode == KeyCode.LeftArrow){
					var previous = currentNode.parent;
					if (previous != null){
						hoveringIndex = currentNode.parent.children.Values.ToList().IndexOf(currentNode);
						currentNode = previous;
					}
					return;
				}
				
				if (e.keyCode == KeyCode.DownArrow){
					hoveringIndex ++;
					return;
				}

				if (e.keyCode == KeyCode.UpArrow){
					hoveringIndex --;
					return;
				}

				if (e.keyCode == KeyCode.Escape){
					base.editorWindow.Close();
					return;
				}
	
				EditorGUI.FocusTextInControl("SearchToolbar");

			}
		}
	}
}

#endif