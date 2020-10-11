#pragma once
#include "iostream"
#include "Vector.h"
class Matrix
{
	int** array_;
	int i_;
	int j_;
public:
	Matrix(int i, int j);
	Matrix(const Matrix& m);
	~Matrix();

	int at(int i, int j) const;
	void setAt(int i, int j, int value);

	//prefix
	Matrix& operator++();
	Matrix& operator--();

	//postfix
	Matrix operator++(int);
	Matrix operator--(int);

	Matrix& initializeMatrix();

	Vector transformMatrix();

	friend std::ostream& operator<< (std::ostream& out, const Matrix& v);
};

