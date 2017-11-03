/* !!auto gen do not change
 
 */

using UnityEngine;
using System;
using System.Collections;
using System.Collections.Generic;

namespace Table
{
    public partial class Character
    {
	    static bool loaded = false;
        public int ID;
        public string Name;
        public int Type;
        public int Level;
        public string Icon;
        public int AT;
        public int DF;
        public int MAT;
        public int MDF;
        public int MP;
        public int MV;
        public int Control;
        public int ArmAT;
        public int ArmDF;
        public int ArmLimit;
        public string ArmType;
        public string Magic;
        public string Res;

static int memberCount = 18 ; 
        public Character()
        {
        }

        public Character( int ID, string Name, int Type, int Level, string Icon, int AT, int DF, int MAT, int MDF, int MP, int MV, int Control, int ArmAT, int ArmDF, int ArmLimit, string ArmType, string Magic, string Res)
        {
            this.ID = ID;
            this.Name = Name;
            this.Type = Type;
            this.Level = Level;
            this.Icon = Icon;
            this.AT = AT;
            this.DF = DF;
            this.MAT = MAT;
            this.MDF = MDF;
            this.MP = MP;
            this.MV = MV;
            this.Control = Control;
            this.ArmAT = ArmAT;
            this.ArmDF = ArmDF;
            this.ArmLimit = ArmLimit;
            this.ArmType = ArmType;
            this.Magic = Magic;
            this.Res = Res;

        }
        public static Dictionary<int, Character> _datas = new Dictionary<int, Character>();
		
		    public static  Dictionary<int, Character>  datas
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
                    Debug.LogError("Character严重错误，表头和表数据长度不一样");
#if UNITY_EDITOR
                     UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("Character严重错误，表头和表数据长度不一样");
                    return;
                }
                Character dataCharacter = new Character();
                if(!int.TryParse(values[0],out dataCharacter.ID))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[0] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[0] + " to int" + " 第"+ i + "行,第0列");
                 
                }
                dataCharacter.Name = values[1];
                if(!int.TryParse(values[2],out dataCharacter.Type))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[2] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[2] + " to int" + " 第"+ i + "行,第2列");
                 
                }
                if(!int.TryParse(values[3],out dataCharacter.Level))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[3] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[3] + " to int" + " 第"+ i + "行,第3列");
                 
                }
                dataCharacter.Icon = values[4];
                if(!int.TryParse(values[5],out dataCharacter.AT))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[5] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[5] + " to int" + " 第"+ i + "行,第5列");
                 
                }
                if(!int.TryParse(values[6],out dataCharacter.DF))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[6] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[6] + " to int" + " 第"+ i + "行,第6列");
                 
                }
                if(!int.TryParse(values[7],out dataCharacter.MAT))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[7] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[7] + " to int" + " 第"+ i + "行,第7列");
                 
                }
                if(!int.TryParse(values[8],out dataCharacter.MDF))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[8] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[8] + " to int" + " 第"+ i + "行,第8列");
                 
                }
                if(!int.TryParse(values[9],out dataCharacter.MP))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[9] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[9] + " to int" + " 第"+ i + "行,第9列");
                 
                }
                if(!int.TryParse(values[10],out dataCharacter.MV))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[10] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[10] + " to int" + " 第"+ i + "行,第10列");
                 
                }
                if(!int.TryParse(values[11],out dataCharacter.Control))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[11] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[11] + " to int" + " 第"+ i + "行,第11列");
                 
                }
                if(!int.TryParse(values[12],out dataCharacter.ArmAT))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[12] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[12] + " to int" + " 第"+ i + "行,第12列");
                 
                }
                if(!int.TryParse(values[13],out dataCharacter.ArmDF))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[13] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[13] + " to int" + " 第"+ i + "行,第13列");
                 
                }
                if(!int.TryParse(values[14],out dataCharacter.ArmLimit))
                {

#if UNITY_EDITOR
                    Debug.LogError("数据有误:" + values[14] + " to int");
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    throw new ArgumentException("数据有误:" + values[14] + " to int" + " 第"+ i + "行,第14列");
                 
                }
                dataCharacter.ArmType = values[15];
                dataCharacter.Magic = values[16];
                dataCharacter.Res = values[17];
                if (datas.ContainsKey(dataCharacter.ID))
                {
               #if UNITY_EDITOR
                     UnityEditor.EditorApplication.isPaused = true;
                #endif
                    throw new ArgumentException("数据有误,主键重复:" + dataCharacter.ID);
                }
                datas.Add(dataCharacter.ID,dataCharacter);
            }

        }

        public static void LoadFromResources()
        {           
		TextAsset data = null;
            #if UNITY_IOS
                data = ResManager.Load("Table_IOS/Character.csv") as TextAsset;
            #else
                data = ResManager.Load("Table/Character.csv") as TextAsset;
            #endif
            
				if(data == null)
				{
				    Debug.LogError("Table/Character.csv 不存在！！！！");
#if UNITY_EDITOR
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    
					
					return;
				}
                string text = data.text;
				if(string.IsNullOrEmpty(text))
				{
					
				    Debug.LogError("Table/Character.csv 没有内容");
#if UNITY_EDITOR
                    UnityEditor.EditorApplication.isPaused = true;
#endif
                    
				
					return;
				}
                Character.LoadFromString(text);
        }
        public static void LoadFromStreaming()
        {
            try
            {
                string url = "Table/Character.csv";
                string content = FileUtils.ReadStringFromStreaming(url);

                LoadFromString(content);
            }
            catch (Exception ex)
            {
                Debug.LogError(string.Format("表Character数据有误! ({0})",ex.Message));
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

        public static Character Get(int ID)
        {
#if UNITY_EDITOR
            if (!Contains(ID))
            {

                Debug.LogError("表Character没有元素" + ID + ",检测一下Excel表");
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
        public static int GetType(int ID)
        {
            return Get(ID).Type;
        }
        public static int GetLevel(int ID)
        {
            return Get(ID).Level;
        }
        public static string GetIcon(int ID)
        {
            return Get(ID).Icon;
        }
        public static int GetAT(int ID)
        {
            return Get(ID).AT;
        }
        public static int GetDF(int ID)
        {
            return Get(ID).DF;
        }
        public static int GetMAT(int ID)
        {
            return Get(ID).MAT;
        }
        public static int GetMDF(int ID)
        {
            return Get(ID).MDF;
        }
        public static int GetMP(int ID)
        {
            return Get(ID).MP;
        }
        public static int GetMV(int ID)
        {
            return Get(ID).MV;
        }
        public static int GetControl(int ID)
        {
            return Get(ID).Control;
        }
        public static int GetArmAT(int ID)
        {
            return Get(ID).ArmAT;
        }
        public static int GetArmDF(int ID)
        {
            return Get(ID).ArmDF;
        }
        public static int GetArmLimit(int ID)
        {
            return Get(ID).ArmLimit;
        }
        public static string GetArmType(int ID)
        {
            return Get(ID).ArmType;
        }
        public static string GetMagic(int ID)
        {
            return Get(ID).Magic;
        }
        public static string GetRes(int ID)
        {
            return Get(ID).Res;
        }

    }
}