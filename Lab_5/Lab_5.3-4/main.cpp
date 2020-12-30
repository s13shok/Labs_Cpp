//		������� ����� ����� Book, � ������� �������� ��������, ����� � ��� ������� �����.
//	� ������� ������� ������� ��������� ����(���������� �). ������������������
//	���������� ���� �� ������(��������� ����) � ��������(��������� ����).
//	������������������ ����� � ��������� : ����� ��� �����, ��� ������� �������
//	��������� � ��������� ���������. ������������ ��������� std::vector � ��������.
//		���������� � ������� �� ������� ���������� ���� ���� ����� 2009 ����, ���������
//	������ ����������� ��������� � �������� STL(���c����� : std::count_if, std::greater<>, std::bind2nd).
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
	books.push_back(new Book("����� � ���", "������� �.�.", 2010));
	books.push_back(new Book("���������", "����������� �.�.", 2004));
	books.push_back(new Book("�����", "�������� �.�.", 2010));
	books.push_back(new Book("���� ��������", "������� �.�.", 1999));
	books.push_back(new Book("������������ �������", "�������� �.�.", 2011));
	books.push_back(new Book("���������� �������", "������� �.", 2009));
	books.push_back(new Book("������ �����", "������� �.", 2001));
	books.push_back(new Book("�����", "ø�� �.�.", 2010));
	books.push_back(new Book("����� ������", "������� �.", 1998));
	
	std::cout << "\n����� � ���������� �������:\n\n";
	BookSorter book_sorter;
	std::sort(books.begin(), books.end(), book_sorter);
	std::vector<Book*>::iterator i;
	
	for (i = books.begin(); i != books.end(); ++i)
	{
		std::cout << (*i)->getAuthor() << " \"" << (*i)->getName() << "\"" << std::endl;
	}
	
	BookFinder book_finder(2005, 2014);
	std::vector<Book*>::iterator finder = std::find_if(books.begin(), books.end(), book_finder);
	std::cout << "\n����� � ��������� ���� ������� 2005 - 2014:\n\n";
	
	while (finder != books.end())
	{
		std::cout << (*finder)->getAuthor() << " \""<< (*finder)->getName() << "\"" << std::endl;
		finder = std::find_if(++finder, books.end(), book_finder);
	}
	
	//4 �������
	std::vector<int> yearsBooks;
	for (i = books.begin(); i != books.end(); ++i) {
		yearsBooks.push_back((*i)->getYear());
		delete (*i);
	}
	std::cout<< '\n' << std::count_if(yearsBooks.begin(), yearsBooks.end(), std::bind2nd(std::greater<int>(), 2009)) << std::endl;
}