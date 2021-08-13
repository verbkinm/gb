#pragma once

#include <iostream>
#include <time.h>

namespace MyLib
{
    float* initArray(size_t size);
    void printArray(float* arr, size_t size);
    void printArray(int* arr, size_t size);
    void calculateArr(float* arr, size_t size);
}
