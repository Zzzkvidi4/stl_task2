#pragma once
#include "Bill.h"
template <typename T>
class BaseFunctor
{
public:
    BaseFunctor() {};
    virtual bool operator()(T bill) = 0;
    virtual T GetValue() { return *(new T()); }
    virtual void Initialize() = 0;
    ~BaseFunctor() {};
};

