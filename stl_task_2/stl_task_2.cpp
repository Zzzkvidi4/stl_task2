// stl_task_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


struct SurnameFunctor {
public:
	SurnameFunctor(std::string surname) {
		this->surname = surname;
	}

	bool operator()(Bill bill) {
		return bill.getSurname() == surname;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setSurname(surname);
		return *bill;
	}
private:
	std::string surname;
};

struct HouseNumberFunctor {
public:
	HouseNumberFunctor(int num) {
		this->num = num;
	}

	bool operator()(Bill bill) {
		return bill.getHouseNumber() == num;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setHouseNumber(num);
		return *bill;
	}
private:
	int num;
};

struct ApartmentNumberFunctor {
public:
	ApartmentNumberFunctor(int num) {
		this->num = num;
	}

	bool operator()(Bill bill) {
		return bill.getApartmentNumber() == num;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setApartmentNumber(num);
		return *bill;
	}
private:
	int num;
};

struct HavePeniFunctor {
	bool operator()(Bill bill) {
		return bill.countPeni() > DBL_EPSILON;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setHasPeni(true);
		return *bill;
	}
};

struct DateFunctor {
public:
	DateFunctor(Date date) {
		this->date = date;
	}

	bool operator()(Bill bill) {
		return bill.getDate() == date;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setDate(date);
		return *bill;
	}
private:
	Date date;
};

int main()
{
	setlocale(LC_ALL, "russian");
	TemplateContainer<int> cont = TemplateContainer<int>();
	Bill bill = Bill();
	std::ifstream fout("some.txt");
	fout >> bill;
	std::cout << bill;
	fout.close();
	cont.Add(5).Add(19).Add(28);
	std::cout << cont;
	system("pause");
	return 0;
}

