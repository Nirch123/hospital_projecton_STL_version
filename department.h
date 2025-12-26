#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include <iostream>
using namespace std;
//class Doctor;
//class Nurse;
//class Staff????

class Department
{
	public:
		Department(const char *name);
		Department(const Department& other);
		~Department();
		const char* getName() const;
		friend ostream& operator<<(ostream& os, const Department& department);
		friend class Hospital;
		
	private:
		char *name;
};
#endif