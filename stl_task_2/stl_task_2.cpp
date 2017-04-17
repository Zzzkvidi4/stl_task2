// stl_task_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


struct SurnameFunctor {
public:
	SurnameFunctor(std::string surname) {
		if (surname == "") {
			throw std::invalid_argument("������� �� ����� ���� ������!");
		}
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

void print_main_menu(TemplateContainer<Bill>& cont) {
	std::cout << "�������� ���� �� ������� ����:" << std::endl;
	std::cout << "1. ���������� �� �����." << std::endl;
	std::cout << "2. ������ � ����." << std::endl;
	std::cout << "3. �����." << std::endl;
	std::cout << "4. ���������� ������." << std::endl;
	std::cout << "5. �������� ������." << std::endl;
	std::cout << "6. �������������� ������." << std::endl;
}

void print_change_record_menu() {
	std::cout << "�������� ���� �� ������� ���� ��������������:" << std::endl;
	std::cout << "1. �����." << std::endl;
	std::cout << "2. ����� ����." << std::endl;
	std::cout << "3. ����� ��������." << std::endl;
	std::cout << "4. ����� ��������." << std::endl;
	std::cout << "5. ������� ���������." << std::endl;
	std::cout << "6. ��� �������." << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
}

void create_changes(TemplateContainer<Bill>::iterator& iter, int choice) {
	std::string str;
	switch (choice) {
		case 1: {
			std::cout << "������� ��������: " << iter->getStreetName() << std::endl;
			std::cout << "������� ����� ����� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				iter->setStreetName(str);
			}
			break;
		}
		case 2: {
			std::cout << "������� ��������: " << iter->getHouseNumber() << std::endl;
			std::cout << "������� ����� ����� ���� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				iter->setHouseNumber(str);
			}
			break;
		}
		case 3: {
			std::cout << "������� ��������: " << iter->getBlockNumber() << std::endl;
			std::cout << "������� ����� ����� �������� (������ ������ - ������, 0 - ��� ������ ��������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				if (str != "0") {
					iter->setBlockNumber(str);
				} else {
					iter->setBlockNumber("");
				}
			}
			break;
		}
		case 4: {
			std::cout << "������� ��������: " << iter->getApartmentNumber() << std::endl;
			std::cout << "������� ����� ����� �������� (������ ������ - ������, 0 - ��� ������ ��������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				if (str != "0") {
					iter->setApartmentNumber(str);
				} else {
					iter->setApartmentNumber("");
				}
			}
			break;
		}
		case 5: {
			std::cout << "������� ��������: " << iter->getSurname() << std::endl;
			std::cout << "������� ����� ������� ��������� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				iter->setSurname(str);
			}
			break;
		}
		case 6: {
			std::cout << "������� ��������: " << iter->getDate().getYear() << std::endl;
			std::cout << "������� ����� ��� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				iter->getDate().setYear(str);
			}
			break;
		}
	}
}

void change_record_action(TemplateContainer<Bill>& cont) {
	std::cout << "������� ������� ��� ��������������:" << std::endl;
	int num;
	getChoice(1, cont.size(), num);
	int choice = -1;
	while (choice != 0) {
		print_change_record_menu();
		getChoice(0, 7, choice);
		create_changes()
	}
}

void fill_from_file_action(TemplateContainer<Bill>& cont) {
	std::cout << "������� ��� ����� (������ ������ ��� ������):" << std::endl;
	std::string file_name;
	std::getline(std::cin, file_name);
	if (file_name != "") {
		try {
			if (!cont.read_from_file(file_name)) {
				print_message("��������, ���������� ����� ����� ���� �������� �����������!");
			}
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}

void fill_file_from_cont_action(TemplateContainer<Bill> cont) {
	std::cout << "������� ��� ����� (������ ������ ��� ������):" << std::endl;
	std::string file_name;
	std::getline(std::cin, file_name);
	if (file_name != "") {
		try {
			cont.print_to_file(file_name);
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}

void print_container_action(TemplateContainer<Bill> cont) {
	if (cont.size() == 0){
		print_message("������ ������ ����!");
	} else {
		std::cout << cont << std::endl;
		system("pause");
	}
}

void add_record_action(TemplateContainer<Bill>& cont) {
	Bill bill = Bill();
	try {
		std::string str;

		std::cout << "������� �����:" << std::endl;
		std::getline(std::cin, str);
		bill.setStreetName(str);

		std::cout << "������� ����� ����:" << std::endl;
		std::getline(std::cin, str);
		bill.setHouseNumber(str);

		std::cout << "������� ����� �������� (������ ������ ��� ��������):" << std::endl;
		std::getline(std::cin, str);
		bill.setBlockNumber(str);

		std::cout << "������� ����� �������� (������ ������ ��� ��������):" << std::endl;
		std::getline(std::cin, str);
		bill.setApartmentNumber(str);

		std::cout << "������� ��� �������:" << std::endl;
		std::getline(std::cin, str);
		bill.getDate().setYear(str);

		std::cout << "������� ����� �������:" << std::endl;
		std::getline(std::cin, str);
		bill.getDate().setMonth(str);

		std::cout << "������� ���� �������:" << std::endl;
		std::getline(std::cin, str);
		bill.getDate().setDay(str);

		std::cout << "������� ������� ���������:" << std::endl;
		std::getline(std::cin, str);
		bill.setSurname(str);

		std::cout << "������� ��� �������:" << std::endl;
		std::getline(std::cin, str);
		bill.setPaymentType(str);

		std::cout << "������� ����� �������:" << std::endl;
		std::getline(std::cin, str);
		bill.setPayment(str);

		std::cout << "������� ������� ����:" << std::endl;
		std::getline(std::cin, str);
		bill.setPeni(str);

		std::cout << "������� ���������� ���� ���������:" << std::endl;
		std::getline(std::cin, str);
		bill.setDelayNumber(str);
	}
	catch (std::exception e) {
		print_message(e.what());
	}
	cont.Add(bill);
}

void remove_record_action(TemplateContainer<Bill>& cont) {
	if (cont.size() == 0) {
		print_message("������ ������ ����!");
		return;
	}
	std::cout << "������� ������� ��� ��������:" << std::endl;
	int num;
	getChoice(1, cont.size(), num);
	cont.Erase(num);
}

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

