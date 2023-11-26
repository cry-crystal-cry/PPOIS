#include "Recipe.h"

Recipe::Recipe()
{
	signature = new Signature;
	dateFrom = new Date;
	dateTo = new Date;

}

Recipe::Recipe(const string& medicineName_, const Signature& signature_, const Date& dateFrom_, const Date& dateTo_)
{
	setMedicineName(medicineName_);
	signature = new Signature;
	dateFrom = new Date;
	dateTo = new Date;
	setSignature(signature_);
	setDateFrom(dateFrom_);
	setDateTo(dateTo_);
}

Recipe::Recipe(const string& medicineName_, const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_,
	const int& dayFrom_, const int& mounthFrom_, const int& yearFrom_, const int& dayTo_, const int& mounthTo_, const int& yearTo_)
{
	setMedicineName(medicineName_);
	signature = new Signature(uniqueSignature_,name_, surname_, lastName_);
	dateFrom = new Date(dayFrom_, mounthFrom_, yearFrom_);
	dateTo = new Date(dayTo_, mounthTo_, yearTo_);
}

Recipe::~Recipe()
{
	delete signature;
	delete dateFrom;
	delete dateTo;
}

void Recipe::setMedicineName(const string& medicineName_)
{
	medicineName = medicineName_;
}

void Recipe::setSignature(const Signature& signature_)
{
	*signature = signature_;
}

void Recipe::setDateFrom(const Date& dateFrom_)
{
	*dateFrom = dateFrom_;
}

void Recipe::setDateTo(const Date& dateTo_)
{
	*dateTo = dateTo_;
}

string Recipe::getMedcineName() const
{
	return medicineName;
}

Signature* Recipe::getSignature() const
{
	return signature;
}

Date* Recipe::getDateFrom() const
{
	return dateFrom;
}

Date* Recipe::getDateTo() const
{
	return dateTo;
}

bool Recipe::operator==(const Recipe& other) const
{
	return (medicineName == other.getMedcineName()) && (*signature == *(other.getSignature())) &&
		(*dateFrom == *(other.getDateFrom())) && (*dateTo == *(other.getDateTo()));
}

void Recipe::operator=(const Recipe& other)
{
	setMedicineName(other.getMedcineName());
	setSignature(*(other.getSignature()));
	setDateFrom(*(other.getDateFrom()));
	setDateTo(*(other.getDateTo()));
}
