#include "MedicalCard.h"

MedicalCard::MedicalCard() = default;

MedicalCard::MedicalCard(const Signature& signature_, const Gender& gender_, const int& age_, const string& country_,
	const string& familyStatus_, const string& identificalNumber_, const string& address_, const int& bloodType_, const bool& bloodRhFactor_)
	:IdCard(signature_, gender_, age_, country_, familyStatus_, identificalNumber_)
{
	setAddress(address_);
	setBloodType(bloodType_);
	setBloodRhFactor(bloodRhFactor_);
}

MedicalCard::MedicalCard(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_,
	const string& gender_, const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, 
	const string& address_, const int& bloodType_, const bool& bloodRhFactor_ )
	:IdCard(name_, surname_, lastName_, uniqueSignature_, gender_, age_, country_, familyStatus_, identificalNumber_)
{
	setAddress(address_);
	setBloodType(bloodType_);
	setBloodRhFactor(bloodRhFactor_);
}

MedicalCard::~MedicalCard() = default;

void MedicalCard::setAddress(const string& address_)
{
	address = address_;
}

void MedicalCard::addNoteToMedicalHistory(const string& note)
{
	medicalHistory.push_back(note);
}

void MedicalCard::removeNoteFromMedicalHistory(const string& note)
{
	for (int i = 0; i < medicalHistory.size(); i++)
		if (medicalHistory[i] == note)
			medicalHistory.erase(medicalHistory.begin() + i);
}

void MedicalCard::setBloodType(const int& bloodType_)
{
	bloodType = bloodType_;
}

void MedicalCard::setBloodRhFactor(const bool& rh)
{
	bloodRhFactor = rh;
}

string MedicalCard::getAddress() const
{
	return address;
}

vector<string> MedicalCard::getMedicalHistory() const
{
	return medicalHistory;
}

int MedicalCard::getBloodType() const
{
	return bloodType;
}

bool MedicalCard::getBloodRhFactor() const
{
	return bloodRhFactor;
}

void MedicalCard::operator=(const MedicalCard& other)
{
	IdCard::operator=(other);
	setAddress(other.getAddress());
	setBloodType(other.getBloodType());
	setBloodRhFactor(other.getBloodRhFactor());
}

bool MedicalCard::operator==(const MedicalCard& other) const
{
	return (IdCard::operator==(other)) && (address == other.getAddress()) && (bloodType == other.getBloodType()) 
		&& (bloodRhFactor == other.getBloodRhFactor());
}
