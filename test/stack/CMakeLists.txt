include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicStackTests
        stack_test.cpp)

target_link_libraries(runBasicStackTests gtest gtest_main)
target_link_libraries(runBasicStackTests stack)