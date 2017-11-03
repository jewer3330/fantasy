using UnityEngine;
using UnityEditor;

public class WeaponEditor : EditorWindow
{

    public static GUISkin PTSkin;
    public static GUISkin oldSkin;
    //public static GameObject characterObj;
    //public static string modelName;

    public WeaponGraph curGraph = null;
   
    protected Vector2 rightMousePos = Vector2.zero;
    protected Vector2 scrollPos;
    public enum PTTabType
    {
        WEAPON,
        WEAPONEDITOR,
    }

    [MenuItem("Window/WeaponEditor #&w")]
    static void Init()
    {
        PlatoNodeGenerator.Parse();

        WeaponEditor window = GetWindow<WeaponEditor>();
        window.Show();
        ProjectileEditor projEditor = GetWindow<ProjectileEditor>(typeof(WeaponEditor));
        projEditor.curGraph = ScriptableObject.CreateInstance<ProjectileGraph>();
        projEditor.Show();
        WeaponWindow.Open("Weapon");
        PTSkin = AssetDatabase.LoadAssetAtPath<GUISkin>("Assets/Editor/WeaponEditor/WeaponEditorSkin.guiskin");
    }

    private void OnEnable()
    {
        EditorUtil.Clear();
    }

    private void OnDestroy()
    {
        WeaponEditorUtil.curCharacter = null;
        WeaponEditorUtil.modelName = "";
        curGraph = null;
    }

    private void OnGUI()
    {
        if (curGraph == null)
            return;
        GUI.skin = PTSkin;
        curGraph.UpdateGUI(this);
        GUI.skin = null;
    }
}
