include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicSortingTests
        sorting_test.cpp)

target_link_libraries(runBasicSortingTests gtest gtest_main)
target_link_libraries(runBasicSortingTests structure)