using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class ChangeTexture : MonoBehaviour
{
[SerializeField]
GameObject cube;

[SerializeField]
GameObject sphere;

[SerializeField]
GameObject cylinder;

[SerializeField]
Texture[] textures;

Renderer cr,cr1,cr2;
int ri;


    // Start is called before the first frame update
    void Start()
    {
        cr=cube.GetComponent<Renderer>();
         cr1=sphere.GetComponent<Renderer>();
          cr2=cylinder.GetComponent<Renderer>();
        gameObject.GetComponent<Button>().onClick.AddListener(ChangeCubeTexture);
       
    }

    // Update is called once per frame
    void ChangeCubeTexture()
    {
        ri=Random.Range(0,textures.Length);
        cr.material.mainTexture=textures[ri];
        cr1.material.mainTexture=textures[ri];
        cr2.material.mainTexture=textures[ri];
    }
}