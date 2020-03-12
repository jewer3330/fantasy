using UnityEngine;
using System.Collections;

public class AnimationManager : MonoBehaviour
{

    private Animator animator;
    public Player player;

    private void Awake()
    {
        animator = GetComponent<Animator>();
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

    public void Attack()
    {
        if (animator)
        {
            animator.SetTrigger("Melee Right Attack 01");
        }
    }

    public void Hurt()
    {
        if (animator)
        {
            animator.SetTrigger("Take Damage");
        }
    }

    
}
