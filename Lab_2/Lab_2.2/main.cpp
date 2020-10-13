//  Написать класс Fraction для представления обыкновенных дробей (как отношения
//	двух целых чисел x / y). 
//    +  Перегрузить операторы + , -, *, / для дробей. 
//    +  Реализовать метод void reduce() для сокращения дроби, 
//  а также статические методы :
//    +  int gcd(int n, int m)
//      функция для нахождения наибольшего общего делителя чисел n и m;
//    +  void printAsFraction(double decimal_fraction)
//    +  void printAsFraction(char* decimal_fraction)
//      перегруженные методы вывода десятичной дроби в виде обыкновенной
//      (например, при значении decimal_fraction = 0.43 на экране должно
//	     вывестись 43 / 100, при 0.25 – 1 / 4 и т.д.).
//	Также реализовать в виде статического члена класса счетчик всех созданных на
//	данный момент в программе экземпляров дробей.
//	Продемонстрировать работу созданного класса.Создать несколько объектов дробей.
//	Произвести операции сложения, вычитания, умножения и деления дробей. Вывести
//	на экран результаты. Показать также результаты работы статических методов класса.

#include "Fraction.h"
#include <iostream>
int main() {
	Fraction a(1, 4);
	Fraction b(1, 5);
	Fraction c(1, 9);
	Fraction d(100, 110);
	std::cout << Fraction::count_ << std::endl;

	std::cout << d << std::endl;
	d.reduce();
	std::cout << d << std::endl;

	std::cout << d * a << std::endl;
	std::cout << d / c << std::endl;
	std::cout << d + b << std::endl;
	std::cout << d - a << std::endl;

	char num[] = "3.45";
	Fraction::printAsFraction(num);
	std::cout << std::endl;
	Fraction::printAsFraction(3.85);
	std::cout << std::endl;

	std::cout << Fraction::gcd(190, 80) << std::endl; //10
	std::cout << Fraction::lcm(190, 80) << std::endl; //1520
	return 0;

}