/**
 * @file MergeSort.hpp
 * @~english
 * @brief A class declaration of the merge sort algorithm.
 * @~polish
 * @brief Deklaracja klasy algorytmu sortowania przez scalanie.
 */
#ifndef B6D5C905_5872_4F94_A31C_212066BD7430
#define B6D5C905_5872_4F94_A31C_212066BD7430

 /**
  * @~english
  * @class MergeSort
  * @brief A class that implements the merge sort algorithm.
  *
  * @~polish
  * @class MergeSort
  * @brief Klasa implementująca algorytm sortowania przez scalanie.
  */

class MergeSort {
    private:
    /**
     * @~english
     * @brief Merges two subarrays into a single sorted array.
     *
     * @param array The original array containing the subarrays.
     * @param left The left subarray.
     * @param right The right subarray.
     * @param size The size of the original array.
     *
     * @~polish
     * @brief Scalanie dwóch podtablic w jedną posortowaną tablicę.
     *
     * @param array Oryginalna tablica zawierająca podtablice.
     * @param left Lewa podtablica.
     * @param right Prawa podtablica.
     * @param size Rozmiar oryginalnej tablicy.
     */
    void merge(int* array, int* left, int* right, int size);

    /**
     * @~english
     * @brief Finds the largest element in the array.
     *
     * @param array The array to search.
     * @param size The size of the array.
     * @return The largest element in the array.
     *
     * @~polish
     * @brief Znajduje największy element w tablicy.
     *
     * @param array Tablica do przeszukania.
     * @param size Rozmiar tablicy.
     * @return Największy element w tablicy.
     */
    int findBiggest(int* array, int size);
    public:
    /**
     * @~english
     * @brief Sorts the array using the merge sort algorithm.
     *
     * @param array The array to sort.
     * @param size The size of the array.
     *
     * @~polish
     * @brief Sortuje tablicę za pomocą algorytmu sortowania przez scalanie.
     *
     * @param array Tablica do posortowania.
     * @param size Rozmiar tablicy.
     */
    void sort(int* array, int size);

    /**
     * @~english
     * @brief Prints the elements of the array.
     *
     * @param array The array to print.
     * @param size The size of the array.
     *
     * @~polish
     * @brief Wypisuje elementy tablicy.
     *
     * @param array Tablica do wypisania.
     * @param size Rozmiar tablicy.
     */
    void printArray(int* array, int size);
};

#endif /* B6D5C905_5872_4F94_A31C_212066BD7430 */
