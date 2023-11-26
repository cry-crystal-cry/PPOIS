#pragma once
#include "Gender.h"
#include "Name.h"
#include "Signature.h"

class IdCard
{
protected:
	Signature* signature = NULL;
	Gender* gender = NULL;
	int age;
	string country;
	string familyStatus;
	string identificalNumber;

public:
	IdCard();
	IdCard(const Signature& signature_, const Gender& gender_,
		const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_);
	IdCard(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
		const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_);
	~IdCard();
	void setName(const Name&);
	void setSignature(const Signature&);
	void setGender(const Gender&);
	void setAge(const int&);
	void setCountry(const string&);
	void setFamilyStatus(const string&);
	void setIdentificalNumber(const string&);
	Name* getName() const;
	Signature* getSignature() const;
	Gender* getGender() const;
	int getAge() const;
	string getCountry() const;
	string getFamilyStatus() const;
	string getIdentificalNumber() const;
	void operator=(const IdCard& other);
	bool operator==(const IdCard& other) const;
};

