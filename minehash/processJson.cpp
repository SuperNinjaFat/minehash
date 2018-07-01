/*
Minehash
Author: Paul Lindberg
Created 6/26/2018
Description: A simple program for extracting Minecraft's files.

*/
#include "Header.h"

my_tuple processJson(string jsonLoc) {
	my_tuple tl;
	if (empty(jsonLoc))
		return tl;
	//string jsonLocClean;
	//for (int i = 0; i < jsonLoc.size(); i++) {
	//	if (jsonLoc[i] && (jsonLoc[i] != '\\'))
	//		jsonLocClean += jsonLoc[i];
	//	else
	//		jsonLocClean += '\\';
	//}
	//mapMaker(jsonLocClean);
	tl = tupleMaker(jsonLoc);
	return tl;
}

my_tuple tupleMaker(string mapName)
{
	// initialize vector of tuples for storing file locations and hashes
	my_tuple tl;


	/*for (my_tuple::const_iterator i = tl.begin(); i != tl.end(); ++i) {
		cout << get<0>(*i) << endl;
		cout << get<1>(*i) << endl;
		cout << endl;
	}*/


	ifstream inputfile;
	inputfile.open(mapName);
	if (inputfile.fail()) {
		inputfile.close();
		cerr << "error:" << endl;
		cerr << strerror(errno) << endl;
		cin.get();
	}
	else {
		string tempMapString;
		string bufferLoc;
		string bufferHash;
		int TAB_DEFAULT = 4;
		while (!(inputfile.eof())) {
			std::getline(inputfile, tempMapString);
			if (tempMapString == "{") {
				while (!(inputfile.eof())) {
					std::getline(inputfile, tempMapString);
					if (tempMapString == "  \"objects\": {") {
						while (!(inputfile.eof())) {
							//get the bufferLoc
							std::getline(inputfile, tempMapString);
							if (tempMapString[TAB_DEFAULT] == '\"') {
								for (int i = 1; i < tempMapString.size(); i++) {
									if (tempMapString[TAB_DEFAULT + i] == '/')
										bufferLoc += "\\";
									else if (tempMapString[TAB_DEFAULT + i] != '\"')
										bufferLoc += tempMapString[TAB_DEFAULT + i];
									else
										i = tempMapString.size();
								}
								//now that the bufferLoc is acquired, get the bufferHash
								std::getline(inputfile, tempMapString);
								if (tempMapString[14] == '\"') {
									for (int i = 1; i < tempMapString.size(); i++) {
											if (tempMapString[14 + i] != '\"')
											bufferHash += tempMapString[14 + i];
										else
											i = tempMapString.size();
									}
									//now the bufferHash is aquired, put both into the tuple.
									tl.push_back(tuple<string, string>(bufferLoc, bufferHash));
									bufferLoc = "";
									bufferHash = "";
									std::getline(inputfile, tempMapString); //skip size
								}
							}
							else if (tempMapString[TAB_DEFAULT+1] != ',') {
								break;
							}
						}
					}
					else
						break;
				}
			}
			else
				break;
		}
	}
	return tl;
}
