#include "pch.h"
#include "CppUnitTest.h"
#include "Signature.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SigntureUnitTest
{
	TEST_CLASS(SignatureUnitTest)
	{
	public:
		TEST_METHOD(SignatureTest)
		{
			Signature a;
			Name bb("Anton", "Chernov", "Andreevich");
			Signature b("123", bb);
			Signature c("123", "Anton", "Chernov", "Andreevich");
			a = c;
			Assert::IsTrue((a == b) && (b == c));
		}
	};
}