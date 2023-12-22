#pragma once
#include "Date.h"
#include "Gender.h"
#include "Name.h"

class Person
{
protected:
	Name name;
	Gender gender;
	int age;
	string country;
	string familyStatus;
	Person();
	Person(const Name& name_, const  Gender& gender_, const int& age_, const string& country_, const string& familyStatus_);
	~Person();
public:

	void setName(const Name&);
	void setGender(const Gender&);
	void setAge(const int&);
	void setCountry(const string&);
	void setFamilyStatus(const string&);
	Name getName() const;
	Gender getGender() const;
	int getAge() const;
	string getCountry() const;
	string getFamilyStatus () const;
	void operator=(const Person& other);
	bool operator==(const Person& other) const;
};

