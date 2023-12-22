#include "pch.h"
#include "CppUnitTest.h"
#include "Post.h"
#include "User.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(PostUnitTest)
	{
	public:

		TEST_METHOD(TestGetPersonFrom)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Post post("teeet", d, t, &p);
			post.setPersonFrom(NULL);
			Assert::IsFalse(post.getPersonFrom());
		}


		TEST_METHOD(TestGetReactions)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Reaction r("like", &p, d, t);
			Post post("teeet", d, t, &p);
			post.addReaction(r);
			Assert::IsTrue(post.getReactions().size());
		}

		TEST_METHOD(TestGetComments)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Comment com("text", d, t, NULL);
			Post post("teeet", d, t, &p);
			post.addComment(com);
			Assert::IsTrue(post.getComments().size());
		}

		TEST_METHOD(TestOperators)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Comment com("text", d, t, NULL);
			Post post("teeet", d, t, &p);
			Post post2("t1t", d, t, NULL);
			post = post2;
			Assert::IsTrue(post == post2);
		}
	};
}
