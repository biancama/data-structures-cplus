//
// Created by Massimo Biancalani on 27/04/16.
//

#include "gtest/gtest.h"
#include "sorting.hpp"
TEST(sorting_check, sort01) {
    int unsorted_array[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    int expected_array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    structure::insertionSort(unsorted_array, 8);
    for (int idx=0; idx< 8 ; idx++) {
        SCOPED_TRACE(idx); //write to the console in which iteration the error occurred
        ASSERT_EQ(unsorted_array[idx],expected_array[idx]);
    }
}