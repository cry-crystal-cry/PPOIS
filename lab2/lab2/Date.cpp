#include "Date.h"

Date::Date() = default;

Date::Date(const int& day_, const int& mounth_, const int& year_)
{
	setDay(day_);
	setMounth(mounth_);
	setYear(year_);
}

Date::~Date() = default;

void Date::setYear(const int& year_)
{
	year = year_;
}

void Date::setMounth(const int& mounth_)
{
	mounth = mounth_ % 13;
}

void Date::setDay(const int& day_)
{
	day = day_ % 31;
}

int Date::getYear() const
{
	return year;
}

int Date::getMounth() const
{
	return mounth;
}

int Date::getDay() const
{
	return day;
}

Date Date::getTerm(Date& from, Date& to)	//not realized 31/30 days mounth; every mounth have 30 days :(
{
	Date term;
	term.setYear(to.getYear() - from.getYear());
	term.setMounth(to.getMounth() - from.getMounth());
	term.setDay(to.getDay() - from.getDay());
	if (term.getYear() > 0 && (term.getMounth() < 0 || term.getDay() < 0)) {
		term.setYear(term.getYear() - 1);
		term.setMounth(term.getMounth() + 12);
	}
	if (term.getMounth() > 0 && term.getDay() < 0) {
		term.setMounth(term.getMounth() - 1);
		term.setDay(term.getDay() + 30);
	}
	return term;
}

bool Date::operator==(const Date& other) const
{
	return (day == other.getDay()) && (mounth == other.getMounth()) && (year == other.getYear());
}

void Date::operator=(const Date& other)
{
	setDay(other.getDay());
	setMounth(other.getMounth());
	setYear(other.getYear());
}


