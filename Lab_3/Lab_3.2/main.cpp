//  Написать собственный класс, в соответствии с вариантом.Продемонстрировать в коде
//  инкапсуляцию данных, применение конструкторов без параметров и с параметрами
//  для инициализации данных.Класс должен содержать метод serialize() для
//  сохранения данных класса в файл и метод deserialize() для чтения данных класса
//  из файла по умолчанию в текущей директории, а также перегруженные методы
//  serialize(const std::string& filename) и deserialize(const std::string&
//	filename) для работы с файлом с указанным в параметре именем.
//
//	Примечание.Вы можете вводить дополнительные закрытые свойства и метода класса,
//	не указанные явно в задании, но помогающие решить поставленные задачи.
//                             Варинт №7
//                           Класс СТАДИОН.
//  Данные: адрес, футбольный клуб, количество секторов, вместимость, посещаемость.
//  Создать 2 стадиона в куче и один в стеке.Установить данные первых двух с помощью
//  сеттеров, данные третьего установить в конструкторе с параметрами.В главной
//  функции проимитировать четыре матча – случайным образом сформировать
//  количество пришедших посетителей и просчитать процент заполнения каждого
//  стадиона.Вывести информацию о стадионах, отсортировав их в порядке убывания
//  среднего процента заполнения за четыре матча.
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