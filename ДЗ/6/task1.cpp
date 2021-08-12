#include "task1.h"

void task1()
{
    std::cout << "Task #1:" << std::endl;

    size_t arrSize = 0;

    std::cout << "Input array size: ";
    std::cin >> arrSize;

    if(std::cin.fail())
    {
        std::cout << "Error create array!";
        exit(1);
    }

    try
    {
        int *arr = createArr(arrSize);
        fillArr(arr, arrSize);
        printArr(arr, arrSize);
        deleteArr(arr);
    }
    catch(const std::exception &error)
    {
        std::cout << error.what() << std::endl;
        return;
    }

    std::cout << "Done." << std::endl << std::endl;
}

int* createArr(size_t arrSize)
{
    return new int[arrSize];
}

void fillArr(int *arr, size_t arrSize)
{
    if(arr == nullptr)
        return;

    for (size_t i = 0; i < arrSize; i++)
        arr[i] = pow(2, i);
}

void printArr(int* arr, size_t arrSize)
{
    if(arr == nullptr)
        return;

    for (size_t i = 0; i < arrSize; i++)
        std::cout << "2^" << i << " = " << arr[i] << std::endl;
}

void deleteArr(int* arr)
{
    if(arr != nullptr)
        delete[] arr;
}
