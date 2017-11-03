using UnityEngine;
using System.Collections;
using System.Collections.Generic;



public class ObjectMap : MonoBehaviour {


	[System.Serializable]
	public class ObjectBundle
	{
		public string name;
		public GameObject go;
	}

	public ObjectBundle[] maps;

	Dictionary<string ,GameObject>  dic = new Dictionary<string, GameObject>();

	void Awake()
	{
		
	}

	public GameObject Get(string key)
	{
		if (dic.ContainsKey (key)) 
		{
			return dic [key];
		} 
		else 
		{
			foreach (var k in maps) 
			{
				if (k.name == key) 
				{
					dic.Add (k.name, k.go);
					return k.go;
				}
			}
		}

        Debug.LogError(key + " not find !");
		return null;
	}
}
