#include "pch.h"
#include "CppUnitTest.h"
#include "IdCard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IdCardUnitTest
{
	TEST_CLASS(IdCardUnitTest)
	{
	public:
		TEST_METHOD(IdCardTest)
		{
			IdCard a;
			Signature bb("123", "Anton", "Chernov", "Andreevich");
			Gender bbb("male");
			IdCard b(bb, bbb, 18, "Belarus", "Married", "HB12122");
			IdCard c("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122");
			a = c;
			Assert::IsTrue((a == b) && (b == c));
		}
	};
}