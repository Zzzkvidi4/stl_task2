#pragma once
#include "Command.h"
class SetPaymentTypeCommand :
	public Command
{
private:
	Bill& bill;
public:
	SetPaymentTypeCommand(std::string title, Bill& bill);
	void Execute();
	~SetPaymentTypeCommand();
};

