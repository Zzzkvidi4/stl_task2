#pragma once
class AbstractFunctorCreator
{
public:
    AbstractFunctorCreator();
    virtual BaseFunctor<Bill>* Create() = 0;
    ~AbstractFunctorCreator();
};

