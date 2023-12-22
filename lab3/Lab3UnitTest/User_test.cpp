#include "pch.h"
#include "CppUnitTest.h"
#include "User.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab3UnitTest
{
	TEST_CLASS(UserUnitTest)
	{
	public:

        TEST_METHOD(TestSetName)
        {
            Name name("John", "Doe", "Smith");
            Gender gender("Male");
            int age = 30;
            string country = "USA";
            string familyStatus = "Married";
            User person(name, gender, age, country, familyStatus);
            Name newName("Jane", "Doe", "Smith");
            person.setName(newName);
            Assert::AreEqual(newName.getName(), person.getName().getName());
        }

        TEST_METHOD(TestSetGender)
        {
            Name name("John", "Doe", "Smith");
            Gender gender("Male");
            int age = 30;
            string country = "USA";
            string familyStatus = "Married";
            User person(name, gender, age, country, familyStatus);
            Gender newGender("Female");
            person.setGender(newGender);
            Assert::AreEqual(newGender.getGender(), person.getGender().getGender());
        }

        TEST_METHOD(TestSetAge)
        {
            Name name("John", "Doe", "Smith");
            Gender gender("Male");
            int age = 30;
            string country = "USA";
            string familyStatus = "Married";
            User person(name, gender, age, country, familyStatus);
            int newAge = 40;
            person.setAge(newAge);
            Assert::AreEqual(newAge, person.getAge());
        }

        TEST_METHOD(TestSetCountry)
        {
            Name name("John", "Doe", "Smith");
            Gender gender("Male");
            int age = 30;
            string country = "USA";
            string familyStatus = "Married";
            User person(name, gender, age, country, familyStatus);
            string newCountry = "Canada";
            person.setCountry(newCountry);
            Assert::AreEqual(newCountry, person.getCountry());
        }

        TEST_METHOD(TestSetFamilyStatus)
        {
            Name name("John", "Doe", "Smith");
            Gender gender("Male");
            int age = 30;
            string country = "USA";
            string familyStatus = "Married";
            User person(name, gender, age, country, familyStatus);
            string newFamilyStatus = "Divorced";
            person.setFamilyStatus(newFamilyStatus);
            Assert::AreEqual(newFamilyStatus, person.getFamilyStatus());
        }

        TEST_METHOD(TestGetFollowingUsers)
        {
            Date d(1, 1, 12);
            Time t(1, 1, 13);
            Name n("John", "Doe", "Smith");
            Gender g("Male");
            User p(n, g, 30, "USA", "Married");
            p.followUser(&p);
            Assert::IsTrue(p.getFollowingUsers().size());
        }

        TEST_METHOD(TestGetPosts)
        {
            Date d(1, 1, 12);
            Time t(1, 1, 13);
            Name n("John", "Doe", "Smith");
            Gender g("Male");
            User p(n, g, 30, "USA", "Married");
            p.createPost("teeet", d, t);
            Assert::IsTrue(p.getPosts().size());
        }

        TEST_METHOD(TestAddDialogs)
        {
            Date d(1, 1, 12);
            Time t(1, 1, 13);
            Name n("John", "Doe", "Smith");
            Gender g("Male");
            User p(n, g, 30, "USA", "Married");
            User p2(n, g, 3000, "USA", "Married");
            Dialog dialog(&p, &p2);
            p.addDialog(dialog);
            Assert::IsTrue(p.getDialogs().size());
        }
        TEST_METHOD(TestCreateDialogs)
        {
            Date d(1, 1, 12);
            Time t(1, 1, 13);
            Name n("John", "Doe", "Smith");
            Gender g("Male");
            User p(n, g, 30, "USA", "Married");
            User p2(n, g, 3000, "USA", "Married");
            Dialog dialog(&p, &p2);
            p.createDialog(&p2);
            Assert::IsTrue(p2.getDialogs().size());
        }

        TEST_METHOD(TestAddChat)
        {
            Date d(1, 1, 12);
            Time t(1, 1, 13);
            Name n("John", "Doe", "Smith");
            Gender g("Male");
            User p(n, g, 30, "USA", "Married");
            User p2(n, g, 3000, "USA", "Married");
            Chat chat("chatName", &p);
            p2.addChat(chat);
            Assert::IsTrue(p2.getChats().size());
        }

        TEST_METHOD(TestAddToChat)
        {
            Date d(1, 1, 12);
            Time t(1, 1, 13);
            Name n("John", "Doe", "Smith");
            Gender g("Male");
            User p(n, g, 30, "USA", "Married");
            User p2(n, g, 3000, "USA", "Married");
            Chat chat("chatName", &p);
            p.addToChat(&chat, &p2);
            Assert::IsTrue(p2.getChats().size());
        }

        TEST_METHOD(TestCreateChat)
        {
            Date d(1, 1, 12);
            Time t(1, 1, 13);
            Name n("John", "Doe", "Smith");
            Gender g("Male");
            User p(n, g, 30, "USA", "Married");
            p.createChat("chatName");
            Assert::IsTrue(p.getChats().size());
        }

        TEST_METHOD(TestOperators)
        {
            Date d(1, 1, 12);
            Time t(1, 1, 13);
            Name n("John", "Doe", "Smith");
            Gender g("Male");
            User p(n, g, 30, "USA", "Married");
            User p2(n, g, 42, "USA", "Divorsed");
            p = p2;
            Assert::IsTrue(p == p2);
        }

	};
}
