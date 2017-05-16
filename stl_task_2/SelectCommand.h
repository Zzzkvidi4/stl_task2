#pragma once
#include "stdafx.h"
#include "Command.h"
#include "TemplateContainer.h"
#include "SearchFunctorFactory.h"
#include "SurnameFunctor.h"
#include "DateFunctor.h"
#include "HavePeniFunctor.h"
#include "HouseNumberFunctor.h"
#include "ApartmentNumberFunctor.h"
#include "BaseFunctor.h"
#include "CommandList.h"
#include "ExitCommand.h"

class SelectCommand: public Command
{
private:
    TemplateContainer<Bill>* cont;
public:

    SelectCommand(std::string title, TemplateContainer<Bill>* cont): Command(title)
    {
        this->cont = cont;
    }

    void Execute() {
        SearchFunctorFactory<Bill> factory = SearchFunctorFactory<Bill>();
        factory.Add<SurnameFunctor>("surname");
        factory.Add<DateFunctor>("date");
        factory.Add<HouseNumberFunctor>("house");
        factory.Add<ApartmentNumberFunctor>("apartment");
        factory.Add<HavePeniFunctor>("peni");
        std::string type = SelectType();
        if (type == "") {
            return;
        }
        BaseFunctor<Bill>* func = factory.Create<Bill>(type);
        func->Initialize();
        int choice = SelectAlgoritmType();

        TemplateContainer<Bill>* result = new TemplateContainer<Bill>();
        switch (choice) {
            case 1: {
                result = cont->GetElemsIf(func);
                break;
            }
            case 2: {
                result = cont->GetElemsIfBinary(func);
                break;
            }
            default: {
                return;
            }
        }

        CommandList* sub_list = new CommandList();
        choice = -1;
        while (choice != 0) {
			FillSubListMenu(sub_list, result);
            sub_list->PrintTitles("�������� ���� �� ������� ���� ��� �������:");
            getChoice(0, sub_list->Size(), choice);
            if (choice != 0) {
                sub_list->ExecuteCommand(choice);
            }
        }
		cont->PushBack(result);
    }

    std::string SelectType() {
        std::cout << "�������� ���� �� ����� �������:" << std::endl;
        std::cout << "1. �� �������." << std::endl;
        std::cout << "2. �� ����." << std::endl;
        std::cout << "3. �� ������ ����." << std::endl;
        std::cout << "4. �� ������ ��������." << std::endl;
        std::cout << "5. �� ������� �����������." << std::endl;
        int choice = -1;
        getChoice(0, 5, choice);
        switch (choice) {
            case 1: {
                return "surname";
            }
            case 2: {
                return "date";
            }
            case 3: {
                return "house";
            }
            case 4: {
                return "apartment";
            }
            case 5: {
                return "peni";
            }
            default: {
                return "";
            }
        }
    }

    int SelectAlgoritmType() {
        std::cout << "�������� ���� �� ����� �������:" << std::endl;
        std::cout << "1. �������." << std::endl;
        std::cout << "2. ��������." << std::endl;
        std::cout << "0. �����." << std::endl;
        int choice = -1;
        getChoice(0, 2, choice);
        return choice;
    }

	void FillSubListMenu(CommandList* list, TemplateContainer<Bill>* cont) {
		list->Clear();
		list->RegisterCommand(new ExitCommand("�����."));
		if (cont->size() != 0) {
			list->RegisterCommand(new PrintToFileCommand<Bill>("��������� � ����.", cont));
			list->RegisterCommand(new PrintCommand<Bill>("������� � �������.", cont));
			list->RegisterCommand(new RemoveCommand<Bill>("������� ������.", cont));
			list->RegisterCommand(new EditRecordCommand("������������� ������.", cont));
		}
	}

    ~SelectCommand()
    {
    }
};
