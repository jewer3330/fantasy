using UnityEngine;
using UnityEngine.UI;
using UnityEditor;
using System;
using System.Collections;
using System.Collections.Generic;

public class PlatoGraph
{
    private List<PlatoNode> nodes = new List<PlatoNode>();

    /// <summary>
    /// 添加节点
    /// </summary>
    /// <param name="node"></param>
    /// <returns></returns>
    public int AddNode(PlatoNode node)
    {
        nodes.Add(node);
        return node.ID;
    }

    /// <summary>
    /// 删除节点
    /// </summary>
    /// <param name="node"></param>
    public void RemoveNode(PlatoNode node)
    {
        nodes.Remove(node);
    }

    /// <summary>
    /// 删除所有节点
    /// </summary>
    public void RemoveAllNode()
    {
        nodes.Clear();
    }

    /// <summary>
    /// 绘制
    /// </summary>
    public void Draw(Rect wndRect, bool debug)
    {
        foreach (PlatoNode node in nodes.FindAll((x) => { return (x is CommentNode); }))
        {
            node.Draw(wndRect, debug);
        }
        foreach (PlatoNode node in nodes.FindAll((x) => { return !(x is CommentNode); }))
        {
            node.Draw(wndRect, debug);
        }
    }

    /// <summary>
    /// 获取所有节点
    /// </summary>
    /// <returns></returns>
    public List<PlatoNode> GetAllNodes()
    {
        return nodes;
    }

    /// <summary>
    /// 按名字查找节点
    /// </summary>
    /// <param name="title"></param>
    /// <returns></returns>
    public List<PlatoNode> FindNodesByTitle(string title)
    {
        return nodes.FindAll((PlatoNode p) => { return p.Title == title; });
    }

    /// <summary>
    /// 按类别查找节点
    /// </summary>
    /// <param name="category"></param>
    /// <returns></returns>
    public List<PlatoNode> FindNodesByCategory(string category)
    {
        return nodes.FindAll((PlatoNode p) => { return p.Category == category; });
    }

    /// <summary>
    /// 按ID查找节点
    /// </summary>
    /// <param name="id"></param>
    /// <returns></returns>
    public PlatoNode FindNodeByID(int id)
    {
        foreach (PlatoNode node in nodes)
        {
            if (node.ID == id)
                return node;
        }
        return null;
    }

    /// <summary>
    /// 获得所有自定义函数名
    /// </summary>
    /// <returns></returns>
    public List<string> GetFunctionNames()
    {
        List<string> result = new List<string>();
        List<PlatoNode> functionNodes = FindNodesByTitle("FunctionStart");
        foreach (PlatoNode node in functionNodes)
        {
            result.Add((string)node.FindPinByTitle("Name", true).Value);
        }
        return result;
    }
    
    /// <summary>
    /// 获取指定函数的IO引脚
    /// </summary>
    /// <param name="name"></param>
    /// <param name="inPins"></param>
    /// <param name="outPins"></param>
    public void GetFunctionIO(string name, List<PlatoPin> inPins, List<PlatoPin> outPins)
    {
        PlatoNode startNode = null;
        foreach (PlatoNode node in nodes)
        {
            if (node.Title == "FunctionStart")
            {
                PlatoPin namePin = node.FindPinByTitle("Name", true);
                if (namePin != null && (string)namePin.Value == name)
                {
                    startNode = node;
                    break;
                }
            }
        }
        if (startNode == null)
            return;

        // Input Pins
        inPins.Clear();
        for (int i = 0; i < startNode.GetDynamicPinCount(); ++i)
        {
            PlatoPin pin = startNode.FindDyanmicPinByIndex(i);
            inPins.Add(pin);
        }

        PlatoNode endNode = null;
        List<PlatoNode> nextNodes = startNode.GetAllNextNodes();
        foreach (PlatoNode node in nextNodes)
        {
            if (node.Title == "FunctionEnd")
            {
                endNode = node;
                break;
            }
        }
        if (endNode == null)
            return;

        // Output Pins
        outPins.Clear();
        for (int i = 0; i < endNode.GetDynamicPinCount(); ++i)
        {
            PlatoPin pin = endNode.FindDyanmicPinByIndex(i);
            outPins.Add(pin);
        }
    }

    /// <summary>
    /// 获取使用到的类别列表
    /// </summary>
    /// <returns></returns>
    public List<string> GetUsedCategories()
    {
        List<string> result = new List<string>();
        result.Add("Get");
        foreach (PlatoNode node in nodes)
        {
            if (!result.Contains(node.Category))
                result.Add(node.Category);
        }
        return result;
    }
    
    /// <summary>
    /// 获取使用到的节点列表
    /// </summary>
    /// <returns></returns>
    public List<string> GetUsedNodes()
    {
        List<string> result = new List<string>();
        foreach (PlatoNode node in nodes)
        {
            if (PLATO.FilterExport(node))
                continue;
            if (node.Category == "Get")
                continue;

            if (!result.Contains(node.Title))
                result.Add(node.Title);
        }
        return result;
    }

    /// <summary>
    /// 重置是否被导出标记
    /// </summary>
    public void ResetExported()
    {
        foreach (PlatoNode node in nodes)
        {
            node.ResetExported();
        }
    }
}
