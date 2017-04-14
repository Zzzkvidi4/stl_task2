#include "stdafx.h"
#include "Bill.h"

Bill::Bill() {
	address.street_name = "";
	address.house_number = 0;
	address.block_number = 0;
	address.apartment_number = 0;
	date = Date();
	surname = "";
	payment_type = "";
	peni = 0.0;
	payment = 0.0;
	delay_number = 0;
}

Bill::Bill(std::string street_name, int house_number, int block_number, int appartment_number, std::string surname, Date date, std::string payment_type, double payment, double peni, int delay_number)
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
	return address.to_string() + '`' + surname + '`' + date.to_string() + '`' + payment_type + '`' + 
			std::to_string(payment) + '`' + std::to_string(peni) + '`' + std::to_string(delay_number);
}

bool Bill::StrToBill(std::string str, Bill& bill) {
	bool res = true;
	int position = str.find('`');
	if (position == std::string::npos) {
		return false;
	}
	std::string buf = str.substr(0, position);
	res = Address::StrToAddress(buf, bill.address);
	if (!res) {
		return false;
	}
	str = str.substr(position + 1);

	position = str.find('`');
	if (position == std::string::npos) {
		return false;
	}
	bill.surname = str.substr(0, position);
	str = str.substr(position + 1);

	position = str.find('`');
	if (position == std::string::npos) {
		return false;
	}
	buf = str.substr(0, position);
	res = Date::StrToDate(buf, bill.date);
	if (!res) {
		return false;
	}
	str = str.substr(position + 1);

	position = str.find('`');
	if (position == std::string::npos) {
		return false;
	}
	bill.payment_type = str.substr(0, position);
	str = str.substr(position + 1);

	position = str.find('`');
	if (position == std::string::npos) {
		return false;
	}
	buf = str.substr(0, position);
	try {
		bill.payment = std::stoi(buf);
	}
	catch (std::exception e) {
		return false;
	}
	str = str.substr(position + 1);

	position = str.find('`');
	if (position == std::string::npos) {
		return false;
	}
	buf = str.substr(0, position);
	try {
		bill.peni = std::stod(buf);
	}
	catch (std::exception e) {
		return false;
	}
	str = str.substr(position + 1);

	try {
		bill.delay_number = std::stoi(buf);
	}
	catch (std::exception e) {
		return false;
	}
	return true;
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

int Bill::getHouseNumber() {
	return address.house_number;
}

void Bill::setBlockNumber(int block_number)
{
	if (block_number != 0) {
		this->address.block_number = block_number;
	}
}

void Bill::setApartmentNumber(int appartment_number)
{
	if (appartment_number >= 0) {
		this->address.apartment_number = appartment_number;
	}
}

int Bill::getApartmentNumber() {
	return address.apartment_number;
}

void Bill::setSurname(std::string surname)
{
	if (surname != "") {
		this->surname = surname;
	}
}

std::string Bill::getSurname() {
	return surname;
}

void Bill::setDate(Date date)
{
	this->date = date;
}

Date Bill::getDate() {
	return date;
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

double Bill::countPeni() {
	return peni*payment*delay_number;
}

bool Bill::houseNumberComparator(Bill bill1, Bill bill2)
{
	return bill1.address.house_number < bill2.address.house_number;
}

bool Bill::appartmentNumberComparator(Bill bill1, Bill bill2)
{
	return bill1.address.apartment_number < bill2.address.apartment_number;
}

bool Bill::surnameComparator(Bill bill1, Bill bill2)
{
	return bill1.surname < bill2.surname;
}

bool Bill::dateComparator(Bill bill1, Bill bill2) {
	return bill1.date < bill2.date;
}

bool Bill::peniComparator(Bill bill1, Bill bill2) {
	return bill1.countPeni() < bill2.countPeni();
}

std::ostream& operator<<(std::ostream & cout, Bill bill)
{
	return cout;
}

std::istream& operator>>(std::istream & cin, Bill bill)
{
	return cin;
}
