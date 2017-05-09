#pragma once
class ApartmentNumberFunctor: public BaseFunctor<Bill>
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

