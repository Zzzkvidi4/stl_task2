#include "stdafx.h"
#include "SetHouseNumberCommand.h"


SetHouseNumberCommand::SetHouseNumberCommand(std::string title, Bill& bill): Command(title), bill(bill)
{
}

void SetHouseNumberCommand::Execute()
{
	std::string str;
	std::cout << "Текущее значение: " << bill.getHouseNumber() << std::endl;
	std::cout << "Введите новый номер дома (пустая строка - отмена):" << std::endl;
	std::getline(std::cin, str);
	if (str == "") {
		throw new std::exception("");
	}
	bill.setHouseNumber(str);
}


SetHouseNumberCommand::~SetHouseNumberCommand()
{
}
