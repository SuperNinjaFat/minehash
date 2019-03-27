/*
Minehash
Author: Paul Lindberg
Created 6/26/2018
Description: A simple program for extracting Minecraft's files.

*/
#include "Header.h"

//selects the path that .minecraft resides in.
string promptPath() {
	string minecraftPath;
	return minecraftPath;
}


string promptLoc() {
	//adapted from https://www.codeproject.com/Articles/2604/Browse-Folder-dialog-search-folder-and-all-sub-fol
	TCHAR path[MAX_PATH];
	BROWSEINFO bi = { 0 };
	bi.ulFlags = BIF_USENEWUI;
	//bi.lpszTitle = ("All Folders Automatically Recursed.");
	LPITEMIDLIST pid1 = SHBrowseForFolder(&bi);

	if (pid1 != 0)
	{
		if (SHGetPathFromIDList(pid1, path)) {
			//do stuff witht the information in open
			cout << "Directory to copy to: " << path << endl;
			SetCurrentDirectory(path);
			cin.get();
		}
		else {
			//user pressed cancel
			DWORD commError = CommDlgExtendedError();
			if (commError) {
				cout << "CommDlgExtendedError: " << commError << endl;
			}
			else {
				cout << "Canceled." << endl;
				return "";
			}
		}
	}
	return path;
}