#include "pch.h"
#include "CppUnitTest.h"
#include "Recipe.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RecipeUnitTest
{
	TEST_CLASS(RecipeUnitTest)
	{
	public:
		TEST_METHOD(RecipeTest)
		{
			Recipe a;
			Signature bb("123", "Anton", "Chernov", "Andreevich");
			Date bbb(18, 11, 2023);
			Date bbbb(25, 12, 2023);
			Recipe b("PainKiller", bb, bbb, bbbb);
			Recipe c("PainKiller", "Anton", "Chernov", "Andreevich", "123", 18, 11, 2023, 25, 12, 2023);
			a = b;
			Assert::IsTrue((a == b) && (b == c));
		}
	};
}