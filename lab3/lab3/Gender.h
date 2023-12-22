#pragma once
#include <string>
using namespace std;

 class Gender
{
protected:
	 string gender;
public:
	Gender();
	Gender(const string& gender_);
	~Gender();
	void setGender(const string&);
	string getGender() const;
	void operator=(const Gender&);
	bool operator==(const Gender&) const;
};

