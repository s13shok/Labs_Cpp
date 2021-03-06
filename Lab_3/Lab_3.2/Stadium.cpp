#include "Stadium.h"
#include <iostream>
#include <fstream>
#include <vector>

Stadium::Stadium() {
	address_ = "unknown";
	football_club_ = "unknown";
	sectors_ = 0;
	capacity_ = 0;
	attendance_ = 0.0;
	avg_attendance_ = 0.0;
	history_of_attendances_.reserve(4);
	season_tickets_ = 100;
}
Stadium::Stadium(std::string address, std::string footballClub, int sectors, int capacity, float attendance) {
	address_ = address;
	football_club_ = footballClub;
	sectors_ = sectors;
	capacity_ = capacity;
	attendance_ = attendance;
	avg_attendance_ = 0.0;
	history_of_attendances_.reserve(4);
	season_tickets_ = 100;
}

void Stadium::setFootballClub(std::string footballClub) {
	football_club_ = footballClub;
}

void Stadium::setSectors(int sectors) {
	sectors_ = sectors;
}

void Stadium::setSeasonTickets(int season_tickets) {
	season_tickets_ = season_tickets > 100 ? 100 : season_tickets;
}

void Stadium::ticket(){
	if (season_tickets_ > 0) {
		season_tickets_--;
		serialize();
		std::cout << "Issued season ticket with number: " << 100 - season_tickets_<< std::endl;
	}
	else {
		std::cout << "No more season tickets" << std::endl;
	}
}

void Stadium::serialize() const {
	serialize(football_club_);
}

void Stadium::serialize(const std::string& filename) const {
	std::ofstream fout(filename + ".txt");
	if (fout.is_open())
	{
		fout << address_ << std::endl;
		fout << football_club_ << std::endl;
		fout << sectors_ << std::endl;
		fout << capacity_ << std::endl;
		fout << attendance_ << std::endl;
		fout << avg_attendance_ << std::endl;
		fout << season_tickets_ << std::endl;
		fout.close();
	}
}

void Stadium::deserialize() {
	deserialize(football_club_);
}

void Stadium::deserialize(const std::string& filename) {
	std::ifstream fin(filename + ".txt");
	std::string line;
	if (fin.is_open())
	{
		std::getline(fin, line);
		address_ = line;
		std::getline(fin, line);
		football_club_ = line;
		std::getline(fin, line);
		sectors_ = std::stoi(line);
		std::getline(fin, line);
		capacity_ = std::stoi(line);
		std::getline(fin, line);
		attendance_ = atof(line.c_str());
		std::getline(fin, line);
		avg_attendance_ = atof(line.c_str());
		std::getline(fin, line);
		season_tickets_ = std::stoi(line);
	}
}

void Stadium::sort(Stadium* arr[], int n) {
	//insertion sort
	int i;
	Stadium* key;
	int j;
	for (i = 1; i < n; ++i)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j]->getAvgAttendance() < key->getAvgAttendance())
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


int Stadium::getCapacity() const {
	return capacity_;
}

float Stadium::getAvgAttendance() const {
	return avg_attendance_;
}

std::ostream& operator<<(std::ostream& out, const Stadium& s) {
	out << "The stadium is in " << s.address_ << std::endl;
	out << "Home club: " << s.football_club_ << std::endl;
	out << "Capacity: " << s.capacity_ << std::endl;
	out << "Number of available season tickets: " << s.season_tickets_ << std::endl;

	return out;
}
