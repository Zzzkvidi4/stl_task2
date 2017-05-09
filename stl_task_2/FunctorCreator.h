#pragma once
template <typename T>
class FunctorCreator: public AbstractFunctorCreator
{
public:
    FunctorCreator() {};

    BaseFunctor<Bill>* Create() {
        return new T();
    }

    ~FunctorCreator() {};
};

