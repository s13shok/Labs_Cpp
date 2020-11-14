#pragma once
#include "ExpressionEvaluator.h"

class Multiplier : public ExpressionEvaluator
{
public:
	Multiplier();
	Multiplier(size_t n);
	double calculate() const override;
	void logToScreen() const override;
	void logToFile(const std::string& filename) const override;
};

