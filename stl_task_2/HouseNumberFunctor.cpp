#include "stdafx.h"
#include "HouseNumberFunctor.h"
#include "Bill.h"


HouseNumberFunctor::HouseNumberFunctor()
{
    house_number = -1;
    comparator = Bill::houseNumberComparator;
}

bool HouseNumberFunctor::operator()(Bill bill)
{
    return bill.getHouseNumber() == house_number;
}

void HouseNumberFunctor::Initialize()
{
    bool isCorrect = false;
    std::string str;
    while (!isCorrect) {
        std::cout << "Введите номер дома (abort - отмена):" << std::endl;
        std::getline(std::cin, str);
        if (str == "abort") {
            throw new std::exception("");
        }
        try {
			if (!checkInt(str)) {
				throw std::invalid_argument("");
			}
            house_number = std::stoi(str);
            if (house_number <= 0) {
                house_number = -1;
                throw new std::exception("Номер дома должен быть больше нуля!");
            }
            isCorrect = true;
        }
        catch (std::invalid_argument e) {
            print_message("Номер дома должен быть числом!");
        }
        catch (std::exception e) {
            print_message(e.what());
        }
    }
}

Bill HouseNumberFunctor::GetValue()
{
    if (house_number == -1) {
        throw new std::invalid_argument("Невозможно создать значение по неинициализированному функтору!");
    }
    Bill* bill = new Bill();
    bill->setHouseNumber(house_number);
    return *bill;
}


HouseNumberFunctor::~HouseNumberFunctor()
{
}
