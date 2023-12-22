#pragma once
class Time
{
protected:
	int hour;
	int minute;
	int second;
public:
	Time();
	Time(const int& hour_, const int& minute_, const int& second_);
	~Time();
	void setHour(const int&);
	void setMinute(const int&);
	void setSecond(const int&);
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	static Time getTerm(Time& from, Time& to);
	void operator=(const Time& other);
	bool operator==(const Time& other) const;
};

