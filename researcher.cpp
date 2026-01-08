#pragma warning (disable: 4996)
#include "researcher.h"
#include "department.h"

Researcher::Researcher(const char* name, const int id, const Date& birthdate, eGender gender, bool isDoctor)
	: Worker(name, id, birthdate, gender, nullptr), isDoctor(isDoctor)
{
	physicalArticles = 0;
	logicalArticles = 2;
	articles = new Article * [logicalArticles];
}

Researcher::~Researcher()
{
	for (int i = 0; i < physicalArticles; i++)
		delete articles[i];
	delete[] articles;
}

bool Researcher::addArticle(const Article& article)
{
	if (physicalArticles == logicalArticles)
	{
		logicalArticles *= 2;
		Article** temp = new Article * [logicalArticles];
		for (int i = 0; i < physicalArticles; i++)
			temp[i] = articles[i];
		delete[] articles;
		articles = temp;
	}
	articles[physicalArticles++] = new Article(article);
	return true;
}

bool Researcher::getIsDoctor() const { return isDoctor; }

int Researcher::getNumOfArticles() const { return physicalArticles; }

ostream& operator<<(ostream& os, const Researcher& researcher)
{
	// שינוי קריטי: לא קוראים ל-(Worker&)researcher כדי לא להדפיס מחלקה ולגרום לקריסה
	// מדפיסים את נתוני העובד ידנית
	os << "\n\tResearcher Info:";
	os << "\n\tName: " << researcher.getName();     // ירושה מ-Person
	os << "\n\tID: " << researcher.getWorkerId();   // ירושה מ-Worker
	// דילגנו על הדפסת המחלקה!

	os << "\n\tIs Doctor: " << (researcher.isDoctor ? "Yes" : "No");
	os << "\n\tArticles count: " << researcher.physicalArticles;
	if (researcher.physicalArticles > 0)
	{
		os << "\n\tArticles List:";
		for (int i = 0; i < researcher.physicalArticles; i++)
			os << "\n\t\t" << *researcher.articles[i];
	}
	return os;
}

void Researcher::researcherOs(ostream& os) const
{
	os << "\n\tTitle: Researcher";
}