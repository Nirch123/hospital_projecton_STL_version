#include "surgeon.h"

Surgeon::Surgeon(const string& name, const int id, const Date& birthdate, const string& expertise,
	eGender gender, Department* department, int NumOfSurgeries)
	: Doctor(name, id, birthdate, expertise, gender, department)
{
	setSurgeonNumOfSurgeries(NumOfSurgeries);
}

Surgeon::Surgeon(const Surgeon& other) : Doctor(other)
{
	NumOfSurgeries = other.NumOfSurgeries;
}

Surgeon::~Surgeon()
{
}

void Surgeon::setSurgeonNumOfSurgeries(const int new_numofsurgeries)
{
	NumOfSurgeries = new_numofsurgeries;
}

const int Surgeon::getSurgeonNumOfSurgeries() const
{
	return NumOfSurgeries;
}

void Surgeon::WorkerTypeOs(ostream& os) const
{
	os << "\n\tTitle: Surgeon\n\tExpertise: " << getDoctorExpertise()
		<< "\n\tNumber of Surgeries: " << NumOfSurgeries;
}