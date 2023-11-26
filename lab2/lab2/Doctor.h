#pragma once
#include "Nurse.h"
#include "Recipe.h"

class Doctor :
    public Nurse
{
public:
    Doctor();
    Doctor(const IdCard& idCard, const int& lifeStatus_, const double& salary_);
    Doctor(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
        const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const double& salary_, const int& lifeStatus_);
    ~Doctor();
    void backToLife(Patient*) const;
    void carryOutOperation(Patient*, Nurse*) const;
    void givePrescription(Patient* patient_, const string& medicineName_, const Date& dateFrom_, const Date& dateTo_) const;
};

