#ifndef __RESEARCHCENTER_H
#define __RESEARCHCENTER_H

using namespace std;
#include <iostream>
//#include "researcher.h"


class Researchcenter
{
public:
	Researchcenter(const char* name);
	~Researchcenter();
	const char* getName() const;
	const int getNumOfResearchers() const;
	//bool removeResearcher(const char* researcherName);
	//bool addReasearcher(Researcher* r);
	//void printResearchcenter() const;
	friend ostream& operator<<(ostream& os, const Researchcenter& researchcenter);

private:
	char* name;
	int  NumOfResearchers;
	//esearcher allResearchers**;
};

#endif