using UnityEngine;
using System.Collections;
using System.IO;
using System.Text;
namespace SuperBoBo
{
    public class ResCommon
    {
        public static string GetFileMD5(string fileName)
        {
            try
            {
                FileStream file = new FileStream(fileName, FileMode.Open);
                System.Security.Cryptography.MD5 md5 = new System.Security.Cryptography.MD5CryptoServiceProvider();
                byte[] retVal = md5.ComputeHash(file);
                file.Close();

                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < retVal.Length; i++)
                {
                    sb.Append(retVal[i].ToString("x2"));
                }
                return sb.ToString();
            }
            catch (System.Exception ex)
            {
                Debug.LogError("GetMD5HashFromFile() fail,error:" + ex.Message);
                return "";
            }
        }
    }
}
