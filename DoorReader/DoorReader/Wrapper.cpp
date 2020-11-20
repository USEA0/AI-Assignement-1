// Boris Au - 100660279
// INFR4320 Fall 2020
// dll wrapper c++ file
#include "Wrapper.h"

DoorReader doorReader;

PLUGIN_API void readDoor(char* path)
{
	return doorReader.readDoor(path);
}

PLUGIN_API void rollDoor()
{
	return doorReader.rollDoor();
}

PLUGIN_API int getDoor(int index)
{
	return doorReader.getDoor(index);
}