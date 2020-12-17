#pragma once
#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable
{
public:
	ExpressionEvaluator();
	ExpressionEvaluator(size_t n);
	virtual ~ExpressionEvaluator();

	virtual double calculate() const = 0;

	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
protected:
	size_t n_;
	double* operands_;
};
