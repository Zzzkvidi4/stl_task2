#pragma once

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

	bool operator<(Date date);

	Date& operator=(Date date);

	bool operator==(Date date);

	~Date();
};

