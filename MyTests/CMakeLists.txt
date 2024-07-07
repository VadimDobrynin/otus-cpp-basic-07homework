cmake_minimum_required(VERSION 3.27)
project(MyTests)
set(CMAKE_CXX_STANDARD 17)

#---------------------------------------------------------------------------------
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

#---------------------------------------------------------------------------------

set(SOURCE_FILES
        TestVector.cpp
        TestLinkedList.cpp
)

foreach (test ${SOURCE_FILES})
    string(REPLACE ".cpp" "" target ${test})
    add_executable(${target} ${test})
    target_include_directories(${target}
            PUBLIC ${CMAKE_SOURCE_DIR}/containers
    )
    add_dependencies(${target} googletest)
    target_link_libraries(${target} containers gtest gtest_main pthread)
endforeach ()
