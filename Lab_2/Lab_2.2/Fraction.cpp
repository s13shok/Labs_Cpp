#include "Fraction.h"
#include <iostream>
#include <string>
int Fraction::count_ = 0;

Fraction::Fraction(int x, int y) {
	x_ = x;
	y_ = y;
	count_++;
}
int Fraction::gcd(int n, int m) {
	if (m == 0)
	{
		return n;
	}
	else
	{
		return gcd(m, n % m);
	}
}

int Fraction::lcm(int n, int m) {
	return (n * m) / Fraction::gcd(n, m);
}
Fraction Fraction::operator+(const Fraction& f)const {
	int coef = Fraction::lcm(y_, f.y_);

	int coef1 = coef / y_;
	int coef2 = coef / f.y_;

	Fraction f1 = *this * Fraction(coef1, 1);
	Fraction f2 = f * Fraction(coef2, 1);

	Fraction newF(f1.x_ + f2.x_, coef);
	return newF;
}

Fraction Fraction::operator-(const Fraction& f)const {
	int coef = Fraction::lcm(y_, f.y_);

	int coef1 = coef / y_;
	int coef2 = coef / f.y_;

	Fraction f1 = *this * Fraction(coef1, 1);
	Fraction f2 = f * Fraction(coef2, 1);

	Fraction newF(f1.x_ - f2.x_, coef);
	return newF;
}

Fraction Fraction::operator*(const Fraction& f)const {
	return Fraction(x_ * f.x_, y_ * f.y_);
}

Fraction Fraction::operator/(const Fraction& f)const {
	return Fraction(x_ * f.y_, y_ * f.x_);
}

void Fraction::reduce() {
	int gcd = Fraction::gcd(x_, y_);
	x_ /= gcd;
	y_ /= gcd;
}


void Fraction::printAsFraction(double decimal_fraction) {
	//Получаем целую часть
	int int_ = (int)decimal_fraction;
	//Получаем дробную часть
	double fraction = decimal_fraction - int_;
	int x = 0;
	int y = 1;
	if (fraction > 0) {
		//Смещаем запятую на 9 позиций
		long long magic_const = 1000000000;
		fraction *= magic_const;
		int int_frac = (int)fraction % magic_const;
		int cnt = 0;
		//Убираем лишние нули
		while (int_frac % 10 == 0) {
			cnt++;
			int_frac /= 10;
		}

		x = int_frac;
		//Получаем знаменатель
		for (; cnt < 9; ++cnt) {
			y *= 10;
		}
	}
	x = int_ * y + x;

	Fraction f(x, y);
	f.reduce();
	std::cout << f.x_ << "/" << f.y_;
}

void Fraction::printAsFraction(char* decimal_fraction) {

	Fraction::printAsFraction(atof(decimal_fraction));

}
std::ostream& operator<<(std::ostream& out, const Fraction& f) {
	out << f.x_ << '/' << f.y_;
	return out;
}
