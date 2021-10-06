#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* arr, size_t size);
void fillArr(int* arr, size_t size);

int main()
{
    const int SIZE = 3;
    int arr[SIZE][SIZE];

    fillArr(arr, SIZE * SIZE);
    bubbleSort(arr, SIZE * SIZE);

    return 0;
}

void bubbleSort(int* arr, size_t size)
{
    for (size_t i = size - 1; i > 0; --i)
    {
        for (size_t j = 0; j < i; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                int buffer = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = buffer;
            }
        }
    }
}

void fillArr(int* arr, size_t size)
{
    for(size_t i = 0; i < size; i++)
        *(arr + i) = rand() % 100;
}
