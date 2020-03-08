using UnityEngine;
using System.Collections;

public class MapCellIndicator : MonoBehaviour {

    public LevelManager levelManager;
    public MapCell mapCell;
    public float alpha;
    public Renderer render;
    public Color orign;
    public bool startHighLight;
	// Use this for initialization
	void Start () {
        SelectGameObject.instance.AddListener(gameObject,Instance_ClickCallback);
        render = GetComponent<Renderer>();
        orign = render.material.color;
    }
	
	// Update is called once per frame
	void Update () {
	    if(startHighLight)
        {
            alpha = Mathf.PingPong(Time.time, 1);
            Color color = new Color(orign.r, orign.g, orign.b, alpha + orign.a);
            render.material.color = color;
        }

	}

    void Instance_ClickCallback(GameObject obj)
    {
        if(levelManager && levelManager.state == LevelManager.State.Select)
        {
            Debug.LogFormat("Click ({0},{1}),G => {2} " , mapCell.data.x , mapCell.data.y,mapCell.steps);
            if (levelManager.select != null )
                levelManager.select.SetHighLight(false);
            levelManager.select = this;
        }
    }

    public void SetHighLight(bool highLight)
    {
        alpha = 1f;
        startHighLight = highLight;
        render.material.color = orign;
    }


}
