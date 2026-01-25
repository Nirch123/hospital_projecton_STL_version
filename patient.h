#ifndef __PATIENT_H
#define __PATIENT_H

#include <iostream>
#include <vector>
#include <string>
#include "person.h"

using namespace std;

class Department;
class Nurse;
class Doctor;
class Visit;

class Patient : public Person
{
public:
	Patient(const string& name, int id, const Date& birthdate, eGender gender, const Date& dateofarrival, Department* department,
		Doctor* doctor = nullptr, Nurse* nurse = nullptr);

	virtual ~Patient();

	string getPatientDepartment() const;
	string getPatientVisitPurpose() const;
	const Date& getDateOfArrival() const;
	Doctor* getPatientDoctor() const;
	Nurse* getPatientNurse() const;
	const int getPatientId() const;

	bool setPatientDepartment(Department* department);

	friend ostream& operator<<(ostream& os, const Patient& patient);
	friend ostream& operator<<(ostream& os, const Patient* patient);

	bool CreateCheckVisit(Patient* patient, const Date& date, Department* department,
		string checkName, Doctor* doctor = nullptr, Nurse* nurse = nullptr);

	bool CreateSurgeryVisit(Patient* patient, const Date& date, Department* department,
		bool isFast, int opRoom, Doctor* doctor = nullptr, Nurse* nurse = nullptr);

	virtual void patientOs(ostream& os) const; 

	bool setNurse(Nurse* nurse);
	bool setDoctor(Doctor* doctor);

	friend class Hospital;

protected:
	vector<Visit*> visits; 
	int PatientId;

private:
	static int PatientIdCounter;
};

#endif