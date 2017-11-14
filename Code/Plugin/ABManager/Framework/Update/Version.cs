using UnityEngine;
using System.Collections;
using LitJson;
namespace SuperBoBo
{
    [System.Serializable]
    public class Version
    {
        public string versionString = "0.0.0";
        public const string fileName = "version.dat";
        int[] versionNums = new int[3] { 0, 0, 0 };

        public override int GetHashCode()
        {
            return versionString.GetHashCode();
        }

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
            if (string.IsNullOrEmpty(version))
            {
                this.versionString = "0.0.0";
            }
            else
            {
                this.versionString = version;
            }
            string[] versionNums = version.Split('.');
            if (versionNums.Length != 3)
            {
                Debug.LogErrorFormat("version length error {0}", version);
                this.versionString = "0.0.0";
                versionNums = versionString.Split('.');
            }
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

        public override bool Equals(object obj)
        {
            if (obj != null && obj is string)
            {
                return isEqual(obj as string);
            }
            return base.Equals(obj);
        }

        public bool isEqual(Version v)
        {
            return this.versionString == v.versionString;
        }

        public bool isEqual(string v)
        {
            return this.versionString == v;
        }

        /// <summary>
        /// 查找路径优先级
        /// 先读缓存目录
        /// 再读流媒体目录
        /// </summary>
        public static Version LoadResVersion()
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

            return new Version(0, 0, 0);

        }

        /// <summary>
        /// 和LoadCodeVersion功能一致，提供一个int类型的值
        /// </summary>
        /// <returns></returns>
        public static int BuildCode()
        {
            string content = FileUtils.ReadStringFromStreaming("config/versionCode.txt");
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
            return new Version(0, 0, 0);
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



    }
}