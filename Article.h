#ifndef __ARTICLE_H
#define __ARTICLE_H

#include <iostream>
#include <string> 
using namespace std;

#include "date.h"

class Article
{
public:
	Article(const string& name, const string& magazineName, const Date& publishDate);


	const string getName() const;         
	const string getMagazineName() const; 
	const Date& getPublishDate() const;

	friend ostream& operator<<(ostream& os, const Article& article);

private:
	string name;          
	string magazineName;  
	Date publishDate;
};

#endif