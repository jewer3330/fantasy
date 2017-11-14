using UnityEngine;
using System.Collections;

public class CoroutineHelper : MonoBehaviour {

	public static CoroutineHelper Instance
	{
		get
		{ 
			if (!_instance) {
				_instance = new GameObject ("CoroutineHelper").AddComponent<CoroutineHelper> ();
			}

			return _instance;
		}
	}

	private static CoroutineHelper _instance;

	void Awake()
	{
		DontDestroyOnLoad (gameObject);
	}

	void OnDestroy()
	{
		_instance = null;
	}
}
