#include "pch.h"
#include "CppUnitTest.h"
#include "Comment.h"
#include "User.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(CommentUnitTest)
	{
	public:

		TEST_METHOD(TestGetPersonFrom)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Comment com("text", d, t, &p);
			com.setPersonFrom(NULL);
			Assert::IsFalse(com.getPersonFrom());
		}

		TEST_METHOD(TestGetReaction)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Reaction r("like", &p, d, t);
			Comment com("text", d, t, NULL);
			com.addReaction(r);
			Assert::IsTrue(com.getReactions().size());
		}

		TEST_METHOD(TestOperators)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Reaction r("like", &p, d, t);
			Comment com("text", d, t, NULL);
			Comment com2("text", d, t, &p);
			com = com2;
			Assert::IsTrue(com == com2);
		}
	};
}
