#include "stdafx.h"
#include "help_utils.h"

//������� ��� ������ ���������
void print_message(std::string msg)
{
    std::cout << msg << std::endl;
    system("pause");
}

//������� ��������� ������ �� ��������� ����� min � max
void getChoice(int min, int max, int& choice_number) {
	bool ok = false;
	choice_number = INT_MIN;
	while (!ok) {
		std::string choice = "";
		try {
			std::getline(std::cin, choice);
			choice_number = std::stoi(choice);
			if ((choice_number < min) || (choice_number > max)) {
				print_message("�� ������ ������ ����� �� " + std::to_string(min) + " �� " + std::to_string(max) + "!");
			} else {
				ok = true;
			}
		}
		catch (std::invalid_argument e) {
			print_message("�� ������ ������ �����!");
		}
		catch (std::out_of_range e) {
			print_message("����� �� ������� ����!");
		}
	}
}

void getIntGreater(int min, int & value) {
	bool ok = false;
	value = INT_MIN;
	while (!ok) {
		std::string choice = "";
		try {
			std::getline(std::cin, choice);
			value = std::stoi(choice);
			if (value < min) {
				print_message("�� ������ ������ ����� ������ " + std::to_string(min) + "!");
			} else {
				ok = true;
			}
		}
		catch (std::invalid_argument e) {
			print_message("�� ������ ������ �����!");
		}
		catch (std::out_of_range e) {
			print_message("����� �� ������� ����!");
		}
	}
}

bool input_query(std::string query) {
	std::cout << query << std::endl;
	std::string str;
	std::getline(std::cin, str);
	if ((str.length() > 0) && ((str[0] == 'Y') || (str[0] == 'y'))) {
		return true;
	}
	return false;
}
