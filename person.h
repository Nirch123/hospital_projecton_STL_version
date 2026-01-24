#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <string> 
#include "date.h"

using namespace std;

class Person
{
public:
	enum eGender { MALE, FEMALE, OTHER };

	Person(const string& name, int id, const Date& birthdate, eGender gender);
	Person(const string& name, Date& birthdate); 
	Person(const Person& other);
	virtual ~Person();

	const string& getName() const; 
	const int getId() const;
	const string getGender() const;
	const Date& getBirthDate() const;

protected:
	string name; 
	int id;
	const Date birthdate;
	eGender gender;
};

#endif