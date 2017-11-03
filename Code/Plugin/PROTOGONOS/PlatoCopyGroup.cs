using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class PlatoCopyGroup
{
    private List<PlatoNode> nodes = new List<PlatoNode>();
    private Dictionary<PlatoNode, PlatoNode> copyNodes = new Dictionary<PlatoNode, PlatoNode>();
    private Vector2 origin;

    public void AddNode(PlatoNode node)
    {
        nodes.Add(node);
    }

    public void AddNodes(List<PlatoNode> nodes)
    {
        this.nodes.AddRange(nodes);
    }

    public PlatoNode GetCopy(PlatoNode origin)
    {
        PlatoNode copy;
        if (!copyNodes.TryGetValue(origin, out copy))
            return null;
        return copy;
    }

    public void Copy(Vector2 pos, PLATO plato)
    {
        int maxID = plato.MaxNodeID;
        copyNodes.Clear();

        // 查找左上角节点坐标
        origin = new Vector2(float.MaxValue, float.MaxValue);
        foreach (PlatoNode node in nodes)
        {
            if (node.Position.x < origin.x) origin.x = node.Position.x;
            if (node.Position.y < origin.y) origin.y = node.Position.y;
        }

        // 找到所有起始节点
        HashSet<PlatoNode> startNodes = new HashSet<PlatoNode>();
        foreach (PlatoNode node in nodes)
        {
            bool isStart = true;
            foreach (PlatoPin pin in node.GetAllInPins())
            {
                if (pin.Prevs.Count == 0)
                    continue;
                foreach (PlatoPin prev in pin.Prevs)
                {
                    if (InGroup(prev.ParentNode))
                    {
                        isStart = false;
                        break;
                    }
                }
            }
            if (isStart)
                startNodes.Add(node);
        }

        // 深度拷贝
        foreach (PlatoNode node in startNodes)
        {
            DeepCopy(node, pos, plato);
        }

        // 重建节点ID
        nodes.Sort();
        for (int i = 0; i < nodes.Count; ++i)
        {
            copyNodes[nodes[i]].ID = maxID + i + 1;
        }
        plato.MaxNodeID = maxID + nodes.Count;
    }

    void DeepCopy(PlatoNode node, Vector2 pos, PLATO plato)
    {
        PlatoNode copy;
        if (!copyNodes.TryGetValue(node, out copy))
        {
            copy = node.Clone(plato);
            copy.Position = pos + node.Position - origin;
            plato.graph.AddNode(copy);
            copyNodes.Add(node, copy);
        }

        foreach (PlatoPin pin in node.GetAllOutPins())
        {
            foreach (PlatoPin next in pin.Nexts)
            {
                if (!InGroup(next.ParentNode))
                    continue;

                PlatoNode copyNext;
                bool found = true;
                if (!copyNodes.TryGetValue(next.ParentNode, out copyNext))
                {
                    copyNext = next.ParentNode.Clone(plato);
                    copyNext.Position = pos + next.ParentNode.Position - origin;
                    plato.graph.AddNode(copyNext);
                    copyNodes.Add(next.ParentNode, copyNext);
                    found = false;
                }

                PlatoPin output = copy.FindPinByTitle(pin.Title, false);
                PlatoPin input = copyNext.FindPinByTitle(next.Title, true);

                if (output.Nexts.Contains(input) == false)
                {
                    output.AddNext(input);
                    input.AddPrev(output);
                }

                if (!found)
                    DeepCopy(next.ParentNode, pos, plato);
            }
        }
    }

    bool InGroup(PlatoNode node)
    {
        return nodes.Contains(node);
    }
}
