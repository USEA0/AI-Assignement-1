// Boris Au - 100660279
// INFR4320 Fall 2020
// Player movement and interaction controller

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerController : MonoBehaviour
{
    // player is active bool
    public bool canMove = false;

    // set movement speed
    public float speed = 3.0f;

    // within door boundries 
    public bool isClose = false;
    public bool safe = false;

    // ui elements
    public Text doorOpen;
    public Text safeCondition;
    public Text dangerCondition;

    GameManager gameManager;

    void Start()
    {
        gameManager = GameObject.FindObjectOfType<GameManager>();
    }

    // Update is called once per frame
    void Update()
    {
        if (canMove)
        {
            // sprint speed
            if (Input.GetKey(KeyCode.LeftShift))
            {
                speed = 7.0f;
            }
            else
            {
                speed = 3.0f;
            }

            // WASD controls for player
            if (Input.GetKey(KeyCode.W))
            {
                transform.Translate(Vector3.forward * Time.deltaTime * speed);
            }
            if (Input.GetKey(KeyCode.A))
            {
                transform.Translate(Vector3.left * Time.deltaTime * speed);
            }
            if (Input.GetKey(KeyCode.S))
            {
                transform.Translate(Vector3.back * Time.deltaTime * speed);
            }
            if (Input.GetKey(KeyCode.D))
            {
                transform.Translate(Vector3.right * Time.deltaTime * speed);
            }

            // Rotation controls
            if (Input.GetKey(KeyCode.E))
            {
                transform.Rotate(0.0f, 0.5f, 0.0f, Space.Self);
            }
            if (Input.GetKey(KeyCode.Q))
            {
                transform.Rotate(0.0f, -0.5f, 0.0f, Space.Self);
            }

            // Reset Character
            if (Input.GetKey(KeyCode.R))
            {
                transform.position = new Vector3(-1.27f, 0.6f, -1.62f);
                transform.rotation = new Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
            }

            // Test Door Condition
            if(isClose)
            {
                if (Input.GetKey(KeyCode.Space))
                {
                    // display safe message
                    if(safe)
                    {
                        safeCondition.gameObject.SetActive(true);
                    }
                    // display unsafe message
                    else
                    {
                        dangerCondition.gameObject.SetActive(true);
                    }
                }
            }
            
            // close with esc
            if(Input.GetKey(KeyCode.Escape))
            {
                Application.Quit();
            }
        }
    }

    // test trigger enter
    private void OnTriggerEnter(Collider other)
    {
        // prompt user to press space
        doorOpen.gameObject.SetActive(true);
        isClose = true;

        // test to see which door user is in front of
        for(int x = 0; x < 20; x++)
        {
            string doorNumber = (x + 1).ToString();
            if (other.transform.name == "Door " + doorNumber)
            {
                // test if door is within safe types
                if (gameManager.doorType[x] == 1 || gameManager.doorType[x] == 3 || gameManager.doorType[x] == 5 || gameManager.doorType[x] == 7)
                {
                    safe = true;
                }
            }
        }
    }

    // reset all states on trigger exit
    private void OnTriggerExit(Collider other)
    {
        isClose = false;
        safe = false;
        doorOpen.gameObject.SetActive(false);
        safeCondition.gameObject.SetActive(false);
        dangerCondition.gameObject.SetActive(false);
    }
}
