    cmake_minimum_required (VERSION 3.8)

    project(Statistic)

    set(SOURCE_FILES
            main.cpp)

    set(HEADER_FILES
            IContainers.h
            vector.h
            linkedList.h
    )

    # We declare the project as a static library and add all the source code files to it.
    add_library(containers STATIC ${HEADER_FILES} ${SOURCE_FILES})

    add_executable(container main.cpp)