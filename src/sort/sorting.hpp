//
// Created by Massimo Biancalani on 27/04/16.
//

#ifndef DATASTRUCTURED_SORTING_H
#define DATASTRUCTURED_SORTING_H
namespace structure {
    template <typename T>
    void insertionSort(T* array, int n) {
        for (unsigned int i = 1; i < n; ++i) {
            unsigned int j = i;
            T curr = array[j];
            while (j > 0 && curr < array[j -1] ) {
                array[j] = array[j-1];
                j--;
            }
            array[j] = curr;
        }
    }
}
#endif //DATASTRUCTURED_SORTING_H
