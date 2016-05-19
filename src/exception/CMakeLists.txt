cmake_minimum_required(VERSION 2.8)
project(DataStructured)

add_definitions(-std=c++11)

set(HEADER_FILES
        IndexOutOfBoundsException.h
        )

set(SOURCE_FILES
        )

add_library(exception STATIC ${SOURCE_FILES} ${HEADER_FILES})