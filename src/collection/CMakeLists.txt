cmake_minimum_required(VERSION 2.8)
project(DataStructured)

add_definitions(-std=c++11)

set(HEADER_FILES
        SinglyLinkedList.hpp
        SingleNode.hpp
        DoubleNode.hpp
        DoublyLinkedList.hpp
        )

set(SOURCE_FILES
        SinglyLinkedList.cpp
        )

add_library(collection STATIC ${SOURCE_FILES} ${HEADER_FILES})