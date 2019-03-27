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

//"minecraftPath" is the path the browsing window defaults to.
string promptJson(string minecraftPath) {
	//OPENFILENAME ofn;       // common dialog box structure
	//char szFile[260];       // buffer for file name
	//HWND hwnd = NULL;              // owner window
	//HANDLE hf;              // file handle

	//						// Initialize OPENFILENAME
	//ZeroMemory(&ofn, sizeof(ofn));
	//ofn.lStructSize = sizeof(ofn);
	//ofn.hwndOwner = hwnd;
	//ofn.lpstrFile = szFile;
	////
	//// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	//// use the contents of szFile to initialize itself.
	////
	//ofn.lpstrFile[0] = '\0';
	//ofn.nMaxFile = sizeof(szFile);
	//ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	//ofn.nFilterIndex = 1;
	//ofn.lpstrFileTitle = NULL;
	//ofn.nMaxFileTitle = 0;
	//ofn.lpstrInitialDir = NULL;
	//ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	TCHAR path[MAX_PATH];
	BROWSEINFO bi = { 0 };
	bi.lpszTitle = { "All Folders Automatically Recursed." };



	//if (GetOpenFileName(&ofn)) {
	//	//do stuff witht the information in open
	//	cout << "json file for indexing: " << ofn.lpstrFile << endl;
	//	hf = CreateFile(ofn.lpstrFile, GENERIC_READ,
	//		0, (LPSECURITY_ATTRIBUTES)NULL,
	//		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
	//		(HANDLE)NULL);
	//}
	//else {
	//	//user pressed cancel
	//	DWORD commError = CommDlgExtendedError();
	//	if (commError) {
	//		cout << "CommDlgExtendedError: " << commError << endl;
	//	}
	//	else {
	//		cout << "Canceled." << endl;
	//		return "";
	//	}
	//}
	string fileString;// = ofn.lpstrFile; //szFile;
	return fileString;
}
string promptLoc() {
	//adapted from https://www.codeproject.com/Articles/2604/Browse-Folder-dialog-search-folder-and-all-sub-fol
	TCHAR path[MAX_PATH];
	BROWSEINFO bi = { 0 };
	bi.ulFlags = BIF_USENEWUI;
	bi.lpszTitle = ("All Folders Automatically Recursed.");
	LPITEMIDLIST pid1 = SHBrowseForFolder(&bi);

	if (pid1 != 0)
	{
		if (SHGetPathFromIDList(pid1, path)) {
			//do stuff witht the information in open
			cout << "Directory to copy to: " << path << endl;
			SetCurrentDirectory(path);

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
