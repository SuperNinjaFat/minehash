/*
Minehash
Author: Paul Lindberg
Created 6/26/2018
Description: A simple program for extracting Minecraft's files.
Author of this file: Will Clark using edited code from Paul Lindberg
*/
#include "Header.h"

void menu() {
	string minecraftPath;
	string jsonPath;
	//fileSelect();

	minecraftPath = "C:\\Users\\super\\AppData\\Roaming\\.minecraft";//promptPath(); //"C:\\Users\\paul.lindberg\\Desktop\\";
	//prompt the user for the json folder
	cout << "Select the directory of your json files, usually: \"C:\\Users\\<username here>\\AppData\\Roaming\\.minecraft\\assets\\indexes\\\"" << endl;
	jsonPath = promptLoc();
	//comandine input to specific file, if non existant, ask again.
	cout << "Enter the name of the json file: ";
	string jsonName;
	cin >> jsonName;

	jsonPath += "\\" + jsonName;
	//jury-rigged unit tests: Takes two variables, send true if equals to each other, false if not.

	/*
	//First, it prompts for the path of your .minecraft folder.
	minecraftPath = "C:\\Users\\super\\AppData\\Roaming\\.minecraft";
	cout << "Select the directory of your .minecraft folder, usually: \"C:\\Users\\<username here>\\AppData\\Roaming\\.minecraft\\\"" << endl;
	//Then, the user will be prompted for the desired json file found under <.minecraft/assets/indexes>.
	cout << "Select the json file for indexing, usually under: \"assets\\indexes\\\"" << endl;
	jsonPath = "C:\\Users\\super\\AppData\\Roaming\\.minecraft\\assets\\indexes\\1.12.json";//"C:\\Users\\paul.lindberg\\Desktop\\assets\\indexes\\1.12.json";//cin >> fileString;//promptJson(minecraftPath);
	*/

	my_tuple tl = processJson(jsonPath);
	//JsonObject hf = new JsonObject(promptJson());
	//if (!hf.getHandle())
		//return 0;
	//Then it loads the file into arrays
	//hf.proccessHandle();
	//hf.closeHandle();


	//Then it prompts for the phrase to search for. (for instance, <minecraft/sounds/music/> would extract all files indexed under that location, and <minecraft/sounds/music/menu/menu2.ogg> would extract <menu2.ogg>)
	tl = searchTuple(tl, minecraftPath);
	//Then it prompts for the location you want to copy your files to.
	string extractPath = promptLoc();//"C:\\Users\\super\\Downloads";//"C:\\Users\\paul.lindberg\\Downloads";
	int status = copyFiles(tl, extractPath);

	//int stat[];

	if (status == 0)
		cout << "All files successfully extracted to \"" << extractPath << "\"." << endl;
	else if (status == 1)
		cout << "Error - Files failed to extract to \"" << extractPath << "\"." << endl;
	else if (status == 2)
		cout << "Error - Some files successfully extracted to \"" << extractPath << "\"." << endl;

}