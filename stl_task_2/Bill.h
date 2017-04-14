#pragma once
#include "stdafx.h"


struct Address {
	std::string street_name;
	int house_number;
	int block_number;
	int apartment_number;

	std::string to_string() {
		return street_name + '|' + std::to_string(house_number) + '|' + std::to_string(block_number) + '|' + std::to_string(apartment_number);
	}

	static bool StrToAddress(std::string str, Address& adr) {
		int position = str.find('|');
		if (position == std::string::npos) {
			return false;
		}
		adr.street_name = str.substr(0, position);
		str = str.substr(position + 1);

		position = str.find('|');
		if (position == std::string::npos) {
			return false;
		}
		std::string buf = str.substr(0, position);
		try {
			adr.house_number = std::stoi(buf);
		}
		catch (std::exception e) {
			return false;
		}
		str = str.substr(position + 1);

		position = str.find('|');
		if (position == std::string::npos) {
			return false;
		}
		buf = str.substr(0, position);
		try {
			adr.block_number = std::stoi(buf);
		}
		catch (std::exception e) {
			return false;
		}
		str = str.substr(position + 1);

		try {
			adr.apartment_number = std::stoi(buf);
		}
		catch (std::exception e) {
			return false;
		}
		return true;
	}
};

struct Date {
	int year;
	int month;
	int day;

	Date() {
		year = 1;
		month = 1;
		day = 1;
	}

	Date(const Date& date) {
		year = date.year;
		month = date.month;
		day = date.day;
	}

	Date(int year, int month, int day) {
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
			}
			else {
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

	std::string to_string() {
		return std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
	}

	static bool StrToDate(std::string str, Date& date) {
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

	bool operator<(Date date) {
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

	Date& operator=(Date date) {
		year = date.year;
		month = date.month;
		day = date.day;
		return *this;
	}

	bool operator==(Date date) {
		return (year == date.year) && (month == date.month) && (day == date.day);
	}
};

class Bill
{
private:
	Address address;
	std::string surname;
	Date date;
	std::string payment_type;
	double payment;
	double peni;
	int delay_number;
public:
	Bill();
	Bill(std::string street_name, int house_number, int block_number, int appartment_number, std::string surname, Date date, std::string payment_type, double payment, double peni, int delay_number);
	std::string to_string();
	bool StrToBill(std::string str, Bill& bill);
	void setStreetName(std::string street_name);
	void setHouseNumber(int house_number);
	int getHouseNumber();
	void setBlockNumber(int block_number);
	void setApartmentNumber(int appartment_number);
	int getApartmentNumber();
	void setSurname(std::string surname);
	std::string getSurname();
	void setDate(Date date);
	Date getDate();
	void setPaymentType(std::string payment_type);
	void setPayment(double payment);
	void setPeni(double peni);
	void setDelayNumber(int delay_number);
	double countPeni();
	friend std::ostream& operator<<(std::ostream& cout, Bill bill);
	friend std::istream& operator>>(std::istream& cin, Bill bill);
	static bool houseNumberComparator(Bill bill1, Bill bill2);
	static bool appartmentNumberComparator(Bill bill1, Bill bill2);
	static bool surnameComparator(Bill bill1, Bill bill2);
	static bool dateComparator(Bill bill1, Bill bill2);
	static bool peniComparator(Bill bill1, Bill bill2);
};

