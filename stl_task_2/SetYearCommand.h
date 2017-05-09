#pragma once
#include "Command.h"
class SetYearCommand :
	public Command
{
private:
	Bill &bill;
public:
	SetYearCommand(std::string title, Bill& bill);
	void Execute();
	~SetYearCommand();
};

