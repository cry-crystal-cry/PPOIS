#include "Person.h"

Person::Person()
{
	idCard = new IdCard;
}

Person::Person(const IdCard& idCard_, const int& lifeStatus_)
{
	idCard = new IdCard;
	setIdCard(idCard_);
	setLifeStatus(lifeStatus_);
}

Person::Person(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
	const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_,const int& lifeStatus_)
{
	idCard = new IdCard(name_, surname_, lastName_, uniqueSignature_, gender_, age_, country_, familyStatus_, identificalNumber_);
	setLifeStatus(lifeStatus_);
}

Person::~Person()
{
	delete idCard;
}
void Person::setIdCard(const IdCard& idCard_)
{
	*idCard = idCard_;
}

IdCard* Person::getIdCard() const
{
	return idCard;
}
void Person::setLifeStatus(const int& lifeStatus_)
{
	lifeStatus = lifeStatus_ % 101;
}

int Person::getLifeStatus() const
{
	return lifeStatus;
}

void Person::operator=(const Person& other)
{
	setIdCard(*(other.getIdCard()));
	setLifeStatus(other.getLifeStatus());
}

bool Person::operator==(const Person& other) const
{
	return ((*idCard) == *(other.getIdCard())) && (lifeStatus == other.getLifeStatus());
}