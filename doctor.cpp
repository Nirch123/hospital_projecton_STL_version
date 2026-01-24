#pragma warning (disable: 4996)
#include "doctor.h"
#include "department.h"
#include "worker.h"

Doctor::Doctor(const string& name, const int id, const Date& birthdate, const string& expertise,
	eGender gender, Department* department)
	: Worker(name, id, birthdate, gender, department), expertise(expertise)
{
	Worker::setWorkerType(Worker::eWorkerType::DOCTOR);
}

Doctor::Doctor(const Doctor& other)
	: Worker(other.name,other.id,other.birthdate,other.gender,other.department), expertise(other.expertise) 
{
	Worker::setWorkerType(Worker::eWorkerType::DOCTOR);
}

Doctor::~Doctor()
{
}

void Doctor::setDoctorExpertise(const string& new_expertise)
{
	expertise = new_expertise; 
}

const string& Doctor::getDoctorExpertise() const
{
	return expertise;
}

ostream& operator<<(ostream& os, const Doctor& doctor)
{
	if (&doctor == nullptr)
		os << "Doctor not assigned";
	else
		os << "Dr." << doctor.getName();
	return os;
}

void Doctor::WorkerTypeOs(ostream& os) const
{
	os << "\n\tTitle: Doctor\n\tExpertise: " << expertise;
}