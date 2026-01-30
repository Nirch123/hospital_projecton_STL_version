#ifndef __RESEARCHCENTER_H
#define __RESEARCHCENTER_H

using namespace std;
#include <iostream>
#include <vector> 
#include <string> 
#include "researcher.h" 

class Researchcenter
{
public:
	Researchcenter(const string& name, int ResearcherCount);

	~Researchcenter();

	const string& getName() const;

	const int getResearcherCount() const;

	const vector<Researcher*> getResearchersVector() const;

	bool addResearcher(const Researcher& r);

	bool addArticleToResearcher(int researcherId, const Article& article);

	const Researcher* getResearcherById(int id) const;

	friend ostream& operator<<(ostream& os, const Researchcenter& researchcenter);

	Researchcenter& operator+=(const Researcher& researcher);

private:
	string name;

	vector<Researcher*> allResearchers;

	int ResearcherCount;
};

#endif