#pragma once
#include <string>
#include <vector>
class Stadium
{
	std::string address_;
	std::string football_club_;
	int sectors_;
	int capacity_;
	float attendance_;
	float avg_attendance_;
	std::vector <float> history_of_attendances_;
public:
	Stadium();
	Stadium(std::string address, std::string footballClub, int sectors, int capacity, float attendance);

	void setAddress(std::string address);
	void setFootballClub(std::string footballClub);
	void setSectors(int sectors);
	void setCapacity(int capacity);
	void setAttendance(float attendance);

	void playGame(int visitors);
	float calculateAttendance(int visitors)const;

	void serialize() const;
	void serialize(const std::string& filename) const;
	void deserialize();
	void deserialize(const std::string& filename);

	friend std::ostream& operator<< (std::ostream& out, const Stadium& s);

	int getCapacity()const;
	float getAvgAttendance()const;

};

