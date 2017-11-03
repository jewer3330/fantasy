using UnityEngine;
using UnityEditor;
using UnityEditor.SceneManagement;
using System.Collections;
using System.IO;

/// <summary>
/// 关卡编辑器
/// </summary>
public class PROTOGONOS : EditorWindow
{
    [MenuItem("Custom/PROTOGONOS")]
    public static void Open()
    {
        EditorWindow.GetWindow<PROTOGONOS>();
    }

    /// <summary>编辑器实例</summary>
    public static PROTOGONOS Instance { get; private set; }

    /// <summary>编辑模式标签页</summary>
    enum TabType
    {
        GAIA,
        PLATO,
        FORGE,
        MINIMAP,
    };
    /// <summary>当前标签页</summary>
    private int currentTab;

    /// <summary>当前主关卡名</summary>
    public string LevelName { get; set; }

    /// <summary>层级编辑器</summary>
    public GAIA gaia;
    /// <summary>可视化脚本编辑器</summary>
    public PLATO plato;
    /// <summary>穿透编辑器</summary>
    public FORGE forge;
    /// <summary>小地图导出</summary>
    public MiniMap miniMap;

    /// <summary>
    /// 编辑器窗口打开
    /// </summary>
    void OnEnable()
    {
        Instance = this;
        gaia = new GAIA();
        plato = new PLATO();
        forge = new FORGE();
        miniMap = new MiniMap();
        SceneView.onSceneGUIDelegate += CustomSceneGUI;
        Selection.selectionChanged += OnSelectionChanged;
    }

    /// <summary>
    /// 编辑器窗口关闭
    /// </summary>
    void OnDisable()
    {
        Instance = null;
        gaia = null;
        plato = null;
        forge = null;
        miniMap = null;
        SceneView.onSceneGUIDelegate -= CustomSceneGUI;
        Selection.selectionChanged -= OnSelectionChanged;
    }

    GameObject oldSelected;
    public void OnSelectionChanged()
    {
        if (oldSelected == Selection.activeGameObject)
            return;
        if (PROTOGONOS.Instance == null || PROTOGONOS.Instance.plato == null || PROTOGONOS.Instance.plato.graph == null)
            return;

        foreach (var node in PROTOGONOS.Instance.plato.graph.GetAllNodes())
        {
            foreach (var p in node.GetAllInPins())
            {
                if (p.Type != typeof(GameObject))
                    continue;
                if (p.Value == Selection.activeGameObject)
                {
                    PROTOGONOS.Instance.plato.Goto(node, this);
                    break;
                }
            }
        }

        oldSelected = Selection.activeGameObject;
    }

    /// <summary>
    /// 自定义GUI绘制
    /// </summary>
    void OnGUI()
    {
        currentTab = GUILayout.Toolbar(currentTab, new string[] {
            TabType.GAIA.ToString(),
            TabType.PLATO.ToString(),
            TabType.FORGE.ToString(),
            TabType.MINIMAP.ToString(),
        });

        switch (currentTab)
        {
            case (int)TabType.GAIA:
                gaia.DrawGUI(this);
                break;

            case (int)TabType.PLATO:
                //====================================================================
                // 文件相关
                GUILayout.BeginHorizontal();
                if (GUILayout.Button("OPEN", EditorStyles.toolbarButton))
                {
                    PlatoLoader loader = new PlatoLoader(PROTOGONOS.Instance.plato);
                    loader.Load(Path.Combine(PLATO.PLATO_SAVE_PATH, PROTOGONOS.Instance.LevelName).Replace("GAIA_", "") + ".txt");
                }
                if (GUILayout.Button("SAVE", EditorStyles.toolbarButton))
                {
                    PlatoSaver saver = new PlatoSaver(PROTOGONOS.Instance.plato);
                    saver.Save(Path.Combine(PLATO.PLATO_SAVE_PATH, PROTOGONOS.Instance.LevelName).Replace("GAIA_", "") + ".txt");
                }
                if (GUILayout.Button("EXPORT LUA", EditorStyles.toolbarButton))
                    PROTOGONOS.Instance.plato.ExportLua();
                if (GUILayout.Button("EXPORT C#", EditorStyles.toolbarButton))
                    PROTOGONOS.Instance.plato.ExportCSharp();
                if (GUILayout.Button("EXPORT CPP", EditorStyles.toolbarButton))
                    PROTOGONOS.Instance.plato.ExportCpp();
                if (GUILayout.Button("COMMENT", EditorStyles.toolbarButton))
                    PROTOGONOS.Instance.plato.Comment();
                GUILayout.EndHorizontal();

                // 如果当前场景不是GAIA中设置的关卡，强制关闭节点图，防止出错
                if (!PROTOGONOS.Instance.gaia.IsSameScene())
                {
                    if (plato.graph != null)
                    {
                        plato.graph.RemoveAllNode();
                        plato.graph = null;
                    }
                }
                plato.DrawGUI(this, new Vector2(0, 8 + 2 * EditorStyles.toolbarButton.fixedHeight));
                break;

            case (int)TabType.FORGE:
                forge.DrawGUI(this);
                break;
            case (int)TabType.MINIMAP:
                miniMap.DrawGUI(this);
                break;
            default:
                break;
        }
    }

    /// <summary>
    /// 自定义场景绘制，目前只对Forge有效
    /// </summary>
    /// <param name="sceneView"></param>
    void CustomSceneGUI(SceneView sceneView)
    {
        switch (currentTab)
        {
            case (int)TabType.GAIA:
                gaia.DrawSceneGUI(sceneView);
                break;

            case (int)TabType.PLATO:
                plato.DrawSceneGUI(sceneView);
                break;

            case (int)TabType.FORGE:
                forge.DrawSceneGUI(sceneView);
                break;

            default:
                break;
        }
    }

    /// <summary>Ctrl+S操作</summary>
    public void Save()
    {
        switch (currentTab)
        {
            case (int)TabType.GAIA:
                gaia.Save();
                break;

            case (int)TabType.PLATO:
                PlatoSaver saver = new PlatoSaver(plato);
                saver.Save(Path.Combine(PLATO.PLATO_SAVE_PATH, PROTOGONOS.Instance.LevelName).Replace("GAIA_", "") + ".txt");
                break;

            case (int)TabType.FORGE:
                forge.Save();
                break;

            default:
                break;
        }
    }
}
