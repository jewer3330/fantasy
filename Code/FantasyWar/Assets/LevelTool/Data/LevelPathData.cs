using UnityEngine;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class LevelPathNodeData : LevelBaseData
{
    public enum NodeType
    {
        Start,
        Middle,
        End
    }


    public NodeType type;
    public LevelPathNodeData()
    {

    }
    public LevelPathNodeData(string name, NodeType type)
    {
        this.type = type;
        this.name = name;
    }

    public LevelPathNodeData(LevelPathNode node)
    {
        LevelPathNodeData data = (LevelPathNodeData)node.GetData();
        name = data.name;
        pos = data.pos;
        type = data.type;
    }

    public override LevelBaseData Clone()
    {
        return (LevelPathNodeData)this.MemberwiseClone();
    }


   

    public override void Copy(LevelBaseData b)
    {
        base.Copy(b);
        LevelPathNodeData o = b as LevelPathNodeData;
        this.ID = o.ID;
        this.name = o.name;
        this.type = o.type;

    }

}


[System.Serializable]
public class LevelPathData : LevelBaseData
{

    public List<LevelPathNodeData> nodes = new List<LevelPathNodeData>();



    private LevelPathNodeData currentNode;

    /// <summary>
    /// 不允许反复添加新的节点
    /// </summary>
    /// <param name="node">新的节点</param>
    public void AddNode(LevelPathNodeData node)
    {
        if (currentNode != node)
        {
            currentNode = node;
            nodes.Add((LevelPathNodeData)node);
        }
        return;
    }


    public Vector3[] GetPoints()
    {
        List<Vector3> points = new List<Vector3>();
        foreach (var k in nodes)
        {

            points.Add(k.pos);
        }

        return points.ToArray();
    }

    public override string ToString()
    {
        string ret = "";
        for (int i = 0; i < nodes.Count; i++)
        {
            ret = ret + nodes[i].name + "->";
        }

        int lenth = ret.LastIndexOf("->");
        if (lenth > 0)
            ret = ret.Substring(0, lenth);

        return ret;
    }

    //public override void Save(Level.LevelData data)
    //{
    //    data.m_listPath.Add(DatasAdapter.ChangeToLevelPathData(this));
    //}

    public override void Save(LevelMapData data)
    {
        data.pathDatas.Add(this);
    }

    public override void Copy(LevelBaseData b)
    {
        base.Copy(b);
        LevelPathData o = b as LevelPathData;
        this.ID = o.ID;
        this.name = o.name;
        this.nodes = o.nodes;

    }
}

