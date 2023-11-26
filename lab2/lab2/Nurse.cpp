#include "Nurse.h"

Nurse::Nurse() = default;

Nurse::Nurse(const IdCard& idCard, const int& lifeStatus_, const double& salary_)
	:Worker(idCard, lifeStatus_, salary_)
	{}

Nurse::Nurse(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
	const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const int& lifeStatus_, const double& salary_)
	:Worker(name_, surname_, lastName_, uniqueSignature_, gender_, age_, country_, familyStatus_, identificalNumber_, lifeStatus_, salary_)
	{}

Nurse::~Nurse() = default;

void Nurse::killPatient(Patient* patient_) const
{
	patient_->setLifeStatus(false);
}

void Nurse::giveMassage(Patient* patient_) const
{
	patient_->setLifeStatus((int)(patient_->getLifeStatus() * 1.07));
}

void Nurse::injectMedicine(Patient* patient_) const
{
	patient_->setLifeStatus((int)(patient_->getLifeStatus() * 1.15));
}



void Nurse::addPatient(Patient* patient_)
{
	listOfPatients.push_back(patient_);
}

void Nurse::removePatient(Patient* patient_)
{
	for (int i = 0; i < listOfPatients.size(); i++)
		if (listOfPatients[i] == patient_)
			listOfPatients.erase(listOfPatients.begin() + i);
}

void Nurse::writeToMedicalCard(Patient* patient_, const string& note_) const
{
	patient_->getMedicalCard()->addNoteToMedicalHistory(note_);
}
