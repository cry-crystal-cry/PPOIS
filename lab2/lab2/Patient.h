#pragma once
#include "Person.h"
#include "IdCard.h"
#include "MedicalCard.h"
#include "Recipe.h"

class Patient :
	public Person
{
protected:
	MedicalCard* medicalCard;
	vector<Recipe*> recipes;
public:
	Patient();
	Patient(const MedicalCard& medicalCard_, const int& lifeStatus_);
	Patient(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
		const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const string& address_,
		const int& bloodType_, const bool& bloodRhFactor_, const int& lifeStatus_);
	~Patient();
	void setMedicalCard(const MedicalCard&);
	MedicalCard* getMedicalCard() const;
	void addRecipe(Recipe*);
	void removePecipe(const string& medicineName_);
	Recipe* getRecipe(const string& medicineName_);
	void operator=(const Patient& other);
	bool operator==(const Patient& other) const;
};

