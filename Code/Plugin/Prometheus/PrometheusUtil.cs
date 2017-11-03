using UnityEngine;
using System.Collections.Generic;
using UnityEditor;
using System.Reflection;
using System;

public  static class PrometheusUtil
{
    public static GameObject curCharacter;
    public static string modelName;
    public static string baseModelPath;
    public static PTCharacterType curCharacterType;

    public static readonly string GraphDesPath = "Assets/Content/PTGraphs/One.asset";
    public static readonly string GraphPath = "Assets/Content/PTGraphs/";

    private static Assembly assembly;

    private static Dictionary<int, string> effects = new Dictionary<int, string>();

    public static PTGraph LoadGraph(string graphName)
    {
        var asset = AssetDatabase.LoadAssetAtPath<PTGraph>(GraphPath + graphName + ".asset");
        if(null == asset) {
            asset = ScriptableObject.CreateInstance<PTGraph>();
            AssetDatabase.CreateAsset(asset, GraphPath + graphName + ".asset");
            AssetDatabase.Refresh();
            asset.assetName = graphName;
        }
        return asset;
    }

    public static string GetEffect(int id)
    {
        if (effects.Count == 0)
        {
            TextAsset csv = AssetDatabase.LoadAssetAtPath<TextAsset>("Assets/Res/Data/Effect.txt");
            CSVReader.LoadText(csv.text, (object[] values) =>
            {
                effects.Add((int)values[0], (string)values[2]);
            });
        }

        string path;
        if (effects.TryGetValue(id, out path))
            return path;
        return string.Empty;
    }
}
