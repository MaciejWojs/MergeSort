/**
 * @file main.cpp
 * @~english
 * @brief A program that demonstrates the use of the merge sort algorithm.
 * @~polish
 * @brief Program demonstrujący użycie algorytmu sortowania przez scalanie.
 */
#include <iostream>
#include <ctime>
#include "MergeSort.hpp"

 /**
  * @~english
  * @brief Main function that executes the merge sort demonstration.
  * @return int Exit status of the program.
  * @~polish
  * @brief Główna funkcja wykonująca demonstrację sortowania przez scalanie.
  * @return int Status zakończenia programu.
  */
int main() {
    srand(time(NULL));
    int size;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> size;
    MergeSort mergeSort;

    std::cout << "Creating " << size << " elements array\n";

    int* array = new int[size];

    /**
     * @~english
     * @brief Fills the array with random values.
     * @~polish
     * @brief Wypełnia tablicę losowymi wartościami.
     */
    for (int i = 0; i < size; i++) {
        array[i] = rand() % size;
    }

    mergeSort.printArray(array, size);
    mergeSort.sort(array, size);
    mergeSort.printArray(array, size);

    delete[] array;

    return 0;
}