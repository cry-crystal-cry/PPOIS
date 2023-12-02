#include "pch.h"
#include "CppUnitTest.h"
#include "Ward.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WardUnitTest
{
	TEST_CLASS(WardUnitTest)
	{
	public:
		TEST_METHOD(WardTest)
		{
			Ward a;
			Gender bb("robot");
			Ward b(bb, 3);
			Ward c("robot", 3);
			a = b;
			Assert::IsTrue((a == b) && (b == c));

			Patient pat("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122", "X street", 2, true, 50);
			a.addSettler(&pat);
			Assert::IsFalse(a.isLiveHere(&pat));

			pat.getIdCard()->setGender(Gender("robot"));
			a.addSettler(&pat);
			Assert::IsTrue(a.isLiveHere(&pat));

			a.makeWardParty();
			Assert::AreEqual(pat.getLifeStatus(), int(50 * 1.02));

			a.removeSettler(&pat);
			Assert::IsFalse(a.isLiveHere(&pat));
		}
	};
}