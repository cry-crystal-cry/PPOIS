#pragma once
#include "IdCard.h"
class Person
{
protected:
	IdCard* idCard;
	int lifeStatus;

public:
	Person();
	Person(const IdCard&, const int& lifeStatus_);
	Person(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
		const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const int& lifeStatus_);
	~Person();
	void setIdCard(const IdCard&);
	IdCard* getIdCard() const;
	void setLifeStatus(const int&);
	int getLifeStatus() const;
	void operator=(const Person& other);
	bool operator==(const Person& other) const;
};

