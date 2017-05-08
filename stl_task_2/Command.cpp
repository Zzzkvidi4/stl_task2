#include "stdafx.h"
#include "Command.h"


Command::Command(std::string title)
{
    this->title = title;
}


std::string Command::GetTitle()
{
    return title;
}

Command::~Command()
{
}
