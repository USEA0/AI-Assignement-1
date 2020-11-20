// Boris Au - 100660279
// INFR4320 Fall 2020
// Game manager script (process doors)

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    // dll stuff
    const string DLL_NAME = "DoorReader";
    [DllImport(DLL_NAME)]
    private static extern void readDoor(string path);
    
    [DllImport(DLL_NAME)]
    private static extern void rollDoor();
    
    [DllImport(DLL_NAME)]
    private static extern int getDoor(int index);

    // ui elements
    public Button enterPath;
    public InputField fileLocation;
    public Image startup;
    public Text doorNumber;

    // doors and particle prefabs
    public GameObject[] doors = new GameObject[20];
    public GameObject hot;
    public GameObject noisy;

    // bool to determine if doors are setup
    private bool run = true;
    public int[] doorType = new int[20];
    
    PlayerController playerController;

    void Start()
    {
        playerController = GameObject.FindObjectOfType<PlayerController>();

    }

    // Update is called once per frame
    void Update()
    {
        // file path prompt
        enterPath.onClick.AddListener(ButtonTask);
    }

    void ButtonTask()
    {
        // show game 
        // disable start screen
        startup.gameObject.SetActive(false);
        // enable movement
        playerController.canMove = true;
        // send file path to dll
        readDoor(fileLocation.text);
        
        while(run)
        {
            // setup all 20 door conditions
            rollDoor();
            for (int i = 0; i < 20; i++)
            {
                doorType[i] = getDoor(i);
            }
            initDoors();
            run = false;
        }
    }

    // YYY = 1
    // YYN = 2
    // YNY = 3
    // YNN = 4
    // NYY = 5
    // NYN = 6
    // NNY = 7
    // NNN = 8
    void initDoors()
    {
       // read door conditions and setup particles accordingly 
       // ui door counter variables
       int yyy = 0, yyn = 0, yny = 0, ynn = 0, nyy = 0, nyn = 0, nny = 0, nnn = 0;
       for (int i = 0; i < 20; i++)
       {
            // if door is that particular type initialize the particles for said type
            if (doorType[i] == 1)
            {
                // instantiate particles at door location
                Instantiate(hot, doors[i].transform);
                Instantiate(noisy, doors[i].transform);
                // increment ui counter
                yyy++;
            }
            else if (doorType[i] == 2)
            {
                Instantiate(hot, doors[i].transform);
                Instantiate(noisy, doors[i].transform);
                yyn++;
            }
            else if (doorType[i] == 3)
            {
                Instantiate(hot, doors[i].transform);
                yny++;
            }
            else if (doorType[i] == 4)
            {
                Instantiate(hot, doors[i].transform);
                ynn++;
            }
            else if (doorType[i] == 5)
            {
                Instantiate(noisy, doors[i].transform);
                nyy++;
            }
            else if (doorType[i] == 6)
            {
                Instantiate(noisy, doors[i].transform);
                nyn++;
            }
            else if (doorType[i] == 7)
            {
                nny++;
            }
            else if (doorType[i] == 8)
            {
                nnn++;
            }
        }
       // update ui with door amounts
        doorNumber.text = "\n" + yyy.ToString() + "\n" + yyn.ToString() + "\n" + yny.ToString() + "\n" + ynn.ToString()
            + "\n" + nyy.ToString() + "\n" + nyn.ToString() + "\n" + nny.ToString() + "\n" + nnn.ToString();
    }
}
