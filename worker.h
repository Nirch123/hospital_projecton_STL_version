#ifndef __WORKER_H
#define __WORKER_H

#include <iostream>
#include <string>
#include "person.h"

using namespace std;

class Department;
class Doctor;

class Worker : public Person
{
public:
	enum eWorkerType { DOCTOR, NURSE, OTHER };

	Worker(const string& name, int id, const Date& birthdate, eGender gender, Department* department = nullptr);
	Worker(const Worker& other);

	virtual ~Worker();

	const int getWorkerId() const;

	string getWorkerDepartmentByName() const;
	Department* getWorkerDepartmentByAdress() const;

	const eWorkerType getWorkerType() const;

	bool setWorkerId(int workerId);

	bool setWorkerType(eWorkerType type);
	bool setWorkerDepartment(Department* new_department);

	friend ostream& operator<<(ostream& os, const Worker& worker);
	virtual void WorkerTypeOs(ostream& os) const {}

protected:
	int workerId; 
	Department* department;
	eWorkerType workertype;
};

#endif