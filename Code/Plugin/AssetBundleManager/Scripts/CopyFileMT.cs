using UnityEngine;
using System.Collections;
using System.Collections.Generic;

using System.Threading;



public class CopyFileMT : MonoBehaviour
{
    
    static CopyFileMT instance;

    static string streamingPath;
    static string persistentDataPath;

    static List<string> soundList;
    static int soundIdx;


    public static CopyFileMT GetInstance()
    {
        if (instance == null)
        {
            streamingPath = Application.streamingAssetsPath;
            persistentDataPath = Application.persistentDataPath;
            Debug.Log("Create");
            GameObject go = new GameObject("CopyFileMT");
            DontDestroyOnLoad(go);
            instance = go.AddComponent<CopyFileMT>();
        }
        return instance;
    }

    public void SetSoundList(List<string> lst)
    {
        soundList = lst;
    }

    void FixedUpdate()
    {
        if (soundList!=null && soundIdx < soundList.Count)
        {
            string fullPathInPersistent = string.Format("{0}/{1}", Application.persistentDataPath, soundList[soundIdx]);
            if (!System.IO.File.Exists(fullPathInPersistent))
            {
                FileUtils.LoadBytesFromFileSystem(soundList[soundIdx], false);
            }
            soundIdx++;
        }
    }


    void CopyFileStreamToPersist(string name, byte[] data)
    {
        try
        {
            //byte[] data = ReadBytesFromStreaming(filename, false);
            string filename = persistentDataPath + "/" + name;
            
            FileUtils.WriteFile(filename, data, false);
        }
        catch (System.Exception e)
        {
            Debug.LogError(e.ToString());
        }
    }

    
    public void AddFile(string s, byte[] data)
    {
        Loom.RunAsync(()=>{
            CopyFileStreamToPersist(s, data);
        });

    }


}
