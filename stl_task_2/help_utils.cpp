#include "stdafx.h"
#include "help_utils.h"
#include "TemplateContainer.h"

//функция для вывода сообщений
void print_message(std::string msg)
{
    std::cout << msg << std::endl;
    system("pause");
}

//функция получения одного из вариантов между min и max
void getChoice(int min, int max, int& choice_number) {
	bool ok = false;
	choice_number = INT_MIN;
	while (!ok) {
		std::string choice = "";
		try {
			std::getline(std::cin, choice);
			if (!checkInt(choice)) {
				throw std::invalid_argument("");
			}
			choice_number = std::stoi(choice);
			if ((choice_number < min) || (choice_number > max)) {
				print_message("Вы должны ввести число от " + std::to_string(min) + " до " + std::to_string(max) + "!");
			} else {
				ok = true;
			}
		}
		catch (std::invalid_argument e) {
			print_message("Вы должны ввести число!");
		}
		catch (std::out_of_range e) {
			print_message("Выход за границы типа!");
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
			if (!checkInt(choice)) {
				throw std::invalid_argument("");
			}
			value = std::stoi(choice);
			if (value < min) {
				print_message("Вы должны ввести число больше " + std::to_string(min) + "!");
			} else {
				ok = true;
			}
		}
		catch (std::invalid_argument e) {
			print_message("Вы должны ввести число!");
		}
		catch (std::out_of_range e) {
			print_message("Выход за границы типа!");
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

bool checkDouble(std::string str) {
	if (str.length() == 0) {
		return false;
	}
	size_t i = 0;
	while ((i < str.length()) && ((str[i] == ' ') || (str[i] == '	'))) {
		++i;
	}
	if (i >= str.length()) {
		return false;
	}
	int sign = 1;
	switch (str[i]) {
		case '-': {
			sign = -1;
			++i;
			break;
		}
		case '+': {
			++i;
			break;
		}
		default: {
			break;
		}
	}

	size_t j = i;
	bool result = j < str.length();
	int dot_number = 0;
	while ((j < str.length()) && (result)) {
		if (str[j] == '.') {
			++dot_number;
		}
		result = ((str[j] >= '0') && (str[j] <= '9')) || ((str[j] == '.') && (dot_number <= 1));
		++j;
	}

	while ((j < str.length()) && ((str[j] == ' ') || (str[j] == '	'))) {
		++j;
	}

	return (j == str.length()) && (result);
}

bool checkInt(std::string str) {
	if (str.length() == 0) {
		return false;
	}
	size_t i = 0;
	while ((i < str.length()) && ((str[i] == ' ') || (str[i] == '	'))) {
		++i;
	}
	if (i >= str.length()) {
		return false;
	}
	int sign = 1;
	switch (str[i]) {
		case '-': {
			sign = -1;
			++i;
			break;
		}
		case '+': {
			++i;
			break;
		}
		default: {
			break;
		}
	}

	size_t j = i;
	bool result = j < str.length();
	while ((j < str.length()) && (result)) {
		result = (str[j] >= '0') && (str[j] <= '9');
		++j;
	}

	while ((j < str.length()) && ((str[j] == ' ') || (str[j] == '	'))) {
		++j;
	}

	return (j == str.length()) && (result);
}
