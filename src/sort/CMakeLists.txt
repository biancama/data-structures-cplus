cmake_minimum_required(VERSION 2.8)
project(DataStructured)

add_definitions(-std=c++11)

set(HEADER_FILES
        sorting.hpp
        )

set(SOURCE_FILES
        sorting.cpp
        )

add_library(structure STATIC ${SOURCE_FILES} ${HEADER_FILES})