#include "stdafx.h"
#include "SetMonthCommand.h"


SetMonthCommand::SetMonthCommand(std::string title, Bill& bill): Command(title), bill(bill)
{
}


void SetMonthCommand::Execute()
{
	std::string str;
	bool isCorrect = false;
	std::cout << "Текущее значение: " << bill.getDate().getMonth() << std::endl;
	while (!isCorrect) {
		std::cout << "Введите новый месяц (пустая строка - отмена):" << std::endl;
		std::getline(std::cin, str);
		if (str == "") {
			throw new std::exception("");
		}
		try {
			bill.getDate().setMonth(str);
			isCorrect = true;
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}

SetMonthCommand::~SetMonthCommand()
{
}
