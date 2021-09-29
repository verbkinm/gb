#include "task2.h"

void task2()
{
    std::cout << "Task #2:" << std::endl;

    const size_t MATRIX_SIZE = 4;

    try
    {
        int** matrix = createMatrix(MATRIX_SIZE);

        fillMatrix(matrix, MATRIX_SIZE);
        printMatrix(matrix, MATRIX_SIZE);
        deleteMatrix(matrix, MATRIX_SIZE);
    }
    catch(const std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << "Done." << std::endl << std::endl;
}

int** createMatrix(size_t SIZE)
{
    int** arr = new int* [SIZE];

    for (size_t i = 0; i < SIZE; ++i)
        arr[i] = new int[SIZE];

    return arr;
}

void fillMatrix(int **matrix, size_t SIZE)
{
    if(matrix == nullptr)
        return;

    srand(time(0));

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0;  j < SIZE; j++)
            matrix[i][j] = rand() % 10;
    }
}

void printMatrix(int** matrix, size_t SIZE)
{
    if(matrix == nullptr)
        return;

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0;  j < SIZE; j++)
            std::cout << matrix[i][j] << " ";

        std::cout << std::endl;
    }
}

void deleteMatrix(int** matrix, size_t SIZE)
{
    if(matrix == nullptr)
        return;

    for (size_t i = 0; i < SIZE; i++)
        delete[] matrix[i];

    delete[] matrix;
}
