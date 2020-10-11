#include "Vector.h"
	Vector::Vector(int length) {
		length_ = length;
		array_ = new int[length];

		for (size_t i = 0; i < length; ++i)
		{
			array_[i] = 0;
		}
	}
	Vector::Vector(const Vector& v)
	{
		length_ = v.length_;
		array_ = new int[length_];
		for (std::size_t i = 0; i < length_; ++i)
		{
			array_[i] = v.array_[i];
		}
	}
	Vector::~Vector() {
		delete[] array_;
	}

	int& Vector::operator[] (const int index)const
	{
		return array_[index];
	}

	Vector& Vector::operator++() {
		for (size_t i = 0; i < length_; ++i)
		{
			++array_[i];
		}
		return *this;
	}
	Vector& Vector::operator--() {
		for (size_t i = 0; i < length_; ++i)
		{
			--array_[i];
		}
		return *this;
	}

	Vector Vector::operator++(int) {
		Vector v(*this);
		for (size_t i = 0; i < length_; ++i)
		{
			array_[i]++;
		}
		return v;
	}
	Vector Vector::operator--(int) {
		Vector v(*this);
		for (size_t i = 0; i < length_; ++i)
		{
			array_[i]--;
		}
		return v;
	}

	std::ostream& operator<<(std::ostream& out, const Vector& v) {
		for (size_t i = 0; i < v.length_; ++i)
		{
			out << v[i] << ' ';
		}

		return out;
	}

