#include <iostream>

const size_t SIZE = 5;

void printArray(double *arr, const size_t &SIZE);
void printArray(int *arr, const size_t &SIZE);

void xorArray(int *arr, size_t SIZE);

void fillArrayStep_3(int *arr, size_t SIZE);

void shiftArr(int *arr, size_t SIZE, int value);
void shiftLeft(int *arr, size_t SIZE);
void shiftRight(int *arr, size_t SIZE);

bool checkBalance(int *arr, size_t SIZE);
int sumArrayTo(int *arr, size_t SIZE, size_t sumTo);       // from arr[0] to arr[sumTo - 1]
int sumArrayFrom(int *arr, size_t SIZE, size_t sumFrom);   // from arr[sumFrom] to arr[SIZE -1]

int main()
{

    // Task 1
    {
        std::cout << "Task #1: " << std::endl;
        double arr[SIZE] = { 10.5, 2, 0.35e+1, 45.0, -0.6};
        printArray(arr, SIZE);
    }
    // Task 2
    {
        std::cout << std::endl << "Task #2: " << std::endl;
        int arr[SIZE] = {1, 0, 1, 0, 0};

        printArray(arr, SIZE);
        xorArray(arr, SIZE);
        printArray(arr, SIZE);
    }
    // Task 3
    {
        std::cout << std::endl << "Task #3: " << std::endl;
        const size_t SIZE = 8;
        int arr[SIZE];

        fillArrayStep_3(arr, SIZE);
        printArray(arr, SIZE);
    }
    // Task 4*
    {
        std::cout << std::endl << "Task #4*: " << std::endl;
        int arr[SIZE] = {1, 2, 3, 4, 5};

        shiftArr(arr, SIZE, 1);
        printArray(arr, SIZE);
        shiftArr(arr, SIZE, -2);
        printArray(arr, SIZE);
    }
    // Task 5**
    {
        std::cout << std::endl << "Task #5**: " << std::endl;
        int arr[SIZE] = {1, 2, 3, 6};

        std::cout << checkBalance(arr, SIZE);
    }

    return 0;
}

void printArray(double *arr, const size_t &SIZE)
{
    for(size_t i = 0; i < SIZE; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

void printArray(int *arr, const size_t &SIZE)
{
    for(size_t i = 0; i < SIZE; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

void xorArray(int *arr, size_t SIZE)
{
//    while (SIZE)
//    {
//        *arr ^= 1;
//        arr++;
//        SIZE--;
//    }

    for(size_t i = 0; i < SIZE; i++)
        arr[i] ^= 1;
}

void fillArrayStep_3(int *arr, size_t SIZE)
{
    for(size_t i = 0, j = 1; i < SIZE; i++, j += 3)
        arr[i] = j;
}

void shiftArr(int *arr, size_t SIZE, int value)
{
    void (*directionShift)(int*, size_t);

    directionShift = (value > 0) ? shiftRight : shiftLeft;

//    if(value > 0)
//        directionShift = shiftRight;
//    else if(value < 0)
//        directionShift = shiftLeft;

    value = abs(value) % SIZE;

    for (int i = 0; i < value; ++i)
        directionShift(arr, SIZE);
}

void shiftLeft(int *arr, size_t SIZE)
{
    size_t arrSizeByte = SIZE * sizeof(arr);

    int *buffArr = new int[SIZE];
    buffArr[SIZE - 1] = arr[0];

    memcpy(buffArr, (arr + 1), arrSizeByte - sizeof (arr));
    memcpy(arr, buffArr, arrSizeByte);

    delete[] buffArr;
}

void shiftRight(int *arr, size_t SIZE)
{
    size_t arrSizeByte = SIZE * sizeof(arr);

    int *buffArr = new int[SIZE];
    buffArr[0] = arr[SIZE - 1];

    memcpy( (buffArr + 1), arr, arrSizeByte - sizeof (arr));
    memcpy(arr, buffArr, arrSizeByte);

    delete[] buffArr;
}

bool checkBalance(int *arr, size_t SIZE)
{
    for(size_t i = 1; i < SIZE; i++)
    {
        if(sumArrayTo(arr, SIZE, i) == sumArrayFrom(arr, SIZE, i))
            return true;
    }

    return false;
}

int sumArrayTo(int *arr, size_t SIZE, size_t sumTo)
{
    int sum = 0;

    for (size_t i = 0; i < sumTo; ++i)
        sum += arr[i];

    return sum;
}

int sumArrayFrom(int *arr, size_t SIZE, size_t sumFrom)
{
    int sum = 0;

    for (size_t i = sumFrom; i < SIZE; ++i)
        sum += arr[i];

    return sum;
}
