#pragma once
#include <string>
using namespace std;
 class Gender
{
private:
	 string gender;
public:
	Gender();
	Gender(const string&);
	~Gender();
	void setGender(const string&);
	string getGender() const;
	void operator=(const Gender&);
	bool operator==(const Gender&) const;
};

