#pragma once
#include <map>

class SearchFunctorFactory
{
private:
    std::map<std::string, AbstractFunctorCreator*> FactoryMap;
public:
    SearchFunctorFactory();

    template <typename T>
    void Add(std::string id) {
        typename std::map<std::string, AbstractFunctorCreator*> map;
        if (FactoryMap.find(id) == map.end()) {
            FactoryMap[id] = new FunctorCreator<T>();
        }
    }

    template <typename T>
    void Create(std::string id) {
        typename std::map<std::string, AbstractFunctorCreator*> map;
        std::map<std::string, AbstractFunctorCreator*>::iterator iter = FactoryMap.find(id);
        if (iter != map.end()) {
            iter->second->Create();
        }
    }

    ~SearchFunctorFactory();
};

