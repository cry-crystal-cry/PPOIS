#pragma once
#include <string>
using namespace std;
class Name
{
protected:
	string name;
	string surname;
	string lastName;
public:
	Name();
	Name(const string& name_, const string& surname_, const string& lastName_);
	~Name();
	void setName(const string&);
	void setSurname(const string&);
	void setLastName(const string&);
	string getSurname() const;
	string getName() const;
	string getLastName() const;
	void operator=(const Name& other);
	bool operator==(const Name& other) const;
};

