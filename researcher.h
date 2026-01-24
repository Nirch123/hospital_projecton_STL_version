#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "person.h" 
#include "article.h"
#include <vector>
#include <string>

class Researcher : public Person
{
public:
	Researcher(const string& name, const int id, const Date& birthdate, eGender gender, bool isDoctor);

	Researcher(const Researcher& other);

	bool addArticle(const Article& article);
	bool getIsDoctor() const;
	int getNumOfArticles() const;

	friend ostream& operator<<(ostream& os, const Researcher& researcher);
	virtual void researcherOs(ostream& os) const; 
	bool operator>(const Researcher& other) const;

private:
	bool isDoctor;
	vector<Article> articles;
};

#endif