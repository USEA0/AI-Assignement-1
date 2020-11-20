// Boris Au - 100660279
// INFR4320 Fall 2020
// dll plugin settings
#pragma once

#ifdef DOORREADER_EXPORTS
#define PLUGIN_API __declspec(dllexport)
#elif DOORREADER_IMPORTS
#define PLIGIN_API __declspec(dllimport)
#else
#define PLUGIN_API
#endif