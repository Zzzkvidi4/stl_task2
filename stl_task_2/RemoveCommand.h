#pragma once
#include "Command.h"
#include "TemplateContainer.h"
#include "stdafx.h"
#include "ContainerUtils.h"

class RemoveCommand : public Command
{
private:
    TemplateContainer<Bill>* cont;
public:

    RemoveCommand(std::string title, TemplateContainer<Bill>* cont): Command(title)
    {
        this->cont = cont;
    }

    void Execute() {
		ContainerUtils<Bill>::print_to_console(std::cout, *cont);
        std::cout << "¬ведите позицию дл€ удалени€ (0 - отмена):" << std::endl;
        int num;
        getChoice(0, cont->size(), num);
        if (num != 0) {
            cont->Erase(num);
        }
    }

    ~RemoveCommand()
    {
    }
};

