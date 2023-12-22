#include "pch.h"
#include "CppUnitTest.h"
#include "TimeClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(TimeUnitTest)
	{
	public:

		TEST_METHOD(TestGetHour)
		{
			Time t(10, 30, 45);
			Assert::AreEqual(10, t.getHour());
		}

		TEST_METHOD(TestGetMinute)
		{
			Time t(10, 30, 45);
			Assert::AreEqual(30, t.getMinute());
		}

		TEST_METHOD(TestGetSecond)
		{
			Time t(10, 30, 45);
			Assert::AreEqual(45, t.getSecond());
		}

		TEST_METHOD(TestSetHour)
		{
			Time t;
			t.setHour(10);
			Assert::AreEqual(10, t.getHour());
		}

		TEST_METHOD(TestSetMinute)
		{
			Time t;
			t.setMinute(30);
			Assert::AreEqual(30, t.getMinute());
		}

		TEST_METHOD(TestSetSecond)
		{
			Time t;
			t.setSecond(45);
			Assert::AreEqual(45, t.getSecond());
		}

		TEST_METHOD(TestGetTerm)
		{
			Time from(10, 30, 45);
			Time to(11, 45, 30);
			Time term = Time::getTerm(from, to);
			Assert::AreEqual(1, term.getHour());
			Assert::AreEqual(14, term.getMinute());
			Assert::AreEqual(45, term.getSecond());
		}

		TEST_METHOD(TestOperatorAssign)
		{
			Time t1(10, 30, 45);
			Time t2;
			t2 = t1;
			Assert::AreEqual(t1.getHour(), t2.getHour());
			Assert::AreEqual(t1.getMinute(), t2.getMinute());
			Assert::AreEqual(t1.getSecond(), t2.getSecond());
		}

		TEST_METHOD(TestOperatorEqual)
		{
			Time t1(10, 30, 45);
			Time t2(10, 30, 45);
			Assert::IsTrue(t1 == t2);
		}

	};
}
