#ifndef __ARTICLE_H
#define __ARTICLE_H

#include <iostream>
using namespace std;
#include "date.h"

class Article
{
public:
	Article(const char* name, const char* magazineName, const Date& publishDate);
	Article(const Article& other);
	~Article();

	const char* getName() const;
	const char* getMagazineName() const;
	const Date& getPublishDate() const;

	friend ostream& operator<<(ostream& os, const Article& article);

private:
	char* name;
	char* magazineName;
	Date publishDate;
};

#endif