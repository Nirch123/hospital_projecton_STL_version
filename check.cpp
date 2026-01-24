#pragma warning (disable: 4996)

#include "check.h"
#include <string>
#include <iostream>
using namespace std;

Check::Check(const string& checkName)
{
	this->checkName = checkName;
}
//Check::~Check()
//{
//	delete[] checkName;
//}
const string& Check::getCheckType() const { return checkName; }

bool Check::setCheckType(const string& checkName)
{
	this->checkName = checkName;
	return true;
}
