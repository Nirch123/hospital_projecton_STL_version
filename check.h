#ifndef __CHECK_H
#define __CHECK_H


#include <iostream>
#include<string>
using namespace std;

class Check
{
public:
	Check(const string& checkName);
	~Check();
	const string getCheckType() const;
	bool setCheckType(const string& checkName);
private:
	//Check(Check& other);
	string checkName;
};

#endif
