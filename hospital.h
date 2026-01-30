#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "department.h";
#include "researchcenter.h"
#include "person.h"
class Date;

class Hospital
{
public:
	Hospital(const string& name, const string& rc_name);
	virtual ~Hospital();
	const string getName() const;
	const string getDepartmentName(int num) const;
	const int getDepartmentsCount() const;
	const int getDepartmentWorkersCount(const string& departmentName) const;
	const int getDepartmentPatientsCount(const string& departmentName) const;
	const int getStaffAmount() const;
	const bool doesDepartmentExist(const string& departmentName) const;
	const string& getResearchCenterName() const;
	Department* getDepartmentByName(const string& dName) const;
	Department* getDepartmentByIndex(const int index) const;
	Nurse* getNurseById(int id);
	Doctor* getDoctorById(int id);
	Patient* getPatientById(int id);
	const string& getPatientNameById(int id);
	bool addDepartment(const string& departmentName);
	bool addDoctor(Doctor& doctor);
	bool operator+=(Doctor& doctor);
	bool addSurgeon(Surgeon& surgeon);
	bool operator+=(Surgeon& surgeon);
	bool addNurse(Nurse& nurse);
	bool operator+=(Nurse& nurse);
	bool addPatient(const string& name, int id, const Date& birthdate, Person::eGender gender,
		const Date& dateofarrival, Department* department, Doctor* doctor = nullptr, Nurse* nurse = nullptr);
	Date createDate(int day, int month, int year);
	friend ostream& operator<<(ostream& os, const Hospital& hospital);
	bool updatePatientInformation(Patient* p,  Department* department = nullptr, Doctor* doctor = nullptr, Nurse* nurse = nullptr);
	Researchcenter* getResearchCenter();

private:
	string name;
	vector<Department*> departments;
	vector<Department*>::iterator departmentIterator = departments.begin();
	vector<Department*>::iterator departmentEnd = departments.end();
	vector<Worker*> staff;
	vector<Worker*>::iterator staffIterator = staff.begin();
	vector<Worker*>::iterator staffEnd = staff.end();
	vector<Patient*> patients;
	vector<Patient*>::iterator patientIterator = patients.begin();
	vector<Patient*>::iterator patientEnd = patients.end();
	Researchcenter researchCenter;
	Hospital(Hospital& other);
	Date* date;
	static int idCounter;


};

#endif
