using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

 class ChangeColor : MonoBehaviour{
    [SerializeField]
     GameObject sphere,cube,cylinder;
     Renderer sphereRenderer,cubeRenderer,cylinderRenderer;
     Color newSphereColor;
     
     float randomChannelOne,randomChannelTwo,randomChannelThree;
    // Start is called before the first frame update
    void Start()
    {
        sphereRenderer=sphere.GetComponent<Renderer>();
        cubeRenderer=cube.GetComponent<Renderer>();
        cylinderRenderer=cylinder.GetComponent<Renderer>();
        GetComponent<Button>().onClick.AddListener(ChangeSphereColor);

    }
     
     void ChangeSphereColor()
    {
        randomChannelOne=Random.Range(0f,1f);
        randomChannelTwo=Random.Range(0f,1f);
        randomChannelThree=Random.Range(0f,1f);
        newSphereColor=new Color(randomChannelOne,randomChannelTwo,randomChannelThree,1f);
        sphereRenderer.material.SetColor("_Color",newSphereColor);
        cubeRenderer.material.SetColor("_Color",newSphereColor);
        cylinderRenderer.material.SetColor("_Color",newSphereColor);

    }

    // Update is called once per frame
 
}