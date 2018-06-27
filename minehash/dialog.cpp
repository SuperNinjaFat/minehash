/*
Minehash
Author: Paul Lindberg
Created 6/26/2018
Description: A simple program for extracting Minecraft's files.

*/
#include "Header.h"

DWORD promptJson() {

	OPENFILENAME ofn;       // common dialog box structure
	char szFile[260];       // buffer for file name
	HWND hwnd = NULL;              // owner window
	HANDLE hf;              // file handle

							// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFile = szFile;
	//
	// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
	// use the contents of szFile to initialize itself.
	//
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	DWORD commResult;

	if (GetOpenFileName(&ofn)) {
		//do stuff witht the information in open
		cout << "File opened!" << ofn.lpstrFile << endl;
		commResult = NULL;
	}
	else {
		//user pressed cancel
		cout << "Canceled!" << endl;
		commResult = CommDlgExtendedError();
	}
	return commResult;
	
	//cout << "GetOpenFileNameA(Arg1): " << GetOpenFileNameA(Arg1) << endl;

	//cout << "Arg1: " << Arg1 << endl;
}

//
//BOOL GetOpenFileNameA(
//	LPOPENFILENAMEA Arg1
//);