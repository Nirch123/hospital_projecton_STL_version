#pragma warning (disable: 4996)
#include <iostream>
#include <string>
#include "person.h"

using namespace std;

Person::Person(const string& name, int id, const Date& birthdate, eGender gender)
	: name(name), id(id), birthdate(birthdate), gender(gender)
{
}

Person::Person(const string& name, Date& birthdate)
	: name(name), birthdate(birthdate), id(0), gender(MALE)
{
}

Person::Person(const Person& other)
	: name(other.name), id(other.id), birthdate(other.birthdate), gender(other.gender)
{
}

Person::~Person()
{
}

const string& Person::getName() const
{
	return name;
}

const int Person::getId() const { return id; }

const int Person::getGender() const { return gender; }

const Date& Person::getBirthDate() const { return birthdate; }