#pragma once
#include "SportsFacility.h"
#include "ISeasonTicketProvider.h"

class Court : public SportsFacility, public ISeasonTicketProvider
{
public:
	Court();
	Court(std::string address, int capacity, float attendance, std::string type_of_coverage);

	void setSeasonTickets(int season_tickets) override;
	void ticket() override;

	friend std::ostream& operator<< (std::ostream& out, const Court& s);
};

