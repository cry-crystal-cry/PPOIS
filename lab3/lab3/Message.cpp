#include "Message.h"

Message::Message() = default;

Message::Message(const string& text_, const Date& date_, const Time& time_, Person* personFrom_)
	:Note(text_,date_,time_)
{
	setPersonFrom(personFrom_);
}

Message::~Message() = default;

void Message::setPersonFrom(Person* personFrom_)
{
	personFrom = personFrom_;
}

void Message::addReaction(const Reaction& reaction_)
{
	reactions.push_back(reaction_);
}

void Message::setMessageReadStatus(const bool& messageReadStatus_)
{
	messageReadStatus = messageReadStatus_;
}

Person* Message::getPersonFrom() const
{
	return personFrom;
}

vector<Reaction> Message::getReactions() const
{
	return reactions;
}

bool Message::getMessageReadStatus() const
{
	return messageReadStatus;
}

void Message::operator=(const Message& other)
{
	Note::operator=(other);
	setPersonFrom(other.getPersonFrom());
	reactions = other.getReactions();
	messageReadStatus = other.getMessageReadStatus();
}

bool Message::operator==(const Message& other) const
{
	return Note::operator==(other) && (personFrom == other.getPersonFrom()) && (reactions == other.getReactions()) && 
		(messageReadStatus == other.getMessageReadStatus());
}
