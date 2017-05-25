#pragma once
#include "Command.h"
#include "TemplateContainer.h"
#include "ContainerUtils.h"

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
				std::ofstream fout(file_name);
                ContainerUtils<Bill>::print_to_file(fout, *cont);
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

