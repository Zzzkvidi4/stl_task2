#pragma once
#include "Command.h"
class SetPaymentCommand :
	public Command
{
private:
	Bill& bill;
public:
	SetPaymentCommand(std::string title, Bill& bill);
	void Execute();
	~SetPaymentCommand();
};

