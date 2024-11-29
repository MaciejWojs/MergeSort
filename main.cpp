#include <iostream>
#include <ctime>
#include "MergeSort.hpp"

int main() {
    srand(time(NULL));
    int size;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> size;
    MergeSort mergeSort;

    std::cout << "Creating " << size << " elements array\n";

    int* array = new int[size];

    for (int i = 0; i < size; i++) {
        array[i] = rand() % size;
    }

    mergeSort.printArray(array, size);
    mergeSort.sort(array, size);
    mergeSort.printArray(array, size);

    delete[] array;

    return 0;
}