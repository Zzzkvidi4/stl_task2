#pragma once
class ApartmentNumberFunctor: BaseFunctor<Bill>
{
private:
    int apartment_number = -1;
public:
    ApartmentNumberFunctor();
    bool operator()(Bill bill);
    void Initialize();
    Bill GetValue();
    ~ApartmentNumberFunctor();
};

