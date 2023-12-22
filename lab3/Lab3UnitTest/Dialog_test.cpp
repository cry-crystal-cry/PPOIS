#include "pch.h"
#include "CppUnitTest.h"
#include "Dialog.h"
#include "User.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(DialogUnitTest)
	{
	public:

		TEST_METHOD(TestGetMessages)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			User p2(n, g, 3000, "USA", "Married");
			Dialog dialog(&p, &p2);
			Message m("tttt", d, t, &p);
			dialog.addMessage(m);
			Assert::IsTrue(dialog.getMessages().size());
		}

		TEST_METHOD(TestOperators)
		{
			Date d(1, 1, 12);
			Time t(1, 1, 13);
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			User p2(n, g, 3000, "USA", "Married");
			Dialog dialog(&p, &p2);
			Dialog dialog2(&p, NULL);
			dialog2 = dialog;
			Assert::IsTrue(dialog == dialog2);
		}
	};
}
