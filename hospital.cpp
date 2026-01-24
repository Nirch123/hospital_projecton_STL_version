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

	departments = new Department* [1];
	staff = new Worker* [1];
	patients = new Patient* [1];
	logicalDepartments = 1;
	physicalDepartments = 0;
	physicalStaff = 0;
	logicalStaff = 1;
	physicalPatients = 0;
	logicalPatients = 1;
}	

Hospital::~Hospital()
{
	cout << "DEBUG: in ~Hospital()";
	for (int i = 0; i < physicalDepartments; i++)
		delete departments[i]; // pointer only
	delete departments;
	delete[] staff; // check if it deletes all staff! (shows in DEBUG)
	/*delete[] name;*/
}

const string& Hospital::getName() const { return name; }

const int Hospital::getDepartmentsCount() const { return physicalDepartments; }

const int Hospital::getStaffAmount() const { return physicalStaff; }

const string& Hospital::getResearchCenterName() const { return researchCenter.getName(); }

bool Hospital::addDepartment(const string& departmentName)
{
	if (physicalDepartments == logicalDepartments) // extension of departments array
	{
		logicalDepartments = logicalDepartments * 2;
		Department** temp = new Department* [logicalDepartments];
		for (int i = 0; i < physicalDepartments; i++)
			temp[i] = departments[i];
		delete[] departments;
		departments = temp;
	}
	departments[physicalDepartments] = new Department(departmentName);
	physicalDepartments++;
	return true;
}

bool Hospital::removeDepartment(const Department& department)
{
	if (&department == nullptr)
		return false;
	for (int i = 0; i < physicalDepartments; i++)
	{
		if ((department.getName() == departments[i]->getName()))
		{
			delete departments[i];
			int j = i;
			do
			{
				departments[j] = departments[j+1];
				j++;
			} while (j < physicalDepartments);
			physicalDepartments--;
			return true; // department was found, deleted and others reorganized
		}
	}
	return false; // department was not found
}

ostream& operator<<(ostream& os, const Hospital& hospital)
{
	os << hospital.name;
	return os;
}

const string& Hospital::getDepartmentName(int num) const
{
	return departments[num]->getName();
}

const bool Hospital::doesDepartmentExist(const string& departmentName) const
{
	for (int i = 0; i < physicalDepartments; i++)
	{
		if (departmentName==departments[i]->getName())
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
	staff[physicalStaff] = d;
	++physicalStaff;
	if (physicalStaff == logicalStaff) // extension of staff array
	{
		logicalStaff = logicalStaff * 2;
		Worker** temp = new Worker * [logicalStaff];
		for (int i = 0; i < physicalStaff; i++)
			temp[i] = staff[i];
		delete[] staff;
		staff = temp;
	}
	if (doesDepartmentExist(doctor.getWorkerDepartmentByName()))
		getDepartmentByName((staff[physicalStaff-1])->getWorkerDepartmentByName())->addWorker(staff[physicalStaff-1]);
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
	staff[physicalStaff] = s;
	++physicalStaff;
	if (physicalStaff == logicalStaff) // extension of staff array
	{
		logicalStaff = logicalStaff * 2;
		Worker** temp = new Worker * [logicalStaff];
		for (int i = 0; i < physicalStaff; i++)
			temp[i] = staff[i];
		delete[] staff;
		staff = temp;
	}
	if (doesDepartmentExist(surgeon.getWorkerDepartmentByName()))
		getDepartmentByName((staff[physicalStaff - 1])->getWorkerDepartmentByName())->addWorker(staff[physicalStaff - 1]);
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
	staff[physicalStaff] = n;
	++physicalStaff;
	if (physicalStaff == logicalStaff) // extension of staff array
	{
		logicalStaff = logicalStaff * 2;
		Worker** temp = new Worker * [logicalStaff];
		for (int i = 0; i < physicalStaff; i++)
			temp[i] = staff[i];
		delete[] staff;
		staff = temp;
	}
	if (doesDepartmentExist(nurse.getWorkerDepartmentByName()))
		getDepartmentByName((staff[physicalStaff - 1])->getWorkerDepartmentByName())->addWorker(staff[physicalStaff - 1]);
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
	patients[physicalPatients] = p;
	++physicalPatients;
	if (physicalPatients == logicalPatients) // extension of patients array
	{
		logicalPatients = logicalPatients * 2;
		Patient** temp = new Patient * [logicalPatients];
		for (int i = 0; i < physicalPatients; i++)
			temp[i] = patients[i];
		delete[] patients;
		patients = temp;
	}
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
	if (physicalStaff == 0)
		return nullptr;
	for (int i = 0; i < physicalStaff; i++)
	{
		if (staff[i]->getWorkerId() == id)
			return dynamic_cast<Nurse*>(staff[i]);
	}
	return nullptr; // nurse not found
}

Doctor* Hospital::getDoctorById(int id)
{
	if (physicalStaff == 0)
		return nullptr;
	for (int i = 0; i < physicalStaff; i++)
	{
		if (staff[i]->getWorkerId() == id)
			return dynamic_cast<Doctor*>(staff[i]);
	}
	return nullptr; // doctor not found
}

Patient* Hospital::getPatientById(int id)
{
	if (physicalDepartments == 0)
		return nullptr; // no departments yet
	for (int i = 0; i < physicalDepartments; i++)
	{
		for (int j = 0; j < departments[i]->physicalPatients; j++)
		{
			if (id == (departments[i]->patientArr[j]->getId()))
				return departments[i]->patientArr[j]; // patient found
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
	for (int i = 0; i < physicalPatients; i++)
	{
		if (patients[i]->getId() == id)
			return patients[i]->getName();
	}
	return "Patient ID was not found";
}

Researchcenter* Hospital::getResearchCenter()
{
	return &researchCenter; 
}
