//
// Created by Massimo Biancalani on 27/04/16.
//

#ifndef DATASTRUCTURED_SORTING_H
#define DATASTRUCTURED_SORTING_H

#include <cstring>

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
    template <typename T>
    void merge(T* array, unsigned int left, unsigned int center, unsigned int right) {
        unsigned i = 0, j = 0;
        T* app = new T[right - left];
        for (int k = 0; k < right - left; ++k) {
            if (i >= center - left || ( j < right - center && array[left + i] > array[center + j])) {
                app[k] = array[j + center];
                j++;
            } else {
                app[k] = array[i + left];
                i++;
            }
        }
        memcpy(&array[left], app, (right - left) * sizeof(T));
        delete app;
    }

    template <typename T>
    void mergeSort(T* array, unsigned int left, unsigned int right) {
        if (right - left > 1) {
            unsigned center = (right + left) / 2;
            mergeSort(array, left, center);
            mergeSort(array, center, right);
            merge(array, left, center, right);
        }
    }
    template <typename T>
    void mergeSort(T* array, unsigned int n) {
        mergeSort(array, 0, n);
    }

}
#endif //DATASTRUCTURED_SORTING_H
