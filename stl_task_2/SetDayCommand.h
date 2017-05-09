#pragma once
#include "Command.h"
class SetDayCommand :
	public Command
{
private:
	Bill& bill;
public:
	SetDayCommand(std::string title, Bill& bill);
	void Execute();
	~SetDayCommand();
};

