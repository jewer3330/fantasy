namespace SuperBoBo
{
#if UNITY_ANDROID
    using UnityEngine;
    using System.Collections;
    using System.IO;

    public class AndroidHelper
    {

        static AndroidJavaClass _helper;
        public static AndroidJavaClass helper
        {
            get
            {
                if (_helper != null) return _helper;
                _helper = new AndroidJavaClass("com.Lee.Helper.Unity3dHelper");
                using (AndroidJavaClass jc = new AndroidJavaClass("com.unity3d.player.UnityPlayer"))
                {
                    object jo = jc.GetStatic<AndroidJavaObject>("currentActivity");
                    _helper.CallStatic("init", jo);
                }
                return _helper;
            }
        }

        public static bool Exits(string path)
        {
            bool exits = helper.CallStatic<bool>("isFileExists", path);
            return exits;
        }

        public static byte[] GetBytesFromAsset(string path)
        {
            byte[] data = helper.CallStatic<byte[]>("getBytes", path);
            return data;
        }

        public static string GetStringFromAsset(string path)
        {
            string data = helper.CallStatic<string>("getString", path);
            return data;
        }

        public static long GetSdCardSize()
        {
            AndroidJavaClass jc = new AndroidJavaClass("com.tank.androidtool.AndroidTool");
            long l = jc.CallStatic<long>("readSDCard");
            return l;
        }
        public static long GetSystemSize()
        {
            AndroidJavaClass jc = new AndroidJavaClass("com.tank.androidtool.AndroidTool");
            long l = jc.CallStatic<long>("readSystem");
            return l;
        }
    }
#endif
}