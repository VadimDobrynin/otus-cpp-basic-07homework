#include <iostream>
#include "linkedList.h"
#include "vector.h"

void test(IContainers<int>*);
int main() {
    std::cout << "containers" << std::endl;
    std::cout << "vector" <<std::endl;
    test(new MyVector<int>);
    std::cout << "linked list" <<std::endl;
    test(new MyLinkedList<int>);
    return 0;
}

void test(IContainers<int>* cont){
    for(int i = 0; i < 10; i++){
        cont->push_back(i);
    }
    for(int i = 0; i < cont->size(); i++){
        std::cout << cont->operator[](i) << " ";
    }
    std::cout << std::endl;
    std::cout << cont->size() <<std::endl;

    cont->erase(2);
    cont->erase(3);
    cont->erase(4);
    std::cout << std::endl;
    for(int i = 0 ; i < cont->size(); i++){
        std::cout << cont->operator[](i) << " ";
    }
    cont->insert(0, 10);
    std::cout << std::endl;
    for(int i = 0 ; i < cont->size(); i++){
        std::cout << cont->operator[](i) << " ";
    }
    std::cout << std::endl;

    cont->insert(4, 20);
    std::cout << std::endl;
    for(int i = 0 ; i < cont->size(); i++){
        std::cout << cont->operator[](i) << " ";
    }
    std::cout << std::endl;

    cont->insert(cont->size(), 30);
    std::cout << std::endl;
    for(int i = 0 ; i < cont->size(); i++){
        std::cout << cont->operator[](i) << " ";
    }
    std::cout << std::endl;
    delete cont;
}