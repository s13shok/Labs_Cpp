#pragma once
#include "Book.h"
class BookFinder
{
	int leftYear_;
	int rightYear_;
public:
	BookFinder(int a, int b);
	bool operator()(Book* b1);
};

