#include "nurse.h"

Nurse::Nurse(const string& name, int id, const Date& birthdate, eGender gender, Department* department, int yearsOfExperience)
	: Worker(name, id, birthdate, gender, department), yearsOfExperience(yearsOfExperience)
{
}

Nurse::Nurse(const Nurse& other) : Worker(other.name,other.id,other.birthdate,other.gender,other.department)
{
	this->yearsOfExperience = other.yearsOfExperience;
}

int Nurse::getYearsOfExperience() const
{
	return yearsOfExperience;
}

void Nurse::WorkerTypeOs(ostream& os) const
{
	os << "\n\tTitle: Nurse";
	os << "\n\tYears of Experience: " << yearsOfExperience;
}