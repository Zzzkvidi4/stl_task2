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

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	TemplateContainer<Bill>* cont = new TemplateContainer<Bill>();
	/*int choice = -1;
	while (choice != 0) {
		print_main_menu(cont);
		getChoice(0, 8, choice);
		create_action(cont, choice);
	}*/
    CommandList* main_menu = new CommandList();
    main_menu->RegisterCommand(new ReadFromFileCommand<Bill>("���������� �� �����.", cont));
    main_menu->RegisterCommand(new PrintToFileCommand<Bill>("����� � ����.", cont));
    main_menu->RegisterCommand(new PrintCommand<Bill>("����� � �������.", cont));
    main_menu->RegisterCommand(new AddBillCommand("���������� ������.", cont));
	main_menu->RegisterCommand(new EditRecordCommand("�������������� ������.", cont));
    int choice = -1;
    while (choice != 0) {
        main_menu->PrintTitles("�������� ���� �� ������� ����:");
        getChoice(0, main_menu->Size(), choice);
        if (choice != 0) {
            main_menu->ExecuteCommand(choice);
        }
    }
	return 0;
}

