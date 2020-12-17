#define _CRT_SECURE_NO_WARNINGS
#include "Court.h"
#include <iostream>
#include <ctime>

Court::Court() {
	address_ = "unknown";
	capacity_ = 0;
	attendance_ = 0.0;
	avg_attendance_ = 0.0;
	history_of_attendances_.reserve(4);
	season_tickets_ = 15;
}
Court::Court(std::string address, int capacity, float attendance, std::string type_of_coverage) {
	address_ = address;
	capacity_ = capacity;
	attendance_ = attendance;
	type_of_coverage_ = type_of_coverage;
	avg_attendance_ = 0.0;
	history_of_attendances_.reserve(4);
	season_tickets_ = 15;
}

void Court::setSeasonTickets(int season_tickets){
	season_tickets_ = season_tickets > 15 ? 15 : season_tickets;
}

void Court::ticket(){
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int currentMonth = 1 + ltm->tm_mon;
	if (currentMonth > 5 && currentMonth < 9) {
		if (season_tickets_ > 0) {
			season_tickets_--;
			std::cout << "Issued season ticket with number: " << 16 - season_tickets_ << std::endl;
		}
		else {
			std::cout << "No more season tickets" << std::endl;
		}
	}
	else {
		std::cout << "Now is not the time to buy season tickets" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Court& s) {
	out << "The stadium is in " << s.address_ << std::endl;
	out << "Capacity: " << s.capacity_ << std::endl;
	out << "Number of available season tickets: " << s.season_tickets_ << std::endl;

	return out;
}

