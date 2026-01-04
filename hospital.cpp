#pragma warning (disable: 4996)
#include "hospital.h"
#include "worker.h"


Hospital::Hospital(const char* name, Researchcenter& rc) : researchCenter(rc)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	departments = new Department* [1];
	logicalDepartments = 1;
	physicalDepartments = 0;
}	

Hospital::~Hospital()
{
	for (int i = 0; i < physicalDepartments; i++)
		delete departments[i]; // pointer only
	delete[] departments;
	delete[] name;
}

const char* Hospital::getName() const { return name; }

const int Hospital::getDepartmentsCount() const { return physicalDepartments; }

const char* Hospital::getResearchCenterName() const { return researchCenter.getName(); }

bool Hospital::addDepartment(Department& department)
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
	departments[physicalDepartments] = new Department(department);
	physicalDepartments++;
	return true;
}

bool Hospital::removeDepartment(const Department& department)
{
	if (&department == nullptr)
		return false;
	for (int i = 0; i < physicalDepartments; i++)
	{
		if (strcmp(department.getName(), departments[i]->getName()) == 0)
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

const char* Hospital::getDepartmentName(int num) const
{
	return departments[num]->getName();
}

bool Hospital::printDepartments() // printing in "master class" allowed?
{
	cout << "\nHospital departments are : \n";
	for (int i = 0; i < getDepartmentsCount(); i++)
		cout << "(" << i << ") " << getDepartmentName(i) << "\n";
	return true;
}

bool Hospital::printWorkersInDepartment(Department& department)
{
	cout << "\nDepartment " << department << " workers are : \n";
	if (department.getWorkersAmount() == 0)
		cout << "There are no workers in this department\n";
	else
	{
		for (int i = 0; i < department.getWorkersAmount(); i++)
			cout << "(" << i << ") " << department.getWorkerByIndex(i) << "\n\n";
	}
	//add for patients
	return true;
}

const Department* Hospital::getDepartmentByName(const char* dName) const
{
	for (int i = 0; i < getDepartmentsCount(); i++)
	{
		if (strcmp(departments[i]->getName(), dName) == 0)
			return (departments[i]);
	}
	return nullptr;
}