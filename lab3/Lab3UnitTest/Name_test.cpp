#include "pch.h"
#include "CppUnitTest.h"
#include "Name.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(NameUnitTest)
	{
	public:
        TEST_METHOD(TestGetSurname)
        {
            Name name("John", "Doe", "Smith");
            Assert::AreEqual(name.getSurname(), std::string("Doe"));
        }

        TEST_METHOD(TestGetName)
        {
            Name name("John", "Doe", "Smith");
            Assert::AreEqual(name.getName(), std::string("John"));
        }

        TEST_METHOD(TestGetLastName)
        {
            Name name("John", "Doe", "Smith");
            Assert::AreEqual(name.getLastName(), std::string("Smith"));
        }

		TEST_METHOD(TestSetName)
		{
			Name name;
			name.setName("John");
			Assert::AreEqual(name.getName(), std::string("John"));
		}

		TEST_METHOD(TestSetSurname)
		{
			Name name;
			name.setSurname("Doe");
			Assert::AreEqual(name.getSurname(), std::string("Doe"));
		}

		TEST_METHOD(TestSetLastName)
		{
			Name name;
			name.setLastName("Smith");
			Assert::AreEqual(name.getLastName(), std::string("Smith"));
		}

		TEST_METHOD(TestOperatorEqual)
		{
			Name name1("John", "Doe", "Smith");
			Name name2("John", "Doe", "Smith");
			Assert::IsTrue(name1 == name2);
		}

		TEST_METHOD(TestOperatorAssign)
		{
			Name name1("John", "Doe", "Smith");
			Name name2;
			name2 = name1;
			Assert::IsTrue(name1 == name2);
		}
	};
}
