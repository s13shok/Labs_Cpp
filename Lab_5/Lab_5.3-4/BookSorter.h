#pragma once
#include "Book.h"
class BookSorter
{
public:
	bool operator() (Book* b1, Book* b2);
};

