#pragma once
#include <string>

class ILoggable
{
public:
	virtual ~ILoggable() {}
	virtual void logToScreen() const = 0;
	virtual void logToFile(const std::string& filename) const = 0;
};