#include "stdafx.h"
#include "CppUnitTest.h"

#include "../minehash/Header.h"
#include "../minehash/dialog.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		TEST_METHOD(TestMethod1)
		{
			//Arrange
			//Act
			string testPath = "C:\\Users\\super\\Downloads";//"C:\\Users\\paul.lindberg\\Downloads";
			//Assert
			Assert::AreEqual(testPath, promptLoc());
		}
		
		TEST_METHOD(TestMethod2)
		{
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

			Assert::AreEqual(string("First String     Second String"), stringResulting);
		}
	};
}