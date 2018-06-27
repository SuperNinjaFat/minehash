/*
Minehash
Author: Paul Lindberg
Created 6/26/2018
Description: A simple program for extracting Minecraft's files.

*/
#include "Header.h"

int main() {
		
	//First, the user will be prompted for the desired json file found under <.minecraft/assets/indexes>.
	promptJson();
	//Then it prompts for the phrase to search for. (for instance, <minecraft/sounds/music/> would extract all files indexed under that location, and <minecraft/sounds/music/menu/menu2.ogg> would extract <menu2.ogg>)
	
	//Then it prompts for the file extension to give the files.
	
	//Then it prompts for the location you want to copy your files to.
	
	cin.get();

	return 0;
}