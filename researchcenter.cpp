#pragma warning (disable: 4996)
using namespace std;
#include "researchcenter.h"
#include <iostream>

Researchcenter::Researchcenter(const string& name) : name(name)
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

bool Researchcenter::addResearcher(const Researcher& r)
{
	allResearchers.push_back(new Researcher(r));
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

void Researchcenter::printAllResearchers() const
{
	if (allResearchers.empty())
		cout << "\nNo researchers in center.";
	else
	{
		cout << "\nList of Researchers in " << name << ":";

		for (vector<Researcher*>::const_iterator itr = allResearchers.begin(); itr != allResearchers.end(); ++itr)
		{

			cout << "\n" << **itr;
		}
	}
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