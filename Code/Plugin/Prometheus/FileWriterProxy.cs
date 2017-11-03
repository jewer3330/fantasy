using System.IO;
using System;

public class FileWriterProxy
{
    public static bool Write(string fileName, string content)
    {
        StreamWriter sw = null;
        try {
            sw = new StreamWriter(fileName, false);
            sw.Write(content);
            sw.Close();
        }
        catch (Exception) {
            if (sw != null)
                sw.Close();
            return false;
        }
        return true;
    }

}
