#pragma once
#include <string>
#include <vector>

class SportsFacility
{
	//адрес, футбольный клуб, количество секторов, вместимость, посещаемость, площадь,
	//тип покрытия, количество абонементов
protected:
	std::string address_;
	std::string type_of_coverage_;
	int capacity_;
	int season_tickets_;
	float square_;
	float attendance_;
	float avg_attendance_;
	std::vector <float> history_of_attendances_;

public:
	virtual ~SportsFacility(){}
	void setAddress(std::string address);
	void setTypeOfCoverage(std::string type_of_coverage);
	void setCapacity(int capacity);
	virtual void setSeasonTickets(int season_tickets);
	void setSquare(float square);
	void setAttendance(float Attendance);

	void playGame(int visitors);
	float calculateAttendance(int visitors) const;
	friend std::ostream& operator<<(std::ostream& out, const SportsFacility& s);
};
