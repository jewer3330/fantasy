using UnityEngine;
using System.Collections;
using UnityEditor;

public class LevelDetailWindow : EditorWindow
{

    public LevelObjectBase objectBase;
    public static LevelDetailWindow instance;
    // Use this for initialization
    void Change()
    {
        objectBase.SetDataOld(objectBase.GetData().Clone());
    }

    
    // Update is called once per frame
    void Update()
    {

    }

    void Save()
    {
        if (EditorUtility.DisplayDialog("提示", "需要保存吗？", "确定", "取消"))
        {
           
        }
        else
        {
            LevelBaseData dataOld = objectBase.GetDataOld();
            objectBase.GetData().Copy(dataOld);
            objectBase.transform.position = dataOld.pos;
            objectBase.transform.eulerAngles = dataOld.dir;
            objectBase.transform.localScale = dataOld.scale;

        }
    }

    void OnDestroy()
    {
     
        if (!objectBase.GetDataOld().Equals(objectBase.GetData()))
        {
            Save();
        }
        Selection.activeGameObject = null;

    }
    void OnInspectorUpdate()
    {
        Repaint();
    }

    public static void Init(LevelObjectBase m)
    {
        if (LevelDetailWindow.instance == null)
        {
            LevelDetailWindow window = (LevelDetailWindow)EditorWindow.GetWindow(typeof(LevelDetailWindow));
            LevelDetailWindow.instance = window;
           
        }

        
        if (instance.objectBase != m)
        {
            instance.Repaint();
            if (instance.objectBase)
            {
                //if (!instance.objectBase.GetData().Equals(instance.objectBase.GetDataOld()))
                //{
                //    instance.Save();
                //}
            }
            LevelDetailWindow.instance.objectBase = m;
            instance.ShowPopup();
            instance.Change();
           
        }

    }

    void OnGUI()
    {

        if (objectBase.GetData() != null && objectBase.GetDataOld() != null)
        {
            if (objectBase)
                LevelCommonFunc.OnGUI(objectBase, objectBase.GetData());

            objectBase.GetData().nameColor = EditorGUILayout.ColorField("字体颜色", objectBase.GetData().nameColor);
            objectBase.GetData().fontSize = EditorGUILayout.IntField("字体大小", objectBase.GetData().fontSize);
            objectBase.GetData().isVisible = EditorGUILayout.Toggle("显示", objectBase.GetData().isVisible);
            
        }

        if (Event.current.keyCode == KeyCode.Delete)
        {
            Close();
            GameObject.DestroyImmediate(objectBase.gameObject);
            Selection.activeGameObject = null;
        }
    }
}
