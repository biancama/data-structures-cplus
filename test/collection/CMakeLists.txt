include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicListTests
        singlyLinkedList_test.cpp
        DoublyLinkedList_test.cpp)

target_link_libraries(runBasicListTests gtest gtest_main)
target_link_libraries(runBasicListTests collection)