//		Создать класс книги Book, в котором хранится название, автор и год издания книги.
//	В главной функции создать коллекцию книг(приложение А). Продемонстрировать
//	сортировку книг по автору(первичный ключ) и названию(вторичный ключ).
//	Продемонстрировать поиск в коллекции : найти все книги, год издания которых
//	находится в указанном диапазоне. Использовать контейнер std::vector и функторы.
//		Подсчитать и вывести на консоль количество всех книг новее 2009 года, используя
//	только стандартные алгоритмы и функторы STL(подcказка : std::count_if, std::greater<>, std::bind2nd).
#include <clocale>
#include <vector>
#include "Book.h"
#include <iostream>
#include <functional>
#include <algorithm>
#include "BookSorter.h"
#include "BookFinder.h"
int main() {
	setlocale(LC_ALL, "RUSSIAN");

	std::vector<Book*> books;
	books.push_back(new Book("Война и мир", "Толстой Л.Н.", 2010));
	books.push_back(new Book("Подросток", "Достоевский Ф.М.", 2004));
	books.push_back(new Book("Обрыв", "Гончаров И.А.", 2010));
	books.push_back(new Book("Анна Каренина", "Толстой Л.Н.", 1999));
	books.push_back(new Book("Обыкновенная история", "Гончаров И.А.", 2011));
	books.push_back(new Book("Утраченные иллюзии", "Бальзак О.", 2009));
	books.push_back(new Book("Оливер Твист", "Диккенс Ч.", 2001));
	books.push_back(new Book("Фауст", "Гёте И.В.", 2010));
	books.push_back(new Book("Лилия долины", "Бальзак О.", 1998));
	
	std::cout << "\nКниги в алфавитном порядке:\n\n";
	BookSorter book_sorter;
	std::sort(books.begin(), books.end(), book_sorter);
	std::vector<Book*>::iterator i;
	
	for (i = books.begin(); i != books.end(); ++i)
	{
		std::cout << (*i)->getAuthor() << " \"" << (*i)->getName() << "\"" << std::endl;
	}
	
	BookFinder book_finder(2005, 2014);
	std::vector<Book*>::iterator finder = std::find_if(books.begin(), books.end(), book_finder);
	std::cout << "\nКниги в диапазоне года издания 2005 - 2014:\n\n";
	
	while (finder != books.end())
	{
		std::cout << (*finder)->getAuthor() << " \""<< (*finder)->getName() << "\"" << std::endl;
		finder = std::find_if(++finder, books.end(), book_finder);
	}
	
	//4 задание
	std::vector<int> yearsBooks;
	for (i = books.begin(); i != books.end(); ++i) {
		yearsBooks.push_back((*i)->getYear());
		delete (*i);
	}
	std::cout<< '\n' << std::count_if(yearsBooks.begin(), yearsBooks.end(), std::bind2nd(std::greater<int>(), 2009)) << std::endl;
}