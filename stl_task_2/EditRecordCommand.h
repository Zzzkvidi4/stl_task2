#pragma once
#include "Command.h"
class EditRecordCommand :
	public Command
{
private:
	TemplateContainer<Bill>* cont;
public:
	EditRecordCommand(std::string title, TemplateContainer<Bill>* cont);
	void Execute();
	int SelectBill();
	~EditRecordCommand();
};

