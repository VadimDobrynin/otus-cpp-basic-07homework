//
// Created by vadim on 13.06.2024.
//

#ifndef OTUS_CPP_BASIC_06HOMEWORK__ICONTAINERS_H
#define OTUS_CPP_BASIC_06HOMEWORK__ICONTAINERS_H

/*!
 * Интерфейс классов по расчёту статистики
 */
#include <cstddef>
template<typename T>
class IContainers{
public:
    virtual void push_back(T) = 0;
    virtual bool insert(size_t, T)  = 0;
    virtual bool erase(size_t) = 0;
    virtual size_t size() = 0;
    virtual T operator[](size_t) = 0;
    virtual ~IContainers() = default;
};

//IContainers::~IContainers(){}

#endif //OTUS_CPP_BASIC_05HOMEWORK__ISTATISTICS_H
