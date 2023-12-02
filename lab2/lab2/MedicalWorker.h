#pragma once
#include <vector>
#include <iostream>
#include "Worker.h"
#include "IdCard.h"
#include "Patient.h"

using namespace std;
class MedicalWorker :
	public Worker
{
protected:
	vector<Patient*> listOfPatients;
public:
	MedicalWorker();
	MedicalWorker(const IdCard& idCard, const int& lifeStatus_, const double& salary_);
	MedicalWorker(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
		const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const int& lifeStatus_, const double& salary_);
	~MedicalWorker();
	void addPatient(Patient*);
	void removePatient(Patient*);
	void writeToMedicalCard(Patient*, const string&) const;
	void killPatient(Patient*) const;
	void giveMassage(Patient*) const;
	void injectMedicine(Patient*) const;

};

