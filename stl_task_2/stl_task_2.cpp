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
private:
	int num;
};

struct HavePeniFunctor {
	bool operator()(Bill bill) {
		return bill.countPeni() > DBL_EPSILON;
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
private:
	Date date;
};

int main()
{
	setlocale(LC_ALL, "russian");
	TemplateContainer<int> cont = TemplateContainer<int>();
	cont.Add(5).Add(19).Add(28);
	std::cout << cont;
	system("pause");
	return 0;
}

