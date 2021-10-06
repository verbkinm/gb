#include <stdio.h>
#include <stdlib.h>

void fillArr(int* arr, size_t size);
void qSort (int* arr, int left, int right);

int main()
{
    const int SIZE = 20;
    int arr[SIZE];

    fillArr(arr, SIZE);
    qSort(arr, 0, SIZE-1);

    return 0;
}

void fillArr(int* arr, size_t size)
{
    for(size_t i = 0; i < size; i++)
        *(arr + i) = rand() % 100;
}

void qSort (int* arr, int left, int right)
{
    int i = left, j = right;
    int temp, pivot = arr[ (left+right) / 2 ];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i <= j)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i++;
            j--;
        }
    }

    if (left < j)
        qSort(arr, left, j);
    if (i < right)
        qSort(arr, i, right);
}
