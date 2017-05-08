#pragma once
class HouseNumberFunctor: public BaseFunctor<Bill>
{
private:
    int house_number;
public:
    HouseNumberFunctor();
    bool operator()(Bill bill);
    void Initialize();
    Bill GetValue();
    ~HouseNumberFunctor();
};

