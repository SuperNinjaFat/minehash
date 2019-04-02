/*
Minehash
Author: Paul Lindberg
Created 6/26/2018
Description: A simple program for extracting Minecraft's files.

*/
#include "Header.h"

my_tuple searchTuple(my_tuple tl, string objectsPath) {
	//initialize a tuple to be filled with search results
	my_tuple tupleReturn;
	while (true)
	{
		cout << "Enter the substring of the files you want extracted: ";
		string findThis;// = "music";
		cin >> findThis;
		cout << endl;

		//adapted from http://www.cplusplus.com/forum/general/12245/
		//convert path string to a TCHAR:
		TCHAR *objectsPathTchar = new TCHAR[objectsPath.size() + 1];
		objectsPathTchar[objectsPath.size()] = 0;
		//can't use memcpy() because sizeof(TCHAR)==sizeof(char) may not be true:
		std::copy(objectsPath.begin(), objectsPath.end(), objectsPathTchar);

		int amountFound = 0;
		string hashPath;
		for (my_tuple::const_iterator i = tl.begin(); i != tl.end(); ++i) {
			size_t found = get<0>(*i).find(findThis);
			if (found != string::npos) {
				//The hash directory is made up of the object path "C:\Users\super\AppData\Roaming\.minecraft"
				//followed by "\assets\objects\", the first two char of the hash, "\", and the hash.
				hashPath = objectsPath + "\\assets\\objects\\" + get<1>(*i).substr(0, 2) + "\\" + get<1>(*i);
				tupleReturn.push_back(tuple<string, string>(get<0>(*i), hashPath));
				if (amountFound == 0)
					cout << "\"" << findThis << "\":" << endl;
				amountFound++;
				//cout << "  " << get<0>(*i) << "    : \"" << hashPath << "\"" << endl;
				spacing(("  " + get<0>(*i)), (": \"" + hashPath + "\""), 60);
			}
		}
		if (amountFound == 0)
			cout << "Didn't find anything for \"" << findThis << "\"." << endl;
		else {
			cout << "Found " << amountFound << " results." << endl;
			break;
		}
	}
	return tupleReturn;
}
/*
//adapted from https://www.codeproject.com/Articles/2604/Browse-Folder-dialog-search-folder-and-all-sub-fol
//function that takes in a directory to search in, a string hash, and returns the filename of the hash.
string searchHash(TCHAR * path, string hash) {
	string hashFileName;
	hashFileName = SearchFolder(path, hash.c_str());
	if (hashFileName == "")
		cout << "Error - hash locations failed!" << endl;
	return hashFileName;
}

//SEARCH FOLDER - Searches folder and all sub-folders, 
//reading every file it comes across.
TCHAR * SearchFolder(TCHAR * path, LPCSTR hash)
{
	//Declare all needed handles     
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	TCHAR filename[MAX_PATH + 256];
	TCHAR pathbak[MAX_PATH];

	//Make a backup of the directory the user chose         
	strcpy(pathbak, path);
	
	//Find the first file in the directory the user chose     
	hFind = FindFirstFile(hash, &FindFileData);

	//Use a do/while so we process whatever FindFirstFile returned     
	do
	{
		//Is it valid?         
		if (hFind != INVALID_HANDLE_VALUE)
		{
			//Is it a . or .. directory? If it is, skip, or we'll go forever.             
			if (!(strcmp(FindFileData.cFileName, ".")) ||
				!(strcmp(FindFileData.cFileName, "..")))
			{
				continue;
			}
			//Restore the original directory chosen by the user             
			strcpy(path, pathbak);

			//Append the file found on to the path of the 
			//directory the user chose             
			sprintf(path, "%s\\%s", path, FindFileData.cFileName);

			//If SetCurrentDirectory Succeeds ( returns 1 ) the 
			//current file is a directory. Pause this function,             
			//and have it call itself. This will begin the whole 
			//process over in a sub directory.             
			if ((SetCurrentDirectory(path)))
			{
				SearchFolder(path, hash);
			}

			//Otherwise right here is where you need to 
			//insert what you want to do.             
			//As an example let's add the filename to a list box.             
			//INSERT WHAT YOU WANT DONE BELOW!             
			return path;
		}
	} while (FindNextFile(hFind, &FindFileData)
		&& hFind != INVALID_HANDLE_VALUE);
	FindClose(hFind);
	return "";
}
*/