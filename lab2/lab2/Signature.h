#pragma once
#include <string>
#include "Name.h"

using namespace std;
class Signature
{
private:
	string uniqueSignature;
	Name* authorName = NULL;
public:
	Signature();
	Signature(const string& uniqueSignature_, const Name&);
	Signature(const string& uniqueSignature_, const string& name_, const string& surname_, const string& lastName_);
	~Signature();
	void setUniqueSignature(const string&);
	void setAuthorName(const Name&);
	string getUniqueSignature() const;
	Name* getAuthorName() const;
	bool operator==(const Signature& other) const;
	void operator=(const Signature& other);
};

