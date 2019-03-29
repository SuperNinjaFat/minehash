/*
Minehash
Author: Paul Lindberg
Created 6/26/2018
Description: A simple program for extracting Minecraft's files.

*/
#include "Header.h"

string spacing(string loc, string result, int spaces)
{
	string spacesString = "";
	//string(loc + result) = 
	printf("%-60s%-30s\n", loc, result);
	return loc + spacesString + result;
}
