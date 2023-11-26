#include "Signature.h"

Signature::Signature()
{
	authorName = new Name;
}
Signature::Signature(const string& uniqueSignature_, const Name& authorName_)
{
	setUniqueSignature(uniqueSignature_);
	authorName = new Name;
	setAuthorName(authorName_);
}
Signature::Signature(const string& uniqueSignature_, const string& name_, const string& surname_, const string& lastName_)
{
	setUniqueSignature(uniqueSignature_);
	authorName = new Name(name_, surname_, lastName_);
}
Signature::~Signature()
{
	delete authorName;
}

void Signature::setUniqueSignature(const string& uniqueSignature_)
{
	uniqueSignature = uniqueSignature_;
}

void Signature::setAuthorName(const Name& authorName_)
{
	*authorName = authorName_;
}

string Signature::getUniqueSignature() const
{
	return uniqueSignature;
}

Name* Signature::getAuthorName() const
{
	return authorName;
}

bool Signature::operator==(const Signature& other) const
{
	return (((*authorName) == *(other.getAuthorName())) && (uniqueSignature == other.getUniqueSignature()));
}

void Signature::operator=(const Signature& other)
{
	setAuthorName(*(other.getAuthorName()));
	setUniqueSignature(other.getUniqueSignature());
}

