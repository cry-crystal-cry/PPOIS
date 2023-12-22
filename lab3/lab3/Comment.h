#pragma once
#include <vector>
#include "Note.h"
#include "Person.h"
#include "Reaction.h"

class Comment :
    public Note
{
protected:
    Person* personFrom;
    vector<Reaction> reactions;
public:
    Comment();
    Comment(const string& text_, const Date& date_, const Time& time_, Person* personFrom_);
    ~Comment();
    void setPersonFrom(Person*);
    Person* getPersonFrom() const;
    void addReaction(const Reaction&);
    vector<Reaction> getReactions() const;
    void operator=(const Comment& other);
    bool operator==(const Comment& other) const;
};

