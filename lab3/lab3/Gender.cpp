#include "Gender.h"

Gender::Gender() = default;

Gender::Gender(const string& gender_)
{
	setGender(gender_);
}

Gender::~Gender() = default;

void Gender::setGender(const string& gender_)
{
	gender = gender_;
}

string Gender::getGender() const
{
	return gender;
}

void Gender::operator=(const Gender& other)
{
	setGender(other.getGender());
}

bool Gender::operator==(const Gender& other) const
{
	return (gender == other.getGender());
}
