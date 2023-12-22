#pragma once
class Date
{
protected:
	int year;
	int mounth;
	int day;
public:
	Date();
	Date(const int& day_, const int& mounth_, const int& year_);
	~Date();
	void setYear(const int&);
	void setMounth(const int&);
	void setDay(const int&);
	int getYear() const;
	int getMounth() const;
	int getDay() const;
	static Date getTerm(Date& from, Date& to);
	void operator=(const Date& other);
	bool operator==(const Date& other) const;
};

