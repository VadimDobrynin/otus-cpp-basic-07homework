cmake_minimum_required(VERSION 3.27)
project(otus_cpp_basic_07homework)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(containers)
add_executable(myProg main.cpp)

target_link_libraries(myProg containers)

target_include_directories(myProg
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/containers)