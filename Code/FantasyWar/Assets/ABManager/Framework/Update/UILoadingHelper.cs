using UnityEngine;
using System.Collections;
namespace SuperBoBo
{
    public class UILoadingHelper
    {

        public delegate void StartDelegate(float compelete, System.Action callback);
        public delegate void SetProgressDelegate(float p);
        public delegate void SetVersionDelegate(string version);
        public delegate void SetTipForUncompressDelegate(bool value);

        public static StartDelegate onStart;
        public static SetProgressDelegate onSetProgress;
        public static SetVersionDelegate onSetVersion;
        public static SetTipForUncompressDelegate onSetTipForUncompress;


        public static void Start(float compelte, System.Action callback)
        {
            if (onStart != null) onStart(compelte, callback);

        }

        public static void SetTipForUncompress(bool value)
        {
            if (onSetTipForUncompress != null) onSetTipForUncompress(value);

        }

        public static void SetProgress(float p)
        {
            if (onSetProgress != null) onSetProgress(p);
        }



        public static void SetVersion(string version)
        {
            if (onSetVersion != null) onSetVersion(version);
        }
    }
}
