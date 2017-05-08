#pragma once
class AbstractFunctorCreator
{
public:
    AbstractFunctorCreator();
    virtual BaseFunctor* Create() = 0;
    ~AbstractFunctorCreator();
};

