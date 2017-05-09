#pragma once
#include "Command.h"
#include "stdafx.h"

class ExitCommand: public Command
{
public:

	ExitCommand(std::string title): Command(title) {
	}

	void Execute() {
	}

	~ExitCommand() {
	}
};

