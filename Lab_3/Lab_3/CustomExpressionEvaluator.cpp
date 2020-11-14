#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>

CustomExpressionEvaluator::CustomExpressionEvaluator() : ExpressionEvaluator() { }
CustomExpressionEvaluator::CustomExpressionEvaluator(size_t n) : ExpressionEvaluator(n) { }

double CustomExpressionEvaluator::calculate()const {
	double result = 0.0;
	//result = x1 – x2 / 2 + x3 / 3 – x4 / 4 + ...
	for (size_t i = 0; i < n_; ++i)
	{
		int x = i + 1;
		if (x % 2 == 1) {
			result += (operands_[i] / x); //odd add
		}
		else {
			result -= (operands_[i] / x); //even subtract
		}
	}
	return result;
}

void CustomExpressionEvaluator::logToScreen()const {
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
			int x = i + 1;
			if (operands_[i] >= 0) {
				if (x % 2 == 1) {
					std::cout << operands_[i] << " - ";
				}
				else {
					std::cout << operands_[i] << " + ";
				}
			}
			else {
				if (x % 2 == 1) {
					std::cout << '(' << operands_[i] << ')' << " - ";
				}
				else {
					std::cout << '(' << operands_[i] << ')' << " + ";
				}
			}
		}
		else {
			if (operands_[i] >= 0) {
				std::cout << operands_[i] << std::endl;
			}
			else {
				std::cout << '(' << operands_[i] << ')' << std::endl;
			}
			std::cout << "-> " << CustomExpressionEvaluator::calculate() << std::endl;
		}
	}
}

void CustomExpressionEvaluator::logToFile(const std::string& filename) const {
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
				int x = i + 1;
				if (operands_[i] >= 0) {
					if (x % 2 == 1) {
						fout << operands_[i] << " - ";
					}
					else {
						fout << operands_[i] << " + ";
					}
				}
				else {
					if (x % 2 == 1) {
						fout << '(' << operands_[i] << ')' << " - ";
					}
					else {
						fout << '(' << operands_[i] << ')' << " + ";
					}
				}
			}
			else {
				if (operands_[i] >= 0) {
					fout << operands_[i] << std::endl;
				}
				else {
					fout << '(' << operands_[i] << ')' << std::endl;
				}
				fout << "-> " << CustomExpressionEvaluator::calculate() << std::endl;
			}
		}
		fout.close();
	}
}

void CustomExpressionEvaluator::shuffle() {
	for (size_t i = 0; i < n_; i++) {
		if (operands_[i] < 0 || operands_[i] < 2) {
			for (size_t j = i + 1; j < n_; j++) {
				if (operands_[j] < 0 || operands_[j] < 2) {
					if (operands_[i] < operands_[j]) {
						double tmp = operands_[i];
						operands_[i] = operands_[j];
						operands_[j] = tmp;
					}
				}
			}
		}
	}
}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j) {
	size_t i_;
	size_t j_;
	if (i < n_ && j < n_) {
		for (i_ = i + 1; i_ < j; ++i_)
		{
			double tmp = operands_[i_];
			j_ = i_ - 1;
			while (j_ >= 0 && operands_[j_] < tmp)
			{
				operands_[j_ + 1] = operands_[j_];
				j_ = j_ - 1;
			}
			operands_[j_ + 1] = tmp;
		}
	}
}
