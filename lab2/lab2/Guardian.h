#pragma once
#include "Worker.h"
#include "IdCard.h"

class Guardian :
    public Worker
{
protected:
    int bullets;
    bool checkMagazineAmmo() const;
    void shoot(Person* person_);
    void kill(Person*);
public:
    Guardian();
    Guardian(const IdCard& idCard, const int& lifeStatus_, const double& salary_, const int& bullets_);
    Guardian(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
        const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const double& salary_, const int& lifeStatus_, const int& bullets_);
    ~Guardian();
    void setBullets(const int&);
    Name* chekIdFromPerson(Person*) const;
    void searchingForGangster(Person* personForCheck_, const Name&);
};

