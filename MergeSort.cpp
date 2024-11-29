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
