#include "pch.h"
#include "CppUnitTest.h"
#include "Name.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NameUnitTest
{
	TEST_CLASS(NameUnitTest)
	{
	public:
		TEST_METHOD(NameTest)
		{
			Name a;
			Name b("Anton", "Chernov", "Andreevich");
			a = b;
			Assert::IsTrue(a == b);
		}
	};
}