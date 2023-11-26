#pragma once
#include "Person.h"

class Worker :
    public Person
{
private:
    double salary;
public:
    Worker();
    Worker(const IdCard& idCard, const int& lifeStatus_, const double& salary_);
    Worker(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
        const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const int& lifeStatus_, const double& salary_);
    ~Worker();
    void setSalary(const int&);
    int getSalary() const;
    void goToVacation();
    void getBackFromVacation();
    void operator=(const Worker& other);
    bool operator==(const Worker& other) const;
};

