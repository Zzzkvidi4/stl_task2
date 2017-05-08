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
    if ((commands.size() < index) || (index < 1)) {
        throw new std::out_of_range("Нарушение индексации списка меню.");
    }
    commands[index - 1]->Execute();
}

void CommandList::PrintTitles(std::string header)
{
    std::cout << header << std::endl;
    int i = 1;
    for (std::vector<Command*>::iterator iter = commands.begin(); iter != commands.end(); ++iter) {
        std::cout << i++ << ". " << (*iter)->GetTitle() << std::endl;
    }
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
