#ifndef __SURGEON_H
#define __SURGEON_H

#include <iostream>
#include <string> 
#include "doctor.h"

using namespace std;

class Surgeon : public Doctor
{
public:
	Surgeon(const string& name, const int id, const Date& birthdate, const string& expertise,
		eGender gender, Department* department = nullptr, int NumOfSurgeries = 0);

	Surgeon(const Surgeon& other);
	virtual ~Surgeon();

	void setSurgeonNumOfSurgeries(int NumOfSurgeries);
	const int getSurgeonNumOfSurgeries() const;

	virtual void WorkerTypeOs(ostream& os) const override;

private:
	int NumOfSurgeries;
};

#endif