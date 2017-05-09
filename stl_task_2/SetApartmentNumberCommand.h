#pragma once
#include "Command.h"
class SetApartmentNumberCommand :
	public Command
{
private:
	Bill& bill;
public:
	SetApartmentNumberCommand(std::string title, Bill& bill);
	void Execute();
	~SetApartmentNumberCommand();
};

