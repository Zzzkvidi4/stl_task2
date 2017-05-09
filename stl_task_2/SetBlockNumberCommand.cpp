#include "stdafx.h"
#include "SetBlockNumberCommand.h"


SetBlockNumberCommand::SetBlockNumberCommand(std::string title, Bill & bill): Command(title), bill(bill)
{
}

void SetBlockNumberCommand::Execute()
{
	std::string str;
	std::cout << "������� ��������: " << bill.getBlockNumber() << std::endl;
	std::cout << "������� ����� ����� �������� (������ ������ - ������, 0 - ��� ������ ��������):" << std::endl;
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
