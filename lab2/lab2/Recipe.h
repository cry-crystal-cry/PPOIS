#pragma once
#include "Signature.h"
#include "Date.h"
class Recipe
{
private:
	string medicineName;
	Signature* signature;
	Date* dateFrom;
	Date* dateTo;
public:
	Recipe();
	Recipe(const string& medicineName_, const Signature& signature_, const Date& dateFrom_, const Date& dateTo);
	Recipe(const string& medicineName_, const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, 
		const int& dayFrom_, const int& mounthFrom_, const int& yearFrom_, const int& dayTo_, const int& mounthTo_, const int& yearTo_);
	~Recipe();
	void setMedicineName(const string&);
	void setSignature(const Signature&);
	void setDateFrom(const Date&);
	void setDateTo(const Date&);
	string getMedcineName() const;
	Signature* getSignature() const;
	Date* getDateFrom() const;
	Date* getDateTo() const;
	bool operator==(const Recipe& other) const;
	void operator=(const Recipe& other);
};

