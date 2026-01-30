#pragma warning (disable: 4996)
#include "worker.h"
#include "department.h"
#include "doctor.h"

Worker::Worker(const string& name, int id, const Date& birthdate, eGender gender, Department* department)
	: Person(name, id, birthdate, gender), department(department)
{
	this->workerId = 0; 
	this->workertype = OTHER;
}

Worker::Worker(const Worker& other)
	: Person(other.name,other.id,other.birthdate,other.gender), department(other.department), workerId(other.workerId), workertype(other.workertype)
{
}

Worker::~Worker()
{
}

const int Worker::getWorkerId() const { return workerId; }

string Worker::getWorkerDepartmentByName() const
{
	if (department)
		return string(department->getName());
	return "None";
}

Department* Worker::getWorkerDepartmentByAdress() const
{
	return department;
}

bool Worker::setWorkerDepartment(Department* new_department)
{
	department = new_department;
	if (department != nullptr)
	{
		department->addWorker(this);
	}
	return true;
}

bool Worker::setWorkerId(int newWorkerId)
{
	this->workerId = newWorkerId;
	return true;
}

const Worker::eWorkerType Worker::getWorkerType() const { return workertype; }

bool Worker::setWorkerType(Worker::eWorkerType type)
{
	this->workertype = type;
	return true;
}

ostream& operator<<(ostream& os, const Worker& worker)
{
	os << "\tWorker Id: " << worker.getWorkerId() 
		<< "\n\tName: " << worker.getName()
		<< "\n\tID: " << worker.getId()      
		<< "\n\tGender: " << worker.getGender();

	if (worker.department)
		os << "\n\tDepartment: " << worker.department->getName();
	else
		os << "\n\tDepartment: None";

	worker.WorkerTypeOs(os);
	return os;
}