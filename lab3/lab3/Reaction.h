#pragma once
#include <string>
#include "Person.h"
#include "Date.h"
#include "TimeClass.h"
using namespace std;

class Reaction
{
protected:
	string reaction;
	Person* personFrom;
	Date date;
	Time time;
public:
	Reaction();
	Reaction(const string& reaction_,Person* personFrom_, const Date& date_, const Time& time_);
	~Reaction();
	void setReaction(const string&);
	void setPersonFrom(Person*);
	void setDate(const Date&);
	void setTime(const Time&);
	string getReaction() const;
	Person* getPersonFrom() const;
	Date getDate() const;
	Time getTime() const;
	void operator=(const Reaction&);
	bool operator==(const Reaction&) const;
};

