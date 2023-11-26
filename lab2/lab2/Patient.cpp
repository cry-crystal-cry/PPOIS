#include "Patient.h"

Patient::Patient()
{
	medicalCard = new MedicalCard;
}

Patient::Patient(const MedicalCard& medicalCard_, const int& lifeStatus_)
{
	setIdCard(medicalCard_);
	medicalCard = new MedicalCard;
	setMedicalCard(medicalCard_);
	setLifeStatus(lifeStatus_);
}

Patient::Patient(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_, 
	const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const string& address_, 
	const int& bloodType_, const bool& bloodRhFactor_, const int& lifeStatus_)
{
	medicalCard = new MedicalCard(name_, surname_, lastName_, uniqueSignature_, gender_, age_, country_, familyStatus_, identificalNumber_,
		address_, bloodType_, bloodRhFactor_);
	setIdCard(*medicalCard);
	setLifeStatus(lifeStatus_);
}

Patient::~Patient()
{
	delete medicalCard;
	for (int i = 0; i < recipes.size(); i++)
		delete recipes[i];
}

void Patient::setMedicalCard(const MedicalCard& medicalCard_)
{
	*medicalCard = medicalCard_;
}

MedicalCard* Patient::getMedicalCard() const
{
	return medicalCard;
}

void Patient::addRecipe(Recipe* recipe_)
{
	recipes.push_back(recipe_);
}

void Patient::removePecipe(const string& medicineName_)
{
	for (int i = 0; i < recipes.size(); i++)
		if (((*(recipes[i])).getMedcineName()) == medicineName_)
			recipes.erase(recipes.begin() + i);
}

Recipe* Patient::getRecipe(const string& medicineName_)
{
	for (int i = 0; i < recipes.size(); i++)
		if ((*(recipes[i])).getMedcineName() == medicineName_)
			return recipes[i];
}

void Patient::operator=(const Patient& other)
{
	Person::operator=(other);
	*medicalCard = *(other.getMedicalCard());
}
bool Patient::operator==(const Patient& other) const
{
	return (Person::operator==(other)) && (*medicalCard == *(other.getMedicalCard()));
}
