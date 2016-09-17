cmake_minimum_required(VERSION 2.8)
SET(CMAKE_C_ARCHIVE_CREATE   "<CMAKE_AR> Scr <TARGET> <LINK_FLAGS> <OBJECTS>")
SET(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> Scr <TARGET> <LINK_FLAGS> <OBJECTS>")
SET(CMAKE_C_ARCHIVE_FINISH   "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
SET(CMAKE_CXX_ARCHIVE_FINISH "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
project(DataStructured LANGUAGES CXX)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(structure_run ${SOURCE_FILES})

include_directories(src/sort)
include_directories(src/collection)
include_directories(src/stack)

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(structure_run sorting collection stack)
