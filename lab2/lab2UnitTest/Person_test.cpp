#include "pch.h"
#include "CppUnitTest.h"
#include "Person.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PersonUnitTest
{
	TEST_CLASS(PersonUnitTest)
	{
	public:
		TEST_METHOD(PersonTest)
		{
			Person a;
			IdCard bb("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122");
			Person b(bb, 67);
			Person c("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122", 67);
			a = c;
			Assert::IsTrue((a == b) && (b == c));
		}
	};
}