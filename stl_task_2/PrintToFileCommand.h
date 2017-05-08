#pragma once
#include "Command.h"
#include "TemplateContainer.h"

template <typename T>
class PrintToFileCommand: public Command
{
private:
    TemplateContainer<T>* cont;
public:

    PrintToFileCommand(std::string title, TemplateContainer<T>* cont): Command(title) {
        this->cont = cont;
    }

    void Execute() {
        std::cout << "Введите имя файла (пустая строка для отмены):" << std::endl;
        std::string file_name;
        std::getline(std::cin, file_name);
        if (file_name != "") {
            try {
                cont->print_to_file(file_name);
            }
            catch (std::exception e) {
                print_message(e.what());
            }
        }
    }

    ~PrintToFileCommand()
    {
    }
};

