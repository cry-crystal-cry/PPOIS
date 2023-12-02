#include "pch.h"
#include "CppUnitTest.h"
#include "Doctor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoctorUnitTest
{
	TEST_CLASS(DoctorUnitTest)
	{
	public:
		TEST_METHOD(DoctorTest)
		{
			Doctor a;
			IdCard bb("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122");
			Doctor b(bb, 67, 1000000);
			Doctor c("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122", 67, 1000000);
			a = c;
			Assert::IsTrue((a == b) && (b == c));

			Patient pat("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122", "X street", 2, true, 50);
			a.carryOutOperation(&pat, &b);
			Assert::AreEqual(pat.getLifeStatus(), (int)(50 * 1.3) % 100);

			a.killPatient(&pat);
			a.backToLife(&pat);
			Assert::AreEqual(pat.getLifeStatus(), 1);

			Signature* sign = new Signature;
			*sign = *(a.getIdCard()->getSignature());
			Date df(18, 11, 2023);
			Date dt(25, 12, 2023);
			Recipe x("PainKiller", *sign, df, dt);
			a.givePrescription(&pat, "PainKiller", df, dt);
			Assert::IsTrue(x == *(pat.getRecipe(x.getMedcineName())));
		}
	};
}