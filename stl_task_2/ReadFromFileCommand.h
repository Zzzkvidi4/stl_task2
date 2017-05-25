#pragma once
#include "Command.h"
#include "TemplateContainer.h"
#include "ContainerUtils.h"

template<typename T>
class ReadFromFileCommand: public Command
{
private:
    TemplateContainer<T>* cont;
public:
    ReadFromFileCommand(std::string title, TemplateContainer<T>* cont) : Command(title) {
        this->cont = cont;
    }

    void Execute() {
        std::cout << "Введите имя файла (пустая строка для отмены):" << std::endl;
        std::string file_name;
        std::getline(std::cin, file_name);
        if (file_name != "") {
            cont->clear();
            try {
				std::ifstream fin(file_name);
                if (!ContainerUtils<Bill>::read_from_file(fin, *cont)) {
                    print_message("Внимание, содержимое файла может быть отражено некорректно!");
                }
            }
            catch (std::exception e) {
				if (cont->size() == 0) {
					print_message("Ничего не удалось прочитать. Возможно, файл пуст или поврежден.");
				} else {
					print_message("Файл поврежден фатально. Содержимое может не быть отражено.");
				}
            }
        }
    }

    ~ReadFromFileCommand() {
    }
};

