#include "pch.h"
#include "CppUnitTest.h"
#include "Doctor.h"
#include "Guardian.h"
#include "Patient.h"
#include "Recipe.h"
#include "Ward.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab2UnitTest
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
	TEST_CLASS(NameUnitTest)
	{
	public:
		TEST_METHOD(NameTest)
		{
			Name a;
			Name b("Anton", "Chernov", "Andreevich");
			a = b;
			Assert::IsTrue(a == b);
		}
	};
	TEST_CLASS(SigntureUnitTest) 
	{
	public:
		TEST_METHOD(SignatureTest)
		{
			Signature a;
			Name bb("Anton", "Chernov", "Andreevich");
			Signature b("123", bb);
			Signature c("123", "Anton", "Chernov", "Andreevich");
			a = c;
			Assert::IsTrue((a == b) && (b == c));
		}
	};
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
	TEST_CLASS(RecipeUnitTest)
	{
	public:
		TEST_METHOD(RecipeTest)
		{
			Recipe a;
			Signature bb("123", "Anton", "Chernov", "Andreevich");
			Date bbb(18, 11, 2023);
			Date bbbb(25, 12, 2023);
			Recipe b("PainKiller", bb, bbb, bbbb);
			Recipe c("PainKiller", "Anton", "Chernov", "Andreevich", "123", 18, 11, 2023, 25, 12, 2023);
			a = b;
			Assert::IsTrue((a == b) && (b == c));
		}
	};
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
	TEST_CLASS(WorkerUnitTest)
	{
	public:
		TEST_METHOD(WorkerTest)
		{
			Worker a;
			IdCard bb("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122");
			Worker b(bb, 67, 1000000);
			Worker c("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122", 67, 1000000);
			a = c;
			Assert::IsTrue((a == b) && (b == c));

			a.goToVacation();
			a.getBackFromVacation();
			Assert::AreEqual(a.getSalary(), b.getSalary());
		}
	};
	TEST_CLASS(NurseUnitTest)
	{
	public:
		TEST_METHOD(NurseTest)
		{
			Nurse a;
			IdCard bb("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122");
			Nurse b(bb, 67, 1000000);
			Nurse c("Anton", "Chernov", "Andreevich", "123", "male", 18, "Belarus", "Married", "HB12122", 67, 1000000);
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
			Assert::AreEqual(pat.getLifeStatus(), int (50 * 1.02));

			a.removeSettler(&pat);
			Assert::IsFalse(a.isLiveHere(&pat));
		}
	};
}
