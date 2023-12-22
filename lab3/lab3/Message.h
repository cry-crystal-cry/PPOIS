#pragma once
#include "Note.h"
#include "Person.h"
#include "Reaction.h"
#include <vector>
class Message :
    public Note
{
protected:
    Person* personFrom;
    vector<Reaction> reactions;
    bool messageReadStatus;
public:
    Message();
    Message(const string& text_, const Date& date_, const Time& time_, Person* personFrom_);
    ~Message();
    void setPersonFrom(Person*);
    void addReaction(const Reaction&);
    void setMessageReadStatus(const bool&);
    Person* getPersonFrom() const;
    vector<Reaction> getReactions() const;
    bool getMessageReadStatus() const;
    void operator=(const Message& other);
    bool operator==(const Message& other) const;
};


