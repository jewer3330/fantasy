using UnityEngine;
using System.Collections.Generic;
using UnityEditor;
using System.Reflection;
using System;

public static class WeaponEditorUtil
{
    public static GameObject curCharacter;
    public static string modelName;
    public static string baseModelPath;
    public static PTCharacterType curCharacterType;

    public static readonly string GraphDesPath = "Assets/Content/PTGraphs/One.asset";
    public static readonly string WeaponGraphPath = "Assets/Content/WeaponGraphs/";

    public static WeaponGraph LoadGraph(string graphName)
    {
        var asset = AssetDatabase.LoadAssetAtPath<WeaponGraph>(WeaponGraphPath + graphName + ".asset");
        if(null == asset) {
            asset = ScriptableObject.CreateInstance<WeaponGraph>();
            AssetDatabase.CreateAsset(asset, WeaponGraphPath + graphName + ".asset");
            AssetDatabase.Refresh();
            asset.assetName = graphName;
        }
        return asset;
    }
    public static ProjectileGraph LoadProjGraph(string graphName)
    {
        var asset = AssetDatabase.LoadAssetAtPath<ProjectileGraph>(WeaponGraphPath + graphName + ".asset");
        if (null == asset)
        {
            asset = ScriptableObject.CreateInstance<ProjectileGraph>();
            AssetDatabase.CreateAsset(asset, WeaponGraphPath + graphName + ".asset");
            AssetDatabase.Refresh();
            asset.assetName = graphName;
        }
        return asset;
    }

}
