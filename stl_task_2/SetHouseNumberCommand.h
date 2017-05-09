#pragma once
#include "Command.h"
class SetHouseNumberCommand :
	public Command
{
private:
	Bill& bill;
public:
	SetHouseNumberCommand(std::string title, Bill& bill);
	void Execute();
	~SetHouseNumberCommand();
};

