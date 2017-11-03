using UnityEngine;
using System.Collections;
using LitJson;

[System.Serializable]
public class Version
{
    public string versionString = "1.0.0";
    public const string fileName = "version.dat";
	public const string appleFileName = "appleversion.dat";
    public int[] versionNums = new int[3] { 1, 0, 0 };
    


    public static bool operator ==(Version lhs, Version rhs)
    {

        if (object.Equals(lhs, null) || object.Equals(rhs, null))
        {
            return object.Equals(lhs, rhs);
        } 

        if (lhs.versionNums != null && rhs.versionNums != null &&
            lhs.versionNums.Length == rhs.versionNums.Length &&
            lhs.versionNums.Length == 3)
        {
            if (lhs.versionNums[0] == rhs.versionNums[0] &&
                lhs.versionNums[1] == rhs.versionNums[1] &&
                lhs.versionNums[2] == rhs.versionNums[2])
                return true;
        }
        return false;
    }

    public static bool operator !=(Version lhs, Version rhs)
    {
        if (object.Equals(lhs, null) || object.Equals(rhs, null))
        {
            return !object.Equals(lhs, rhs);
        }

        return !(lhs == rhs);
    }

    public static bool operator >(Version lhs, Version rhs)
    {
         
        if (lhs.versionNums != null && rhs.versionNums != null &&
            lhs.versionNums.Length == rhs.versionNums.Length &&
            lhs.versionNums.Length == 3)
        {
            if (lhs.versionNums[0] > rhs.versionNums[0])
            {
                return true;
            }
            else
            {
                if (lhs.versionNums[0] == rhs.versionNums[0])
                {
                    if (lhs.versionNums[1] > rhs.versionNums[1])
                    {
                        return true;
                    }
                    else
                    {
                        if (lhs.versionNums[1] == rhs.versionNums[1])
                        {
                            if (lhs.versionNums[2] > rhs.versionNums[2])
                            {
                                return true;
                            }
                            else
                            {
                                if (lhs.versionNums[2] == rhs.versionNums[2])
                                {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }

        return false;
    }


    public override string ToString()
    {
        return versionString;
    }

    public static bool operator <(Version lhs, Version rhs)
    {
        if (lhs == rhs)
            return false;
        else
            return rhs > lhs;
    }

    public Version(string version)
    {
        Parse(version);
    }

    public Version(int buildCode, int bigCode, int littleCode)
    {
        Parse(buildCode, bigCode, littleCode);
    }

    public Version(int[] version)
    {

        Parse(version);
    }

    public void Parse(string version)
    {
        this.versionString = version;
        string[] versionNums = version.Split('.');
        for (int i = 0; i < 3; i++)
        {
            this.versionNums[i] = int.Parse(versionNums[i]);
        }
    }

    public void Parse(int[] version)
    {
        versionString = "";
        for (int i = 0; i < 3; i++)
        {
            this.versionNums[i] = version[i];
            this.versionString += version[i].ToString() + ".";
        }

        versionString = this.versionString.Substring(0, this.versionString.Length - 1);
    }

    public void Parse(int buildCode, int bigCode, int littleCode)
    {
        versionNums[0] = buildCode;
        versionNums[1] = bigCode;
        versionNums[2] = littleCode;

        this.versionString = buildCode + "." + bigCode + "." + littleCode;
    }

    public int GetBuildVersion()
    {
        return versionNums[0];
    }

    public int GetBigVersion()
    {
        return versionNums[1];
    }

    public int GetLittleVersion()
    {
        return versionNums[2];
    }

    public void UpgradeBigVersion()
    {
        this.versionNums[1]++;
        this.versionNums[2] = 0;
        Parse(versionNums);

    }

    public void UpgradeLittleVersion()
    {
        this.versionNums[2]++;
        Parse(versionNums);
    }

    

    public bool isEqual(Version v)
    {
        return this.versionString == v.versionString;
    }

    public bool isEqual(string v)
    {
        return this.versionString == v;
    }


    public static string LoadResVersion(bool local)
    {
        string content = "";
        if(local)
        {
            content = FileUtils.ReadStringFromStreaming(fileName, false);
        }
        else
        {
            FileUtils.ReadFileInPersistent(fileName, ref content, false);
        }
        return content;
    }

    public static bool ComparerResVersion()
    {
        string local = LoadResVersion(true);
        string persist = LoadResVersion(false);
        return local.Equals(persist);
    }


    /// <summary>
    /// 查找路径优先级
    /// 先读缓存目录
    /// 再读流媒体目录
    /// </summary>
    public static Version LoadVersion()
    {
        string content = "";
        FileUtils.ReadFileInPersistent(fileName, ref content, false);

        if (!string.IsNullOrEmpty(content))
        {
            return new Version(content);
        }
        else
        {

            content = FileUtils.ReadStringFromStreaming(fileName, false);
            if (!string.IsNullOrEmpty(content))
            {
                return new Version(content);
            }
        }

        return new Version(1, 0, 0);

    }

    /// <summary>
    /// 和LoadCodeVersion功能一致，提供一个int类型的值
    /// </summary>
    /// <returns></returns>
    public static int BuildCode()
    {
        string content = FileUtils.ReadStringFromStreaming("versionCode.txt");
        if (!string.IsNullOrEmpty(content))
        {
            content = content.Replace("\r\n", "\r").Replace("\r", "");
            return int.Parse(content);
        }
        return 1;
    }

    /// <summary>
    /// 和BuildCode一一对应 ，但是形式是x.x.x
    /// </summary>
    /// <returns></returns>
    public static Version LoadCodeVersion()
    {

        return Version.LoadVersionFromStreamingAsset();
    }

    public static Version LoadVersionFromStreamingAsset()
    {
        string content = FileUtils.ReadStringFromStreaming(fileName, false);
        content = content.Replace("\r\n", "\n").Replace("\n", "");
        if (!string.IsNullOrEmpty(content))
        {
            return new Version(content);
        }
        return new Version(1, 0, 0);
    }

	public static string LoadAppleVersionFromStreamingAsset()
	{
		string content = FileUtils.ReadStringFromStreaming(appleFileName, false);
        content = content.Replace("\r\n", "\n").Replace("\n", "");
		if (string.IsNullOrEmpty(content))
		{
			return "1.0.0";
		}
		return content;
	}

    /// <summary>
    /// 直接存到缓存目录
    /// </summary>
    /// <param name="v"></param>
    public static void SaveVersion(Version v)
    {
        FileUtils.WriteFileInPersistent(fileName, v.ToString(), false);
    }

    /// <summary>
    /// 存入流媒体目录
    /// </summary>
    /// <param name="v"></param>
    public static void SaveVersion2StreamingAsset(Version v)
    {
        FileUtils.WriteFile(string.Format("{0}/{1}", Application.streamingAssetsPath, fileName), v.ToString(), false);
    }


    //public static Version LoadFromCDN()
    //{
    //    try
    //    {
    //        string versionURL = string.Format("{0}/{1}/{2}", FileUtils.url, ResSetting.GetChannelRes(), "beta.dat")
    //               + "?time=" + System.DateTime.Now.Ticks + "&r=" + UnityEngine.Random.Range(int.MinValue, int.MaxValue);
    //        Version newVersion = new Version(1, 0, 0);
    //        bool isBeta = false;
    //        WWW www2 = new WWW(versionURL);
    //        if (FileUtils.Download(www2))
    //        {
    //            Debug.LogError("beta.dat --> " + www2.text);
    //            GameUpdater.VersionData vesion_data = JsonMapper.ToObject<GameUpdater.VersionData>(www2.text);
    //            vesion_data.betaList.Add(vesion_data.beta);
    //            Version codeVersion = Version.LoadCodeVersion();
    //            foreach (var version in vesion_data.betaList)
    //            {
    //                if (codeVersion.isEqual(version))
    //                {
    //                    isBeta = true;
    //                }
    //            }
    //            if (isBeta)
    //                newVersion = new Version(vesion_data.beta);
    //            else
    //                newVersion = new Version(vesion_data.relase);

    //            return newVersion;
    //        }
    //        else
    //        {
    //            return null;
    //        }


    //    }
    //    catch (System.Exception e)
    //    {
    //        Debug.LogError(e.ToString());
    //    }

    //    return null;

    //}


    public static IEnumerator LoadFromCDN(System.Action<Version> callback)
    {

        string versionURL = string.Format("{0}/{1}/{2}", FileUtils.url, ResSetting.GetChannelRes(), "beta.dat") + "?time=" + System.DateTime.Now.Ticks + "&r=" + UnityEngine.Random.Range(int.MinValue, int.MaxValue);

        WWW www = new WWW(versionURL);

        yield return www;

        if (string.IsNullOrEmpty(www.error))
        {
            Version newVersion = new Version(1, 0, 0);
            bool isBeta = false;
            Debug.LogError("beta.dat --> " + www.text);
            GameUpdater.VersionData vesion_data = null;
            try
            {
                vesion_data = JsonMapper.ToObject<GameUpdater.VersionData>(www.text);
            }
            catch (System.Exception e)
            {
                Debug.LogError(e.ToString());
                if (callback != null) callback(null);
            }

            vesion_data.betaList.Add(vesion_data.beta);
            Version codeVersion = Version.LoadCodeVersion();
            foreach (var version in vesion_data.betaList)
            {
                if (codeVersion.isEqual(version))
                {
                    isBeta = true;
                }
            }
            if (isBeta)
                newVersion = new Version(vesion_data.beta);
            else
                newVersion = new Version(vesion_data.relase);

            if (callback != null) callback(newVersion);
        }
        else
        {
            if (callback != null) callback(null);
        }

    }
}
