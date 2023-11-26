#include "Guardian.h"

Guardian::Guardian() = default;

Guardian::Guardian(const IdCard& idCard, const int& lifeStatus_, const double& salary_, const int& bullets_)
	:Worker(idCard,lifeStatus_,salary_)
{
	setBullets(bullets_);
}

Guardian::Guardian(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
	const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const double& salary_, const int& lifeStatus_, const int& bullets_)
	:Worker(name_, surname_, lastName_, uniqueSignature_, gender_, age_, country_, familyStatus_, identificalNumber_, salary_, lifeStatus_)
{
	setBullets(bullets_);
}

Guardian::~Guardian() = default;

void Guardian::setBullets(const int& bullets_)
{
	bullets = bullets_;
}

bool Guardian::checkMagazineAmmo() const
{
	return bullets;
}

void Guardian::shoot(Person* person_)
{
	person_->setLifeStatus(false);
	bullets--;
}

void Guardian::kill(Person* person_) 
{
	if (checkMagazineAmmo())
		shoot(person_);
}

Name* Guardian::chekIdFromPerson(Person* person_) const
{
	return person_->getIdCard()->getName();
}

void Guardian::searchingForGangster(Person* personForChek_, const Name& gangsterName_) 
{
	if (*(chekIdFromPerson(personForChek_)) == gangsterName_)
		kill(personForChek_);
}
