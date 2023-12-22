#include "pch.h"
#include "CppUnitTest.h"
#include "Reaction.h"
#include "User.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(ReactionUnitTest)
	{
	public:

		TEST_METHOD(TestGetReaction)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Reaction r("like", &p, d, t);
			Reaction r2("00000", &p, d, t);
			r2.setReaction("like");
			Assert::IsTrue(r == r2);
		}

		TEST_METHOD(TestGetPersonFrom)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Reaction r("like", &p, d, t);
			r.setPersonFrom(NULL);
			Assert::IsFalse(r.getPersonFrom());
		}

		TEST_METHOD(TestGetPersonDate)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Reaction r("like", &p, Date(), t);
			Reaction r2("like", &p, d, t);
			r.setDate(d);
			Assert::IsTrue(r == r2);
		}

		TEST_METHOD(TestGetPersonTime)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Reaction r("like", &p, d, Time());
			Reaction r2("like", &p, d, t);
			r.setTime(t);
			Assert::IsTrue(r == r2);
		}

		TEST_METHOD(TestGetOperators)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Reaction r("like", &p, d, Time());
			Reaction r2("like", &p, d, t);
			r = r2;
			Assert::IsTrue(r == r2);
		}
	};
}
