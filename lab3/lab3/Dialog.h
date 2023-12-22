#pragma once
#include "Message.h"
#include "Person.h"
class Dialog
{
protected:
	pair<Person*, Person*> companions;	//information about person who send message is already contained in massage, BUT this need if you resend message from other dialog
	vector<Message> messages;		
public:
	Dialog();
	Dialog(Person*, Person*);
	~Dialog();
	void addMessage(const Message&);
	pair<Person*, Person*> getCompanions() const;
	vector<Message> getMessages() const;
	void operator=(const Dialog& other);
	bool operator==(const Dialog& other) const;
};

