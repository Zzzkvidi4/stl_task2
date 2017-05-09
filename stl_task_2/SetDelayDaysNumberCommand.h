#pragma once
#include "Command.h"
class SetDelayDaysNumberCommand :
	public Command
{
private:
	Bill& bill;
public:
	SetDelayDaysNumberCommand(std::string title, Bill& bill);
	void Execute();
	~SetDelayDaysNumberCommand();
};

