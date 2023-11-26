#include "IdCard.h"

IdCard::IdCard()
{
	signature = new Signature;
	gender = new Gender;
}

IdCard::IdCard(const Signature& signature_, const Gender& gender_, const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_)
{
	signature = new Signature;
	gender = new Gender;
	setSignature(signature_);
	setGender(gender_);
	setAge(age_);
	setCountry(country_);
	setFamilyStatus(familyStatus_);
	setIdentificalNumber(identificalNumber_);
}

IdCard::IdCard(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
	const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_)
{
	signature = new Signature(uniqueSignature_, name_, surname_, lastName_);
	gender = new Gender(gender_);
	setAge(age_);
	setCountry(country_);
	setFamilyStatus(familyStatus_);
	setIdentificalNumber(identificalNumber_);
}

IdCard::~IdCard()
{
	delete signature;
	delete gender;
}

void IdCard::setName(const Name& name_)
{
	signature->setAuthorName(name_);
}

void IdCard::setSignature(const Signature& signature_)
{
	*signature = signature_;
}

void IdCard::setGender(const Gender& gender_)
{
	*gender = gender_;
}

void IdCard::setAge(const int& age_)
{
	age = age_ % 130;
}

void IdCard::setCountry(const string& country_)
{
	country = country_;
}

void IdCard::setFamilyStatus(const string& familyStatus_)
{
	familyStatus = familyStatus_;
}

void IdCard::setIdentificalNumber(const string& identificalNumber_)
{
	identificalNumber = identificalNumber_;
}

Name* IdCard::getName() const
{
	return signature->getAuthorName();
}

Signature* IdCard::getSignature() const
{
	return signature;
}

Gender* IdCard::getGender() const
{
	return gender;
}

int IdCard::getAge() const
{
	return age;
}

string IdCard::getCountry() const
{
	return country;
}

string IdCard::getFamilyStatus() const
{
	return familyStatus;
}

string IdCard::getIdentificalNumber() const
{
	return identificalNumber;
}
void IdCard::operator=(const IdCard& other)
{
	setSignature(*(other.getSignature()));
	setName(*(other.getName()));
	setGender(*(other.getGender()));
	setAge(other.getAge());
	setCountry(other.getCountry());
	setFamilyStatus(other.getFamilyStatus());
	setIdentificalNumber(other.getIdentificalNumber());
}
bool IdCard::operator==(const IdCard& other) const
{
	return ((*signature) == *(other.getSignature())) && 
		((*gender) == *(other.getGender())) && (age == other.getAge()) && (country == other.getCountry()) 
		&& (familyStatus == other.getFamilyStatus()) && (identificalNumber == other.getIdentificalNumber());
}
