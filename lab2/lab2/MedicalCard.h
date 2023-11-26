#pragma once
#include "IdCard.h"
#include <vector>

using namespace std;

class MedicalCard :
    public IdCard
{
protected:
    string address;
    vector<string> medicalHistory;
    int bloodType;
    bool bloodRhFactor;
public:
    MedicalCard();
    MedicalCard(const Signature& signature_, const Gender& gender_,
        const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const string& address_,
        const int& bloodType_, const bool& bloodRhFactor_);
    MedicalCard(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_, 
        const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const string& address_,
        const int& bloodType_, const bool& bloodRhFactor_);
    ~MedicalCard();
    void setAddress(const string&);
    void addNoteToMedicalHistory(const string&);
    void removeNoteFromMedicalHistory(const string&);
    void setBloodType(const int&);
    void setBloodRhFactor(const bool&);
    string getAddress() const;
    vector<string> getMedicalHistory() const;
    int getBloodType() const;
    bool getBloodRhFactor() const;
    void operator=(const MedicalCard& other);
    bool operator==(const MedicalCard& other) const;
};

