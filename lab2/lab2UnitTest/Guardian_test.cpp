#include "pch.h"
#include "CppUnitTest.h"
#include "Guardian.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GuardianUnitTest
{
	TEST_CLASS(GuardianUnitTest)
	{
	public:
		TEST_METHOD(GuardianTest)
		{
			Guardian a;
			IdCard bb("John", "Wick", "Andreevich", "kidOfBelarus", "male", 35, "Belarus", "Widower", "HB12122");
			Guardian b(bb, 67, 1000000, 7);
			Guardian c("John", "Wick", "Andreevich", "kidOfBelarus", "male", 35, "Belarus", "Widower", "HB12122", 67, 1000000, 7);
			a = c;
			Assert::IsTrue((a == b) && (b == c));

			Person x("Vincent", "Bisset", "de Gramont", "gangster", "male", 20, "USA", "Not married", "RG38422", 100);
			Name gangsta("Vincent", "Bisset", "de Gramont");
			a.setBullets(0);
			a.searchingForGangster(&x, gangsta);
			Assert::AreNotEqual(x.getLifeStatus(), 0);

			a.setBullets(7);
			a.searchingForGangster(&x, gangsta);
			Assert::AreEqual(x.getLifeStatus(), 0);
		}
	};
}