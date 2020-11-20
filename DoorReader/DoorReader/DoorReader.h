// Boris Au - 100660279
// INFR4320 Fall 2020
// DoorReader Header File
#pragma once

#include "PluginSettings.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>

class PLUGIN_API DoorReader
{
public:
	void readDoor(char* path);
	void rollDoor();
	int getDoor(int index);
private:
	void swapOrder();
	void assignProbabilities();
	std::vector<int> doorType;
	std::vector<std::string> col1, col2, col3, col4;
	std::vector<std::string> probability;
};
