using UnityEngine;
using System.Collections;
using System.IO;

public class PlatoWriter
{
    private int indentLevel;
    private TextWriter writer;
    private string filename;

    public string Filename { get { return filename; } }

    public PlatoWriter(PlatoWriter writer)
    {
        this.filename = writer.filename;
        this.indentLevel = writer.indentLevel;
        this.writer = new StringWriter();
    }

    public PlatoWriter(string filename)
    {
        this.filename = filename;
        writer = new StreamWriter(filename, false, new System.Text.UTF8Encoding());
    }

    public void PushIndent() { ++indentLevel; }
    public void PopIndent() { --indentLevel; }

    public void Line(string format, params object[] args)
    {
        if (writer == null)
            return;

        if (string.IsNullOrEmpty(format))
        {
            writer.WriteLine();
            return;
        }

        string line = string.Format(format, args);
        for (int i = 0; i < indentLevel; ++i)
        {
            line = "    " + line;
        }
        writer.WriteLine(line);
    }

    public void WriteWithoutIndent(string text)
    {
        if (writer == null || string.IsNullOrEmpty(text))
            return;

        writer.Write(text);
    }

    public void Close()
    {
        if (writer != null)
        {
            writer.Flush();
            writer.Close();
            writer = null;
        }
    }

    public string GetText()
    {
        if (writer is StringWriter)
            return writer.ToString();
        return string.Empty;
    }
}
