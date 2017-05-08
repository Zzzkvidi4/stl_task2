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
    if ((commands.size() > index) || (index < 1)) {
        throw new std::out_of_range("Нарушение индексации списка меню.");
    }
    commands[index - 1]->Execute();
}

void CommandList::PrintTitles(std::string header)
{
    std::cout << header << std::endl;
    for (std::vector<Command*>::iterator iter = commands.begin(); iter != commands.end(); ++iter) {
        std::cout << (*iter)->GetTitle() << std::endl;
    }
}

void CommandList::Clear()
{
    commands.clear();
}

CommandList::~CommandList()
{
    Clear();
}
