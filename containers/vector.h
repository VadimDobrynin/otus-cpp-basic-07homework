//
// Created by vadim on 17.06.2024.
//

#ifndef OTUS_CPP_BASIC_06HOMEWORK_VECTOR_H
#define OTUS_CPP_BASIC_06HOMEWORK_VECTOR_H

#include "IContainers.h"

template<typename T>
class MyVector : public IContainers<T>{
public:
    MyVector() : adr{nullptr}, size_reserved{2}, count{0} {}
    MyVector(MyVector &myVector){
        adr = nullptr;
        size_reserved = 2;
        count = 0;
        for(size_t i = 0; i < myVector.size(); i++){
            this->push_back(myVector[i]);
        }
    }
    void push_back(T) override;
    T operator[](size_t) override;
    bool erase(size_t) override;
    bool insert(size_t, T) override;
    size_t size() override;
    ~MyVector() override{
        delete[] adr;
    }
private:
    size_t size_reserved;
    size_t count;
    T* adr;
};

///---------------------------------------------------------------------------
template <typename T>
void MyVector<T>::push_back(T value) {
    if(adr == nullptr){
        adr = new int[size_reserved];
        adr[0] = value;
        count++;
    }else{
        if(count == size_reserved){
            int* tmp = new int[2 * size_reserved];
            for(size_t i = 0; i < size_reserved; i++){
                tmp[i] = adr[i];
            }
            size_reserved *= 2;
            tmp[count] = value;
            delete[] adr;
            adr = tmp;
            tmp = nullptr;
            count++;
        }else{
            adr[count] = value;
            count++;
        }
    }
}
template <typename T>
T MyVector<T>::operator[] (size_t index) {
    return adr[index];
}
/*!
 * Удаление элемента из списка по индексу.
 * Если индекс больше размера массива, операция игнорируется(возвращается false);
 */
template <typename T>
bool MyVector<T>::erase(size_t index) {
    if(index <= count - 1){
        for(size_t i = index; i < count - 1; i++){
            adr[i] = adr[i + 1];
        }
        count--;
        return true;
    }
    return false;
}
/*!
 *
 * @param index
 * @param value
 * @return false - в случае неуспеха операции
 */
template <typename T>
bool MyVector<T>::insert(size_t index, T value) {
    ///< невозможная позиция
    if(index > count){
        return false;
    }
    if(count == size_reserved){
        int* tmp = new int[2 * size_reserved];
        for(size_t i = 0; i < index; i++){
            tmp[i] = adr[i];
        }
        for(size_t i = index; i < count; i++){
            tmp[i + 1] = adr[i];
        }
        size_reserved *= 2;
        count++;
        tmp[index] = value;
        delete[] adr;
        adr = tmp;
    }else{
        for(size_t i = count; i > index; i--){
            adr[i] = adr[i - 1];
        }
        adr[index] = value;
        count++;
    }
    return true;
}
template <typename T>
size_t MyVector<T>::size(){
    return this->count;
}



#endif //OTUS_CPP_BASIC_06HOMEWORK_VECTOR_H
