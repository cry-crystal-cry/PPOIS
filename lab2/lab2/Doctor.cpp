#include "Doctor.h"

Doctor::Doctor() = default;

Doctor::Doctor(const IdCard& idCard, const int& lifeStatus_, const double& salary_)
	:Nurse(idCard, lifeStatus_, salary_)
		{}

Doctor::Doctor(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
	const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const double& salary_, const int& lifeStatus_)
		:Nurse(name_, surname_, lastName_, uniqueSignature_, gender_, age_, country_, familyStatus_, identificalNumber_, salary_, lifeStatus_)
			{};

Doctor::~Doctor() = default;

void Doctor::backToLife(Patient* patient_) const
{
	patient_->setLifeStatus(true);
}

void Doctor::carryOutOperation(Patient* patient_, Nurse* nurse_) const
{
	if (!patient_->getLifeStatus())
		backToLife(patient_);
	else
		patient_->setLifeStatus((int)(patient_->getLifeStatus() * 1.3));
}

void Doctor::givePrescription(Patient* patient_, const string& medicineName_, const Date& dateFrom_, const Date& dateTo_) const
{
	Recipe* buf = new Recipe(medicineName_, *(getIdCard()->getSignature()), dateFrom_, dateTo_);
	patient_->getMedicalCard()->addNoteToMedicalHistory("write recipe for " + medicineName_);
	patient_->addRecipe(buf);
}
