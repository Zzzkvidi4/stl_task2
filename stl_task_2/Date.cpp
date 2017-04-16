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
		throw std::out_of_range("ћес€ц должен быть между 1 и 13!");
	}
	this->month = month;

	max_day = max_day_number(year, month);

	if ((day < 1) || (day > max_day)) {
		throw std::out_of_range("ƒень должен быть между 1 и " + std::to_string(max_day) + "!");
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

int Date::max_day_number(int year, int month) {
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {
		return 31;
	} else if (month == 2) {
		if ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0)) {
			return 29;
		} else {
			return 28;
		}
	} else {
		return 30;
	}
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

std::ostream& operator<<(std::ostream& cout, Date date) {
	cout << date.to_string();
	return cout;
}

std::istream& operator>>(std::istream& cin, Date date) {
	std::string buf;
	//std::cout << "¬ведите год:" << std::endl;
	std::getline(cin, buf);
	try {
		date.year = std::stoi(buf);
	}
	catch (std::invalid_argument e) {
		throw std::invalid_argument("√од должен быть числом!");
	}

	//std::cout << "¬ведите мес€ц:" << std::endl;
	std::getline(cin, buf);
	try {
		date.month = std::stoi(buf);
		if ((date.month < 1) || (date.month > 12)) {
			throw std::out_of_range("ћес€ц должен быть числом от 1 до 12!");
		}
	}
	catch (std::invalid_argument e) {
		throw std::invalid_argument("ћес€ц должен быть числом!");
	}

	//std::cout << "ƒень:" << std::endl;
	std::getline(cin, buf);
	try {
		date.day = std::stoi(buf);
		int max_day = Date::max_day_number(date.year, date.month);
		if ((date.day < 1) || (date.day > max_day)) {
			throw std::out_of_range("ƒень должен быть числом от 1 до " + std::to_string(max_day) + "!");
		}
	}
	catch (std::invalid_argument e) {
		throw std::invalid_argument("ƒень должен быть числом!");
	}

	return cin;
}
