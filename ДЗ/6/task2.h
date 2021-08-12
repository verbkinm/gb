#ifndef TASK2_H
#define TASK2_H

#include <iostream>
#include <time.h>

void task2();
int** createMatrix(size_t SIZE);
void fillMatrix(int** matrix, size_t SIZE);
void printMatrix(int** matrix, size_t SIZE);
void deleteMatrix(int** matrix, size_t SIZE);

#endif // TASK2_H
