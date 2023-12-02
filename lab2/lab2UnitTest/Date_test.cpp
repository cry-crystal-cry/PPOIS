#include "pch.h"
#include "CppUnitTest.h"
#include "Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DateUnitTest
{
	TEST_CLASS(DateUnitTest)
	{
	public:

		TEST_METHOD(DateTest)
		{
			Date a;
			Date b(18, 11, 2023);
			a = b;
			Date term = Date::getTerm(a, b);
			Assert::AreEqual((term.getDay() + term.getMounth() + term.getYear()), 0);
		}
	};
}