#include "Header.h"
int copyFiles(my_tuple tl, string copyDir)
{
	int status = 0;
	cout << "Copying to \"" << copyDir << "\":" << endl;
	const char * fileToCopy;
	const char * fileCopyTo;
	string fileCopyTostring;
	int errorMsg;
	for (my_tuple::const_iterator i = tl.begin(); i != tl.end(); ++i) {
		int s;//tracks the start of the substring
		int j;//tracks the end of the substring and traversing index
		s = 0;
		j = 0;
		while (true)
		{
			while (true) {
				j++;
				if (get<0>(*i)[j + 1] == '\\')
					break;
				else if (get<0>(*i).size() - 1 == j)
					break;
			}
			if (get<0>(*i).size() - 1 == j) {//its the file
				break;
			}
			else {//it's a folder
				//attempt to make a folder. Regardless of result, continue
				CreateDirectory((copyDir + '\\' + get<0>(*i).substr(0, j + 1)).c_str(), NULL);
				//j += 2;
			}

		}
		fileToCopy = get<1>(*i).c_str();
		fileCopyTostring = (copyDir + '\\' + get<0>(*i));
		fileCopyTo = fileCopyTostring.c_str();
		cout << "   \"" << get<0>(*i) << "\":";
		CopyFile(fileToCopy, fileCopyTo, TRUE);
		errorMsg = GetLastError();
		if (ERROR_FILE_EXISTS == errorMsg) {
			cout << "   Already exists, skipping." << endl;
		}
		else if (0 != errorMsg) {
			cout << "   Error code \"" << errorMsg << "\"." << endl;
			status = 1;
		}
		else {
			cout << "   Done." << endl;
		}
	}
	return status;
}