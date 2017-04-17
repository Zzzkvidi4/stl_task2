#pragma once
#include "help_utils.h"

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date();

	Date(const Date& date);

	Date(int year, int month, int day);

	std::string to_string();

	static bool StrToDate(std::string str, Date& date);

	static int max_day_number(int year, int month);

	bool operator<(Date date);

	Date& operator=(Date date);

	bool operator==(Date date);

	void setYear(std::string buf);

	int getYear();

	void setMonth(std::string buf);

	int getMonth();

	void setDay(std::string buf);

	int getDay();

	friend std::ostream& operator<<(std::ostream& cout, Date date);

	friend std::istream& operator>>(std::istream& cin, Date& date);

	~Date();
};

