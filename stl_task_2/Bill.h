#pragma once
#include "stdafx.h"
#include "Date.h"
#include "help_utils.h"


struct Address {
	std::string street_name;
	int house_number;
	int block_number;
	int apartment_number;

	std::string to_string() {
		return street_name + '|' + std::to_string(house_number) + '|' + std::to_string(block_number) + '|' + std::to_string(apartment_number);
	}

	Address() {
		street_name = "";
		house_number = 0;
		block_number = 0;
		apartment_number = 0;
	}

	Address(std::string str) {
		if (!StrToAddress(str, *this)) {
			throw std::invalid_argument("Ќевозможно преобразовать строку к адресу!");
		}
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

	friend std::ofstream& operator<<(std::ofstream& fout, Address adr) {
		fout << adr.to_string();
		return fout;
	}

	friend std::ostream& operator<<(std::ostream& cout, Address adr) {
		std::string block_str = (adr.block_number == 0) ? "" : ", стр. " + std::to_string(adr.block_number);
		std::string apartment_str = (adr.apartment_number == 0) ? "" : ", кв. " + std::to_string(adr.apartment_number);
		cout << adr.street_name << ", д. " << std::to_string(adr.house_number) << block_str << apartment_str;
		return cout;
	}

	friend std::istream& operator>>(std::istream& cin, Address adr) {
		std::string buf;
		std::cout << "¬ведите навзание улицы:" << std::endl;
		std::getline(cin, buf);
		if (buf == "") {
			throw std::invalid_argument("Ќазвание улицы не может быть пустой строкой!");
		}
		adr.street_name = buf;

		std::cout << "¬ведите номер дома:" << std::endl;
		std::getline(cin, buf);
		try {
			adr.house_number = std::stoi(buf);
			if (adr.house_number < 1) {
				throw std::out_of_range("Ќомер дома должен быть больше нул€!");
			}
		}
		catch (std::invalid_argument e) {
			throw std::invalid_argument("Ќомер дома должен быть числом!");
		}

		std::cout << "¬ведите номер строени€(пуста€ строка дл€ пропуска):" << std::endl;
		std::getline(cin, buf);
		if (buf == "") {
			adr.block_number = 0;
		} else {
			try {
				adr.block_number = std::stoi(buf);
				if (adr.block_number < 0) {
					throw std::out_of_range("Ќомер строени€ должен быть больше нул€!");
				}
			}
			catch (std::invalid_argument e) {
				throw std::invalid_argument("Ќомер строени€ должен быть числом!");
			}
		}

		std::cout << "¬ведите номер квартиры(пуста€ строка дл€ пропуска):" << std::endl;
		std::getline(cin, buf);
		if (buf == "") {
			adr.block_number = 0;
		} else {
			try {
				adr.block_number = std::stoi(buf);
				if (adr.block_number < 0) {
					throw std::out_of_range("Ќомер квартиры должен быть больше нул€!");
				}
			}
			catch (std::invalid_argument e) {
				throw std::invalid_argument("Ќомер строени€ должен быть числом!");
			}
		}

		return cin;
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
	friend std::ofstream& operator<<(std::ofstream& fout, Bill bill);
	friend std::ostream& operator<<(std::ostream& cout, Bill bill);
	friend std::istream& operator>>(std::istream& cin, Bill bill);
	static bool houseNumberComparator(Bill bill1, Bill bill2);
	static bool appartmentNumberComparator(Bill bill1, Bill bill2);
	static bool surnameComparator(Bill bill1, Bill bill2);
	static bool dateComparator(Bill bill1, Bill bill2);
	static bool peniComparator(Bill bill1, Bill bill2);
};

