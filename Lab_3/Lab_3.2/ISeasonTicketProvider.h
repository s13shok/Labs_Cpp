#pragma once
#include <string>

class ISeasonTicketProvider
{
public:
	virtual ~ISeasonTicketProvider() {}
	virtual void ticket() = 0;
};