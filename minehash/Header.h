/*
Minehash
Author: Paul Lindberg
Created 6/26/2018
Description: A simple program for extracting Minecraft's files.

*/
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <map>
#include <vector>
#include <errno.h>

#include <Shobjidl.h>
#include <shobjidl_core.h>
using namespace std;

typedef vector< tuple<string, string> > my_tuple;

#include "dialog.h"
#include "processJson.h"
#include "jsonObject.h"
#include "search.h"




#endif // !HEADER_H
