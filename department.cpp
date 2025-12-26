#pragma warning (disable: 4996)
#include "department.h"
#include <iostream>
using namespace std;


Department::Department(const char* name) 
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name); 
}

Department::Department(const Department& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

Department::~Department() 
{
	if (name != nullptr)
		delete[] name; 
}

const char* Department::getName() const { return name; }

ostream& operator<<(ostream& os, const Department& department)
{
	os << department.name;
	return os;
}
