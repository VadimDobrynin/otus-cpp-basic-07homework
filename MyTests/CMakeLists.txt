cmake_minimum_required(VERSION 3.27)
project(MyTests)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        TestVector.cpp)

# We declare the project as a static library and add all the source code files to it.
#add_library(MyTests STATIC ${SOURCE_FILES})

add_executable(mt TestVector.cpp)