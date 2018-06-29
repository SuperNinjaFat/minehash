/*
Minehash
Author: Paul Lindberg
Created 6/26/2018
Description: A simple program for extracting Minecraft's files.

*/
#include "Header.h"

my_tuple searchTuple(my_tuple tl) {
	//initialize a tuple to be filled with search results
	my_tuple tupleReturn;
	cout << "Enter the substring of the files you want extracted: ";
	string findThis;
	cin >> findThis;
	cout << endl;
	int amountFound = 0;
	for (my_tuple::const_iterator i = tl.begin(); i != tl.end(); ++i) {
		size_t found = get<0>(*i).find(findThis);
		if (found != string::npos) {
			tupleReturn.push_back(tuple<string, string>(get<0>(*i), get<1>(*i)));
			if (amountFound == 0)
				cout << "\"" << findThis << "\":" << endl;
			amountFound++;
			cout << "  " << get<0>(*i) << "    : \"" << get<1>(*i) << "\"" << endl;
		}
	}
	if (amountFound == 0)
		cout << "Didn't find anything for \"" << findThis << "\"." << endl;
	else
		cout << "Found " << amountFound << " results." << endl;
	return tupleReturn;
}
