#include "pch.h"
#include "CppUnitTest.h"
#include "Gender.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(GenderUnitTest)
	{
	public:

        TEST_METHOD(TestGetGender)
        {
            Gender gender("male");
            Assert::AreEqual(gender.getGender(), std::string("male"));
        }

        TEST_METHOD(TestSetGender)
        {
            Gender gender;
            gender.setGender("male");
            Assert::AreEqual(gender.getGender(), std::string("male"));
        }

        TEST_METHOD(TestOperatorEqual)
        {
            Gender gender1("male");
            Gender gender2("male");
            Assert::IsTrue(gender1 == gender2);
        }

        TEST_METHOD(TestOperatorAssign)
        {
            Gender gender1("male");
            Gender gender2;
            gender2 = gender1;
            Assert::AreEqual(gender1.getGender(), gender2.getGender());
        }

	};
}
