#pragma once
#include "stdafx.h"


struct Address {
	std::string street_name;
	int house_number;
	int block_number;
	int apartment_number;
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
	Bill(std::string street_name, int house_number, int block_number, int appartment_number, std::string surname, Date date, std::string payment_type, double payment, double peni, int delay_number);
	std::string to_string();
	void setStreetName(std::string street_name);
	void setHouseNumber(int house_number);
	void setBlockNumber(int block_number);
	void setAppartmentNumber(int appartment_number);
	void setSurname(std::string surname);
	void setDate(Date date);
	void setPaymentType(std::string payment_type);
	void setPayment(double payment);
	void setPeni(double peni);
	void setDelayNumber(int delay_number);
	friend std::ostream& operator<<(std::ostream& cout, Bill bill);
	friend std::istream& operator>>(std::istream& cin, Bill bill);
	static bool houseNumberComparator(Bill bill1, Bill bill2);
	static bool appartmentNumberComparator(Bill bill1, Bill bill2);
	static bool surnameComparator(Bill bill1, Bill bill2);
	static bool dateComparator(Bill bill1, Bill bill2);
};

