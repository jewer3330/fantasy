using UnityEngine;
using System.Collections;
using System.Collections.Generic;

/*
 * DESC:定义了一些常用接口 
 * by zj
 * 2016年1月7日16:13:40
 */
namespace SuperBoBo
{

    /// <summary>
    /// Singleton.
    /// </summary>
    public class Singleton<T> where T : new()
    {

        private static T instance;

        public static T Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new T();
                }
                return instance;
            }
        }


    }






    public delegate bool isActive ();

	/// <summary>
	/// 红点管理器
	/// by zj
	/// 2016-3-4 10:08:32
	/// </summary>
	public class RedPointManager
	{

		public RedPointManager ()
		{

		}

		private static RedPointManager instance;

		public static RedPointManager Instance {
			get {
				if (instance == null) {
					instance = new RedPointManager ();
				}
				return instance;
			}
		}


		public class RedPointBundle
		{
			public string tag;
			public int index;
			public GameObject go;
			public isActive activeFunc;

			public RedPointBundle ()
			{

			}

			public RedPointBundle (string tag, int index, GameObject go, isActive activeFunc)
			{
				this.tag = tag;
				this.index = index;
				this.go = go;
				this.activeFunc = activeFunc;
			}
		}

		private Dictionary<string, List<RedPointBundle>> dic = new Dictionary<string, List<RedPointBundle>> ();

		public void Reg (string tag, int index, GameObject go, isActive activeFunc)
		{
			if (dic.ContainsKey (tag)) {
				List<RedPointBundle> bs = dic [tag];

				if (bs != null) {

					bool find = false;
					for (int i = 0; i < bs.Count; ++i) {
						if (bs [i].index == index) {
							find = true;
							//Debug.LogWarning(string.Format("find index {0} exsits", index));

							bs [i] = new RedPointBundle (tag, index, go, activeFunc);

							break;
						}
					}

					if (!find) {
						bs.Add (new RedPointBundle (tag, index, go, activeFunc));
					}
				} else {
					throw new System.Exception ("null pointer exception");
				}
			} else {
				List<RedPointBundle> bundles = new List<RedPointBundle> ();

				RedPointBundle b = new RedPointBundle (tag, index, go, activeFunc);
				bundles.Add (b);
				dic.Add (tag, bundles);
			}
		}

		public void UnReg (string tag)
		{
			if (dic.ContainsKey (tag)) {
				dic.Remove (tag);
			} else {
				//Debug.LogWarning(string.Format("{0} not exsits", tag));
			}
		}

		public void Triggle (string tag, int index)
		{
			ActiveTag (tag);
			try {
				if (dic.ContainsKey (tag)) {
					List<RedPointBundle> rbs = dic [tag];

					RedPointBundle rb = null;

					foreach (var k in rbs) {
						if (k.index == index) {
							rb = k;
							break;
						}
					}

					if (rb != null) {
						if (rb.go.gameObject) {
							rb.go.SetActive (false);
						} else {
							Debug.LogWarning (string.Format ("tag {0} index {1} 's gameObject is null ,use this function after register!", tag, index));
						}
					} else {
						//Debug.LogWarning("not find!");
					}

				}
			} catch (System.Exception e) {
				Debug.LogError (e.ToString ());
			}
			//            Debug.Log("Triggle " + tag + " " + index);
		}

		public void ActiveTag (string tag)
		{
			if (dic.ContainsKey (tag)) {
				List<RedPointBundle> rbs = dic [tag];
				foreach (var k in rbs) {
					if (!k.go) {
						//Debug.LogWarning("the gameObject has been destoryed ! please check!");
					} else if (k.activeFunc == null) {
						//Debug.LogWarning("the activeFunc is null ! please check!");
					} else {
						k.go.SetActive (k.activeFunc ());
					}
				}

				//                Debug.Log("ActiveTag " + tag);
			}
		}
	}

	    
}





