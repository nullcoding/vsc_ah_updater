// basic includes

// old libraries and shit
// additional library dir (debug) = $(SolutionDir)depend\lib\curl64d\lib
// additional library dir (release) = $(SolutionDir)depend\lib\curl64\lib

#pragma once

#if defined(WIN32) || defined(WIN64) && !defined(UNIX) || !defined(__unix__) || !defined(__unix)
#define JSON_DIR "jsons"
#elif defined(UNIX) || defined(__unix__) || defined(__unix) && !defined(WIN32) || !defined(WIN64)
#define JSON_DIR "/var/www/vsc/jsons"
#endif

#include "id.h"

#include <stdio.h>
#include <tchar.h>
#include <dirent.h>
#include <direct.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "curl.h"
#include "json.h"