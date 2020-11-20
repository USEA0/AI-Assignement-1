// Boris Au - 100660279
// INFR4320 Fall 2020
// dll wrapper header file
#pragma once
#include "PluginSettings.h"
#include "DoorReader.h"

#ifdef __cplusplus
extern "C"
{
#endif

	PLUGIN_API void readDoor(char* path);
	PLUGIN_API void rollDoor();

	PLUGIN_API int getDoor(int index);

#ifdef __cplusplus
}
#endif