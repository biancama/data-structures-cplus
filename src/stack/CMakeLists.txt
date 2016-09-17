cmake_minimum_required(VERSION 2.8)
project(DataStructured)

add_definitions(-std=c++11)

set(HEADER_FILES
        Stack.hpp
        )

set(SOURCE_FILES
        Stack.cpp
        )

add_library(stack STATIC ${SOURCE_FILES} ${HEADER_FILES})