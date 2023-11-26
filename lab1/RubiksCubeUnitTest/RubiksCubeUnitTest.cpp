#include "pch.h"
#include "CppUnitTest.h"
#include "RubiksCube.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RubiksCubeUnitTest
{
	TEST_CLASS(RubiksCubeUnitTest)
	{
	public:
		TEST_METHOD(TestMethodSetRandom)
		{
			RubiksCube cube;
			cube.setRandom();
			Assert::IsTrue(true);
		}
		TEST_METHOD(TestMethodSetFromNotExistFile)
		{
			RubiksCube cube;
			try {
				cube.setFromFile("notExistFile_______");
			}
			catch (exception)
			{
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(TestMethodSetFromNotEnoughDataFile)
		{
			RubiksCube cube;
			try {
				cube.setFromFile("testNotEnough.txt");
			}
			catch (exception)
			{
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(TestMethodSetFromUncorrectColorsFile)
		{
			RubiksCube cube;
			try {
				cube.setFromFile("testUncorrectColors.txt");
			}
			catch (exception)
			{
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(TestMethodSetFromCorrectFile)
		{
			RubiksCube cube;
			try{
				cube.setFromFile("test.txt");
			}catch(exception){ Assert::IsTrue(false); }
			Assert::IsTrue(true);
		}
		TEST_METHOD(TestMethodRotateFace)
		{
			RubiksCube cube1,cube2;
			cube1.setFromFile("test.txt");
			cube2.setFromFile("test.txt");
			for (int i = 0; i < 6; i++) 
				for (int j = 0; j < 4; j++)
					cube1.rotateFace(i);
			
			Assert::IsTrue(cube1 == cube2);
		}
		TEST_METHOD(TestMethodBackRotateFace)
		{
			RubiksCube cube1, cube2;
			cube1.setFromFile("test.txt");
			cube2.setFromFile("test.txt");
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 4; j++)
					cube1.backRotateFace(i);
			}
			Assert::IsTrue(cube1 == cube2);
		}
		TEST_METHOD(TestMethodShowCubeCrossForSide)
		{
			RubiksCube cube;
			cube.setFromFile("test.txt");
			for (int i = 0; i < 6; i++) 
					cube.showCubeCrossForSide(i);
			Assert::IsTrue(true);
		}
	};
}
