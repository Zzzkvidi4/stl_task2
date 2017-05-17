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
	bool isCorrect = false;
	while (!isCorrect) {
		std::getline(std::cin, str);
		if (str == "") {
			throw  std::exception("");
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
