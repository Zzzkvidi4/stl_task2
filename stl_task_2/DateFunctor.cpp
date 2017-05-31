#include "stdafx.h"
#include "DateFunctor.h"
#include "Bill.h"


DateFunctor::DateFunctor()
{
    comparator = Bill::dateComparator;
}

bool DateFunctor::operator()(Bill bill)
{
    return bill.getDate() == date;
}

void DateFunctor::Initialize()
{
    std::string str;
    bool isCorrect = false;
    while (!isCorrect) {
        std::cout << "¬ведите год платежа (abort - отмена):" << std::endl;
        std::getline(std::cin, str);
        if (str == "abort") {
            throw std::exception("");
        }
        try {
            date.setYear(str);
            isCorrect = true;
        }
        catch (std::exception e) {
            print_message(e.what());
        }
    }

    isCorrect = false;
    while (!isCorrect) {
        std::cout << "¬ведите мес€ц платежа (abort - отмена):" << std::endl;
        std::getline(std::cin, str);
        if (str == "abort") {
            throw std::exception("");
        }
        try {
            date.setMonth(str);
            isCorrect = true;
        }
        catch (std::exception e) {
            print_message(e.what());
        }
    }

    isCorrect = false;
    while (!isCorrect) {
        std::cout << "¬ведите день платежа (abort - отмена):" << std::endl;
        std::getline(std::cin, str);
        if (str == "abort") {
            throw std::exception("");
        }
        try {
            date.setDay(str);
            isCorrect = true;
        }
        catch (std::exception e) {
            print_message(e.what());
        }
    }
    isInitialized = true;
}

Bill DateFunctor::GetValue()
{
    Bill* bill = new Bill();
    bill->setDate(date);
    return *bill;
}


DateFunctor::~DateFunctor()
{
}
