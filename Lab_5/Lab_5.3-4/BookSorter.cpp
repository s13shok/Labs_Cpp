#include "BookSorter.h"

bool BookSorter::operator()(Book* b1, Book* b2) {
	return (b1->getName() < b2->getName());
}
