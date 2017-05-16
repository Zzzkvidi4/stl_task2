#include "stdafx.h"
#include "SetStreetCommand.h"


SetStreetCommand::SetStreetCommand(std::string title, Bill& bill): Command(title), bill(bill)
{
}

void SetStreetCommand::Execute()
{
	std::string str;
	std::cout << "������� ��������: " << bill.getStreetName() << std::endl;
	std::cout << "������� ����� ����� (������ ������ - ������):" << std::endl;
	bool isCorrect = false;
	while (!isCorrect) {
		std::getline(std::cin, str);
		if (str == "") {
			throw new std::exception("");
		}
		try {
			bill.setStreetName(str);
			isCorrect = true;
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}


SetStreetCommand::~SetStreetCommand()
{
}