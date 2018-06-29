/*
Minehash
Author: Paul Lindberg
Created 6/26/2018
Description: A simple program for extracting Minecraft's files.

*/
#ifndef JSONOBJECT_H
#define JSONOBJECT_H

class JsonObject {
public:
	~JsonObject() {};
	JsonObject(HANDLE hf);
	HANDLE getHandle();
	BOOL WINAPI closeHandle();
	void proccessHandle();
private:
	// map containing objects
	HANDLE jHandle;
};


#endif // !JSONOBJECT_H