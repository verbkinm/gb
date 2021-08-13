#include "mylib.h"

namespace MyLib
{
float *initArray(size_t size)
{
    float* arr = new (std::nothrow) float[size];

    if(!arr)
        return arr;

    srand(time(0));
    for (size_t i = 0; i < size; ++i)
        arr[i] = -100 + rand() % 200;

    return arr;
}

void printArray(float *arr, size_t size)
{
    std::cout.precision(2);

    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

void printArray(int *arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

void calculateArr(float *arr, size_t size)
{
    size_t positiveCount = 0, negativeCount = 0;

    for (size_t i = 0; i < size; ++i)
    {
        if(arr[i] < 0)
            negativeCount++;
        else if (arr[i] > 0)
            positiveCount++;
    }

    std::cout << "Positive numbers: " << positiveCount << std::endl;
    std::cout << "Negative numbers: " << negativeCount << std::endl;
}
}
