#pragma once
#include "iostream"
class Vector
{
	int* array_;
	int length_;

	public:
	Vector(int length);
	Vector(const Vector& v);
	~Vector();

	int& operator[] (const int index)const;
	
	//prefix
	Vector& operator++(); 
	Vector& operator--(); 

	//postfix
	Vector operator++(int);
	Vector operator--(int);

	friend std::ostream& operator<< (std::ostream& out, const Vector& v);
};

