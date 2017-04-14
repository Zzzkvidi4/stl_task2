#pragma once
#include "stdafx.h"


struct Address {
	std::string street_name;
	int house_number;
	int block_number;
	int apartment_number;
};

class Bill
{
private:
	Address address;
	std::string surname;
	std::string date;
	std::string payment_type;
	double payment;
	double peni;
	int delay_number;
public:
	Bill(std::string street_name, int house_number, int block_number, int appartment_number, std::string surname, std::string date, std::string payment_type, double payment, double peni, int delay_number);
	std::string to_string();
	void setStreetName(std::string street_name);
	void setHouseNumber(int house_number);
	void setBlockNumber(int block_number);
	void setAppartmentNumber(int appartment_number);
	void setSurname(std::string surname);
	void setDate(std::string date);
	void setPaymentType(std::string payment_type);
	void setPayment(double payment);
	void setPeni(double peni);
	void setDelayNumber(int delay_number);
};

