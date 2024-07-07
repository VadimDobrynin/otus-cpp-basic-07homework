cmake_minimum_required(VERSION 3.27)
project(otus_cpp_basic_07homework)

include(ExternalProject)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(containers)
add_subdirectory(MyTests)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR})

ExternalProject_Add(googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG main
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
include_directories(
        ${EXTERNAL_INSTALL_LOCATION}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/containers
#        ${CMAKE_CURRENT_SOURCE_DIR}/MyTests
)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

add_executable(myProg main.cpp)
add_dependencies(myProg googletest)

#target_link_libraries(myProg containers gtest gtest_main pthread MyTests)
target_link_libraries(myProg containers gtest gtest_main pthread)

#include_directories(myProg
#        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/containers)

