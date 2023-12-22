#pragma once
#include "Message.h"
#include "Person.h"
class Chat
{
protected:
	string chatName;
	vector<Message> messages;
	vector<Person*> companions;
public:
	Chat();
	Chat(const string& chatName_, Person* creater);
	~Chat();
	void setChatName(const string&);
	void addMessage(Message&);
	void addCompanion(Person*);
	string getChatName() const;
	vector<Message> getMessages() const;
	vector<Person*> getCompanions() const;
	void operator=(const Chat& other);
	bool operator==(const Chat& other) const;
};

