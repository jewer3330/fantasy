using UnityEngine;
using System.Collections;

public class AnimationManager : MonoBehaviour
{

    private Animator animator;
    private Player player;

    private void Awake()
    {
        animator = GetComponent<Animator>();
        player = GetComponent<Player>();
    }

    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if (animator && player)
        {
            animator.SetBool("Run", player.currentSpeed > 0);
        }
    }

    public void Play(string animation)
    {
        if (animator)
        {
            animator.Play(animation);
        }
    }

    
}
