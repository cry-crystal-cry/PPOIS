#include "Comment.h"

Comment::Comment() = default;

Comment::Comment(const string& text_, const Date& date_, const Time& time_,Person* personFrom_)
	:Note(text_,date_,time_)
{
	setPersonFrom(personFrom_);
}

Comment::~Comment() = default;

void Comment::setPersonFrom(Person* personFrom_)
{
	personFrom = personFrom_;
}

Person* Comment::getPersonFrom() const
{
	return personFrom;
}

void Comment::addReaction(const Reaction& reaction_)
{
	reactions.push_back(reaction_);
}

vector<Reaction> Comment::getReactions() const
{
	return reactions;
}

void Comment::operator=(const Comment& other)
{
	Note::operator=(other);
	setPersonFrom(other.getPersonFrom());
	reactions = other.getReactions();
}

bool Comment::operator==(const Comment& other) const
{
	return Note::operator==(other) && (personFrom == other.getPersonFrom()) && (reactions == other.getReactions());
}
