//  �������� ����������� �����, � ������������ � ���������.������������������ � ����
//  ������������ ������, ���������� ������������� ��� ���������� � � �����������
//  ��� ������������� ������.����� ������ ��������� ����� serialize() ���
//  ���������� ������ ������ � ���� � ����� deserialize() ��� ������ ������ ������
//  �� ����� �� ��������� � ������� ����������, � ����� ������������� ������
//  serialize(const std::string& filename) � deserialize(const std::string&
//	filename) ��� ������ � ������ � ��������� � ��������� ������.
//
//	����������.�� ������ ������� �������������� �������� �������� � ������ ������,
//	�� ��������� ���� � �������, �� ���������� ������ ������������ ������.
//                             ������ �7
//                           ����� �������.
//  ������: �����, ���������� ����, ���������� ��������, �����������, ������������.
//  ������� 2 �������� � ���� � ���� � �����.���������� ������ ������ ���� � �������
//  ��������, ������ �������� ���������� � ������������ � �����������.� �������
//  ������� �������������� ������ ����� � ��������� ������� ������������
//  ���������� ��������� ����������� � ���������� ������� ���������� �������
//  ��������.������� ���������� � ���������, ������������ �� � ������� ��������
//  �������� �������� ���������� �� ������ �����.
#include "Stadium.h"
#include <iostream>

int main() {
	Stadium s1;
	s1.setAddress("Kiev");
	s1.setFootballClub("Dynamo");
	s1.setSectors(29);
	s1.setCapacity(16873);
	s1.setAttendance(90.0);
	Stadium s2;
	s2.setAddress("Moscow");
	s2.setFootballClub("Spartak");
	s2.setSectors(10);
	s2.setCapacity(45360);
	s2.setAttendance(81.0);
	Stadium* s3 = new Stadium("Donetsk", "Shakhtar", 0, 52667, 75.0);
	
	//Stadium s1;
	//Stadium s2;
	//Stadium* s3 = new Stadium();

	//s1.setFootballClub("Dynamo");
	//s1.deserialize();
	//s2.setFootballClub("Spartak");
	//s2.deserialize();
	//s3->setFootballClub("Shakhtar");
	//s3->deserialize();

	Stadium* stadiums[3] = { &s1, &s2, s3 };

	srand(7);
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			stadiums[i]->playGame(rand() % (stadiums[i])->getCapacity() + 1);
		}
	}

	Stadium::sort(stadiums, 3);

	for (size_t i = 0; i < 3; ++i)
	{
		std::cout << *(stadiums[i]) << std::endl;
	}
	return 0;
}