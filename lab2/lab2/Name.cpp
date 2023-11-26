#include "Name.h"

Name::Name() = default;
Name::Name(const string& name_, const string& surname_, const string& lastName_)
{
	setName(name_);
	setSurname(surname_);
	setLastName(lastName_);
}
Name::~Name() = default;

void Name::setName(const string& name_)
{
	name = name_;
}

void Name::setSurname(const string& surname_)
{
	surname = surname_;
}

void Name::setLastName(const string& lastName_)
{
	lastName = lastName_;
}

string Name::getName() const
{
	return name;
}

string Name::getSurname() const
{
	return surname;
}

string Name::getLastName() const
{
	return lastName;
}

bool Name::operator==(const Name& other) const
{
	return ((name == other.getName()) && (surname == other.getSurname()) && (lastName == other.getLastName()));
}

void Name::operator=(const Name& other)
{
	setName(other.getName());
	setSurname(other.getSurname());
	setLastName(other.getLastName());
}
	
