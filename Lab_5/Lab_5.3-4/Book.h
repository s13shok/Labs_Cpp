#pragma once
#include <string>
class Book
{
	std::string name_;
	std::string author_;
	int year_;
public:
	Book(std::string name, std::string author, int year);
	std::string getAuthor();
	std::string getName();
	int getYear();
};

