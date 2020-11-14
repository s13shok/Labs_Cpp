#include "Summator.h"
#include <iostream>
#include <fstream>

Summator::Summator() : ExpressionEvaluator() { }
Summator::Summator(size_t n) : ExpressionEvaluator(n) { }

double Summator::calculate() const {
	double sum = 0.0;
	for (size_t i = 0; i < n_; ++i)
	{
		sum += operands_[i];
	}
	return sum;
}

void Summator::logToScreen() const {
	for (size_t i = 0; i < n_; ++i)
	{
		if (i != n_ - 1) {
			std::cout << "Op" << i << ", ";
		}
		else {
			std::cout << "Op" << i << " : ";
		}
	}
	for (size_t i = 0; i < n_; ++i)
	{
		if (i != n_ - 1) {
			if (operands_[i] >= 0) {
				std::cout << operands_[i] << " + ";
			}
			else {
				std::cout << '(' << operands_[i] << ')' << " + ";
			}
		}
		else {
			if (operands_[i] >= 0) {
				std::cout << operands_[i] << std::endl;
			}
			else {
				std::cout << '(' << operands_[i] << ')' << std::endl;
			}
			std::cout << "-> " << Summator::calculate() << std::endl;
		}
	}
}

void Summator::logToFile(const std::string& filename) const{
	std::ofstream fout(filename+".log", std::ios_base::app);
	if (fout.is_open())
	{
		for (size_t i = 0; i < n_; ++i)
		{
			if (i != n_ - 1) {
				fout << "Op" << i << ", ";
			}
			else {
				fout << "Op" << i << " : ";
			}
		}
		for (size_t i = 0; i < n_; ++i)
		{
			if (i != n_ - 1) {
				if (operands_[i] >= 0) {
					fout << operands_[i] << " + ";
				}
				else {
					fout << '(' << operands_[i] << ')' << " + ";
				}
			}
			else {
				if (operands_[i] >= 0) {
					fout << operands_[i] << std::endl;
				}
				else {
					fout << '(' << operands_[i] << ')' << std::endl;
				}
				fout << "-> " << Summator::calculate() << std::endl;
			}
		}
		fout.close();
	}
}
