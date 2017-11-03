using UnityEngine;
using System.Collections;
using System.Collections.Generic;


/// <summary>
/// 拓扑排序
/// </summary>
public static class TopologicalSorter
{
    /// <summary>
    /// 节点颜色
    /// </summary>
    enum NodeColor
    {
        White,
        Gray,
        Black,
    }

    /// <summary>
    /// 深度优先搜索节点
    /// </summary>
    class DFSEntry
    {
        public NodeColor color = NodeColor.White;
        public int dtime; // 发现时间
        public int ftime; // 完成时间
        public PlatoNode node;
    }

    /// <summary>
    /// 深度优先排序
    /// </summary>
    /// <remarks>算法导论22.3</remarks>
    /// <param name="nodes">待排序节点</param>
    /// <returns></returns>
    static List<DFSEntry> DFS(List<PlatoNode> nodes)
    {
        HashSet<PlatoPin> edges = new HashSet<PlatoPin>();
        int time = 0;

        List<DFSEntry> entries = new List<DFSEntry>();
        foreach (PlatoNode node in nodes)
        {
            entries.Add(new DFSEntry() { node = node });
        }

        foreach (DFSEntry entry in entries)
        {
            if (entry.color == NodeColor.White)
                DFSVisit(entry, entries, edges, ref time);
        }
        return entries;
    }

    /// <summary>
    /// 深度优先排序
    /// </summary>
    /// <remarks>算法导论22.3</remarks>
    /// <param name="entry"></param>
    /// <param name="entries"></param>
    /// <param name="edges"></param>
    /// <param name="time"></param>
    static void DFSVisit(DFSEntry entry, List<DFSEntry> entries, HashSet<PlatoPin> edges, ref int time)
    {
        entry.color = NodeColor.Gray;
        entry.dtime = ++time;

        foreach (PlatoPin pin in entry.node.GetAllOutPins())
        {
            foreach (PlatoPin next in pin.Nexts)
            {
                DFSEntry adj = FindEntryByNode(next.ParentNode, entries);
                if (adj == null)
                    continue;

                // 是否有回环？
                if (!edges.Contains(pin))
                {
                    if (adj.color == NodeColor.Gray)
                        throw new System.Exception("不能有循环");
                    edges.Add(pin);
                }
                if (adj.color == NodeColor.White)
                {
                    DFSVisit(adj, entries, edges, ref time);
                }
            }
        }
        entry.color = NodeColor.Black;
        entry.ftime = ++time;
    }

    /// <summary>
    /// 在DFS节点中查找PLATO节点
    /// </summary>
    /// <param name="node"></param>
    /// <param name="entries"></param>
    /// <returns></returns>
    static DFSEntry FindEntryByNode(PlatoNode node, List<DFSEntry> entries)
    {
        foreach (DFSEntry entry in entries)
        {
            if (entry.node == node)
                return entry;
        }
        return null;
    }

    /// <summary>
    /// 拓扑排序
    /// </summary>
    /// <remarks>算法导论22.4</remarks>
    /// <param name="nodes"></param>
    /// <returns></returns>
    public static List<PlatoNode> Sort(List<PlatoNode> nodes)
    {
        List<DFSEntry> entries = DFS(nodes);
        entries.Sort((DFSEntry a, DFSEntry b) => b.ftime - a.ftime);

        List<PlatoNode> result = new List<PlatoNode>();
        foreach (DFSEntry entry in entries)
        {
            entry.node.ResetExported();
            result.Add(entry.node);
        }
        return result;
    }
}
