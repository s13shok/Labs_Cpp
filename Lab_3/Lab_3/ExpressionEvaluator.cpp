#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator() {
	n_ = 20;
	operands_ = new double[n_];
	for (size_t i = 0; i < n_; ++i)
	{
		operands_[i] = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(size_t n) {
	n_ = n;
	operands_ = new double[n_];
	for (size_t i = 0; i < n_; ++i)
	{
		operands_[i] = 0;
	}
}

ExpressionEvaluator::~ExpressionEvaluator() {
	delete[] operands_;
}

void ExpressionEvaluator::setOperand(size_t pos, double value) {
	if (pos < n_) {
		operands_[pos] = value;
	}
}

void ExpressionEvaluator::setOperands(double ops[], size_t n) {
	for (size_t i = 0; i < n; ++i)
	{
		operands_[i] = ops[i];
	}
}
