#pragma once
class HavePeniFunctor: public BaseFunctor<Bill>
{
private:
    bool hasPeni = false;
public:
    HavePeniFunctor();
    bool operator()(Bill bill);
    void Initialize();
    Bill GetValue();
    ~HavePeniFunctor();
};

