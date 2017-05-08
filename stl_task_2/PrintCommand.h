#pragma once
#include "Command.h"
#include "TemplateContainer.h"

template<typename T>
class PrintCommand: public Command
{
private:
    TemplateContainer<T>* cont;
public:

    PrintCommand(std::string title, TemplateContainer<T>* cont): Command(title)
    {
        this->cont = cont;
    }

    void Execute() {
        if (cont->size() == 0) {
            print_message("Список счетов пуст!");
        } else {
            std::cout << *cont << std::endl;
            system("pause");
        }
    }

    ~PrintCommand()
    {
    }
};

