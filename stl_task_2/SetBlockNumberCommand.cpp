#include "stdafx.h"
#include "SetBlockNumberCommand.h"


SetBlockNumberCommand::SetBlockNumberCommand(std::string title, Bill & bill): Command(title), bill(bill)
{
}

void SetBlockNumberCommand::Execute()
{
	std::string str;
	std::cout << "Текущее значение: " << bill.getBlockNumber() << std::endl;
	std::cout << "Введите новый номер строения (пустая строка - отмена, 0 - нет номера строения):" << std::endl;
	std::getline(std::cin, str);
	if (str == "") {
		throw new std::exception("");
	}
	if (str != "0") {
		bill.setBlockNumber(str);
	}
	else {
		bill.setBlockNumber("");
	}
}

SetBlockNumberCommand::~SetBlockNumberCommand()
{
}
