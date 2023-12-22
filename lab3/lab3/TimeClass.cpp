#include "TimeClass.h"

Time::Time() = default;

Time::Time(const int& hour_, const int& minute_, const int& second_)
{
	setHour(hour_);
	setMinute(minute_);
	setSecond(second_);
}

Time::~Time() = default;

void Time::setSecond(const int& second_)
{
	second = second_ % 60;
}

void Time::setMinute(const int& minute_)
{
	minute = minute_ % 60;
}

void Time::setHour(const int& hour_)
{
	hour = hour_ % 24;
}

int Time::getSecond() const
{
	return second;
}

int Time::getMinute() const
{
	return minute;
}

int Time::getHour() const
{
	return hour;
}

Time Time::getTerm(Time& from, Time& to)	//not realized 31/30 hours minute; every minute have 30 hours :(
{
	Time term;
	term.setSecond(to.getSecond() - from.getSecond());
	term.setMinute(to.getMinute() - from.getMinute());
	term.setHour(to.getHour() - from.getHour());
	if (term.getHour() > 0 && (term.getMinute() < 0 || (term.getMinute() == 0 && term.getSecond() < 0))) {
		term.setHour(term.getHour() - 1);
		term.setMinute(term.getMinute() + 60);
	}
	if (term.getMinute() > 0 && term.getSecond() < 0) {
		term.setMinute(term.getMinute() - 1);
		term.setSecond(term.getSecond() + 60);
	}
	return term;
}

void Time::operator=(const Time& other)
{
	setHour(other.getHour());
	setMinute(other.getMinute());
	setSecond(other.getSecond());
}

bool Time::operator==(const Time& other) const
{
	return (hour == other.getHour()) && (minute == other.getMinute()) && (second == other.getSecond());
}



