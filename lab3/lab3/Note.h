#pragma once
#include <string>
#include "Date.h"
#include "TimeClass.h"
using namespace std;

class Note
{
protected:
	string text;
	Date date;
	Time time;
	Note();
	Note(const string& text_, const Date& date_, const Time& time_);
	~Note();
public:
	void setText(const string&);
	void setDate(const Date&);
	void setTime(const Time&);
	string getText() const;
	Date getDate() const;
	Time getTime() const;
	void operator=(const Note& other);
	bool operator==(const Note& other) const;
};

