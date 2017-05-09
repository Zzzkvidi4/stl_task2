#include "stdafx.h"
#include "SetPaymentCommand.h"


SetPaymentCommand::SetPaymentCommand(std::string title, Bill& bill): Command(title), bill(bill)
{
}

void SetPaymentCommand::Execute()
{
	std::string str;
	std::cout << "������� ��������: " << bill.getPaymentType() << std::endl;
	std::cout << "������� ����� ��� ������� (������ ������ - ������):" << std::endl;
	std::getline(std::cin, str);
	std::getline(std::cin, str);
	if (str == "") {
		throw new std::exception("");
	}
	bill.setPaymentType(str);
}


SetPaymentCommand::~SetPaymentCommand()
{
}
