#include "pch.h"
#include "CppUnitTest.h"
#include "MedicalWorker.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MedicalWorkerUnitTest
{
	TEST_CLASS(MedicalWorkerUnitTest)
	{
	public:
		TEST_METHOD(NurseTest)
		{
			MedicalWorker a;
			IdCard bb("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122");
			MedicalWorker b(bb, 67, 1000000);
			MedicalWorker c("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122", 67, 1000000);
			a = c;
			Assert::IsTrue((a == b) && (b == c));

			Patient pat("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122", "X street", 2, true, 50);
			a.addPatient(&pat);
			c.giveMassage(&pat);
			Assert::AreEqual(pat.getLifeStatus(), (int)(50 * 1.07) % 100);

			pat.setLifeStatus(50);
			c.injectMedicine(&pat);
			Assert::AreEqual(pat.getLifeStatus(), (int)(50 * 1.15) % 100);

			a.writeToMedicalCard(&pat, "make procedures");
			c.killPatient(&pat);
			Assert::AreEqual(pat.getLifeStatus(), 0);

			a.removePatient(&pat);
		}
	};
}