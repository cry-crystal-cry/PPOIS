#include "pch.h"
#include "CppUnitTest.h"
#include "Chat.h"
#include "User.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(ChatUnitTest)
	{
	public:
		TEST_METHOD(TestGetChatName)
		{
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Chat chat("chatName", &p);
			Assert::AreEqual((string)"chatName", chat.getChatName());
		}
		TEST_METHOD(TestGetMessages)
		{
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Chat chat("chatName", &p);
			Date d(12, 11, 2003);
			Time t(23, 12, 55);
			Message mes("text", d, t, &p);
			chat.addMessage(mes);
			Assert::IsTrue(chat.getMessages().size());
		}
		TEST_METHOD(TestGetCompanions)
		{
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Chat chat("chatName", &p);
			chat.addCompanion(&p);
			Assert::IsTrue(chat.getCompanions().size());
		}

		TEST_METHOD(TestOperators)
		{
			Name n("John", "Doe", "Smith");
			Gender g("Male");
			User p(n, g, 30, "USA", "Married");
			Chat chat("chatName", &p);
			Chat chat2("ch", &p);
			chat2 = chat;
			Assert::IsTrue(chat2 == chat);
		}

	};
}
