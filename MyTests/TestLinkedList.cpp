//
// Created by vadim on 03.07.2024.
//
#include <iostream>
#include <gtest/gtest.h>
#include "linkedList.h"

TEST(LinkedList, Empty) {
    MyLinkedList<int> linkedList;
    ASSERT_EQ(linkedList.size(), 0);
}

TEST(LinkedList, ADD_TO_END){
    MyLinkedList<int> linkedList;
    for(int i = 0; i < 100; i++){
        linkedList.push_back(i);
    }
    ASSERT_EQ(linkedList[linkedList.size() - 1], 99);
}

TEST(LinkedList, ADD_TO_BEGIN){
    MyLinkedList<int> linkedList;
    for(int i = 0; i < 100; i++){
        linkedList.push_back(i);
    }
    linkedList.insert(0,777);
    ASSERT_EQ(linkedList[0], 777);
}

TEST(LinkedList, ADD_TO_HALF){
    MyLinkedList<int> linkedList;
    for(int i = 0; i < 100; i++){
        linkedList.push_back(i);
    }
    linkedList.insert(50,777);
    ASSERT_EQ(linkedList[50], 777);
}

TEST(LinkedList, DELETE_FROM_END){
    MyLinkedList<int> linkedList;
    for(int i = 0; i < 100; i++){
        linkedList.push_back(i);
    }
    linkedList.erase(99);
    ASSERT_EQ(linkedList.size(), 99);
    ASSERT_EQ(linkedList[linkedList.size() - 1], 98);
}

TEST(LinkedList, DELETE_FROM_BEGIN){
    MyLinkedList<int> linkedList;
    for(int i = 0; i < 100; i++){
        linkedList.push_back(i);
    }
    linkedList.erase(0);
    ASSERT_EQ(linkedList.size(), 99);
    ASSERT_EQ(linkedList[0], 1);
}

TEST(LinkedList, DELETE_FROM_HALF){
    MyLinkedList<int> linkedList;
    for(int i = 0; i < 100; i++){
        linkedList.push_back(i);
    }
    linkedList.erase(50);
    ASSERT_EQ(linkedList.size(), 99);
    ASSERT_EQ(linkedList[50], 51);
}

TEST(LinkedList, GET_ELEMENTS){
    MyLinkedList<int> linkedList;
    for(int i = 0; i < 100; i++){
        linkedList.push_back(i);
    }
    for(int i = 0; i < linkedList.size(); i++){
        ASSERT_EQ(linkedList[i], i);
    }
}

TEST(LinkedList, GET_COUNT_ELEMENTS){
    MyLinkedList<int> linkedList;
    for(int i = 0; i < 100; i++){
        linkedList.push_back(i);
    }
    ASSERT_EQ(linkedList.size(), 100);
}

TEST(LinkedList, DELETE_ALL_ELEMENTS){
    MyLinkedList<int> linkedList;
    for(int i = 0; i < 2; i++){
        linkedList.push_back(i);
    }
    for(int i = 0; i < 2; i++)
        linkedList.erase(0);

    ASSERT_EQ(linkedList.size(), 0);
}

TEST(LinkedList, DELETE_ALL_ELEMENTS_ADD_ALL_ELEMENTS){
    MyLinkedList<int> linkedList;
    for(int i = 0; i < 100; i++){
        linkedList.push_back(i);
    }
    for(int i = 0; i < 100; i++)
        linkedList.erase(0);
    ASSERT_EQ(linkedList.size(), 0);
    for(int i = 0; i < 100; i++){
        linkedList.push_back(i);
    }
    for(int i = 0; i < linkedList.size(); i++){
        ASSERT_EQ(linkedList[i], i);
    }
}

TEST(LinkedList, COPY){
    MyLinkedList<int> linkedList;
    for(int i = 0; i < 100; i++){
        linkedList.push_back(i);
    }
    MyLinkedList<int> linkedList2(linkedList);
    ASSERT_EQ(linkedList.size(),linkedList2.size());
    for(int i = 0; i < linkedList.size(); i++){
        ASSERT_EQ(linkedList[i], linkedList2[i]);
    }


}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}