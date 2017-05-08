#pragma once
#include "BaseFunctor.h"
#include "Bill.h"

class SurnameFunctor : public BaseFunctor<Bill>
{
private:
    std::string surname;
public:
    SurnameFunctor();
    bool operator()(Bill bill);
    void Initialize();
    Bill GetValue();
    ~SurnameFunctor();
};

