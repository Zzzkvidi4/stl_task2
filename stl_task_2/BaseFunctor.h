#pragma once
#include "Bill.h"
#include <functional>

template <typename T>
class BaseFunctor
{
protected:
    std::function<bool(T, T)> comparator;
public:
    BaseFunctor() {};
    virtual bool operator()(T bill) = 0;
    virtual T GetValue() { return *(new T()); }
    virtual void Initialize() = 0;
    virtual std::function<bool(T, T)> GetComparator() { return comparator; };
    ~BaseFunctor() {};
};

