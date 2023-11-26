#include "pch.h"
#include "CppUnitTest.h"
#include "CubeSide.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CubeSideUnitTest
{
	TEST_CLASS(CubeSideUnitTest)
	{
	public:
		TEST_METHOD(TestMethodSetSide)
		{
			CubeSide side;
			vector<char> vec{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
			side.setSide(vec);
			Assert::IsTrue(true);
		}
		TEST_METHOD(TestMethodRotateSide)
		{
			CubeSide side1,side2;
			vector<char> vec1{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
			vector<char> vec2{'7', '4', '1', '8', '5', '2', '9', '6', '3'};
			side1.setSide(vec1);
			side2.setSide(vec2);
			side1.rotateSide();
			Assert::IsTrue(side1 == side2);
		}
		TEST_METHOD(TestMethodBackRotateSide)
		{
			CubeSide side1, side2;
			vector<char> vec1{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
			vector<char> vec2{'3', '6', '9', '2', '5', '8', '1', '4', '7'};
			side1.setSide(vec1);
			side2.setSide(vec2);
			side1.backRotateSide();
			Assert::IsTrue(side1 == side2);
		}
	};
}
