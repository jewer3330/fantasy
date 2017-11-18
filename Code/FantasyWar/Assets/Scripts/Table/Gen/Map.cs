/* !!auto gen do not change
 
 */

using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;
using SuperBoBo;

namespace Table
{
    public partial class Map
    {
	    static bool loaded = false;
        public int ID;
        public string Name;
        public int MoveCost;
        public int Advantage;

static int memberCount = 4 ; 
        public Map()
        {
        }

        public Map( int ID, string Name, int MoveCost, int Advantage)
        {
            this.ID = ID;
            this.Name = Name;
            this.MoveCost = MoveCost;
            this.Advantage = Advantage;

        }
        public static Dictionary<int, Map> _datas = new Dictionary<int, Map>();
		
		    public static  Dictionary<int, Map>  datas
        {
            get
            {
                if(!loaded)
                {
                    loaded = true;
                    LoadFromResources();
                }
                return _datas;
            }
			
			set
			{
			_datas = value;
			}
        }
		
        public static void LoadFromString(string data)
        {

            string content = data;
            string[] lines = content.Split('\n');
       

            for (int i = 2; i < lines.Length; i++)
            {
                string line = lines[i];
                line = line.Replace("\r", "");
                if(string.IsNullOrEmpty(line)) continue;
                string[] values = line.Split('\t');
                if(values.Length != memberCount)
                {
                    Debug.LogError("Map严重错误，表头和表数据长度不一样");
#if UNITY_EDITOR
                     UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("Map严重错误，表头和表数据长度不一样");
                    return;
                }
                Map dataMap = new Map();
                if(!int.TryParse(values[0],out dataMap.ID))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[0] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[0] + " to int" + " 第"+ i + "行,第0列");
                 
                }
                dataMap.Name = values[1];
                if(!int.TryParse(values[2],out dataMap.MoveCost))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[2] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[2] + " to int" + " 第"+ i + "行,第2列");
                 
                }
                if(!int.TryParse(values[3],out dataMap.Advantage))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[3] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[3] + " to int" + " 第"+ i + "行,第3列");
                 
                }
                if (datas.ContainsKey(dataMap.ID))
                {
               #if UNITY_EDITOR
                     UnityEditor.EditorApplication.isPaused = true;
                #endif
                    throw new ArgumentException("数据有误,主键重复:" + dataMap.ID);
                }
                datas.Add(dataMap.ID,dataMap);
            }

        }

        public static void LoadFromResources()
        {           
		TextAsset data = null;
            #if UNITY_IOS
                data = ResManager.Load("Table_IOS/Map.csv") as TextAsset;
            #else
                data = ResManager.Load("Table/Map.csv") as TextAsset;
            #endif
            
				if(data == null)
				{
				    Debug.LogError("Table/Map.csv 不存在！！！！");
#if UNITY_EDITOR
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    
					
					return;
				}
                string text = data.text;
				if(string.IsNullOrEmpty(text))
				{
					
				    Debug.LogError("Table/Map.csv 没有内容");
#if UNITY_EDITOR
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    
				
					return;
				}
                Map.LoadFromString(text);
        }
        public static void LoadFromStreaming()
        {
            try
            {
                string url = "Table/Map.csv";
                string content = FileUtils.ReadStringFromStreaming(url);

                LoadFromString(content);
            }
            catch (Exception ex)
            {
                Debug.LogError(string.Format("表Map数据有误! ({0})",ex.Message));
            }
        }


        public static void Clear()
        {
            datas.Clear();
        }

        public static bool Contains(int ID)
        {    
            return datas.ContainsKey(ID);
        }

        public static Map Get(int ID)
        {
#if UNITY_EDITOR
            if (!Contains(ID))
            {

                Debug.LogError("表Map没有元素" + ID + ",检测一下Excel表");
                #if UNITY_EDITOR
                      UnityEditor.EditorApplication.isPaused = true;
                #endif
                return null;
            }
#endif
            return datas[ID];
        }


        public static string GetName(int ID)
        {
            return Get(ID).Name;
        }
        public static int GetMoveCost(int ID)
        {
            return Get(ID).MoveCost;
        }
        public static int GetAdvantage(int ID)
        {
            return Get(ID).Advantage;
        }

    }
}