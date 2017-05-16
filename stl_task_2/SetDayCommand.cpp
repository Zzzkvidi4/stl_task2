#include "stdafx.h"
#include "SetDayCommand.h"


SetDayCommand::SetDayCommand(std::string title, Bill& bill): Command(title), bill(bill)
{
}

void SetDayCommand::Execute()
{
	std::string str;
	bool isCorrect = false;
	std::cout << "������� ��������: " << bill.getDate().getDay() << std::endl;
	while (!isCorrect) {
		std::cout << "������� ����� ���� (������ ������ - ������):" << std::endl;
		std::getline(std::cin, str);
		if (str == "") {
			throw new std::exception("");
		}
		try {
			bill.getDate().setDay(str);
			isCorrect = true;
		}
		catch (std::exception e) {
			print_message(e.what());
		}
	}
}


SetDayCommand::~SetDayCommand()
{
}