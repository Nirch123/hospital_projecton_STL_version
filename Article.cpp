#include "article.h"

Article::Article(const string& name, const string& magazineName, const Date& publishDate)
	: name(name), magazineName(magazineName), publishDate(publishDate)
{
}


const string& Article::getName() const { return name; }

const string& Article::getMagazineName() const { return magazineName; }

const Date& Article::getPublishDate() const { return publishDate; }

ostream& operator<<(ostream& os, const Article& article)
{
	os << "Article: " << article.name << ", Magazine: " << article.magazineName
		<< ", Date: " << article.publishDate;
	return os;
}