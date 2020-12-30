#include "BookFinder.h"

BookFinder::BookFinder(int firstYear, int secondYear) {
	if (firstYear < secondYear) {
		leftYear_ = firstYear;
		rightYear_ = secondYear;
	}
	else {
		leftYear_ = secondYear;
		rightYear_ = firstYear;
	}
}

bool BookFinder::operator()(Book* book) {
	return ((book->getYear() <= rightYear_) && (book->getYear() >= leftYear_));
}

