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
			string testPath = "C:\\Users\\paul.lindberg\\Downloads";
			//Assert
			Assert::AreEqual(testPath, string(promptLoc()));
		}

	};
}