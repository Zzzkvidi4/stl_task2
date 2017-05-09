#pragma once
#include "Command.h"
class SetSurnameCommand :
	public Command
{
private:
	Bill& bill;
public:
	SetSurnameCommand(std::string title, Bill& bill);
	void Execute();
	~SetSurnameCommand();
};

