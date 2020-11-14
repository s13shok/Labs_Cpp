#pragma once
#include "ExpressionEvaluator.h"

class Summator : public ExpressionEvaluator
{
public:
	Summator();
	Summator(size_t n);
	double calculate() const override;
	void logToScreen() const override;
	void logToFile(const std::string& filename) const override;
};

