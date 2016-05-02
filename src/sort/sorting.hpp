//
// Created by Massimo Biancalani on 27/04/16.
//

#ifndef DATASTRUCTURED_SORTING_H
#define DATASTRUCTURED_SORTING_H
namespace structure {
    template <typename T>
    void insertionSort(T* array, unsigned int n) {
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

    template <typename T>
    void swap(T* array, unsigned int i, unsigned int j) {
        T app = array[i];
        array[i] = array[j];
        array[j] = app;
    }

    template <typename T>
    void selectionSort(T* array, unsigned int n) {
        for (unsigned int i = 0; i < n; ++i) {
            unsigned int min_index = i;
            for (int j = i; j < n; ++j) {
                if (array[j] < array[min_index]) {
                    min_index = j;
                }
            }
            swap(array, i, min_index);
        }
    }

    template <typename T>
    void bubbleSort(T* array, unsigned int n) {
        unsigned k = n;
        bool swapped = true;
        while (swapped) {
            swapped = false;
            for (int i = 0; i < k - 1 ; ++i) {
                if (array[i+1] < array[i]) {
                    swapped = true;
                    swap(array, i , i+1);
                }
            }
            k--;
        }

    }
}
#endif //DATASTRUCTURED_SORTING_H
