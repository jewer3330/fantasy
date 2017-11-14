using UnityEngine;
using System.Collections;

namespace SuperBoBo
{
/// <summary>
/// Action 抽象类
/// </summary>
public class Action
{
	public delegate void Func ();

	public delegate void TimeFunc (float delta);

	public virtual void Reset ()
	{

	}

	public virtual void Update ()
	{

	}

	public virtual bool IsFinished ()
	{
		return true;
	}

	public virtual void Pause ()
	{

	}

	public virtual void Resume ()
	{

	}

    
}
}
