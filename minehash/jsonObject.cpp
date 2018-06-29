/*
Minehash
Author: Paul Lindberg
Created 6/26/2018
Description: A simple program for extracting Minecraft's files.

*/
#include "Header.h"

JsonObject::JsonObject(HANDLE hf)
{
	if (hf)
		jHandle = hf;
	else
		jHandle = NULL;
}

HANDLE JsonObject::getHandle()
{
	return jHandle;
}

BOOL JsonObject::closeHandle()
{
	return CloseHandle(jHandle);
}

void JsonObject::proccessHandle()
{
	jHandle;
}
