#pragma once
#include "Command.h"
#include "TemplateContainer.h"

template <typename T>
class RemoveCommand : public Command
{
private:
    TemplateContainer<T>* cont;
public:

    RemoveCommand(std::string title, TemplateContainer<T>* cont): Command(title)
    {
        this->cont = cont;
    }

    void Execute() {
		std::cout << *cont << std::endl;
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

