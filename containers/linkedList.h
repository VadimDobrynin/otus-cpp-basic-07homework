//
// Created by vadim on 17.06.2024.
//

#ifndef OTUS_CPP_BASIC_06HOMEWORK_LINKEDLIST_H
#define OTUS_CPP_BASIC_06HOMEWORK_LINKEDLIST_H

#include "IContainers.h"

template<typename T>
class MyLinkedList : public IContainers<T>{
public:
    MyLinkedList(): nextObject{nullptr}, val{0}, count_elements{0}{}
    MyLinkedList(T value): nextObject{nullptr},count_elements{1}, val{value}{}
    MyLinkedList(MyLinkedList &myLinkedList){
        for(size_t i = 0; i < myLinkedList.size(); i++){
            this->push_back(myLinkedList[i]);
        }
    }
    void push_back(T) override;
    T operator[](size_t) override;
    bool erase(size_t) override;
    bool insert(size_t, T) override;
    size_t size() override;
    ~MyLinkedList(){
        for(size_t i = this->size(); i > 0; i--){
            delete this->get(i);
        }
    }
private:
    T val;
    size_t count_elements;
    MyLinkedList *nextObject;
    MyLinkedList* get(size_t index);
};

///---------------------------------------------------------------------------------------
template <typename T>
void MyLinkedList<T>::push_back(T value) {
    if(count_elements == 0){
        this->val = value;
        count_elements += 1;
        return;
    }
    MyLinkedList* lastObject = this;
    while(lastObject->nextObject != nullptr){
        lastObject = lastObject->nextObject;
    }
    lastObject->nextObject = new MyLinkedList(value);
    count_elements++;
}
template <typename T>
T MyLinkedList<T>::operator[] (size_t index) {
    auto res = get(index);
    if(res == nullptr){
        return val;
    }else{
        return res->val;
    }
}
template <typename T>
bool MyLinkedList<T>::erase(size_t index) {
    if(index < count_elements){
        if(count_elements == 1){
            this->count_elements = 0;
            this->nextObject = nullptr;
            this->val = 0;
            return true;
        }
        auto tmp_prev = get(index - 1);
        auto tmp_index = get(index);
        if(tmp_prev == nullptr) {
            if(tmp_index->nextObject != nullptr){
                tmp_index->val = tmp_index->nextObject->val;
                auto t = tmp_index->nextObject;
                tmp_index->nextObject = tmp_index->nextObject->nextObject;
                count_elements--;
                delete t;
                return true;
            }
        }else{
            tmp_prev->nextObject = tmp_index->nextObject;
            count_elements--;
            delete tmp_index;
            return true;
        }
    }else{
        return false;
    }
    return false;
}
template <typename T>
bool MyLinkedList<T>::insert(size_t index, T value) {
    if(index == 0){
        auto item = new MyLinkedList(value);
        std::swap(this->val, item->val);
        std::swap(this->nextObject, item->nextObject);
        this->nextObject = item;
        count_elements++;
    }else{
        auto item_prev = get(index - 1);
        auto item = new MyLinkedList(value);
        item->nextObject = item_prev->nextObject;
        item_prev->nextObject = item;
        count_elements++;
    }
    return true;
}
template<typename T>
size_t MyLinkedList<T>::size() {return count_elements;}

template<typename T>
MyLinkedList<T>* MyLinkedList<T>::get(size_t index){
    MyLinkedList* indexObject = this;
    if(index < count_elements){
        for(size_t i = 0; i < index; i++){
            indexObject = indexObject->nextObject;
        }
        return indexObject;
    }
    return nullptr;
}


#endif //OTUS_CPP_BASIC_06HOMEWORK_LINKEDLIST_H
