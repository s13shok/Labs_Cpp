#include "Matrix.h"
#include <iomanip>
#include "Vector.h"
Matrix::Matrix(int i, int j) {
	array_ = new int* [i];
	i_ = i;
	j_ = j;
	for (size_t l = 0; l < i_; ++l)
	{
		array_[l] = new int[j_];
	}
	for (size_t i = 0; i < i_; ++i)
	{
		for (size_t j = 0; j < j_; ++j)
		{
			array_[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix& m) {
	i_ = m.i_;
	j_ = m.j_;
	array_ = new int* [i_];
	for (size_t k = 0; k < i_; ++k)
	{
		array_[k] = new int[j_];
	}
	for (size_t i = 0; i < i_; ++i)
	{
		for (size_t j = 0; j < j_; ++j)
		{
			array_[i][j] = m.array_[i][j];
		}
	}
}
Matrix::~Matrix() {
	for (size_t i = 0; i < i_; ++i)
	{
		delete[] * (array_ + i);
	}
	delete[] array_;
}
int Matrix::at(int i, int j) const {
	return array_[i][j];
}
void Matrix::setAt(int i, int j, int value) {
	array_[i][j] = value;
}

Matrix& Matrix::operator++() {
	for (size_t i = 0; i < i_; ++i)
	{
		for (size_t j = 0; j < j_; ++j)
		{
			++array_[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator--() {
	for (size_t i = 0; i < i_; ++i)
	{
		for (size_t j = 0; j < j_; ++j)
		{
			--array_[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator++(int) {
	Matrix m(*this);
	for (size_t i = 0; i < i_; ++i)
	{
		for (size_t j = 0; j < j_; ++j)
		{
			array_[i][j]++;
		}
	}
	return m;
}

Matrix Matrix::operator--(int) {
	Matrix m(*this);
	for (size_t i = 0; i < i_; ++i)
	{
		for (size_t j = 0; j < j_; ++j)
		{
			array_[i][j]++;
		}
	}
	return m;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m)
{
	for (size_t i = 0; i < m.i_; ++i)
	{
		for (size_t j = 0; j < m.j_; ++j)
		{
			out << std::setw(8) << m.array_[i][j] << ' ';
		}
		if (i != m.i_ - 1) {
			out << std::endl;
		}
	}
	return out;
}

int factorial(int x) {
	if (x < 0 || x > 12) {
		return -1;
	}
	static const int table[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600 };
	return table[x];
}

Matrix& Matrix::initializeMatrix() {
	for (size_t i = 0; i < i_; ++i)
	{
		for (size_t j = 0; j < j_; ++j)
		{
			array_[i][j] = factorial(i) + factorial(j);
		}
	}
	return *this;
}
Vector Matrix::transformMatrix() {
	Vector v = i_ / 2 * j_;
	int position = 0;
	for (size_t i = 0; i < i_; ++i)
	{
		if (i % 2 != 0) {
			for (size_t j = 0; j < j_; ++j)
			{
				v[position] = array_[i][j];
				position++;
			}
		}
	}
	return v;
}
