#include "stdafx.h"
#include "Bill.h"

Bill::Bill(std::string street_name, int house_number, int block_number, int appartment_number, std::string surname, std::string date, std::string payment_type, double payment, double peni, int delay_number)
{
	this->address.street_name = street_name;
	this->address.house_number = house_number;
	this->address.block_number = block_number;
	this->address.apartment_number = appartment_number;
	this->surname = surname;
	this->date = date;
	this->payment_type = payment_type;
	this->payment = payment;
	this->peni = peni;
	this->delay_number = delay_number;
}

std::string Bill::to_string()
{
	return std::string();
}

void Bill::setStreetName(std::string street_name)
{
	if (street_name != "") {
		this->address.street_name = street_name;
	}
}

void Bill::setHouseNumber(int house_number)
{
	if (house_number != 0) {
		this->address.house_number = house_number;
	}
}

void Bill::setBlockNumber(int block_number)
{
	if (block_number != 0) {
		this->address.block_number = block_number;
	}
}

void Bill::setAppartmentNumber(int appartment_number)
{
	if (appartment_number >= 0) {
		this->address.apartment_number = appartment_number;
	}
}

void Bill::setSurname(std::string surname)
{
	if (surname != "") {
		this->surname = surname;
	}
}

void Bill::setDate(std::string date)
{
	if (date != "") {
		this->date = date;
	}
}

void Bill::setPaymentType(std::string payment_type)
{
	if (payment_type != "") {
		this->payment_type = payment_type;
	}
}

void Bill::setPayment(double payment)
{
	if (payment != 0) {
		this->payment = payment;
	}
}

void Bill::setPeni(double peni)
{
	if (peni > DBL_EPSILON) {
		this->peni = peni;
	}
}

void Bill::setDelayNumber(int delay_number)
{
	if (delay_number >= 0) {
		this->delay_number = delay_number;
	}
}
