#include "stdafx.h"
#include "Date.h"


Date::Date() {
	year = 1;
	month = 1;
	day = 1;
}

Date::Date(const Date & date) {
	year = date.year;
	month = date.month;
	day = date.day;
}

Date::Date(int year, int month, int day) {
	int max_day;
	this->year = year;
	if ((month < 1) || (month > 12)) {
		throw std::invalid_argument("ћес€ц должен быть между 1 и 13!");
	}
	this->month = month;
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {
		max_day = 31;
	} else if (month == 2) {
		if ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0)) {
			max_day = 29;
		} else {
			max_day = 28;
		}
	} else {
		max_day = 30;
	}

	if ((day < 1) || (day > max_day)) {
		throw std::invalid_argument("ƒень должен быть между 1 и " + std::to_string(max_day) + "!");
	}
	this->day = day;
}

std::string Date::to_string() {
	return std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
}

bool Date::StrToDate(std::string str, Date & date) {
	int position = str.find('/');
	if (position == std::string::npos) {
		return false;
	}
	std::string buf = str.substr(0, position);
	try {
		date.day = std::stoi(buf);
	}
	catch (std::exception e) {
		return false;
	}
	str = str.substr(position + 1);

	position = str.find('/');
	if (position == std::string::npos) {
		return false;
	}
	buf = str.substr(0, position);
	try {
		date.month = std::stoi(buf);
	}
	catch (std::exception e) {
		return false;
	}
	str = str.substr(position + 1);
	try {
		date.year = std::stoi(str);
	}
	catch (std::exception e) {
		return false;
	}
	return true;
}

bool Date::operator<(Date date) {
	if (year != date.year) {
		return year < date.year;
	} else {
		if (month != date.month) {
			return month < date.month;
		} else {
			return day < date.day;
		}
	}
}

Date & Date::operator=(Date date) {
	year = date.year;
	month = date.month;
	day = date.day;
	return *this;
}

bool Date::operator==(Date date) {
	return (year == date.year) && (month == date.month) && (day == date.day);
}

Date::~Date() {
}
