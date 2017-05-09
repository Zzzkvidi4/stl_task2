#include "stdafx.h"
#include "SetStreetCommand.h"


SetStreetCommand::SetStreetCommand(std::string title, Bill& bill): Command(title), bill(bill)
{
}

void SetStreetCommand::Execute()
{
	std::string str;
	std::cout << "Текущее значение: " << bill.getStreetName() << std::endl;
	std::cout << "Введите новую улицу (пустая строка - отмена):" << std::endl;
	std::getline(std::cin, str);
	if (str == "") {
		throw new std::exception("");
	}
	bill.setStreetName(str);
}


SetStreetCommand::~SetStreetCommand()
{
}
