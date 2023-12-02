#include "pch.h"
#include "CppUnitTest.h"
#include "Worker.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WorkerUnitTest
{
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
}