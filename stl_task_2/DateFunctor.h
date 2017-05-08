#pragma once
class DateFunctor: public BaseFunctor<Bill>
{
private:
    Date date;
    bool isInitialized = false;
public:
    DateFunctor();
    bool operator()(Bill bill);
    void Initialize();
    Bill GetValue();
    ~DateFunctor();
};

