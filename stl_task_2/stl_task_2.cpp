// stl_task_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

/*����������� ������ ���� ���������� ��������� � ��������� ����. ��������� ������ ��������� ��������� ����� ��� ���������� ������� �������� �������. ��� �������� ������ ���������� ������� ����������� � ����� ������ ������� ���������. 
1. ������������� �������� ����������, ��������� � �������� �������� ����������. 
2. ����������� ���� � ����� ��������� ���������� � �������������� ��������� ���������� �� ����� � � ����. 
3. ����������� �������� ������ �� �������� ��������� � ������� ������������ ��������� �� �������� ���������. ����������� ����� � ���� ���������: �������� ����� � �������� ����� �� ��������������� ����������. 
4. ������������� ����� ������������ ������� �� ����� � � ����. 
�������� �������. 
8. ��������� ������ � ������������ ������� �������� ����: ����� ��������,
������� ���������, ��� �������, ���� �������, ����� �������, ������� ����,
���������� ���� ��������� �������. 
����� �� ������ ����, ��������, ���������, ����, ������� �����. 
����� ����� ����� � ����������� ������. */

struct SurnameFunctor {
	SurnameFunctor(std::string surname):surname(surname) {}

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
	HavePeniFunctor(bool val) : hasPeni(val) {};

	bool operator()(Bill bill) {
		return bill.countPeni() > DBL_EPSILON;
	}

	Bill constructValue() {
		Bill* bill = new Bill();
		bill->setHasPeni(hasPeni);
		return *bill;
	}
private:
	bool hasPeni;
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

//�������� ����
void print_main_menu(TemplateContainer<Bill>& cont) {
	system("cls");
	std::cout << "�������� ���� �� ������� ����:" << std::endl;
	std::cout << "1. ���������� �� �����." << std::endl;
	std::cout << "2. ������ � ����." << std::endl;
	std::cout << "3. �����." << std::endl;
	std::cout << "4. ���������� ������." << std::endl;
	std::cout << "5. �������� ������." << std::endl;
	std::cout << "6. �������������� ������." << std::endl;
	std::cout << "7. ������� ������� �� ���������." << std::endl;
	std::cout << "8. ������� ������� �� ���������(�������� �����)." << std::endl;
	std::cout << "0. �����." << std::endl;
	if (cont.size() == 0) {
		std::cout << "������ ������ ����. ��������� �������� ����������." << std::endl;
	}
}

//���� ���������
void print_change_record_menu() {
	std::cout << "�������� ���� �� ������� ���� ��������������:" << std::endl;
	std::cout << "1. �����." << std::endl;
	std::cout << "2. ����� ����." << std::endl;
	std::cout << "3. ����� ��������." << std::endl;
	std::cout << "4. ����� ��������." << std::endl;
	std::cout << "5. ������� ���������." << std::endl;
	std::cout << "6. ��� �������." << std::endl;
	std::cout << "7. ����� �������." << std::endl;
	std::cout << "8. ���� �������." << std::endl;
	std::cout << "9. ����� �������." << std::endl;
	std::cout << "10. ��� �������." << std::endl;
	std::cout << "11. ������� ����." << std::endl;
	std::cout << "12. ���������� ���� �����������." << std::endl;
	std::cout << "0. �����." << std::endl;
}

//���������� ���������
void create_changes(Bill& bill, int choice) {
	std::string str;
	try {
		switch (choice) {
		case 1: {
			std::cout << "������� ��������: " << bill.getStreetName() << std::endl;
			std::cout << "������� ����� ����� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setStreetName(str);
			}
			break;
		}
		case 2: {
			std::cout << "������� ��������: " << bill.getHouseNumber() << std::endl;
			std::cout << "������� ����� ����� ���� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setHouseNumber(str);
			}
			break;
		}
		case 3: {
			std::cout << "������� ��������: " << bill.getBlockNumber() << std::endl;
			std::cout << "������� ����� ����� �������� (������ ������ - ������, 0 - ��� ������ ��������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				if (str != "0") {
					bill.setBlockNumber(str);
				} else {
					bill.setBlockNumber("");
				}
			}
			break;
		}
		case 4: {
			std::cout << "������� ��������: " << bill.getApartmentNumber() << std::endl;
			std::cout << "������� ����� ����� �������� (������ ������ - ������, 0 - ��� ������ ��������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				if (str != "0") {
					bill.setApartmentNumber(str);
				} else {
					bill.setApartmentNumber("");
				}
			}
			break;
		}
		case 5: {
			std::cout << "������� ��������: " << bill.getSurname() << std::endl;
			std::cout << "������� ����� ������� ��������� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setSurname(str);
			}
			break;
		}
		case 6: {
			std::cout << "������� ��������: " << bill.getDate().getYear() << std::endl;
			std::cout << "������� ����� ��� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.getDate().setYear(str);
			}
			break;
		}
		case 7: {
			std::cout << "������� ��������: " << bill.getDate().getMonth() << std::endl;
			std::cout << "������� ����� ����� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.getDate().setMonth(str);
			}
			break;
		}
		case 8: {
			std::cout << "������� ��������: " << bill.getDate().getDay() << std::endl;
			std::cout << "������� ����� ���� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.getDate().setDay(str);
			}
			break;
		}
		case 9: {
			std::cout << "������� ��������: " << bill.getPayment() << std::endl;
			std::cout << "������� ����� ����� ������� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setPayment(str);
			}
			break;
		}
		case 10: {
			std::cout << "������� ��������: " << bill.getPaymentType() << std::endl;
			std::cout << "������� ����� ��� ������� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setPaymentType(str);
			}
			break;
		}
		case 11: {
			std::cout << "������� ��������: " << bill.getPeni() << std::endl;
			std::cout << "������� ����� ������� ���� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setPeni(str);
			}
			break;
		}
		case 12: {
			std::cout << "������� ��������: " << bill.getDelayNumber() << std::endl;
			std::cout << "������� ����� ����� ������� (������ ������ - ������):" << std::endl;
			std::getline(std::cin, str);
			if (str != "") {
				bill.setDelayNumber(str);
			}
			break;
		}
		default: {
			break;
		}
		}
	}
	catch (std::exception e) {
		print_message(e.what());
	}
}

//�������� ��������� ������
void change_record_action(TemplateContainer<Bill>& cont) {
	std::cout << "������� ������� ��� ��������������:" << std::endl;
	int num;
	getChoice(1, cont.size(), num);
	int choice = -1;
	while (choice != 0) {
		std::cout << cont[num] << std::endl;
		print_change_record_menu();
		getChoice(0, 12, choice);
		if (choice != 0) {
			create_changes(cont[num], choice);
		}
		system("cls");
	}
}

//�������� ���������� �� �����
void fill_from_file_action(TemplateContainer<Bill>& cont) {
	std::cout << "������� ��� ����� (������ ������ ��� ������):" << std::endl;
	std::string file_name;
	std::getline(std::cin, file_name);
	if (file_name != "") {
		cont.clear();
		try {
			if (!cont.read_from_file(file_name)) {
				print_message("��������, ���������� ����� ����� ���� �������� �����������!");
			}
		}
		catch (std::exception e) {
			print_message("���� ��������� ����������. ���������� �� ����� ���� ��������.");
		}
	}
}

//�������� ���������� ����� �� ����������
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

//�������� ������ ����������
void print_container_action(TemplateContainer<Bill> cont) {
	if (cont.size() == 0){
		print_message("������ ������ ����!");
	} else {
		std::cout << cont << std::endl;
		system("pause");
	}
}

//�������� ���������� ������
void add_record_action(TemplateContainer<Bill>& cont) {
	if (input_query("������ ������? (Y/N) (N):")) {
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
}

//�������� �������� ������
void remove_record_action(TemplateContainer<Bill>& cont) {
	if (cont.size() == 0) {
		print_message("������ ������ ����!");
		return;
	}
	std::cout << "������� ������� ��� �������� (0 - ������):" << std::endl;
	int num;
	getChoice(0, cont.size(), num);
	if (num != 0) {
		cont.Erase(num);
	}
}

#pragma region select_functions_region

//������� �� �������
void select_records_by_surname(TemplateContainer<Bill> cont) {
	if (input_query("������ ������� ���������? (Y/N) (N):")) {
		std::cout << "������� ������� ��������� (������ ������ - ������):" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			SurnameFunctor func = SurnameFunctor(str);
			TemplateContainer<Bill> result = cont.GetElemsIf(func);
			std::cout << result << std::endl;
			bool is_saving = input_query("��������� ��������� � ����? (Y/N) (N):");
			if (is_saving) {
				std::cout << "������� ��� ����� (������ ������ - ������):" << std::endl;
				std::getline(std::cin, str);
				if (str != "") {
					try {
						result.print_to_file(str);
					}
					catch (std::exception e) {
						print_message(e.what());
					}
				}
			}
		}
	}
}

//������� �� ������� ��������
void select_records_by_surname_binary(TemplateContainer<Bill> cont) {
	if (input_query("������ ������� ���������? (Y/N) (N):")) {
		std::cout << "������� ������� ��������� (������ ������ - ������):" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			SurnameFunctor func = SurnameFunctor(str);
			TemplateContainer<Bill> result = cont.GetElemsIfBinary(Bill::surnameComparator, func, func.constructValue());
			std::cout << result << std::endl;
			bool is_saving = input_query("��������� ��������� � ����? (Y/N) (N):");
			if (is_saving) {
				std::cout << "������� ��� ����� (������ ������ - ������):" << std::endl;
				std::getline(std::cin, str);
				if (str != "") {
					try {
						result.print_to_file(str);
					}
					catch (std::exception e) {
						print_message(e.what());
					}
				}
			}
		}
	}
}

//������� �� ������ ��������
void select_records_by_apartment_number(TemplateContainer<Bill> cont) {
	if (input_query("������ ����� ��������? (Y/N) (N):")) {
		std::cout << "������� ����� �������� (������ ������ - ������, 0 - ��� ������ ��������):" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				int num = std::stoi(str);
				ApartmentNumberFunctor func = ApartmentNumberFunctor(num);
				TemplateContainer<Bill> result = cont.GetElemsIf(func);
				std::cout << result << std::endl;
				bool is_saving = input_query("��������� ��������� � ����? (Y/N) (N):");
				if (is_saving) {
					std::cout << "������� ��� ����� (������ ������ - ������):" << std::endl;
					std::getline(std::cin, str);
					if (str != "") {
						try {
							result.print_to_file(str);
						}
						catch (std::exception e) {
							print_message(e.what());
						}
					}
				}
			}
			catch (std::invalid_argument e) {
				print_message("����� �������� ������ ���� ������!");
			}
		}
	}
}

//������� �� ������ �������� ��������
void select_records_by_apartment_number_binary(TemplateContainer<Bill> cont) {
	if (input_query("������ ����� ��������? (Y/N) (N):")) {
		std::cout << "������� ����� �������� (������ ������ - ������, 0 - ��� ������ ��������):" << std::endl;
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				int num = std::stoi(str);
				ApartmentNumberFunctor func = ApartmentNumberFunctor(num);
				TemplateContainer<Bill> result = cont.GetElemsIfBinary(Bill::appartmentNumberComparator, func, func.constructValue());
				std::cout << result << std::endl;
				bool is_saving = input_query("��������� ��������� � ����? (Y/N) (N):");
				if (is_saving) {
					std::cout << "������� ��� ����� (������ ������ - ������):" << std::endl;
					std::getline(std::cin, str);
					if (str != "") {
						try {
							result.print_to_file(str);
						}
						catch (std::exception e) {
							print_message(e.what());
						}
					}
				}
			}
			catch (std::invalid_argument e) {
				print_message("����� �������� ������ ���� ������!");
			}
		}
	}
}

//������� �� ������ ����
void select_records_by_house_number(TemplateContainer<Bill> cont) {
	if (input_query("������ ����� ����? (Y/N) (N):")) {
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				int num = std::stoi(str);
				HouseNumberFunctor func = HouseNumberFunctor(num);
				TemplateContainer<Bill> result = cont.GetElemsIf(func);
				std::cout << result << std::endl;
				bool is_saving = input_query("��������� ��������� � ����? (Y/N) (N):");
				if (is_saving) {
					std::cout << "������� ��� ����� (������ ������ - ������):" << std::endl;
					std::getline(std::cin, str);
					if (str != "") {
						try {
							result.print_to_file(str);
						}
						catch (std::exception e) {
							print_message(e.what());
						}
					}
				}
			}
			catch (std::invalid_argument e) {
				print_message("����� ���� ������ ���� ������!");
			}
		}
	}
}

//������� �� ������ ���� ��������
void select_records_by_house_number_binary(TemplateContainer<Bill> cont) {
	if (input_query("������ ����� ����? (Y/N) (N):")) {
		std::string str;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				int num = std::stoi(str);
				HouseNumberFunctor func = HouseNumberFunctor(num);
				TemplateContainer<Bill> result = cont.GetElemsIfBinary(Bill::houseNumberComparator, func, func.constructValue());
				std::cout << result << std::endl;
				bool is_saving = input_query("��������� ��������� � ����? (Y/N) (N):");
				if (is_saving) {
					std::cout << "������� ��� ����� (������ ������ - ������):" << std::endl;
					std::getline(std::cin, str);
					if (str != "") {
						try {
							result.print_to_file(str);
						}
						catch (std::exception e) {
							print_message(e.what());
						}
					}
				}
			}
			catch (std::invalid_argument e) {
				print_message("����� ���� ������ ���� ������!");
			}
		}
	}
}

//������� �� ����
void select_records_by_date(TemplateContainer<Bill> cont) {
	if (input_query("������ ����? (Y/N) (N):")) {
		Date date = Date();
		try {
			std::cin >> date;
			DateFunctor func = DateFunctor(date);
			TemplateContainer<Bill> result = cont.GetElemsIf(func);
			std::cout << result << std::endl;
			bool is_saving = input_query("��������� ��������� � ����? (Y/N) (N):");
			if (is_saving) {
				std::cout << "������� ��� ����� (������ ������ - ������):" << std::endl;
				std::string str;
				std::getline(std::cin, str);
				if (str != "") {
					try {
						result.print_to_file(str);
					}
					catch (std::exception e) {
						print_message(e.what());
					}
				}
			}
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}

//������� �� ���� ��������
void select_records_by_date_binary(TemplateContainer<Bill> cont) {
	if (input_query("������ ����? (Y/N) (N):")) {
		Date date = Date();
		try {
			std::cin >> date;
			DateFunctor func = DateFunctor(date);
			TemplateContainer<Bill> result = cont.GetElemsIfBinary(Bill::dateComparator, func, func.constructValue());
			std::cout << result << std::endl;
			bool is_saving = input_query("��������� ��������� � ����? (Y/N) (N):");
			if (is_saving) {
				std::cout << "������� ��� ����� (������ ������ - ������):" << std::endl;
				std::string str;
				std::getline(std::cin, str);
				if (str != "") {
					try {
						result.print_to_file(str);
					}
					catch (std::exception e) {
						print_message(e.what());
					}
				}
			}
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}

//������� �� ������� ����
void select_records_by_having_peni(TemplateContainer<Bill> cont) {
	std::string str;
	HavePeniFunctor func = HavePeniFunctor(input_query("������� ������ � ������? (Y/N) (N):"));
	TemplateContainer<Bill> result = cont.GetElemsIf(func);
	std::cout << result << std::endl;
	bool is_saving = input_query("��������� ��������� � ����? (Y/N) (N):");
	if (is_saving) {
		std::cout << "������� ��� ����� (������ ������ - ������):" << std::endl;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				result.print_to_file(str);
			}
			catch (std::exception e) {
				print_message(e.what());
			}
		}
	}
}

//������� �� ������� ���� ��������
void select_records_by_having_peni_binary(TemplateContainer<Bill> cont) {
	std::string str;
	HavePeniFunctor func = HavePeniFunctor(input_query("������� ������ � ������? (Y/N) (N):"));
	TemplateContainer<Bill> result = cont.GetElemsIfBinary(Bill::peniComparator, func, func.constructValue());
	std::cout << result << std::endl;
	bool is_saving = input_query("��������� ��������� � ����? (Y/N) (N):");
	if (is_saving) {
		std::cout << "������� ��� ����� (������ ������ - ������):" << std::endl;
		std::getline(std::cin, str);
		if (str != "") {
			try {
				result.print_to_file(str);
			}
			catch (std::exception e) {
				print_message(e.what());
			}
		}
	}
}

//���� �������
void print_select_records_menu() {
	system("cls");
	std::cout << "�������� ���� �� ������� ���� �������:" << std::endl;
	std::cout << "1. �� �������." << std::endl;
	std::cout << "2. �� ������ ��������." << std::endl;
	std::cout << "3. �� ����." << std::endl;
	std::cout << "4. �� ������ ����." << std::endl;
	std::cout << "5. �� ������� �����������." << std::endl;
	std::cout << "0. �����." << std::endl;
}

//���������� �������
void create_select(TemplateContainer<Bill> cont, int choice) {
	switch (choice) {
	case 1: {
		select_records_by_surname(cont);
		break;
	}
	case 2: {
		select_records_by_house_number(cont);
		break;
	}
	case 3: {
		select_records_by_date(cont);
		break;
	}
	case 4: {
		select_records_by_house_number(cont);
		break;
	}
	case 5: {
		select_records_by_having_peni(cont);
		break;
	}
	default: {
		break;
	}
	}
}

//�������� �������
void select_records_action(TemplateContainer<Bill> cont) {
	int choice = -1;
	while (choice != 0) {
		print_select_records_menu();
		getChoice(0, 5, choice);
		if (choice != 0) {
			create_select(cont, choice);
		}
	}
}

//���������� ������� ��������
void create_select_binary(TemplateContainer<Bill> cont, int choice) {
	switch (choice) {
	case 1: {
		select_records_by_surname_binary(cont);
		break;
	}
	case 2: {
		select_records_by_house_number_binary(cont);
		break;
	}
	case 3: {
		select_records_by_date_binary(cont);
		break;
	}
	case 4: {
		select_records_by_house_number_binary(cont);
		break;
	}
	case 5: {
		select_records_by_having_peni_binary(cont);
		break;
	}
	default: {
		break;
	}
	}
}

//�������� ������� ��������
void select_records_binary_action(TemplateContainer<Bill> cont) {
	int choice = -1;
	while (choice != 0) {
		print_select_records_menu();
		getChoice(0, 5, choice);
		if (choice != 0) {
			create_select_binary(cont, choice);
		}
	}
}


#pragma endregion

//�������� ���������
void create_action(TemplateContainer<Bill>& cont, int choice) {
	switch (choice) {
	case 1: {
		fill_from_file_action(cont);
		break;
	}
	case 2: {
		if (cont.size() != 0) {
			fill_file_from_cont_action(cont);
		}
		break;
	}
	case 3: {
		print_container_action(cont);
		break;
	}
	case 4: {
		add_record_action(cont);
		break;
	}
	case 5: {
		if (cont.size() != 0) {
			remove_record_action(cont);
		}
		break;
	}
	case 6: {
		if (cont.size() != 0) {
			change_record_action(cont);
		}
		break;
	}
	case 7: {
		if (cont.size() != 0) {
			select_records_action(cont);
		}
		break;
	}
	case 8: {
		if (cont.size() != 0) {
			select_records_binary_action(cont);
		}
		break;
	}
	default: {
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	TemplateContainer<Bill> cont = TemplateContainer<Bill>();
	int choice = -1;
	while (choice != 0) {
		print_main_menu(cont);
		getChoice(0, 8, choice);
		create_action(cont, choice);
	}
	return 0;
}

