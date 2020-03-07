/* !!auto gen do not change
 
 */

using UnityEngine;
using System.Collections;
using SuperBoBo;

namespace Table
{
    public class TableLoad
    {
/*
        public static void LoadFromMemory()
        {
            Character.LoadFromMemory();
            Map.LoadFromMemory();

        }
*/
        public static void LoadFromResources()
        {
            Character.LoadFromResources();
            Map.LoadFromResources();

        }

        public static void LoadBinFromResources()
        {
            Character.LoadBinFromResources();
            Map.LoadBinFromResources();

        }

        public static void LoadFromStreaming()
        {
            Character.LoadFromStreaming();
            Map.LoadFromStreaming();

        }

        public static void Clear()
        {
            Character.Clear();
            Map.Clear();

        }
		
        public static void UnLoad()
        {
            Character.UnLoad();
            Map.UnLoad();

        }
    }
}