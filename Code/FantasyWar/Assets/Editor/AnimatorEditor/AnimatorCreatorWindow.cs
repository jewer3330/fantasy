using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using UnityEditor;
using UnityEngine;

namespace Assets.Editor.AnimatorEditor
{
    public enum PTCharacterType
    {
        Hero,
        Npc
    }

    public class AnimatorCreatorWindow : EditorWindow
    {
        #region const
        private static GUISkin skin;
        private const float LineSpace = 5f;
        #endregion const

        #region private members
        private string[] characterTypes;
        private PTCharacterType selectedCharacterType;
        private PTCharacterType oldCharacterType = PTCharacterType.Hero;
        private List<string> modelNames = new List<string>();
        private List<string> fDirs = new List<string>();
        private List<string> fEnemyDirs = new List<string>();
        private string modelNameIndex;
        private string oldModelNameIndex;
        private int idx;
        private AETemplate curTemplate;
        private string exportingCharacterName;
        #endregion private members

        [MenuItem("Window/AnimatorCreator &a")]
        static void Init()
        {
            AnimatorCreatorWindow window = GetWindow<AnimatorCreatorWindow>();
            window.titleContent = new GUIContent("AnimCreator");
            window.maximized = true;
            window.Show();
            skin = AssetDatabase.LoadAssetAtPath<GUISkin>("Assets/Editor/AnimatorEditor/AnimatorCreator.guiskin");
            AEUtil.CurCreator = window;
            return;
        }

        #region mono
        private void OnDestroy()
        {

        }

        private void OnEnable()
        {
            UpdateModelDirectory();

            return;
        }

        private void Update()
        {
            if (!exportingAll)
                return;

            if (exportDatas.Count != 0)
            {
                ExportData data = exportDatas.Dequeue();
                data.Template.Export(data.Type, data.Index);
                if (data.Callback != null)
                    data.Callback.Invoke();
                exportingCharacterName = string.Format("{0}{1}", data.Type, data.Index);
                Repaint();
            }

            if (needExportCount == exportedCount)
            {
                exportingAll = false;
                curTemplate = null;
            }
        }

        private void OnGUI()
        {
            GUI.skin = skin;
            Color oldColor = GUI.color;
            GUI.color = AEConfig.WINDOW_COLOR;

            // 导出全部时不绘制
            if (exportingAll)
            {
                DrawProgress();
                return;
            }

            DrawConsole();

            GUI.color = oldColor;
            GUI.skin = null;
        }
        #endregion mono

        private void DrawProgress()
        {
            EditorGUILayout.Space();
            EditorGUILayout.BeginVertical();

            EditorGUI.ProgressBar(
                new Rect(AEConfig.PROGRESS_X, AEConfig.PROGRESS_Y, AEConfig.PROGRESS_WIDTH, AEConfig.PROGRESS_HEIGHT),
                (float)exportedCount / needExportCount,
                string.Format("Exporting\n{0}", exportingCharacterName)
            );

            EditorGUILayout.EndVertical();
        }

        private void DrawConsole()
        {
            EditorGUILayout.Space();
            EditorGUILayout.BeginVertical();

            EditorGUILayout.BeginHorizontal();
            // 获取角色类型
            SelectCharacterType();
            // 选择导出角色
            SelectCharacter();
            // 获取当前状态机信息
            LoadAnimatorInfo();
            EditorGUILayout.EndHorizontal();
            EditorGUILayout.Space();

            EditorGUILayout.BeginHorizontal();
            // 读取模板
            LoadTemplate();
            // 保存模板
            SaveTemplate();
            EditorGUILayout.EndHorizontal();
            EditorGUILayout.Space();

            EditorGUILayout.BeginHorizontal();
            SaveAnimatorInfo();
            // 导出该角色
            ExportOne();
            EditorGUILayout.EndHorizontal();
            EditorGUILayout.Space();

            EditorGUILayout.BeginHorizontal();
            // 导出已经导出过的英雄
            ExportExistHeros();
            // 导出已经导出过的NPC
            ExportExistNpcs();
            // 导出已经导出过的角色
            ExportAllExistActors();
            EditorGUILayout.EndHorizontal();
            EditorGUILayout.Space();

            EditorGUILayout.BeginHorizontal();
            // 按指定模板导出已导出过的英雄
            ExportExistHerosByTemplate();
            // 按指定模板导出已导出过的NPC
            ExportExistNpcsByTemplate();
            EditorGUILayout.EndHorizontal();
            EditorGUILayout.Space();

            EditorGUILayout.BeginHorizontal();
            // 按指定模板导出所有英雄
            ExportAllHerosByTemplate();
            // 按指定模板导出所有NPC
            ExportAllNpcsByTemplate();
            // 导出已经导出过的英雄
            DoHotfix();
            EditorGUILayout.EndHorizontal();
            EditorGUILayout.Space();

            DrawTemplate();
            EditorGUILayout.Space();

            EditorGUILayout.EndVertical();
        }

        private void SaveAnimatorInfo()
        {
            if (GUILayout.Button("SaveAnimator", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                if (curTemplate == null)
                    return;
                curTemplate.SaveInstance(selectedCharacterType, modelNameIndex);
            }
        }

        private void LoadAnimatorInfo()
        {
            if (GUILayout.Button("LoadAnimator", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                string filename = string.Format("{0}{1}Animator.txt", selectedCharacterType, modelNameIndex);
                ParseTemplate(Path.Combine(AEConfig.ANIMATOR_INSTANCE_PATH, Path.GetFileName(filename)));
            }
        }

        private void DrawTemplate()
        {
            if (curTemplate == null)
                return;

            curTemplate.Draw(this);
        }

        private bool exportingAll;
        private int needExportCount;
        private int exportedCount;

        private void ExportExistHeros()
        {
            if (GUILayout.Button("ExportExistHeros", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                exportingAll = true;
                needExportCount = 0;
                exportedCount = 0;
                exportDatas.Clear();

                // 获取所有导出过的文件
                string[] files = Directory.GetFiles(AEConfig.ANIMATOR_INSTANCE_PATH);
                foreach (var filePath in files)
                {
                    if (Path.GetExtension(filePath) != ".txt")
                        continue;

                    string fileName = Path.GetFileName(filePath);
                    if (fileName.ToLower().Contains("npc"))
                        continue;

                    needExportCount++;
                    selectedCharacterType = PTCharacterType.Hero;
                    modelNameIndex = fileName.Substring(4, 3);
                    ParseTemplate(Path.Combine(AEConfig.ANIMATOR_INSTANCE_PATH, fileName));
                    if (curTemplate != null)
                    {
                        ExportSync(curTemplate, selectedCharacterType, modelNameIndex, () => { exportedCount++; });
                    }
                }
            }
        }

        private void ExportExistNpcs()
        {
            if (GUILayout.Button("ExportExistNpcs", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                exportingAll = true;
                needExportCount = 0;
                exportedCount = 0;
                exportDatas.Clear();

                // 获取所有导出过的文件
                string[] files = Directory.GetFiles(AEConfig.ANIMATOR_INSTANCE_PATH);
                foreach (var filePath in files)
                {
                    if (Path.GetExtension(filePath) != ".txt")
                        continue;

                    string fileName = Path.GetFileName(filePath);
                    if (fileName.ToLower().Contains("hero"))
                        continue;

                    needExportCount++;
                    selectedCharacterType = PTCharacterType.Npc;
                    modelNameIndex = fileName.Substring(3, 3);
                    ParseTemplate(Path.Combine(AEConfig.ANIMATOR_INSTANCE_PATH, fileName));
                    if (curTemplate != null)
                    {
                        ExportSync(curTemplate, selectedCharacterType, modelNameIndex, () => { exportedCount++; });
                    }
                }
            }
        }

        private void ExportAllExistActors()
        {
            if (GUILayout.Button("ExportAllExistActors", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                exportingAll = true;
                needExportCount = 0;
                exportedCount = 0;
                exportDatas.Clear();

                // 获取所有导出过的文件
                string[] files = Directory.GetFiles(AEConfig.ANIMATOR_INSTANCE_PATH);
                foreach (var filePath in files)
                {
                    if (Path.GetExtension(filePath) != ".txt")
                        continue;

                    needExportCount++;
                    string fileName = Path.GetFileName(filePath);

                    if (fileName.ToLower().Contains("hero"))
                    {
                        selectedCharacterType = PTCharacterType.Hero;
                        modelNameIndex = fileName.Substring(4, 3);
                    }
                    else
                    {
                        selectedCharacterType = PTCharacterType.Npc;
                        modelNameIndex = fileName.Substring(3, 3);
                    }
                    ParseTemplate(Path.Combine(AEConfig.ANIMATOR_INSTANCE_PATH, fileName));
                    if (curTemplate != null)
                    {
                        ExportSync(curTemplate, selectedCharacterType, modelNameIndex, () => { exportedCount++; });
                    }
                }
            }
        }

        private void ExportExistHerosByTemplate()
        {
            if (GUILayout.Button("ExportExistHerosByTemplate", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                if (curTemplate == null)
                {
                    AEUtil.ShowNotification("You need select a template first!");
                    return;
                }

                exportingAll = true;
                needExportCount = 0;
                exportedCount = 0;
                exportDatas.Clear();

                string[] files = Directory.GetFiles(AEConfig.ANIMATOR_INSTANCE_PATH);
                foreach (var filePath in files)
                {
                    if (Path.GetExtension(filePath) != ".txt")
                        continue;

                    string fileName = Path.GetFileName(filePath);
                    if (fileName.ToLower().Contains("npc"))
                        continue;

                    needExportCount++;
                    selectedCharacterType = PTCharacterType.Hero;
                    modelNameIndex = fileName.Substring(4, 3);
                    ExportSync(curTemplate, selectedCharacterType, modelNameIndex, () => { exportedCount++; });
                }
            }
        }

        private void ExportExistNpcsByTemplate()
        {
            if (GUILayout.Button("ExportExistNpcsByTemplate", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                if (curTemplate == null)
                {
                    AEUtil.ShowNotification("You need select a template first!");
                    return;
                }

                string[] files = Directory.GetFiles(AEConfig.ANIMATOR_INSTANCE_PATH);
                foreach (var filePath in files)
                {
                    if (Path.GetExtension(filePath) != ".txt")
                        continue;

                    string fileName = Path.GetFileName(filePath);
                    if (fileName.ToLower().Contains("hero"))
                        continue;

                    needExportCount++;
                    selectedCharacterType = PTCharacterType.Npc;
                    modelNameIndex = fileName.Substring(3, 3);
                    ExportSync(curTemplate, selectedCharacterType, modelNameIndex, () => { exportedCount++; });
                }
            }
        }

        private void ExportAllHerosByTemplate()
        {
            if (GUILayout.Button("ExportAllHerosByTemplate", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                if (curTemplate == null)
                {
                    AEUtil.ShowNotification("You need select a template first!");
                    return;
                }
                List<string> indices = new List<string>();
                foreach (string dir in fDirs)
                    indices.Add(dir.Substring(dir.LastIndexOf("\\") + 1, 3));

                exportingAll = true;
                needExportCount = indices.Count;
                exportedCount = 0;
                exportDatas.Clear();
                foreach (var index in indices)
                {
                    ExportSync(curTemplate, PTCharacterType.Hero, index, () => { exportedCount++; });
                }
            }
        }

        private void ExportAllNpcsByTemplate()
        {
            if (GUILayout.Button("ExportAllNpcsByTemplate", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                if (curTemplate == null)
                {
                    AEUtil.ShowNotification("You need select a template first!");
                    return;
                }
                List<string> indices = new List<string>();
                foreach (string dir in fEnemyDirs)
                    indices.Add(dir.Substring(dir.LastIndexOf("\\") + 1, 3));

                exportingAll = true;
                needExportCount = indices.Count;
                exportedCount = 0;
                exportDatas.Clear();
                foreach (var index in indices)
                {
                    ExportSync(curTemplate, PTCharacterType.Npc, index, () => { exportedCount++; });
                }
            }
        }
        private void DoHotfix()
        {
            if (GUILayout.Button("HotFix: Don't Touch!", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                AEUtil.SetAllTransitionInterruptType(UnityEditor.Animations.TransitionInterruptionSource.Destination);
            }
        }


        private Queue<ExportData> exportDatas = new Queue<ExportData>();
        private class ExportData
        {
            public AETemplate Template;
            public PTCharacterType Type;
            public string Index;
            public System.Action Callback;
        }

        private void ExportSync(AETemplate template, PTCharacterType type, string index, System.Action callback)
        {
            ExportData data = new ExportData() { Template = template, Type = type, Index = index, Callback = callback };
            exportDatas.Enqueue(data);
        }

        private void ExportOne()
        {
            if (GUILayout.Button("Export", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                if (curTemplate != null)
                {
                    AEUtil.ShowNotification(string.Format("Exporting {0} {1}", selectedCharacterType, modelNameIndex));
                    curTemplate.Export(selectedCharacterType, modelNameIndex);
                }
                else
                {
                    AEUtil.ShowNotification("You need select export info first!");
                }
                curTemplate = null;
            }
        }

        private void SelectCharacterType()
        {
            if (characterTypes == null)
            {
                characterTypes = Enum.GetValues(typeof(PTCharacterType)).Cast<PTCharacterType>().Select(v => v.ToString()).ToArray();
            }
            selectedCharacterType = (PTCharacterType)EditorGUILayout.Popup((int)selectedCharacterType, characterTypes.ToArray(),
                GUILayout.Width(AEConfig.POPUP_COLUMN_WIDTH),
                GUILayout.Height(AEConfig.LINE_HEIGHT));
            if (selectedCharacterType != oldCharacterType)
            {
                curTemplate = null;
                oldCharacterType = selectedCharacterType;
            }
        }

        private void SelectCharacter()
        {
            modelNames.Clear();
            if (selectedCharacterType == PTCharacterType.Hero)
            {
                foreach (string dir in fDirs)
                    modelNames.Add(dir.Substring(dir.LastIndexOf("\\") + 1, 3));
                idx = EditorGUILayout.Popup(idx, modelNames.ToArray(),
                    GUILayout.Width(AEConfig.POPUP_COLUMN_WIDTH),
                    GUILayout.Height(AEConfig.LINE_HEIGHT));

                modelNameIndex = modelNames[idx];

            }
            else if (selectedCharacterType == PTCharacterType.Npc)
            {
                foreach (string dir in fEnemyDirs)
                    modelNames.Add(dir.Substring(dir.LastIndexOf("\\") + 1, 3));
                idx = EditorGUILayout.Popup(idx, modelNames.ToArray());
                modelNameIndex = modelNames[idx];
            }
            if (modelNameIndex != oldModelNameIndex)
            {
                curTemplate = null;
                oldModelNameIndex = modelNameIndex;
            }
        }

        private void UpdateModelDirectory()
        {
            // get hero directory list
            string[] dirs = Directory.GetDirectories("Assets/Content/Character/Hero");

            // filter with directories' names
            System.Text.RegularExpressions.Regex searchTerm =
                new System.Text.RegularExpressions.Regex(@"\d{3}$");

            var filterdDirs = from dir in dirs
                              where (searchTerm.IsMatch(dir))
                              select dir;

            fDirs.Clear();
            fDirs = filterdDirs.ToList();

            // get enmey directory list
            string[] enemydirs = Directory.GetDirectories("Assets/Content/Character/Npc");

            // filter with directories' names
            System.Text.RegularExpressions.Regex enmeysearchTerm =
                new System.Text.RegularExpressions.Regex(@"\d{3}$");

            var enemyFilterdDirs = from enemydir in enemydirs
                                   where (enmeysearchTerm.IsMatch(enemydir))
                                   select enemydir;

            fEnemyDirs.Clear();
            fEnemyDirs = enemyFilterdDirs.ToList();

            return;
        }

        private void LoadTemplate()
        {
            if (GUILayout.Button("LoadTemplate", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                string filename = LoadTemplateFile();
                if (string.IsNullOrEmpty(filename))
                    return;

                ParseTemplate(Path.Combine(AEConfig.ANIMATOR_TEMPLATE_PATH, Path.GetFileName(filename)));
            }
        }

        private void SaveTemplate()
        {
            if (GUILayout.Button("SaveTemplate", GUILayout.Width(AEConfig.BUTTON_COLUMN_WIDTH)))
            {
                if (curTemplate == null)
                {
                    AEUtil.ShowNotification("Template is empty");
                    return;
                }

                if (!Directory.Exists(AEConfig.ANIMATOR_TEMPLATE_PATH))
                    Directory.CreateDirectory(AEConfig.ANIMATOR_TEMPLATE_PATH);

                string filename = EditorUtility.SaveFilePanel("Save Animator Template File", AEConfig.ANIMATOR_TEMPLATE_PATH, "AnimatorTemplate", "txt");
                curTemplate.Save(filename);
            }
        }

        private string LoadTemplateFile()
        {
            if (!Directory.Exists(AEConfig.ANIMATOR_TEMPLATE_PATH))
                Directory.CreateDirectory(AEConfig.ANIMATOR_TEMPLATE_PATH);

            return EditorUtility.OpenFilePanel("Load Animator Template File", AEConfig.ANIMATOR_TEMPLATE_PATH, "txt");
        }

        private void ParseTemplate(string filename)
        {
            TextAsset asset = AssetDatabase.LoadAssetAtPath<TextAsset>(filename);
            if (asset == null)
            {
                AEUtil.ShowNotification(string.Format("Can not found file [{0}]", filename));
                return;
            }
            curTemplate = new AETemplate();
            LitJson.JsonData data = LitJson.JsonMapper.ToObject(asset.text);
            curTemplate.ParseFromJson(data);
        }
    }
}
