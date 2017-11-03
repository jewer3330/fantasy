using UnityEngine;
using System.Collections;
using System.IO;
using System;
using System.Collections.Generic;
#if UNITY_EDITOR
using UnityEditor;
#endif

public class ResSetting
{
    /// <summary>
    /// lastRes/[Platform]
    /// </summary>
    public static string build_root_path
    {
        get
        {
            return "lastRes/" + GetPlatformName();
        }
    }
    /// <summary>
    /// lastRes/[Platform]/assetbundles
    /// </summary>
    public static string build_ab_path
    {
        get
        {
            return build_root_path + "/assetbundles";    
        }
    }

    /// <summary>
    /// lastRes/[Platform]/[Version]
    /// </summary>
    public static string build_res_path
    {
        get
        {
            return build_root_path + "/" + Version.LoadVersionFromStreamingAsset();
        }
    } 

    //public static bool isDebug = true;


    /// <summary>
    /// 返回asset/[ChannelRes]/[Version]/assetbundles
    /// @warnning [ChannelRes] 平台特供
    /// </summary>
    /// <returns></returns>
    public static string AssetBundlesPath()
    {
        string outputPath = string.Format("{0}/{1}/{2}/{3}", AssetBundlesOutputPath, GetChannelRes(), Version.LoadVersionFromStreamingAsset(), "assetbundles");
        return outputPath;
    }

    /// <summary>
    /// 返回asset/[ChannelRes]/[Version]
    /// </summary>
    /// <returns></returns>
    public static string ResPath()
    {
        string outputPath = string.Format("{0}/{1}/{2}", AssetBundlesOutputPath, GetChannelRes(), Version.LoadVersionFromStreamingAsset());
        return outputPath;
    }



    /// <summary>
    /// "asset" 
    /// </summary>
    public static string AssetBundlesOutputPath
    {
        get
        {
            return "asset";
        }
    }

    private static string _channelResName = "quick";
    private static bool _isReadChannelResName;
    public static string channelResName
    {
        get
        {
#if UNITY_EDITOR
            string content = FileUtils.ReadStringFromStreaming("channel_res.dat", false);
            if (!string.IsNullOrEmpty(content))
            {

                _channelResName = content;
               return _channelResName;
                
            }
            else
            {
                return _channelResName;
            }

            
#else
            if (_isReadChannelResName == false)
            {
                _isReadChannelResName = true;
                string content = FileUtils.ReadStringFromStreaming("channel_res.dat", false);
            if (!string.IsNullOrEmpty(content))
            {

                _channelResName = content;
               return _channelResName;
                
            }
            else
            {
                return _channelResName;
            }

            }
            return _channelResName;
#endif

        }
    }

    /// <summary>
    /// "Android" | "iOS" | "WebGL" | "WebPlayer" | "Windows" | "OSX"
    /// </summary>
    /// <returns></returns>

    public static string GetPlatformName()
    { 
#if UNITY_EDITOR
      return GetPlatformForAssetBundles(EditorUserBuildSettings.activeBuildTarget);  
#else
      return GetPlatformForAssetBundles(Application.platform);
#endif
    }
    
    /// <summary>
    /// [chanelName](_debug|_release)/[Platform]
    /// </summary>
    /// <returns></returns>
    public static string GetChannelRes()
    {
        
        //if (FileUtils.isInternalNetwork)
        //{
        //    return channelResName + "_debug/" + GetPlatformName();
        //}
        //else
        //{
            return channelResName + "_release/" + GetPlatformName();
        //}      

    }
#if UNITY_EDITOR
    private static string GetPlatformForAssetBundles(BuildTarget target)
    {
        switch (target)
        {
            case BuildTarget.Android:
                return "Android";
            case BuildTarget.iOS:
                return "iOS";
            case BuildTarget.WebGL:
                return "WebGL";
            case BuildTarget.WebPlayer:
                return "WebPlayer";
            case BuildTarget.StandaloneWindows:
            case BuildTarget.StandaloneWindows64:
                return "Windows";
            case BuildTarget.StandaloneOSXIntel:
            case BuildTarget.StandaloneOSXIntel64:
            case BuildTarget.StandaloneOSXUniversal:
                return "OSX";
            // Add more build targets for your own.
            // If you add more targets, don't forget to add the same platforms to GetPlatformForAssetBundles(RuntimePlatform) function.
            default:
                return null;
        }
    }
#endif
    private static string GetPlatformForAssetBundles(RuntimePlatform platform)
    {
        switch (platform)
        {
            case RuntimePlatform.Android:
                return "Android";
            case RuntimePlatform.IPhonePlayer:
                return "iOS";
            case RuntimePlatform.WebGLPlayer:
                return "WebGL";
            case RuntimePlatform.OSXWebPlayer:
            case RuntimePlatform.WindowsWebPlayer:
                return "WebPlayer";
            case RuntimePlatform.WindowsPlayer:
                return "Windows";
            case RuntimePlatform.OSXPlayer:
                return "OSX";
            // Add more build targets for your own.
            // If you add more targets, don't forget to add the same platforms to GetPlatformForAssetBundles(RuntimePlatform) function.
            default:
                return null;
        }
    }




}

