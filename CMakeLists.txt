cmake_minimum_required(VERSION 2.8)
project(DataStructured)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(structure_run ${SOURCE_FILES})

include_directories(src/sort)

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(structure_run structure)
