#include "Worker.h"

Worker::Worker() = default;

Worker::Worker(const IdCard& idCard, const int& lifeStatus_, const double& salary_)
	:Person(idCard,lifeStatus_)
{
	setSalary(salary_);
}

Worker::Worker(const string& name_, const string& surname_, const string& lastName_, const string& uniqueSignature_, const string& gender_,
	const int& age_, const string& country_, const string& familyStatus_, const string& identificalNumber_, const int& lifeStatus_, const double& salary_)
	:Person(name_, surname_, lastName_, uniqueSignature_, gender_, age_, country_, familyStatus_, identificalNumber_, lifeStatus_)
{
	setSalary(salary_);
}

Worker::~Worker() = default;

void Worker::setSalary(const int& salary_)
{
	salary = salary_;
}

int Worker::getSalary() const
{
	return salary;
}

void Worker::goToVacation()
{
	setSalary(getSalary() * 0.1);
}

void Worker::getBackFromVacation()
{
	setSalary(getSalary() * 10);
}

void Worker::operator=(const Worker& other)
{
	Person::operator=(other);
	setSalary(other.getSalary());
}

bool Worker::operator==(const Worker& other) const
{
	return (Person::operator==(other)) && (salary == other.getSalary());
}
