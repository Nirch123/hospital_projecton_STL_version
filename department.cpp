#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "department.h"
//#include "person.h"
#include "worker.h"
#include "patient.h"


Department::Department(const string& name) : name(name)
{
}

//Department::~Department() 
//{
//	cout << "\nDEBUG: in ~Department()";
//	if (name != nullptr)
//		delete[] name; 
//}

bool Department::addWorker(Worker* worker)
{
	for (; workerIterator != workerEnd; ++workerIterator)  // check if worker id is in department already
		if (worker->getWorkerId() == (*workerIterator)->getWorkerId())
			return false;

	workers.push_back(worker);
	if ((worker->getWorkerDepartmentByName())!= workers.back()->getWorkerDepartmentByName())
		worker->setWorkerDepartment(this); // make sure worker acknowledges it's new department
	return true;
}

bool Department::addPatient(Patient* patient)
{
	for (; patientIterator != patientEnd; ++patientIterator)  
		if (patient->getId() == (*patientIterator)->getId())
			return false;

	patients.push_back(patient);
	return true;
}

bool Department::removeWorker(Worker* worker)
{
	for (; workerIterator != workerEnd; ++workerIterator)  // check if worker id is in department already
		if (worker->getId() == (*workerIterator)->getId())
		{
			(*workerIterator)->setWorkerDepartment(nullptr);
			do
			{
				(*workerIterator) = ++(*workerIterator);
				++workerIterator;
			}
			while (workerIterator != workerEnd);
			return true; // worker was found and removed from department
		}
		return false; // worker was not found
}

bool Department::removePatient(Patient* patient)
{
	for (; patientIterator != patientEnd; ++patientIterator) 
		if (patient->getId() == (*patientIterator)->getId())
		{
			(*patientIterator)->setPatientDepartment(nullptr);
			do
			{
				(*patientIterator) = ++(*patientIterator);
				++patientIterator;
			} while (patientIterator != patientEnd);
			return true; 
		}
	return false;
}

const string Department::getName() const 
{
	if (this == nullptr)
		return "NONE";
	else
		return name; 
}

const int Department::getWorkersAmount() const { return workers.size(); }

const int Department::getPatientsAmount() const { return patients.size(); }

const Worker& Department::getWorkerByIndex(int index) const { return *(workers[index]); }

const Patient& Department::getPatientByIndex(int index) const { return *(patients[index]); }

ostream& operator<<(ostream& os, const Department& department)
{
	os << department.name;
	return os;
}

const bool Department::doesPatientExist(const Patient* patient)
{
	if (patient->getPatientDepartment()=="NONE")
		return true; // if patient is in no department it's "undefined"
	for (; patientIterator != patientEnd; ++patientIterator)
		if (patient->getId() == (*patientIterator)->getId())
			return true;
	return false;
}

