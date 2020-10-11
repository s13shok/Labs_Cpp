#pragma once
#include "iostream"
class Fraction
{
	int x_;
	int y_;
public:
	Fraction(int x, int y);
	Fraction operator+ (const Fraction& f)const;
	Fraction operator- (const Fraction& f)const;
	Fraction operator* (const Fraction& f)const;
	Fraction operator/ (const Fraction& f)const;
	friend std::ostream& operator<< (std::ostream& out, const Fraction& f);
	void reduce();

	static int count_;
	static int gcd(int n, int m);
	static int lcm(int n, int m);
	static void printAsFraction(double decimal_fraction);
	static void printAsFraction(char* decimal_fraction);
};

