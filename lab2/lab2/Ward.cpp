#include "Ward.h"
#include <iostream>

Ward::Ward()
{
	genderType = new Gender;
	wardSize = 0;
}
Ward::Ward(const Gender& genderType_, const int& wardSize_)
{
	genderType = new Gender;
	setGenderType(genderType_);
	setWardSize(wardSize_);
}
Ward::Ward(const string& genderType_, const int& wardSize_)
{
	genderType = new Gender(genderType_);
	setWardSize(wardSize_);
}
Ward::~Ward()
{
	delete genderType;
}

void Ward::setGenderType(const Gender& gender_)
{
	*genderType = gender_;
}

void Ward::setWardSize(const int& size_)
{
	wardSize = size_;
}

Gender* Ward::getGenderType() const
{
	return genderType;
}

int Ward::getWardSize() const
{
	return wardSize;
}

int Ward::ownNumberInWard(Person* person_) const
{
	for (int i = 0; i < settlers.size(); i++)
		if (settlers[i] == person_)
			return i;
	return -1;
}

bool Ward::isLiveHere(Person* person_) const
{
	if (ownNumberInWard(person_) == -1)
		return false;
	return true;
}

void Ward::addSettler(Patient* patient_)
{
	if (*(patient_->getIdCard()->getGender()) == *genderType)
		if (settlers.size() < wardSize)
			if(!isLiveHere(patient_))
				settlers.push_back(patient_);
}

void Ward::removeSettler(Patient* patient_)
{
	int buf = ownNumberInWard(patient_);
	if (buf != -1)
		settlers.erase(settlers.begin() + buf);
}

void Ward::makeWardParty()
{
	for (int i = 0; i < settlers.size(); i++)
		settlers[i]->setLifeStatus(settlers[i]->getLifeStatus() * 1.02);
}

void Ward::operator=(const Ward& other)
{
	setGenderType(*(other.getGenderType()));
	setWardSize(other.getWardSize());
}

bool Ward::operator==(const Ward& other) const
{
	return (*genderType == *(other.getGenderType())) && (wardSize == other.getWardSize());
}
