#pragma warning (disable: 4996)
using namespace std;
#include "researchcenter.h"
#include <iostream>

Researchcenter::Researchcenter(const string& name, int ResearcherCount) : name(name), ResearcherCount(0)
{
}

Researchcenter::~Researchcenter()
{
	for (vector<Researcher*>::iterator itr = allResearchers.begin(); itr != allResearchers.end(); ++itr)
	{
		delete* itr; 
	}
}

const string& Researchcenter::getName() const { return name; }

const int Researchcenter::getResearcherCount() const { return ResearcherCount; }

const vector<Researcher*> Researchcenter::getResearchersVector() const { return allResearchers; }

bool Researchcenter::addResearcher(const Researcher& r)
{
	allResearchers.push_back(new Researcher(r));
	ResearcherCount++;
	return true;
}

const Researcher* Researchcenter::getResearcherById(int id) const
{
	for (vector<Researcher*>::const_iterator it = allResearchers.begin(); it != allResearchers.end(); ++it)
	{

		if ((*it)->getId() == id)
			return *it;
	}
	return nullptr;
}

bool Researchcenter::addArticleToResearcher(int researcherId, const Article& article)
{
	for (vector<Researcher*>::iterator itr = allResearchers.begin(); itr != allResearchers.end(); ++itr)
	{
		if ((*itr)->getId() == researcherId)
		{
			return (*itr)->addArticle(article);
		}
	}
	return false;
}

ostream& operator<<(ostream& os, const Researchcenter& researchcenter)
{
	os << "Research Center: " << researchcenter.name
		<< " (Researchers count: " << researchcenter.allResearchers.size() << ")";
	return os;
}

Researchcenter& Researchcenter::operator+=(const Researcher& other)
{
	this->addResearcher(other);
	return *this;
}

