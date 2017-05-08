#pragma once
#include "stdafx.h"
#include "Command.h"

class CommandList
{
private:
    std::vector<Command*> commands = std::vector<Command*>();
public:
    CommandList();
    void RegisterCommand(Command* command);
    void ExecuteCommand(int index);
    void PrintTitles(std::string header);
    void Clear();
    int Size();
    ~CommandList();
};

