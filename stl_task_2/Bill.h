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

