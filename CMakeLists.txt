cmake_minimum_required(VERSION 3.27)
project(otus_cpp_basic_07homework)

include(ExternalProject)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(containers)
add_subdirectory(MyTests)

add_executable(myProg main.cpp)

target_include_directories(myProg
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/containers
)

target_link_libraries(myProg containers)

#include_directories(myProg
#        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/containers)

