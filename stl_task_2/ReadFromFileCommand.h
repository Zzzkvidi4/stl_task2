#pragma once
#include "Command.h"
#include "TemplateContainer.h"

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
        std::cout << "������� ��� ����� (������ ������ ��� ������):" << std::endl;
        std::string file_name;
        std::getline(std::cin, file_name);
        if (file_name != "") {
            cont->clear();
            try {
				std::ifstream fin(file_name);
                if (!cont->read_from_file(fin)) {
                    print_message("��������, ���������� ����� ����� ���� �������� �����������!");
                }
            }
            catch (std::exception e) {
				if (cont->size() == 0) {
					print_message("������ �� ������� ���������. ��������, ���� ���� ��� ���������.");
				} else {
					print_message("���� ��������� ��������. ���������� ����� �� ���� ��������.");
				}
            }
        }
    }

    ~ReadFromFileCommand() {
    }
};

