#include "stdafx.h"
#include "SetApartmentNumberCommand.h"


SetApartmentNumberCommand::SetApartmentNumberCommand(std::string title, Bill& bill): Command(title), bill(bill)
{
}

void SetApartmentNumberCommand::Execute()
{
	std::string str;
	std::cout << "Текущее значение: " << bill.getApartmentNumber() << std::endl;
	bool isCorrect = false;
	while (!isCorrect) {
		std::cout << "Введите новый номер квартиры (пустая строка - отмена, 0 - нет номера квартиры):" << std::endl;
		std::getline(std::cin, str);
		if (str == "") {
			throw std::exception("");
		}
		try {
			if (str != "0") {
				bill.setApartmentNumber(str);
			}
			else {
				bill.setApartmentNumber("");
			}
			isCorrect = true;
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}


SetApartmentNumberCommand::~SetApartmentNumberCommand()
{
}
