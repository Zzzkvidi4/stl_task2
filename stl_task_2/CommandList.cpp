#include "stdafx.h"
#include "CommandList.h"
#include "Command.h"

CommandList::CommandList()
{
}

void CommandList::RegisterCommand(Command* command)
{
    commands.push_back(command);
}

void CommandList::ExecuteCommand(int index)
{
    if ((commands.size() < index) || (index < 0)) {
        throw new std::out_of_range("Нарушение индексации списка меню.");
    }
	try {
		commands[index]->Execute();
	}
	catch (std::exception e) {
		if (e.what() != "") {
			print_message(e.what());
		}
	}
}

void CommandList::PrintTitles(std::string header)
{
    std::cout << header << std::endl;
    int i = 1;
    for (std::vector<Command*>::iterator iter = commands.begin() + 1; iter != commands.end(); ++iter) {
        std::cout << i++ << ". " << (*iter)->GetTitle() << std::endl;
    }
	std::cout << "0. " << *commands.begin() << std::endl;
}

void CommandList::Clear()
{
    commands.clear();
}

int CommandList::Size()
{
    return commands.size();
}

CommandList::~CommandList()
{
    Clear();
}
