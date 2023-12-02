#include "pch.h"
#include "CppUnitTest.h"
#include "MedicalCard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MedicalCardUnitTest
{
	TEST_CLASS(MedicalCardUnitTest)
	{
	public:
		TEST_METHOD(MedicalCardTest)
		{
			MedicalCard a;
			Signature bb("123", "Anton", "Chernov", "Andreevich");
			Gender bbb("male");
			MedicalCard b(bb, bbb, 18, "Belarus", "Married", "HB12122", "X street", 2, true);
			MedicalCard c("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122", "X street", 2, true);
			a = c;
			Assert::IsTrue((a == b) && (b == c));
		}
	};
}