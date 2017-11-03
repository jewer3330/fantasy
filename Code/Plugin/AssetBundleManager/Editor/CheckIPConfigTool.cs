using System;
using UnityEditor;
using LitJson;
using System.IO;
using UnityEngine;
using System.Collections.Generic;

public class CheckIPConfigTool
{
	private static string strIPConfigFile = "cdn_ipconfig_json/ipconfig.json";

	[MenuItem("Tools/检查准备上传CND的配表《ipconfig.json》")]
	public static void CheckIPConfigFile()
	{
		if (File.Exists (strIPConfigFile)) {
			string jsonContent = FileUtilTool.ReadFile (strIPConfigFile);
			if (jsonContent.Trim ().Equals ("")) {
				Debug.LogError ("ipconfig.json 文件内容不能为空");
				return;
			}

			try
			{
				JsonReader jsonReader = new JsonReader (jsonContent);
				JsonData jData = JsonMapper.ToObject(jsonReader);
				string[] strPlatfofNameList = new string[]{"Android", "iOS"};
				foreach(var platforName in strPlatfofNameList)
				{
					if (jData.Contains(platforName))
					{
						JsonData content = jData [platforName];
						string[] keyList = IPConfigInfo.m_keyList;
						for (int i = 0; i < keyList.Length; i++) 
						{
							string strKey = keyList [i];
							if (content.Contains(strKey))
							{
								JsonData item = content [strKey];
								IPConfigInfo.GetInstance().getIPConfigData (strKey, item);
							}
						}
					}
					else
					{
						Debug.LogError ("ipconfig.json 文件中缺少：" + platforName + "平台");
						return;
					}
				}
			}
			catch(Exception e) 
			{
				Debug.LogError ("ipconfig.json 文件解析错误：" + e.ToString());
				return;
			}

			Debug.LogError ("ipconfig.json 文件解析成功！！");

		} else {
			Debug.LogError ("ipconfig.json 文件不存在");
		}

	}
}


