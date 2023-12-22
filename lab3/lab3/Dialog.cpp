#include "Dialog.h"

Dialog::Dialog() = default;

Dialog::Dialog(Person* person1_, Person* person2_)
{
	companions.first = person1_;
	companions.second = person2_;
}

Dialog::~Dialog() = default;

void Dialog::addMessage(const Message& message_)
{
	messages.push_back(message_);
}

pair<Person*, Person*> Dialog::getCompanions() const
{
	return companions;
}

vector<Message> Dialog::getMessages() const
{
	return messages;
}

void Dialog::operator=(const Dialog& other)
{
	companions = other.getCompanions();
	messages = other.getMessages();
}

bool Dialog::operator==(const Dialog& other) const
{
	return (companions == other.getCompanions()) && (messages == other.getMessages());
}
