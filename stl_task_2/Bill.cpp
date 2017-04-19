#include "stdafx.h"
#include "Bill.h"

//����������� �� ���������
Bill::Bill() {
	address = Address();
	date = Date();
	surname = "";
	payment_type = "";
	peni = 0.0;
	payment = 0.0;
	delay_number = 0;
	hasPeni = false;
}

//����������� �� ������
Bill::Bill(std::string str) {
	if (!StrToBill(str, *this)) {
		throw std::invalid_argument("������ �������������� ������ � ����!");
	}
}

//�������������� � ������
std::string Bill::to_string()
{
	return address.to_string() + '`' + surname + '`' + date.to_string() + '`' + payment_type + '`' + 
			std::to_string(payment) + '`' + std::to_string(peni) + '`' + std::to_string(delay_number);
}

//�������������� �� ������
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

//������� ��� ������
void Bill::setAddress(Address adr) {
	address = adr;
}

//������� � ������� ��� �����
void Bill::setStreetName(std::string street_name)
{
	if (street_name != "") {
		this->address.setStreetName(street_name);
	}
}

std::string Bill::getStreetName() {
	return address.getStreetName();
}

//������� � ������� ��� ������ ����
void Bill::setHouseNumber(std::string house_number)
{
	if (house_number != "0") {
		this->address.setHouseNumber(house_number);
	}
}

void Bill::setHouseNumber(int num) {
	address.setHouseNumber(num);
}

int Bill::getHouseNumber() {
	return address.getHouseNumber();
}

//������� � ������� ������ ��������
void Bill::setBlockNumber(std::string block_number)
{
	this->address.setBlockNumber(block_number);
}

int Bill::getBlockNumber() {
	return address.getBlockNumber();
}

//������� � ������� ��� ������ ��������
void Bill::setApartmentNumber(std::string appartment_number)
{
	this->address.setApartmentNumber(appartment_number);
}

void Bill::setApartmentNumber(int num) {
	address.setApartmentNumber(num);
}

int Bill::getApartmentNumber() {
	return address.getApartmentNumber();
}

//������� � ������� ��� �������
void Bill::setSurname(std::string surname)
{
	if (surname == "") {
		throw std::invalid_argument("������� ��������� �� ����� ���� ������!");
	}
	this->surname = surname;
}

std::string Bill::getSurname() {
	return surname;
}

//������� � ������� ��� ����
void Bill::setDate(Date date)
{
	this->date = date;
}

Date& Bill::getDate() {
	return date;
}

//������� � ������� ��� ���� ������
void Bill::setPaymentType(std::string payment_type)
{
	if (payment_type == "") {
		throw std::invalid_argument("��� ������� �� ����� ���� ������ �������!");
	}
	this->payment_type = payment_type;
}

std::string Bill::getPaymentType() {
	return payment_type;
}

//������� � ������� ��� ����� ������
void Bill::setPayment(double payment)
{
	this->payment = payment;
}

void Bill::setPayment(std::string str) {
	try {
		this->payment = std::stod(str);
	}
	catch (std::exception e) {
		throw std::invalid_argument("����� ������� �� ����� ���� �� ������!");
	}
}

double Bill::getPayment() {
	return payment;
}

//������� � ������� ��� �������� ����
void Bill::setPeni(double peni)
{
	if (peni > DBL_EPSILON) {
		this->peni = peni;
	}
}

void Bill::setPeni(std::string str) {
	try {
		this->peni = std::stod(str);
	}
	catch (std::exception e) {
		throw std::invalid_argument("���� �� ����� ���� �� ������!");
	}
}

double Bill::getPeni() {
	return peni;
}

//������� � ������� ��� ���������� ���� ���������
void Bill::setDelayNumber(int delay_number)
{
	if (delay_number >= 0) {
		this->delay_number = delay_number;
		hasPeni = delay_number > 0;
	}
}

void Bill::setDelayNumber(std::string str) {
	try {
		this->delay_number = std::stoi(str);
		hasPeni = delay_number > 0;
	}
	catch (std::exception e) {
		throw std::invalid_argument("���������� ���� ��������� �� ����� ���� �� ������!");
	}
}

int Bill::getDelayNumber() {
	return delay_number;
}

void Bill::setHasPeni(bool val) {
	hasPeni = val;
}

//������� ����
double Bill::countPeni() {
	return peni*payment*delay_number;
}

//����������� �� �����
bool Bill::houseNumberComparator(Bill bill1, Bill bill2)
{
	return bill1.address.getHouseNumber() < bill2.address.getHouseNumber();
}

bool Bill::appartmentNumberComparator(Bill bill1, Bill bill2)
{
	return bill1.address.getApartmentNumber() < bill2.address.getApartmentNumber();
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

//�������� �����/������
std::ostream& operator<<(std::ostream & cout, Bill bill)
{
	cout << "�����: " << bill.address << std::endl << "��������: " << bill.surname << std::endl 
			<< "����: " << bill.date << std::endl << "��� �������: " << bill.payment_type << std::endl 
			<< "����� �������: " << std::to_string(bill.payment) << std::endl << "����: " << std::to_string(bill.peni) << std::endl 
			<< "���� �����������: " << bill.delay_number << std::endl << "����: " << bill.countPeni();
	return cout;
}

std::istream& operator>>(std::istream & cin, Bill &bill)
{
	std::string buf;
	std::getline(cin, buf);
	int position = buf.find(':');
	if (position == std::string::npos) {
		throw std::invalid_argument("���� �����������!");
	}
	buf = buf.substr(position + 2);
	if (!Address::StrToAddress(buf, bill.address)) {
		throw std::invalid_argument("���������� ������������� ������ � ������!");
	}

	std::getline(cin, buf);
	position = buf.find(':');
	if (position == std::string::npos) {
		throw std::invalid_argument("���� �����������!");
	}
	buf = buf.substr(position + 2);
	if (buf == "") {
		throw std::invalid_argument("������� ��������� �� ����� ���� ������ �������!");
	}
	bill.surname = buf;

	std::getline(cin, buf);
	position = buf.find(':');
	if (position == std::string::npos) {
		throw std::invalid_argument("���� �����������!");
	}
	buf = buf.substr(position + 2);
	if (!Date::StrToDate(buf, bill.date)) {
		throw std::invalid_argument("���������� ������������� ������ � ����!");
	}

	std::getline(cin, buf);
	position = buf.find(':');
	if (position == std::string::npos) {
		throw std::invalid_argument("���� �����������!");
	}
	buf = buf.substr(position + 2);
	if (buf == "") {
		throw std::invalid_argument("��� ������� �� ����� ���� ������ �������!");
	}
	bill.payment_type = buf;

	std::getline(cin, buf);
	position = buf.find(':');
	if (position == std::string::npos) {
		throw std::invalid_argument("���� �����������!");
	}
	buf = buf.substr(position + 2);
	try {
		bill.payment = std::stod(buf);
	}
	catch (std::invalid_argument e) {
		throw std::invalid_argument("����� ������� �� ����� ���� �� ������!");
	}

	std::getline(cin, buf);
	position = buf.find(':');
	if (position == std::string::npos) {
		throw std::invalid_argument("���� �����������!");
	}
	buf = buf.substr(position + 2);
	try {
		bill.peni = std::stod(buf);
	}
	catch (std::invalid_argument e) {
		throw std::invalid_argument("������� ���� �� ����� ���� �� ������!");
	}

	std::getline(cin, buf);
	position = buf.find(':');
	if (position == std::string::npos) {
		throw std::invalid_argument("���� �����������!");
	}
	buf = buf.substr(position + 2);
	try {
		bill.delay_number = std::stoi(buf);
	}
	catch (std::invalid_argument e) {
		throw std::invalid_argument("���������� ���� ����������� �� ����� ���� �� ������!");
	}

	std::getline(cin, buf);
	position = buf.find(':');
	if (position == std::string::npos) {
		throw std::invalid_argument("���� �����������!");
	}
	buf = buf.substr(position + 2);
	try {
		bill.peni_payment = std::stod(buf);
	}
	catch (std::invalid_argument e) {
		throw std::invalid_argument("����� ���� �� ����� ���� �� ������!");
	}
	bill.hasPeni = bill.delay_number > 0;
	return cin;
}
