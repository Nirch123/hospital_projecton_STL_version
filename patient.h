#ifndef __PATIENT_H
#define __PATIENT_H

#include "person.h"
class Department;
class Nurse;
class Doctor;

class Patient : public Person
{
public:
	Patient(const char* name, const int id, Date& birthdate, eGender gender, Department* department = nullptr, 
		Doctor* doctor=nullptr, Nurse* nurse=nullptr, Date& dateofarrival, char* VisitPurpose);
	~Patient();
	const char* getPatientDepartment() const;
	const char* getPatientVisitPurpose() const;
	Doctor* getPatientDoctor() const;
	Nurse* getPatientNurse() const;
	const int getPatientId() const;
	bool setPatientDepartment(Department* department);
	bool setDateOfArrival(Date& dateofarrival);
	friend ostream& operator<<(ostream& os, const Patient& patient);



protected:
	Date& dateofarrival;
	Department* department;
	Doctor* MyDoctor;
	Nurse* MyNurse;
	char* VisitPurpose;
	int PatientId;


private:
	static int PatientIdCounter;
};

#endif
