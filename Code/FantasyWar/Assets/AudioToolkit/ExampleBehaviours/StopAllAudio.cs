using UnityEngine;
using System.Collections;

public class StopAllAudio : AudioTriggerBase
{
    public float fadeOut = 0;

    protected override void _OnEventTriggered()
    {
        AudioController.StopAll( fadeOut );
    }

}
