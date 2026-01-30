#pragma warning (disable: 4996)
using namespace std;
#include <vector> 
#include <string>
#include "hospital.h"
#include "worker.h"
#include "doctor.h"
#include "nurse.h"
#include "date.h"
#include "patient.h"
#include "surgeon.h"
#include "visit.h"
#include "check.h"
#include "surgery.h"

int Hospital::idCounter = 100;

Hospital::Hospital(const string& name, const string& rc_name) : name(name), researchCenter(rc_name)
{
}	

Hospital::~Hospital()
{
	cout << "DEBUG: in ~Hospital()";
}

const string Hospital::getName() const { return name; }

const int Hospital::getDepartmentsCount() const { return departments.size(); }

const int Hospital::getStaffAmount() const { return staff.size(); }

const string& Hospital::getResearchCenterName() const { return researchCenter.getName(); }

bool Hospital::addDepartment(const string& departmentName)
{
	departments.push_back(new Department(departmentName));
	return true;
}

ostream& operator<<(ostream& os, const Hospital& hospital)
{
	os << hospital.name;
	return os;
}

const string Hospital::getDepartmentName(int num) const
{
	return departments[num]->getName();
}

const bool Hospital::doesDepartmentExist(const string& departmentName) const
{
	for (auto localIterator = departments.begin(); localIterator != departments.end(); ++localIterator)
	{
		if (departmentName == (*localIterator)->getName())
			return true;
	}
	return false;
}


const int Hospital::getDepartmentWorkersCount(const string& departmentName) const
{
	if (doesDepartmentExist(departmentName) == true)
	{
		return getDepartmentByName(departmentName)->getWorkersAmount();
	}
	else
		return -1;
}

const int Hospital::getDepartmentPatientsCount(const string& departmentName) const
{
	if (doesDepartmentExist(departmentName) == true)
	{
		return getDepartmentByName(departmentName)->getPatientsAmount();
	}
	else
		return -1;
}


Department* Hospital::getDepartmentByName(const string& dName) const
{
	for (int i = 0; i < getDepartmentsCount(); i++)
	{
		if (departments[i]->getName()== dName)
			return (departments[i]);
	}
	return nullptr;
}

Department* Hospital::getDepartmentByIndex(const int index) const { return departments[index]; }

bool Hospital::addDoctor(Doctor& doctor)
{
	Doctor* d = new Doctor(doctor);
	d->setWorkerId(idCounter++);
	staff.push_back(d);
	if (doesDepartmentExist(doctor.getWorkerDepartmentByName()))
		(staff.back())->getWorkerDepartmentByAdress()->addWorker(staff.back());
	return true;
}


bool Hospital::operator+=(Doctor& doctor)
{
	addDoctor(doctor);
	return true;
}

bool Hospital::addSurgeon(Surgeon& surgeon)
{
	Surgeon* s = new Surgeon(surgeon);
	s->setWorkerId(idCounter++);
	staff.push_back(s);
	if (doesDepartmentExist(surgeon.getWorkerDepartmentByName()))
		(staff.back())->getWorkerDepartmentByAdress()->addWorker(staff.back());
	return true;
}


bool Hospital::operator+=(Surgeon& surgeon)
{
	addSurgeon(surgeon);
	return true;
}

bool Hospital::addNurse(Nurse& nurse)
{
	Nurse* n = new Nurse(nurse);
	n->setWorkerId(idCounter++);
	staff.push_back(n);
	if (doesDepartmentExist(nurse.getWorkerDepartmentByName()))
		(staff.back())->getWorkerDepartmentByAdress()->addWorker(staff.back());
	return true;
}

bool Hospital::operator+=(Nurse& nurse)
{
	addNurse(nurse);
	return true;
}

bool Hospital::addPatient(const string& name, int id, const Date& birthdate, Person::eGender gender,
	const Date& dateofarrival, Department* department, Doctor* doctor, Nurse* nurse)
{
	Patient* p = new Patient(name, id, birthdate, gender, dateofarrival, department, doctor, nurse);
	patients.push_back(p);
	if (department != NULL)
	{
		department->addPatient(p);
		return true;
	}
	else
		return false;
}

Date Hospital::createDate(int day, int month, int year)
{
	Date tempDate(day,month,year);
	return tempDate;
}

Nurse* Hospital::getNurseById(int id)
{
	if (staff.size() == 0)
		return nullptr;
	staffIterator = staff.begin();
	staffEnd = staff.end();
	for (; staffIterator != staffEnd; ++staffIterator)
	{
		if ((*staffIterator)->getWorkerId() == id)
			return dynamic_cast<Nurse*>(*staffIterator);
	}
	return nullptr; // nurse not found
}

Doctor* Hospital::getDoctorById(int id)
{
	if (staff.size() == 0)
		return nullptr;
	staffIterator = staff.begin();
	staffEnd = staff.end();
	for (; staffIterator != staffEnd; ++staffIterator)
	{
		if ((*staffIterator)->getWorkerId() == id)
			return dynamic_cast<Doctor*>(*staffIterator);
	}
	return nullptr; // doctor not found
}

Patient* Hospital::getPatientById(int id)
{
	if (departments.size() == 0)
		return nullptr; // no departments yet
	departmentIterator = departments.begin();
	departmentEnd = departments.end();
	for (; departmentIterator != departmentEnd; ++departmentIterator)
	{
		for (int j = 0; j < (*departmentIterator)->getPatientsAmount(); j++)
		{
			if (id == ((*departmentIterator)->patients[j]->getId()))
				return (*departmentIterator)->patients[j]; // patient found
		}
	}
	return nullptr; // patient not found
}

bool Hospital::updatePatientInformation(Patient* p, Department* department, Doctor* doctor, Nurse* nurse)
{
	getDepartmentByName((p->getPatientDepartment()))->removePatient(p);
	p->setPatientDepartment(department);
	p->setDoctor(doctor);
	p->setNurse(nurse);
	return true;
}

const string& Hospital::getPatientNameById(int id)
{
	patientIterator = patients.begin();
	patientEnd = patients.end();
	for (; patientIterator != patientEnd; ++patientIterator)
	{
		if ((*patientIterator)->getId() == id)
			return (*patientIterator)->getName();
	}
	return "Patient ID was not found";
}

Researchcenter* Hospital::getResearchCenter()
{
	return &researchCenter; 
}
