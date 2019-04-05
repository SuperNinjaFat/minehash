#include "pch.h"

//#include "stdafx.h"
#include "CppUnitTest.h"

#include "../minehash/Header.h"
#include "../minehash/dialog.cpp"
#include "windows.h"

TEST(TestCaseName, Test1) {
	//Arrange
	//Act
	string testPath = "C:\\Users\\super\\Downloads";//"C:\\Users\\paul.lindberg\\Downloads";
	//Assert
	EXPECT_EQ(testPath, promptLoc());
	EXPECT_TRUE(true);
}

TEST(TestCaseName, Test2) {
	//Arrange
	string stringResulting;
	string stringFirst;
	string stringSecond;
	int spaces;
	//Act
	stringFirst = "First String";
	stringSecond = "Second String";
	spaces = 30;
	stringResulting = spacing(stringFirst, stringSecond, spaces);


	EXPECT_EQ(string("First String     Second String"), stringResulting);
	EXPECT_TRUE(true);
}
