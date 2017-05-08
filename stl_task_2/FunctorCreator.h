#pragma once
template <typename T>
class FunctorCreator: public AbstractFunctorCreator
{
public:
    FunctorCreator() {};
    BaseFunctor* Create() {
        return new T();
    }
    ~FunctorCreator() {};
};

