#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#include "department.h";
#include "researchcenter.h"
#include <iostream>
using namespace std;
//class Department;
//class ResearchCenter;

class Hospital
{
public:
	Hospital(const char* name, Researchcenter& rc);
	~Hospital();
	const char* getName() const;
	const char* getDepartmentName(int num) const;
	const int getDepartmentsCount() const;
	const char* getResearchCenterName() const;
	bool addDepartment(Department& department);
	bool removeDepartment(Department& department);
	friend ostream& operator<<(ostream& os, const Hospital& hospital);

private:
	char* name;
	int logicalDepartments,physicalDepartments;
	Department** departments;
	Researchcenter& researchCenter;
	Hospital(Hospital& other);
};

#endif
