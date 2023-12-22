#include "pch.h"
#include "CppUnitTest.h"
#include "Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(DialogUnitTest)
	{
	public:
		TEST_METHOD(TestGetYear)
		{
			Date date(1, 1, 2023);
			Assert::AreEqual(date.getYear(), 2023);
		}

		TEST_METHOD(TestGetMounth)
		{
			Date date(1, 12, 2023);
			Assert::AreEqual(date.getMounth(), 12);
		}

		TEST_METHOD(TestGetDay)
		{
			Date date(31, 1, 2023);
			Assert::AreEqual(date.getDay(), 31);
		}

		TEST_METHOD(TestSetYear)
		{
			Date date;
			date.setYear(2023);
			Assert::AreEqual(date.getYear(), 2023);
		}

		TEST_METHOD(TestSetMounth)
		{
			Date date;
			date.setMounth(12);
			Assert::AreEqual(date.getMounth(), 12);
		}

		TEST_METHOD(TestSetDay)
		{
			Date date;
			date.setDay(31);
			Assert::AreEqual(date.getDay(), 31);
		}

		TEST_METHOD(TestGetTerm)
		{
			Date from(1, 1, 2023);
			Date to(31, 12, 2023);
			Date term = Date::getTerm(from, to);
			Assert::AreEqual(term.getYear(), 0);
			Assert::AreEqual(term.getMounth(), 11);
			Assert::AreEqual(term.getDay(), 30);
		}

		TEST_METHOD(TestOperatorAssignment)
		{
			Date date1(1, 1, 2023);
			Date date2(2, 2, 2024);
			date1 = date2;
			Assert::AreEqual(date1.getYear(), 2024);
			Assert::AreEqual(date1.getMounth(), 2);
			Assert::AreEqual(date1.getDay(), 2);
		}

		TEST_METHOD(TestOperatorEqual)
		{
			Date date1(1, 1, 2023);
			Date date2(1, 1, 2023);
			Assert::IsTrue(date1 == date2);
		}
	};
}
