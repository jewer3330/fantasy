using UnityEngine;
using UnityEditor;
using System.IO;
namespace SuperBoBo
{
    public class CustomDialog : EditorWindow
    {

        public string title;
        public string msg;
        public string ok;
        public string cancel;
        public static CustomDialog instance;

        public Vector2 scrollPos;

        public bool ret = false;

        public CallBack okCallBack;
        public CallBack cancelCallBack;

        public delegate void CallBack();

        public bool toggle = false;


        public string version = "1.0.0";

        public static void Show(string title, string msg, string ok, string cancel, CallBack okCallBack, CallBack cancelCallBack)
        {
            // Get existing open window or if none, make a new one:
            CustomDialog window = (CustomDialog)EditorWindow.GetWindow(typeof(CustomDialog));
            window.Show();
            window.title = title;
            window.msg = msg;
            window.ok = ok;
            window.cancel = cancel;
            window.okCallBack = okCallBack;
            window.cancelCallBack = cancelCallBack;

            CustomDialog.instance = window;
        }

        void OnGUI()
        {
            //GUILayout.Label("场景配置", EditorStyles.boldLabel);

            if (CustomDialog.instance)
            {

                CustomDialog.instance.titleContent = new GUIContent(title);

                scrollPos = GUILayout.BeginScrollView(scrollPos);

                string[] lines = msg.Split('\n');
                for (int i = 0; i < lines.Length - 1; i++)
                {
                    string k = lines[i];
                    GUILayout.Label(k);
                }
                GUILayout.EndScrollView();

                GUILayout.BeginHorizontal();
                GUILayout.Label("老的资源版本号");
                GUILayout.Label(BuildTool.versionRes.ToString());
                GUILayout.Label("老的代码版本号");
                GUILayout.Label(BuildTool.versionCode.ToString());
                GUILayout.Label("老的APP版本号");
                GUILayout.Label(BuildTool.versionName.ToString());


                GUILayout.EndHorizontal();

                toggle = GUILayout.Toggle(toggle, "修改");
                if (toggle)
                {
                    GUILayout.BeginHorizontal();

                    version = GUILayout.TextField(version);
                    try
                    {
                        BuildTool.versionRes.Parse(version);
                    }
                    catch (System.Exception e)
                    {
                        Debug.LogError(e.ToString());
                    }
                    GUILayout.EndHorizontal();
                }



                if (GUILayout.Button(ok))
                {
                    ret = true;
                    okCallBack();
                    CustomDialog.instance.Close();
                }


                if (GUILayout.Button(cancel))
                {
                    ret = false;
                    cancelCallBack();
                    CustomDialog.instance.Close();

                }

            }
        }

    }
}