#include "researcher.h"

Researcher::Researcher(const string& name, const int id, const Date& birthdate, eGender gender, bool isDoctor)
	: Person(name, id, birthdate, gender), isDoctor(isDoctor) 
{
}

Researcher::Researcher(const Researcher& other)
	: Person(other.name, other.id, other.birthdate, other.gender), isDoctor(other.isDoctor), articles(other.articles)
{
}

bool Researcher::addArticle(const Article& article)
{
	articles.push_back(article);
	return true;
}

bool Researcher::getIsDoctor() const { return isDoctor; }

int Researcher::getNumOfArticles() const { return (int)articles.size(); }

ostream& operator<<(ostream& os, const Researcher& researcher)
{
	os << "\n\tResearcher Info:";
	os << "\n\tName: " << researcher.getName();
	os << "\n\tID: " << researcher.getId();
	os << "\n\tIs Doctor: " << (researcher.isDoctor ? "Yes" : "No");
	os << "\n\tArticles count: " << researcher.articles.size();

	if (!researcher.articles.empty())
	{
		os << "\n\tArticles List:";
		for (vector<Article>::const_iterator it = researcher.articles.begin(); it != researcher.articles.end(); ++it)
		{
			os << "\n\t# " << *it;
		}
	}
	return os;
}

void Researcher::researcherOs(ostream& os) const
{
	os << "\n\tTitle: Researcher";
}

bool Researcher::operator>(const Researcher& other) const
{
	return this->articles.size() > other.articles.size();
}