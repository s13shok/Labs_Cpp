//	�������� ��������� ����� ���� ������ Cache<T> � ������� ���������� �������� �
//	��� put(T elem) � ��� �������� � ���������� +=, � ����� ������� �������� �������
//	�������� � ���� bool contains(T elem).�������� ����� ������������� �������
//	��� ���� std::string � ������ �������� : ����� contains() ������ ���������� true
//	�� ���������� ������� ������� ������; ����� add() ������ ������������
//	����������, ���� � ���� ��� ���� 100 �����.� ������� ������� ��������������
//	Cache � ������ int � std::string, �������� � ������ ��������� ��������� �
//	������������������ ��� ������� ������ ������ contains()

#include "Cache.h"
#include <string>
#include <iostream>

int main() {
	Cache<int> cache;
	cache.put(1); // ��� ������ ��������
	cache.put(2);
	cache.put(3);
	cache += 5; // ��� ���� ������ ��������

	Cache<std::string> vocabulary;
	vocabulary.put("OK");

	std::cout << vocabulary.contains("Only") << std::endl; // 1
	std::cout << cache.contains(5) << std::endl; // 1
	return 0;
}