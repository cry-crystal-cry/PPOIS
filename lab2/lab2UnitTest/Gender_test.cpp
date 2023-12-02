#include "pch.h"
#include "CppUnitTest.h"
#include "Gender.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GenderUnitTest
{
	TEST_CLASS(GenderUnitTest)
	{
	public:

		TEST_METHOD(GenderTest)
		{
			Gender a;
			Gender b("male");
			a = b;
			Assert::IsTrue(a == b);

		}
	};
}