#ifndef B6D5C905_5872_4F94_A31C_212066BD7430
#define B6D5C905_5872_4F94_A31C_212066BD7430

class MergeSort {
    private:
    void merge(int* array, int left, int middle, int right);
    int findBiggest(int* array, int size);
    public:
    void sort(int* array, int size);
    void printArray(int* array, int size);
};

#endif /* B6D5C905_5872_4F94_A31C_212066BD7430 */
