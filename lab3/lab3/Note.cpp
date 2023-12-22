#include "Note.h"

Note::Note() = default;

Note::Note(const string& text_, const Date& date_, const Time& time_)
{
	setText(text_);
	setDate(date_);
	setTime(time_);
}

Note::~Note() = default;

void Note::setText(const string& text_)
{
	text = text_;
}

void Note::setDate(const Date& date_)
{
	date = date_;
}

void Note::setTime(const Time& time_)
{
	time = time_;
}

string Note::getText() const
{
	return text;
}

Date Note::getDate() const
{
	return date;
}

Time Note::getTime() const
{
	return time;
}

void Note::operator=(const Note& other)
{
	setText(other.getText());
	setDate(other.getDate());
	setTime(other.getTime());
}

bool Note::operator==(const Note& other) const
{
	return (text == other.getText()) && (date == other.getDate()) && (time == other.getTime());
}
