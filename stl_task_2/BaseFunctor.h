#pragma once
class BaseFunctor
{
public:
    BaseFunctor();
    virtual bool operator()(Bill bill) = 0;
    virtual Bill GetValue() = 0;
    virtual void Initialize() = 0;
    ~BaseFunctor();
};

