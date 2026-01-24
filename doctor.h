#ifndef __DOCTOR_H
#define __DOCTOR_H

#include <iostream>
#include <string> 
#include "worker.h"

using namespace std;

class Department;
class Surgeon;

class Doctor : public Worker
{
public:
	Doctor(const string& name, const int id, const Date& birthdate, const string& expertise,
		eGender gender, Department* department = nullptr);

	Doctor(const Doctor& other);
	virtual ~Doctor();

	void setDoctorExpertise(const string& expertise);
	const string& getDoctorExpertise() const; 

	friend ostream& operator<<(ostream& os, const Doctor& doctor);
	virtual void WorkerTypeOs(ostream& os) const override;

private:
	string expertise; 
};

#endif