#include "Multiplier.h"
#include <iostream>
#include <fstream>

Multiplier::Multiplier() : ExpressionEvaluator() { }
Multiplier::Multiplier(size_t n) : ExpressionEvaluator(n) { }

double Multiplier::calculate() const {
	double res = 1.0;
	for (size_t i = 0; i < n_; ++i)
	{
		res *= operands_[i];
	}
	return res;
}

void Multiplier::logToScreen() const {
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
				std::cout << operands_[i] << " x ";
			}
			else {
				std::cout << '(' << operands_[i] << ')' << " x ";
			}
		}
		else {
			if (operands_[i] >= 0) {
				std::cout << operands_[i] << std::endl;
			}
			else {
				std::cout << '(' << operands_[i] << ')' << std::endl;
			}
			std::cout << "-> " << Multiplier::calculate() << std::endl;
		}
	}
}

void Multiplier::logToFile(const std::string& filename) const {
	std::ofstream fout(filename + ".log", std::ios_base::app);
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
					fout << operands_[i] << " x ";
				}
				else {
					fout << '(' << operands_[i] << ')' << " x ";
				}
			}
			else {
				if (operands_[i] >= 0) {
					fout << operands_[i] << std::endl;
				}
				else {
					fout << '(' << operands_[i] << ')' << std::endl;
				}
				fout << "-> " << Multiplier::calculate() << std::endl;
			}
		}
		fout.close();
	}
}
