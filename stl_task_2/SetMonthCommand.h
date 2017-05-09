#pragma once
#include "Command.h"
class SetMonthCommand :
	public Command
{
private:
	Bill& bill;
public:
	SetMonthCommand(std::string title, Bill& bill);
	void Execute();
	~SetMonthCommand();
};

