//
// Created by vadim on 03.07.2024.
//
#include <iostream>
#include <gtest/gtest.h>
#include "vector.h"

TEST(Vector, Empty) {
    MyVector<int> vector;
    ASSERT_EQ(vector.size(), 0);
}

TEST(Vector, ADD_TO_END){
    MyVector<int> vector;
    for(int i = 0; i < 100; i++){
        vector.push_back(i);
    }
    ASSERT_EQ(vector[vector.size() - 1], 99);
}

TEST(Vector, ADD_TO_BEGIN){
    MyVector<int> vector;
    for(int i = 0; i < 100; i++){
        vector.push_back(i);
    }
    vector.insert(0,777);
    ASSERT_EQ(vector[0], 777);
}

TEST(Vector, ADD_TO_HALF){
    MyVector<int> vector;
    for(int i = 0; i < 100; i++){
        vector.push_back(i);
    }
    vector.insert(50,777);
    ASSERT_EQ(vector[50], 777);
}

TEST(Vector, DELETE_FROM_END){
    MyVector<int> vector;
    for(int i = 0; i < 100; i++){
        vector.push_back(i);
    }
    vector.erase(99);
    ASSERT_EQ(vector.size(), 99);
    ASSERT_EQ(vector[vector.size() - 1], 98);
}

TEST(Vector, DELETE_FROM_BEGIN){
    MyVector<int> vector;
    for(int i = 0; i < 100; i++){
        vector.push_back(i);
    }
    vector.erase(0);
    ASSERT_EQ(vector.size(), 99);
    ASSERT_EQ(vector[0], 1);
}

TEST(Vector, DELETE_FROM_HALF){
    MyVector<int> vector;
    for(int i = 0; i < 100; i++){
        vector.push_back(i);
    }
    vector.erase(50);
    ASSERT_EQ(vector.size(), 99);
    ASSERT_EQ(vector[50], 51);
}

TEST(Vector, GET_ELEMENTS){
    MyVector<int> vector;
    for(int i = 0; i < 100; i++){
        vector.push_back(i);
    }
    for(int i = 0; i < vector.size(); i++){
        ASSERT_EQ(vector[i], i);
    }
}

TEST(Vector, GET_COUNT_ELEMENTS){
    MyVector<int> vector;
    for(int i = 0; i < 100; i++){
        vector.push_back(i);
    }
    ASSERT_EQ(vector.size(), 100);
}

TEST(Vector, DELETE_ALL_ELEMENTS){
    MyVector<int> vector;
    for(int i = 0; i < 100; i++){
        vector.push_back(i);
    }
    for(int i =0; i < 100; i++)
        vector.erase(0);

    ASSERT_EQ(vector.size(), 0);
}

TEST(Vector, COPY){
    MyVector<int> vector;
    for(int i = 0; i < 100; i++){
        vector.push_back(i);
    }
    MyVector<int> vector2(vector);
    ASSERT_EQ(vector.size(),vector2.size());
    for(int i = 0; i < vector.size(); i++){
        ASSERT_EQ(vector[i], vector2[i]);
    }


}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}