#include "pch.h"
#include "CppUnitTest.h"
#include "Message.h"
#include "User.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(MessageUnitTest)
	{
	public:

		TEST_METHOD(TestGetPersomFrom)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Message m("tttt", d, t, &p);
			m.setPersonFrom(NULL);
			Assert::IsFalse(m.getPersonFrom());
		}

		TEST_METHOD(TestGetReactions)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Message m("tttt", d, t, &p);
			Reaction r("like", &p, d, t);
			m.addReaction(r);
			Assert::IsTrue(m.getReactions().size());
		}

		TEST_METHOD(TestGetMessageReadStatus)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Message m("tttt", d, t, &p);
			m.setMessageReadStatus(1);
			Assert::IsTrue(m.getMessageReadStatus());
		}

		TEST_METHOD(TestOperators)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Message m("tttt", d, t, &p);
			Message m2("tttt", d, t, NULL);
			m = m2;
			Assert::IsTrue(m == m2);
		}
	};
}
