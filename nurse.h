#ifndef __NURSE_H
#define __NURSE_H

#include "worker.h"
#include <string> 
using namespace std;

class Nurse : public Worker
{
public:

	Nurse(const string& name, int id, const Date& birthdate, eGender gender, Department* department, int yearsOfExperience);
	Nurse(const Nurse& other);

	int getYearsOfExperience() const;
	virtual void WorkerTypeOs(ostream& os) const;

private:
	int yearsOfExperience;
};

#endif