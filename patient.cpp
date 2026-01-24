#pragma warning (disable: 4996)

#include "patient.h"
#include "department.h"
#include "doctor.h"
#include "nurse.h"
#include "date.h"
#include "visit.h"

int Patient::PatientIdCounter = 1000;

Patient::Patient(const string& name, int id, const Date& birthdate, eGender gender, const Date& dateofarrival, Department* department,
	Doctor* doctor, Nurse* nurse)
	: Person(name, id, birthdate, gender), PatientId(PatientIdCounter++)
{
}

Patient::~Patient()
{
	for (auto* v : visits)
		delete v;
	visits.clear();
}

bool Patient::CreateCheckVisit(const Patient* patient, const Date& date, Department* department,
	const string& checkName, Doctor* doctor, Nurse* nurse)
{
	if (department == nullptr)
		return false;

	visits.push_back(new Visit(const_cast<Patient*>(this), date, department, checkName.c_str(), doctor, nurse));
	return true;
}

bool Patient::CreateSurgeryVisit(const Patient* patient, const Date& date, Department* department,
	bool isFast, int opRoom, Doctor* doctor, Nurse* nurse)
{
	if (department == nullptr)
		return false;

	visits.push_back(new Visit(const_cast<Patient*>(this), date, department, isFast, opRoom, doctor, nurse));
	return true;
}

const int Patient::getPatientId() const { return PatientId; }

string Patient::getPatientDepartment() const
{
	if (visits.empty()) return "None";
	return visits.back()->getPatientDepartment(); 
}

Doctor* Patient::getPatientDoctor() const
{
	if (visits.empty()) return nullptr;
	return visits.back()->getPatientDoctor();
}

Nurse* Patient::getPatientNurse() const
{
	if (visits.empty()) return nullptr;
	return visits.back()->getPatientNurse();
}

string Patient::getPatientVisitPurpose() const
{
	if (visits.empty()) return "No Visits Yet";
	return visits.back()->getPatientVisitPurpose();
}

const Date& Patient::getDateOfArrival() const
{

	if (visits.empty())
	{
		static Date defaultDate(1, 1, 2000);
		return defaultDate;
	}
	return visits.back()->getDateOfArrival();
}

bool Patient::setPatientDepartment(Department* new_department)
{
	if (visits.empty()) return false;

	visits.back()->setPatientDepartment(new_department);
	if (new_department->doesPatientExist(this) == false)
		new_department->addPatient(this);
	return true;
}

bool Patient::setNurse(Nurse* new_nurse)
{
	if (visits.empty()) return false;
	visits.back()->setNurse(new_nurse);
	return true;
}

bool Patient::setDoctor(Doctor* new_doctor)
{
	if (visits.empty()) return false;
	visits.back()->setDoctor(new_doctor);
	return true;
}

ostream& operator<<(ostream& os, const Patient& patient)
{
	os << "\tId: " << patient.getId() <<
		"\n\tName: " << patient.getName() <<
		"\n\tGender: " << patient.getGender() <<
		"\n\tDOB: " << patient.getBirthDate() <<
		"\n\tPatient Id : " << patient.getPatientId();

	if (!patient.visits.empty())
	{
		os << "\n\tDepartment: " << patient.getPatientDepartment() <<
			"\n\tDOA: " << patient.getDateOfArrival() <<
			"\n\tVisit reason: " << patient.getPatientVisitPurpose();
		if (patient.getPatientDoctor() != NULL)
			os << "\n\tAssigned Doctor: Dr." << patient.getPatientDoctor()->getName();
		else
			os << "\n\tNo Assigned Doctor";
		if (patient.getPatientNurse() != NULL)
			os << "\n\tAssigned Nurse: " << patient.getPatientNurse()->getName();
		else
			os << "\n\tNo Assigned Nurse";
	}
	else
	{
		os << "\n\t(No visits logged yet)";
	}
	return os;
}

ostream& operator<<(ostream& os, const Patient* patient)
{
	if (!patient) return os;
	return os << *patient;
}

void Patient::patientOs(ostream& os) const
{
	if (!visits.empty())
	{
		os << "\nDate of arrival: " << getDateOfArrival() <<
			"\nVisit purpose: " << getPatientVisitPurpose() <<
			"\nDepartment: " << getPatientDepartment();
	}
}