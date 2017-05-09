#pragma once
#include "Command.h"
class SetPeniCommand :
	public Command
{
private:
	Bill& bill;
public:
	SetPeniCommand(std::string title, Bill& bill);
	void Execute();
	~SetPeniCommand();
};

