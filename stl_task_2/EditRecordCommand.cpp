#include "stdafx.h"
#include "EditRecordCommand.h"

EditRecordCommand::EditRecordCommand(std::string title, TemplateContainer<Bill>* cont): Command(title)
{
	this->cont = cont;
}

void EditRecordCommand::Execute()
{
	int choice;
	if ((choice = SelectBill()) == 0) {
		throw new std::exception("");
	}
	Bill& bill = (*cont)[choice];
	CommandList* record_list = new CommandList();
	record_list->RegisterCommand(new SetStreetCommand("�����.", bill));
	record_list->RegisterCommand(new SetHouseNumberCommand("����� ����.", bill));
	record_list->RegisterCommand(new SetBlockNumberCommand("����� ��������.", bill));
	record_list->RegisterCommand(new SetApartmentNumberCommand("����� ��������.", bill));
	record_list->RegisterCommand(new SetSurnameCommand("������� ���������.", bill));
	choice = -1;
	while (choice != 0) {
		std::cout << bill << std::endl;
		record_list->PrintTitles("�������� ���� �� ������� ���� ���������:");
		getChoice(0, 4, choice);
		record_list->ExecuteCommand(choice);
	}
}

int EditRecordCommand::SelectBill() {
	std::cout << "�������� ������ (0 - ������):" << std::endl;
	int choice = -1;
	getChoice(0, cont->size(), choice);
	return choice;
}

EditRecordCommand::~EditRecordCommand()
{
}
