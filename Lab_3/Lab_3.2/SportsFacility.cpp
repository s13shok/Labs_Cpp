#include "SportsFacility.h"
#include <iostream>

void SportsFacility::setAddress(std::string address) {
	address_ = address;
}

void SportsFacility::setTypeOfCoverage(std::string type_of_coverage){
	type_of_coverage_ = type_of_coverage;
}

void SportsFacility::setCapacity(int capacity) {
	capacity_ = capacity;
}

void SportsFacility::setSeasonTickets(int season_tickets){
	season_tickets_ = season_tickets;
}

void SportsFacility::setSquare(float square){
	square_ = square;
}

void SportsFacility::setAttendance(float Attendance) {
	attendance_ = Attendance;
}

void SportsFacility::playGame(int visitors) {
	history_of_attendances_.push_back(calculateAttendance(visitors));
	float sum = 0;
	for (size_t i = 0; i < history_of_attendances_.size(); ++i)
	{
		sum += history_of_attendances_[i];
	}
	avg_attendance_ = sum / history_of_attendances_.size();
}

float SportsFacility::calculateAttendance(int visitors)const {
	return (float)visitors / capacity_ * 100;
}

std::ostream& operator<<(std::ostream& out, const SportsFacility& s) {
	out << "The sport facility is in " << s.address_ << std::endl;
	out << "Capacity: " << s.capacity_ << std::endl;
	out << "Number of available season tickets: " << s.season_tickets_ << std::endl;

	return out;
}