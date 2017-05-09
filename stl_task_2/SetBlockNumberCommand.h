#pragma once
#include "Command.h"
class SetBlockNumberCommand :
	public Command
{
private:
	Bill& bill;
public:
	SetBlockNumberCommand(std::string title, Bill& bill);
	void Execute();
	~SetBlockNumberCommand();
};

