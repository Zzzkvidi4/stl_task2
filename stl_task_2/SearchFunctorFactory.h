#pragma once
#include <map>
#include "FunctorCreator.h"

template <typename T>
class SearchFunctorFactory
{
private:
	std::map<std::string, AbstractFunctorCreator*> FactoryMap;
public:
	SearchFunctorFactory() {}

    template <typename S>
    void Add(std::string id) {
        typename std::map<std::string, AbstractFunctorCreator*> map;
        if (FactoryMap.find(id) == FactoryMap.end()) {
            FactoryMap[id] = new FunctorCreator<S>();
        }
    }

    template <typename T>
    BaseFunctor<T>* Create(std::string id) {
        std::map<std::string, AbstractFunctorCreator*>::iterator iter = FactoryMap.find(id);
        if (iter != FactoryMap.end()) {
            return iter->second->Create();
        }
    }

	~SearchFunctorFactory() {}
};

