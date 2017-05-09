#include "stdafx.h"
#include "SetPaymentTypeCommand.h"


SetPaymentTypeCommand::SetPaymentTypeCommand(std::string title, Bill& bill): Command(title), bill(bill)
{
}


void SetPaymentTypeCommand::Execute()
{
	std::string str;
	std::cout << "Текущее значение: " << bill.getPaymentType() << std::endl;
	std::cout << "Введите новый тип платежа (пустая строка - отмена):" << std::endl;
	std::getline(std::cin, str);
	if (str == "") {
		throw new std::exception("");
	}
	bill.setPaymentType(str);
}

SetPaymentTypeCommand::~SetPaymentTypeCommand()
{
}
