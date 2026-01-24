#pragma warning (disable: 4996)

#include "visit.h"
#include "department.h"

Visit::Visit(Patient* patient,const Date& date, Department* department,
	const string& checkName, Doctor* doctor, Nurse* nurse)
	: patient(patient), DateOfArrival(date), department(department)
	  ,doctor(doctor), nurse(nurse)
{
	surgery = nullptr;
	visitType = CHECK;
}

Visit::Visit(Patient* patient,const Date& date, Department* department,
	bool isFast, int opRoom, Doctor* doctor, Nurse* nurse)
	: patient(patient), DateOfArrival(date), department(department)
	, doctor(doctor), nurse(nurse)
{
	surgery = new Surgery(isFast, opRoom);
	check = nullptr;
	visitType = SURGERY;
}

const string& Visit::getPatientDepartment() const { return department->getName(); }

Doctor* Visit::getPatientDoctor() const { return doctor; }

Nurse* Visit::getPatientNurse() const { return nurse; }

const string& Visit::getPatientVisitPurpose() const // for printing
{ 
	if (visitType == CHECK)
		return "Check";
	else
		return "Surgery";
}

const Date& Visit::getDateOfArrival() const { return DateOfArrival; }

bool Visit::setPatientDepartment(Department* new_department)
{
	department = new_department;
	if (new_department == nullptr)
		return true;
	if (new_department->doesPatientExist(patient) == false)
		new_department->addPatient(patient);
	return true;
}

bool Visit::setNurse(Nurse* new_nurse)
{
	nurse = new_nurse;
	return true;
}
bool Visit::setDoctor(Doctor* new_doctor)
{
	doctor = new_doctor;
	return true;
}
