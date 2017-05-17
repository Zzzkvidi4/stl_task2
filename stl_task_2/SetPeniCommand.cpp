#include "stdafx.h"
#include "SetPeniCommand.h"


SetPeniCommand::SetPeniCommand(std::string title, Bill & bill): Command(title), bill(bill)
{
}

void SetPeniCommand::Execute()
{
	bool isCorrect = false;
	std::string str;
	std::cout << "Текущее значение: " << bill.getPeni() << std::endl;
	while (!isCorrect) {
		std::cout << "Введите новый процент пени (пустая строка - отмена):" << std::endl;
		std::getline(std::cin, str);
		if (str == "") {
			throw std::exception("");
		}
		try {
			bill.setPeni(str);
			isCorrect = true;
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}

SetPeniCommand::~SetPeniCommand()
{
}
