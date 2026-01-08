#pragma warning (disable: 4996)
#include "article.h"
#include <cstring>

Article::Article(const char* name, const char* magazineName, const Date& publishDate)
	: publishDate(publishDate) // This calls Date(const Date& other)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->magazineName = new char[strlen(magazineName) + 1];
	strcpy(this->magazineName, magazineName);
}

Article::Article(const Article& other) : publishDate(other.publishDate)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->magazineName = new char[strlen(other.magazineName) + 1];
	strcpy(this->magazineName, other.magazineName);
}

Article::~Article()
{
	delete[] name;
	delete[] magazineName;
}

const char* Article::getName() const { return name; }
const char* Article::getMagazineName() const { return magazineName; }
const Date& Article::getPublishDate() const { return publishDate; }

ostream& operator<<(ostream& os, const Article& article)
{
	os << "Article: " << article.name << ", Magazine: " << article.magazineName
		<< ", Date: " << article.publishDate;
	return os;
}