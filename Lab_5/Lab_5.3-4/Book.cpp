#include "Book.h"

Book::Book(std::string name, std::string author, int year) {
	name_ = name;
	author_ = author;
	year_ = year;
}

std::string Book::getAuthor() {
	return author_;
}

std::string Book::getName() {
	return name_;
}

int Book::getYear() {
	return year_;
}
