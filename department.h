#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person;
class Worker;
class Patient;
class Doctor;
class Nurse;
class Surgeon;

class Department
{
	public:
		//enum eWorkerType {DOCTOR, NURSE, OTHER}; // should classification be under department? or under worker?
		Department(const string& name);
		//Department(const Department& other) = delete;
		//virtual ~Department();
		bool addWorker(Worker* worker);
		bool addPatient(Patient* patient);
		bool removeWorker(Worker* worker);
		bool removePatient(Patient* patient);
		const string getName() const;
		const int getWorkersAmount() const;
		const int getPatientsAmount() const;
		const Worker& getWorkerByIndex(int index) const;
		const Patient& getPatientByIndex(int index) const;
		friend ostream& operator<<(ostream& os, const Department& department);
		const bool doesPatientExist(const Patient* patient);
		friend class Hospital;
		
	private:
		string name;
		//int physicalWorkers, logicalWorkers, physicalPatients, logicalPatients;
		//Patient** patientArr;
		//Worker** workerarr;
		vector<Worker*> workers;
		vector<Worker*>::iterator workerIterator = workers.begin();
		vector<Worker*>::iterator workerEnd = workers.end();
		vector<Patient*> patients;
		vector<Patient*>::iterator patientIterator = patients.begin();
		vector<Patient*>::iterator patientEnd = patients.end();
};
#endif