#pragma once
#include "Command.h"
class SetStreetCommand: public Command
{
private:
	Bill& bill;
public:
	SetStreetCommand(std::string title, Bill& bill);
	void Execute();
	~SetStreetCommand();
};

