#include <iostream>
using namespace std;
#include "date.h"

Date::Date()
{
	day = month = 1;
	year = 1900;
}

Date::Date(int d, int m, int y)
{
	if (d > 31 || d < 1 || m>12 || m < 1 || y < 1900)
	{
		day = month = 1;
		year = 1900;
	}
	else
	{
		day = d;
		month = m;
		year = y;
	}
}

// Change: Added const
Date::Date(const Date& other)
{
	setDate(other.day, other.month, other.year);
}

void Date::show() const
{
	cout << day << "/" << month << "/" << year << endl;
}

ostream& operator<< (ostream& os, const Date& date)
{
	// Change: Removed "\n" to allow inline printing in other classes
	os << date.day << "/" << date.month << "/" << date.year;
	return os;
}

const int Date::getDate() const { return day, month, year; }

void Date::setDate(int d, int m, int y)
{
	day = d;
	month = m;
	year = y;
}