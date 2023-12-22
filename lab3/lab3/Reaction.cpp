#include "Reaction.h"

Reaction::Reaction() = default;

Reaction::Reaction(const string& reaction_, Person* personFrom_, const Date& date_, const Time& time_)
{
	setReaction(reaction_);
	setPersonFrom(personFrom_);
	setDate(date_);
	setTime(time_);
}

Reaction::~Reaction() = default;

void Reaction::setReaction(const string& reaction_)
{
	reaction = reaction_;
}

void Reaction::setPersonFrom(Person* personFrom_)
{
	personFrom = personFrom_;
}

void Reaction::setDate(const Date& date_)
{
	date = date_;
}

void Reaction::setTime(const Time& time_)
{
	time = time_;
}

string Reaction::getReaction() const
{
	return reaction;
}

Person* Reaction::getPersonFrom() const
{
	return personFrom;
}

Date Reaction::getDate() const
{
	return date;
}

Time Reaction::getTime() const
{
	return time;
}

void Reaction::operator=(const Reaction& other)
{
	setReaction(other.getReaction());
	setPersonFrom(other.getPersonFrom());
	setDate(other.getDate());
	setTime(other.getTime());
}

bool Reaction::operator==(const Reaction& other) const
{
	return (reaction == other.getReaction()) && (personFrom == other.getPersonFrom()) && (date == other.getDate()) 
		&& (time == other.getTime());
}