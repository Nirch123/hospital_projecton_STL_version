#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "worker.h"

int Worker::idCounter = 100;

Worker::Worker(const char* name, const int id, Date& birthdate, eGender gender, Department* department = nullptr) : Person(name, id, birthdate, gender), workerId(++idCounter)
{
	this->department = department;
}

Worker::~Worker()
{}

const int Worker::getWorkerId() const { return workerId; }

//const char* Worker::getWorkerDepartment() const { return department->getDepartmentName(); }

bool Worker::setWorkerDepartment(Department& new_department)
{
	department = &new_department;
	return true;
}
