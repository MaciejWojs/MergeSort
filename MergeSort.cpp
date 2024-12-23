/**
 * @file MergeSort.cpp
 * @~english
 * @brief A class implementation of the merge sort algorithm.
 * @~polish
 * @brief Implementacja klasy algorytmu sortowania przez scalanie.
 */
#include "MergeSort.hpp"
#include <iostream>
#include <iomanip>

int MergeSort::findBiggest(int* array, int size) {
    if (size <= 0) {
        std::cerr << "1 Array size must be greater than 0\n";
        return -1;
    }

    int biggest = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > biggest) {
            biggest = array[i];
        }
    }
    return biggest;
}

void MergeSort::printArray(int* array, int size) {
    if (size <= 0) {
        std::cerr << "2 Array size must be greater than 0\n";
    }

    // if (size == 1) {
    //     std::cout << "Array arleady sorted";
    //     return;
    // }


    int biggest = findBiggest(array, size);

    auto width = std::to_string(biggest).length();
    for (auto i = 0; i < size; i++) {
        std::cout << std::setw(width) << array[i] << ' ';
    }
    std::cout << '\n';
}

void MergeSort::merge(int* array, int* left, int* right, int size) {
    int i = 0, j = 0, k = 0;

    while (i < size / 2 && j < size - (size / 2)) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < size / 2) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < size - (size / 2)) {
        array[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort::sort(int* array, int size) {
    if (size <= 1) {
        // std::cerr << "3 Array size must be greater than 0\n";
        return;
    }

    int half_size = size / 2;
    int* left = new int[half_size];
    int* right = new int[size - half_size];

    //filing left array
    for (int i = 0; i < half_size; i++) {
        left[i] = array[i];
    }

    //filing right array
    for (int i = half_size; i < size; i++) {
        right[i - half_size] = array[i];
    }



    sort(left, half_size);
    sort(right, size - half_size);
    merge(array, left, right, size);


    delete[] left;
    delete[] right;
}