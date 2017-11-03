using UnityEngine;
using System.Collections;
using ICSharpCode.SharpZipLib.Zip;
using System.IO;
using ICSharpCode.SharpZipLib.Checksums;
using System;

/// <summary>
/// Zip压缩与解压缩 
/// </summary>
public class ZipManager
{
	/// <summary>
	/// 压缩单个文件
	/// </summary>
	/// <param name="fileToZip">要压缩的文件</param>
	/// <param name="zipedFile">压缩后的文件</param>
	/// <param name="compressionLevel">压缩等级</param>
	/// <param name="blockSize">每次写入大小</param>
	public static void ZipFile(string fileToZip, string zipedFile, int compressionLevel, int blockSize)
	{
		//如果文件没有找到，则报错
		if (!System.IO.File.Exists(fileToZip))
		{
			throw new System.IO.FileNotFoundException("指定要压缩的文件: " + fileToZip + " 不存在!");
		}

		using (System.IO.FileStream ZipFile = System.IO.File.Create(zipedFile))
		{
			using (ZipOutputStream ZipStream = new ZipOutputStream(ZipFile))
			{
				using (System.IO.FileStream StreamToZip = new System.IO.FileStream(fileToZip, System.IO.FileMode.Open, System.IO.FileAccess.Read))
				{
					string fileName = fileToZip.Substring(fileToZip.LastIndexOf("/") + 1);

					ZipEntry ZipEntry = new ZipEntry(fileName);

					ZipStream.PutNextEntry(ZipEntry);

					ZipStream.SetLevel(compressionLevel);

					byte[] buffer = new byte[blockSize];

					int sizeRead = 0;

					try
					{
						do
						{
							sizeRead = StreamToZip.Read(buffer, 0, buffer.Length);
							ZipStream.Write(buffer, 0, sizeRead);
						}
						while (sizeRead > 0);
					}
					catch (System.Exception ex)
					{
						throw ex;
					}

					StreamToZip.Close();
				}

				ZipStream.Finish();
				ZipStream.Close();
			}

			ZipFile.Close();
		}
	}

	/// <summary>
	/// 压缩单个文件
	/// </summary>
	/// <param name="fileToZip">要进行压缩的文件名</param>
	/// <param name="zipedFile">压缩后生成的压缩文件名</param>
	public static void ZipFile(string fileToZip, string zipedFile)
	{
		//如果文件没有找到，则报错
		if (!File.Exists(fileToZip))
		{
			throw new System.IO.FileNotFoundException("指定要压缩的文件: " + fileToZip + " 不存在!");
		}

		using (FileStream fs = File.OpenRead(fileToZip))
		{
			byte[] buffer = new byte[fs.Length];
			fs.Read(buffer, 0, buffer.Length);
			fs.Close();

			using (FileStream ZipFile = File.Create(zipedFile))
			{
				using (ZipOutputStream ZipStream = new ZipOutputStream(ZipFile))
				{
					string fileName = fileToZip.Substring(fileToZip.LastIndexOf("/") + 1);
					ZipEntry ZipEntry = new ZipEntry(fileName);
					ZipStream.PutNextEntry(ZipEntry);
					ZipStream.SetLevel(5);

					ZipStream.Write(buffer, 0, buffer.Length);
					ZipStream.Finish();
					ZipStream.Close();
				}
			}
		}
	}

	/// <summary>
	/// 压缩多层目录
	/// </summary>
	/// <param name="strDirectory">The directory.</param>
	/// <param name="zipedFile">The ziped file.</param>
	public static void ZipFileDirectory(string strDirectory, string zipedFile)
	{
		if (File.Exists(zipedFile))
		{
			File.Delete(zipedFile);
		}
		ZipSetp(strDirectory, zipedFile);

	}


	private static void ZipSetp(string strDirectory,string zipedFile)
	{
		if (strDirectory[strDirectory.Length - 1] != Path.DirectorySeparatorChar)
		{
			strDirectory += Path.DirectorySeparatorChar;
		}

		strDirectory = strDirectory.Replace("\\", "/");

		string temp = "data.zip";

		System.IO.FileStream tfs = System.IO.File.Create(temp);
		ZipOutputStream s = new ZipOutputStream(tfs);

		Crc32 crc = new Crc32();

		//        string[] filenames = Directory.GetFileSystemEntries(strDirectory);
		string[] filenames = Directory.GetFiles(strDirectory,"*.*",SearchOption.AllDirectories);

		int count = 0;
		foreach (string f in filenames)// 遍历所有的文件和目录
		{
			string file = f.Replace("\\","/");

			if (file == zipedFile)
			{ 
				continue; 
			}
			//if (Directory.Exists(file))// 先当作目录处理如果存在这个目录就递归Copy该目录下面的文件
			//{
			//    string pPath = parentPath;
			//    pPath += file.Substring(file.LastIndexOf("/") + 1);
			//    pPath += "/";
			//    ZipSetp(file, s, pPath,zipedFile);
			//}
			else // 否则直接压缩文件
			{
				//打开压缩文件
				using (FileStream fs = File.OpenRead(file))
				{

					byte[] buffer = new byte[fs.Length];
					fs.Read(buffer, 0, buffer.Length);

					//string fileName = parentPath + file.Substring(file.LastIndexOf("/") + 1);
					string fileName = file.Replace(strDirectory, "");
					ZipEntry entry = new ZipEntry(fileName);

					entry.DateTime = DateTime.Now;
					entry.Size = fs.Length;

					fs.Close();

					crc.Reset();
					crc.Update(buffer);

					entry.Crc = crc.Value;
					s.PutNextEntry(entry);

					s.Write(buffer, 0, buffer.Length);
					#if UNITY_EDITOR
					UnityEditor.EditorUtility.DisplayProgressBar("压缩文件", file, (float)count /(float)filenames.Length);
					count++;
					#endif
				}

			}
		}

		s.Flush();
		tfs.Flush();

		s.Close();
		tfs.Close();

		Directory.Delete(strDirectory + "/" + "assetbundles",true);
		Directory.Delete(strDirectory + "/" + "Lua",true);

		File.Copy(temp, zipedFile);



		#if UNITY_EDITOR
		UnityEditor.AssetDatabase.SaveAssets();
		UnityEditor.AssetDatabase.Refresh();
		UnityEditor.EditorUtility.ClearProgressBar();
		#endif
	}

	/// <summary>
	/// 解压缩一个 zip 文件。
	/// </summary>
	/// <param name="zipedFile">The ziped file.</param>
	/// <param name="strDirectory">The STR directory.</param>
	/// <param name="password">zip 文件的密码。</param>
	/// <param name="overWrite">是否覆盖已存在的文件。</param>
	public static void UnZip(string zipedFile, string strDirectory, string password, bool overWrite,out float proc)
	{
		proc = 0f;
		if (strDirectory == "")
			strDirectory = Directory.GetCurrentDirectory();
		if (!strDirectory.EndsWith("/"))
			strDirectory = strDirectory + "/";

		using (ZipInputStream s = new ZipInputStream(File.OpenRead(zipedFile)))
		{
			s.Password = password;
			ZipEntry theEntry;

			FileInfo info = new FileInfo(zipedFile);

			while ((theEntry = s.GetNextEntry()) != null)
			{

				float process = (float)s.Position / (float)info.Length;
				proc = process;
//				#if UNITY_EDITOR
//				Debug.Log(string.Format("Available {0} Position {1} Length {2} {3}", s.Available, s.Position, info.Length, process));
//				UnityEditor.EditorUtility.DisplayProgressBar("解压中", theEntry.Name, process);
//				#endif
				string directoryName = "";
				string pathToZip = "";
				pathToZip = theEntry.Name;

				if (pathToZip != "")
					directoryName = Path.GetDirectoryName(pathToZip) + "/";

				string fileName = Path.GetFileName(pathToZip);

				Directory.CreateDirectory(strDirectory + directoryName);

				if (fileName != "")
				{
					if ((File.Exists(strDirectory + directoryName + fileName) && overWrite) || (!File.Exists(strDirectory + directoryName + fileName)))
					{
						using (FileStream streamWriter = File.Create(strDirectory + directoryName + fileName))
						{
							int size = 2048;
							byte[] data = new byte[2048];
							while (true)
							{
								size = s.Read(data, 0, data.Length);

								if (size > 0)
									streamWriter.Write(data, 0, size);
								else
									break;
							}
							streamWriter.Close();
						}
					}
				}
			}

			s.Close();
		}

//		#if UNITY_EDITOR
//		UnityEditor.EditorUtility.ClearProgressBar();
//		#endif
	}



}
