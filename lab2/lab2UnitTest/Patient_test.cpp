#include "pch.h"
#include "CppUnitTest.h"
#include "Patient.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PatientUnitTest
{
	TEST_CLASS(PatientUnitTest)
	{
	public:
		TEST_METHOD(PatientTest)
		{
			Patient a;
			MedicalCard bb("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122", "X street", 2, true);
			Patient b(bb, 67);
			Patient c("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122", "X street", 2, true, 67);
			a = c;
			Recipe* buf = new Recipe("PainKiller", "Anton", "Chernov", "Andreevich", "123", 18, 11, 2023, 25, 12, 2023);
			a.addRecipe(buf);
			a.removePecipe("PainKiller");
			Assert::IsTrue((a == b) && (b == c));
		}
	};
}