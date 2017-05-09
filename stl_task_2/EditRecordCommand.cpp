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
	record_list->RegisterCommand(new SetStreetCommand("Улица.", bill));
	record_list->RegisterCommand(new SetHouseNumberCommand("Номер дома.", bill));
	record_list->RegisterCommand(new SetBlockNumberCommand("Номер строения.", bill));
	record_list->RegisterCommand(new SetApartmentNumberCommand("Номер квартиры.", bill));
	record_list->RegisterCommand(new SetSurnameCommand("Фамилия владельца.", bill));
	choice = -1;
	while (choice != 0) {
		std::cout << bill << std::endl;
		record_list->PrintTitles("Выберите один из пунктов меню изменения:");
		getChoice(0, 4, choice);
		record_list->ExecuteCommand(choice);
	}
}

int EditRecordCommand::SelectBill() {
	std::cout << "Выберите запись (0 - отмена):" << std::endl;
	int choice = -1;
	getChoice(0, cont->size(), choice);
	return choice;
}

EditRecordCommand::~EditRecordCommand()
{
}
