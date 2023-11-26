#pragma once
#include <vector>
#include "Patient.h"
#include "Gender.h"

class Ward
{
private:
	Gender* genderType;
	int wardSize;
	vector<Patient*> settlers;
public:
	Ward();
	Ward(const Gender& genderType_, const int& wardSize_);
	Ward(const string& genderType_, const int& wardSize_);
	~Ward();
	void setGenderType(const Gender& gender_);
	void setWardSize(const int& size_);
	Gender* getGenderType() const;
	int getWardSize() const;
	int ownNumberInWard(Person* person_) const;
	bool isLiveHere(Person* person_) const;
	void addSettler(Patient*);
	void removeSettler(Patient*);
	void makeWardParty();
	void operator=(const Ward& other);
	bool operator==(const Ward& other) const;
};
