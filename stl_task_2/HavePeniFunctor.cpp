#include "stdafx.h"
#include "HavePeniFunctor.h"
#include "Bill.h"


HavePeniFunctor::HavePeniFunctor()
{
    comparator = Bill::peniComparator;
}

bool HavePeniFunctor::operator()(Bill bill)
{
    return (bill.countPeni() > dec::decimal_cast<2>(DBL_EPSILON)) == hasPeni;
}

void HavePeniFunctor::Initialize()
{
    std::string str;
    std::cout << "Выбрать счета с задолжностью (Y/N) (N) (abort - отмена):" << std::endl;
    std::getline(std::cin, str);
    if (str == "abort") {
        throw new std::exception("");
    } else if ((str.length() != 0) && ((str[0] == 'Y') || (str[0] == 'y'))) {
        hasPeni = true;
    } else {
        hasPeni = false;
    }
}


Bill HavePeniFunctor::GetValue()
{
    Bill* bill = new Bill();
    bill->setHasPeni(hasPeni);
    return *bill;
}

HavePeniFunctor::~HavePeniFunctor()
{
}
