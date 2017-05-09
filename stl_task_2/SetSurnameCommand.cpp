#include "stdafx.h"
#include "SetSurnameCommand.h"


SetSurnameCommand::SetSurnameCommand(std::string title, Bill& bill): Command(title), bill(bill)
{
}


void SetSurnameCommand::Execute()
{
	std::string str;
	std::cout << "Текущее значение: " << bill.getSurname() << std::endl;
	std::cout << "Введите новую фамилию владельца (пустая строка - отмена):" << std::endl;
	std::getline(std::cin, str);
	if (str == "") {
		throw new std::exception("");
	}
	bill.setSurname(str);
}

SetSurnameCommand::~SetSurnameCommand()
{
}
