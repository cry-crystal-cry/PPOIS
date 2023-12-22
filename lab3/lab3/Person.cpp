#include "Person.h"


Person::Person() = default;

Person::Person(const Name& name_, const Gender& gender_, const int& age_, const string& country_, const string& familyStatus_)
{
	setName(name_);
	setGender(gender_);
	setAge(age_);
	setCountry(country_);
	setFamilyStatus(familyStatus_);
}

Person::~Person() = default;

void Person::setName(const Name& name_)
{
	name = name_;
}

void Person::setGender(const Gender& gender_)
{
	gender = gender_;
}

void Person::setAge(const int& age_)
{
	age = age_;
}

void Person::setCountry(const string& country_)
{
	country = country_;
}

void Person::setFamilyStatus(const string& familyStatus_)
{
	familyStatus = familyStatus_;
}

Name Person::getName() const
{
	return name;
}

Gender Person::getGender() const
{
	return gender;
}

int Person::getAge() const
{
	return age;
}

string Person::getCountry() const
{
	return country;
}

string Person::getFamilyStatus() const
{
	return familyStatus;
}

void Person::operator=(const Person& other)
{
	setName(other.getName());
	setGender(other.getGender());
	setAge(other.getAge());
	setCountry(other.getCountry());
	setFamilyStatus(other.getFamilyStatus());
}

bool Person::operator==(const Person& other) const
{
	return (name == other.getName()) && (gender == other.getGender()) && (age == other.getAge()) &&
		(country == other.getCountry()) && (familyStatus == other.getFamilyStatus());
}
