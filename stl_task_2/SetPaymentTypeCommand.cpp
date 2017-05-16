#include "stdafx.h"
#include "SetPaymentTypeCommand.h"


SetPaymentTypeCommand::SetPaymentTypeCommand(std::string title, Bill& bill): Command(title), bill(bill)
{
}


void SetPaymentTypeCommand::Execute()
{
	std::string str;
	std::cout << "������� ��������: " << bill.getPaymentType() << std::endl;
	std::cout << "������� ����� ��� ������� (������ ������ - ������):" << std::endl;
	bool isCorrect = false;
	while (!isCorrect) {
		std::getline(std::cin, str);
		if (str == "") {
			throw new std::exception("");
		}
		try {
			bill.setPaymentType(str);
			isCorrect = true;
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}

SetPaymentTypeCommand::~SetPaymentTypeCommand()
{
}