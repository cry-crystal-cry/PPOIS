#include "Chat.h"

Chat::Chat() = default;

Chat::Chat(const string& chatName_, Person* creater)
{
	setChatName(chatName_);
	companions.push_back(creater);
}

Chat::~Chat() = default;

void Chat::setChatName(const string& chatName_)
{
	chatName = chatName_;
}

void Chat::addMessage(Message& message_)
{
	messages.push_back(message_);
}

void Chat::addCompanion(Person* companion_)
{
	companions.push_back(companion_);
}

string Chat::getChatName() const
{
	return chatName;
}

vector<Message> Chat::getMessages() const
{
	return messages;
}

vector<Person*> Chat::getCompanions() const
{
	return companions;
}

void Chat::operator=(const Chat& other)
{
	chatName = other.getChatName();
	messages = other.getMessages();
	companions = other.getCompanions();
}

bool Chat::operator==(const Chat& other) const
{
	return (chatName == other.getChatName()) && (messages == other.getMessages()) && (companions == other.getCompanions());
}
