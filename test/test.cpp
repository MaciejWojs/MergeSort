/**
 * @file test.cpp
 * @~polish
 * @brief Testy jednostkowe dla funkcji sortujących tablice za pomocą MergeSort.
 * @~english
 * @brief Unit tests for array sorting functions using MergeSort.
 */

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <random>
#include "../MergeSort.hpp"
#include "../MergeSort.cpp"

 /**
  * @~polish
  * @brief Sortuje tablicę za pomocą MergeSort.
  * @param arr Tablica do posortowania.
  * @~english
  * @brief Sorts an array using MergeSort.
  * @param arr Array to be sorted.
  */
void sortArray(std::vector<int>& arr) {
    MergeSort mergeSort;
    mergeSort.sort(arr.data(), arr.size());
}

/**
 * @~polish
 * @brief Wypisuje elementy tablicy.
 * @param arr Tablica do wypisania.
 * @~english
 * @brief Prints the elements of the array.
 * @param arr Array to be printed.
 */
void printArray(std::vector<int>& arr) {
    MergeSort mergeSort;
    mergeSort.printArray(arr.data(), arr.size());
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca zachowuje tablicę niezmienioną, gdy ona jest już posortowana rosnąco.
 * @~english
 * @brief Tests if the sorting function keeps the array unchanged when it is already sorted in ascending order.
 */
TEST(SortArrayTest, AlreadySortedArray) {
    std::cout << "Running AlreadySortedArray test" << std::endl;
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = arr;
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje tablicę z elementami w odwrotnej kolejności.
 * @~english
 * @brief Tests if the sorting function correctly sorts an array with elements in reverse order.
 */
TEST(SortArrayTest, ReverseSortedArray) {
    std::cout << "Running ReverseSortedArray test" << std::endl;
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje tablicę z losowymi elementami.
 * @~english
 * @brief Tests if the sorting function correctly sorts an array with random elements.
 */
TEST(SortArrayTest, RandomArray) {
    std::cout << "Running RandomArray test" << std::endl;
    size_t size = 5;
    std::random_device rd;
    std::mt19937 m{ rd() };
    std::vector<int> arr(size);
    std::vector<int> expected(size);
    for (auto i = 0; i < size; i++) {
        int value = m() % 1000;
        arr[i] = value;
        expected[i] = value;
    }
    std::cout << "Random array before sorting: ";
    printArray(arr);
    std::cout << "expected array before sorting: ";
    printArray(expected);

    std::cout << "Random array after sorting: ";
    sortArray(arr);
    printArray(arr);
    std::cout << "expected array after sorting: ";
    std::sort(expected.begin(), expected.end());
    printArray(expected);
    printArray(arr);

    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje tablicę z elementami ujemnymi.
 * @~english
 * @brief Tests if the sorting function correctly sorts an array with negative elements.
 */
TEST(SortArrayTest, NegativeArray) {
    std::cout << "Running NegativeArray test" << std::endl;
    std::vector<int> arr = { -5, -4, -3, -2, -1 };
    std::vector<int> expected = { -5, -4, -3, -2, -1 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje tablicę z elementami ujemnymi i dodatnimi.
 * @~english
 * @brief Tests if the sorting function correctly sorts an array with negative and positive elements.
 */
TEST(SortArrayTest, NegativeAndPositiveArray) {
    std::cout << "Running NegativeAndPositiveArray test" << std::endl;
    std::vector<int> arr = { -5, 4, 3, 2, -1 };
    std::vector<int> expected = { -5, -1, 2,3, 4 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje pustą tablicę.
 * @~english
 * @brief Tests if the sorting function correctly sorts an empty array.
 */
TEST(SortArrayTest, EmptyArray) {
    std::cout << "Running EmptyArray test" << std::endl;
    std::vector<int> arr = {};
    std::vector<int> expected = {};
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje tablicę z jednym elementem.
 * @~english
 * @brief Tests if the sorting function correctly sorts an array with a single element.
 */
TEST(SortArrayTest, SingleElementArray) {
    std::cout << "Running SingleElementArray test" << std::endl;
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje tablicę z powtarzającymi się elementami.
 * @~english
 * @brief Tests if the sorting function correctly sorts an array with repeated elements.
 */
TEST(SortArrayTest, RepeatedElementsArray) {
    std::cout << "Running RepeatedElementsArray test" << std::endl;
    std::vector<int> arr = { 5, 5, 1, 5, 5 };
    std::vector<int> expected = { 1, 5, 5, 5, 5 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje tablicę z powtarzającymi się elementami ujemnymi.
 * @~english
 * @brief Tests if the sorting function correctly sorts an array with repeated negative elements.
 */
TEST(SortArrayTest, RepeatedElementsArrayNegative) {
    std::cout << "Running RepeatedElementsArrayNegative test" << std::endl;
    std::vector<int> arr = { -5, -5, -1, -5, -5 };
    std::vector<int> expected = { -5, -5, -5, -5, -1 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje tablicę z liczbami ujemnymi, dodatnimi oraz duplikatami.
 * @~english
 * @brief Tests if the sorting function correctly sorts an array with negative, positive, and duplicate elements.
 */
TEST(SortArrayTest, NegativePositiveAndRepeatedElementsArray) {
    std::cout << "Running NegativePositiveAndRepeatedElementsArray test" << std::endl;
    std::vector<int> arr = { -5, 5, 1, -5, 5 };
    std::vector<int> expected = { -5, -5, 1, 5, 5 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje tablicę zawierającą tylko dwa elementy w kolejności rosnącej.
 * @~english
 * @brief Tests if the sorting function correctly sorts an array with only two elements in ascending order.
 */
TEST(SortArrayTest, TwoElementsArray) {
    std::cout << "Running TwoElementsArray test" << std::endl;
    std::vector<int> arr = { 1, 2 };
    std::vector<int> expected = { 1, 2 };
    sortArray(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów.
 * @~english
 * @brief Tests if the sorting function correctly sorts a large array with over 100 elements.
 */
TEST(SortArrayTest, LargeArray) {
    std::cout << "Running LargeArray test" << std::endl;
    size_t size = 1000;
    std::random_device rd;
    std::mt19937 m{ rd() };
    std::vector<int> arr(size);
    std::vector<int> expected(size);
    for (auto i = 0; i < size; i++) {
        int value = m() % 1000;
        arr[i] = value;
        expected[i] = value;
    }
    std::cout << "Random array before sorting: ";
    printArray(arr);
    std::cout << "expected array before sorting: ";
    printArray(expected);

    std::cout << "Random array after sorting: ";
    sortArray(arr);
    printArray(arr);
    std::cout << "expected array after sorting: ";
    std::sort(expected.begin(), expected.end());
    printArray(expected);
    printArray(arr);

    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Testuje, czy funkcja sortująca poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów z liczbami ujemnymi, dodatnimi oraz duplikatami.
 * @~english
 * @brief Tests if the sorting function correctly sorts a large array with over 100 elements, including negative, positive, and duplicate numbers.
 */
TEST(SortArrayTest, LargeArrayNegativePositiveAndRepeatedElements) {
    std::cout << "Running LargeArrayNegativePositiveAndRepeatedElements test" << std::endl;
    size_t size = 1000;
    std::random_device rd;
    std::mt19937 m{ rd() };
    std::vector<int> arr = { -5, 5, 1, -5, 5 };
    arr.reserve(size);
    std::vector<int> expected = { -5, 5, 1, -5, 5 };
    expected.reserve(size);
    for (auto i = 0; i < size - 5; i++) {
        int value = m() % 1000;
        arr.push_back(value);
        expected.push_back(value);
    }
    std::cout << "Random array before sorting: ";
    printArray(arr);
    std::cout << "expected array before sorting: ";
    printArray(expected);

    std::cout << "Random array after sorting: ";
    sortArray(arr);
    printArray(arr);
    std::cout << "expected array after sorting: ";
    std::sort(expected.begin(), expected.end());
    printArray(expected);
    printArray(arr);

    EXPECT_EQ(arr, expected);
}

/**
 * @~polish
 * @brief Główna funkcja uruchamiająca wszystkie testy.
 * @param argc Liczba argumentów wiersza poleceń.
 * @param argv Tablica argumentów wiersza poleceń.
 * @return Wynik testów.
 * @~english
 * @brief Main function that runs all tests.
 * @param argc Number of command line arguments.
 * @param argv Array of command line arguments.
 * @return Test results.
 */
int main(int argc, char** argv) {
    srand(time(NULL));
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}