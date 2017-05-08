#include "stdafx.h"
#include "SurnameFunctor.h"


SurnameFunctor::SurnameFunctor()
{
    comparator = Bill::surnameComparator;
}

bool SurnameFunctor::operator()(Bill bill)
{
    return bill.getSurname() == surname;
}

void SurnameFunctor::Initialize()
{
    bool isCorrect = false;
    std::string str;
    while (!isCorrect) {
        std::cout << "Введите фамилию (abort - отмена):" << std::endl;
        std::getline(std::cin, str);
        if (str == "abort") {
            throw new std::exception("");
        }
        if (str == "") {
            print_message("Фамилия не может быть пустой!");
        } else {
            surname = str;
            isCorrect = true;
        }
    }
}

Bill SurnameFunctor::GetValue()
{
    if (surname == "") {
        throw new std::invalid_argument("Невозможно создать значение по неинициализированному функтору!");
    }
    Bill* bill = new Bill();
    bill->setSurname(surname);
    return *bill;
}

SurnameFunctor::~SurnameFunctor()
{
}
