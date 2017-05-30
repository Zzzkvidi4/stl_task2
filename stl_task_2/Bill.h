#pragma once
#include "stdafx.h"
#include "Date.h"
#include "help_utils.h"
#include "decimal.h"


struct Address {
private:
	std::string street_name;
	int house_number;
	int block_number;
	int apartment_number;

public:
	std::string getStreetName() {
		return street_name;
	}

	void setStreetName(std::string buf) {
		if (buf == "") {
			throw std::invalid_argument("Ќазвание улицы не может быть пустой строкой!");
		}
		street_name = buf;
	}

	int getHouseNumber() {
		return house_number;
	}

	void setHouseNumber(std::string buf) {
		try {
			if (!checkInt(buf)) {
				throw std::invalid_argument("");
			}
			house_number = std::stoi(buf);
			if (house_number < 1) {
				throw std::out_of_range("Ќомер дома должен быть больше нул€!");
			}
		}
		catch (std::invalid_argument e) {
			throw std::invalid_argument("Ќомер дома должен быть числом!");
		}
	}

	void setHouseNumber(int num) {
		if (num < 1) {
			throw std::out_of_range("Ќомер дома должен быть больше нул€!");
		}
		house_number = num;
	}

	int getBlockNumber() {
		return block_number;
	}

	void setBlockNumber(std::string buf) {
		if (buf == "") {
			block_number = 0;
		} else {
			try {
				if (!checkInt(buf)) {
					throw std::invalid_argument("");
				}
				block_number = std::stoi(buf);
				if (block_number < 0) {
					throw std::out_of_range("Ќомер строени€ должен быть больше нул€!");
				}
			}
			catch (std::invalid_argument e) {
				throw std::invalid_argument("Ќомер строени€ должен быть числом!");
			}
		}
	}

	int getApartmentNumber() {
		return apartment_number;
	}

	void setApartmentNumber(std::string buf) {
		if (buf == "") {
			apartment_number = 0;
		} else {
			try {
				if (!checkInt(buf)) {
					throw std::invalid_argument("");
				}
				apartment_number = std::stoi(buf);
				if (apartment_number < 0) {
					throw std::out_of_range("Ќомер квартиры должен быть больше нул€!");
				}
			}
			catch (std::invalid_argument e) {
				throw std::invalid_argument("Ќомер строени€ должен быть числом!");
			}
		}
	}

	void setApartmentNumber(int num) {
		if (num < 0) {
			throw std::out_of_range("Ќомер квартиры должен быть больше нул€!");
		}
		apartment_number = num;
	}

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
		size_t position = str.find(',');
		adr.setStreetName(str.substr(0, position));
		str = str.substr(position + 5); //' д. '
		std::string buf = str.substr(0, str.find(','));
		try {
			adr.setHouseNumber(buf);
		}
		catch (std::exception e) {
			return false;
		}
		
		position = str.find(", стр. ");
		if (position == std::string::npos) {
			adr.block_number = 0;
		} else {
			str = str.substr(position + 7);
			buf = str.substr(0, str.find(','));
			try {
				adr.setBlockNumber(buf);
			}
			catch (std::exception e) {
				return false;
			}
		}

		position = str.find(", кв. ");
		if (position == std::string::npos) {
			adr.block_number = 0;
		} else {
			str = str.substr(position + 6);
			buf = str.substr(0, str.find(','));
			try {
				adr.setApartmentNumber(buf);
			}
			catch (std::exception e) {
				return false;
			}
		}
		return true;
	}

	friend std::ostream& operator<<(std::ostream& cout, Address adr) {
		std::string block_str = (adr.block_number == 0) ? "" : ", стр. " + std::to_string(adr.block_number);
		std::string apartment_str = (adr.apartment_number == 0) ? "" : ", кв. " + std::to_string(adr.apartment_number);
		cout << adr.street_name << ", д. " << std::to_string(adr.house_number) << block_str << apartment_str;
		return cout;
	}
};

class Bill
{
private:
	Address address;
	std::string surname;
	Date date;
	std::string payment_type;
	dec::decimal<2> payment;
	dec::decimal<2> peni;
	int delay_number;
	bool hasPeni;
public:
	Bill();
	Bill(std::string str);
	std::string to_string();
	bool StrToBill(std::string str, Bill& bill);
	void setAddress(Address adr);
	void setStreetName(std::string street_name);
	std::string getStreetName();
	void setHouseNumber(std::string house_number);
	void setHouseNumber(int num);
	int getHouseNumber();
	void setBlockNumber(std::string block_number);
	int getBlockNumber();
	void setApartmentNumber(std::string appartment_number);
	void setApartmentNumber(int num);
	int getApartmentNumber();
	void setSurname(std::string surname);
	std::string getSurname();
	void setDate(Date date);
	Date& getDate();
	void setPaymentType(std::string payment_type);
	std::string getPaymentType();
	void setPayment(double payment);
	void setPayment(std::string str);
	dec::decimal<2> getPayment();
	void setPeni(double peni);
	void setPeni(std::string str);
	dec::decimal<2> getPeni();
	void setDelayNumber(int delay_number);
	void setDelayNumber(std::string str);
	int getDelayNumber();
	void setHasPeni(bool val);
	dec::decimal<2> countPeni();
	friend std::ostream& operator<<(std::ostream& cout, Bill bill);
	friend std::istream& operator>>(std::istream& cin, Bill& bill);
	static bool houseNumberComparator(Bill bill1, Bill bill2);
	static bool appartmentNumberComparator(Bill bill1, Bill bill2);
	static bool surnameComparator(Bill bill1, Bill bill2);
	static bool dateComparator(Bill bill1, Bill bill2);
	static bool peniComparator(Bill bill1, Bill bill2);
	bool operator==(Bill bill);
};

